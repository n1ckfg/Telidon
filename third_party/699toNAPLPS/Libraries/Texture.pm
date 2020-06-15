#!/usr/bin/perl
# convert a texture pattern from 699 to 709/NAPLPS equivalent
package Texture;
use strict;
use POSIX;
use Exporter;

our @ISA= qw( Exporter );

# these CAN be exported.
our @EXPORT_OK = qw( texture bin2dec );

# these are exported by default.
our @EXPORT = qw( texture );

our $dimension=16;
our $pcharX = 1;
our $ncharX = 0;
our $pcharY = 1;
our $ncharY = 0;

#my $texture = texture('@R@');
#print "\n----------\n";
#print $texture . "\n";


sub texture {

	my $operands = shift @_; #expects ASCII chars, 699 pdi operands
	
	if ($operands eq '') {
		return 0;	
	}
	
	my $x = '';
	my $y = '';
	
	my @operands = split(//, $operands); #split into individual chars
	
	foreach my $operand (@operands) {
		my $xy = unpack("B*", $operand); #convert to binary string
		$x .= substr($xy, 2,3);
		$y .= substr($xy, 5,3);
	}
	
	#print "x: $x\n";
	#print "y: $y\n";
	
	if (substr($x,1,4) eq "1111") {
		return '@';	
	}
	
	if (substr($y,1,4) eq "1111") {
		return '@';	
	}
		
	my $xAngle = substr($x,0,1); #1 = slope at 45
	my $yAngle = substr($y,0,1); #1 = slope at 135
	
	my $xDec = bin2dec(substr($x,1,4)); #max 4 bits precision (1/16)
	#print "Xdec: $xDec\n";
	
	my $xFill;
	if ($xDec != 0) {
		
		if ($xDec > 0.5) {
			$pcharX = 0;
			$ncharX = 1;
			$xDec = 1-$xDec; 
		}
		
		$xFill = int(1/$xDec); #turn fraction into integer, eg 0.5 = 2, every other space
	} else {
		$xFill = 0;
	}
	

	#binary representation of y value, fraction from 0 to .999999
	my $yDec = bin2dec(substr($y,1,4)); #max 4 bits precision (1/16)
	#print "Ydec: $yDec\n";
	
	my $yFill; #fill density
	if ($yDec !=0) {
		if ($yDec > 0.5) {
			$pcharY = 0;
			$ncharY = 1;
			$yDec = 1-$yDec; 
		}
		$yFill = int(1/$yDec); #turn fraction into integer, eg 0.5 = 2, every other space
	} else {
		$yFill = 0;
	}

	my $def_texture;

	
	my $grid = '';
	#what kind of grid?
	if (!$xAngle && !$yAngle) {
		#if both x and y = 0 or 1, no fill ... 
		#on a 16x16 grid, textures are:
		#@R@ - grid
		#@B@ - horizontal hatch
		#@P@ - vertical hatch
		if (($xFill < 2) && ($yFill < 2)) { 		#no texture, solid fill
			return '@';
			#$def_texture = def_texture_begin('@B@');
			#$main::masksize = '@B@';
		} elsif (($xFill < 2) && ($yFill >= 2)) { 	#horizontal fill
			$def_texture = def_texture_begin('@B@');
			$main::masksize = '@B@';
		} elsif (($xFill >= 2) && ($yFill < 2)) { 	#vertical fill
			$def_texture = def_texture_begin('@P@');
			$main::masksize = '@P@';
		} else {									#grid fill
			$def_texture = def_texture_begin('@R@');
			$main::masksize = '@R@';
		}
		$grid = gridrect($xFill, $yFill);
		
	} elsif ($xAngle && !$yAngle) {
		#print "xAngle: $xFill, $xDec\n";
		$def_texture = def_texture_begin('@R@');
		$main::masksize = '@R@';
		$grid = gridangleY($xFill);
	} elsif (!$xAngle && $yAngle) {
		#print "yAngle: $yFill, $yDec\n";
		$def_texture = def_texture_begin('@R@');
		$main::masksize = '@R@';
		$grid = gridangleX($yFill);
	} else {
		print "GOT GRID ANGLE X AND Y!!:$xFill,$yFill\n";
		
		if (($xFill == 2) && ($yFill == 2)) {
			$def_texture = def_texture_begin('@R@');
			$main::masksize = '@R@';
			$grid = gridangleY($xFill);
		}
	}
	
	my @grid = ($grid =~ m/.{$dimension}/g); #split into dimensional lengths
	my $encoded = '';

	# To pack as an encoding, 6 bits per byte
	# On a 16x16 grid, 3 bytes (6+6+4) per line;
	#number of bytes needed to represent each line, 
	my $num_bytes = ceil($dimension/6); 	
	
	foreach my $coord (@grid) {
		
		#print $coord . "\n";
		
		#add zeros to make the length a multiple of six
		my $zeros = ($num_bytes * 6) - $dimension;
		
		my $i;
		for ($i=0;$i<$zeros;$i++) {
			$coord = $coord . '0';	
		}
	
		#print $coord . "\n";
		
		for ($i=0;$i<$num_bytes;$i++) {
		
			my $encoded = '01' . substr($coord, $i * 6, 6);
			#print "encoded: $encoded " . pack("B*", $encoded) . "\n";
			$def_texture .= pack("B*", $encoded);
		}
		
	}
	
	$def_texture .= def_texture_end();
	
	return ($def_texture);
	
}


sub gridrect {
	
	my($xFill, $yFill) = (@_);

	my $grid='';
	my ($i, $j);
	
	for ($i=$dimension;$i>0;$i--){ #number of rows
	
		for ($j=$dimension;$j>0;$j--){  #8 bits
													
			if (($yFill > 0) && ($i % $yFill == 0)) {
  
				$grid .= '1';
				
			} elsif (($xFill > 0) && ($j % $xFill == 0)) {
				
				$grid .= 1;
				
			} else {
				
				$grid .= 0;
					
			}
	
		} 
				
	}	
	
	return $grid;
}

#print lines angled +135
sub gridangleY {
	my $yFill = shift(@_);

	my $grid='';
	my $numZeros = $yFill - 1;
	my ($i, $j, $k);
	
	for ($i=$dimension;$i>0;$i--){ #number of rows
		
		if ($numZeros < 0) {
			$numZeros = $yFill-1;
		} 
		
		for ($k=0;$k<$numZeros;$k++) {
			$grid .= 0;	
		}

		for ($j=$dimension;$j>($numZeros);$j--){  #number of columns 
													
			if (($yFill > 0) && ($j % $yFill == 0)) {				
				$grid .= 1;				
			} else {			
				$grid .= 0;				
			}	
		} 
		
		$numZeros--;
	}	
	return $grid;		
}


#print lines angled -45
sub gridangleX {
	my $xFill = shift(@_);

	my $grid='';
	my $rownum = 0;
	my $numZeros = 0;
	my ($i, $j, $k);
	
	for ($i=$dimension;$i>0;$i--){ #number of rows
		
		if ($rownum == $xFill) {
			$rownum = 0;
			#print "bingo!\n";
			
		} else {
			#print "$xFill, $rownum\n";
			$numZeros = $rownum;
			#print "$numZeros\n";
			for ($k=0;$k<$numZeros;$k++) {
				$grid .= 0;	
			}
		}
		
		
		for ($j=$dimension;$j>($rownum);$j--){  #number of columns 
			
			if (($xFill > 0) && ($j % $xFill == 0)) {			
				$grid .= 1;			
			} else {			
				$grid .= 0;				
			}
		} 	
		$rownum++;
	}	
	return $grid;	
	
}

sub def_texture_begin {
	
	my $pelsize = shift(@_);
	

	# #	23	00100011 opcode texture (dotted, crosshatch) #
	# `	60	01100000 `
	# @	40	01000000 @
	# R	52	01010010 R
	# @	40	01000000 @
	# !	21	00100001 opcode domain command !
	# I	49	01001001 I
	# @	40	01000000 @
	# d	64	01100100 d
	# @	40	01000000 @
	# 	1b	00011011 opcode code extension – c1 in 7 bit 
	# D	44	01000100 D
	# A	41	01000001 A
	# 9	39	00111001 opcode incremental point 9
	# A ... not sure what this is here for, but you need it

	#my $begin = '#`@R@!I' . $pelsize; 
    my $begin = '@R@!I' . $pelsize;
	$begin .= pack("B*",'00011011');
	$begin .= 'DA8$9A';
	
	return($begin);

}

sub def_texture_end {
	# 	1b	00011011 opcode code extension – c1 in 7 bit 
	# E	45	01000101 E
	# 	0e	00001110 opcode exit text mode -enter g1 set (PDI) 
	# !	21	00100001 opcode domain command !
	# H	49	01001000 H
	# @	40	01000000 @
	# @	40	01000000 @
	# I	49	01001001 I	
	
	my $end = pack("B*",'00011011');
	$end .= 'E';
	$end .= pack("B*",'00001110');
	$end .= '!H@@I#@';
	
	return ($end);
	
}

	
#convert binary fractions to decimal equivalents
sub bin2dec {
    
	my $bin = shift(@_);
	
	my @digits = split(//,$bin);
	
	my $divideby = 2;
	my $result = 0;
	foreach my $digit (@digits) {
		$result += $digit/$divideby;
		$divideby = $divideby * 2;
	}
	
	return $result;
	
}

1;