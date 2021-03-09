	PROGRAM DRAWLINE

C	Include PHIGS enumeration file
	INCLUDE 'phigs/phigsf77.h'

C	Delcare arrays
	REAL COLR(1:3)
	REAL PXA(1:2)
	REAL PYA(1:2)

C	Open PHIGS and a workstation
	CALL POPPH(0, 0)
	CALL POPWK(0, 0, 0)

C	Define line colour in workstation table
	COLR(1) = 1.0
	COLR(2) = 1.0
	COLR(3) = 0.0
	CALL PSCR(0, 1, 3, COLR)

C	Open structure
	CALL POPST(0)

C	Set text attributes
	CALL PSCHH(0.055)

C	Draw text
	CALL PTX(0.22, 0.48, 'Hello Fortran!')

C	Set line attributes
	CALL PSPLCI(1)
	CALL PSLN(PLDASD)
	CALL PSLWSC(2.0)

C	Draw line from bottom-left to top-right
	PXA(1) = 0.0
	PYA(1) = 0.0
	PXA(2) = 1.0
	PYA(2) = 1.0
	CALL PPL(2, PXA, PYA)

C	Draw line from bottom-right to top-left
	PXA(1) = 1.0
	PYA(1) = 0.0
	PXA(2) = 0.0
	PYA(2) = 1.0
	CALL PPL(2, PXA, PYA)

C	Close structure
	CALL PCLST

C	Post structure to workstation
	CALL PPOST(0, 0, 0.0)

C	Buisy loop
	DO WHILE (1 .GT. 0)
	END DO

	STOP
	END
