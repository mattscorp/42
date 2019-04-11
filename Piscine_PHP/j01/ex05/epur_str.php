#!/usr/bin/php
<?php
if (count($argv) == 2){
$ret = str_replace("\t", " ", $argv[1]);
$ret = preg_replace("# +#", " ", $ret);
$ret = trim($ret);
echo($ret)."\n";
}
else {
	exit;
}
?>