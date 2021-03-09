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

#ifndef _ftn_h
#define _ftn_h

#define FTN_NAME(NAME)                   NAME##_

#define FTN_SUBROUTINE(NAME)             void \
                                         FTN_NAME(NAME)

#define FTN_INTEGER(NAME)                int *NAME
#define FTN_INTEGER_GET(NAME)            *NAME

#define FTN_REAL(NAME)                   float *NAME
#define FTN_REAL_GET(NAME)               *NAME

#define FTN_REAL_ARRAY(NAME)             float NAME[]
#define FTN_REAL_ARRAY_GET(NAME, INDEX)  NAME[INDEX]

#define FTN_CHARACTER(NAME)              char *NAME_str, \
                                         int NAME_len
#define FTN_CHARACTER_GET(NAME)          NAME_str
#define FTN_CHARACTER_LEN(NAME)          NAME_len

#endif /* _ftn_h */

