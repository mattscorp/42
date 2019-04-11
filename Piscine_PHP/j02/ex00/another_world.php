#!/usr/bin/php
<?php
if ($argc < 2)
	exit;
$ret = str_replace("\t", " ", $argv[1]);
$ret = preg_replace("# +#", " ", $ret);
$ret = trim($ret);
echo($ret)."\n";
?>