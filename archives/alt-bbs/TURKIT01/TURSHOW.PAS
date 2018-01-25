{*********************************************************}
{                                                         }
{ NAPLPS Unit Demo                                        }
{ Copyright (c) 1993 Software @ Work, All Rights Reserved }
{ Copyright (c) 1993 Shawn Rhoads, All Rights Reserved    }
{                                                         }
{*********************************************************}

{$F+,O-,A+,B-,E+,L+,N+,V-,G+}  { to for 8086 use G- }
{$M 65520,0,100000}

{$DEFINE NoDebug}

{$IFDEF Debug}
{$R+,S+,D+,L+}
{$ELSE}
{$R-,S-,D-,L-}
{$ENDIF}

Program TurShow;

Uses  unaplps, crt;

var i, startclock, endclock, filesze: longint;
    secs: real;
    j: integer;
    filename: string[80];
    dispfile: file;
    outbuf: string;
    a: array[1..300] of byte;
    ch: char;
    baudrate, byteon: longint;
    botched, nostat: boolean;

Function Value(s:string):longint;

var e:integer;
    j: longint;

begin
  val(s,j,e);
  value:=j;
end;

Function Up(C:String):String;

Var
  A: String;
  I: Integer;

Begin
  A:='';
  For I:=1 to Length(C) do
    A:=A+UpCase(C[i]);
  Up:=A;
End;

begin
  filename:='<no file specified>  Use "TurShow <filename>"';
  botched:=false;
  writeln;

  if paramcount = 0 then begin
    writeln('TurShow v1.06 (c) Copyright 1993 Shawn Rhoads, ALL RIGHTS RESERVED');
    writeln('              (c) Copyright 1993 Software @ Work, ALL RIGHTS RESERVED');
    writeln;
    writeln('NAPLPS Viewer Program.  Requires CGA or better.');
    writeln(' Use format:  TURSHOW <filename> <options>');
    writeln;
    writeln(' <filename> is NAPLPS frame you wish to display.');
    writeln(' <options>:  -CGA     Display in CGA 320x200x4   mode.  (Default CGA)');
    writeln('             -EGA     Display in EGA 640x350x16  mode.  (Default EGA)');
    writeln('             -VGA     Display in VGA 640x480x16  mode.  (Default VGA)');
    writeln('             -SVGA    Display in SVGA 320x200x256 mode.');
    writeln('             -SVGA1   Display in SVGA 640x400x256 mode.');
    writeln('             -SVGA2   Display in SVGA 640x480x256 mode.');
    writeln('             -SVGA3   Display in SVGA 800x600x256 mode.');
    writeln('             -SVGA4   Display in SVGA 1024x768x256 mode.');
    writeln('             -SVGA5   Display in SVGA 640x350x256 mode.');
    writeln('             -SVGA6   Display in SVGA 1028x1024x256 mode.');
    writeln('             -CBIOS   Use your BIOS routines for color writes.');
    writeln('             -B<baud> Display at <baud> baudrate.  Ex: -b2400');
    writeln('             -NoStat  Supress the displaying of statistics.');
    writeln;
    writeln('For more information on this program, call the TurBoard BBS Support');
    writeln('system at: 404/395-6326.');
    halt(0);
  end;

  baudrate:=0;
  byteon:=0;
  nostat:=false;
  for i:=1 to paramcount do begin
    if pos('-B',up(paramstr(i)))>0 then
      baudrate:=value(copy(paramstr(i),3,length(paramstr(i))-2)) else
    if pos('-CGA',up(paramstr(i)))>0 then displaytype:=1 else
    if pos('-EGA',up(paramstr(i)))>0 then displaytype:=3 else
    if pos('-SVGA',up(paramstr(i)))>0 then begin
      svgaflag:=true;
      svgamode:=value(copy(paramstr(i),6,length(paramstr(i))-5));
      if (svgamode<0) or (svgamode>6) then svgamode:=0;
    end else
    if pos('-VGA',up(paramstr(i)))>0 then displaytype:=9 else
    if pos('-CBIOS',up(paramstr(i)))>0 then bioscolor:=true else
    if pos('-NOSTAT',up(paramstr(i)))>0 then nostat:=true else
    filename:=up(paramstr(i));
  end;

    writeln('TurShow NAPLPS (c) Copyright 1993 Shawn Rhoads, ALL RIGHTS RESERVED');
    writeln('               (c) Copyright 1993 Software @ Work, ALL RIGHTS RESREVED');
    i:=tenths;
    while (tenths-i<15) and (i<=tenths) do ;

    assign(dispfile,filename);
    {$I-} reset(dispfile,1) {$I+};
    if ioresult<>0 then begin
      writeln('Unable to open file:  ',filename);
      halt(1);
    end else begin
      turnnapon;
      startclock:=tenths;
      repeat
        blockread(dispfile,a,20,j);
        outbuf:='';
        for i:=1 to j do ansiwrite(chr(a[i]));
        if baudrate>0 then begin
          byteon:=byteon+j;
          while ((100*byteon) div (tenths-startclock))>baudrate do
            napcursor;
        end;
        napcursor;
      until (j=0) or keypressed;
      endclock:=tenths;
      filesze:=filesize(dispfile);
      close(dispfile);
      if keypressed then botched:=true;
      i:=tenths;
      ch:=#255;
      while (tenths-i<200) and (i<=tenths) and not keypressed do napcursor;
      while keypressed do ch:=readkey;
      turnnapoff;
      clrscr;
      if not nostat then begin
        writeln('TurShow NAPLPS Statistics:');
        writeln;
        if botched then begin
          writeln('Display aborted, no statistics available.');
        end else begin
          secs:=1.0 * (endclock-startclock) / 10;
          writeln('Time to display file: ',secs:0:1,' seconds.');
          writeln('        Size of file: ',filesze,' bytes');
          if secs<>0 then
          writeln('Simulated Throughput: ',((100*filesze) div
            (endclock-startclock)):0,' BAUD');
          writeln;
        end;
        writeln('Thanks for using TurShow!');
      end;
    end;

end.