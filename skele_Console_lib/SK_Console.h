#ifndef SK_CONSOLE
	#define SK_CONSOLE
	#include <stdarg.h>

	#define stocs(t) t.c_str() 
	#ifdef  WIN
		#include "SK_ConsoleWIN.h"
		#define use_va_list(t) va_list valist; va_start(valist, fmnt); t va_end(valist)
	#else
		#include "SK_ConsoleUNIX.h"
		#define use_va_list(t) va_list valist;\
			va_start(valist, fmnt);\ 
			t\
			va_end(valist)
	#endif 
#endif 
