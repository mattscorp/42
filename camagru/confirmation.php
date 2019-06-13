<?php
include("coco.php");

if(isset($_GET['pseudo'], $_GET['key']) AND !empty($_GET['pseudo']) AND !empty($_GET['key'])){
	$pseudo = htmlspecialchars(urldecode($_GET['pseudo']));
	$key = intval($_GET['key']);

	$requser = $bdd->prepare("SELECT * FROM users WHERE pseudo = ? AND confirmkey = ?");
	$requser->execute(array($pseudo, $key));
	$userexist = $requser->rowCount();

	if($userexist == 1)
	{
		$user = $requser->fetch();
		if($user['confirm'] == 0){
			$updateuser = $bdd->prepare("UPDATE users SET confirm = 1 WHERE pseudo = ? AND confirmkey = ?");
			$updateuser->execute(array($pseudo,$key));
			echo "Votre compte a bien ete confirme";
		}
		else 
			echo "Compte deja valide";
	}
	else 
		echo "L'utilisateur n'existe pas !";
}
?>