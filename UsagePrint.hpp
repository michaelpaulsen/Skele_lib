#pragma once
#include "./utils/Array.h"; 
namespace Skele_lib::UsageLib {
	class Param {
		char* name; 
		bool Optional; 
		Param() {
			name = ""; 
			Optional = false; 
		}
		Param(char* n, bool opt = false) {
			name = n; 
			Optional = opt; 
		}
		Param(const char* n, bool opt = false) {
			name = n; 
			Optional = opt; 
		}
		char* displayParamiter() {
			if (this->Optional) {
				return '[' + this->name + ']'; 
			}
			return '<' + this->name + '>'; 
		}
	};
	class Command {
		Skele_lib::Utils::Array<Param> paramaters;

	};
}