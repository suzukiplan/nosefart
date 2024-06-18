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
** types.h
**
** Data type definitions
** $Id: types.h,v 1.1 2003/04/08 20:46:46 ben Exp $
*/

#ifndef _TYPES_H_
#define _TYPES_H_

/* Define this if running on little-endian (x86) systems */

#ifndef DCPLAYA
# define  HOST_LITTLE_ENDIAN
#endif

#ifdef __GNUC__
#define  INLINE      static inline
#elif defined(WIN32)
#define  INLINE      static __inline
#else /* crapintosh? */
#define  INLINE      static
#endif

/* These should be changed depending on the platform */
#include <stdint.h>
typedef  int8_t   int8;
typedef  int16_t  int16;
typedef  int32_t  int32;
typedef  uint8_t  uint8;
typedef  uint16_t uint16;
typedef  uint32_t uint32;
typedef  uint8_t  boolean;

#ifndef  TRUE
#define  TRUE     1
#endif
#ifndef  FALSE
#define  FALSE    0
#endif

#ifndef  NULL
#define  NULL     ((void *) 0)
#endif

#include <stdlib.h>
#define  ASSERT(expr)
#define  ASSERT_MSG(msg)

#endif /* _TYPES_H_ */

/*
** $Log: types.h,v $
** Revision 1.1  2003/04/08 20:46:46  ben
** add new input for NES music file.
**
** Revision 1.7  2000/07/04 04:46:44  matt
** moved INLINE define from osd.h
**
** Revision 1.6  2000/06/09 15:12:25  matt
** initial revision
**
*/
