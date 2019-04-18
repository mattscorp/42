<?php
session_start();
$bdd = new PDO('mysql:host=localhost;dbname=db_camagru', 'root', '123456');

if(isset($_POST['form_connexion']))
{
   $pseudo_connect = htmlspecialchars($_POST['pseudo_connect']);
   $mdp_connect = sha1($_POST['mdp_connect']);
   if(!empty($pseudo_connect) AND !empty($mdp_connect))
   {
      $requser = $bdd->prepare("SELECT * FROM users WHERE pseudo = ? AND mdp = ?");
      $requser->execute(array($pseudo_connect, $mdp_connect));
      $userexist = $requser->rowCount();
      if($userexist == 1)
      {
         $userinfo = $requser->fetch();
         $_SESSION['id'] = $userinfo['id'];
         $_SESSION['pseudo'] = $userinfo['pseudo'];
         $_SESSION['mail'] = $userinfo['mail'];
         header("Location: profil.php?id=".$_SESSION['id']);
      }
      else
      {
         $erreur = "Mauvais pseudo ou mot de passe";
      }
   }
   else
   {
      $erreur = "Tous les champs doivnt etre completer";
   }
}

?>
<html>
<head>
   <title></title>

</head>
<body>


<div class="inscription" >

   <h3>Connexion</h3>
   <br><br>
   <form method="POST" action="">
      <input type="text" name="pseudo_connect" placeholder="pseudo"/>
      <input type="password" name="mdp_connect" placeholder="mot de passe"/>
      <input type="submit" name="form_connexion" value="Se connecter" />


   </form>
<?php
   if(isset($erreur))
   {
      echo $erreur;
   }
?>
</div>
</body>
</html>

