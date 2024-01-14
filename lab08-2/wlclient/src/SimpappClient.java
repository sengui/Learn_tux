/* 
 * ------------------------------------------------------------------------
 * -- DISCLAIMER:
 * --    This script is provided for educational purposes only. It is NOT
 * --    supported by Oracle World Wide Technical Support.
 * --    The script has been tested and appears to work as intended.
 * --    You should always run new scripts on a test instance initially.
 * -- 
 * ------------------------------------------------------------------------
 */

package com.oracle.salt.examples.simpapp.wlclient;

import java.util.Random;
import java.util.Properties;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.io.*;
import java.rmi.RemoteException;
import javax.xml.rpc.Stub;



public class SimpappClient {

    public static void main(String[] args) throws Exception {
        TuxedoWebService service;
        Simpapp_PortType port;

        if( args.length < 1 )
        {
            System.out.println( "Please specify the string to tansfer." );
            return;
        }

        service = new TuxedoWebService_Impl();
        port = service.getSimpapp_GWWS1_HTTPPort();
        System.out.println( "ToUpper Returns: " + port.toUpperWS(args[0]) );
    }

}
