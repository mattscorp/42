   var video = document.getElementById('canvas0');

   var tmp = document.getElementById('canvastmp');
   var context_tmp = tmp.getContext('2d');
   var c = document.getElementById("filtres");

   var canvas = document.getElementById('canvas');
   var context = canvas.getContext('2d');

   var cadre = document.getElementById('stikers');
   var blanc = document.getElementById('blanc.png');

   var base64 = document.getElementById("base64");
   var id_cadre_selected = "NOP";

   let control_filtres = undefined;
   let control_canvastmp = undefined;
   let control_canvas = undefined;

//AFFICHE LE STREAM DE LA VIDEO DANS LE CANVA
   if(navigator.mediaDevices && navigator.mediaDevices.getUserMedia) {
    navigator.mediaDevices.getUserMedia({ video: true }).then(function(stream) {
        video.srcObject = stream;
        video.play();

    }).catch(function(err) {
    console.log("veuillez activer votre camera");
  });

   }
   //TRACE BLANC DANS LES CANVAS
   window.onload = function() {

   var tempo = document.getElementById("canvastmp");
   var c = document.getElementById("filtres");
   var montage = document.getElementById("canvas");
   var ctx_tempo = tempo.getContext("2d");
   var ctx = c.getContext("2d");
   var ctx_montage = montage.getContext("2d");
   var img = blanc;
   ctx_tempo.drawImage(img, 0, 0, 640, 480);
   ctx.drawImage(img, 0, 0, 640, 480);
   ctx_montage.drawImage(img, 0, 0, 640, 480);
    control_filtres = c.toDataURL();
    control_canvastmp = tmp.toDataURL();
    control_canvas = canvas.toDataURL();
  }
  //TRACK L ID DU CADRE SELECTIONNE
  function reply_click(clicked_id)
  {
     id_cadre_selected = clicked_id;
     var c = document.getElementById("filtres");
     var ctx = c.getContext("2d");
     var img = document.getElementById(id_cadre_selected);
     ctx.drawImage(blanc, 0, 0, 640, 480);
     ctx.drawImage(img, 0, 0, 640, 480);
     context.drawImage(blanc, 0, 0, 640, 480);
     context.drawImage(tmp, 0, 0, 640, 480);
     context.drawImage(img, 0, 0, 640, 480);
  }

  


  //EFFECTUE LA PRISE DE LA PHOTO DESSINE LA PHOTO VIA LA VARIABLE VIDEO 
  //PUIS DESSINE LE CADRE DANS LE MEME CANVA
  //SUOERPOSSITION DES CANVAS
document.getElementById("snap").onclick = function() {
       // SI AUCUN CADRFE N A ETE SELECTIONNE
        if (id_cadre_selected === "NOP") {
          alert("SELECTIONNER UN CADRE AVANT DE PRENDRE UNE PHOTO");
          return(0);
        }
       context.drawImage(video, 0, 0, 640, 480);
       var c = document.getElementById("canvas");
       var ctx = c.getContext("2d");

       context_tmp.drawImage(video, 0, 0, 640, 480);

       var img = document.getElementById(id_cadre_selected);
       ctx.drawImage(img, 0, 0, 640, 480);
   }

document.getElementById("send").onclick = function(e) {
   var control_filtres_2 = c.toDataURL();
   var control_canvastmp_2 = tmp.toDataURL();
   var control_canvas_2 = canvas.toDataURL();
      if (control_filtres_2.localeCompare(control_filtres) != 0 && control_canvastmp.localeCompare(control_canvastmp_2) != 0 && control_canvas.localeCompare(control_canvas_2) != 0 ) {
          var imagetosave = canvas.toDataURL();
          document.getElementById("base64").value = imagetosave;
      }
    else
    {
      alert("Veuillez selectionner un cadre puis prendre une photo");
    }
  }


   // UPLOAD IMAGE

var imageLoader = document.getElementById('imageLoader');
    imageLoader.addEventListener('change', handleImage, false);
function handleImage(e){
  if (id_cadre_selected === "NOP") {
          alert("SELECTIONNER UN CADRE AVANT DE TELECHARGER UNE PHOTO");
          document.getElementById('imageLoader').value = "";
          return(0);
        }
    var reader = new FileReader();
    reader.onload = function(event){
        var img_dl = new Image();
        var cadre = document.getElementById(id_cadre_selected);
        img_dl.onload = function(){
            canvas.width = 640;
            canvas.height = 480;
            context.drawImage(img_dl,0, 0, 640, 480);
            context.drawImage(cadre, 0, 0, 640, 480);
            context_tmp.drawImage(img_dl,0, 0, 640, 480);
        }
        img_dl.src = event.target.result;
    }
    reader.readAsDataURL(e.target.files[0]);     
}