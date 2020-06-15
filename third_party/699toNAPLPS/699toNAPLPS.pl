#!/usr/bin/perl

# 699-to-NAPLPS.pl
# convert Telidon 699 PDIs to 709/NAPLPS
# John Durno, 2019
use strict;
use warnings;
use File::Path qw(make_path);
use Libraries::Texture qw(texture);
use Libraries::Textconv qw(textsize);

#dir to convert
my $indir=$ARGV[0];


#put the converted files in a directory
my $outdir = "NAPLPS";
eval { make_path("$outdir/$indir") };
if ($@) {
  print "Couldn't create $outdir/$indir: $@";
  exit;
}

my $logfile = 'logfile.txt';
open(LOGFILE, ">$logfile") || die "can't open $logfile: $!";

my @files = glob("$indir/*"); #filenames include directory name

# string to hold the converted file up to the pdi before the last point abs invisible
our $converted = '';

#string to hold the fully converted file
our $fully_converted = '';

# status flags
our $textmode = 0; #0 = PDI, 1 = text;
our $colourmode = 1; #0 = grey scale, 1 = colour

#current colour
our $current_colour;

# number of byte we're currently processing
our $bytecount = 0;

# current drawing point as pdi
our $current_position;

# current text size
our $current_textsize = '@Az';

#current textsize supplied by PDI
our $current_textsize_numeric = 0;

#is current text double height?
our $current_textsize_double = 0;

#y value of current text size, in decimal
our $current_textsize_y_dec = 0;

#current text format
our $current_textformat = 'p@';

#set displacement on next shift
our $displacement_flag = 0;

#mask size for textures
our $masksize = '@R@';

#four custom texture masks
my %textures = (
	'`' => 0,
	'h' => 0,
	'p' => 0,
	'x' => 0,
);

#texture masks in order
#my @textures = ('`','h','p','x');
my @textures = ('`');

#identifier of last saved texture
my $lastSavedTexture = '';



#hash of ascii bytes that do nothing (in 699)
my %do_nothing = (
	"00000000" => "NUL",
	"00000001" => "SOH",
	"00000010" => "STX",
	"00000011" => "ETX",
	"00000100" => "EOT",
	"00000101" => "ENQ",
	"00000110" => "ACK",
	"00010000" => "DLE",
	"00010001" => "DC1",
	"00010010" => "DC2",
	"00010011" => "DC3",
	"00010100" => "DC4",
	"00010101" => "NAK",
	"00010110" => "SYN",
	"00010111" => "ETB",
	"00011000" => "CAN",
	"00011010" => "SUB",
	"00011011" => "ESC",
	"00011100" => "FS",
	"00011101" => "GS",
	"00011110" => "RS",
	"00011111" => "US",
	"00011010" => "SUB",
	"00011011" => "ESC",
	"00011100" => "FS",
	"00011101" => "GS",
	"00011110" => "RS",
	"00011111" => "US",
	"00100000" => "Space",
	"00100001" => "!",
	"00100010" => "Double Quote",
	"00100011" => "#",
	"00111111" => "?",
	"00111110" => ">"
);



# take single PDIs and decide how to process them
sub convert699 {
	my $pdi = shift @_;

	#are we in text mode? 
	if ($textmode) {
		#not a PDI
		print LOGFILE "textmode: not a PDI: $pdi\n";
	} else {
		
		#if $pdi begins with '=' it's a status-type command
		if ($pdi =~ /^=/) {
			status_cmds($pdi);
		} else {
			pdi_cmds($pdi);
			
		}
	}
}

# logic for converting PDI status commands (begin with '=')
sub status_cmds {

	my $pdi = shift @_;
	my $init;

	if ($pdi =~ /^=@/){ #RESET: Clear screen, set to black
		$init = pack("B*","00100000"); #SPC - selective reset
		$init .= pack("B*","01111000"); #x - border & main to black
		$init .= pack("B*","01111111"); #DEL reset cursor, other stuff
		#print 'got =@';
 		$converted .= $init;
 		undef($init); 
	} elsif ($pdi =~ /^=A/){ #RESET: clear screen, set transparent
		
		print LOGFILE "got =A, clear screen, set transparent\n";
 
	} elsif ($pdi =~ /^=B/){ #RESET: clear to black, initialize
		 		
 		initialize_pdi();
		print LOGFILE "=B #RESET: clear to black, initialize\n";
 		                                           
	} elsif ($pdi =~ /^=C/){ #RESET: clear to current colour
 		$init = pack("B*","00100000"); #SPC - selective reset
		$init .= pack("B*","01101000"); #border & main to current colour
		$init .= pack("B*","01111111"); #reset cursor, other stuff		
 		$converted .= $init;
 		undef($init);
 		
 		print LOGFILE "=C #RESET: clear to current colour\n";
 		
	} elsif ($pdi =~ /^=D/){ #DOMAIN: coordinate data 9bits,3bytes
		print LOGFILE "GOT '=D' domain 9bits,3bytes (default)\n";
		
	} elsif ($pdi =~ /^=E/){ #DOMAIN: coordinate data 12bits,4bytes
		print LOGFILE "***GOT '=E' domain 12bits,4bytes***\n";
	} elsif ($pdi =~ /^=F/){ #DOMAIN: coordinate data 15bits,5bytes
		print LOGFILE "***GOT '=F' domain 15bits,5bytes***\n";	
	} elsif ($pdi =~ /^=G/){ #DOMAIN: coordinate data 18bits,6bytes
		print LOGFILE "***GOT '=G' domain 18bits,6bytes***\n";
	} elsif ($pdi =~ /^=H/){ #BLINK: blink off,trans off
		$init = pack("B*","00111111"); #?
		$init .= pack("B*","01000000"); #@
		$init .= pack("B*","01000000"); #@
		$init .= pack("B*","01000000"); #@
  		$converted .= $init;
 		undef($init);
		print LOGFILE "GOT =H #BLINK: blink off,trans off\n";
	} elsif ($pdi =~ /^=I/){ #BLINK: blink off, trans on
		print LOGFILE "GOT =I #BLINK: blink off, trans on\n";
		#$init = pack("B*","00111111"); #?
		#$init .= pack("B*","01111111"); #@
		#$init .= pack("B*","01001000"); #@
		#$init .= pack("B*","01001000"); #@
  		#$converted .= $init;
 		#undef($init);
	} elsif ($pdi =~ /^=J/){ #BLINK: blink on, trans off
		print LOGFILE "GOT =J/ #BLINK: blink on, trans off\n";
	} elsif ($pdi =~ /^=K/){ #BLINK: blink on, trans on 
		print LOGFILE "GOT =K #BLINK: blink on, trans on\n";
	} elsif ($pdi =~ /^=L/){ #TONAL CONTROL: colour mode
		$colourmode = 1;
		#needed because colour mode can change current colour without setting it again
		if (defined($current_colour)) {
			setcolour($current_colour);
		}
		print LOGFILE "colour mode\n"; 
	} elsif ($pdi =~ /^=M/){ #TONAL CONTROL: grey scale mode
 		$colourmode = 0;
 		#needed because grey scale mode can change current colour without setting it again
		if (defined($current_colour)) {
			setcolour($current_colour);
		}
		print LOGFILE "greyscale mode\n";
	} elsif ($pdi =~ /^=N/){ #TONAL CONTROL: colour mode (bit b2 reserved, so means the same as '=L')
		$colourmode = 1;
		if (defined($current_colour)) {
			setcolour($current_colour);
		}
		print LOGFILE "colour mode\n";
	} elsif ($pdi =~ /^=O/){ #TONAL CONTROL: grey scale mode (bit b2 reserved, so means the same as '=M')
		$colourmode = 0;
		if (defined($current_colour)) {
			setcolour($current_colour);
		}
		print LOGFILE "greyscale mode\n";
	} elsif ($pdi =~ /^=P/){ #LINE CONTROL: solid line
		$init = pack("B*","00100011"); # # (hash sign)
		$init .= pack("B*","01000000");	# @
  		$converted .= $init;
 		undef($init);
 		print LOGFILE "GOT =P #LINE CONTROL: solid line\n";
 		
	} elsif ($pdi =~ /^=Q/){ #LINE CONTROL: dotted line
		$init = pack("B*","00100011"); # # (hash sign)
		$init .= pack("B*","01000001");	# A
  		$converted .= $init;
 		undef($init); 
 		print LOGFILE "GOT =Q #LINE CONTROL: dotted line\n";
 		
	} elsif ($pdi =~ /^=R/){ #LINE CONTROL: dashed line
		$init = pack("B*","00100011"); # # (hash sign)
		$init .= pack("B*","01000010");	# B
  		$converted .= $init;
 		undef($init);  
 		
 		print LOGFILE "GOT =R #LINE CONTROL: dashed line\n";
	} elsif ($pdi =~ /^=S/){ #LINE CONTROL: dotted-dashed line
 		$init = pack("B*","00100011"); # # (hash sign)
		$init .= pack("B*","01000011");	# C
  		$converted .= $init;
 		undef($init); 
 		
 		print LOGFILE "GOT =S #LINE CONTROL: dotted-dashed line\n";
 		
	} elsif ($pdi =~ /^=T/){ #FILL: fill no highlight (outline)		
		$init = pack("B*","00100011"); # # [hash character]
		
		my $texture = 0;
		#get the fill pattern part of the PDI (everything after '=T'
		my $fill = substr($pdi,2); 
		if ($fill eq '') {
			print LOGFILE "Got empty fill\n";	
		} else {
		
			$texture = Texture::texture($fill);
		}
		
		#handle default textures differently
		if ($texture && ($texture =~ /^X|^H|^P/ || $texture eq '@') ) {
			$init .= $texture;

			print LOGFILE "GOT $texture in passthrough mode\n";
			
		} elsif ($texture) {
			
			my $maskLabel = 0;
			
			foreach my $mask (@textures) {
				
				#if the fill has already been registered, use that mask
				if ($textures{$mask} eq $fill) {
					$maskLabel = $mask;
					print LOGFILE "mask is still $mask; texture is still #" . $mask .  $texture . "\n";
					last;
					#if we get to a blank mask, then register that as the current mask	
				}	elsif (!$textures{$mask}) {
					$maskLabel = $mask;
					$textures{$mask} = $fill;
					$fully_converted .= '#' . $mask . $texture; #add this before the last abs point
					$lastSavedTexture = $mask;
					print LOGFILE "mask is now $mask; texture is #" . $mask . $texture. "\n";
					last;
				} 			
			}
			
			#if got to here without a mask label, means all slots are full
			#so replace the oldest mask which should be the one after the last saved texture
			if (!$maskLabel) {
				my $mask;	
				if ($lastSavedTexture eq '`') {
						$mask = '`';
					}# elsif ($lastSavedTexture eq 'h') {
					#	$mask = 'p';	
					#} elsif ($lastSavedTexture eq 'p') {
					#	$mask = 'x';	
					#} elsif ($lastSavedTexture eq 'x') {
					#	$mask = '`';	
					#}
					
					#other masks not working! Don't know why (2019-07-01)
				
					$maskLabel = $mask;
					$textures{$mask} = $fill;
					$fully_converted .= '#' . $mask . $texture; #add this before the last abs point
					$lastSavedTexture = $mask;	
					print LOGFILE "mask is now $mask; texture is $texture\n";
			}
			
			
			print "before: $fill\n";
			$init .= $maskLabel . $masksize;
			print "after: $maskLabel + " . $masksize ."\n";
			
		} else {
			$init = ''; #=T opcode with no operands is ignored	
		}

		print LOGFILE "GOT =T #fill no highlight (outline): $pdi\n";
 		print LOGFILE "Converted to: $init\n";
		
  		$converted .= $init;
 		undef($init);

 		
	} elsif ($pdi =~ /^=U/){ #FILL: flll colour highlight
		
		$init = pack("B*","00100011"); # # [hash character]
		
		my $texture = 0;
		#get the fill pattern part of the PDI (everything after '=T'
		my $fill = substr($pdi,2); 
		if ($fill eq '') {
			print LOGFILE "Got empty fill\n";	
		} else {
		
			$texture = Texture::texture($fill);
		}
		
		#handle default textures differently
		if ($texture && ($texture =~ /^X|^H|^P/ || $texture eq '@') ) {
			$init .= $texture;

			print LOGFILE "GOT $texture in passthrough mode\n";
			
		} elsif ($texture) {
			
			my $maskLabel = 0;
			
			foreach my $mask (@textures) {
				
				#if the fill has already been registered, use that mask
				if ($textures{$mask} eq $fill) {
					$maskLabel = $mask;
					print LOGFILE "mask is still $mask; texture is still #" . $mask .  $texture . "\n";
					last;
					#if we get to a blank mask, then register that as the current mask	
				}	elsif (!$textures{$mask}) {
					$maskLabel = $mask;
					$textures{$mask} = $fill;
					$fully_converted .= '#' . $mask . $texture; #add this before the last abs point
					$lastSavedTexture = $mask;
					print LOGFILE "mask is now $mask; texture is #" . $mask . $texture. "\n";
					last;
				} 			
			}
			
			#if got to here without a mask label, means all slots are full
			#so replace the oldest mask which should be the one after the last saved texture
			if (!$maskLabel) {
				my $mask;	
				if ($lastSavedTexture eq '`') {
						$mask = '`';
					}# elsif ($lastSavedTexture eq 'h') {
					#	$mask = 'p';	
					#} elsif ($lastSavedTexture eq 'p') {
					#	$mask = 'x';	
					#} elsif ($lastSavedTexture eq 'x') {
					#	$mask = '`';	
					#}
					
					#other masks not working! Don't know why (2019-07-01)
				
					$maskLabel = $mask;
					$textures{$mask} = $fill;
					$fully_converted .= '#' . $mask . $texture; #add this before the last abs point
					$lastSavedTexture = $mask;	
					print LOGFILE "mask is now $mask; texture is $texture\n";
			}
			
			
			print "before: $fill\n";
			$init .= $maskLabel . $masksize;
			print "after: $maskLabel + " . $masksize ."\n";
			
		} else {
			$init = ''; #=U opcode with no operands is ignored	
		}

		print LOGFILE "GOT =U #fill no highlight (outline): $pdi\n";
 		print LOGFILE "Converted to: $init\n";
		
  		$converted .= $init;
 		undef($init);

	} elsif ($pdi =~ /^=V/){ #FILL: fill black highlight
		print LOGFILE "GOT =V #fill black highlight\n";
 
	} elsif ($pdi =~ /^=W/){ #FILL: fill (reserved)
		print LOGFILE "GOT =W #fill (reserved)\n";
	} elsif ($pdi =~ /^=X/){ #MARKER: marker off, reposition
		print LOGFILE "GOT =X #marker off, reposition\n"
	} elsif ($pdi =~ /^=Y/){ #MARKER: marker on, reposition
		print LOGFILE "GOT =Y #marker on, reposition\n";
	} elsif ($pdi =~ /^=Z/){ #MARKER: marker (specified) off, repos
		print LOGFILE "GOT =Z #marker (specified) off, repos\n";
	} elsif ($pdi =~ /^=\[/){ #MARKER: marker (specified) off, repos
		print LOGFILE "GOT =[ #marker (specified) off, repos\n";
 
	} elsif ($pdi =~ /^=\\/){ #wait timed
		#delay is specified in one or two bytes 
		#least significant to most significant
		#tenths of a second
		
		print LOGFILE "GOT =\ #wait timed\n";
 
	} elsif ($pdi =~ /^=\]/){ #wait indefinite
		print LOGFILE "GOT =] #wait indefinite\n";
 
	} elsif ($pdi =~ /^=\^/){ #wait timed flow control
 		#delay is specified in one or two bytes 
		#least significant to most significant
		#tenths of a second
		
		print LOGFILE "GOT =^/ #wait timed flow control\n";
		
	} elsif ($pdi =~ /^=_/){ #wait indefinite flow control
		
		print LOGFILE "GOT =_ #wait indefinite flow control\n";
		
 
	} elsif ($pdi =~ /^=`/){ #text format
		print LOGFILE "GOT =` #text format: $pdi\n";
		my $textformat = Textconv::textformat($pdi);
		$current_textformat = $textformat;
		$init = '"' . $textformat . $current_textsize;
		print LOGFILE "converted to $init\n";
		$converted .= $init;
		undef($init);
		
 
	} elsif ($pdi =~ /^=a/){ #text size 
		print LOGFILE "GOT =a #text size: $pdi\n";
		my $textsize = Textconv::textsize($pdi);
		$current_textsize = $textsize;
		$init = '"' . $current_textformat . $textsize;
		print LOGFILE "Converted to $init\n";
		$converted .= $init;
		undef($init);
 
	} elsif ($pdi =~ /^=b/){ #character set
		print LOGFILE "GOT =b #character set\n";
 
	} elsif ($pdi =~ /^=c/){ #tab positions
		print LOGFILE "GOT =c #tab positions";
 
	} elsif ($pdi =~ /^=d/){ #char def (reserved)
		print LOGFILE "got reserved PDI! $pdi\n"; 
	} elsif ($pdi =~ /^=e/){ #char def (reserved)
 		print LOGFILE "got reserved PDI! $pdi\n"; 
	} elsif ($pdi =~ /^=f/){ #char def (reserved)
 		print LOGFILE "got reserved PDI! $pdi\n"; 
	} elsif ($pdi =~ /^=g/){ #char def (reserved)
 		print LOGFILE "got reserved PDI! $pdi\n"; 
	} else {
		print LOGFILE "got unrecognized PDI status code! $pdi\n";
	}

}

#newlines require PDIs to set the left margin
sub convert_newline {

	my $newline = pack("B*","00001110"); #shift out
	$newline .= pack("B*","00100101"); #point, relative invisible
	$newline .= get_current_x();
	$newline .= pack("B*","00001111"); #shift in
	print LOGFILE "Newline: $newline\n";
	return $newline;
}

#get the x coord from the current position
#for text positioning on newlines
sub get_current_x {
	
	my $pdi = $current_position;
	my $coords = substr($pdi,1);
	print LOGFILE "got coords: $coords\n";
	my @bytes = split(//,$coords);
	
	my $x = '';
	foreach (@bytes) {
		print LOGFILE "got byte: " . unpack("B*",$_) . "\n";
		my $coord = unpack("B*",$_);
		my $xpart = substr($coord,2,3); #get the x coord from the byte
		#print "xpart: $xpart\n";
		my $xbin = '01' . $xpart . '000';
		$x .= pack("B*",$xbin);		
	}
	
	return $x;	
}

sub pdi_cmds {
	
	my $pdi = shift @_;
	
	#opcode is first byte of pdi
	my $opcode = substr($pdi, 0, 1);
	#print "-- $opcode --\n";
	
	my $binary = unpack("B*",$opcode); #ascii char to binary string
	
	if ($binary eq "00000111"){  #	BEL	bell	ring a bell
		$converted .= $pdi;
	} elsif ($binary eq "00001000"){  #	BS	backspace	reset back one char width
		$converted .= $pdi;
	} elsif ($binary eq "00001001"){  #	HT	horizontal tab	reset forward one tab (default one space)
		$converted .= $pdi;
	} elsif ($binary eq "00001010"){  #	LF	line feed	reset to current x, down one line
		$converted .= $pdi;
	} elsif ($binary eq "00001011"){  #	VT	vertical tab	raise Y coord one tab (default 1 char height)
		$converted .= $pdi;
	} elsif ($binary eq "00001100"){  #	FF	form feed	clear screen, reset to left margin & y to one char down
		$converted .= $pdi; #not sure about this one
	} elsif ($binary eq "00001101"){  #	CR	enter / carriage return	reset to margin x, current y
		$converted .= $pdi;
	} elsif ($binary eq "00001110"){  #	SO	shift out	exit text mode 
		$converted .= $pdi;
		if ($displacement_flag) {
			$converted .= Textconv::get_displacement_pos();
			$displacement_flag = 0;
		}
	} elsif ($binary eq "00001111"){  #	SI	shift in	enter text mode
		$converted .= $pdi;
	} elsif ($binary eq "00011001"){  #	EM	end of medium	invoke g2 chars (accents)
		$converted .= $pdi;
	} elsif ($binary eq "00100100"){  #	$	dollar	point, absolute invisible
		$current_position = $pdi; 
		$fully_converted .= $converted;
		$converted = $pdi;
	} elsif ($binary eq "00100101"){  #	%	percent	point, relative invisible
		$converted .= $pdi;
	} elsif ($binary eq "00100110"){  #	&	ampersand	point, absolute visible
		$converted .= $pdi;
	} elsif ($binary eq "00100111"){  #	'	single quote	point, relative visible
		$converted .= $pdi;
	} elsif ($binary eq "00101000"){  #	(	left parenthesis	line, absolute
		$converted .= $pdi;
	} elsif ($binary eq "00101001"){  #	)	right parenthesis	line, relative
		$converted .= $pdi;
	} elsif ($binary eq "00101010"){  #	*	asterisk	Set & line (absolute)
		$converted .= $pdi;
	} elsif ($binary eq "00101011"){  #	+	plus	Set & line (relative)
		$converted .= $pdi;
	} elsif ($binary eq "00101100"){  #	,	comma	arc, outline
		$converted .= $pdi;
	} elsif ($binary eq "00101101"){  #	-	minus	arc, filled
		$converted .= $pdi;
	} elsif ($binary eq "00101110"){  #	0	period	Set & arc (outline)
		$converted .= $pdi;
	} elsif ($binary eq "00101111"){  #	/	slash	Set & arc (filled)
		$converted .= $pdi;
	} elsif ($binary eq "00110000"){  #	0	zero	rectangle, outlined
		$converted .= $pdi;
	} elsif ($binary eq "00110001"){  #	1	one	rectangle, filled
		$converted .= $pdi;
	} elsif ($binary eq "00110010"){  #	2	two	Set & rectangle (outlined)
		$converted .= $pdi;
	} elsif ($binary eq "00110011"){  #	3	three	Set & rectangle (filled)
		$converted .= $pdi;
	} elsif ($binary eq "00110100"){  #	4	four	polygon (outlined)
		$converted .= $pdi;
	} elsif ($binary eq "00110101"){  #	5	five	polygon (filled)
		$converted .= $pdi;
	} elsif ($binary eq "00110110"){  #	6	six	Set & polygon (outlined)
		$converted .= $pdi;
	} elsif ($binary eq "00110111"){  #	7	seven	Set & polygon (filled)
		$converted .= $pdi;
	} elsif ($binary eq "00111000"){  #	8	eight	bit format 0
		print "GOT 8	eight	bit format 0\n";
	} elsif ($binary eq "00111001"){  #	9	nine	bit format 1
		print "GOT 9	nine	bit format 1\n";
	} elsif ($binary eq "00111010"){  #	:	colon	Set & bit format 0
		print "GOT :	colon	Set & bit format 0\n";
	} elsif ($binary eq "00111011"){  #	;	semicolon	Set & bit format 1
		print "GOT ;	semicolon	Set & bit format 1\n";
	} elsif ($binary eq "00111100"){  #	<	less than	PDI Control – Value

		#sets the color (or greyscale)
		#note this method assumes only the first three colour bits of the first operand are significant
		#standard says 3-bit colour was a "typical system" (p42). 
		#Were there non-typical systems that supported more?
		
		setcolour($pdi);
		$current_colour = $pdi; #remember for later	
		
	}else {
		print LOGFILE "Got unrecognized opcode in PDI! $pdi\n";	
	}
		
	
}


sub setcolour {
	
	my $pdi = shift(@_);
	
	if (length($pdi) > 1) {
		my $oper699 = substr($pdi,1,1); #get the first operand
		my $binop699 = unpack("B*",$oper699); #ascii char to binary string
		
		if ($colourmode) {	#colour mode
			my $colour699 = substr($binop699,2,3);
			my $colour709 = '01' . $colour699 . $colour699;
			my $oper709 = pack("B*",$colour709) . pack("B*",$colour709) . pack("B*",$colour709);
			$converted .= '<' . $oper709;
		} else { #grey scale mode
			my $onebit = substr($binop699,2,1);
			my $twobit = substr($binop699,3,1);
			my $threebit = substr($binop699,4,1);
			my $firstbyte = pack("B*",("01" . $onebit . $onebit . $onebit . $twobit . $twobit . $twobit));
			my $secondbyte = pack("B*",("01" . $threebit . $threebit . $threebit. $onebit . $onebit . $onebit));
			my $thirdbyte = pack("B*",("01" . $twobit . $twobit . $twobit . $threebit . $threebit . $threebit));
			$converted .= '<' . $firstbyte . $secondbyte . $thirdbyte;
			print  LOGFILE "grey scale: $firstbyte $secondbyte $thirdbyte\n";
		}	
			
	}	
	
}

#initialize the file
sub initialize_pdi {

	my $init = pack("B*","00001110"); #^N
	$init .= pack("B*","00011000"); #18 end all macro processing
	$init .= pack("B*","00011111"); #1f non-selective reset
	$init .= pack("B*","01000000"); #40
	$init .= pack("B*","01000000"); #40 reposition cursor to upper left (NSR operands)
	$init .= pack("B*","00001110"); #^N
	$init .= pack("B*","00111101"); # = wait
	$init .= pack("B*","01000000"); # @ zero
	$init .= pack("B*","00100000"); # space reset selective
	$init .= pack("B*","01111011"); # {
	$init .= pack("B*","01001111"); # O
	$init .= pack("B*","00100001"); # ! domain
	$init .= pack("B*","01001000"); # H 1 single op, 3 multi op, 2d,
	$init .= pack("B*","01000000"); # @ - size of logical pel
	$init .= pack("B*","01000000"); # @ - size of logical pel
	$init .= pack("B*","01001001"); # I - size of logical pel (smallest possible in this case)
	$init .= pack("B*","00001111"); # ^O enter text mode
	$init .= pack("B*","00001110"); #^N
	$init .= pack("B*","00100011"); # # - set texture
	$init .= pack("B*","01000000"); # @
	$init .= pack("B*","01000000"); # @
	$init .= pack("B*","01000000"); # @
	
	$converted .= $init;
	undef($init);

}



#read one byte at a time
$/ = \1; 

my $file;
my $filecount = 0;
foreach $file (@files) {

%textures = (
	'`' => 0,
	'h' => 0,
	'p' => 0,
	'x' => 0,
);
	
my $lastSavedTexture = '';
	
	
	$filecount++;
	
	#skip com.text files
	if ($file =~ /text$/) {
		print LOGFILE "skipping $file\n";
		next;	
	}
	print $file . "\n";
	#the whole file
	$fully_converted = '';
	
	# string to hold the converted file up to the most recent abs point
	$converted = '';
	
	if ($filecount == 1) {
		initialize_pdi();	
	}
	
	# status flags
	$textmode = 0; #0 = PDI, 1 = text;
	$colourmode = 1; #0 = grey scale, 1 = colour
	
	# number of byte we're currently processing
	$bytecount = 0;
	
	# current drawing point as pdi
	$current_position = 0;
	
	my $pdi;	
	
	
	my $out = $outdir . '/' . $file;
	
	print LOGFILE "-------------$file-------------\n\n";
	
	open(INFILE, $file) || die "can't open $file: $!";
	open(OUTFILE, ">$out") || die "can't open $out: $!";
	
	
	while (<INFILE>) {
	
		$bytecount++;
			
		my $binary = unpack("B*",$_); #ascii char to binary string
	
		#set text mode on or off
		if ($binary eq "00001111") { #set textmode on
			if (!$textmode) { #but only if textmode is not on already
			#clear previous opcode
			if (defined $pdi){
				convert699($pdi);
				undef ($pdi);
			}
			
			$textmode = 1;
			$converted .= Textconv::get_displacement_neg();
			print LOGFILE "textmode is on\n";
			$displacement_flag = 1;
			} else {
				print LOGFILE "got textmode on but textmode already on\n";	
			}
	
		} elsif ($binary eq "00001110") { #set textmode off
			if ($textmode) { #but only if textmode not already off
				$textmode = 0;
				print LOGFILE "textmode is off\n";
			} else {
				print LOGFILE "got textmode off but textmode already off\n";	
			}
	
		}
		
		
		if ($textmode) {
			print LOGFILE "textmode: $_\n";
			
			#newlines require special handling
			#set the left margin before the carriage return
			if ($binary eq "00001101") { 
				my $newline = convert_newline();
				$converted .= $_ . $newline;
			} else {
				$converted .= $_;
			}
			next;
		}
	
		#opcodes always have 0 in the 7th bit
		if ($binary =~ /00\d\d\d\d\d\d/) { 
			#it's an opcode
			if (defined $pdi) {
				#do a bunch of stuff with the current instruction
				convert699($pdi);
				
			}
			
			undef($pdi);
	
			#only set a new value if the incoming opcode is one we recognize
			if (!exists($do_nothing{$binary})){
				$pdi = $_; #set pdi to new opcode
			} else {
				unless ($do_nothing{$binary} eq 'NUL') {
					print LOGFILE "got bad opcode! $do_nothing{$binary}\n";
				}
			}
	
	
		} else {
			#it's an operand
	
			if (defined $pdi) {
				$pdi .= $_;
			} else {
				print LOGFILE "got operand $_ but opcode not defined!\n";
			}
	
		}
		
		#print OUTFILE " " . pack("B*", $binary); #binary string back to ascii char
		#print OUTFILE "\n";
	}
	
	#process last pdi, if any
	if (defined $pdi) {
		convert699($pdi);
	}
	
	#tack on what's left in $converted
	$fully_converted .= $converted;
	print OUTFILE $fully_converted;
	#tack on a null char (sometimes needed so last opcode will run)
	my $null = pack("B*","00011010");
	print OUTFILE $null;

}
print "\nAll done\n";

