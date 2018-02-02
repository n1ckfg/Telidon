Archival strategies ranked from simple to complex:

1. NAPLPS images are readable in CorelDraw, including current CorelDraw 2017;
you can then save to a modern format like SVG. Original fonts are not preserved,
but you can approximate them with a TTF equivalent included here.
https://github.com/n1ckfg/Telidon/tree/master/fonts/Telidon_Regular

2. Turshow can be run in DOSBox to more faithfully present NAPLPS images,
displaying the original fonts and using the progressive draw-on effect. Turshow
does not export, but DOSBox can be used with a screen capture utility.
https://github.com/n1ckfg/Telidon/tree/master/archives/prodigy-slack/turshow6

3. The TelidonP5 Java decoder can read polygon info. (If you want to try it out,
just be aware that it's not yet reading the header info automatically, so you'll
have to manually set number of bytes per coordinate, etc.)
https://github.com/n1ckfg/Telidon/tree/master/processing/TelidonP5

4. For displaying original interactive works beyond individual images, John
Durno at the University of Victoria has developed a complete BBS emulator setup
for Ubuntu Linux.
https://github.com/n1ckfg/Telidon/tree/master/archives/uvic
