<?php
session_start();
$bdd = new PDO('mysql:host=localhost;dbname=db_camagru', 'root', '123456');

if(isset($_GET['id']) AND $_GET['id'] > 0)
{
   $getid = intval($_GET['id']);
   $requser = $bdd->prepare('SELECT * FROM users WHERE id = ?');
   $requser->execute(array($getid));
   $userinfo = $requser->fetch();
?>
<html>
<head>
   <title></title>

</head>
<body>


<div class="inscription" >

   <h3>Profil de <?php echo $userinfo['pseudo']; ?></h3>
   <br>
   Pseudo =  <?php echo $userinfo['pseudo']; ?>
   <br>
   Mail =  <?php echo $userinfo['mail']; ?>
     <br>
<?php
if(isset($_SESSION['id']) AND $userinfo['id'] == $_SESSION['id'])
{
?>
<a href="edition_profil.php">EDITER MON PROFIL</a>
<a href="deconnexion.php">SE DECONNECTER</a>
<?php
}
?>
</div>
</body>
</html>
<?php
}
?>