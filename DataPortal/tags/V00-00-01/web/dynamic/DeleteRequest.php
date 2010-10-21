<?php

require_once('AuthDB/AuthDB.inc.php');
require_once('FileMgr/FileMgr.inc.php');

/* This script will delete a pending translation request for the specified
 * identifier and, if successfull, return a JSON object describing the deleted
 * request. Otherwise another JSON object with an explanation of the problem will be returned.
 */

/**
 * This function is used to report errors back to the script caller applications
 *
 * @param $msg - a message to be reported
 */
function return_error( $msg ) {

	header( 'Content-type: application/json' );
	header( 'Cache-Control: no-cache, must-revalidate' ); // HTTP/1.1
	header( 'Expires: Sat, 26 Jul 1997 05:00:00 GMT' );   // Date in the past

	echo '{"ResultSet":{"Status":"error","Reason":"'.json_encode( $msg ).'"}}';

	exit;
}

/* Translate & analyze input parameters
 */
if( !isset( $_GET[ 'id' ] ))
	return_error( 'no request identifier parameter found' );

$id = (int)trim( $_GET[ 'id' ] );
if( $id <= 0 )
	return_error( 'invalid request identifier' );

/**
 * Produce a document with JSON representation of successfully
 * deleted requests.
 *
 * @param $result - an array of requests
 */	
function return_result( $request ) {

	header( 'Content-type: application/json' );
	header( 'Cache-Control: no-cache, must-revalidate' ); // HTTP/1.1
	header( 'Expires: Sat, 26 Jul 1997 05:00:00 GMT' );   // Date in the past

	echo '{"ResultSet":{"Status":"success","Result":'.json_encode( $request ).'}}';

	exit;
}

try {
	$authdb = new AuthDB();
	$authdb->begin();

	$request = null;
	FileMgrIfaceCtrlWs::delete_request(
		$request,
		$id );

	return_result( $request );

} catch( AuthDBException $e ) {
	return_error( $e->toHtml());
} catch( LogBookException $e ) {
	return_error( $e->toHtml());
} catch( FileMgrException $e ) {
	return_error( $e->toHtml());
}
?>
