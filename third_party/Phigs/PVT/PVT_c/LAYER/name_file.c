#include <phigs.h>
#include <string.h>

/*** Comon block used to get program name ***/
struct
{
   char      pident[40],
             glberr[60],
             tstmsg[900],
             funcid[80],
             dumch[400];
}         globch_;


/**************************************************************************
     name_file

     create a file name based on the input integers (usually the Fortran
     LUN) and the name of the currently running program


**************************************************************************/
#ifdef NO_PROTO
name_file (logical_unit, archive_id, type, string)
   int      *logical_unit,
            *archive_id;
   char     *type,
            *string;
#else
name_file (int *logical_unit, int *archive_id, char *type, char *string)
#endif
{
   char     *start,
            *finish;
   char     *cur,
            *ptr;
   start = strchr (globch_.pident, '/');
   start++;
   finish = strchr (start, ' ');

   cur = string; 
   *cur = 'p'; 
   cur++;

   for (ptr = start; ptr != finish; ptr++, cur++)
      *cur = *ptr;

   if (archive_id == 0)
      sprintf (cur, ".%s\0", type);
   else
      sprintf (cur, "-%d-%d.%s\0", *logical_unit, *archive_id, type);
}
