/* colnam.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int colnam_(real *u, real *v, integer *incode, integer *cdex,
	 char *cnam, ftnlen cnam_len)
#else /* NO_PROTO */
/* Subroutine */ int colnam_(u, v, incode, cdex, cnam, cnam_len)
real *u, *v;
integer *incode, *cdex;
char *cnam;
ftnlen cnam_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static char reglbl[16*20] = "purple          " "purplish blue   " "blue "
	    "           " "greenish blue   " "bluish green    " "green       "
	    "    " "yellowish green " "yellow green    " "greenish yellow " 
	    "yellow          " "orange yellow   " "orange          " "reddis"
	    "h orange  " "red             " "purplish red    " "reddish purpl"
	    "e  " "yellowish pink  " "pink            " "purplish pink   " 
	    "white           ";
#else /* NO_PROTO */
    static char reglbl[16*20+1] = "purple          purplish blue   blue     \
       greenish blue   bluish green    green           yellowish green yello\
w green    greenish yellow yellow          orange yellow   orange          r\
eddish orange  red             purplish red    reddish purple  yellowish pin\
k  pink            purplish pink   white           ";
#endif /* NO_PROTO */
    static integer regdx[20] = { 15,33,47,58,69,81,94,101,107,113,117,123,133,
	    146,159,169,178,189,200,226 };
#ifndef NO_PROTO
    static real regx[226] = { .25484f,.23237f,.21495f,.20258f,.19648f,.19294f,
	    .197f,.20583f,.22099f,.23745f,.25769f,.29662f,.32923f,.36687f,
	    .40575f,.18325f,.17465f,.1673f,.16249f,.1639f,.17037f,.17809f,
	    .18313f,.19195f,.188f,.1866f,.18895f,.20126f,.2099f,.22359f,
	    .23853f,.25103f,.20456f,.07929f,.09838f,.12126f,.14667f,.15545f,
	    .17306f,.16407f,.15752f,.1598f,.16466f,.17698f,.14187f,.11304f,
	    .09178f,.03059f,.06726f,.10519f,.133f,.13418f,.14292f,.12893f,
	    .10735f,.08954f,.07553f,.05056f,8.6e-4f,.06389f,.10422f,.142f,
	    .13564f,.13303f,.10774f,.06856f,.0281f,.01691f,.00574f,.00872f,
	    .0528f,.09182f,.13207f,.15469f,.14581f,.1118f,.06265f,.02862f,
	    8.9e-4f,.001f,.0049f,.13108f,.15366f,.17496f,.16736f,.1585f,
	    .13713f,.10443f,.05786f,.01379f,.0239f,.03528f,.05294f,.08319f,
	    .20041f,.1978f,.19772f,.18002f,.16874f,.1537f,.13739f,.22436f,
	    .21546f,.21036f,.20278f,.20285f,.20419f,.26973f,.252f,.2356f,
	    .21667f,.22429f,.23066f,.30124f,.27216f,.2583f,.27603f,.35796f,
	    .32258f,.29858f,.286f,.27719f,.30754f,.52182f,.47515f,.42344f,
	    .38305f,.36665f,.35659f,.34274f,.33014f,.35035f,.3693f,.59218f,
	    .54429f,.50143f,.43964f,.38415f,.38294f,.37419f,.40827f,.44612f,
	    .48648f,.53188f,.57476f,.63148f,.48565f,.4454f,.40387f,.3636f,
	    .33843f,.3549f,.37138f,.38028f,.38413f,.41314f,.46484f,.52157f,
	    .58837f,.40828f,.3807f,.32299f,.2891f,.30933f,.33337f,.36987f,
	    .41518f,.4567f,.48311f,.35907f,.32877f,.28964f,.26439f,.26949f,
	    .29477f,.31877f,.33389f,.35279f,.37525f,.33365f,.28574f,.25673f,
	    .26184f,.28078f,.31108f,.36409f,.37541f,.37914f,.37908f,.28534f,
	    .264f,.23136f,.24655f,.25418f,.28823f,.33615f,.37397f,.35873f,
	    .3372f,.31189f,.25519f,.24f,.22607f,.20334f,.18441f,.16554f,
	    .15048f,.14297f,.13924f,.13807f,.14194f,.15973f,.17365f,.20149f,
	    .22169f,.23935f,.25449f,.26709f,.28219f,.28974f,.26446f,.25936f,
	    .25297f,.24026f,.22631f,.24012f };
    static real regy[226] = { .01485f,.06971f,.1272f,.18469f,.23305f,.29317f,
	    .35723f,.35855f,.36381f,.37822f,.39395f,.35219f,.30911f,.26212f,
	    .21122f,.08662f,.1415f,.19247f,.24998f,.28397f,.3245f,.35981f,
	    .35851f,.35722f,.318f,.28401f,.24218f,.17162f,.12719f,.08146f,
	    .03574f,.00962f,.05659f,.26028f,.29953f,.34271f,.3872f,.37415f,
	    .36241f,.32449f,.26696f,.21076f,.16501f,.09576f,.14536f,.18845f,
	    .23024f,.37653f,.39751f,.4198f,.43424f,.41594f,.39373f,.36756f,
	    .33353f,.2969f,.2655f,.32558f,.50458f,.49685f,.48908f,.47608f,
	    .463f,.44208f,.42765f,.40666f,.38306f,.42225f,.46537f,.57518f,
	    .55827f,.54004f,.51266f,.49441f,.48263f,.49302f,.50208f,.50855f,
	    .51111f,.53856f,.56602f,.57933f,.54931f,.51667f,.50881f,.49964f,
	    .5166f,.53876f,.5622f,.57911f,.58567f,.59222f,.59226f,.58708f,
	    .569f,.54808f,.52978f,.51929f,.53626f,.55846f,.57934f,.56512f,
	    .54811f,.53503f,.5324f,.5494f,.56901f,.55737f,.54034f,.54031f,
	    .53766f,.54944f,.56514f,.5522f,.53515f,.53904f,.557f,.54315f,
	    .52871f,.51951f,.52602f,.53124f,.5509f,.51862f,.51853f,.51713f,
	    .51183f,.50918f,.51701f,.52352f,.52611f,.53268f,.54056f,.45339f,
	    .46245f,.4676f,.47141f,.47392f,.48568f,.50397f,.50926f,.51194f,
	    .51202f,.5108f,.51088f,.50183f,.31594f,.3407f,.36415f,.38499f,
	    .39802f,.41504f,.43599f,.453f,.46738f,.46744f,.46492f,.4598f,
	    .44816f,.21253f,.253f,.32609f,.36525f,.37574f,.39409f,.37585f,
	    .35241f,.32896f,.31071f,.50739f,.50087f,.49304f,.48783f,.49957f,
	    .51261f,.52174f,.51913f,.51261f,.45652f,.46174f,.46435f,.46435f,
	    .48f,.48522f,.49304f,.50217f,.49304f,.4813f,.46696f,.37043f,
	    .39522f,.43043f,.44478f,.45913f,.45783f,.45522f,.4513f,.42652f,
	    .40435f,.38478f,.39913f,.38609f,.37304f,.36522f,.36391f,.37435f,
	    .39261f,.40565f,.42f,.44087f,.46174f,.49304f,.50478f,.52565f,
	    .52957f,.53217f,.53217f,.52826f,.52174f,.51652f,.50478f,.49043f,
	    .46957f,.44739f,.43043f,.41478f };
#else /* NO_PROTO */
    static real regx[226] = { (float).25484,(float).23237,(float).21495,(
	    float).20258,(float).19648,(float).19294,(float).197,(float)
	    .20583,(float).22099,(float).23745,(float).25769,(float).29662,(
	    float).32923,(float).36687,(float).40575,(float).18325,(float)
	    .17465,(float).1673,(float).16249,(float).1639,(float).17037,(
	    float).17809,(float).18313,(float).19195,(float).188,(float).1866,
	    (float).18895,(float).20126,(float).2099,(float).22359,(float)
	    .23853,(float).25103,(float).20456,(float).07929,(float).09838,(
	    float).12126,(float).14667,(float).15545,(float).17306,(float)
	    .16407,(float).15752,(float).1598,(float).16466,(float).17698,(
	    float).14187,(float).11304,(float).09178,(float).03059,(float)
	    .06726,(float).10519,(float).133,(float).13418,(float).14292,(
	    float).12893,(float).10735,(float).08954,(float).07553,(float)
	    .05056,(float)8.6e-4,(float).06389,(float).10422,(float).142,(
	    float).13564,(float).13303,(float).10774,(float).06856,(float)
	    .0281,(float).01691,(float).00574,(float).00872,(float).0528,(
	    float).09182,(float).13207,(float).15469,(float).14581,(float)
	    .1118,(float).06265,(float).02862,(float)8.9e-4,(float).001,(
	    float).0049,(float).13108,(float).15366,(float).17496,(float)
	    .16736,(float).1585,(float).13713,(float).10443,(float).05786,(
	    float).01379,(float).0239,(float).03528,(float).05294,(float)
	    .08319,(float).20041,(float).1978,(float).19772,(float).18002,(
	    float).16874,(float).1537,(float).13739,(float).22436,(float)
	    .21546,(float).21036,(float).20278,(float).20285,(float).20419,(
	    float).26973,(float).252,(float).2356,(float).21667,(float).22429,
	    (float).23066,(float).30124,(float).27216,(float).2583,(float)
	    .27603,(float).35796,(float).32258,(float).29858,(float).286,(
	    float).27719,(float).30754,(float).52182,(float).47515,(float)
	    .42344,(float).38305,(float).36665,(float).35659,(float).34274,(
	    float).33014,(float).35035,(float).3693,(float).59218,(float)
	    .54429,(float).50143,(float).43964,(float).38415,(float).38294,(
	    float).37419,(float).40827,(float).44612,(float).48648,(float)
	    .53188,(float).57476,(float).63148,(float).48565,(float).4454,(
	    float).40387,(float).3636,(float).33843,(float).3549,(float)
	    .37138,(float).38028,(float).38413,(float).41314,(float).46484,(
	    float).52157,(float).58837,(float).40828,(float).3807,(float)
	    .32299,(float).2891,(float).30933,(float).33337,(float).36987,(
	    float).41518,(float).4567,(float).48311,(float).35907,(float)
	    .32877,(float).28964,(float).26439,(float).26949,(float).29477,(
	    float).31877,(float).33389,(float).35279,(float).37525,(float)
	    .33365,(float).28574,(float).25673,(float).26184,(float).28078,(
	    float).31108,(float).36409,(float).37541,(float).37914,(float)
	    .37908,(float).28534,(float).264,(float).23136,(float).24655,(
	    float).25418,(float).28823,(float).33615,(float).37397,(float)
	    .35873,(float).3372,(float).31189,(float).25519,(float).24,(float)
	    .22607,(float).20334,(float).18441,(float).16554,(float).15048,(
	    float).14297,(float).13924,(float).13807,(float).14194,(float)
	    .15973,(float).17365,(float).20149,(float).22169,(float).23935,(
	    float).25449,(float).26709,(float).28219,(float).28974,(float)
	    .26446,(float).25936,(float).25297,(float).24026,(float).22631,(
	    float).24012 };
    static real regy[226] = { (float).01485,(float).06971,(float).1272,(float)
	    .18469,(float).23305,(float).29317,(float).35723,(float).35855,(
	    float).36381,(float).37822,(float).39395,(float).35219,(float)
	    .30911,(float).26212,(float).21122,(float).08662,(float).1415,(
	    float).19247,(float).24998,(float).28397,(float).3245,(float)
	    .35981,(float).35851,(float).35722,(float).318,(float).28401,(
	    float).24218,(float).17162,(float).12719,(float).08146,(float)
	    .03574,(float).00962,(float).05659,(float).26028,(float).29953,(
	    float).34271,(float).3872,(float).37415,(float).36241,(float)
	    .32449,(float).26696,(float).21076,(float).16501,(float).09576,(
	    float).14536,(float).18845,(float).23024,(float).37653,(float)
	    .39751,(float).4198,(float).43424,(float).41594,(float).39373,(
	    float).36756,(float).33353,(float).2969,(float).2655,(float)
	    .32558,(float).50458,(float).49685,(float).48908,(float).47608,(
	    float).463,(float).44208,(float).42765,(float).40666,(float)
	    .38306,(float).42225,(float).46537,(float).57518,(float).55827,(
	    float).54004,(float).51266,(float).49441,(float).48263,(float)
	    .49302,(float).50208,(float).50855,(float).51111,(float).53856,(
	    float).56602,(float).57933,(float).54931,(float).51667,(float)
	    .50881,(float).49964,(float).5166,(float).53876,(float).5622,(
	    float).57911,(float).58567,(float).59222,(float).59226,(float)
	    .58708,(float).569,(float).54808,(float).52978,(float).51929,(
	    float).53626,(float).55846,(float).57934,(float).56512,(float)
	    .54811,(float).53503,(float).5324,(float).5494,(float).56901,(
	    float).55737,(float).54034,(float).54031,(float).53766,(float)
	    .54944,(float).56514,(float).5522,(float).53515,(float).53904,(
	    float).557,(float).54315,(float).52871,(float).51951,(float)
	    .52602,(float).53124,(float).5509,(float).51862,(float).51853,(
	    float).51713,(float).51183,(float).50918,(float).51701,(float)
	    .52352,(float).52611,(float).53268,(float).54056,(float).45339,(
	    float).46245,(float).4676,(float).47141,(float).47392,(float)
	    .48568,(float).50397,(float).50926,(float).51194,(float).51202,(
	    float).5108,(float).51088,(float).50183,(float).31594,(float)
	    .3407,(float).36415,(float).38499,(float).39802,(float).41504,(
	    float).43599,(float).453,(float).46738,(float).46744,(float)
	    .46492,(float).4598,(float).44816,(float).21253,(float).253,(
	    float).32609,(float).36525,(float).37574,(float).39409,(float)
	    .37585,(float).35241,(float).32896,(float).31071,(float).50739,(
	    float).50087,(float).49304,(float).48783,(float).49957,(float)
	    .51261,(float).52174,(float).51913,(float).51261,(float).45652,(
	    float).46174,(float).46435,(float).46435,(float).48,(float).48522,
	    (float).49304,(float).50217,(float).49304,(float).4813,(float)
	    .46696,(float).37043,(float).39522,(float).43043,(float).44478,(
	    float).45913,(float).45783,(float).45522,(float).4513,(float)
	    .42652,(float).40435,(float).38478,(float).39913,(float).38609,(
	    float).37304,(float).36522,(float).36391,(float).37435,(float)
	    .39261,(float).40565,(float).42,(float).44087,(float).46174,(
	    float).49304,(float).50478,(float).52565,(float).52957,(float)
	    .53217,(float).53217,(float).52826,(float).52174,(float).51652,(
	    float).50478,(float).49043,(float).46957,(float).44739,(float)
	    .43043,(float).41478 };
#endif /* NO_PROTO */

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix, prv, this__;
#ifndef NO_PROTO
    extern integer inarea_(real *, real *, integer *, real *, real *);
#else /* NO_PROTO */
    extern integer inarea_();
#endif /* NO_PROTO */

/*  COLNAM returns the English phrase corresponding to the color */
/*  indicated by the u-v CIELUV coordinates (luminance is ignored). */
/*  COLNAM returns "none" for locations near borders or outside the */
/*  color region. */

/*  Input parameters: */
/*    U,V    : the u', v' CIELUV coordinates */
/*  Output parameters: */
/*    INCODE : status of u', v' point: 1-inside color region, */
/*             2-on edge of color region, 3-outside color region */
/*    CDEX   : integer identifier of region; 0 if none */
/*    CNAM   : English description of color, taken from CIELUV diagram */
/*  label for 20 CIELUV color regions */
/*  list of end-points of color regions */
    prv = 0;
    for (ix = 1; ix <= 20; ++ix) {
	this__ = regdx[ix - 1];
	i__1 = this__ - prv;
	*incode = inarea_(u, v, &i__1, &regx[prv], &regy[prv]);
	prv = this__;
	if (*incode == 1 || *incode == 2) {
	    *cdex = ix;
	    s_copy(cnam, reglbl + (ix - 1 << 4), cnam_len, 16L);
	    return 0;
	}
/* L400: */
    }
    *cdex = 0;
    s_copy(cnam, "none", cnam_len, 4L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* colnam_ */

