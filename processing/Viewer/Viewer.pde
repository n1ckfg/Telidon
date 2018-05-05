/**
* naplps.Viewer
* Copyright (C) 1997, 1999 by Alastair JW Mayer,
* All rights reserved.
* May be copied, modified and/or distributed according to
* the terms of the GNU License (GPL) version 2.
* It is requested (but not required) that changes be posted
* back to me at al11@delphi.com,
* see also http://members.xoom.com/amayer/software/
*/



import java.io.*;
import java.awt.*;
import java.net.*;

/**
* A NAPLPS viewer application.   There's some code here for
* setting up as a server for remote viewer apps, this is for
* testing in conjuction with conferencing/whiteboarding app
* (ie JCoSy).
*
* Use the File/Open dialog to select a NAPLPS PDI (Picture
* Description Instruction) file (extension .nap or .pdi) to
* view.   Most of the other stuff doesn't work yet.
*/

	 Show pdi;
	 MenuBar menubar;
    Menu fileMenu, optMenu;
    static Viewer me;
    Button step;
    Canvas canv;
    Panel pan;
    Graphics gr;
	boolean stepmode = false;
   	
   void init() 
   {  /* try this */
      setMenuBar(menubar = new MenuBar());
      menubar.add(fileMenu = new Menu("File"));
      //fileMenu.add("New");
      fileMenu.add("Open...");
      fileMenu.add("Server");
      //fileMenu.add("Save");
      //fileMenu.add("Close");
      fileMenu.addSeparator();
      //fileMenu.add("Print...");
      //fileMenu.addSeparator();
      fileMenu.add("Exit");
   	menubar.add(optMenu = new Menu("Options"));
   	optMenu.add("Step");
   	optMenu.addSeparator();
      optMenu.add("Step...");
      optMenu.add("Bgnd Color...");
     // add("Center", canv = new Canvas());
      //add("North", pan = new Panel());
     // pan.setBackground(Color.lightGray);
     // pan.add(step = new Button("Step"));
      
      resize(516, 550); 
      setBackground(Color.gray); // was black
      setFont(new Font("Courier",Font.PLAIN,14));
      show();
      pdi = new Show();
   }
  
	boolean action(Event e, Object arg)
	{
	
   if (e.target instanceof MenuItem) {
     if (((String)e.arg).equals("Exit")) {
       System.exit(0);
     }
     else if (((String)e.arg).equals("Step...")) {
     System.out.println("setting step mode");
     	 stepmode = true;
     }
     else if (((String)e.arg).equals("Step")) {
     System.out.println("steped");
     	pdi.step(gr);
     	return true;
     }
	  else if (((String)e.arg).equals("Open...")) {	// offline read
      gr = /*canv.*/getGraphics();
     gr.translate(0,-5);
      FileDialog fd;
      try {
   	 fd = new FileDialog(this, "NAPLPS");
   	 fd.show();
   	 String fname = fd.getFile();
   	 String fdir = fd.getDirectory();
   	DataInputStream dis = new DataInputStream(new FileInputStream(fdir+"/"+fname));
   	pdi.init(dis);
   	pdi.setStep(stepmode);
  	
  	System.out.println("size is: "+size());
  //	pdi.screen = (size().width > size().height) ? size().width : size().height;
   	pdi.ctx.screen = 512;
   	gr.setColor(Color.white);// for now
   	pdi.disassemble(gr);
   	}
   	catch (IOException ex) {
   		System.err.println("IO exception");
   	}
	  	}
	  else if (((String)e.arg).equals("Server")) { // act as view server
	    gr = getGraphics();
	    gr.translate(0,-5);
	    Socket sock;
	    try {
	    ServerSocket ss = new ServerSocket(1234);
	    System.out.println("got server socket, # "+ss.getLocalPort());
	     sock = ss.accept();
	     System.out.println("got socket");
	     DataInputStream dis = new DataInputStream(sock.getInputStream());
	     pdi.init(dis);
	     pdi.setStep(stepmode);
	     System.out.println("got client connection");
	     pdi.ctx.screen = 512;
	     gr.setColor(Color.white);
	     pdi.disassemble(gr);
	    }
	    catch (IOException exx) {
	    	System.err.println("IO exception -"+exx);
	    }
	   }
   }
	return true;
	}
	}
