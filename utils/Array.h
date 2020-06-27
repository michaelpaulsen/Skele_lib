#pragma once
#include <cassert>
namespace Skele_lib {
	namespace Utils {
		/*
		*	the class Array is a c++ Javascript like array implementation
		*/
		template<typename t> class Array {
			t* data;
			int items;
		public:
			int length;
			Array(int length) {
				data = static_cast<t*>(malloc(sizeof(t) * length));
				assert(this->data != nullptr);
				this->length = length;
			}
			~Array()
			{
				free(this->data);
			}

			void Push(t newLast) {
				if (this->items == this->length) {
					this->length *= 2;
					this->data = static_cast<t*>(realloc(this->data, sizeof(t) * length));
					assert(this->data != nullptr);
				}
				this->items++;
				this->data[this->items] = newLast;
			}
			t Pop() {
				t temp = data[this->items];
				this->items--;
				return temp;
			}
			t operator [](int i) {
				return this->data[i];
			}
		};
	}
}