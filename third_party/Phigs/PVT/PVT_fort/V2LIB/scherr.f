      SUBROUTINE SCHERR (ERRNUM, ERRMSG)

C  SCHERR accepts a valid error code and returns the standard
C  corresponding error message.
C
C  Input parameter:
C    ERRNUM: Standard error code
C  Output parameter:
C    ERRMSG: Wording of corresponding standard error message

      INTEGER    LISIZE
      PARAMETER (LISIZE = 111)
      INTEGER    ERRNUM, STDNUM(LISIZE), MSGDX, IARFND

      CHARACTER  ERRMSG*(*), STDMSG*180

C  List of standard error codes
      DATA STDNUM /
     1     1,2,3,4,5,6,7,
     2     50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,
     3     100,101,102,103,104,105,106,107,108,109,
     4     110,111,112,113,114,115,116,117,118,
     5     150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,
     6     200,201,202,203,204,205,206,207,208,
     7     250,251,252,253,254,255,256,257,258,259,260,261,262,263,
     8     300,301,302,303,304,305,306,307,350,351,
     9     400,401,402,403,404,405,406,407,408,450,
     A     2000,2001,2002,2003,2004,2005,2006,
     B     2200,2201,2202,2203,2204  /

      MSGDX = IARFND(ERRNUM, LISIZE, STDNUM)
      IF (MSGDX.LT.1) CALL UNMSG ('SCHERR called with invalid ERRNUM.')

      GOTO ( 01,02,03,04,05,06,07,08,09,10,
     1       11,12,13,14,15,16,17,18,19,20,
     2       21,22,23,24,25,26,27,28,29,30,
     3       31,32,33,34,35,36,37,38,39,40,
     4       41,42,43,44,45,46,47,48,49,50,
     5       51,52,53,54,55,56,57,58,59,60,
     6       61,62,63,64,65,66,67,68,69,70,
     7       71,72,73,74,75,76,77,78,79,80,
     8       81,82,83,84,85,86,87,88,89,90,
     9       91,92,93,94,95,96,97,98,99,
     A       2000,2001,2002,2003,2004,2005,2006,
     B       2200,2201,2202,2203,2204),  MSGDX

      CALL UNMSG ('SCHERR called with very invalid ERRNUM.')

C  List of standard error messages

01    STDMSG = '(PHCL,WSCL,STCL,ARCL)'
      GOTO 101
02    STDMSG = '(PHOP,*,*,*)'
      GOTO 101
03    STDMSG = '(PHOP,WSOP,*,*)'
      GOTO 101
04    STDMSG = '(PHOP,WSCL,STCL,ARCL)'
      GOTO 101
05    STDMSG = '(PHOP,*,STOP,*)'
      GOTO 101
06    STDMSG = '(PHOP,*,STCL,*)'
      GOTO 101
07    STDMSG = '(PHOP,*,*,AROP)'
      GOTO 101
08    STDMSG = 'connection identifier not recognized by the ' //
     1         'implementation'
      GOTO 101
09    STDMSG = 'this information is not yet available for this ' //
     1         'generic workstation type; open a workstation of ' //
     1         'this type and use the specific workstation type'
      GOTO 101
10    STDMSG = 'workstation type not recognized by the implementation'
      GOTO 101
11    STDMSG = 'workstation identifier already is in use'
      GOTO 101
12    STDMSG = 'the specified workstation is not open'
      GOTO 101
13    STDMSG = 'workstation cannot be opened for an implementation ' //
     1         'dependent reason'
      GOTO 101
14    STDMSG = 'specified workstation is not of category MO'
      GOTO 101
15    STDMSG = 'specified workstation is of category MI'
      GOTO 101
16    STDMSG = 'specified workstation is not of category MI'
      GOTO 101
17    STDMSG = 'the specified workstation does not have output ' //
     1         'capability (i.e., the workstation category is ' //
     1         'neither OUTPUT, OUTIN, nor MO)'
      GOTO 101
18    STDMSG = 'specified workstation is not of category OUTIN'
      GOTO 101
19    STDMSG = 'specified workstation is neither of category INPUT ' //
     1         'nor of category OUTIN'
      GOTO 101
20    STDMSG = 'this information is not available for this MO ' //
     1         'workstation type'
      GOTO 101
21    STDMSG = 'opening this workstation would exceed the maximum ' //
     1         'number of simultaneously open workstations'
      GOTO 101
22    STDMSG = 'the specified workstation type is not able to ' //
     1         'generate the specified GDP'
      GOTO 101
23    STDMSG = 'the bundle index value is less than one'
      GOTO 101
24    STDMSG = 'the specified representation has not been defined'
      GOTO 101
25    STDMSG = 'the specified representation has not been ' //
     1         'predefined on this workstation'
      GOTO 101
26    STDMSG = 'setting this bundle table entry would exceed the ' //
     1         'maximum number of entries allowed in the ' //
     1         'workstation bundle table'
      GOTO 101
27    STDMSG = 'the specified linetype is not available on the ' //
     1         'specified workstation'
      GOTO 101
28    STDMSG = 'the specified marker type is not available on the ' //
     1         'specified workstation'
      GOTO 101
29    STDMSG = 'the specified font is not available for the ' //
     1         'requested text precision on the specified workstation'
      GOTO 101
30    STDMSG = 'the specified edgetype is not available on the ' //
     1         'specified workstation'
      GOTO 101
31    STDMSG = 'the specified interior style is not available on ' //
     1         'the workstation'
      GOTO 101
32    STDMSG = 'interior style PATTERN is not suppported on the ' //
     1         'workstation'
      GOTO 101
33    STDMSG = 'the specified colour model is not available on the ' //
     1         'workstation'
      GOTO 101
34    STDMSG = 'the specified HLHSR model is not available on the ' //
     1         'specified workstation'
      GOTO 101
35    STDMSG = 'the pattern index value is less than one'
      GOTO 101
36    STDMSG = 'the colour index value is less than zero'
      GOTO 101
37    STDMSG = 'the view index value is less than zero'
      GOTO 101
38    STDMSG = 'the view index value is less than one'
      GOTO 101
39    STDMSG = 'one of the dimensions of pattern colour index array ' //
     1         'is less than one'
      GOTO 101
40    STDMSG = 'one of the dimensions of the colour index array is ' //
     1         'less than zero'
      GOTO 101
41    STDMSG = 'one of the components of the colour specification ' //
     1         'is out of range.  The valid range is dependent ' //
     1         'upon the current colour model'
      GOTO 101
42    STDMSG = 'setting this view table entry would exceed the ' //
     1         'maximum number of entries allowed in the ' //
     1         'workstation view table'
      GOTO 101
43    STDMSG = 'invalid window: XMIN>=XMAX, YMIN>=YMAX, ZMIN>ZMAX, ' //
     1         'UMIN>=UMAX or VMIN>=VMAX'
      GOTO 101
44    STDMSG = 'invalid viewport: XMIN>=XMAX, YMIN>=YMAX, or ZMIN>ZMAX'
      GOTO 101
45    STDMSG = 'invalid view clipping limits: XMIN>=XMAX, ' //
     1         'YMIN>=YMAX or ZMIN>ZMAX'
      GOTO 101
46    STDMSG = 'the view clipping limits are not within NPC range'
      GOTO 101
47    STDMSG = 'the projection viewport limits are not within NPC range'
      GOTO 101
48    STDMSG = 'the workstation window limits are not within NPC range'
      GOTO 101
49    STDMSG = 'the workstation viewport is not within display space'
      GOTO 101
50    STDMSG = 'front plane and back plane distances are equal ' //
     1         'when z-extent of the projection viewport is non-zero'
      GOTO 101
51    STDMSG = 'the view plane normal vector has length zero'
      GOTO 101
52    STDMSG = 'the view up vector has length zero'
      GOTO 101
53    STDMSG = 'the view up and view plane normal vectors are ' //
     1         'parallel thus the viewing coordinate system ' //
     1         'cannot be established'
      GOTO 101
54    STDMSG = 'the projection reference point is between the ' //
     1         'front and back planes'
      GOTO 101
55    STDMSG = 'the projection reference point cannot be ' //
     1         'positioned on the view plane'
      GOTO 101
56    STDMSG = 'the back plane is in front of the front plane'
      GOTO 101
57    STDMSG = 'Warning, ignoring structures that do not exist'
      GOTO 101
58    STDMSG = 'the specified structure does not exist'
      GOTO 101
59    STDMSG = 'the specified element does not exist'
      GOTO 101
60    STDMSG = 'specified starting path not found in CSS'
      GOTO 101
61    STDMSG = 'specified search ceiling index out of range'
      GOTO 101
62    STDMSG = 'the table does not exist in the open structure ' //
     1         'between the element pointer and the end of the ' //
     1         'structure'
      GOTO 101
63    STDMSG = 'one or both of the labels does not exist in the ' //
     1         'open structure between the element pointer and ' //
     1         'the end of structure'
      GOTO 101
64    STDMSG = 'the specified path depth is less than zero'
      GOTO 101
65    STDMSG = 'the display priority is out of range'
      GOTO 101
66    STDMSG = 'the specified device is not available on the ' //
     1         'specified workstation '
      GOTO 101
67    STDMSG = 'the function requires the input device to be in ' //
     1         'REQUEST mode'
      GOTO 101
68    STDMSG = 'the function requires the input device to be in ' //
     1         'SAMPLE mode'
      GOTO 101
69    STDMSG = 'the specified prompt/echo type is not available on ' //
     1         'the specified workstation'
      GOTO 101
70    STDMSG = 'invalid echo area/volume; XMIN>=XMAX,YMIN>=YMAX or ' //
     1         'ZMIN>ZMAX'
      GOTO 101
71    STDMSG = 'one of the echo area/volume boundary points is ' //
     1         'outside the range of the device'
      GOTO 101
72    STDMSG = 'Warning, the input queue has overflowed'
      GOTO 101
73    STDMSG = 'input queue has not overflowed, since OPEN PHIGS ' //
     1         'or last invocation of INQUIRE INPUT QUEUE OVERFLOW'
      GOTO 101
74    STDMSG = 'input queue has overflowed, but associated ' //
     1         'workstation has been closed'
      GOTO 101
75    STDMSG = 'the input device class of the current input report ' //
     1         'does not match the class being requested'
      GOTO 101
76    STDMSG = 'one of the fields within the input device data ' //
     1         'record is in error'
      GOTO 101
77    STDMSG = 'initial value is invalid'
      GOTO 101
78    STDMSG = 'number of points in the initial stroke is greater ' //
     1         'than the buffer size'
      GOTO 101
79    STDMSG = 'length of the initial string is greater than the ' //
     1         'buffer size'
      GOTO 101
80    STDMSG = 'item type is not allowed for user items'
      GOTO 101
81    STDMSG = 'item length is invalid '
      GOTO 101
82    STDMSG = 'no item is left in metafile input'
      GOTO 101
83    STDMSG = 'metafile item is invalid'
      GOTO 101
84    STDMSG = 'item type is unknown'
      GOTO 101
85    STDMSG = 'content of item data record is invalid for the ' //
     1         'specified item type'
      GOTO 101
86    STDMSG = 'maximum item data record length is invalid'
      GOTO 101
87    STDMSG = 'user item cannot be interpreted'
      GOTO 101
88    STDMSG = 'Warning, the specified escape is not available on ' //
     1         'one or more workstations in this implementation.  ' //
     1         'The escape will be processed by those workstations ' //
     1         'on which it is available'
      GOTO 101
89    STDMSG = 'one of the fields within the escape data record is ' //
     1         'in error'
      GOTO 101
90    STDMSG = 'the archive file cannot be opened'
      GOTO 101
91    STDMSG = 'opening this archive file would exceed the maximum ' //
     1         'number of simultaneously open archive files'
      GOTO 101
92    STDMSG = 'archive file identifier already in use'
      GOTO 101
93    STDMSG = 'the archive file is not a PHIGS archive file'
      GOTO 101
94    STDMSG = 'the specified archive file is not open'
      GOTO 101
95    STDMSG = 'name conflict occurred while conflict resolution ' //
     1         'flag has value ABANDON'
      GOTO 101
96    STDMSG = 'Warning, the archive file is full.  Any structures ' //
     1         'that were archived were archived in total'
      GOTO 101
97    STDMSG = 'Warning, some of the specified structures do not ' //
     1         'exist on the archive file'
      GOTO 101
98    STDMSG = 'Warning, some of the specified structures do not ' //
     1         'exist on the archive file.  PHIGS will create ' //
     1         'empty structure in their place'
      GOTO 101
99    STDMSG = 'the specified error file is invalid'
      GOTO 101

2000  STDMSG = 'enumeration type out of range'
      GOTO 101
2001  STDMSG = 'output parameter size insufficient'
      GOTO 101
2002  STDMSG = 'list or set element not available'
      GOTO 101
2003  STDMSG = 'invalid data record'
      GOTO 101
2004  STDMSG = 'input parameter size out of range'
      GOTO 101
2005  STDMSG = 'invalid list of point lists'
      GOTO 101
2006  STDMSG = 'invalid list of filters'
      GOTO 101
2200  STDMSG = 'start index is out of range'
      GOTO 101
2201  STDMSG = 'length of application''s list is negative'
      GOTO 101
2202  STDMSG = 'enumeration type out of range'
      GOTO 101
2203  STDMSG = 'error while allocating a Store'
      GOTO 101
2204  STDMSG = 'error while allocating memory'
      GOTO 101

101   CONTINUE

      IF (MSGDX .LE. 7) THEN
         ERRMSG = 'Ignoring function, function requires state ' //
     1            STDMSG
      ELSEIF (STDMSG(1:7) .EQ. 'Warning') THEN
         ERRMSG = STDMSG
      ELSE
         ERRMSG = 'Ignoring function, ' // STDMSG
      ENDIF

      END
