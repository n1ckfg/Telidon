File: README 

README - JAVA NAPLPS DECODER/VIEWER

by Alastair J.W. Mayer

Quickstart

Compile all the *.java files.  (If you're using a 1.0 Java VM,
you can use the supplied naplps.zip classes file).   Set your
CLASSPATH if necessary.  Run the Viewer ("java Viewer" or
"java naplps.Viewer").  Use the "File"->"Open" menu and dialog
to open a NAPLPS PDI file (.nap or .pdi, some sample .pdi files
are included.)  Have fun.

What is NAPLPS?

NAPLPS is the North American Presentation Level Syntax Protocol.
This code goes back to the mid-1980s, originally intended as a
flexible protocol for displaying text & graphic pages on computers
via phone lines.  (Think of it as an early version of the Web.)
It's optimized for low speed links and relatively low-res screens.

However, it has some advantages over the common bitmap images
(.gif, .jpg, .png etc) in that it's a vector- or object-based 
format rather than raster (although it can include raster images).
This means the drawing sequence can be replayed and edited, which
could be useful for e.g. conferencing/collaboration systems.
(The conferencing system CoSy that I wrote at U Guelph supported
the embedding of NAPLPS images in messages, but there was never
any client software to take advantage of that capability.)

NAPLPS can include timing instructions (WAIT), providing an
animation capability by successively drawing slightly different
images in the same area between waits.

What is here?

As part of a reimplementation of CoSy, in Java, that I started
a couple of years ago, I wanted to include appropriate client
software to support graphics as well as text.  That client
software (which can act as a distributed whiteboard) is on my
home page under "JCoSy", but it uses this naplps package for
decoding the PDI's (picture description instructions).

What is here is the naplps decoder package, which includes a
viewer to look at sample NAPLPS files (*.nap and *.pdi). 
NAPLPS, despite its name (North American etc) seems to have
caught on in Japan as a file format, some of the sample files
here were borrowed from Japanese web sites (there's even a
Netscape plugin available out there somewhere for NAPLPS).

Is it fully functional?

The basic graphic stuff works, meaning that a displayed file
will generally look more-or-less like it's supposed to.

However, there's lots of work left.  Specifically:

   Filled arcs are incomplete.  The outline is drawn but
   the fill is simplified to a filled triangle based on the
   three points that define the arc.

   Textures are incomplete.  I do solid fill or no fill, not
   any of the line or grid textures.

   Regions - NAPLPS provides for some interesting effects (eg
   animation, panning) by defining regions that alter the
   coordinate system (bad explanation).  I haven't done anything
   with this yet.

   Text orientation - limited capabilities here, basicially
   going with what Java AWT gave me for free.  This needs to
   be extended.

Other Notes:

  This was originally developed using JDK 1.0.2-5, so there
are some methods that are deprecated in 1.1, and perhaps more
so in 1.2.  It compiles (with warnings) under JDK 1.1.7, and
seems to run alright.

   The classes in naplps.zip were compiled with JDK 1.0.5,
you'll need to recompile if you're using 1.1 or 1.2.

   This code is released under the GPL.  See the file "Copying"
for details.  Basically you can do what you like with it, but
if you distribute anything based on it, you have to provide the
source,  you can only charge reasonable distribution (not
licensing) fees, and release under a GPL-compatible license.

Cheers.

