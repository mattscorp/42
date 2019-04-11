#!/usr/bin/php
<?php
function ft_split($string){
$my_tab = explode(" ", $string);
sort($my_tab);
return $my_tab;
}
if ($argc < 2)
	exit;
else
{
$i = 1;
while(isset($argv[$i]))
{
	$ret = preg_replace("# +#", " ", $argv[$i]);
	$tmp = $tmp." ".trim($ret);
		$i++;
}
$tmp = trim($tmp);
$tab = ft_split($tmp);
$i = 0;
while(isset($tab[$i]))
{
	echo $tab[$i]."\n";
	$i++;
}
}
?>