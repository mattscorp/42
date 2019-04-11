<?php
session_start();

if (isset($_GET['login']) AND !empty($_GET['login']) AND isset($_GET['passwd']) AND !empty($_GET['passwd']))
{
	$_SESSION['user_name'] = $_GET['login'];
	$_SESSION['password'] = $_GET['passwd'];
}
/*
print_r("$_SESSION[user_name]");
echo " ";
print_r("$_SESSION[password]");
*/

?>
<html><body>
<form method="get">
Identifiant: <input type="user_name" name="login" required value="<?php if(isset($_SESSION['user_name']) AND (!empty($_SESSION['user_name']))) {echo $_SESSION['user_name'];}?>" /><br />
Mot de passe: <input type="password" name="passwd" required value="<?php if(isset($_SESSION['password']) AND (!empty($_SESSION['password']))) {echo $_SESSION['password'];}?>" />
<input type="submit" placeholder="OK" name = "submit" value = "OK"/>
</form>
</body></html>
