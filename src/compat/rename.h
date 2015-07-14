/*
 * Copyright (C) 2004 CreepLord (creeplord@pvpgn.org)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
#ifndef INCLUDED_RENAME_PROTOS
#define INCLUDED_RENAME_PROTOS

#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif
#include "compat/access.h"

static inline int p_rename(const char * old, const char * new_)
{
#ifdef WIN32
    if(access(new_, F_OK) == 0)
        if(remove(new_) < 0)
            return -1;
#endif
    return rename(old, new_);
}
		
#endif