<?php
session_start();
include("coco.php");
if(isset($_SESSION['id']) AND !empty($_SESSION['id']))
{  
   $requser = $bdd->prepare("SELECT * FROM users WHERE id = ?");
   $requser->execute(array($_SESSION['id']));
   $user = $requser->fetch();

   if (isset($_POST['newpseudo']) AND !empty($_POST['newpseudo']) AND ($_POST['newpseudo'] != $user['pseudo']))
   {
      $newpseudo = htmlspecialchars($_POST['newpseudo']);
      $reqpseudo = $bdd->prepare("SELECT * FROM users WHERE pseudo = ?");
      $reqpseudo->execute(array($newpseudo));
      $pseudoexist = $reqpseudo->rowCount();
      if($pseudoexist == 0) {
         $insertpseudo = $bdd->prepare("UPDATE users SET pseudo = ? WHERE id = ?");
         $insertpseudo->execute(array($newpseudo, $_SESSION['id']));
         header('Location: profil.php?id='.$_SESSION['id']);
      }
      else
         $msg = "Ce pseudo est deja utilisé =/";
   }
   if (isset($_POST['newmail']) AND !empty($_POST['newmail']) AND ($_POST['newmail'] != $user['mail']))
   {
      $newmail = htmlspecialchars($_POST['newmail']);
      $reqmail = $bdd->prepare("SELECT * FROM users WHERE mail = ?");
      $reqmail->execute(array($newmail));
      $mailexist = $reqmail->rowCount();
      if($mailexist == 0) {
         $insertmail = $bdd->prepare("UPDATE users SET mail = ? WHERE id = ?");
         $insertmail->execute(array($newmail, $_SESSION['id']));
         header('Location: profil.php?id='.$_SESSION['id']);
      }
      else
         $msg = "Ce mail est deja utilisé";
   }
   if (isset($_POST['newmdp1']) AND !empty($_POST['newmdp1']) AND isset($_POST['newmdp2']) AND !empty($_POST['newmdp2']))
   {
      if(preg_match('#^(?=.*[a-z])(?=.*[0-9])#', $_POST['newmdp1']))
      {
      
      $mdp1 = sha1($_POST['newmdp1']);
      $mdp2 = sha1($_POST['newmdp2']);
      if ($mdp1 == $mdp2)
      {
         $insertmdp = $bdd->prepare("UPDATE users SET mdp = ? WHERE id = ?");
         $insertmdp->execute(array($mdp1, $_SESSION['id']));
         header('Location: profil.php?id='.$_SESSION['id']);
      }
      
   }
      else
      {
         $msg = "Votre mot de passe doit faire au moins 6 caracteres et contenir au moins un chiffre et une lettre";
      }
   }
      else
      {
         $msg = "Les mots de passe ne correspondent pas !";
      }
?>
<html>
<head>
    <title>Edition de mon profil</title>
    <link href="styles.css" rel="stylesheet">
</head>
<body>
<?php include("header_co_ed.php"); ?>
<div class="inscription" >
   <h3>Edition de mon profil "<?php echo $user['pseudo']; ?>"</h3>
   <form method="POST" action="">
      <label>Pseudo: </label>
      <input type="text" name="newpseudo" placeholder="Pseudo" value="<?php echo $user['pseudo']; ?>"><br><br>
      <label>Mail: </label>
      <input type="text" name="newmail" placeholder="Mail" value="<?php echo $user['mail']; ?>"><br><br>
      <label>Mdp: </label>
      <input type="password" name="newmdp1" placeholder="Nouveau password" autocomplete=""><br><br>
      <label>Confirmation Mdp: </label>
      <input type="password" name="newmdp2" placeholder="Confirmation" autocomplete=""><br><br>
      <input type="submit" value="Mettre a jour mon profil">
   </form>
    <?php  if(isset($msg)){echo $msg;}?>   
</div>
</body>
</html>
<?php
}
else
   header("Location: connexion.php");
?>