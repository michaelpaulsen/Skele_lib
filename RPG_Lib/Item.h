#pragma once
#include "skele_RPG_Lib.h" 
namespace Skele_lib {
	namespace RPG {
		class Item {
		public:
			Item() {
			};
			std::string name;
			int range = -1;
			int type;
			virtual bool use() {
				return false;
			}			// override this to implement a use 
		};
	}