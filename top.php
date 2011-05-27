#!/usr/bin/php -e
<?php
error_reporting(E_ALL);

if (0 > version_compare(PHP_VERSION, '5')) {
    die('This file was generated for PHP 5');
}

require_once('PomGenerator/class.UpdatePomGenerator.php');

$scriptName = $argv[0];
$projectName = $argv[1];
$modulesList = $argv[2];
$modulesList = "<module>".$modulesList."</modules>";

$hode = new PomGenerator_UpdatePomGenerator($projectName,$modulesList);
$hode->printHeader();

?>
