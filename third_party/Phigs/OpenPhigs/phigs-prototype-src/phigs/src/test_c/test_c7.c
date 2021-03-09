/******************************************************************************
*   DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER
*
*   This file is part of Open PHIGS
*   Copyright (C) 2014 Surplus Users Ham Society
*
*   Open PHIGS is free software: you can redistribute it and/or modify
*   it under the terms of the GNU Lesser General Public License as published by
*   the Free Software Foundation, either version 2.1 of the License, or
*   (at your option) any later version.
*
*   Open PHIGS is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU Lesser General Public License for more details.
*
*   You should have received a copy of the GNU Lesser General Public License
*   along with Open PHIGS. If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <phigs/phg.h>
#include <phigs/private/phgP.h>
#include <phigs/css.h>

#define WIDTH   0.8
#define HEIGHT  0.8

#define VP_X0    0.0
#define VP_X1  500.0
#define VP_Y0    0.0
#define VP_Y1  500.0
#define WIN_X0   0.0
#define WIN_X1   1.0
#define WIN_Y0   0.0
#define WIN_Y1   1.0

int view_index = 0;

void init_checker(int num)
{
   int i;
   Pfacet_data3 fdata;
   Pfloat x = 0.0;
   Pfloat y = 0.0;
   Pfloat dx = WIDTH / (float) num;
   Pfloat dy = HEIGHT / (float) num;
   Ppoint3 *points = (Ppoint3 *) malloc(sizeof(Ppoint3) * 4 * num);
   Pfacet_vdata_list3 *vdata = (Pfacet_vdata_list3 *) malloc(
      sizeof(Pfacet_vdata_list3) * num);
   Pedge_flag *edges = (Pedge_flag *) malloc(sizeof(Pedge_flag) * 4 * num);
   Pedge_data_list *edata = malloc(sizeof(Pedge_data_list) * num);
   Ppoint3 *p;

   fdata.colr.direct.rgb.red = 0.0;
   fdata.colr.direct.rgb.green = 0.5;
   fdata.colr.direct.rgb.blue = 0.5;

   p = points;
   for (i = 0; i < 4 * num; i++) {
      edges[i] = (i % 2) ? PEDGE_OFF : PEDGE_ON;
   }

   for (i = 0; i < num; i++) {
      p[0].x = x;
      p[0].y = y;
      p[0].z = 0.0;

      p[1].x = x + dx;
      p[1].y = y;
      p[1].z = 0.0;

      p[2].x = x + dx;
      p[2].y = y + dy;
      p[2].z = 0.0;

      p[3].x = x;
      p[3].y = y + dy;
      p[3].z = 0.0;

      vdata[i].num_vertices = 4;
      vdata[i].vertex_data.points = p;

      edata[i].num_edges = 4;
      edata[i].edgedata.edges = &edges[i * 4];

      x += dx;
      y += dy;
      p = &p[4];
   }

   pset_edge_flag(PEDGE_ON);
   pset_edgewidth(2.0);
   pfill_area_set3_data(PFACET_COLOUR,
                        PEDGE_VISIBILITY,
                        PVERT_COORD,
                        PMODEL_RGB,
                        &fdata,
                        num,
                        edata,
                        vdata);

   free(vdata);
   free(points);
}

int main(int argc, char *argv[])
{
   XEvent event;
   KeySym ks;
   Plimit3 vp, win;

   if (argc > 1) {
      view_index = atoi(argv[1]);
      printf("Use view: %d\n", view_index);
   }

   popen_phigs(NULL, 0);

   popen_struct(0);
   pset_view_ind(view_index);
   init_checker(16);
   pclose_struct();

   popen_ws(0, NULL, PWST_OUTPUT_TRUE_DB);
   vp.x_min = VP_X0;
   vp.x_max = VP_X1;
   vp.y_min = VP_Y0;
   vp.y_max = VP_Y1;
   vp.z_min = 0.0;
   vp.z_max = 1.0;
   win.x_min = WIN_X0;
   win.x_max = WIN_X1;
   win.y_min = WIN_Y0;
   win.y_max = WIN_Y1;
   win.z_min = 0.0;
   win.z_max = 1.0;
   pset_ws_vp3(0, &vp);
   pset_ws_win3(0, &win);
   pset_hlhsr_mode(0, PHIGS_HLHSR_MODE_ZBUFF);

   ppost_struct(0, 0, 0);

   XSelectInput(PHG_WSID(0)->display,
                PHG_WSID(0)->drawable_id,
                ExposureMask | KeyPressMask);
   while (1) {
      XNextEvent(PHG_WSID(0)->display, &event);
      switch(event.type) {

         case Expose:
            while (XCheckTypedEvent(PHG_WSID(0)->display, Expose, &event));
            predraw_all_structs(0, PFLAG_ALWAYS);
            break;

         case KeyPress:
            ks = XLookupKeysym((XKeyEvent *) &event, 0);
            if (ks == XK_Down) {
            }
            break;

         default:
            break;
      }
   }

   pclose_ws(0);
   pclose_phigs();

   return 0;
}

