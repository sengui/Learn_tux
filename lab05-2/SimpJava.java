/* ------------------------------------------------------------------------
   -- DISCLAIMER:
   --    This script is provided for educational purposes only. It is NOT
   --    supported by Oracle World Wide Technical Support.
   --    The script has been tested and appears to work as intended.
   --    You should always run new scripts on a test instance initially.
   -- 
   ------------------------------------------------------------------------ */

import weblogic.wtc.jatmi.TypedBuffer;
import weblogic.wtc.jatmi.TypedString;
import com.oracle.tuxedo.tjatmi.*;

public class SimpJava extends TuxedoJavaServer
{
    public SimpJava() {}

    public int tpsvrinit() throws TuxException { return 0; }

    public void tpsvrdone() {}

    public void MyTOUPPERJavaService(TPSVCINFO rqst) throws TuxException {
        TypedBuffer svcData;

        TuxAppContext   myAppCtxt = getTuxAppContext();

        svcData = rqst.getServiceData();

        TypedString TbStr = (TypedString)svcData;

        System.out.println("svcData:" + TbStr.toString());

        String newstr = TbStr.toString().toUpperCase();

        TypedString replyTbString = new TypedString(newstr);

        myAppCtxt.tpreturn(TPSUCCESS, 0, replyTbString, 0);
    }
}


