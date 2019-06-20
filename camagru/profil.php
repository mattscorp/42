<?php
session_start();
include("coco.php");
$id = $_SESSION['id'];
$link = "profil.php?id=".$id;
if(isset($_GET['id']) AND $_GET['id'] > 0 AND isset($_SESSION['id']) AND $_SESSION['id'] > 0)
{
  if($_GET['id'] !== $_SESSION['id'])
  {
    header('location: index.php');
  }
   $getid = intval($_GET['id']);
   $requser = $bdd->prepare('SELECT * FROM users WHERE id = ?');
   $requser->execute(array($getid));
   $userinfo = $requser->fetch();
   $mycollection = $bdd->prepare("SELECT * FROM images WHERE id_user_img = ? ORDER BY id_img DESC");
   $mycollection->execute(array($id));
?>
<html>
<head>
   <title>Profil de <?php echo $userinfo['pseudo']; ?></title>
    <link href="styles.css" rel="stylesheet">
   </head>
<body>
       <?php include("header_co.php");?>
      <div class="inscription" >
         <table>
         <td><h3>Profil de <?php echo $userinfo['pseudo']; ?></h3></td>
       </tr>
      <tr>
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
       <tr>
         <td><a href="index.php">HOME PAGE</a></td>
       </tr>
       <tr>
          <td>
    <div id="collection" class="collection">
      <?php
        while( $gallerie = $mycollection->fetch())
            {
              if (empty($gallerie['link_img']))
              {
                echo "<h3> TA GALLERIE SERA LA <h3>";
              }
            else
              echo "<img class='img_suppr' id="."'".$gallerie['link_img']."' src="."'".$gallerie['link_img']."' width='320' height='240'<br>";
          }
      ?>
    </div>
  </td>
       </tr>
       <script type="text/javascript" src="js/profil.js"> </script>
</body>
</html>
<?php
}
}
?>