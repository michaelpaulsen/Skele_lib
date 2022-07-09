#ifndef SKELE_WEB_LIB
#define SKELE_WEB_LIB

#include <string> 
#include <iostream> 

namespace Skele_lib {
	namespace Web {
		void printTabs(FILE* f, int numtabs = 1) {
			for (int t = 0; t < numtabs; t++) {
				fprintf(f, "\t");
			}
		}
		std::string make_url_safe(std::string s) {
			std::string retval;

			for (int x = 0; x < s.length(); x++) {
				if (s[x] == ' ') {
					retval += '_';
				}
				else {
					retval += s[x];
				}
			}
			return retval;
		}
	}
}
#endif