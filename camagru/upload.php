<?php
session_start();
include("coco.php");
$id = $_SESSION['id'];
$link = "profil.php?id=".$id;
$target_dir = "images/";
$target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
$uploadOk = 1;
$imageFileType = strtolower(pathinfo($target_file,PATHINFO_EXTENSION));

$img = $_POST['img'];
      $img = str_replace('data:image/png;base64,', '', $img);
      $img = str_replace(' ', '+', $img);
      $data = base64_decode($img);
      $file = 'images/'.$_SESSION['id'].'_'.date("YmdHis").'.'."$imageFileType";
      
?>
<html>
<head>
   <title>Profil de <?php echo $userinfo['pseudo']; ?></title>
    <link href="styles.css" rel="stylesheet">
</head>
<body>
 <?php include("header_co.php");
 // Check if image file is a actual image or fake image
if(isset($_POST["submit"])) {
    $check = getimagesize($_FILES["fileToUpload"]["tmp_name"]);
    if($check !== false) {
        echo "File is an image - " . $check["mime"] . ".";
        $uploadOk = 1;
    } else {
        echo "File is not an image.";
        $uploadOk = 0;
    }
}
// Check if file already exists
if (file_exists($target_file)) {
    echo "Sorry, file already exists.";
    $uploadOk = 0;
}
// Check file size
if ($_FILES["fileToUpload"]["size"] > 50000000) {
    echo "Sorry, your file is too large.";
    $uploadOk = 0;
}
// Allow certain file formats
if($imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg"
&& $imageFileType != "gif" ) {
    echo "Sorry, only JPG, JPEG, PNG & GIF files are allowed.";
    $uploadOk = 0;
}
// Check if $uploadOk is set to 0 by an error
if ($uploadOk == 0) {
    echo "Sorry, your file was not uploaded.";
// if everything is ok, try to upload file
} else {
    if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file)) {
        rename($target_file, $file);
        $linkimg = $bdd->prepare("INSERT INTO images(link_img, id_user_img, img_date) VALUES (?, ?, ?)");
        $linkimg->execute(array($file, $_SESSION['id'], date("YmdHis")));
        header('Location: profil.php?id='.$_SESSION['id']);
    } 

    else {
        echo "Sorry, there was an error uploading your file.";
    }
}
?>
