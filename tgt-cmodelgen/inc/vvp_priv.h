/*
 *      Copyright (c) 2017 Programmer Woogwei (woogwei@outlook.com)
 *              ALL RIGHTS RESERVED
 *
 *    This source code is free software; you can redistribute it
 *    and/or modify it in source code form under the terms of the GNU
 *    Library General Public License as published by the Free Software
 *    Foundation; either version 2 of the License, or (at your option)
 *    any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Library General Public License for more details.
 *
 *    You should have received a copy of the GNU Library General Public
 *    License along with this program; if not, write to the Free
 *    Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *    Boston, MA 02110-1301, USA.
 */
#ifndef __vvp_priv_H
#define __vvp_priv_H

extern "C" {
# include  "ivl_target.h"
}
# include  <stdio.h>

#ifdef __MINGW32__  /* MinGW has inconsistent %p output. */
#define snprintf _snprintf
#endif

#define IMM_WID 32

extern int number_is_unknown(ivl_expr_t ex);
extern int number_is_immediate(ivl_expr_t ex, unsigned lim_wid, int negative_is_ok);
extern long get_number_immediate(ivl_expr_t ex);

#endif
