<?php
function user_exist($login)
{
	if(!file_exists("../private/passwd"))
	{
		return (-2);
	}
	else{
		$previous = file_get_contents("../private/passwd");
		$check = unserialize($previous);
		$i = 0;
		while(isset($check[$i]))
		{
			if ($check[$i]['login'] == $login)
			{	
				return($i);
			}
			$i++;
		}
		return(-1);
	}
}
if(!empty($_POST) AND isset($_POST['login']) AND !empty($_POST['login']) AND isset($_POST['oldpw']) AND !empty($_POST['oldpw']) AND isset($_POST['newpw']) AND !empty($_POST['newpw']) AND ($_POST['submit'] == "OK"))
{
	$tab_log_pwd['login'] = $_POST['login'];
	$old = hash('whirlpool', $_POST['oldpw']);
	$new = hash('whirlpool', $_POST['newpw']);
	if (user_exist($tab_log_pwd['login']) == -2)
	{
		echo "ERROR\n";
	} 
	else if (user_exist($tab_log_pwd['login']) >= 0)
	{
		$i = user_exist($tab_log_pwd['login']);
		$previous = file_get_contents("../private/passwd");
		$check = unserialize($previous);
		if ($check[$i]['passwd'] == $old)
		{
			if ($check[$i]['passwd'] != $new)
			{

				$check[$i]['passwd'] = $new;

				file_put_contents("../private/passwd",serialize($check), FILE_USE_INCLUDE_PATH);
				echo "OK\n";
			}
			else
				echo "ERROR\n";
		}
		else
			echo "ERROR\n";
	}
	else
		echo "ERROR\n";
}
else
		echo "ERROR\n";
?>