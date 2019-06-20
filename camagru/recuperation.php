<?php
session_start();
include("coco.php");
if(isset($_SESSION['id']) AND !empty($_SESSION['id']))
{
	header('Location: profil.php?id='.$_SESSION['id']);
}
if(isset($_POST['pseudo']) AND !empty($_POST['pseudo']) AND isset($_POST['mail']) AND !empty($_POST['mail']) )
{
	  $pseudo_verif = htmlspecialchars($_POST['pseudo']);
	  $mail_verif = htmlspecialchars($_POST['mail']);
      $reqpseudo = $bdd->prepare("SELECT * FROM users WHERE pseudo = ?");
      $reqmail = $bdd->prepare("SELECT * FROM users WHERE mail = ?");
      $reqpseudo->execute(array($pseudo_verif));
      $reqmail->execute(array($mail_verif));
      $pseudoexist = $reqpseudo->rowCount();
      $mailexist = $reqmail->rowCount();
      if($pseudoexist == 1 AND $mailexist == 1)
      {
      	$data_user = $reqmail->fetch();
      	if ($data_user['confirm']== 1)
      	{
	      	$longueurKey = 10;
	        $key = $data_user['id']."_";
	        for ($i=1; $i < $longueurKey; $i++) { 
	           $key .= mt_rand(0,9);
        }
        $insert = $bdd->prepare("UPDATE users SET recup_mail = ? WHERE id = ?");
        $insert->execute(array($key, $data_user['id']));
        header('Location: connexion.php');
		$msg = "Un mail de reinitialisation vient de t'être envoyé";
      }
      else
      	$msg = "Ton mail n'a pas ete confirmer, confirme d'abord ton mail avant de pouvoir recuperer ton mot de passe";
  	}
      else
      	$msg = "Ton mail ou ton pseudo n'éxiste pas";
}
else
	$msg = "Ton mail et ton pseudo doivent être remplis";
?>
<html>
<head>
    <title>Recupération de mot de passe</title>
    <link href="styles.css" rel="stylesheet">
</head>
<body>
<?php include("header.php"); ?>
<div class="recuperation" >
   <h3>Recupération de mon mot de passe</h3>
   <form method="POST" action="">
      <label>Pseudo: </label>
      <input type="text" name="pseudo" placeholder="Ton Pseudo" autocomplete=""><br><br>
      <label>Mail: </label>
      <input type="text" name="mail" placeholder="Ton Mail" autocomplete=""><br><br>
      <input type="submit" value="Recupération">
   </form>
<?php  if(isset($msg)){echo $msg;}?>   
</div>
</body>
</html>