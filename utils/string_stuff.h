namespace Skele_lib {
	namespace Utils {
		namespace string{ 
			const char* GetDayOfWeek(size_t dayindex, bool sub1 = false) {
    				const char* days[7] = {
     					"sunday",
        				"monday",
        				"tusday",
        				"wednesday",
        				"thursday",
        				"friday",
        				"saturday"
    				};
    				return days[(dayindex - sub1)];
			}
			size_t wcscmpcs(const PWCHAR wide, const c_str thin) {
				auto nob = (wcslen(wide) > strlen(thin) ? wcslen(wide) : strlen(thin))+1; 
				PWCHAR wb = (PWCHAR)malloc(nob * sizeof(WCHAR));
				c_str  tb = (c_str)malloc(nob); 
				wcscpy_s(wb, nob, wide);
				strcpy_s(tb, nob, thin); 
				size_t i; 
				for (size_t i = 0; i < nob; i++){
					if (wb[i] != (short)tb[i]) {
						return wb[i] - (short)tb[i];
					}
				}
				return 0; 
			}
		}
	}
}