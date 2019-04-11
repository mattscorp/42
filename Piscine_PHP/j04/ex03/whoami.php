<?php 
session_start();

if (!empty($_SESSION['loggued_on_user']))
{
	$ret = $_SESSION['loggued_on_user'];
	echo "$ret\n";
}
else{
	echo "ERROR\n";
}
?>