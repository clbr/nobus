/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*- */
/* dbus-macros.h generic macros
 *
 * Copyright (C) 2002 Red Hat Inc.
 *
 * Licensed under the Academic Free License version 2.1
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */
#if !defined (DBUS_INSIDE_DBUS_H) && !defined (DBUS_COMPILATION)
#error "Only <dbus/dbus.h> can be included directly, this file may disappear or change contents."
#endif

#ifndef DBUS_MACROS_H
#define DBUS_MACROS_H

#ifdef __cplusplus
# define DBUS_BEGIN_DECLS extern "C" {
# define DBUS_END_DECLS }
#else
# define DBUS_BEGIN_DECLS
# define DBUS_END_DECLS
#endif

#ifndef TRUE
# define TRUE 1
#endif
#ifndef FALSE
# define FALSE 0
#endif

#ifndef NULL
# ifdef __cplusplus
# define NULL (0L)
# else /* !__cplusplus */
# define NULL ((void*) 0)
# endif /* !__cplusplus */
#endif

#if __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 1)
# define DBUS_DEPRECATED __attribute__ ((__deprecated__))
#else
# define DBUS_DEPRECATED
#endif

#if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 8)
# define _DBUS_GNUC_EXTENSION __extension__
#else
# define _DBUS_GNUC_EXTENSION
#endif

#if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ > 4)
#define _DBUS_GNUC_PRINTF( format_idx, arg_idx ) \
 __attribute__((__format__ (__printf__, format_idx, arg_idx)))
#define _DBUS_GNUC_NORETURN \
 __attribute__((__noreturn__))
#else /* !__GNUC__ */
#define _DBUS_GNUC_PRINTF( format_idx, arg_idx )
#define _DBUS_GNUC_NORETURN
#endif /* !__GNUC__ */

#if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 96)
#define DBUS_MALLOC __attribute__((__malloc__))
#else
#define DBUS_MALLOC
#endif

#if (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3)
#define DBUS_ALLOC_SIZE(x) __attribute__((__alloc_size__(x)))
#define DBUS_ALLOC_SIZE2(x,y) __attribute__((__alloc_size__(x,y)))
#else
#define DBUS_ALLOC_SIZE(x)
#define DBUS_ALLOC_SIZE2(x,y)
#endif


#endif /* DBUS_MACROS_H */
