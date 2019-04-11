<?php
if(isset($_GET['action']))
{
	if($_GET['action'] === "set" AND isset($_GET['name']) AND isset($_GET['value']))
	{
		setcookie($_GET['name'],$_GET['value'], time() + 3600);
	}
	elseif ($_GET['action'] === "get" AND isset($_GET['name']))
	{
		if(!empty($_COOKIE[$_GET['name']]))
			echo $_COOKIE[$_GET['name']]."\n";
	}
	elseif ($_GET['action'] === "del" AND isset($_GET['name']))
	{
		setcookie($_GET['name']);
	}
}
?>