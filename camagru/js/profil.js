//TRAQUE L IMAGE POUR LA SUPPRESSION
   if (document.getElementById("collection")){
      let imgs_suppr = document.querySelectorAll('.img_suppr');
      let i = 0;
      while (i < imgs_suppr.length) {
        imgs_suppr[i].addEventListener('click', suppr_img);
        i++;
      }
    }
    function suppr_img(e) {
      let confirmation = window.confirm("Veux tu supprimer cette image ?");
      if (confirmation){
        let id = e.target.id;
        window.location="sup.php?id="+encodeURIComponent(id);
      }
      else
        return;
    //  console.log(e.target.src);
      
    }