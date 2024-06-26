/*
** Nofrendo (c) 1998-2000 Matthew Conte (matt@conte.com)
**
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of version 2 of the GNU Library General
** Public License as published by the Free Software Foundation.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Library General Public License for more details.  To obtain a
** copy of the GNU Library General Public License, write to the Free
** Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
**
** Any permitted reproduction of these routines, in whole or in part,
** must bear this legend.
**
**
** osd.h
**
** O/S dependent routine defintions (must be customized)
** $Id: osd.h,v 1.1 2003/04/08 20:46:46 ben Exp $
*/

#ifndef _OSD_H_
#define _OSD_H_

#if 1
#define __PACKED__
#if WIN32
#define PATH_SEP '\\'
#else
#define PATH_SEP '/'
#endif
#else
#ifdef __GNUC__
#define __PACKED__ __attribute__((packed))
#define PATH_SEP '/'
#ifdef __DJGPP__
#include "dos_ints.h"
#include <dpmi.h>
#endif
#elif defined(WIN32)
#define __PACKED__
#define PATH_SEP '\\'
#else /* crapintosh? */
#define __PACKED__
#define PATH_SEP ':'
#endif
#endif

extern void osd_loginit(void);
extern void osd_logshutdown(void);
extern void osd_logprint(const char* string);

extern int osd_startsound(void (*playfunc)(void* buffer, int size));
extern int osd_getsoundbps(void);
extern int osd_getsamplerate(void);

#endif /* _OSD_H_ */

/*
** $Log: osd.h,v $
** Revision 1.1  2003/04/08 20:46:46  ben
** add new input for NES music file.
**
** Revision 1.7  2000/07/04 04:45:33  matt
** moved INLINE define into types.h
**
** Revision 1.6  2000/06/29 16:06:18  neil
** Wrapped DOS-specific headers in an ifdef
**
** Revision 1.5  2000/06/09 15:12:25  matt
** initial revision
**
*/
