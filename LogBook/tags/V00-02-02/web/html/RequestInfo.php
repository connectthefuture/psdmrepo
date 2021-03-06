<?php

require_once( 'logbook/logbook.inc.php' );
require_once( 'lusitime/lusitime.inc.php' );
require_once( 'regdb/regdb.inc.php' );

use LogBook\LogBook;
use LogBook\LogBookAuth;
use LogBook\LogBookException;

use LusiTime\LusiTime;
use LusiTime\LusiTimeException;

use RegDB\RegDBHtml;
use RegDB\RegDBException;

/*
 * This script will process requests for various information stored in the database.
 * The result will be returned as JSON object (array).
 */
if( !isset( $_GET['type'] )) die( "no valid information type in the request" );
$type = trim( $_GET['type'] );

if( !isset( $_GET['exper_id'] )) die( "no valid experiment identifier in the request" );
$exper_id = trim( $_GET['exper_id'] );

define( TYPE_HISTORY_P,     110 );  // preparation phase
define( TYPE_HISTORY_D,     120 );  // data taking phase
define( TYPE_HISTORY_D_DAY, 121 );  // a day in data taking phase
define( TYPE_HISTORY_F,     130 );  // follow-up phase

define( TYPE_SHIFTS,  200 );
define( TYPE_SHIFT,   201 );

define( TYPE_RUNS,    300 );
define( TYPE_RUN,     301 );

function shift2json( $shift ) {
    return json_encode(
        array (
            "label" => $shift->begin_time()->toStringShort(),
            "expanded" => false,
            "type" => TYPE_SHIFT,
            "title" => "major events happened within the shift",
            "shift_id" => $shift->id()
        )
    );
}

function run2json( $run ) {
    return json_encode(
        array (
            "label" => $run->num(),
            "expanded" => false,
            "type" => TYPE_RUN,
            "title" => "all events happened within the run",
            "run_id" => $run->id(),
            "shift_id" => $run->shift()->id()
        )
    );
}

function day2json( $d ) {
    $label = $d->begin->toStringDay();
    $today = LusiTime::now()->toStringDay();
    if( $label == $today ) $label .= ' <span style="color:red; font-weight:bold;">&lt;&minus;today</span>';
    return json_encode(
        array (
            "label" => $label,
            "expanded" => false,
            "type" => TYPE_HISTORY_D_DAY,
            "title" => "all events happened during that day of data taking",
            "day" => $d->begin->toStringDay(),
            "begin" => $d->begin->to64(),
            "end" => $d->end->to64()
        )
    );
}
function entry2json( $entry ) {

    $relevance_time_str   = is_null( $entry->relevance_time()) ? 'n/a' : $entry->relevance_time()->toStringShort();
    $shift_begin_time_str = is_null( $entry->shift_id())       ? 'n/a' : $entry->shift()->begin_time()->toStringShort();
    $run_number_str       = is_null( $entry->run_id())         ? 'n/a' : $entry->run()->num();

    $tags = $entry->tags();
    $attachments = $entry->attachments();

    // Estimate a number of lines for the message text by counting
    // new lines.
    //
    $message_lines = count( explode( "\n", $entry->content()));
    $message_height = min( 200, 8 + 16*$message_lines );
    $base = 10 + $message_height;

    $extra_lines = max( count( $tags ), count( $attachments ));
    $extra_vspace = $extra_lines == 0 ? 0 :  20 + 20 * $extra_lines;

    $con = new RegDBHtml( 0, 0, 750, 60 + $message_height + $extra_vspace );
    $con->container_1 (   0,   0, "<pre style=\"padding:4px; font-size:14px; background-color:#cfecec;\">{$entry->content()}</pre>", 750, $message_height );
        //->label   ( 250,  $base,    'By:'        )->value( 300,  $base,    $entry->author())
        //->label   (  20,  $base,    'Posted:'    )->value( 100,  $base,    $entry->insert_time()->toStringShort())
        //->label   (  20,  $base+20, 'Relevance:' )->value( 100,  $base+20, $relevance_time_str )
        //->label   ( 250,  $base+20, 'Run:'       )->value( 300,  $base+20, $run_number_str )
        //->label   ( 350,  $base+20, 'Shift:'     )->value( 400,  $base+20, $shift_begin_time_str );

    if( count( $tags ) != 0 ) {
        $con->label_1(  0, $base+20, 'Tag', 80 )->label_1( 115, $base+20, 'Value', 100 );
    }
    if( count( $attachments ) != 0 ) {
        $con->label_1  ( 250, $base+20, 'Attachment', 200 )->label_1( 465, $base+20, 'Size', 50 )
            ->container( 520, $base+20, 'viewarea' );
    }
    $base4tags = $base+45;
    foreach( $tags as $tag ) {
        $con->value_1(   0, $base4tags, $tag->tag())
            ->value_1( 115, $base4tags, $tag->value());
        $base4tags = $base4tags + 20;
    }
    $base4attch = $base+45;
    foreach( $attachments as $attachment ) {
        //$attachment_url = '<a href="ShowAttachment.php?id='.$attachment->id().'" target="_blank" class="lb_link">'.$attachment->description().'</a>';
        $attachment_url = '<a href="attachments/'.$attachment->id().'/'.$attachment->description().'" target="_blank" class="lb_link">'.$attachment->description().'</a>';
        //$attachment_url = '<a href="javascript:preview_atatchment('.$attachment->id().')" class="lb_link">'.$attachment->description().'</a>';
        //$attachment_url =
        //    '<a href="ShowAttachment.php?id='.$attachment->id().'" target="_blank" class="lb_link">'.$attachment->description().'</a>'.
        //    '&nbsp;'.
        //    '<a href="#viewarea" class="lb_link">View</a>';

        $con->value_1( 250, $base4attch, $attachment_url )
            ->value_1( 465, $base4attch, $attachment->document_size());
        $base4attch = $base4attch + 20;
    }
    return json_encode(
        array (
            "event_time" => $entry->insert_time()->toStringShort(),
            "relevance_time" => $relevance_time_str,
            "run" => $run_number_str,
            "shift" => $shift_begin_time_str,
            "author" => $entry->author(),
            "html" => $con->html()
        )
    );
}

/*
 * Analyze and process the request
 */
try {

    $logbook = new LogBook();
    $logbook->begin();

    $experiment = $logbook->find_experiment_by_id( $exper_id )
        or die( "no such experiment" );

    $instrument = $experiment->instrument();

    // Check for the authorization
    //
    if( !LogBookAuth::instance()->canRead( $experiment->id())) {
        print( LogBookAuth::reporErrorHtml(
            'You are not authorized to access any information about the experiment' ));
        exit;
    }

    // Proceed to the operation
    //
    header( "Content-type: application/json" );
    header( "Cache-Control: no-cache, must-revalidate" ); // HTTP/1.1
    header( "Expires: Sat, 26 Jul 1997 05:00:00 GMT" );   // Date in the past
    print <<< HERE
{
  "ResultSet": {
    "Result": [
HERE;
    $first = true;

    if( $type == TYPE_HISTORY_P ) {

        $entries = $experiment->entries_of_experiment( null, $experiment->begin_time());
        foreach( $entries as $e ) {
          if( $first ) {
              $first = false;
              echo "\n".entry2json( $e );
          } else {
              echo ",\n".entry2json( $e );
          }
        }

    } else if( $type == TYPE_HISTORY_D ) {
        $days = $experiment->days();
        foreach( $days as $d ) {
          if( $first ) {
              $first = false;
              echo "\n".day2json( $d );
          } else {
              echo ",\n".day2json( $d );
          }
        }

    } else if( $type == TYPE_HISTORY_D_DAY ) {

        if( !isset( $_GET['begin'] )) die( "no valid begin time in the history range request" );
        $begin = LusiTime::from64( trim( $_GET['begin'] ));

        if( !isset( $_GET['end'] )) die( "no valid end time in the history range request" );
        $end = LusiTime::from64( trim( $_GET['end'] ));

        $entries = $experiment->entries_of_experiment( $begin, $end );
        foreach( $entries as $e ) {
          if( $first ) {
              $first = false;
              echo "\n".entry2json( $e );
          } else {
              echo ",\n".entry2json( $e );
          }
        }

    } else if( $type == TYPE_HISTORY_F ) {

        $entries = $experiment->entries_of_experiment( $experiment->end_time(), null );
        foreach( $entries as $e ) {
          if( $first ) {
              $first = false;
              echo "\n".entry2json( $e );
          } else {
              echo ",\n".entry2json( $e );
          }
        }

    } else if( $type == TYPE_SHIFTS ) {
        $shifts = $experiment->shifts();
        foreach( $shifts as $s ) {
          if( $first ) {
              $first = false;
              echo "\n".shift2json( $s );
          } else {
              echo ",\n".shift2json( $s );
          }
        }

    } else if( $type == TYPE_RUNS ) {
        $runs = $experiment->runs();
        foreach( $runs as $r ) {
          if( $first ) {
              $first = false;
              echo "\n".run2json( $r );
          } else {
              echo ",\n".run2json( $r );
          }
        }

    } else {
        ;
    }
    print <<< HERE
 ] } }
HERE;

    $logbook->commit();

} catch( LogBookException $e ) {
    print $e->toHtml();
} catch( LusiTimeException $e ) {
    print $e->toHtml();
} catch( RegDBException $e ) {
    print $e->toHtml();
}
?>
