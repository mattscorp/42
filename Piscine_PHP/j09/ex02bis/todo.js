window.onload = function() {
var tab_cook = document.cookie;
var tab_cook = tab_cook.split(";");
var i = 0;
while (tab_cook[i])
{
	if (tab_cook[i] !== null)
	{ 
		var new_div = document.createElement("DIV");
		var request = tab_cook[i].split("=");
  		new_div.innerText = request[0].trim();
  		new_div.id = request[0].trim();
  		var name = new_div.id;
  		console.log(new_div.id);
  		$('#ft_list').prepend($("<div id="+name+">"+name+"</div>").click(ft_delete));
	}
	i++;
}

function ft_already(request) {
	var tab_cook = document.cookie;
	var tab_cook = tab_cook.split(";");
	var i = 0;
	while (tab_cook[i])
	{
		var to_check = tab_cook[i].split("=");
		if(request.trim() == to_check[0].trim())
			return 1;
		i++;
	}
	return 0;
}
		$('#new').click(function get_the_request() {
		var request = prompt("Please enter a new thing to do", "buy unicorn").trim();
		request = request.replace(/=/g, '');
		request = request.replace(/;/g, '');
				if (request != "" && request != null && ft_already(request) === 0)
		{
			document.cookie = request+" = "+request+"; expires=Thu, 18 Dec 2023 12:00:00 UTC";
			location.reload();
		}
	});
function ft_delete(new_div_id) {
		var request = prompt("Do you want to remove this ?", "enter yes or no");
		if(request === "no")
			return;
		else if (request === "yes")
		{
			document.cookie = new_div_id.target.id+" = "+new_div_id.target.id+";expires=Thu, 01 Jan 1970 00:00:01 GMT";
			location.reload();
			return;
		}
		else
			alert("You can only answer the question by tapping yes or no");
		return;
	}
}