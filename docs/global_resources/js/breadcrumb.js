//If you can see this you are using a browser that does not support
//JavaScript or Jscript. Please download Netscape Navigator Version 4.0
//(or newer) from http:\home.netscape.com or http:\www.microsoft.com
// Microsoft Internet Explorer Version 4.0 (or newer) from http://home.microsoft.com
//
//set pages/docs15 breadcrumb to not appear - 8/05/08

function Breadcrumb(){
var strHref = window.location.href;
//alert("strHref=" + strHref);

if (strHref.indexOf("bea/integration/docs102/") != -1) {

	document.write('<a href="http://edocs.bea.com">eDocs Home</a>');

}

else if (strHref.indexOf("albsi/docs60") != -1) {

	// do nothing
}

else if (strHref.indexOf("ales/docs32") != -1) {

	// do nothing
}

else if (strHref.indexOf("common/docs103") != -1) {

	// do nothing
}

else if (strHref.indexOf("osb/docs10gr3") != -1) {

	// do nothing
}

else if (strHref.indexOf("pages/docs15") != -1) {

	// do nothing
}

else if (strHref.indexOf("wlevs/docs30") != -1) {

	// do nothing
}

else if (strHref.indexOf("wls/docs103") != -1) {

	// do nothing
}

else if (strHref.indexOf("wlw/docs103") != -1) {

	// do nothing
}

else {

	document.write('<a href="http://edocs.bea.com">eDocs Home</a>&nbsp;&gt;&nbsp;');

if (strHref.indexOf("/copyright.html") != -1) {

	document.write('Copyright');
}

else if (strHref.indexOf("/alint/docs30/index.html") != -1) {

	document.write('BEA AquaLogic Integrator 3.0 Documentation');
}

else if (strHref.indexOf("/alint/docs30") != -1) {

	document.write('<a href="/alint/docs30/index.html">BEA AquaLogic Integrator 3.0 Documentation</a>');
}

else if (strHref.indexOf("en/alui/ali/docs65/index.html") != -1) {

	document.write('AquaLogic Interaction 6.5 Documentation');
}

else if (strHref.indexOf("en/alui/ali/docs65") != -1) {

	document.write('<a href="/en/alui/ali/docs65/index.html">AquaLogic Interaction 6.5 Documentation</a>');
}

else if (strHref.indexOf("alui/analytics/docs21/index.html") != -1) {

	document.write('AquaLogic Analytics 2.1 Documentation');
}

else if (strHref.indexOf("alui/analytics/docs21") != -1) {

	document.write('<a href="/alui/analytics/docs21/index.html">AquaLogic Analytics 2.1 Documentation</a>');
}

else if (strHref.indexOf("alui/analytics/docs25/index.html") != -1) {

	document.write('AquaLogic Analytics 2.5 Documentation');
}

else if (strHref.indexOf("alui/analytics/docs25") != -1) {

	document.write('<a href="/alui/analytics/docs25/index.html">AquaLogic Analytics 2.5 Documentation</a>');
}

else if (strHref.indexOf("en/alui/devdoc/docs6x/aluidevguide/index.html") != -1) {

	document.write('<a href="/alui/index.html">AquaLogic User Interaction Documentation</a>');
}

else if (strHref.indexOf("en/alui/devdoc/docs6x/aluidevguide") != -1) {

	document.write('<a href="/alui/index.html">AquaLogic User Interaction Documentation</a> &gt; <a href="/en/alui/devdoc/docs6x/aluidevguide/index.html">AquaLogic User Interaction Development Guide</a>');
}

else if (strHref.indexOf("albsi/docs55") != -1) {

	document.write('<a href="/albsi/docs55/index.html">BEA AquaLogic Business Process Management (ALBPM) 5.5 Documentation</a>');
}

else if (strHref.indexOf("albsi/docs57") != -1) {

	document.write('<a href="/albsi/docs57/index.html">BEA AquaLogic Business Process Management (ALBPM) 5.7 Documentation</a>');
}

else if (strHref.indexOf("albsi/docs60") != -1) {

	document.write('<a href="/albsi/docs60/index.html">BEA AquaLogic Business Process Management (ALBPM) 6.0 Documentation</a>');
}

else if (strHref.indexOf("alcs/index.html") != -1) {

	document.write('BEA AquaLogic Commerce Services Product Documentation');
}

else if (strHref.indexOf("alcs") != -1) {

	document.write('<a href="/alcs/index.html">BEA AquaLogic Commerce Services Product Documentation</a>');
}

else if (strHref.indexOf("aldsp/docs25/index.html") != -1) {

	document.write('BEA AquaLogic Data Services Platform 2.5 Documentation');
}

else if (strHref.indexOf("aldsp/docs25") != -1) {

	document.write('<a href="/aldsp/docs25/index.html">BEA AquaLogic Data Services Platform 2.5 Documentation</a>');
}

else if (strHref.indexOf("aldsp/docs301/index.html") != -1) {

	document.write('BEA AquaLogic Data Services Platform 3.01 Documentation');
}

else if (strHref.indexOf("aldsp/docs301") != -1) {

	document.write('<a href="/aldsp/docs30/index.html">BEA AquaLogic Data Services Platform 3.01 Documentation</a>');
}

else if (strHref.indexOf("aldsp/docs30/index.html") != -1) {

	document.write('BEA AquaLogic Data Services Platform 3.0 Documentation');
}

else if (strHref.indexOf("aldsp/docs30") != -1) {

	document.write('<a href="/aldsp/docs30/index.html">BEA AquaLogic Data Services Platform 3.0 Documentation</a>');
}

else if (strHref.indexOf("aldsp/docs32/index.html") != -1) {

	document.write('BEA AquaLogic Data Services Platform 3.2 Documentation');
}

else if (strHref.indexOf("aldsp/docs32") != -1) {

	document.write('<a href="/aldsp/docs32/index.html">BEA AquaLogic Data Services Platform 3.2 Documentation</a>');
}

else if (strHref.indexOf("aler/docs26/index.html") != -1) {

	document.write('BEA AquaLogic Enterprise Repository 2.6 Documentation');
}

else if (strHref.indexOf("aler/docs30/index.html") != -1) {

	document.write('BEA AquaLogic Enterprise Repository 3.0 Documentation</a>');
}

else if (strHref.indexOf("aler/docs30") != -1) {

	document.write('<a href="/aler/docs30/index.html">BEA AquaLogic Enterprise Repository 3.0 Documentation</a>');
}

else if (strHref.indexOf("ales/docs22") != -1) {

	document.write('<a href="../index.html">BEA AquaLogic Enterprise Security 2.2 Documentation</a>');
}

else if (strHref.indexOf("ales/docs25/index.html") != -1) {

	document.write('BEA AquaLogic Enterprise Security 2.5 Documentation');
}

else if (strHref.indexOf("ales/docs25") != -1) {

	document.write('<a href="/ales/docs25/index.html">BEA AquaLogic Enterprise Security 2.5 Documentation</a>');
}

else if (strHref.indexOf("ales/docs26/index.html") != -1) {

	document.write('BEA AquaLogic Enterprise Security 2.6 Documentation');
}

else if (strHref.indexOf("ales/docs26") != -1) {

	document.write('<a href="/ales/docs26/index.html">BEA AquaLogic Enterprise Security 2.6 Documentation</a>');
}

else if (strHref.indexOf("ales/docs30/index.html") != -1) {

	document.write('BEA AquaLogic Enterprise Security 3.0 Documentation');
}

else if (strHref.indexOf("ales/docs30") != -1) {

	document.write('<a href="/ales/docs30/index.html">BEA AquaLogic Enterprise Security 3.0 Documentation</a>');
}

else if (strHref.indexOf("alsb/docs20") != -1) {

	document.write('<a href="../index.html">BEA AquaLogic Service Bus 2.0 Documentation</a>');
}

else if (strHref.indexOf("alsb/docs21") != -1) {

	document.write('<a href="../index.html">BEA AquaLogic Service Bus 2.1 Documentation</a>');
}

else if (strHref.indexOf("alsb/docs25") != -1) {

	document.write('<a href="../index.html">BEA AquaLogic Service Bus 2.5 Documentation</a>');
}

else if (strHref.indexOf("alsb/docs261/index.html") != -1) {

	document.write('BEA AquaLogic Service Bus 2.6 RP1 Documentation');
}

else if (strHref.indexOf("alsb/docs261") != -1) {

	document.write('<a href="/alsb/docs261/index.html">BEA AquaLogic Service Bus 2.6 RP1 Documentation</a>');
}

else if (strHref.indexOf("alsb/docs26/index.html") != -1) {

	document.write('BEA AquaLogic Service Bus 2.6 Documentation');
}

else if (strHref.indexOf("alsb/docs26") != -1) {

	document.write('<a href="/alsb/docs26/index.html">BEA AquaLogic Service Bus 2.6 Documentation</a>');
}

else if (strHref.indexOf("alsb/docs30/index.html") != -1) {

	document.write('BEA AquaLogic Service Bus 3.0 Documentation');
}

else if (strHref.indexOf("alsb/docs30") != -1) {

	document.write('<a href="/alsb/docs30/index.html">BEA AquaLogic Service Bus 3.0 Documentation</a>');
}

else if (strHref.indexOf("alsm/docs26/index.html") != -1) {

	document.write('BEA AquaLogic SOA Management 2.6 Documentation');
}

else if (strHref.indexOf("alsm/docs26") != -1) {

	document.write('<a href="/alsm/docs26/index.html">BEA AquaLogic SOA Management 2.6 Documentation</a>');
}

else if (strHref.indexOf("alsr/docs21") != -1) {

	document.write('<a href="/alsr/docs21/index.html">BEA AquaLogic Service Registry 2.1</a>');
}

else if (strHref.indexOf("alsr/docs30/index.html") != -1) {

	document.write('BEA AquaLogic Service Registry 3.0 Documentation');
}

else if (strHref.indexOf("alsr/docs30") != -1) {

	document.write('<a href="/alsr/docs30/index.html">BEA AquaLogic Service Registry 3.0 Documentation</a>');
}

else if (strHref.indexOf("/alui/ali/docs61/index.html") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a>');
}

else if (strHref.indexOf("/alui/ali/docs61") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/ali/docs61/index.html">AquaLogic Interaction 6.1 Documentation</a>');
}

else if (strHref.indexOf("alui/analytics/docs20/index.html") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a>');
}

else if (strHref.indexOf("alui/analytics/docs20/") != -1) {

	document.write('<a href="../../../index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="../index.html">AquaLogic Interaction Analytics 2.0 Documentation</a>');
}

else if (strHref.indexOf("alui/collaboration/docs41/index.html") != -1) {

	document.write('<a href="../../index.html">BEA AquaLogic User Interaction Documentation</a> &gt; AquaLogic Interaction (ALI) Collaboration 4.1 Documentation');
}

else if (strHref.indexOf("alui/collaboration/docs41") != -1) {

	document.write('<a href="../../../index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/collaboration/docs41/index.html">AquaLogic Interaction (ALI) Collaboration 4.1 Documentation</a>');
}

else if (strHref.indexOf("/alui/collaboration/docs42/index.html") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a>');
}

else if (strHref.indexOf("/alui/collaboration/docs42") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/collaboration/docs42/index.html">AquaLogic Interaction Collaboration 4.2 Documentation</a>');
}

else if (strHref.indexOf("/alui/collaboration/docs45/index.html") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a>');
}

else if (strHref.indexOf("/alui/collaboration/docs45") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/collaboration/docs45/index.html">AquaLogic Interaction (ALI) Collaboration 4.5 Documentation</a>');
}

else if (strHref.indexOf("alui/deployment/index.html") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a>');
}

else if (strHref.indexOf("alui/deployment") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/deployment/index.html">AquaLogic User Interaction Deployment Guide</a>');
}

else if (strHref.indexOf("alui/devtools/index.html") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; AquaLogic User Interaction Developer Tools Documentation');
}

else if (strHref.indexOf("alui/devtools/wsrp/docs11/index.html") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/devtools/index.html">AquaLogic User Interaction Developer Tools Documentation</a> &gt; AquaLogic Interaction WSRP Consumer 1.1 Documentation');
}

else if (strHref.indexOf("alui/devtools/wsrp/docs11") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/devtools/index.html">AquaLogic User Interaction Developer Tools Documentation</a> &gt; <a href="/alui/devtools/wsrp/docs11/index.html">AquaLogic Interaction WSRP Consumer 1.1 Documentation</a>');
}

else if (strHref.indexOf("alui/devtools") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/devtools/index.html">AquaLogic User Interaction Developer Tools Documentation</a>');
}

else if (strHref.indexOf("alui/dotnetappaccelerator/docs10/index.html") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; AquaLogic Interaction .NET Application Accelerator 1.0 Documentation');
}

else if (strHref.indexOf("alui/dotnetappaccelerator/docs10") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/dotnetappaccelerator/docs10/index.html">AquaLogic Interaction .NET Application Accelerator 1.0 Documentation</a>');
}

else if (strHref.indexOf("en/alui/dotnetappaccelerator/docs11/index.html") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; AquaLogic Interaction .NET Application Accelerator 1.1 Documentation');
}

else if (strHref.indexOf("en/alui/dotnetappaccelerator/docs11") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/en/alui/dotnetappaccelerator/docs11/index.html">AquaLogic Interaction .NET Application Accelerator 1.1 Documentation</a>');
}

else if (strHref.indexOf("en/alui/dotnetportlettoolkit/docs11/index.html") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; AquaLogic .NET Portlet Toolkit 1.1 Documentation');
}

else if (strHref.indexOf("en/alui/dotnetportlettoolkit/docs11") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/en/alui/dotnetportlettoolkit/docs11/index.html">AquaLogic .NET Portlet Toolkit 1.1 Documentation</a>');
}

else if (strHref.indexOf("alui/hiper/docs11/index.html") != -1) {

	document.write('<a href="../../index.html">BEA AquaLogic User Interaction Documentation</a> &gt; AquaLogic HiPer Workspace For Retail 1.1 Documentation');
}

else if (strHref.indexOf("alui/hiper/docs11") != -1) {

	document.write('<a href="../../../index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/hiper/docs11/index.html">AquaLogic HiPer Workspace For Retail 1.1 Documentation</a>');
}

else if (strHref.indexOf("/alui/idk/docs53/index.html") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a>');
}

else if (strHref.indexOf("/alui/idk/docs54/index.html") != -1) {
	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; AquaLogic Interaction Development Kit (IDK) Documentation');
}

else if (strHref.indexOf("/alui/idk/docs54/") != -1) {
	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/idk/docs54/index.html">AquaLogic Interaction Development Kit (IDK) Documentation</a>');
}

else if (strHref.indexOf("/alui/idk/docs60/index.html") != -1) {
	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; AquaLogic Interaction Development Kit (IDK) Documentation');
}

else if (strHref.indexOf("/alui/idk/docs60/") != -1) {
	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/idk/docs60/index.html">AquaLogic Interaction Development Kit (IDK) Documentation</a>');
}

else if (strHref.indexOf("/alui/integration/index.html") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a>');
}

else if (strHref.indexOf("/alui/integration/activedirectoryids/docs63") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/integration/index.html">AquaLogic User Interaction Integration Documentation</a> &gt; Identity Service - Active Directory 6.3 Documentation');
}

else if (strHref.indexOf("/alui/integration/documentumcs/docs55") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/integration/index.html">AquaLogic User Interaction Integration Documentation</a> &gt; Content Service - Documentum 5.5 Documentation');
}

else if (strHref.indexOf("/alui/integration/excelframework/docs12") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/integration/index.html">AquaLogic User Interaction Integration Documentation</a> &gt; Portlet Framework - Microsoft Excel 1.2 Documentation');
}

else if (strHref.indexOf("/alui/integration/exchangecs/docs52") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/integration/index.html">AquaLogic User Interaction Integration Documentation</a> &gt; Content Service - Microsoft Exchange 5.2 Documentation');
}

else if (strHref.indexOf("/alui/integration/exchangeportlets/docs32") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/integration/index.html">AquaLogic User Interaction Integration Documentation</a> &gt; Portlet Suite - Microsoft Exchange 3.2 Documentation');
}

else if (strHref.indexOf("/alui/integration/imapportlets/docs32") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/integration/index.html">AquaLogic User Interaction Integration Documentation</a> &gt; Portlet Suite - IMAP 3.2 Documentation');
}

else if (strHref.indexOf("/alui/integration/ldapids/docs22") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/integration/index.html">AquaLogic User Interaction Integration Documentation</a> &gt; Identity Service - LDAP 2.2 Documentation');
}

else if (strHref.indexOf("/alui/integration/notescs/docs61") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/integration/index.html">AquaLogic User Interaction Integration Documentation</a> &gt; Content Service - Lotus Notes 6.1 Documentation');
}

else if (strHref.indexOf("/alui/integration/notesportlets/docs34") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/integration/index.html">AquaLogic User Interaction Integration Documentation</a> &gt; Portlet Suite - Lotus Notes 3.4 Documentation');
}

else if (strHref.indexOf("/alui/integration/sharepointconsole/docs11") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/integration/index.html">AquaLogic User Interaction Integration Documentation</a> &gt; Sharepoint Console 1.1 Documentation');
}

else if (strHref.indexOf("/alui/integration/windowsfilescs/docs61") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/integration/index.html">AquaLogic User Interaction Integration Documentation</a> &gt; Content Service - Windows Files 6.1 Documentation');
}

else if (strHref.indexOf("/alui/integration/") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/integration/index.html">AquaLogic User Interaction Integration Documentation</a>');
}

else if (strHref.indexOf("/alui/process/docs15/index.html") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a>');
}

else if (strHref.indexOf("/alui/publisher/docs62/index.html") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a>');
}

else if (strHref.indexOf("/alui/publisher/docs62/ja/index.html") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a>');
}

else if (strHref.indexOf("/alui/publisher/docs63/index.html") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a>');
}

else if (strHref.indexOf("/alui/publisher/docs63") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/publisher/docs63/index.html">AquaLogic Interaction Publisher 6.3 Documentation</a>');
}

else if (strHref.indexOf("/alui/publisher/docs64/index.html") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a>');
}

else if (strHref.indexOf("/alui/publisher/docs64") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/publisher/docs64/index.html">AquaLogic Interaction Publisher 6.4 Documentation</a>');
}


else if (strHref.indexOf("/alui/studio/docs22/index.html") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a>');
}

else if (strHref.indexOf("/alui/studio/docs22") != -1) {

	document.write('<a href="/alui/index.html">BEA AquaLogic User Interaction Documentation</a> &gt; <a href="/alui/studio/docs22/index.html">AquaLogic Interaction Studio 2.2 Documentation</a>');
}

else if (strHref.indexOf("/alui/index.html") != -1) {

	document.write('BEA AquaLogic User Interaction Documentation');
}

else if (strHref.indexOf("/clipping/index.html") != -1) {

	document.write('QuickClip Portlet, BEA WebLogic Edition and Kapow Enterprise WebClipper, BEA Edition Product Documentation');
}

else if (strHref.indexOf("/collabrasuite") != -1) {

	document.write('<a href="/collabrasuite/index.html">CollabraSuite, BEA Edition Documentation</a>');
}

else if (strHref.indexOf("common/docs20") != -1) {

	document.write('<a href="../index.html">BEA Products Documentation</a>');
}

else if (strHref.indexOf("common/docs22") != -1) {

	document.write('<a href="../index.html">BEA Products Documentation</a>');
}

else if (strHref.indexOf("common/docs90") != -1) {

	document.write('<a href="../index.html">BEA Products Documentation</a>');
}

else if (strHref.indexOf("common/docs92/index.html") != -1) {

	document.write('BEA Products Installation and Configuration Documentation');
}

else if (strHref.indexOf("common/docs92") != -1) {

	document.write('<a href="../index.html">BEA Products Documentation</a>');
}

else if (strHref.indexOf("common/docs100/index.html") != -1) {

	document.write('BEA Products Installation and Configuration Documentation');
}

else if (strHref.indexOf("common/docs100") != -1) {

	document.write('<a href="../index.html">BEA Products Documentation</a>');
}

else if (strHref.indexOf("common/docs102/index.html") != -1) {

	document.write('BEA Products Installation and Configuration Documentation');
}

else if (strHref.indexOf("common/docs102") != -1) {

	document.write('<a href="../index.html">BEA Products Installation and Configuration Documentation</a>');
}

else if (strHref.indexOf("common/smartupdate/guide") != -1) {

	document.write('<a href="/platform/docs102/index.html">BEA WebLogic Platform 10.2 Documentation</a>');
}

else if (strHref.indexOf("configs_history") != -1) {

	document.write('<a href="../index.html">Supported Configurations</a>');
}

else if (strHref.indexOf("configs_al20") != -1) {

	document.write('<a href="../../index.html">Supported Configurations</a>');
}

else if (strHref.indexOf("configs90") != -1) {

	document.write('<a href="../../index.html">Supported Configurations</a>');
}

else if (strHref.indexOf("configs85") != -1) {

	document.write('<a href="../../index.html">Supported Configurations</a>');
}

else if (strHref.indexOf("configs81") != -1) {

	document.write('<a href="../../index.html">Supported Configurations</a>');
}

else if (strHref.indexOf("configs70") != -1) {

	document.write('<a href="../../index.html">Supported Configurations</a>');
}

else if (strHref.indexOf("ensemble/docs10/index.html") != -1) {

	document.write('AquaLogic Ensemble 1.0 Documentation');
}

else if (strHref.indexOf("ensemble/docs10") != -1) {

	document.write('<a href="/ensemble/docs10/index.html">AquaLogic Ensemble 1.0 Documentation</a>');
}

else if (strHref.indexOf("fmd/docs34/index.html") != -1) {

	document.write('Financial Message Designer 3.4 Documentation');
}

else if (strHref.indexOf("fmd/docs34") != -1) {

	document.write('<a href="/fmd/docs34/index.html">Financial Message Designer 3.4 Documentation</a>');
}

else if (strHref.indexOf("guardian/uihelp100/index.html") != -1) {

	document.write('BEA Guardian 1.0 Documentation');
}

else if (strHref.indexOf("guardian/uihelp100") != -1) {

	document.write('<a href="/guardian/uihelp100/index.html">BEA Guardian 1.0 Documentation</a>');
}

else if (strHref.indexOf("guardian/uihelp110/index.html") != -1) {

	document.write('BEA Guardian 1.1 Documentation');
}

else if (strHref.indexOf("guardian/uihelp110") != -1) {

	document.write('<a href="/guardian/uihelp110/index.html">BEA Guardian 1.1 Documentation</a>');
}

else if (strHref.indexOf("jrockit/geninfo") != -1) {

	document.write('<a href="/jrockit/webdocs/index.html">Oracle JRockit Documentation</a>&nbsp;&gt;&nbsp;<a href="/jrockit/geninfo/index.html">Oracle JRockit JVM General Information</a>');
}

else if (strHref.indexOf("jrockit/jrdocs") != -1) {

	document.write('<a href="/jrockit/webdocs/index.html">Oracle JRockit Documentation</a>&nbsp;&gt;&nbsp;<a href="/jrockit/jrdocs/index.html">Oracle JRockit JDK Reference and Support Documentation Center</a>');
}

else if (strHref.indexOf("jrockit/releases") != -1) {

	document.write('<a href="/jrockit/webdocs/index.html">Oracle JRockit Documentation</a>&nbsp;&gt;&nbsp;<a href="/jrockit/releases/index.html">Oracle JRockit JDK Release Documentation</a>');
}

else if (strHref.indexOf("jrockit/tools") != -1) {

	document.write('<a href="/jrockit/webdocs/index.html">Oracle JRockit Documentation</a>&nbsp;&gt;&nbsp;<a href="/jrockit/tools/index.html">Oracle JRockit Mission Control Documentation</a>');
}

else if (strHref.indexOf("jrockit/webdocs/index.html") != -1) {

	document.write('Oracle JRockit Online Documentation');
}

else if (strHref.indexOf("kodo/docs40/supp_configs") != -1) {

	document.write('<a href="../index.html">BEA Kodo 4.0 Documentation</a>');
}

else if (strHref.indexOf("kodo/docs41/supp_configs") != -1) {

	document.write('<a href="../index.html">Oracle Kodo 4.1 Documentation</a>');
}

else if (strHref.indexOf("kodo/docs40") != -1) {

	document.write('<a href="../../index.html">BEA Kodo 4.0 Documentation</a>');
}

else if (strHref.indexOf("kodo/docs41/index.html") != -1) {

	document.write('Oracle Kodo 4.1 Documentation');
}

else if (strHref.indexOf("kodo/docs41") != -1) {

	document.write('<a href="/kodo/docs41/index.html">Oracle Kodo 4.1 Documentation</a>');
}

else if (strHref.indexOf("liquiddata/docs85") != -1) {

	document.write('<a href="../index.html">BEA AquaLogic Data Services Platform 2.0 Documentation</a>');
}

else if (strHref.indexOf("liquiddata/docs81") != -1) {

	document.write('<a href="../index.html">BEA Liquid Data for WebLogic 8.1 Documentation </a>');
}

else if (strHref.indexOf("/pages/docs10/index.html") != -1) {

	document.write('AquaLogic Pages 1.0 Documentation</a>');
}

else if (strHref.indexOf("/pages/docs10") != -1) {

	document.write('<a href="/pages/docs10/index.html">AquaLogic Pages 1.0 Documentation</a>');
}

else if (strHref.indexOf("pathways/docs10/index.html") != -1) {

	document.write('AquaLogic Pathways 1.0 Documentation');
}

else if (strHref.indexOf("pathways/docs10") != -1) {

	document.write('<a href="/pathways/docs10/index.html">AquaLogic Pathways 1.0 Documentation</a>');
}

else if (strHref.indexOf("pathways/docs15/index.html") != -1) {

	document.write('AquaLogic Pathways 1.5 Documentation');
}

else if (strHref.indexOf("pathways/docs15") != -1) {

	document.write('<a href="/pathways/docs15/index.html">AquaLogic Pathways 1.5 Documentation</a>');
}

else if (strHref.indexOf("platform/docs81") != -1) {

	document.write('<a href="../index.html">BEA WebLogic Platform 8.1 Documentation</a>');
}

else if (strHref.indexOf("platform/suppconfigs/index.html") != -1) {

	document.write('<a href="/common/docs92/index.html">BEA Products Installation and Configuration Documentation</a> &gt; Supported Configurations');
}

else if (strHref.indexOf("platform/docs102/index.html") != -1) {

	document.write('BEA WebLogic Platform 10.2 Documentation');
}

else if (strHref.indexOf("platform/docs102") != -1) {

	document.write('<a href="/platform/docs102/index.html">BEA WebLogic Platform 10.2 Documentation</a>');
}

else if (strHref.indexOf("platform/suppconfigs") != -1) {

	document.write('<a href="/common/docs92/index.html">BEA Products Installation and Configuration Documentation</a> &gt; <a href="../index.html">Supported Configurations</a>');
}

else if (strHref.indexOf("rfid/edge_server/docs20") != -1) {

	document.write('<a href="/rfid/edge_server/docs20/index.html">BEA WebLogic RFID Edge Server 2.0 Documentation</a>');
}

else if (strHref.indexOf("rfid/edge_server/docs21") != -1) {

	document.write('<a href="/rfid/edge_server/docs21/index.html">BEA WebLogic RFID Edge Server 2.1 Documentation</a>');
}

else if (strHref.indexOf("rfid/edge_server/docs22/index.html") != -1) {

	document.write('BEA WebLogic RFID Edge Server 2.2 Documentation');
}

else if (strHref.indexOf("rfid/edge_server/docs22") != -1) {

	document.write('<a href="/rfid/edge_server/docs22/index.html">BEA WebLogic RFID Edge Server 2.2 Documentation</a>');
}

else if (strHref.indexOf("rfid/edge_server/docs23/index.html") != -1) {

	document.write('BEA WebLogic RFID Edge Server 2.3 Documentation');
}

else if (strHref.indexOf("rfid/edge_server/docs23") != -1) {

	document.write('<a href="/rfid/edge_server/docs23/index.html">BEA WebLogic RFID Edge Server 2.3 Documentation</a>');
}

else if (strHref.indexOf("rfid/edge_server/docs30/index.html") != -1) {

	document.write('BEA WebLogic RFID Edge Server 3.0 Documentation');
}

else if (strHref.indexOf("rfid/edge_server/docs30") != -1) {

	document.write('<a href="/rfid/edge_server/docs30/index.html">BEA WebLogic RFID Edge Server 3.0 Documentation</a>');
}

else if (strHref.indexOf("rfid/enterprise_server/docs20") != -1) {

	document.write('<a href="/rfid/enterprise_server/docs20/index.html">BEA WebLogic RFID Enterprise Server 2.0 Documentation</a>');
}

else if (strHref.indexOf("rfid/mobile_sdk/docs10/index.html") != -1) {

	document.write('BEA WebLogic RFID Edge Mobile SDK 1.0 Documentation</a>');
}

else if (strHref.indexOf("rfid/mobile_sdk/docs10") != -1) {

	document.write('<a href="/rfid/mobile_sdk/docs10/index.html">BEA WebLogic RFID Edge Mobile SDK 1.0 Documentation</a>');
}

else if (strHref.indexOf("salt/docs20/index.html") != -1) {

	document.write('BEA SALT 2.0 Documentation');
}

else if (strHref.indexOf("salt/docs20") != -1) {

	document.write('<a href="/salt/docs20/index.html">BEA SALT 2.0 Documentation</a>');
}

else if (strHref.indexOf("salt/docs11/index.html") != -1) {

	document.write('BEA SALT 1.1 Documentation');
}

else if (strHref.indexOf("salt/docs11") != -1) {

	document.write('<a href="/salt/docs11/index.html">BEA SALT 1.1 Documentation</a>');
}

else if (strHref.indexOf("bea/sam/docs10/index.html") != -1) {

	document.write('BEA Service Assembly Modeler (SAM) 1.0 Documentation');
}

else if (strHref.indexOf("smartconnect/docs26/index.html") != -1) {

	document.write('BEA SmartConnect 2.6 Documentation</a>');
}

else if (strHref.indexOf("smartconnect/docs26") != -1) {

	document.write('<a href="/smartconnect/docs26/index.html">BEA SmartConnect 2.6 Documentation</a>');
}

else if (strHref.indexOf("smartconnect/docs30/index.html") != -1) {

	document.write('BEA SmartConnect 3.0 Documentation</a>');
}

else if (strHref.indexOf("smartconnect/docs30") != -1) {

	document.write('<a href="/smartconnect/docs30/index.html">BEA SmartConnect 3.0 Documentation</a>');
}

else if (strHref.indexOf("tmc/docs15") != -1) {

	document.write('<a href="/tmc/docs15/index.html">BEA WebLogic Server Extension for Tomcat 1.5 Documentation</a>');
}

else if (strHref.indexOf("tsam/docs11/index.html") != -1) {

	document.write('BEA TSAM 1.1 Documentation</a>');
}

else if (strHref.indexOf("tsam/docs11") != -1) {

	document.write('<a href="/tsam/docs11/index.html">BEA TSAM 1.1 Documentation</a>');
}

else if (strHref.indexOf("tsam/docs20/index.html") != -1) {

	document.write('BEA TSAM 2.0 Documentation</a>');
}

else if (strHref.indexOf("tsam/docs20") != -1) {

	document.write('<a href="/tsam/docs20/index.html">BEA TSAM 2.0 Documentation</a>');
}

else if (strHref.indexOf("tuxedo/ositp/v81/index.html") != -1) {

	document.write('<a href="/tuxedo/tux81/index.htm">Tuxedo 8.1</a> > BEA Tuxedo Mainframe Adapter for OSI TP 8.1 Documentation');
}

else if (strHref.indexOf("tuxedo/ositp/v81") != -1) {

	document.write('<a href="/tuxedo/tux81/index.htm">Tuxedo 8.1</a> > <a href="../index.htm">BEA Tuxedo Mainframe Adapter for OSI TP 8.1 Documentation</a>');
}

else if (strHref.indexOf("tuxedo/ositp/v91/") != -1) {

	document.write('<a href="../index.html">BEA Tuxedo Mainframe Adapter for OSI TP 9.1 Documentation</a>');
}

else if (strHref.indexOf("tuxedo/ositp/v100/index.html") != -1) {

	document.write('BEA Tuxedo Mainframe Adapter for OSI TP 10.0 Documentation');
}

else if (strHref.indexOf("tuxedo/ositp/v100") != -1) {

	document.write('<a href="/tuxedo/ositp/v100/index.html">BEA Tuxedo Mainframe Adapter for OSI TP 10.0 Documentation</a>');
}

else if (strHref.indexOf("tuxedo/eam/v91") != -1) {

	document.write('<a href="../index.html">BEA Tuxedo Mainframe Adapter for SNA 9.1 Documentation</a>');
}

else if (strHref.indexOf("tuxedo/eam/v100/index.html") != -1) {

	document.write('BEA Tuxedo Mainframe Adapter for SNA 10.0 Documentation');
}

else if (strHref.indexOf("tuxedo/eam/v100") != -1) {

	document.write('<a href="/tuxedo/eam/v100/index.html">BEA Tuxedo Mainframe Adapter for SNA 10.0 Documentation</a>');
}

else if (strHref.indexOf("tuxedo/tcp/v91/") != -1) {

	document.write('<a href="../index.html">BEA Tuxedo Mainframe Adapter for TCP 9.1 Documentation</a>');
}

else if (strHref.indexOf("tuxedo/tcp/v100/index.html") != -1) {

	document.write('<a href="/tuxedo/tux100/index.html">Tuxedo 10.0</a>&nbsp;&gt;&nbsp;Oracle Tuxedo Mainframe Adapter for TCP 10.0 Documentation');
}

else if (strHref.indexOf("tuxedo/tcp/v100/") != -1) {

	document.write('<a href="/tuxedo/tux100/index.html">Tuxedo 10.0</a>&nbsp;&gt;&nbsp;<a href="/tuxedo/tcp/v100/index.html">Oracle Tuxedo Mainframe Adapter for TCP 10.0 Documentation</a>');
}

else if (strHref.indexOf("tuxedo/tux90") != -1) {

	document.write('<a href="../index.html">BEA Tuxedo 9.0 Documentation</a>');
}

else if (strHref.indexOf("tuxedo/tux100/index.html") != -1) {

	document.write('BEA Tuxedo 10.0 Documentation</a>');
}

else if (strHref.indexOf("tuxedo/tux100") != -1) {

	document.write('<a href="/tuxedo/tux100/index.html">BEA Tuxedo 10.0 Documentation</a>');
}

else if (strHref.indexOf("wlcp/esdk22/index.html") != -1) {

	document.write('Extension SDK for BEA WebLogic Network Gatekeeper 2.2 Developer Documentation');
}

else if (strHref.indexOf("wlcp/esdk22") != -1) {

	document.write('<a href="/wlcp/esdk22/index.html">Extension SDK for BEA WebLogic Network Gatekeeper 2.2 Developer Documentation</a>');
}

else if (strHref.indexOf("wlcp/wlng22/index.html") != -1) {

	document.write('BEA WebLogic Network Gatekeeper 2.2 Documentation');
}

else if (strHref.indexOf("wlcp/wlng22") != -1) {

	document.write('<a href="/wlcp/wlng22/index.html">BEA WebLogic Network Gatekeeper 2.2 Documentation</a>');
}

else if (strHref.indexOf("wlcp/wlng30/protected/index.html") != -1) {

	document.write('BEA WebLogic Network Gatekeeper 3.0 Documentation');
}

else if (strHref.indexOf("wlcp/wlng30/protected") != -1) {

	document.write('<a href="/wlcp/wlng30/protected/index.html">BEA WebLogic Network Gatekeeper 3.0 Documentation</a>');
}

else if (strHref.indexOf("wlcp/wlng30/open/index.html") != -1) {

	document.write('BEA WebLogic Network Gatekeeper 3.0 Documentation');
}

else if (strHref.indexOf("wlcp/wlng30/open") != -1) {

	document.write('<a href="/wlcp/wlng30/open/index.html">BEA WebLogic Network Gatekeeper 3.0 Documentation</a>');
}

else if (strHref.indexOf("wlcp/wlng40/index.html") != -1) {

	document.write('Oracle Communications Services Gatekeeper 4.0 Documentation');
}

else if (strHref.indexOf("wlcp/wlng40") != -1) {

	document.write('<a href="/wlcp/wlng40/index.html">Oracle Communications Services Gatekeeper 4.0 Documentation</a>');
}

else if (strHref.indexOf("wlcp/wlss21") != -1) {

	document.write('<a href="../index.html">BEA WebLogic SIP Server 2.1 Documentation</a>');
}

else if (strHref.indexOf("wlcp/wlss22") != -1) {

	document.write('<a href="../index.html">BEA WebLogic SIP Server 2.2 Documentation</a>');
}

else if (strHref.indexOf("wlcp/wlss30/index.html") != -1) {

	document.write('BEA WebLogic SIP Server 3.0 Documentation');
}

else if (strHref.indexOf("wlcp/wlss30") != -1) {

	document.write('<a href="/wlcp/wlss30/index.html">BEA WebLogic SIP Server 3.0 Documentation</a>');
}

else if (strHref.indexOf("wlcp/wlss31/index.html") != -1) {

	document.write('BEA WebLogic SIP Server 3.1 Documentation');
}

else if (strHref.indexOf("wlcp/wlss31") != -1) {

	document.write('<a href="/wlcp/wlss31/index.html">BEA WebLogic SIP Server 3.1 Documentation</a>');
}

else if (strHref.indexOf("wlcp/wlss40/index.html") != -1) {

	document.write('BEA WebLogic SIP Server 4.0 Documentation');
}

else if (strHref.indexOf("wlcp/wlss40") != -1) {

	document.write('<a href="/wlcp/wlss40/index.html">BEA WebLogic SIP Server 4.0 Documentation</a>');
}

else if (strHref.indexOf("wles/docs42") != -1) {

	document.write('<a href="../index.html">BEA WebLogic Enterprise Security 4.2 Documentation</a>');
}

else if (strHref.indexOf("wlevs/docs20/index.html") != -1) {

	document.write('BEA WebLogic Event Server 2.0 Documentation');
}

else if (strHref.indexOf("wlevs/docs20") != -1) {

	document.write('<a href="/wlevs/docs20/index.html">BEA WebLogic Event Server 2.0 Documentation</a>');
}

else if (strHref.indexOf("wli/docs85") != -1) {

	document.write('<a href="../index.html">BEA WebLogic Integration 8.5 Documentation</a>');
}

else if (strHref.indexOf("wli/docs81") != -1) {

	document.write('<a href="../index.html">BEA WebLogic Integration 8.1 Documentation</a>');
}

else if (strHref.indexOf("wli/docs92/index.html") != -1) {

	document.write('BEA WebLogic Integration 9.2 Documentation');
}

else if (strHref.indexOf("wli/docs92") != -1) {

	document.write('<a href="/wli/docs92/index.html">BEA WebLogic Integration 9.2 Documentation</a>');
}

else if (strHref.indexOf("wli/docs102/index.html") != -1) {

	document.write('BEA WebLogic Integration 10.2 Documentation');
}

else if (strHref.indexOf("wli/docs102") != -1) {

	document.write('<a href="/wli/docs102/index.html">BEA WebLogic Integration 10.2 Documentation</a>');
}

else if (strHref.indexOf("wlibc/docs81") != -1) {

	document.write('<a href="../index.html">BEA WebLogic Integration - Business Connect BEA 8.1.2 Documentation</a>');
}

else if (strHref.indexOf("wljrockit/docs81") != -1) {

	document.write('<a href="../index.html">BEA JRockit SDK 8.1 Documentation</a>');
}

else if(strHref.indexOf("wljrockit/docs50") != -1) {

	document.write('<a href="../index.html">BEA JRockit JDK 5.0 Documentation</a>');
}

else if (strHref.indexOf("wljrockit/docs142") != -1) {

	document.write('<a href="../index.html">BEA JRockit 1.4.2 Documentation</a>');
}

else if (strHref.indexOf("wlloc/docs10/index.html") != -1) {

	document.write('BEA Liquid Operations Control 1.0 Documentation');
}

else if (strHref.indexOf("wlloc/docs10") != -1) {

	document.write('<a href="/wlloc/docs10/index.html">BEA Liquid Operations Control 1.0 Documentation</a>');
}

else if (strHref.indexOf("wloc/docs10/index.html") != -1) {

	document.write('BEA WebLogic Operations Control 1.0 Documentation');
}

else if (strHref.indexOf("wloc/docs10") != -1) {

	document.write('<a href="/wloc/docs10/index.html">BEA WebLogic Operations Control 1.0 Documentation</a>');
}

else if (strHref.indexOf("wlp/docs81") != -1) {

	document.write('<a href="../index.html">BEA WebLogic Portal 8.1 Documentation</a>');
}

else if (strHref.indexOf("wlp/docs92/index.html") != -1) {

	document.write('BEA WebLogic Portal 9.2 Documentation');
}

else if (strHref.indexOf("wlp/docs92") != -1) {

	document.write('<a href="/wlp/docs92/index.html">BEA WebLogic Portal 9.2 Documentation</a>');
}

else if (strHref.indexOf("wlp/docs100/index.html") != -1) {

	document.write('BEA WebLogic Portal 10.0 Documentation');
}

else if (strHref.indexOf("wlp/docs100") != -1) {

	document.write('<a href="/wlp/docs100/index.html">BEA WebLogic Portal 10.0 Documentation</a>');
}

else if (strHref.indexOf("wlp/docs102/index.html") != -1) {

	document.write('BEA WebLogic Portal 10.2 Documentation');
}

else if (strHref.indexOf("wlp/docs102") != -1) {

	document.write('<a href="/wlp/docs102/index.html">BEA WebLogic Portal 10.2 Documentation</a>');
}

else if (strHref.indexOf("wlrt/docs10") != -1) {

	document.write('<a href="/wlrt/docs10/index.html">BEA WebLogic Real Time 1.0 Documentation</a>');
}

else if (strHref.indexOf("wlrt/docs11") != -1) {

	document.write('<a href="/wlrt/docs11/index.html">BEA WebLogic Real Time, Core Edition 1.1 Documentation</a>');
}

else if (strHref.indexOf("wlrt/docs20/index.html") != -1) {

	document.write('BEA WebLogic Real Time 2.0 Documentation');
}

else if (strHref.indexOf("wlrt/docs20") != -1) {

	document.write('<a href="/wlrt/docs20/index.html">BEA WebLogic Real Time 2.0 Documentation</a>');
}

else if (strHref.indexOf("wls-ve/docs92-v10/index.html") != -1) {

	document.write('BEA WebLogic Server Virtual Edition 9.2 V1.0 Documentation');
}

else if (strHref.indexOf("wls-ve/docs92-v10") != -1) {

	document.write('<a href="/wls-ve/docs92-v10/index.html">BEA WebLogic Server Virtual Edition 9.2 V1.0 Documentation</a>');
}

else if (strHref.indexOf("wls-ve/docs92-v11/index.html") != -1) {

	document.write('BEA WebLogic Server Virtual Edition 9.2 V1.1 Documentation');
}

else if (strHref.indexOf("wls-ve/docs92-v11") != -1) {

	document.write('<a href="/wls-ve/docs92-v11/index.html">BEA WebLogic Server Virtual Edition 9.2 V1.1 Documentation</a>');
}

else if (strHref.indexOf("wls/docs81") != -1) {

	document.write('<a href="../index.html">BEA WebLogic Server 8.1 Documentation</a>');
}

else if (strHref.indexOf("wls/docs90") != -1) {

	document.write('<a href="../index.html">BEA WebLogic Server 9.0 Documentation</a>');
}

else if (strHref.indexOf("wls/docs91/ConsoleHelp") != -1) {

	document.write('<a href="/wls/docs91/index.html">BEA WebLogic Server 9.1 Documentation</a>');
}

else if (strHref.indexOf("wls/docs91") != -1) {

	document.write('<a href="../index.html">BEA WebLogic Server 9.1 Documentation</a>');
}

else if (strHref.indexOf("wls/docs92/ConsoleHelp") != -1) {

	document.write('<a href="/wls/docs92/index.html">BEA WebLogic Server 9.2 Documentation</a>');
}

else if (strHref.indexOf("wls/docs92/messages") != -1) {

	document.write('<a href="/wls/docs92/messages/index.html">BEA WebLogic Server and WebLogic Express 9.2 Documentation</a>');
}

else if (strHref.indexOf("wls/docs92/index.html") != -1) {

	document.write('BEA WebLogic Server 9.2 Documentation');
}

else if (strHref.indexOf("wls/docs92") != -1) {

	document.write('<a href="/wls/docs92/index.html">BEA WebLogic Server 9.2 Documentation</a>');
}

else if (strHref.indexOf("wls/docs100/index.html") != -1) {

	document.write('BEA WebLogic Server 10.0 Documentation');
}

else if (strHref.indexOf("wls/docs100") != -1) {

	document.write('<a href="/wls/docs100/index.html">BEA WebLogic Server 10.0 Documentation</a>');
}

else if (strHref.indexOf("wls/essex/TechPreview/index.html") != -1) {

	document.write('BEA WebLogic Server 10.3 Tech Preview Documentation');
}

else if (strHref.indexOf("wls/essex/TechPreview") != -1) {

	document.write('<a href="/wls/essex/TechPreview/index.html">BEA WebLogic Server 10.3 Tech Preview Documentation</a>');
}

else if (strHref.indexOf("wlspe/docs81/peoverview") != -1) {

	document.write('<a href="../index.html">BEA WebLogic Server Process Edition 8.1 Documentation</a>');
}

else if (strHref.indexOf("wl-ve/docs10-x/index.html") != -1) {

	document.write('BEA WebLogic Server 10.0 Virtual Edition Documentation');
}

else if (strHref.indexOf("wl-ve/docs10-x") != -1) {

	document.write('<a href="/wl-ve/docs10-x/index.html">BEA WebLogic Server 10.0 Virtual Edition Documentation</a>');
}

else if (strHref.indexOf("workshop/docs92/studio31") != -1) {
 
	document.write('<a href="/workshop/docs92/studio31.html">BEA Workshop Studio 3.1</a>');
}

else if (strHref.indexOf("workshop/docs92") != -1) {

	document.write('<a href="/workshop/docs92/index.html">BEA Workshop Product Family</a>');
}

else if (strHref.indexOf("wlw/docs100/index.html") != -1) {

	document.write('BEA Workshop for WebLogic Platform');
}

else if (strHref.indexOf("wlw/docs100") != -1) {

	document.write('<a href="/wlw/docs100/index.html">BEA Workshop for WebLogic Platform</a>');
}

else if (strHref.indexOf("wlw/docs101/index.html") != -1) {

	document.write('BEA Workshop Product Family');
}

else if (strHref.indexOf("wlw/docs101") != -1) {

	document.write('<a href="/wlw/docs101/index.html">BEA Workshop Product Family</a>');
}

else if (strHref.indexOf("wlw/docs102/index.html") != -1) {

	document.write('BEA Workshop Product Family');
}

else if (strHref.indexOf("wlw/docs102") != -1) {

	document.write('<a href="/wlw/docs102/index.html">BEA Workshop Product Family</a>');
}

}

}