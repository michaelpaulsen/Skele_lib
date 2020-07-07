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
			int length;
		public:
			Array(int length) {
				data = static_cast<t*>(malloc(sizeof(t) * length));
				assert(this->data != nullptr);
				this->length = length;
				this->items = 0;
			}
			~Array()
			{
				free(this->data);
			}
			int Length() {
				return this->items;
			}
			void Push(t newLast) {
				if (this->items == this->length) {
					this->length *= 2;
					this->data = static_cast<t*>(realloc(this->data, sizeof(t) * length));
					assert(this->data != nullptr);
					for (int x = this->items; x < this->length; x++) {
						this->data[x] = NULL; 
					}
				}
				this->data[this->items] = newLast;
				this->items++;
			}
			t Pop() {
				
				this->items--;
				t temp = this->operator[](this->items);
				return temp;
			}
			t operator [](int i) {
				if (i <= this->items) {
					return this->data[i+1];
				}
			}
		};
	}
}