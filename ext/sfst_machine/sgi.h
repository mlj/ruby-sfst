
/*******************************************************************/
/*                                                                 */
/*     File: sgi.h                                                 */
/*   Author: Helmut Schmid                                         */
/*  Purpose:                                                       */
/*  Created: Thu Sep 11 15:58:25 2008                              */
/* Modified: Fri Sep 12 08:17:03 2008 (schmid)                     */
/*                                                                 */
/*******************************************************************/

#ifndef _SGI_INCLUDED
#define _SGI_INCLUDED


#ifdef SGIext

#include <ext/hash_map>
#include <ext/hash_set>
using std::hash_map;
using std::hash_set;
using std::hash;

#else

#ifdef SGI__gnu_cxx

#include <ext/hash_map>
#include <ext/hash_set>

#else

#include <backward/hash_map>
#include <backward/hash_set>

#endif

using __gnu_cxx::hash_map;
using __gnu_cxx::hash_set;
using __gnu_cxx::hash;

#endif

#endif
