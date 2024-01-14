//If you can see this you are using a browser that does not support
//JavaScript or Jscript. Please download Netscape Navigator Version 4.0
//(or newer) from http:\home.netscape.com or http:\www.microsoft.com
// Microsoft Internet Explorer Version 4.0 (or newer) from http://home.microsoft.com
//
//This script outputs the correct copyright date and link to copyright page.
//Version 1.37a

function Copyright() 
{
var strHref = window.location.href;
//alert("strHref=" + strHref);


	copyright=new Date();
	update=copyright.getFullYear();
	document.write('<a href="http://edocs.bea.com/copyright.html">&copy; ' + update + ' BEA Systems</a>');
}
