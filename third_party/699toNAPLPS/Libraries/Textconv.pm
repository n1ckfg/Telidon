#!/usr/bin/perl
package Textconv;
use strict;
use Exporter;

our @ISA= qw( Exporter );

# these CAN be exported.
our @EXPORT_OK = qw( textsize, get_displacement_pos, get_displacement_neg );

# these are exported by default.
our @EXPORT = qw( textsize, get_displacement_pos, get_displacement_neg );


#convert 699 text to NAPLPS equiv

#699 only has 7 character sizes, from biggest(0) to smallest(7)
#expressed as fractions of the screen

#my $pdi = textsize('=ac');
#print $pdi . "\n";

#x values indicate number of chars per line
#slightly more than spec, so chars are slightly smaller,
#don't go right to edge

#saved values
#our @xvalues = (24,34,52,60,90,120,160,260);
#our @disp = (0,-1.4,-2.1,-2,0,0,0,0);
#our @disp_double = (1.5,1.4,0.6,0.1,0,0,0,0);

our @xvalues = (26,36,54,72,96,128,180,260);
our @disp = (1.5,1.2,1,0.8,0,0,0,0);
our @disp_double = (1.5,1.4,1.2,1.2,0,0,0,0);

our $displacement = 1/8;

#our $disp_height = 1.4;



#converts 699 size pdi (=a)
sub textsize {
	my $pdi_699 = shift (@_);
	
	$pdi_699 = substr($pdi_699, 2,1);
	$pdi_699 = unpack("B*", $pdi_699);
	my $double_height = substr($pdi_699, 2,1);
	$main::current_textsize_double = $double_height;
	my $size = substr($pdi_699, 5,3);
	$size = bin2dec($size);
	$main::current_textsize_numeric = $size;
	#remember the index value of the current text size
	
	#print $size . "\n";

	
	#value 0 is	28 @/`
	#value 1 is 36 A/a
	#value 2 is 54 B/b
	#value 3 is 72 C/c
	
	
	
	my $x = sprintf("%.7f",1/$xvalues[$size]);
	my $y = sprintf("%.7f",(1 + 3/8) * $x); #char height a proportion of width
	
	if ($double_height) {
		$y = $y * 2;	
	}
	
	
	$main::current_textsize_y_dec = $y;
	my $pdi_NAPLPS = dec2pdi($x,$y);
	return $pdi_NAPLPS;

}

#converts 699 format pdi (=`)
sub textformat { 
	my $pdi_699 = shift (@_);	
	$pdi_699 = substr($pdi_699, 2,1);
	$pdi_699 = unpack("B*", $pdi_699);
	
	my $free_format = substr($pdi_699,2,1); #0=terminal,1=diagram
	my $break = substr($pdi_699,3,1); #0=char,1=word
	my $rotation = substr($pdi_699,4,2); #00=normal, 01=down etc
	my $vertical = substr($pdi_699,6,2); #1,1.5,2,2.5 
	
	#sadly, naplps replaces 2.5 with 1.25, so values not the same
	my %internarrow = (
		'00' => '00',
		'01' => '10',
		'10' => '11',
		'11' => '11'	
		);
	
	#naplps 
	my $byte1 = '011100' . $rotation;
	my $byte2 = '010000' . $internarrow{$vertical};
	
	my $encoded_pdi = pack("B*",$byte1);
	$encoded_pdi .= pack("B*", $byte2);
	
	return $encoded_pdi;
	
}



#figure out how much to shift line down
sub get_displacement_neg {
	
	my $current_y = $main::current_textsize_y_dec;
	#print "Current Y: $current_y\n";
	my $disp_height;
	if ($main::current_textsize_double) {
		$disp_height = $disp_double[$main::current_textsize_numeric];
	} else {
		$disp_height = $disp[$main::current_textsize_numeric];
	}
	
	my $displace_y = $current_y * ($displacement * $disp_height);
	
	#positive displacement if disp_height is negative
	if ($disp_height > 0 ) {
		$displace_y = 1.002 - $displace_y; #not sure why it needs to be slightly more than one
	} else {
		$displace_y = $displace_y * -1;	
	}
	
	#print "Displace Y: $displace_y\n";
	
	my $encoded = dec2pdi(0, $displace_y);
		
	my $neg_encoded = '%' . $encoded;
	
	return ($neg_encoded);
	
}

sub get_displacement_pos {
	
	my $current_y = $main::current_textsize_y_dec;
	
	my $disp_height;
	if ($main::current_textsize_double) {
		$disp_height = $disp_double[$main::current_textsize_numeric];
	} else {
		$disp_height = $disp[$main::current_textsize_numeric];
	}
	
	my $displace_y = $current_y * ($displacement * $disp_height);

	#negative displacement if disp_height is negative
	if ($disp_height < 0 ) {
		$displace_y = $displace_y * -1;
		$displace_y = 1.002 - $displace_y;
	} 
	
	
	my $encoded = dec2pdi(0, $displace_y);
	
	$encoded = '%' . $encoded;
	
	return($encoded);
}


sub dec2pdi {
	my($x,$y) = (@_);
	
	my $binx = dec2bin($x);
	my $biny = dec2bin($y);
	
	#print "Bin Y:  $biny\n";
	
	my @array_x = ();
	push @array_x, $1 while ($binx =~ /(.{1,3})/msxog);

	my @array_y = ();
	push @array_y, $1 while ($biny =~ /(.{1,3})/msxog);
	
	my $i;
	my $pdi;
	
	
	my $encoded_pdis;
	for ($i=0;$i<3;$i++) {
		$pdi = '01' . $array_x[$i] . $array_y[$i];
		#print $pdi . "\n";
		$encoded_pdis .= pack("B*",$pdi);
	}
	return $encoded_pdis;
	
	
}


sub dec2bin {
	
	my $dec = shift (@_);
	my $bin;
	my $i;
	for ($i=0;$i<9;$i++) {
		my $temp = $dec * 2;
		#print "Temp: $temp\n";
		($temp, $dec) = split(/\./,$temp);
		#print "$temp, $dec\n";
		$bin .= "$temp";
		$dec = '0.' . $dec;
	}
	
	return $bin;
}



sub bin2dec {
    return unpack("N", pack("B32", substr("0" x 32 . shift, -32)));
}


1;



