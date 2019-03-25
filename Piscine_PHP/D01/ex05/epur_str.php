#!/usr/bin/php
<?php
if (count($argv) == 2){
$ret = preg_replace("# +#", " ", $argv[1]);
$ret = trim($ret);
echo($ret)."\n";
}
else {
	echo "\n";
}
?>