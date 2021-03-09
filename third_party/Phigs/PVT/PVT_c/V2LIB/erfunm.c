/* erfunm.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int erfunm_(integer *funccd, char *funnam, ftnlen funnam_len)

#else /* NO_PROTO */
/* Subroutine */ int erfunm_(funccd, funnam, funnam_len)
integer *funccd;
char *funnam;
ftnlen funnam_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static char funtab[45*183] = "<open phigs>                              "
	    "   " "<close phigs>                                " "<open work"
	    "station>                           " "<close workstation>       "
	    "                   " "<redraw all structures>                   "
	    "   " "<update workstation>                         " "<set displ"
	    "ay update state>                   " "<message>                 "
	    "                   " "<polyline 3>                              "
	    "   " "<polyline>                                   " "<polymarke"
	    "r 3>                               " "<polymarker>              "
	    "                   " "<text 3>                                  "
	    "   " "<text>                                       " "<annotatio"
	    "n text relative 3>                 " "<annotation text relative>"
	    "                   " "<fill area 3>                             "
	    "   " "<fill area>                                  " "<fill area"
	    " set 3>                            " "<fill area set>           "
	    "                   " "<cell array 3>                            "
	    "   " "<cell array>                                 " "<generaliz"
	    "ed drawing primitive 3>            " "<generalized drawing primi"
	    "tive>              " "<set polyline index>                      "
	    "   " "<set polymarker index>                       " "<set text "
	    "index>                             " "<set interior index>      "
	    "                   " "<set edge index>                          "
	    "   " "<set linetype>                               " "<set linew"
	    "idth scale factor>                 " "<set polyline colour index"
	    ">                  " "<set marker type>                         "
	    "   " "<set marker size scale factor>               " "<set polym"
	    "arker colour index>                " "<set text font>           "
	    "                   " "<set text precision>                      "
	    "   " "<set character expansion factor>             " "<set chara"
	    "cter spacing>                      " "<set text colour index>   "
	    "                   " "<set character height>                    "
	    "   " "<set character up vector>                    " "<set text "
	    "path>                              " "<set text alignment>      "
	    "                   " "<set annotation text character height>    "
	    "   " "<set annotation text character up vector>    " "<set annot"
	    "ation text path>                   " "<set annotation text align"
	    "ment>              " "<set annotation style>                    "
	    "   " "<set interior style>                         " "<set inter"
	    "ior style index>                   " "<set interior colour index"
	    ">                  " "<set edge flag>                           "
	    "   " "<set edgetype>                               " "<set edgew"
	    "idth scale factor>                 " "<set edge colour index>   "
	    "                   " "<set pattern size>                        "
	    "   " "<set pattern reference point and vectors>    " "<set patte"
	    "rn reference point>                " "<add names to set>        "
	    "                   " "<remove names from set>                   "
	    "   " "<set individual asf>                         " "<set polyl"
	    "ine representation>                " "<set polymarker representa"
	    "tion>              " "<set text representation>                 "
	    "   " "<set interior representation>                " "<set edge "
	    "representation>                    " "<set pattern representatio"
	    "n>                 " "<set colour representation>               "
	    "   " "<set highlighting filter>                    " "<set invis"
	    "ibility filter>                    " "<set colour model>        "
	    "                   " "<set hlhsr identifier>                    "
	    "   " "<set hlhsr mode>                             " "<set local"
	    " transformation 3>                 " "<set local transformation>"
	    "                   " "<set global transformation 3>             "
	    "   " "<set global transformation>                  " "<set model"
	    "ling clipping volume 3>            " "<set modelling clipping vo"
	    "lume>              " "<set modelling clipping indicator>        "
	    "   " "<restore modelling clipping volume>          " "<set view "
	    "index>                             " "<set view representation 3"
	    ">                  " "<set view representation>                 "
	    "   " "<set view transformation input priority>     " "<set works"
	    "tation window 3>                   " "<set workstation window>  "
	    "                   " "<set workstation viewport 3>              "
	    "   " "<set workstation viewport>                   " "<open stru"
	    "cture>                             " "<close structure>         "
	    "                   " "<execute structure>                       "
	    "   " "<label>                                      " "<applicati"
	    "on data>                           " "<generalized structure ele"
	    "ment>              " "<set edit mode>                           "
	    "   " "<copy all elements from structure>           " "<set eleme"
	    "nt pointer>                        " "<offset element pointer>  "
	    "                   " "<set element pointer at label>            "
	    "   " "<delete element>                             " "<delete el"
	    "ement range>                       " "<delete elements between l"
	    "abels>             " "<empty structure>                         "
	    "   " "<delete structure>                           " "<delete st"
	    "ructure network>                   " "<delete all structures>   "
	    "                   " "<change structure identifier>             "
	    "   " "<change structure references>                " "<change st"
	    "ructure identifier and references> " "<post structure>          "
	    "                   " "<unpost structure>                        "
	    "   " "<unpost all structures>                      " "<open arch"
	    "ive file>                          " "<close archive file>      "
	    "                   " "<archive structures>                      "
	    "   " "<archive structure networks>                 " "<archive a"
	    "ll structures>                     " "<set conflict resolution> "
	    "                   " "<retrieve structure identifiers>          "
	    "   " "<retrieve structures>                        " "<retrieve "
	    "structure networks>                " "<retrieve all structures> "
	    "                   " "<retrieve paths to ancestors>             "
	    "   " "<retrieve paths to descendants>              " "<delete st"
	    "ructures from archive>             " "<delete structure networks"
	    " from archive>     " "<delete all structures from archive>      "
	    "   " "<set pick identifier>                        " "<set pick "
	    "filter>                            " "<initialize locator 3>    "
	    "                   " "<initialize locator>                      "
	    "   " "<initialize stroke 3>                        " "<initializ"
	    "e stroke>                          " "<initialize valuator 3>   "
	    "                   " "<initialize valuator>                     "
	    "   " "<initialize choice 3>                        " "<initializ"
	    "e choice>                          " "<initialize pick 3>       "
	    "                   " "<initialize pick>                         "
	    "   " "<initialize string 3>                        " "<initializ"
	    "e string>                          " "<set locator mode>        "
	    "                   " "<set stroke mode>                         "
	    "   " "<set valuator mode>                          " "<set choic"
	    "e mode>                            " "<set pick mode>           "
	    "                   " "<set string mode>                         "
	    "   " "<request locator 3>                          " "<request l"
	    "ocator>                            " "<request stroke 3>        "
	    "                   " "<request stroke>                          "
	    "   " "<request valuator>                           " "<request c"
	    "hoice>                             " "<request pick>            "
	    "                   " "<request string>                          "
	    "   " "<sample locator 3>                           " "<sample lo"
	    "cator>                             " "<sample stroke 3>         "
	    "                   " "<sample stroke>                           "
	    "   " "<sample valuator>                            " "<sample ch"
	    "oice>                              " "<sample pick>             "
	    "                   " "<sample string>                           "
	    "   " "<await event>                                " "<flush dev"
	    "ice events>                        " "<get locator 3>           "
	    "                   " "<get locator>                             "
	    "   " "<get stroke 3>                               " "<get strok"
	    "e>                                 " "<get valuator>            "
	    "                   " "<get choice>                              "
	    "   " "<get pick>                                   " "<get strin"
	    "g>                                 " "<write item to metafile>  "
	    "                   " "<get item type from metafile>             "
	    "   " "<read item from metafile>                    " "<interpret"
	    " item>                             " "<set error handling mode> "
	    "                   " "<escape>                                  "
	    "   " "<pack data record>                           " "<unpack da"
	    "ta record>                         ";
#else /* NO_PROTO */
    static char funtab[45*183+1] = "<open phigs>                            \
     <close phigs>                                <open workstation>        \
                   <close workstation>                          <redraw all \
structures>                      <update workstation>                       \
  <set display update state>                   <message>                    \
                <polyline 3>                                 <polyline>     \
                              <polymarker 3>                               <\
polymarker>                                 <text 3>                        \
             <text>                                       <annotation text r\
elative 3>                 <annotation text relative>                   <fil\
l area 3>                                <fill area>                        \
          <fill area set 3>                            <fill area set>      \
                        <cell array 3>                               <cell a\
rray>                                 <generalized drawing primitive 3>     \
       <generalized drawing primitive>              <set polyline index>    \
                     <set polymarker index>                       <set text \
index>                             <set interior index>                     \
    <set edge index>                             <set linetype>             \
                  <set linewidth scale factor>                 <set polyline\
 colour index>                  <set marker type>                           \
 <set marker size scale factor>               <set polymarker colour index> \
               <set text font>                              <set text precis\
ion>                         <set character expansion factor>             <s\
et character spacing>                      <set text colour index>          \
            <set character height>                       <set character up v\
ector>                    <set text path>                              <set \
text alignment>                         <set annotation text character heigh\
t>       <set annotation text character up vector>    <set annotation text p\
ath>                   <set annotation text alignment>              <set ann\
otation style>                       <set interior style>                   \
      <set interior style index>                   <set interior colour inde\
x>                  <set edge flag>                              <set edgety\
pe>                               <set edgewidth scale factor>              \
   <set edge colour index>                      <set pattern size>          \
                 <set pattern reference point and vectors>    <set pattern r\
eference point>                <add names to set>                           \
<remove names from set>                      <set individual asf>           \
              <set polyline representation>                <set polymarker r\
epresentation>              <set text representation>                    <se\
t interior representation>                <set edge representation>         \
           <set pattern representation>                 <set colour represen\
tation>                  <set highlighting filter>                    <set i\
nvisibility filter>                    <set colour model>                   \
        <set hlhsr identifier>                       <set hlhsr mode>       \
                      <set local transformation 3>                 <set loca\
l transformation>                   <set global transformation 3>           \
     <set global transformation>                  <set modelling clipping vo\
lume 3>            <set modelling clipping volume>              <set modelli\
ng clipping indicator>           <restore modelling clipping volume>        \
  <set view index>                             <set view representation 3>  \
                <set view representation>                    <set view trans\
formation input priority>     <set workstation window 3>                   <\
set workstation window>                     <set workstation viewport 3>    \
             <set workstation viewport>                   <open structure>  \
                           <close structure>                            <exe\
cute structure>                          <label>                            \
          <application data>                           <generalized structur\
e element>              <set edit mode>                              <copy a\
ll elements from structure>           <set element pointer>                 \
       <offset element pointer>                     <set element pointer at \
label>               <delete element>                             <delete el\
ement range>                       <delete elements between labels>         \
    <empty structure>                            <delete structure>         \
                  <delete structure network>                   <delete all s\
tructures>                      <change structure identifier>               \
 <change structure references>                <change structure identifier a\
nd references> <post structure>                             <unpost structur\
e>                           <unpost all structures>                      <o\
pen archive file>                          <close archive file>             \
            <archive structures>                         <archive structure \
networks>                 <archive all structures>                     <set \
conflict resolution>                    <retrieve structure identifiers>    \
         <retrieve structures>                        <retrieve structure ne\
tworks>                <retrieve all structures>                    <retriev\
e paths to ancestors>                <retrieve paths to descendants>        \
      <delete structures from archive>             <delete structure network\
s from archive>     <delete all structures from archive>         <set pick i\
dentifier>                        <set pick filter>                         \
   <initialize locator 3>                       <initialize locator>        \
                 <initialize stroke 3>                        <initialize st\
roke>                          <initialize valuator 3>                      \
<initialize valuator>                        <initialize choice 3>          \
              <initialize choice>                          <initialize pick \
3>                          <initialize pick>                            <in\
itialize string 3>                        <initialize string>               \
           <set locator mode>                           <set stroke mode>   \
                         <set valuator mode>                          <set c\
hoice mode>                            <set pick mode>                      \
        <set string mode>                            <request locator 3>    \
                      <request locator>                            <request \
stroke 3>                           <request stroke>                        \
     <request valuator>                           <request choice>          \
                   <request pick>                               <request str\
ing>                             <sample locator 3>                         \
  <sample locator>                             <sample stroke 3>            \
                <sample stroke>                              <sample valuato\
r>                            <sample choice>                              <\
sample pick>                                <sample string>                 \
             <await event>                                <flush device even\
ts>                        <get locator 3>                              <get\
 locator>                                <get stroke 3>                     \
          <get stroke>                                 <get valuator>       \
                        <get choice>                                 <get pi\
ck>                                   <get string>                          \
       <write item to metafile>                     <get item type from meta\
file>                <read item from metafile>                    <interpret\
 item>                             <set error handling mode>                \
    <escape>                                     <pack data record>         \
                  <unpack data record>                         ";
#endif /* NO_PROTO */

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */

/* ERFUNM accepts an integer identifying a function and returns the generi
c*/
/* name of the function.  These are the "official" function codes from the
*/
/*  standard Fortran binding.  Only functions that generate errors are */
/*  encoded. */

/*  Input parameter: */
/*    FUNCCD : integer code for offending function */
/*  Output parameter: */
/*    FUNNAM : generic name of function */
    if (*funccd >= 0 && *funccd <= 182) {
	s_copy(funnam, funtab + *funccd * 45, funnam_len, 45L);
    } else {
	unmsg_("ERFUNM called with invalid value.", 33L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* erfunm_ */

