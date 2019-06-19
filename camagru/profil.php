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
   $mycollection = $bdd->prepare("SELECT * FROM images WHERE id_user_img = ? ORDER BY id_img DESC");
   $mycollection->execute(array($id));
  // $gallerie = $mycollection->fetch();
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
     <label>Image File:</label><br/>
      <input type="file" id="imageLoader" name="imageLoader"/>
      <button id="snap">Snap Photo</button>
      <canvas id="canvas" width="640" height="480"></canvas>
              <form method="POST" name="form" id="form">
          <textarea class="blanc" name="base64" id="base64"></textarea>
          <button  id='send' type="submit">
            Send image
          </button>
        </form>
      <canvas hidden="hidden" id="canvastmp" width="640" height="480"></canvas>
      <canvas hidden="hidden" id="filtres" width="640" height="480"></canvas>


    </div>
  </td>
  <td>
    <div class="stikers">
        <p>Les effets disponibles</p>
     <?php
        $dir = "filtres/";
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
     </div> 
  </td>
  <td>
    <div class="collection">
      <?php
        while( $gallerie = $mycollection->fetch())
            {
              if (empty($gallerie['link_img']))
              {
                echo "<h3> TA GALLERIE SERA LA <h3>";
              }
            else
              echo "<img src="."'".$gallerie['link_img']."'"."width="."'320'"."height="."'240'". "<br>";
          }
      ?>
    </div>
  </td>

</tr>
</table>

<!--
  SAUVERGARDE DE L IMAGE EN PHP
  VIA JS
!-->
<?php
          if(isset($_POST['base64']) AND !empty($_POST['base64']))
          {
          $img = $_POST['base64'];
          $img = str_replace('data:image/png;base64,', '', $img);
          $img = str_replace(' ', '+', $img);
          $data = base64_decode($img);
          $file = 'images/'.$_SESSION['id'].'_'.date("YmdHis").'.png';
          $baseFromJavascript = $_POST['base64'];
          $base_to_php = explode(',', $baseFromJavascript);
          $data = base64_decode($base_to_php[1]);
          $filepath = "/images";
          // ENREGISTRE L IMAGE ET SAUVE LE PATH DANS LA BDD
          file_put_contents($file,$data);
          $linkimg = $bdd->prepare("INSERT INTO images(link_img, id_user_img, img_date) VALUES (?, ?, ?)");
          $linkimg->execute(array($file, $_SESSION['id'], date("YmdHis")));
          $file = "";
          $data = "";
          $img = "";
          $_POST['base64'] = "";
          header('Refresh:0; url=profil.php?id='.$_SESSION['id']);
          }
?>
<?php
}
?>
</div>
   <script type="text/javascript" src="js/scripts.js"> </script>
   <script type="text/javascript" src="js/camagru.js"> </script>
</body>
</html>
<?php
}
?>