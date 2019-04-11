#!/usr/bin/php
<?php
function ft_is_sort($tab)
{
	$i = 0;
	$n = 0;
	$tmp = $tab;
	$rev = array_reverse($tab);
	sort($tab);
	while(isset($tab[$i]) && isset($rev[$n]))
	{
		if ((strcmp($tab[$i], $tmp[$i])) == 0)
			$i++;
		elseif ((strcmp($rev[$n], $tab[$n])) == 0)
			$n++;
		else
			return (0);
	}
	return (1);
}
?>