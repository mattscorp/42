   var video = document.getElementById('canvas0');
   var canvas = document.getElementById('canvas');
   var context = canvas.getContext('2d');
   var cadre = document.getElementById('stikers');
   var blanc = document.getElementById('blanc.png');
   var id_cadre_selected = "NOP";
  
   if(navigator.mediaDevices && navigator.mediaDevices.getUserMedia) {
    navigator.mediaDevices.getUserMedia({ video: true }).then(function(stream) {
        video.srcObject = stream;
        video.play();

    });
   }
   window.onload = function() {
   var c = document.getElementById("filtres");
   var ctx = c.getContext("2d");
   var img = blanc;
   ctx.drawImage(img, 0, 0, 640, 480);
  }

  function reply_click(clicked_id)
  {
     id_cadre_selected = clicked_id;
     var c = document.getElementById("filtres");
     var ctx = c.getContext("2d");
     var img = document.getElementById(id_cadre_selected);
     ctx.drawImage(blanc, 0, 0, 640, 480);
     ctx.drawImage(img, 0, 0, 640, 480);
  }

   document.getElementById("snap").onclick = function() {

        if (id_cadre_selected === "NOP") {
          alert("SELECTIONNER UN CADRE AVANT DE PRENDRE UNE PHOTO");
          exit();
        }
        
       context.drawImage(video, 0, 0, 640, 480);
       var c = document.getElementById("canvas");
       var ctx = c.getContext("2d");
       var img = document.getElementById(id_cadre_selected);
       ctx.drawImage(img, 0, 0, 640, 480);
       var imagetosave = canvas.toDataURL();
      
       console.log(imagetosave);
   }