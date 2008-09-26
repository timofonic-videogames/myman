/* guess.h - feature guessing for the MyMan video game
 * Copyright 2008, Benjamin C. Wiley Sittler <bsittler@gmail.com>
 *
 *  Permission is hereby granted, free of charge, to any person
 *  obtaining a copy of this software and associated documentation
 *  files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use, copy,
 *  modify, merge, publish, distribute, sublicense, and/or sell copies
 *  of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *  DEALINGS IN THE SOFTWARE.
 */

#ifndef MYMAN_GUESS_H_INCLUDED
#define MYMAN_GUESS_H_INCLUDED 1

#if ! defined(WIN32)
#if defined(DOS) || defined(__TURBOC__)

/* some DOS C compilers do not define __MSDOS__ */
#ifndef __MSDOS__
#define __MSDOS__ 1
#endif

#endif
#endif

/* HAVE_FCNTL_H: do we have <fcntl.h>? */

#ifndef HAVE_FCNTL_H
#define HAVE_FCNTL_H 1
#endif

/* HAVE_IO_H: do we have <io.h>? */

#ifndef HAVE_IO_H
#ifdef __TURBOC__
#define HAVE_IO_H 1
#endif
#endif

#ifndef HAVE_IO_H
#define HAVE_IO_H 0
#endif

/* HAVE_IOCTL_H: do we have <ioctl.h>? */

#ifndef HAVE_IOCTL_H
#if defined(__PACIFIC__) || defined(HI_TECH_C) || defined(macintosh)
#define HAVE_IOCTL_H 1
#endif
#endif

#ifndef HAVE_IOCTL_H
#define HAVE_IOCTL_H 0
#endif

/* HAVE_LANGINFO_H: do we have <langinfo.h>? */

#ifndef HAVE_LANGINFO_H
#if ! (defined(WIN32) || defined(CPM) || defined(macintosh) || defined(__MSDOS__) || defined(atarist) || defined(__atarist__) || defined(__DMC__))
#define HAVE_LANGINFO_H 1
#endif
#endif

#ifndef HAVE_LANGINFO_H
#define HAVE_LANGINFO_H 0
#endif

/* HAVE_LOCALE_H: do we have <locale.h>? */

#ifndef HAVE_LOCALE_H
#if ! (defined(LSI_C) || defined(__PACIFIC__) || defined(HI_TECH_C) || defined(SMALL_C) || defined(__TURBOC__) || (defined(__BCC__) && defined(__MSDOS__)))
#define HAVE_LOCALE_H 1
#endif
#endif

#ifndef HAVE_LOCALE_H
#define HAVE_LOCALE_H 0
#endif

/* HAVE_PSAPI_H: do we have <psapi.h>? */

#ifndef HAVE_PSAPI_H
#ifdef WIN32
#if ! (defined(__DMC__) || defined(__TINYC__))
#define HAVE_PSAPI_H 1
#endif
#endif
#endif

#ifndef HAVE_PSAPI_H
#define HAVE_PSAPI_H 0
#endif

/* HAVE_SHLWAPI_H: do we have <shlwapi.h>? */

#ifndef HAVE_SHLWAPI_H
#ifdef WIN32
#if ! (defined(__DMC__) || defined(__TINYC__))
#define HAVE_SHLWAPI_H 1
#endif
#endif
#endif

#ifndef HAVE_SHLWAPI_H
#define HAVE_SHLWAPI_H 0
#endif

/* HAVE_STDINT_H: do we have <stdint.h>? */

#ifndef HAVE_STDINT_H
#if ! (defined(macintosh) || defined(LSI_C) || defined(__PACIFIC__) || defined(HI_TECH_C) || defined(SMALL_C) || defined(__TURBOC__) || (defined(__BCC__) && defined(__MSDOS__)))
#ifdef __atarist__
#if ((! defined(__GNUC__)) || (__GNUC__ > 2))
#define HAVE_STDINT_H 1
#else /* ! ((! defined(__GNUC__)) || (__GNUC__ > 2)) */
#define HAVE_STDINT_H 0
#endif /* ! ((! defined(__GNUC__)) || (__GNUC__ > 2)) */
#else /* ! defined(__atarist__) */
#define HAVE_STDINT_H 1
#endif /* ! defined(__atarist__) */
#endif /* ! (defined(macintosh) || defined(LSI_C) || defined(__PACIFIC__) || defined(HI_TECH_C) || defined(SMALL_C) || defined(__TURBOC__) || (defined(__BCC__) && defined(__MSDOS__))) */
#endif

#ifndef HAVE_STDINT_H
#define HAVE_STDINT_H 0
#endif

/* HAVE_SYS_H: do we have <sys.h>? */

#ifndef HAVE_SYS_H
#if defined(__PACIFIC__) || defined(HI_TECH_C)
#define HAVE_SYS_H 1
#endif
#endif

#ifndef HAVE_SYS_H
#define HAVE_SYS_H 0
#endif

/* HAVE_SYS_IOCTL_H: do we have <sys/ioctl.h>? */

#ifndef HAVE_SYS_IOCTL_H
#if ! (defined(__PACIFIC__) || defined(HI_TECH_C) || defined(macintosh) || defined(__TURBOC__) || defined(LSI_C) || defined(__BCC__) || defined(__DMC__) || defined(__WATCOMC__) || defined(__TINYC__))
#define HAVE_SYS_IOCTL_H 1
#endif
#endif

#ifndef HAVE_SYS_IOCTL_H
#define HAVE_SYS_IOCTL_H 0
#endif

/* HAVE_SYS_SOCKET_H: do we have <sys/socket.h>? */

#ifndef HAVE_SYS_SOCKET_H
#if ! (defined(__MSDOS__) || defined(CPM) || defined(macintosh))
#if ! (defined(__atarist__) && defined(__GNUC__) && (__GNUC__ == 2))
#define HAVE_SYS_SOCKET_H 1
#endif /* ! (defined(__atarist__) && defined(__GNUC__) && (__GNUC__ == 2)) */
#endif /* ! (defined(__MSDOS__) || defined(CPM) || defined(macintosh)) */
#endif

#ifndef HAVE_SYS_SOCKET_H
#define HAVE_SYS_SOCKET_H 0
#endif

/* HAVE_SYS_STAT_H: do we have <sys/stat.h>? */

#ifndef HAVE_SYS_STAT_H
#if ! (defined(__MSDOS__) || defined(CPM) || defined(macintosh))
#define HAVE_SYS_STAT_H 1
#endif
#endif

#ifndef HAVE_SYS_STAT_H
#define HAVE_SYS_STAT_H 0
#endif

/* HAVE_SYS_TIME_H: do we have <sys/time.h>? */

#ifndef HAVE_SYS_TIME_H
#if ! (defined(LSI_C) || defined(macintosh) || defined(__PACIFIC__) || defined(HI_TECH_C) || defined(SMALL_C) || defined(__TURBOC__) || defined(__WATCOMC__))
#define HAVE_SYS_TIME_H 1
#endif
#endif

#ifndef HAVE_SYS_TIME_H
#define HAVE_SYS_TIME_H 0
#endif

/* HAVE_SYS_TYPES_H: do we have <sys/types.h>? */

#ifndef HAVE_SYS_TYPES_H
#ifndef macintosh
#ifndef __PACIFIC__
#define HAVE_SYS_TYPES_H 1
#endif
#endif
#endif

#ifndef HAVE_SYS_TYPES_H
#define HAVE_SYS_TYPES_H 0
#endif

/* HAVE_TLHELP32_H: do we have <tlhelp32.h>? */

#ifndef HAVE_TLHELP32_H
#ifdef WIN32
#ifndef __TINYC__
#define HAVE_TLHELP32_H 1
#endif
#endif
#endif

#ifndef HAVE_TLHELP32_H
#define HAVE_TLHELP32_H 0
#endif

/* HAVE_UNISTD_H: do we have <unistd.h>? */

#ifndef HAVE_UNISTD_H
#if ! (defined(LSI_C) || defined(macintosh) || defined(__PACIFIC__) || defined(HI_TECH_C) || defined(SMALL_C) || defined(__TURBOC__) || (defined(WIN32) && defined(__DMC__)))
#define HAVE_UNISTD_H 1
#endif
#endif

#ifndef HAVE_UNISTD_H
#define HAVE_UNISTD_H 0
#endif

/* HAVE_UNIXIO_H: do we have <unixio.h>? */

#ifndef HAVE_UNIXIO_H
#if defined(__PACIFIC__) || defined(HI_TECH_C)
#define HAVE_UNIXIO_H 1
#endif
#endif

#ifndef HAVE_UNIXIO_H
#define HAVE_UNIXIO_H 0
#endif

/* HAVE_WCHAR_H: do we have <wchar.h>? */

#ifndef HAVE_WCHAR_H
#if ! (defined(macintosh) || defined(LSI_C) || defined(__PACIFIC__) || defined(HI_TECH_C) || defined(SMALL_C) || defined(__TURBOC__) || (defined(__BCC__) && defined(__MSDOS__)) || defined(__atarist__))
#define HAVE_WCHAR_H 1
#endif
#endif

#ifndef HAVE_WCHAR_H
#define HAVE_WCHAR_H 0
#endif

#endif /* ! defined(MYMAN_GUESS_H_INCLUDED) */