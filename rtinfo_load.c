/*
 * librtinfo is a small library for Linux for retreive some system status monitor
 * Copyright (C) 2012  DANIEL Maxime <root@maxux.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "misc.h"
#include "rtinfo.h"

rtinfo_loadagv_t * rtinfo_get_loadavg(rtinfo_loadagv_t *load) {
	char data[32];

	/* Init Load */
	load->load[0] = -1;
	load->load[1] = -1;
	load->load[2] = -1;
	
	if(!file_get(LOADAVG_FILE, data, sizeof(data)))
		return NULL;
	
	sscanf(data, "%f %f %f", &load->load[0], &load->load[1], &load->load[2]);
	
	return load;
}