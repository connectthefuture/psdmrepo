<?php

require_once('LogBook.inc.php');

/*
 * This script will process a request for closing an existing experiment
 * in the database.
 */
if(isset($_POST['name']))
    $name = $_POST['name'];
else
    die( "no valid experiment name" );

if(isset($_POST['end_time'])) {
    $end_time = LogBookTime::parse($_POST['end_time']);
    if(is_null($end_time))
        die("end time has invalid format");
} else
    die( "no end time for experiment" );

/* Proceed with the operation
 */
try {
    $logbook = new LogBook();

    $experiment = $logbook->find_experiment_by_name( $name )
        or die("no such experiment");

    $experiment->close( $end_time );

} catch( LogBookException $e ) {
    print $e->toHtml();
    return;
}
?>
<!--
The page for reporting the information about the closed experiment.
-->
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Closed experiments</title>
    </head>
    <link rel="stylesheet" type="text/css" href="LogBookTest.css" />
    <body>
        <!------------------------------>
        <h1>Closed experiment</h1>
        <?php
        LogBookTestTable::Experiment()->show( array( $experiment ));
        ?>
        <h2>Its shifts</h2>
        <?php
        LogBookTestTable::Shift()->show( $experiment->shifts());
        ?>
        <h2>Its runs</h2>
        <?php
        LogBookTestTable::Run()->show( $experiment->runs());
        ?>    </body>
</html>
