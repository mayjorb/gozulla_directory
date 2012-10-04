<?php

/*
 * Run this script in CLI after setting your key and secrect below. See https://github.com/Factual/factual-php-driver#testing
 */

//Add your key and secret here
$key = "";
$secret = "";

//Add filename for to log results to file, if required (echoes to screen by default)
$logFile = "";

//Set error level -- best not to change this.
error_reporting (E_ERROR);

//check that key/secret are populated
if (!$key || !$secret){
	echo "Add your key and secret to test.php before running this script\n";
	echo "See https://github.com/Factual/factual-php-driver/wiki/Getting-Started for more info\n";
	exit;
}

require_once('FactualTest.php');
	
//Run tests	
$factualTest = new factualTest($key,$secret);	
$factualTest->setLogFile($logFile);   
$factualTest->test();

?>
