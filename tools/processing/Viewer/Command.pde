

import java.awt.Graphics;

class Command extends Object {
  
	Context ctx;
	byte opcode;

	Command(Context context, byte op) {
		ctx = context;
		opcode = op;
	}
	
	void execute(PGraphics gr) {
	  //
  }
	
}
