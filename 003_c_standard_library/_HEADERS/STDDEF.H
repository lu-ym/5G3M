/* stddef.h standard header */
#ifndef _STDDEF
#define _STDDEF
#ifndef _YVALS
#include <yvals.h>
#endif
		/* macros */
		/*offsetof, 利用把0设置成T的指针地址，其成员的位置就是相对位置offset*/
#define NULL	_NULL
#define offsetof(T, member)	((_Sizet)&((T *)0)->member)	
		/* type definitions */
#ifndef _SIZET
#define _SIZET
typedef _Sizet size_t;
#endif
#ifndef _WCHART
#define _WCHART
typedef _Wchart wchar_t;
#endif
typedef _Ptrdifft ptrdiff_t;
#endif
