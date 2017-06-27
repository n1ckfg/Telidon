'Copyright 1993 by Memra Software Inc.
'                  All Rights Reserved
'
'-----------------------------------------------------------------------
DIM abyte AS STRING * 1
DIM addr AS INTEGER

infile$ = ENVIRON$("IN")
outfile$ = ENVIRON$("OUT")
IF infile$ = "" OR outfile$ = "" THEN
        PRINT "Enter NAPLPS input file:";
        INPUT infile$
        PRINT "Enter name for Debug Script:";
        INPUT outfile$
END IF
OPEN infile$ FOR BINARY AS #1
OPEN outfile$ FOR OUTPUT AS #2
addr = 256
outstr$ = "E " + HEX$(addr) + " "
nbytes = 1
WHILE NOT EOF(1)
        GET #1, , abyte
        outstr$ = outstr$ + HEX$(ASC(abyte)) + " "
        IF (nbytes MOD 8) = 0 THEN
                PRINT #2, outstr$
                addr = addr + 8
                outstr$ = "E " + HEX$(addr) + " "
        END IF
        nbytes = nbytes + 1
WEND
IF LEN(outstr$) > 7 THEN
        PRINT #2, outstr$
END IF
PRINT #2, "N "; infile$
PRINT #2, "RCX"
PRINT #2, HEX$(nbytes)
PRINT #2, "W"
PRINT #2, "Q"
CLOSE #1
CLOSE #2
SYSTEM

