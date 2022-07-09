#ifndef SKELE_JSON_WRITER
#define SKELE_JSON_WRITER

#include <string> 
#include <iostream> 
#include "./web.cpp" 
namespace Skele_lib {
	namespace Web {
		namespace JSON {
			std::string AddElementToJSONArray(std::string value, bool printComma = true) {
				return  "\"" + value + "\"" += (printComma ? "," : "");
			}
			int printObjectWithName(FILE* f, std::string key, int tabs = 1) {
				printTabs(f,tabs); 
				fprintf(f, "\"%s\": {\n", key.c_str()); 
				return ++tabs;
			}
			void printJsonProperty(FILE* f, std::string key, std::string value, int tabs = 1, bool printComma = true) {
				printTabs(f, tabs); 
				fprintf(f, "\"%s\":\"%s\"%s\n", key.c_str(), value.c_str(), printComma ? "," : "");
			}
		}
	}
}
#endif