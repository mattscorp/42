//**************************mini_lib_camagru made by agasparo*********************************\\

var fade_timer;
var opa = 0;

//********************************************************************************************\\
// 					fonction qui permet de faire des requetes ajax avec POST.                 \\
//										pour l'utiliser : 									  \\ 
//	post_page('url_de_la_cible', {param:value_param, param2:value_param2...}, function(data) {\\
//       console.log(data);    																  \\
//	});   																					  \\
//********************************************************************************************\\

function post_page(url, infos, callback) {
	let http_req = new XMLHttpRequest();

	http_req.onreadystatechange = function () {
		if (http_req.readyState === 4) {
			callback(http_req.responseText);
		}
	}
	http_req.open('POST', url, true);
	http_req.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
	let variables = "";
	let i  = 0;
	Object.keys(infos).forEach(function (key){
		i++;
	});
	i--;
	Object.keys(infos).forEach(function (key){
		if (i - 1 >= 0)
			variables = variables+key+'='+encodeURIComponent(infos[key])+'&';
		else
			variables = variables+key+'='+encodeURIComponent(infos[key]);
		i--;
	});
	http_req.send(variables);
}

// Exemple : 
// post_page('test.php', {nom:'gasparotto', prenom:'arthur'}, function(data) {
//       console.log(data);
//	});
//
// test.php : <?php var_dump($_POST); ?>
// ceci retournera :
// array(2) {
//	  ["nom"]=>
//	  string(10) "gasparotto"
//	  ["prenom"]=>
//	  string(6) "arthur"
// }

//********************************************************************************************\\
// 					fonction qui permet de faire comme la function load 	                  \\
//										pour l'utiliser : 									  \\ 
//	load("url_de_la_cible", elem_ou_charger_la_page);                                         \\  																					  \\
//********************************************************************************************\\

function load(url, element) {
    req = new XMLHttpRequest();
    req.open("POST", url, false);
    req.send(null);

    element.innerHTML = req.responseText; 
}

// Exemple : 
// load("test.php", document.getElementById("img_show"));
//
// test.php : <?php echo "ok"; ?>
// ceci retournera :
// ok
// dans la div


//********************************************************************************************\\
// 					fonction qui permet de faire comme la function fadein / fadeout           \\
//										pour l'utiliser : 									  \\ 
//	fade('in ou out', element_cible);                                                         \\  																					  \\
//********************************************************************************************\\

function fade(type, elem) {
	if (type === 'in') {
		elem.style.opacity = 0;
		fade_timer = setInterval(function(){ fadein(elem); }, 50);
	} else {
		fade_timer = setInterval(function(){ fadeout(elem); }, 50);
	}
}

function fadeout(elem) {
	if (elem.style.opacity <= 0.1)
		clearInterval(fade_timer);
	elem.style.opacity = elem.style.opacity - 0.1;
}

function fadein(elem) {
	if (elem.style.opacity >= 1.1)
		clearInterval(fade_timer);
	elem.style.opacity = opa;
	opa = opa + 0.1;
}

//********************************************************************************************\\
// 					fonction qui permet de faire comme la function resize                     \\
//										pour l'utiliser : 									  \\ 
//	resize(id_de_l_elemnt_cible);                                                             \\  																					  \\
//********************************************************************************************\\

function resize(id) {
	var box = document.getElementById(id);
	box.style.cursor = 'pointer';
	box.addEventListener('mousedown', initialiseResize, false);

	function initialiseResize(e) {
		window.addEventListener('mousemove', startResizing, false);
		window.addEventListener('mouseup', stopResizing, false);
	}

	function startResizing(e) {
		box.style.width = (e.clientX - box.offsetLeft) + 'px';
		box.style.height = (e.clientY - box.offsetTop) + 'px';
	}
	function stopResizing(e) {
		window.removeEventListener('mousemove', startResizing, false);
		window.removeEventListener('mouseup', stopResizing, false);
	}
}

//********************************************************************************************\\
// 					fonction qui permet d'upload une image                                    \\
//										pour l'utiliser : 									  \\ 
//	upload_fil_img(elem_file_du_formulaire, page_cible);                                      \\  																					  \\
//********************************************************************************************\\
// envoye a la page ciblee 2 valeures : 
// 1 - l'image en base64 ($base64)
// 2 - le type de l'image (ex : png, jpg ...) | ($img_type)

function upload_fil_img(elem, page_cible) {

	if (elem.files && elem.files[0]) {
		var reader = new FileReader();

		reader.onload = function(e) {
			var dat = e.target.result.split('/');
			var base = dat[1].split(';');
			if (dat[0] == "data:image") {
				post_page(page_cible, {base64:e.target.result, img_type:base[0]}, function(data) {
					console.log(data);
				});
			}
		};

		reader.readAsDataURL(elem.files[0]);
	}
}