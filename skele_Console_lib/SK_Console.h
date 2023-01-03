#ifndef SK_CONSOLE
	#define SK_CONSOLE
	#define stocs(t) t.c_str() 
	#ifdef  WIN
		#include "SK_ConsoleWIN.h"
	#else
		#include "SK_ConsoleUNIX.h"
	#endif 
#endif 
