#!/usr/bin/php
<?php
function da_sort($s1, $s2)
{
	$cmp = "abcdefghijklmnopqrstuvwxyz0123456789!\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~";
	$chaine1 = strtolower($s1);
	$chaine2 = strtolower($s2);
	$i = 0;
	while (($i < strlen($chaine1) || $i < strlen($chaine2))) 
	{
		if ($i >= strlen($chaine1))
			return(-1);
		if ($i >= strlen($chaine2))
			return(1);
		$pos1 = strpos($cmp, $chaine1[$i]);
		$pos2 = strpos($cmp, $chaine2[$i]);
		if ($pos1 < $pos2)
			return (-1);
		elseif ($pos1 > $pos2) {
			return (1);
		}
		else
			$i++;
	}
	return (0);
}
function ft_split($string)
{
	$my_tab = explode(" ", $string);
	return $my_tab;
}
$i = 1;
while(isset($argv[$i]))
{
	$ret = preg_replace("# +#", " ", $argv[$i]);
	$tmp = $tmp." ".trim($ret);
	$i++;
}
$tmp = trim($tmp);
$tmp = ft_split($tmp);
$i = 0;
$a = 0;
$k = 0;
while (isset($tmp[$i]))
{
	if (ctype_alnum($tmp[$i]) == 1)
		{
			$tab_alnu[$a] = $tmp[$i];
			$a++;
		}
	else
		{
			$tab_other[$k] = $tmp[$i];
			$k++;
		}
	$i++;
}
usort($tab_other, 'da_sort');
usort($tab_alnu, 'da_sort');
$tab_final = array_merge($tab_alnu, $tab_other);
$i = 0;
while (isset($tab_final[$i])) 
{
	$tab_final[$i] = trim($tab_final[$i]);
	echo "$tab_final[$i]"."\n";
	$i++;
}
?>