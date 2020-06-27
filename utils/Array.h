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
				this->data = nullptr; 
				this->items = NULL;
				this->length = NULL;
			}

			void Push(t newLast) {
				if(this->data != nullptr){ // the array has not been distroyed 
					if (this->items == this->length) {
						this->length *= 2;
						this->data = static_cast<t*>(realloc(this->data, sizeof(t) * length)); // &this->data will be the same unless there's not enogh room at &this->data to realloc to the new size
						assert(this->data != nullptr);// make shure that it actualy worked 
						/*get more mem for the array if the size is too small to store the next value*/
					}
					this->items++;//add one to the items "index"
					this->data[this->items] = newLast;
				}
			}
			t Pop() {
				if (this->data != nullptr || this->items <=0) {
					return NULL;
				} // return NULL if this has already been distroyed or the array has no more items in it 
					t temp = data[this->items];
					this->items--;
					return temp;// otherwise return the value of the last item in the array
			}
			t operator [](int i) {
				return this->data != nullptr ?this->data[i]:NULL;// safely index the array
			}
			int Length(void) {
				return this->items;
			}
		};
	}
}