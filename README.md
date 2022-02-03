![TelidonP5](/tools/rosetta_stone/cover/screenshots/shark.gif)
# TelidonP5
<p>
	<b><a href="https://github.com/n1ckfg/Telidon/blob/master/js/telidon/TelidonP5.js">TelidonP5.js</a></b> allows NAPLPS vector graphics files to be displayed in a browser using <a href="https://p5js.org/">p5.js</a>. Its companion encoder/decoder library <b><a href="https://github.com/n1ckfg/Telidon/blob/master/js/telidon/naplps.js">naplps.js</a></b> can also be used independently.<br/>
	[ <a href="https://n1ckfg.github.io/Telidon/"><i>See an example</i></a> ]
</p>

### Contents:
<pre>
./archives/ <-- contemporary utility apps, most without source.
./css/ <-- for web demo.
./docs/ <-- original spec documentation and commentary.
./images/ <-- testbed of NAPLPS images.
./js/ <-- TelidonP5.js lives here.
./tools/ <-- misc. new tests and prototypes, with source.
</pre>

### Tutorial:
<pre>
./tools/rosetta_stone/boom
A simple NAPLPS image explained instruction by instruction. Start here.
</pre>

### Experimental Viewers (source included):
<pre>
TelidonP5.js (Nick Fox-Gieg, 2018)
./js/telidon/
License: MIT
Language: JavaScript
Read, edit, write NAPLPS; convert from SVG; export to GIF.
Tested with Firefox, Chrome, Safari.
position: yes / color: yes / text: no / animation: no

TelidonP5 prototype (Nick Fox-Gieg, 2018)
./tools/processing/TelidonP5/
License: MIT
Language: Java
Read NAPLPS only.
Tested in Win10, OS X High Sierra.
position: yes / color: no / text: no / animation: no

Ajwm Decoder (Alastair Mayer, 1999)
./archives/ajwm-naplps/
License: GPL
Language: Java
Read NAPLPS only.
Tested in Win10, Ubuntu; doesn't work in OS X.
position: yes / color: yes / text: no / animation: no
</pre>

### Reference Viewers (no source):
<pre>
TurShow (Shawn Rhoads, 1993)
./archives/simtel/TURSHOW6/
License: unknown
Language: Pascal
Read NAPLPS only.
Tested with DosBox; doesn't work in Win10.
position: yes / color: yes / text: yes / animation: yes

Microstar Graphics Editor (Microstar Software, 1991)
./archives/simtel/MGE201A/
License: unknown
Language: unknown
Read, edit, write NAPLPS.
Tested with WinXP; doesn't work with DosBox.
position: yes / color: yes / text: yes / animation: ?

Personality+III (Microstar Software, 1992)
./archives/simtel/PP3217A/
License: unknown
Language: unknown
Read NAPLPS only.
Untested; doesn't work with WinXP or DosBox.

Note: ./archives/ also contains more untested utilities.
</pre>

### Background info:
<p>
	August 15th, 2018 marked the 40th anniversary of the <a href="https://en.wikipedia.org/wiki/Telidon">Telidon</a> vector graphics workstation, launched in 1978. The Telidon hardware was discontinued in 1985, but its file format, standardized as <a href="https://en.wikipedia.org/wiki/NAPLPS">NAPLPS</a>, thrived and remained in wide use throughout the <a href="https://en.wikipedia.org/wiki/Bulletin_board_system">BBS</a> era, until the mid-1990s. Thanks to its exceptionally small file size and limited animation features, NAPLPS can be seen as a technological ancestor of the <a href="https://en.wikipedia.org/wiki/GIF#Animated_GIF">animated GIF</a> and the <a href="https://en.wikipedia.org/wiki/SWF">Flash SWF</a>&mdash;a new artistic medium that could be both produced and distributed on the same machine.
</p>
<p>
	From 1982&ndash;1985, members of the Toronto arts org <a href="http://interaccess.org/">InterAccess</a> used Telidon systems to produce an ambitious series of <a href="https://motherboard.vice.com/en_us/article/ezveak/the-original-net-artists">interactive BBS-based artworks</a> in the format.
</p>		
<p>
	Nick Fox-Gieg<br/>
	190406
</p>
