//If you can see this you are using a browser that does not support
//JavaScript or Jscript. Please download Netscape Navigator Version 4.0
//(or newer) from http:\home.netscape.com or http:\www.microsoft.com
// Microsoft Internet Explorer Version 4.0 (or newer) from http://home.microsoft.com
//
//This script opens a new, small, floating window and puts TOCname.htm and IXname.htm files in it.
//Sets a generic popup window code to enable the display of some viewlets in the WebLogic Platform Tour:


function SetWindowName() {
        window.name="qaview";
}
        SetWindowName();

//Position windows on right side
leftPos = 0
if (screen) {
leftPos = screen.width-620;
}

function OpenWindowToc(){
                var tocwin = window.open('creclientTOC.html', 'newWin1', 'resizable=yes,scrollbars=yes,status=0,width=450,height=600,left='+leftPos+',top=20');
}

function OpenWindowTuxedoToc(){
                var tocwin = window.open('creclientTOC.htm', 'newWin1', 'resizable=yes,scrollbars=yes,status=0,width=450,height=600,left='+leftPos+',top=20');
}

function OpenWindowIndex(){
                var indexwin = window.open('creclientIX.html', 'newWin2', 'resizable=yes,scrollbars=yes,status=0,width=450,height=600,left='+leftPos+',top=20');
}

function OpenWindowTuxedoIndex(){
                var indexwin = window.open('creclientIX.htm', 'newWin2', 'resizable=yes,scrollbars=yes,status=0,width=450,height=600,left='+leftPos+',top=20');
}

function popup_window( url, id, width, height )
{
      	popup = window.open( url, id, 'toolbar=no,scrollbars=no,location=no,statusbar=no,menubar=no,resizable=no,width=' + width + ',height=' + height + ',left=100,top=100' );
      	popup.focus();
}

function popup_window_bars( url, id, width, height )
{
      	popup = window.open( url, id, 'toolbar=no,scrollbars=yes,location=no,statusbar=no,menubar=yes,resizable=no,width=' + width + ',height=' + height + ',left=100,top=100' );
      	popup.focus();
}
