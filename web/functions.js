
function showContentFromToc (event, node) {

    var cont=node.href
    var pos=cont.lastIndexOf("?");
    if (pos>0) cont=cont.substring(pos+1);
    showContent(cont);

    event.preventDefault(); 
};


function showContentFromUrl() {

    showContent((window.location.search.substring(1) || "whatsnew") + window.location.hash);
};


function showContent (cont) {

    // Change content of iframe
    var iframe=window.top.document.getElementById("content");
    var matches = cont.match("^((.*)/)?([^/#]+)?(#(.*?))?$");
    var hashpos = cont.indexOf("#");
    if (hashpos >= 0) {
	iframe.src = cont.substr(0,hashpos) + ".html" + cont.substr(hashpos);
    } else {
	iframe.src = cont + ".html";
    }

    if (cont) window.top.history.pushState(null, window.top.document.title, "?" + cont);
 };


function toggleTOC (event,node) {

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


