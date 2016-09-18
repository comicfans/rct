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
struct tm *localtime_r(const time_t *timep,struct tm* result){
    localtime_s(result,timep);
    return result;
}

struct tm *gmtime_r(const time_t *timep,struct tm* result){
    gmtime_s(result,timep);
    return result;
}

#endif

#ifdef __GNUC__
#define RCT_PRINTF_WARNING(fmt, firstarg) __attribute__ ((__format__ (__printf__, fmt, firstarg)))
#else
#define RCT_PRINTF_WARNING(fmt, firstarg) 
#endif

#ifdef HAVE_GETOPT
#include <getopt.h>
#else
#include "getopt.h"
#endif

#endif /* end of include guard: WIN32HELPER_H_IYWOUQJ8 */


