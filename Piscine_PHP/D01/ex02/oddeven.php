#!/usr/bin/php
<?php
function check($num) {
	if($num % 2 == 0)
	{
		echo "Le chiffre ".trim("$num")." est Pair\n";
	}
	else
	{
		echo "Le chiffre ".trim("$num")." est Impair\n";
	}
}
while (1)
{
echo "Entrez un nombre:";
$num = fgets(STDIN);
if ($num == eof)
	exit;
if ($num == 0)
	echo "Le chiffre 0 est Pair\n";
//echo "mon num = $num";
else if (is_int($num + 0) && intval($num))
	check($num);
else
	echo "'".trim("$num")."'"." n'est pas un chiffre\n";
//$num = intval($num);
}

?>