<html>
<body>
	<form method="POST" action="create.php">
		Identifiant: <input type="user_name" name="login" required <?php if(isset($_SESSION['user_name']) AND (!empty($_SESSION['user_name']))) {echo $_SESSION['user_name'];}?> <br>
		Adresse E-mail: <input type="mail" name="mail" required <?php if(isset($_SESSION['mail']) AND (!empty($_SESSION['mail']))) {echo $_SESSION['mail'];}?> <br>
		Mot de passe: <input type="password" name="passwd" required <?php if(isset($_SESSION['password']) AND (!empty($_SESSION['password']))) {echo $_SESSION['password'];}?> <br>
		<input type="submit" placeholder="OK" name = "submit" value = "OK">
	</form>
</body>
</html>
<?php
function user_exist($login)
{
	if(!file_exists("./private/passwd"))
	{
		return (2);
	}
	else{
		$previous = file_get_contents("./private/passwd");
		$check = unserialize($previous);
		$i = 0;
		while(isset($check[$i]))
		{
			if ($check[$i]['login'] == $login)
			{
				return(0);
			}
			$i++;
		}
		return(1);
	}
}
if(!empty($_POST) AND isset($_POST['login']) AND !empty($_POST['login']) AND isset($_POST['passwd']) AND !empty($_POST['passwd']) AND ($_POST['submit'] == "OK"))
{
	if (!file_exists("./private"))
		mkdir("./private");
	$tab_log_pwd['login'] = $_POST['login'];
	$tab_log_pwd['passwd'] = hash('whirlpool', $_POST['passwd']);
	if (user_exist($tab_log_pwd['login']) == 2)
	{
		$check[0] = $tab_log_pwd;
		file_put_contents("./private/passwd",serialize($check), FILE_USE_INCLUDE_PATH);
		echo "OK\n";
	} else if (user_exist($tab_log_pwd['login']) == 1)
	{
		$previous = file_get_contents("./private/passwd");
		$check = unserialize($previous);
		$check[count($check)] = $tab_log_pwd;
		file_put_contents("./private/passwd",serialize($check), FILE_USE_INCLUDE_PATH);
		echo "OK\n";
	}
	else
		echo "ERROR\n";
}
else
		echo "ERROR\n";
?>
