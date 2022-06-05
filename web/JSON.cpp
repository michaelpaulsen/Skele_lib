#include <string> 
#include <iostream> 
#include "./web.cpp" 
namespace Skele_lib {
	namespace Web {
		namespace JSON {
			
		
			std::string AddElementToJSONArray(std::string value, bool printComma = true) {
				return  "\"" + value + "\"" += printComma ? "," : "";
			}
			void printArray(FILE* f, std::string key, std::string value) {
				//this is basicly the same as print json but it dosn't use a opening quotation mark 
				fprintf(f, "\"%s\": %s", key, value); 
			}
			int printObjectWithName(FILE* f, std::string key, int tabs = 1) {
				printTabs(f,tabs); 
				fprintf(f, "\"%s\": {"); 
				return ++tabs;
			}
			void printJsonProperty(FILE* f, std::string key, std::string value, int tabs = 1, bool printComma = true) {
				printTabs(f, tabs); 
				fprintf(f, "\"%s\":\"%s\"%s\n", key.c_str(), value.c_str(), printComma ? "," : "");
			}
		}
	}
}
