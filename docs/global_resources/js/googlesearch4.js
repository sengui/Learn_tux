//If you can see this you are using a browser that does not support
//JavaScript or Jscript. Please download Netscape Navigator Version 4.0
//(or newer) from http:\home.netscape.com or http:\www.microsoft.com
// Microsoft Internet Explorer Version 4.0 (or newer) from http://home.microsoft.com
//
//This script is the google search form for the google 4 appliance.
//added pages/docs15 - 8/05/08

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

if (strHref.indexOf("albsi/docs60") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/albsi/docs60">');
}

else if (strHref.indexOf("alcs") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_alcs">');
}

else if (strHref.indexOf("aldsp/docs32") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_aldsp32">');
}

else if (strHref.indexOf("aldsp/docs301") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_aldsp301">');
}

else if (strHref.indexOf("aldsp/docs30") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_aldsp30">');
}

else if (strHref.indexOf("aldsp/docs25") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_aldsp25">');
}

else if (strHref.indexOf("aldsp/docs21") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/aldsp/docs21">');
}

else if (strHref.indexOf("aldsp/docs20") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/aldsp/docs20">');
}

else if (strHref.indexOf("aler/docs30") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_aler30">');
}

else if (strHref.indexOf("ales/docs21") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/ales/docs21">');
}

else if (strHref.indexOf("ales/docs22") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/ales/docs22">');
}

else if (strHref.indexOf("ales/docs25") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/ales/docs25">');
}

else if (strHref.indexOf("ales/docs26") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/ales/docs26">');
}

else if (strHref.indexOf("ales/docs30") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_ales30">');
}

else if (strHref.indexOf("alint/docs30") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/alint/docs30">');
}

else if (strHref.indexOf("alsb/docs20") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_al20">');
}

else if (strHref.indexOf("alsb/docs21") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_al21">');
}

else if (strHref.indexOf("alsb/docs25") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/alsb/docs25">');
}

else if (strHref.indexOf("alsb/docs261") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_alsb261">');
}

else if (strHref.indexOf("alsb/docs26") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/alsb/docs26">');
}

else if (strHref.indexOf("alsb/docs30") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_alsb30">');
}

else if (strHref.indexOf("alsm/docs26") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/alsm/docs26">');
}

else if (strHref.indexOf("alsr/docs20") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_alsr20">');
}

else if (strHref.indexOf("alsr/docs21") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_alsr21">');
}

else if (strHref.indexOf("alsr/docs30") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_alsr30">');
}

else if (strHref.indexOf("en/alui/ali/docs65") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_ali65">');
}

else if (strHref.indexOf("alui/analytics/docs25") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_analytics25">');
}

else if (strHref.indexOf("alui/collaboration/docs45") != -1) {
	document.write('<input type="hidden" name="site" value="edocs_collaboration45">');
}

else if (strHref.indexOf("alui/devdoc/docs60") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/alui/devdoc/docs60">');
}

else if (strHref.indexOf("en/alui/devdoc/docs6x/aluidevguide") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/en/alui/devdoc/docs6x/aluidevguide">');
}

else if (strHref.indexOf("alui/devtools/wsrp/docs11") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/alui/devtools/wsrp/docs11">');
}

else if (strHref.indexOf("en/alui/dotnetappaccelerator/docs11") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_dotnetappaccelerator11">');
}

else if (strHref.indexOf("en/alui/dotnetportlettoolkit/docs11") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_dotnetportlettoolkit11">');
}

else if (strHref.indexOf("alui/integration/sharepointconsole/docs11") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/alui/integration/sharepointconsole/docs11">');
}

else if (strHref.indexOf("collabrasuite") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_collabrasuite">');
}

else if (strHref.indexOf("bluedragon/621") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_bluedragon">');
}

else if (strHref.indexOf("clipping") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_clipping">');
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

else if (strHref.indexOf("common/docs92") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_al21|edocs_platform91">');
}

else if (strHref.indexOf("common/docs100") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_common100">');
}

else if (strHref.indexOf("common/docs102") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_common102">');
}

else if (strHref.indexOf("common/docs103") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/common/docs103">');
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

else if (strHref.match("/platform/suppconfigs/configs/") != null) {
	//find out if we're looking at HTML pages in this very directory
	if (strHref.match("/platform/suppconfigs/configs/.*html") != null) {
		// HTML pages in this directory will perform a wider search
		document.write('<input type="hidden" name="site" value="edocs_al20|edocs_al21|edocs_configs|edocs_platform70|edocs_platform81|edocs_platform90|edocs_platform91">');
	} else {
		// Doing a more restricted search
		document.write('<input type="hidden" name="site" value="edocs_al20|edocs_al21|edocs_platform90|edocs_platform91">');
	}
}

else if (strHref.indexOf("/platform/suppconfigs/index.html") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_al20|edocs_al21|edocs_configs|edocs_platform70|edocs_platform81|edocs_platform90|edocs_platform91">');
}

else if (strHref.indexOf("fmd/docs34") != -1) {

             document.write('<input type="hidden" name="site" value="edocs_fmd34">');
} 

else if (strHref.indexOf("guardian/uihelp100") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/guardian/uihelp100">');
}

else if (strHref.indexOf("guardian/uihelp110") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_guardian110">');
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

else if (strHref.indexOf("kodo/docs40") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/kodo/docs40">');
}

else if (strHref.indexOf("kodo/docs41") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/kodo/docs41">');
}

else if (strHref.indexOf("liquiddata/docs81") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/liquiddata/docs81">');
}

else if (strHref.indexOf("pages/docs10") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_pages10">');
}

else if (strHref.indexOf("pages/docs15") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/pages/docs15">');
}

else if (strHref.indexOf("pathways/docs15") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_pathways15">');
}

else if (strHref.indexOf("platform/docs81") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_platform81">');
}

else if (strHref.indexOf("platform/docs102") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_platform102">');
}

else if (strHref.indexOf("rfid/docs10") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/rfid/docs10">');
}

else if (strHref.indexOf("rfid/edge_server/docs20") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/rfid/edge_server/docs20">');
}

else if (strHref.indexOf("rfid/edge_server/docs21") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/rfid/edge_server/docs21">');
}

else if (strHref.indexOf("rfid/edge_server/docs22") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/rfid/edge_server/docs22">');
}

else if (strHref.indexOf("rfid/edge_server/docs23") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/rfid/edge_server/docs23">');
}

else if (strHref.indexOf("rfid/edge_server/docs30") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/rfid/edge_server/docs30">');
}

else if (strHref.indexOf("rfid/enterprise_server/docs20") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/rfid/enterprise_server/docs20">');
}

else if (strHref.indexOf("rfid/mobile_sdk/docs10") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/rfid/mobile_sdk/docs10">');
}

else if (strHref.indexOf("rfid/rftagaware") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/rfid/rftagaware">');
}

else if (strHref.indexOf("salt/docs11") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/salt/docs11">');
}

else if (strHref.indexOf("salt/docs20") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/salt/docs20">');
}

else if (strHref.indexOf("smartconnect/docs26") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/smartconnect/docs26">');
}

else if (strHref.indexOf("smartconnect/docs30") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_smartconnect30">');
}

else if (strHref.indexOf("tcm/docs10") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/tcm/docs10">');
}

else if (strHref.indexOf("tsam/docs11") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/tsam/docs11">');
}

else if (strHref.indexOf("tuxedo/eam/v91") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/tuxedo/eam/v91">');
}

else if (strHref.indexOf("tuxedo/tcp/v91") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/tuxedo/tcp/v91">');
}

else if (strHref.indexOf("tuxedo/tcp/v100") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/tuxedo/tcp/v100">');
}

else if (strHref.indexOf("tuxedo/tux90") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/tuxedo/tux90">');
}

else if (strHref.indexOf("tuxedo/tux91") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/tuxedo/tux91">');
}

else if (strHref.indexOf("tuxedo/tux100") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/tuxedo/tux100">');
}

else if (strHref.indexOf("wladapters/docs91") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wladapters/docs91">');
}

else if (strHref.indexOf("wladapters/docs81") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wladapters/docs81">');
}

else if (strHref.indexOf("wlcp/wlng30/open") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wlcp/wlng30/open">');
}

else if (strHref.indexOf("wlcp/wlng40") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wlcp/wlng40">');
}

else if (strHref.indexOf("wlcp/wlngcoyote/open") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wlcp/wlngcoyote/open">');
}

else if (strHref.indexOf("wlcp/wlss21") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wlcp">');
}

else if (strHref.indexOf("wlcp/wlss22") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wlcp/wlss22">');
}

else if (strHref.indexOf("wlcp/wlss30") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wlcp/wlss30">');
}

else if (strHref.indexOf("wlcp/wlss31") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wlcp/wlss31">');
}

else if (strHref.indexOf("wlcp/wlss40") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wlss40">');
}

else if (strHref.indexOf("wles/docs42") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wles/docs42">');
}

else if (strHref.indexOf("wlevs/docs20") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wlevs/docs20">');
}

else if (strHref.indexOf("wlevs/docs30") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wlevs30">');
}

else if (strHref.indexOf("wli/docs81") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wli81|edocs_wlibc81|edocs_workshop81">');
}

else if (strHref.indexOf("wli/docs85") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wli85">');
}

else if (strHref.indexOf("wli/docs92") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wli/docs92">');
}

else if (strHref.indexOf("wli/docs102") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wli102">');
}

else if (strHref.indexOf("wlibc/docs81") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wli81|edocs_wlibc81">');
}

else if (strHref.indexOf("wlloc/docs10") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wlloc/docs10">');
}

else if (strHref.indexOf("wloc/docs10") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wloc10">');
}

else if (strHref.indexOf("wlp/docs81") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wlp81">');
}

else if (strHref.indexOf("wlp/docs92/groupware.html") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wlp/docs92/compoze">');
}

else if (strHref.indexOf("wlp/docs92") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wlp92|edocs_92core">');
}

else if (strHref.indexOf("wlp/docs100") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wlp100">');
}

else if (strHref.indexOf("wlp/docs102") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wlp102">');
}

else if (strHref.indexOf("wlrt/docs10") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wlrt10">');
}

else if (strHref.indexOf("wlrt/docs11") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wlrt11">');
}

else if (strHref.indexOf("wlrt/docs20") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wlrt20">');
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

else if (strHref.indexOf("wls/docs92") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_92core">');
}

else if (strHref.indexOf("wls/docs100") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wls/docs100">');
}

else if (strHref.indexOf("wls/docs103") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wls/docs103">');
}

else if (strHref.indexOf("wlspe/docs81") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wli81|edocs_workshop81">');
}

else if (strHref.indexOf("wls-ve/docs92-v10") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wlsve92v10">');
}

else if (strHref.indexOf("wls-ve/docs92-v11") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wlsve92v11">');
}

else if (strHref.indexOf("wl-ve/docs10-x") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wlve10x">');
}

else if (strHref.indexOf("workshop/docs81") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/workshop/docs81">');
}

else if (strHref.indexOf("workshop/docs92") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/workshop/docs92">');
}

else if (strHref.indexOf("wlw/docs100") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wlw/docs100">');
}

else if (strHref.indexOf("wlw/docs101") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wlw/docs101">');
}

else if (strHref.indexOf("wlw/docs102") != -1) {

	document.write('<input type="hidden" name="site" value="edocs_wlw102">');
}

else if (strHref.indexOf("wlw/docs103") != -1) {

	document.write('<input type="hidden" name="site" value="edocs" />');
	document.write('<input type="hidden" name="sitesearch" value="e-docs.bea.com/wlw/docs103">');
}

document.write('<input type="hidden" name="source" value="edocs" />');
document.write('</form>');
}