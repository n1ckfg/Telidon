      SUBROUTINE ERFUNM (FUNCCD, FUNNAM)

C  ERFUNM accepts an integer identifying a function and returns the generic
C  name of the function.  These are the "official" function codes from the
C  standard Fortran binding.  Only functions that generate errors are
C  encoded.
C
C  Input parameter:
C    FUNCCD : integer code for offending function
C  Output parameter:
C    FUNNAM : generic name of function

      INTEGER    FUNCCD, IX
      CHARACTER  FUNNAM*(*), FUNTAB(0:182)*45

      DATA (FUNTAB(IX), IX=0,9) / '<open phigs>',
     1  '<close phigs>', '<open workstation>', '<close workstation>',
     1  '<redraw all structures>', '<update workstation>',
     1  '<set display update state>', '<message>', '<polyline 3>',
     1  '<polyline>'  /

      DATA (FUNTAB(IX), IX=10,19) / '<polymarker 3>',
     1  '<polymarker>', '<text 3>', '<text>',
     1  '<annotation text relative 3>',  '<annotation text relative>',
     1  '<fill area 3>', '<fill area>', '<fill area set 3>',
     1  '<fill area set>' /

      DATA (FUNTAB(IX), IX=20,29) / '<cell array 3>',
     1  '<cell array>', '<generalized drawing primitive 3>',
     1  '<generalized drawing primitive>', '<set polyline index>',
     1  '<set polymarker index>', '<set text index>',
     1  '<set interior index>', '<set edge index>', '<set linetype>' /

      DATA (FUNTAB(IX), IX=30,39) / '<set linewidth scale factor>',
     1  '<set polyline colour index>', '<set marker type>',
     1  '<set marker size scale factor>',
     1  '<set polymarker colour index>', '<set text font>',
     1  '<set text precision>', '<set character expansion factor>',
     1  '<set character spacing>', '<set text colour index>' /

      DATA (FUNTAB(IX), IX=40,49) / '<set character height>',
     1  '<set character up vector>', '<set text path>',
     1  '<set text alignment>',
     1  '<set annotation text character height>',
     1  '<set annotation text character up vector>',
     1  '<set annotation text path>', '<set annotation text alignment>',
     1  '<set annotation style>', '<set interior style>' /

      DATA (FUNTAB(IX), IX=50,59) / '<set interior style index>',
     1  '<set interior colour index>', '<set edge flag>',
     1  '<set edgetype>', '<set edgewidth scale factor>',
     1  '<set edge colour index>', '<set pattern size>',
     1  '<set pattern reference point and vectors>',
     1  '<set pattern reference point>', '<add names to set>' /

      DATA (FUNTAB(IX), IX=60,69) / '<remove names from set>',
     1  '<set individual asf>', '<set polyline representation>',
     1  '<set polymarker representation>', '<set text representation>',
     1  '<set interior representation>', '<set edge representation>',
     1  '<set pattern representation>', '<set colour representation>',
     1  '<set highlighting filter>' /

      DATA (FUNTAB(IX), IX=70,79) / '<set invisibility filter>',
     1  '<set colour model>', '<set hlhsr identifier>',
     1  '<set hlhsr mode>', '<set local transformation 3>',
     1  '<set local transformation>', '<set global transformation 3>',
     1  '<set global transformation>',
     1  '<set modelling clipping volume 3>',
     1  '<set modelling clipping volume>' /

      DATA (FUNTAB(IX), IX=80,89) /'<set modelling clipping indicator>',
     1  '<restore modelling clipping volume>', '<set view index>',
     1  '<set view representation 3>', '<set view representation>',
     1  '<set view transformation input priority>',
     1  '<set workstation window 3>', '<set workstation window>',
     1  '<set workstation viewport 3>', '<set workstation viewport>' /

      DATA (FUNTAB(IX), IX=90,99) / '<open structure>',
     1  '<close structure>', '<execute structure>', '<label>',
     1  '<application data>', '<generalized structure element>',
     1  '<set edit mode>', '<copy all elements from structure>',
     1  '<set element pointer>', '<offset element pointer>' /

      DATA (FUNTAB(IX), IX=100,109) / '<set element pointer at label>',
     1  '<delete element>', '<delete element range>',
     1  '<delete elements between labels>', '<empty structure>',
     1  '<delete structure>', '<delete structure network>',
     1  '<delete all structures>', '<change structure identifier>',
     1  '<change structure references>' /

      DATA (FUNTAB(IX), IX=110,119) /
     1  '<change structure identifier and references>',
     1  '<post structure>', '<unpost structure>',
     1  '<unpost all structures>', '<open archive file>',
     1  '<close archive file>', '<archive structures>',
     1  '<archive structure networks>', '<archive all structures>',
     1  '<set conflict resolution>' /

      DATA (FUNTAB(IX), IX=120,129) /'<retrieve structure identifiers>',
     1  '<retrieve structures>', '<retrieve structure networks>',
     1  '<retrieve all structures>',
     1  '<retrieve paths to ancestors>',
     1  '<retrieve paths to descendants>',
     1  '<delete structures from archive>',
     1  '<delete structure networks from archive>',
     1  '<delete all structures from archive>', '<set pick identifier>'/

      DATA (FUNTAB(IX), IX=130,139) / '<set pick filter>',
     1  '<initialize locator 3>', '<initialize locator>',
     1  '<initialize stroke 3>', '<initialize stroke>',
     1  '<initialize valuator 3>', '<initialize valuator>',
     1  '<initialize choice 3>', '<initialize choice>',
     1  '<initialize pick 3>' /

      DATA (FUNTAB(IX), IX=140,149) / '<initialize pick>',
     1  '<initialize string 3>', '<initialize string>',
     1  '<set locator mode>', '<set stroke mode>',
     1  '<set valuator mode>', '<set choice mode>', '<set pick mode>',
     1  '<set string mode>', '<request locator 3>' /

      DATA (FUNTAB(IX), IX=150,159) / '<request locator>',
     1  '<request stroke 3>', '<request stroke>', '<request valuator>',
     1  '<request choice>', '<request pick>', '<request string>',
     1  '<sample locator 3>', '<sample locator>', '<sample stroke 3>' /

      DATA (FUNTAB(IX), IX=160,169) / '<sample stroke>',
     1  '<sample valuator>', '<sample choice>', '<sample pick>',
     1  '<sample string>', '<await event>', '<flush device events>',
     1  '<get locator 3>', '<get locator>', '<get stroke 3>' /

      DATA (FUNTAB(IX), IX=170,179) / '<get stroke>',
     1  '<get valuator>', '<get choice>', '<get pick>', '<get string>',
     1  '<write item to metafile>', '<get item type from metafile>',
     1  '<read item from metafile>', '<interpret item>',
     1  '<set error handling mode>' /

      DATA (FUNTAB(IX), IX=180,182) / '<escape>', '<pack data record>',
     1  '<unpack data record>' /

      IF (FUNCCD.GE.0 .AND. FUNCCD.LE.182) THEN
         FUNNAM = FUNTAB(FUNCCD)
      ELSE
         CALL UNMSG ('ERFUNM called with invalid value.')
      ENDIF

      END
