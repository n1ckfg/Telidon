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
#include <phigs/phg.h>
#include <phigs/private/phgP.h>
#include <phigs/ws.h>
#include <phigs/ws_inp.h>
#include <phigs/private/wsglP.h>
#include <phigs/css.h>
#include <phigs/alloc.h>

#define HASH_SIZE 10

/*******************************************************************************
 * phg_create_table
 *
 * DESCR:	Helper function to create a hash table
 * RETURNS:	Non-zero on success
 */

static int phg_create_table(
    Hash_table *htab,
    Pint *err,
    int hash_size
    )
{
    int status;

    *htab = phg_htab_create(hash_size);
    if (*htab == NULL) {
        *err = ERR900;
        status = 0;
    }
    else {
        status = 1;
    }

    return status;
}

/*******************************************************************************
 * phg_wsb_create_LUTs
 *
 * DESCR:	Create workstation lookup tables
 * RETURNS:	Non-zero on success
 */

int phg_wsb_create_LUTs(
    Ws *ws
    )
{
    Pint err;
    int status = 1;
    Ws_output_ws *ows = &ws->out_ws;

    if (!phg_create_table(&ows->htab.line, &err, HASH_SIZE)) {
        status = 0;
        goto end;
    }

    if (!phg_create_table(&ows->htab.marker, &err, HASH_SIZE)) {
        status = 0;
        goto end;
    }

    if (!phg_create_table(&ows->htab.text, &err, HASH_SIZE)) {
        status = 0;
        goto end;
    }

    if (!phg_create_table(&ows->htab.interior, &err, HASH_SIZE)) {
        status = 0;
        goto end;
    }

    if (!phg_create_table(&ows->htab.edge, &err, HASH_SIZE)) {
        status = 0;
        goto end;
    }

    if (!phg_create_table(&ows->htab.colour, &err, 100)) {
        status = 0;
        goto end;
    }

    if (!phg_create_table(&ows->htab.view, &err, 20)) {
        status = 0;
        goto end;
    }

    if (!phg_create_table(&ows->htab.light_source, &err, HASH_SIZE)) {
        status = 0;
        goto end;
    }

end:

    if (!status) {
       phg_wsb_destroy_LUTs(ws);
    }

    return status;
}

/*******************************************************************************
 * phg_wsb_destroy_LUTs
 *
 * DESCR:	Destroy workstation lookup tables
 * RETURNS:	N/A
 */

void phg_wsb_destroy_LUTs(
    Ws *ws
    )
{
    Ws_output_ws *ows = &ws->out_ws;

    if (ows->htab.line)
       phg_htab_destroy(ows->htab.line, (void(*)())NULL);
    if (ows->htab.marker)
       phg_htab_destroy(ows->htab.marker, (void(*)())NULL);
    if (ows->htab.text)
       phg_htab_destroy(ows->htab.text, (void(*)())NULL);
    if (ows->htab.interior)
       phg_htab_destroy(ows->htab.interior, (void(*)())NULL);
    if (ows->htab.edge)
       phg_htab_destroy(ows->htab.edge, (void(*)())NULL);
    if (ows->htab.colour)
       phg_htab_destroy(ows->htab.colour, (void(*)())NULL);
    if (ows->htab.view)
       phg_htab_destroy(ows->htab.view, (void(*)())NULL);
    if (ows->htab.light_source)
       phg_htab_destroy(ows->htab.light_source, (void(*)())NULL);
}

/*******************************************************************************
 * phg_wsb_set_LUT_entry
 *
 * DESCR:	Set workstation table entry
 * RETURNS:	N/A
 */

void phg_wsb_set_LUT_entry(
    Ws *ws,
    Phg_args_rep_type type,
    Phg_args_rep_data *rep,
    Pgcolr *gcolr
    )
{
    caddr_t data;
    Ws_output_ws *ows = &ws->out_ws;

    switch(type) {
        case PHG_ARGS_LNREP:
#ifdef DEBUG
            printf("Set lnrep %d\n", rep->index);
#endif
            data = malloc(sizeof(Pline_bundle_plus));
            if (data != NULL) {
                memset(data, 0, sizeof(Pline_bundle_plus));
                ((Pline_bundle_plus *) data)->type = rep->bundl.lnrep.type;
                ((Pline_bundle_plus *) data)->width = rep->bundl.lnrep.width;
                ((Pline_bundle_plus *) data)->colr.type = PINDIRECT;
                ((Pline_bundle_plus *) data)->colr.val.ind =
                    rep->bundl.lnrep.colr_ind;
                if (!phg_htab_add_entry(ows->htab.line, rep->index, data)) {
                    ERR_BUF(ws->erh, ERR900);
                }
            }
            else {
                ERR_BUF(ws->erh, ERR900);
            }
            break;

        case PHG_ARGS_EXTLNREP:
#ifdef DEBUG
            printf("Set extlnrep: %d\n", rep->index);
#endif
            data = malloc(sizeof(Pline_bundle_plus));
            if (data != NULL) {
                memcpy(data, &rep->bundl.extlnrep, sizeof(Pline_bundle_plus));
                if (!phg_htab_add_entry(ows->htab.line, rep->index, data)) {
                    ERR_BUF(ws->erh, ERR900);
                }
            }
            else {
                ERR_BUF(ws->erh, ERR900);
            }
            break;

        case PHG_ARGS_MKREP:
#ifdef DEBUG
            printf("Set mkrep: %d\n", rep->index);
#endif
            data = malloc(sizeof(Pmarker_bundle_plus));
            if (data != NULL) {
                memset(data, 0, sizeof(Pmarker_bundle_plus));
                ((Pmarker_bundle_plus *) data)->type = rep->bundl.mkrep.type;
                ((Pmarker_bundle_plus *) data)->size = rep->bundl.mkrep.size;
                ((Pmarker_bundle_plus *) data)->colr.type = PINDIRECT;
                ((Pmarker_bundle_plus *) data)->colr.val.ind =
                    rep->bundl.mkrep.colr_ind;
                if (!phg_htab_add_entry(ows->htab.marker, rep->index, data)) {
                    ERR_BUF(ws->erh, ERR900);
                }
            }
            else {
                ERR_BUF(ws->erh, ERR900);
            }
            break;

        case PHG_ARGS_EXTMKREP:
#ifdef DEBUG
            printf("Set extmkrep: %d\n", rep->index);
#endif
            data = malloc(sizeof(Pmarker_bundle_plus));
            if (data != NULL) {
                memcpy(data, &rep->bundl.extmkrep, sizeof(Pmarker_bundle_plus));
                if (!phg_htab_add_entry(ows->htab.marker, rep->index, data)) {
                    ERR_BUF(ws->erh, ERR900);
                }
            }
            else {
                ERR_BUF(ws->erh, ERR900);
            }
            break;

        case PHG_ARGS_TXREP:
#ifdef DEBUG
            printf("Set txrep: %d\n", rep->index);
#endif
            data = malloc(sizeof(Ptext_bundle_plus));
            if (data != NULL) {
                memset(data, 0, sizeof(Ptext_bundle_plus));
                ((Ptext_bundle_plus *) data)->font = rep->bundl.txrep.font;
                ((Ptext_bundle_plus *) data)->colr.type = PINDIRECT;
                ((Ptext_bundle_plus *) data)->colr.val.ind =
                    rep->bundl.txrep.colr_ind;
                if (!phg_htab_add_entry(ows->htab.text, rep->index, data)) {
                    ERR_BUF(ws->erh, ERR900);
                }
            }
            else {
                ERR_BUF(ws->erh, ERR900);
            }
            break;

        case PHG_ARGS_EXTTXREP:
#ifdef DEBUG
            printf("Set exttxrep: %d\n", rep->index);
#endif
            data = malloc(sizeof(Ptext_bundle_plus));
            if (data != NULL) {
                memcpy(data, &rep->bundl.exttxrep, sizeof(Ptext_bundle_plus));
                if (!phg_htab_add_entry(ows->htab.text, rep->index, data)) {
                    ERR_BUF(ws->erh, ERR900);
                }
            }
            else {
                ERR_BUF(ws->erh, ERR900);
            }
            break;

        case PHG_ARGS_INTERREP:
#ifdef DEBUG
            printf("Set interrep: %d\n", rep->index);
#endif
            data = malloc(sizeof(Pint_bundle_plus));
            if (data != NULL) {
                memset(data, 0, sizeof(Pint_bundle_plus));
                ((Pint_bundle_plus *) data)->style = rep->bundl.interrep.style;
                ((Pint_bundle_plus *) data)->style_ind =
                    rep->bundl.interrep.style_ind;
                ((Pint_bundle_plus *) data)->colr.type = PINDIRECT;
                ((Pint_bundle_plus *) data)->colr.val.ind =
                    rep->bundl.interrep.colr_ind;
                if (!phg_htab_add_entry(ows->htab.interior,
                                        rep->index,
                                        data)) {
                    ERR_BUF(ws->erh, ERR900);
                }
            }
            else {
                ERR_BUF(ws->erh, ERR900);
            }
            break;

        case PHG_ARGS_EXTINTERREP:
#ifdef DEBUG
            printf("Set extinterrep: %d\n", rep->index);
#endif
            data = malloc(sizeof(Pint_bundle_plus));
            if (data != NULL) {
                memcpy(data,
                       &rep->bundl.extinterrep,
                       sizeof(Pint_bundle_plus));
                if (!phg_htab_add_entry(ows->htab.interior,
                                        rep->index,
                                        data)) {
                    ERR_BUF(ws->erh, ERR900);
                }
            }
            else {
                ERR_BUF(ws->erh, ERR900);
            }
            break;

        case PHG_ARGS_EDGEREP:
#ifdef DEBUG
            printf("Set edgerep: %d\n", rep->index);
#endif
            data = malloc(sizeof(Pedge_bundle_plus));
            if (data != NULL) {
                memset(data, 0, sizeof(Pedge_bundle_plus));
                ((Pedge_bundle_plus *) data)->flag = rep->bundl.edgerep.flag;
                ((Pedge_bundle_plus *) data)->type = rep->bundl.edgerep.type;
                ((Pedge_bundle_plus *) data)->width = rep->bundl.edgerep.width;
                ((Pedge_bundle_plus *) data)->colr.type = PINDIRECT;
                ((Pedge_bundle_plus *) data)->colr.val.ind =
                    rep->bundl.edgerep.colr_ind;
                if (!phg_htab_add_entry(ows->htab.edge, rep->index, data)) {
                    ERR_BUF(ws->erh, ERR900);
                }
            }
            else {
                ERR_BUF(ws->erh, ERR900);
            }
            break;

        case PHG_ARGS_EXTEDGEREP:
#ifdef DEBUG
            printf("Set extedgerep: %d\n", rep->index);
#endif
            data = malloc(sizeof(Pedge_bundle_plus));
            if (data != NULL) {
                memcpy(data, &rep->bundl.extedgerep, sizeof(Pedge_bundle_plus));
                if (!phg_htab_add_entry(ows->htab.edge, rep->index, data)) {
                    ERR_BUF(ws->erh, ERR900);
                }
            }
            else {
                ERR_BUF(ws->erh, ERR900);
            }
            break;

        case PHG_ARGS_COREP:
#ifdef DEBUG
            printf("Set corep: %d\n", rep->index);
#endif
            data = malloc(sizeof(Pgcolr));
            if (data != NULL) {
                memcpy(data, gcolr, sizeof(Pgcolr));
                if (!phg_htab_add_entry(ows->htab.colour, rep->index, data)) {
                    ERR_BUF(ws->erh, ERR900);
                }
            }
            else {
                ERR_BUF(ws->erh, ERR900);
            }
            break;

        case PHG_ARGS_VIEWREP:
#ifdef DEBUG
            printf("Set view: %d\n", rep->index);
            phg_mat_print(rep->bundl.viewrep.ori_matrix);
            printf("\n");
            phg_mat_print(rep->bundl.viewrep.map_matrix);
#endif
            data = malloc(sizeof(Pview_rep3));
            if (data != NULL) {
                memcpy(data, &rep->bundl.viewrep, sizeof(Pview_rep3));
                if (!phg_htab_add_entry(ows->htab.view, rep->index, data)) {
                    ERR_BUF(ws->erh, ERR900);
                }
            }
            else {
                ERR_BUF(ws->erh, ERR900);
            }
            break;

        case PHG_ARGS_LIGHTSRCREP:
#ifdef DEBUG
            printf("Set lightsrcrep: %d\n", rep->index);
#endif
            data = malloc(sizeof(Plight_src_bundle));
            if (data != NULL) {
                memcpy(data,
                       &rep->bundl.lightsrcrep,
                       sizeof(Plight_src_bundle));
                if (!phg_htab_add_entry(ows->htab.light_source,
                                        rep->index,
                                        data)) {
                    ERR_BUF(ws->erh, ERR900);
                }
            }
            else {
                ERR_BUF(ws->erh, ERR900);
            }
            break;

        default:
            break;
    }
}

/*******************************************************************************
 * phg_wsb_inq_LUT_entry
 *
 * DESCR:	Get workstation table entry
 * RETURNS:	N/A
 */

void phg_wsb_inq_LUT_entry(
    Ws *ws,
    Pint index,
    Pinq_type type,
    Phg_args_rep_type rep_type,
    Phg_ret *ret,
    Pgcolr *gcolr,
    Pview_rep3 *vrep
    )
{
    caddr_t data;
    Phg_ret_rep *rep = &ret->data.rep;
    Ws_output_ws *ows = &ws->out_ws;

    switch(rep_type) {
        case PHG_ARGS_LNREP:
        case PHG_ARGS_EXTLNREP:
#ifdef DEBUG
            printf("Inq line: %d\n", index);
#endif
            if (!phg_htab_get_entry(ows->htab.line, index, &data)) {
                ret->err = ERR101;
            }
            else {
                memcpy(&rep->extlnrep, data, sizeof(Pline_bundle_plus));
                ret->err = 0;
            }
            break;

        case PHG_ARGS_MKREP:
        case PHG_ARGS_EXTMKREP:
#ifdef DEBUG
            printf("Inq marker: %d\n", index);
#endif
            if (!phg_htab_get_entry(ows->htab.marker, index, &data)) {
                ret->err = ERR101;
            }
            else {
                memcpy(&rep->extmkrep, data, sizeof(Pmarker_bundle_plus));
                ret->err = 0;
            }
            break;

        case PHG_ARGS_TXREP:
        case PHG_ARGS_EXTTXREP:
#ifdef DEBUG
            printf("Inq text: %d\n", index);
#endif
            if (!phg_htab_get_entry(ows->htab.text, index, &data)) {
                ret->err = ERR101;
            }
            else {
                memcpy(&rep->exttxrep, data, sizeof(Ptext_bundle_plus));
                ret->err = 0;
            }
            break;

        case PHG_ARGS_INTERREP:
        case PHG_ARGS_EXTINTERREP:
#ifdef DEBUG
            printf("Inq interior: %d\n", index);
#endif
            if (!phg_htab_get_entry(ows->htab.interior, index, &data)) {
                ret->err = ERR101;
            }
            else {
                memcpy(&rep->extinterrep, data, sizeof(Pint_bundle_plus));
                ret->err = 0;
            }
            break;

        case PHG_ARGS_EDGEREP:
        case PHG_ARGS_EXTEDGEREP:
#ifdef DEBUG
            printf("Inq edge: %d\n", index);
#endif
            if (!phg_htab_get_entry(ows->htab.edge, index, &data)) {
                ret->err = ERR101;
            }
            else {
                memcpy(&rep->extedgerep, data, sizeof(Pedge_bundle_plus));
                ret->err = 0;
            }
            break;

        case PHG_ARGS_COREP:
#ifdef DEBUG
            printf("Inq colour: %d\n", index);
#endif
            if (!phg_htab_get_entry(ows->htab.colour, index, &data)) {
                ret->err = ERR101;
            }
            else {
                memcpy(gcolr, data, sizeof(Pgcolr));
                ret->err = 0;
            }
            break;

        case PHG_ARGS_VIEWREP:
#ifdef DEBUG
            printf("Inq view: %d\n", index);
#endif
            if (!phg_htab_get_entry(ows->htab.view, index, &data)) {
#ifdef DEBUG
                printf("No such view\n");
#endif
                ret->err = ERR101;
            }
            else {
                memcpy(vrep, data, sizeof(Pview_rep3));
#ifdef DEBUG
                printf("Got view:\n");
                phg_mat_print(vrep->ori_matrix);
                printf("\n");
                phg_mat_print(vrep->map_matrix);
#endif
                ret->err = 0;
            }
            break;

        case PHG_ARGS_LIGHTSRCREP:
#ifdef DEBUG
            printf("Inq light source: %d\n", index);
#endif
            if (!phg_htab_get_entry(ows->htab.light_source, index, &data)) {
                ret->err = ERR101;
            }
            else {
                memcpy(&rep->lightsrcrep, data, sizeof(Plight_src_bundle));
                ret->err = 0;
            }
            break;

        default:
            break;
    }
}

/*******************************************************************************
 * phg_wsb_inq_LUT_indices
 *
 * DESCR:	Get workstation indices in table
 * RETURNS:	N/A
 */

void phg_wsb_inq_LUT_indices(
    Ws *ws,
    Phg_args_rep_type rep_type,
    Phg_ret *ret
    )
{
    Hash_table htab;
    int count;

    switch(rep_type) {
        case PHG_ARGS_LNREP:
        case PHG_ARGS_EXTLNREP:
            htab = ws->out_ws.htab.line;
            break;

        case PHG_ARGS_MKREP:
        case PHG_ARGS_EXTMKREP:
            htab = ws->out_ws.htab.marker;
            break;

        case PHG_ARGS_TXREP:
        case PHG_ARGS_EXTTXREP:
            htab = ws->out_ws.htab.text;
            break;

        case PHG_ARGS_INTERREP:
        case PHG_ARGS_EXTINTERREP:
            htab = ws->out_ws.htab.interior;
            break;

        case PHG_ARGS_EDGEREP:
        case PHG_ARGS_EXTEDGEREP:
            htab = ws->out_ws.htab.edge;
            break;

        case PHG_ARGS_COREP:
            htab = ws->out_ws.htab.colour;
            break;

        case PHG_ARGS_VIEWREP:
            htab = ws->out_ws.htab.view;
            break;

        case PHG_ARGS_LIGHTSRCREP:
            htab = ws->out_ws.htab.light_source;
            break;

        default:
            ret->data.int_list.num_ints = 0;
            return;
    }

    count = phg_htab_num_entries(htab);
    if (count <= 0) {
        ret->data.int_list.num_ints = 0;
        ret->err = 0;
    }
    else if (PHG_SCRATCH_SPACE(&ws->scratch, count * sizeof(Pint))) {
        ret->data.int_list.ints = (Pint *) ws->scratch.buf;
        ret->data.int_list.num_ints =
            phg_htab_get_keys(htab, ret->data.int_list.ints);
        ret->err = 0;
    }
    else {
        ret->data.int_list.num_ints = 0;
        ret->err = ERR900;
    }
}

/*******************************************************************************
 * phg_wsb_set_name_set
 *
 * DESCR:	Set filter name set
 * RETURNS:	N/A
 */

void phg_wsb_set_name_set(
   Ws *ws,
   Phg_args_flt_type type,
   Pint dev_id,
   Pint_list *incl_set,
   Pint_list *excl_set
   )
{
   Ws_inp_pick *pick;
   Ws_output_ws *ows = &ws->out_ws;

   switch (type) {
      case PHG_ARGS_FLT_INVIS:
         phg_nset_names_set(ows->nset.invis_incl,
                            incl_set->num_ints,
                            incl_set->ints);
         phg_nset_names_set(ows->nset.invis_excl,
                            excl_set->num_ints,
                            excl_set->ints);
         wsgl_set_filter(ws,
                         PHG_ARGS_FLT_INVIS,
                         ows->nset.invis_incl,
                         ows->nset.invis_excl);
         break;

      case PHG_ARGS_FLT_PICK:
         pick = &ws->in_ws.devs.pick[dev_id - 1];
         phg_nset_names_set(pick->filter.incl,
                            incl_set->num_ints,
                            incl_set->ints);
         phg_nset_names_set(pick->filter.excl,
                            excl_set->num_ints,
                            excl_set->ints);
         break;

      default:
         /* TODO: Other filter types */
         break;
   }
}

