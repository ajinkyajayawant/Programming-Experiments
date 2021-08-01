/* I have no idea what this block does or how the syntax functions */

const hidePage = `body > :not(beastify-image){
display: none;
}`

/* document looks like an object */
function listenForClicks() {
    function clickAction(e){

	function beastify(tabs){
	    function beastNameToURL(beastName){
		switch (beastName){
		case "Frog":
		    return browser.runtime.getURL("beasts/frog.jpg");
		case "Snake":
		    return browser.runtime.getURL("beasts/snake.jpg");
		case "Turtle":
		    return browser.runtime.getURL("beasts/turtle.jpg");
		}
	    }

	    function beastifyMessage(){
		let url = beastNameToURL(e.target.textContent);
		browser.tabs.sendMessage(tabs[0].id, {command: "beastify", beastURL: url});
	    }
	    browser.tabs.insertCSS({code: hidePage}).then(beastifyMessage);
	}

	function reset(tabs){
	    function resetMessage(){
		browser.tabs.sendMessage(tabs[0].id, {command: "reset"});
	    }
	    browser.tabs.removeCSS({code:hidePage}).then(resetMessage)
	}

	function reportError(error){
	    console.error(`Could not beastify: ${error}`);
	}

	if (e.target.classList.contains("beast"))
	    browser.tabs.query({active: true, currentWindow: true}).then(beastify).catch(reportError);
	else if (e.target.classList.contains("reset"))
	    browser.tabs.query({active: true, currentWindow: true}).then(reset).catch(reportError);

    }
    document.addEventListener("click", clickAction);
}

function reportExecuteScriptError(error){
    document.querySelector("#popup-content").classList.add("hidden");
    document.querySelector("#error-content").classList.remove("hidden");
    console.error(`Failed to execute beastify script: ${error.message}`)
}

browser.tabs.executeScript({file: "/content_scripts/beastify.js"}).then(listenForClicks).catch(reportExecuteScriptError);
