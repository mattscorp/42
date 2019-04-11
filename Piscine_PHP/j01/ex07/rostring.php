#!/usr/bin/php
<?php
function ft_split($string){
$my_tab = explode(" ", $string);
return $my_tab;
}
if ($argc > 1){
$ret = preg_replace("# +#", " ", $argv[1]);
$ret = trim($ret);
$ret = ft_split($ret);

$i = 1;
while($ret[$i])
{
	echo "$ret[$i]"." ";
	$i++;
}
echo "$ret[0]"."\n";
}
else
	return;
?>