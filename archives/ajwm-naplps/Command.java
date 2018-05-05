package naplps;

import java.awt.Graphics;

class Command extends Object
{
	Context ctx;
	byte opcode;

	public Command(Context context, byte op)
	{
		ctx = context;
		opcode = op;
	}
	
	
	public void execute(Graphics gr)
	{
	}
	
}