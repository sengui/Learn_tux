//If you can see this you are using a browser that does not support
//JavaScript or Jscript. Please download Netscape Navigator Version 4.0
//(or newer) from http:\home.netscape.com or http:\www.microsoft.com
// Microsoft Internet Explorer Version 4.0 (or newer) from http://home.microsoft.com
//
//This script is the google search form for the google 4 appliance.
//Version 1.37m (Updated for tomcat docs)

function GoogleURL(){
	document.write('<form name="gs" method="get" action="http://seeker.bea.com/search">');
}


function GoogleSearchCollection() 
{
var strHref = window.location.href;
//alert("strHref=" + strHref);

document.write('<input type="hidden" name="client" value="developer" />');
document.write('<input type="hidden" name="filter" value="p" />');
document.write('<input type="hidden" name="ie" value="latin1" />');
document.write('<input type="hidden" name="lr" value="lang_en" />');
document.write('<input type="hidden" name="numgm" value="5" />');
document.write('<input type="hidden" name="oe" value="latin1" />');
document.write('<input type="hidden" name="output" value="xml_no_dtd" />');
document.write('<input type="hidden" name="proxystylesheet" value="developer" />');

if (strHref.indexOf("aldsp/docs20") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/aldsp/docs20">');
}

else if (strHref.indexOf("ales/docs21") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/ales/docs21">');
}

else if (strHref.indexOf("alsb/docs20") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_al20">');
}

else if (strHref.indexOf("alsb/docs21") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_al21">');
}

else if (strHref.indexOf("alsr/docs20") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_alsr20">');
}

else if (strHref.indexOf("common/docs20") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_al20|edocs_platform90">');
}

else if (strHref.indexOf("common/docs21") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_al21|edocs_platform91">');
}

else if (strHref.indexOf("common/docs90") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_al20|edocs_platform90">');
}

else if (strHref.indexOf("common/docs91") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_al21|edocs_platform91">');
}

else if (strHref.indexOf("configs_al20") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_al20">');
}

else if (strHref.indexOf("configs_al21") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_al21">');
}

else if (strHref.indexOf("configs70") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_platform70">');
}

else if (strHref.indexOf("configs81") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_platform81">');
}

else if (strHref.indexOf("configs85") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_platform81|edocs_wli85">');
}

else if (strHref.indexOf("configs90") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_platform90">');
}

else if (strHref.indexOf("configs91") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_platform91">');
}

else if (strHref.indexOf("configs_history") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_al20|edocs_al21|edocs_configs|edocs_platform70|edocs_platform81|edocs_platform90|edocs_platform91">');
}

else if (strHref.match("/suppconfigs\/configs\/") != null) {
	//find out if we're looking at HTML pages in this very directory
	if (strHref.match("/suppconfigs\/configs\/.*html/") != null) {
		// HTML pages in this directory will perform a wider search
		document.write('<input type="hidden" name="site" value="edocs_al20|edocs_al21|edocs_configs|edocs_platform70|edocs_platform81|edocs_platform90|edocs_platform91">');
	} else {
		// Doing a more restricted search
		document.write('<input type="hidden" name="site" value="edocs_al20|edocs_al21|edocs_platform90|edocs_platform91">');
	}
}

else if (strHref.indexOf("suppconfigs/index.html") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_al20|edocs_al21|edocs_configs|edocs_platform70|edocs_platform81|edocs_platform90|edocs_platform91">');
}

else if (strHref.indexOf("iwaydocs/iway55") != -1) {

             document.write('<input type="hidden" name="site" value="edocs_wli85">');
} 

else if (strHref.indexOf("jrockit") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/jrockit">');
}

else if (strHref.indexOf("jrockit/docs142") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/jrockit/docs142">');
}

else if (strHref.indexOf("jrockit/docs70") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/jrockit/docs70">');
}

else if (strHref.indexOf("jrockit/docs81") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/jrockit/docs81">');
}

else if (strHref.indexOf("liquiddata/docs81") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/liquiddata/docs81">');
}

else if (strHref.indexOf("platform/docs81") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_platform81">');
}

else if (strHref.indexOf("rfid/rftagaware") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/rfid/rftagaware">');
}

else if (strHref.indexOf("rfid/docs10") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/rfid/docs10">');
}

else if (strHref.indexOf("tcm/docs10") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/tcm/docs10">');
}

else if (strHref.indexOf("tuxedo/tux90") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/tuxedo/tux90">');
}

else if (strHref.indexOf("wladapters/docs81") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wladapters/docs81">');
}

else if (strHref.indexOf("wlcp") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wlcp">');
}

else if (strHref.indexOf("wles/docs42") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wles/docs42">');
}

else if (strHref.indexOf("wli/docs81") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wli81|edocs_wlibc81|edocs_workshop81">');
}

else if (strHref.indexOf("wli/docs85") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wli85">');
}

else if (strHref.indexOf("wlibc/docs81") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wli81|edocs_wlibc81">');
}

else if (strHref.indexOf("wlp/docs81") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wlp81">');
}

else if (strHref.indexOf("wlrt/docs10") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wlrt10">');
}

else if (strHref.indexOf("wls/docs81") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wls/docs81">');
}

else if (strHref.indexOf("wls/docs90") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_platform90">');
}

else if (strHref.indexOf("wls/docs91") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_platform91">');
}

else if (strHref.indexOf("wlspe/docs81") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wli81|edocs_workshop81">');
}

else if (strHref.indexOf("workshop/docs81") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/workshop/docs81">');
}

document.write('<input type="hidden" name="source" value="edocs" />');
document.write('</form>');
}

