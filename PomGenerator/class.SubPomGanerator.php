<?php

error_reporting(E_ALL);

/**
 * untitledModel - PomGenerator\class.SubPomGanerator.php
 *
 * $Id$
 *
 * This file is part of untitledModel.
 *
 * Automatically generated on 27.05.2011, 18:13:52 with ArgoUML PHP module 
 * (last revised $Date: 2010-01-12 20:14:42 +0100 (Tue, 12 Jan 2010) $)
 *
 * @author firstname and lastname of author, <author@example.org>
 * @package PomGenerator
 */

if (0 > version_compare(PHP_VERSION, '5')) {
    die('This file was generated for PHP 5');
}

/**
 * include PomGenerator_PomGenerator
 *
 * @author firstname and lastname of author, <author@example.org>
 */
require_once('PomGenerator/class.PomGenerator.php');

/* user defined includes */
// section -64--88-1-66--3980adbb:13030b35d90:-8000:0000000000000AB7-includes begin
// section -64--88-1-66--3980adbb:13030b35d90:-8000:0000000000000AB7-includes end

/* user defined constants */
// section -64--88-1-66--3980adbb:13030b35d90:-8000:0000000000000AB7-constants begin
// section -64--88-1-66--3980adbb:13030b35d90:-8000:0000000000000AB7-constants end

/**
 * Short description of class PomGenerator_SubPomGanerator
 *
 * @access public
 * @author firstname and lastname of author, <author@example.org>
 * @package PomGenerator
 */
class PomGenerator_SubPomGanerator
    extends PomGenerator_PomGenerator
{
    // --- ASSOCIATIONS ---


    // --- ATTRIBUTES ---

    // --- OPERATIONS ---
    public function printAll(){
	$this->printHeader();
	$this->printPearent();
	$this->printBody();
	$this->printFutter();
    }
    /**
     * Short description of method printPearent
     *
     * @access public
     * @author firstname and lastname of author, <author@example.org>
     * @return mixed
     */
    public function printPearent()
    {
        // section -64--88-1-66--3980adbb:13030b35d90:-8000:0000000000000ABC begin
	echo "
	<parent>
		<groupId>$this->groupName</groupId>
		<artifactId>$this->projectName-parent</artifactId>
		<version>$this->version</version>
	</parent>
	";
        // section -64--88-1-66--3980adbb:13030b35d90:-8000:0000000000000ABC end
    }

} /* end of class PomGenerator_SubPomGanerator */

?>
