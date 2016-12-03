function toggleTOC(event,node) {

    var n=node.parentNode;
    n=n.parentNode;
    n=n.nextSibling;
    if (n.nodeType!=1) n=n.nextSibling;
    if (n.style.display=="none") {
	node.innerHTML='<i class="fa fa-angle-down" aria-hidden="true"></i>';
	n.style.display="";
    } else {
	node.innerHTML='<i class="fa fa-angle-right" aria-hidden="true"></i>';
	n.style.display="none";
    }
    var iframe=window.top.document.getElementById("toc");

    event.preventDefault(); 
};


function changeURL(text) {
    window.top.history.pushState(null,null,text);
    return true;
};
