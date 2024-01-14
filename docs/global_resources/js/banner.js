//If you can see this you are using a browser that does not support
//JavaScript or Jscript. Please download Netscape Navigator Version 4.0
//(or newer) from http:\home.netscape.com or http:\www.microsoft.com
// Microsoft Internet Explorer Version 4.0 (or newer) from http://home.microsoft.com
//
//This script is the edocs banner.
//Version 2.0

var strHref = window.location.href;

function Banner(){
var metaArrayTest = document.getElementsByName('LASTUPDATED');
document.write('<div id="header">');
document.write('	<div id="floater">');
document.write('		<div class="buttons"><a href="#skipnav" title="Jump to Content"></a>');
document.write('		<a href="http://commerce.bea.com/">Downloads</a>');
document.write('		&nbsp;|&nbsp;');
document.write('		<a href="http://edocs.bea.com/">Product Documentation</a>');
document.write('		&nbsp;|&nbsp;');
document.write('		<a href="http://support.bea.com/">Support</a>');
document.write('		</div>');
document.write('		<div class="searchbox">');
document.write('			<input type="text" name="q" value="Search" class="search" id="Search" title="Enter Search Term" onclick="if(this.value==\'Search\')this.value=\'\';" />');
document.write('			<input type="image" src="/global_resources/images/redarrow.gif" alt="Search" style="vertical-align:middle;" />');
document.write('<BR/><div class="buttons"><a   href="http://seeker.bea.com/search?&client=developer&filter=p&ie=latin1&lr=lang_en&numgm=5&oe=latin1&output=xml_no_dtd&proxystylesheet=developer&site=edocs&source=edocs&st=adv">Advanced Search</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </div>');
document.write('		</div>');
document.write('	</div>');
document.write('	<div id="headergraphic"><a href="http://www.bea.com/"><img src="/global_resources/images/oracle_bea.gif" alt="Oracle BEA Logo" border="0" width="248" height="41" style="margin:10px 0px 0px 20px;" /></a>');
//document.write('			<img src="/global_resources/images/header_right.gif" align="right" border="0" width="701" height="85" alt="" style="border:0;margin:0;padding:0;width:701px;height:85px;align:right;" />');
document.write('<p style="font-size:10pt;color:red;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Starting August 31, 2009, edocs.bea.com will no longer be maintained.'); 
document.write('<BR/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;At that time, edocs documentation will be available from the <a href="http://www.oracle.com/technology/documentation/index.html" class="splashlink">Oracle Technology Network</a>.');
document.write('	</div>');
document.write('	<div class="blueline"><img src="/global_resources/images/_.gif" width="1" height="1" alt="" /></div>');
document.write('	<div id="graybar">');
document.write('		<div class="topnav">');

if ((strHref.indexOf("docs-stage") != -1) && (metaArrayTest[0] != null)) {

	document.write('<strong>BEA Internal Doc Info:</strong> ');
	
	var metaArray = document.getElementsByName('LASTUPDATED');
	for (var i=0; i<metaArray.length; i++) {
	document.write('&nbsp;&nbsp; Last update: ' + metaArray[i].content + '&nbsp;&nbsp;');
	}

	var metaArray = document.getElementsByName('LOC_US_CHANGE');
	for (var i=0; i<metaArray.length; i++) {
	document.write('P4 change: ' + metaArray[i].content + '&nbsp;&nbsp;');
	}

	var metaArray = document.getElementsByName('LOC_US_SRCFILE');
	for (var i=0; i<metaArray.length; i++) {
	document.write('P4 File: ' + metaArray[i].content );
	}

	var metaArray = document.getElementsByName('LOC_US_REV');
	for (var i=0; i<metaArray.length; i++) {
	document.write('#' + metaArray[i].content + '<br/>');
	}

} else
	{
	document.write('		<a href="http://www.oracle.com/technology/index.html">OTN Home</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;');
	document.write('		<a href="http://forums.oracle.com/">Oracle Forums</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;');
	document.write('		<a href="http://www.oracle.com/technology/community/index.html">Community</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;');	
 	}

document.write('		</div>');
document.write('	</div>');
document.write('	<div class="twodots"><img src="/global_resources/images/_.gif" width="1" height="1" alt="" /></div>');
document.write('</div>');
}