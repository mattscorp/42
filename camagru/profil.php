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
   <title>Mon Profil</title>

</head>
<body>


<div class="inscription" >
   <table>
<tr>
   <td><h3>Profil de <?php echo $userinfo['pseudo']; ?></h3></td>
 </tr>
 <tr>
   <td>Pseudo =  <?php echo $userinfo['pseudo']; ?></td>
 </tr>
 <tr>
   <td>Mail =  <?php echo $userinfo['mail']; ?></td>
 </tr>
<?php
if(isset($_SESSION['id']) AND $userinfo['id'] == $_SESSION['id'])
{
?>
<tr>
   <td><a href="edition_profil.php">EDITER MON PROFIL</a></td>
 </tr>
<tr>
   <td><a href="deconnexion.php">SE DECONNECTER</a></td>
 </tr>
</table>
<?php
}
?>
</div>
</body>
</html>
<?php
}
?>