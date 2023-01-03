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
		}
	}
}