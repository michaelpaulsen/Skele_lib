#ifndef SK_CONSOLE
	#define SK_CONSOLE
	#define use_va_list(t) va_list valist;\
			va_start(valist, fmnt);\ 
			t\
			va_end(valist)
	#define stocs(t) t.c_str() 
	#ifdef  WIN
		#include "SK_ConsoleWIN.h"
	#else
		#include "SK_ConsoleUNIX.h"
	#endif 
#endif 
