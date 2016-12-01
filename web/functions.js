function toggleTOC(event,node) {

    var n=node.parentNode;
    n=n.parentNode;
    n=n.nextSibling;
    if (n.nodeType!=1) n=n.nextSibling;
    if (node.textContent=="+") {
	node.innerHTML="&ndash;";
	n.style.display="";
    } else {
	node.textContent="+";
	n.style.display="none";
    }
    var iframe=window.top.document.getElementById("toc");

    event.preventDefault(); 
};


function changeURL(text) {
    window.top.history.pushState(null,null,text);
    return true;
};
