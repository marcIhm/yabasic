function toggleTOC(event,node) {

    var sibling=node.parentNode.parentNode.nextSibling;
    if (sibling.nodeType!=1) sibling=sibling.nextSibling;
    if (sibling.style.display=="none") {
	node.innerHTML='<i class="fa fa-angle-down" aria-hidden="true"></i>';
	sibling.style.display="";
    } else {
	node.innerHTML='<i class="fa fa-angle-right" aria-hidden="true"></i>';
	sibling.style.display="none";
    }
    var iframe=window.top.document.getElementById("toc");

    event.preventDefault(); 
};


function changeURL(text) {
    window.top.history.pushState(null,null,text);
    return true;
};
