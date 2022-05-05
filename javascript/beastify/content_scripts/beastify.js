// I didn't understand this syntax
// I think it is the syntax of immediately executing anonymous functions
(function(){

    if (window.hasRun)
	return;
    window.hasRun = true;

    function insertBeast(beastURL){
	removeExistingBeasts();
	let beastImage = document.createElement("img");
	beastImage.setAttribute("src", beastURL);
	beastImage.style.height = "100vh";
	beastImage.className = "beastify-image";
	document.body.appendChild(beastImage);
    }

    function removeExistingBeasts(){
	let existingBeasts = document.querySelectorAll(".beastify-image");
	for (let beast of existingBeasts)
	    beast.remove();
    }

    function messageRemoveBeasts(message){
	if (message.command = "beastify")
	    insertBeast(message.beastURL);
	else if (message.command = "reset")
	    removeExistingBeasts();
    }

    browser.runtime.onMessage.addListener(messageRemoveBeasts)

)();
