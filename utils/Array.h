#pragma once
#define Array_Loaded
#include <cassert>
#include <exception>
#include <iostream>
namespace Skele_lib {
	namespace Utils {
		
		template<typename t> class Array {
/*
*	the class Array is a c++ Javascript like array implementation
*/
			t* data;
			int items;
			int length;
			void resize(int m, int op) {
				if (op == 1) {
					this->length *= m;
				} 
				if (op == 2) {
					this->length /= m;
				}
				this->data = static_cast<t*>(realloc(this->data, sizeof(t) * length));
				assert(this->data != nullptr);
			}
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
					this->resize(2, 1);
					for (int x = this->items; x < this->length; x++) {
						this->data[x] = NULL; 
					}
				}
				this->data[this->items] = newLast;
				this->items++;
			}
			t Pop() {
				this->items--;
				if (this->items < this->length / 2) {
					this->resize(2, 2);
				}
				return this->data[this->items];
			}
			t operator [](int i) {
				if (i >= 0 && i <= this->items - 1) {
					return this->data[i + 1];//index 0 is ptn to the array so always at least return index 1; 
				}
				std::cerr << "ARRAY_INDEX_OUT_OF_BOUNDS ERROR"; 
				return NULL;
			}
			Array<t> operator+(Array<t> o ){ /// append operator 
				Array<t> temp = Array<t>((this->Length() + o.Length())-2); 
				for (int i = 0; i < this->Length(); i++) {
					temp.Push(this->operator[](i));
				}
				for (int i = 0; i < o.Length(); i++) {
					temp.Push(o[i]);
				}
				return temp; 
			}
		};
	}
}