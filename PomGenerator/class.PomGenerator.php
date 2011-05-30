<?php

error_reporting(E_ALL);

/**
 * untitledModel - PomGenerator\class.PomGenerator.php
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

/* user defined includes */
// section -64--88-1-67-3804dd1e:1302b37cea3:-8000:0000000000000AA1-includes begin
// section -64--88-1-67-3804dd1e:1302b37cea3:-8000:0000000000000AA1-includes end

/* user defined constants */
// section -64--88-1-67-3804dd1e:1302b37cea3:-8000:0000000000000AA1-constants begin
// section -64--88-1-67-3804dd1e:1302b37cea3:-8000:0000000000000AA1-constants end

/**
 * Short description of class PomGenerator_PomGenerator
 *
 * @access public
 * @author firstname and lastname of author, <author@example.org>
 * @package PomGenerator
 */
class PomGenerator_PomGenerator
{
    // --- ASSOCIATIONS ---
    public function __construct($projectName,$moduleList){
            $this->projectName = $projectName;
            $this->groupName = "jp.lnc.eclipse.".$projectName;
            $this->version = "1.0.0-SNAPSHOT";
	    $this->moduleList =$moduleList;
    }

    // --- ATTRIBUTES ---

    /**
     * Short description of attribute projectName
     *
     * @access public
     */
    public $projectName;

    /**
     * Short description of attribute moduleList
     *
     * @access public
     */
    public $moduleList;

    /**
     * Short description of attribute groupName
     *
     * @access public
     */
    public $groupName;

    /**
     * Short description of attribute version
     *
     * @access public
     */
    public $version;

    // --- OPERATIONS ---

    /**
     * Short description of method printAll
     *
     * @access public
     * @author firstname and lastname of author, <author@example.org>
     * @return mixed
     */
    public function printAll()
    {
        // section -64--88-1-67-3804dd1e:1302b37cea3:-8000:0000000000000AA9 begin
	$this->printHeader();
	$this->printBody();
	$this->printFutter();
        // section -64--88-1-67-3804dd1e:1302b37cea3:-8000:0000000000000AA9 end
    }

    /**
     * Short description of method printHeader
     *
     * @access public
     * @author firstname and lastname of author, <author@example.org>
     * @return mixed
     */
    public function printHeader()
    {
        // section -64--88-1-67-3804dd1e:1302b37cea3:-8000:0000000000000AAB begin
	echo '<?xml version="1.0" encoding="UTF-8"?>

<!-- Copyright (C) 2009, Igor Fedorenko <igor@ifedorenko.com> Copyright (C) 
	2010, Chris Aniszczyk <caniszczyk@gmail.com> All rights reserved. This program 
	and the accompanying materials are made available under the terms of the 
	Eclipse Public License v1.0 which accompanies this distribution, and is available 
	at http://www.eclipse.org/legal/epl-v10.html -->

<project xmlns="http://maven.apache.org/POM/4.0.0" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
	xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/maven-v4_0_0.xsd">
	<modelVersion>4.0.0</modelVersion>

	<prerequisites>
		<maven>3.0</maven>
	</prerequisites>';
	echo "
	<groupId>$this->groupName</groupId>
	<artifactId>$this->projectName-parent</artifactId>
	<version>$this->version</version>
	<packaging>pom</packaging>

	<name>Maven Example Parent (Incubation)</name>";
        // section -64--88-1-67-3804dd1e:1302b37cea3:-8000:0000000000000AAB end
    }

    /**
     * Short description of method printBody
     *
     * @access public
     * @author firstname and lastname of author, <author@example.org>
     * @return mixed
     */
    public function printBody()
    {
        // section -64--88-1-67-3804dd1e:1302b37cea3:-8000:0000000000000AB3 begin
        
	// section -64--88-1-67-3804dd1e:1302b37cea3:-8000:0000000000000AB3 end
    }

    /**
     * Short description of method printFutter
     *
     * @access public
     * @author firstname and lastname of author, <author@example.org>
     * @return mixed
     */
    public function printFutter()
    {
        // section -64--88-1-67-3804dd1e:1302b37cea3:-8000:0000000000000AB5 begin
        echo "</project>";
	// section -64--88-1-67-3804dd1e:1302b37cea3:-8000:0000000000000AB5 end
    }

} /* end of class PomGenerator_PomGenerator */

?>
