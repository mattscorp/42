<?php
function auth($login, $passwd)
{
	$passwd = hash('whirlpool', $passwd);
	$index = file_get_contents("../private/passwd");
	$index = unserialize($index);
	$i = 0;
	while (isset($index[$i]))
	{
		if($index[$i]['login'] == $login AND $index[$i]['passwd'] == $passwd)
			return (TRUE);
		$i++;
	}
	return (FALSE);
}

/* DEBUG*/
/*$index = file_get_contents("./private/passwd");
$index = unserialize($index);

$ret = auth(matt, matt);
echo "$ret\n";

	print_r($index);
*/
?>%