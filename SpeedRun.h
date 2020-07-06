#pragma once
#include "Duration.h"
#include <memory>
namespace Skele_lib{
	struct Split
	{
		char* name;
		Duration dur;
		Split(char* name, Duration dur) {
			this->name = name;
			this->dur = dur;
		}
		~Split()
		{
			free(this->name);
		}

	};
	struct SpeedRun {
		Split* splits;
		int len;
		int items;
		SpeedRun(int num) {
			// make a array of size num or 1 ( if num is 0) 
			this->splits = static_cast<Split*>(malloc(sizeof(Split) * (num | 0b01)));
			///set the length of the array to 
			this->len = num | 0b01;
		}
		~SpeedRun()
		{
			free(this->splits);
		}
		/** JS like array implemetation */
	};
}