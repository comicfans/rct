/*
 * =====================================================================================
 *
 *       Filename:  Win32Helper.h
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  2016/9/18 21:44:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "rct/rct-config.h"

#ifndef WIN32HELPER_H_IYWOUQJ8
#define WIN32HELPER_H_IYWOUQJ8

#ifdef HAVE_STRINGS
#include <strings.h>
#else
#define strcasecmp _stricmp
#define strncasecmp _strnicmp
#endif


#ifdef HAVE_LOCALTIME_R
#include <time.h>
#else
#include <time.h>
#define localtime_r(TM,TIME_T) localtime_s(TIME,TIM)
#endif

#ifdef __GNUC__
#define RCT_PRINTF_WARNING(fmt, firstarg) __attribute__ ((__format__ (__printf__, fmt, firstarg)))
#else
#define RCT_PRINTF_WARNING(fmt, firstarg) 
#endif


#endif /* end of include guard: WIN32HELPER_H_IYWOUQJ8 */


