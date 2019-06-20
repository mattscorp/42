<?php
session_start();
include("coco.php");
if (isset($_SESSION['id']) AND $_SESSION['id'] > 0)
{
	$imgtosup = $_GET['id'];
	$rm_dbb = $bdd->prepare('DELETE FROM images WHERE link_img = ?');
	$rm_dbb->execute(array($imgtosup));
}
header("location:profil.php?id=".$_SESSION["id"]);
?>