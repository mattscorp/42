<?php
session_start();
include("coco.php");
$id = $_SESSION['id'];
$link = "profil.php?id=".$id;
if(isset($_GET['id']) AND $_GET['id'] > 0)
{
   $getid = intval($_GET['id']);
   $requser = $bdd->prepare('SELECT * FROM users WHERE id = ?');
   $requser->execute(array($getid));
   $userinfo = $requser->fetch();
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
 <!--<tr>
 <tr>
   <td>Pseudo =  <?php echo $userinfo['pseudo']; ?></td>
 </tr>
 <tr>
   <td>Mail =  <?php echo $userinfo['mail']; ?></td>
 </tr>
-->
<?php
if(isset($_SESSION['id']) AND $userinfo['id'] == $_SESSION['id'])
{
?>
<!--
<tr>
   <td><a href="edition_profil.php">EDITER MON PROFIL</a></td>
 </tr>
<tr>
   <td><a href="deconnexion.php">SE DECONNECTER</a></td>
 </tr>
 <tr>
   <td><a href="index.php">HOME PAGE</a></td>
 </tr>
 -->
 <tr>
   <td>
    <div class="cam">
      <video  id="canvas0" width="640" height="480" autoplay></video>
      <button id="snap">Snap Photo</button>
      <canvas id="filtres" width="640" height="480"></canvas>
      <canvas id="canvas" width="640" height="480"></canvas>
      </td>
    </div>
    <div class="stikers">
      <td>
        <p>Les effets disponibles</p>
                <?php
        $dir = "filtres/";

        // Open a directory, and read its contents
        if (is_dir($dir)){
          if ($dh = opendir($dir)){
            while (($file = readdir($dh)) !== false){
             if($file[0]!= '.'){
              if($file === 'blanc.png'){

                echo "<img class=".'"blanc"'."onClick=".'"reply_click(this.id)"'."id='".$file."'"."src='/filtres/".$file."'"."width="."'0'"."height="."'0'". "<br>";
              }
              else
                echo "<img onClick=".'"reply_click(this.id)"'."id='".$file."'"."src='/filtres/".$file."'"."width="."'320'"."height="."'240'". "<br>";
            }
            }
            closedir($dh);
          }
        }
        ?>
       
      </td>
    </div>
   <script type="text/javascript" src="js/scripts.js"> </script>
   <script type="text/javascript" src="js/camagru.js"> </script>
 </tr>
</table>

<form action="upload.php" method="post" enctype="multipart/form-data">
    Select image to upload:
    <input type="file" name="fileToUpload" id="fileToUpload">
    <input type="submit" value="Upload Image" name="submit">
</form>


<?php
}
?>
</div>

</body>
</html>
<?php
}
?>