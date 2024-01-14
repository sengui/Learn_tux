<!-- Begin
	// The <replace> value must be replaced with the product revision folder name. ie. docs81, tux90
	// The relative path to search_offline_main.html may need to be modified to find the search folder
	// The path below is for a platform release which need to go two levels up.
	// This function is called by the child window that handles CD searches
	function getSearchText() {
	    return document.forms[0].q.value;
	}

	function doSearch() {
	  dotdot = document.location.href;
	  re = new RegExp(".*<replace>\/", "i");
	  dotdot = dotdot.replace( re, "");
	  re = new RegExp( "[^/]*\/", "g");
	  dotdot = dotdot.replace(re, "../");
	  re = new RegExp( "[_0-9a-zA-Z].*", "i" );
	  dotdot = dotdot.replace( re, "" )
		// search for any spaces and replace with '+'	
		var theEntry=getSearchText();
		var pattern = /\b \b/ig;
		var theQuery = theEntry.replace(pattern,"+");
		window.open( dotdot + "../../search/search_offline_main.html", "subwin");
		return false;
	}

// End -->

