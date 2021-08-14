
#pragma once
#define vector2d
#include <iostream>
#include <cmath>
#include "math.h"
namespace Skele_lib{
	namespace Math{
	
		template<typename t> class V2d
		{
		private:
			t x;
			t y;
		public:
			V2d(t x, t y) {
				this->x = x;
				this->y = y;
			}
			V2d() {
				this->x = 0;
				this->y = 0;
			}
			float getAngle() {
				return std::atan(this->y / this->x);
			}
			t getX() {
				return this->x;
			}
			void setX(t sx) {
				this->x = sx;
			}
			t getY() {
				return this->y;
			}
			void setY(t sy) {
				this->y = sy;
			}
			float getAngle(bool deg = false) {
				std::printf("%f : %f", x, y);
				double rad = std::atan(this->y / this->x);
				if (deg) {
					return rad * Skele_lib::Math::RAD_TO_DEG;
				}
				else {
					return rad; 
				}
			}
			V2d<t> delta(V2d o) {
				V2d temp;
				temp = V2d(abs(this->x - o.x), abs(this->y - o.y));
				return temp;
			}
			V2d<t> operator+(V2d o) {
				V2d temp = V2d(0, 0);
				temp.x = this->x + o.x;
				temp.y = this->y + o.y;
				return temp;
			}
			V2d<t> operator-(V2d o) {
				V2d temp = V2d(0, 0);
				temp.x = this->x - o.x;
				temp.y = this->y - o.y;
				return temp;
			}
			V2d<t> operator*(V2d o) {
				V2d temp = V2d(0, 0);
				temp.x = this->x * o.x;
				temp.y = this->y * o.y;
				return temp;
			}
			V2d<t> operator/(V2d o) {
				V2d temp = V2d(0, 0);
				temp.x = this->x / o.x;
				temp.y = this->y / o.y;
				return temp;
			}	
			V2d<t> operator*(float o) {
				V2d temp = V2d(0, 0);
				temp.x = this->x * o;
				temp.y = this->y * o;
				return temp;
			}
			V2d<t> operator/(float o) {
				V2d temp = V2d(0, 0);
				temp.x = this->x / o;
				temp.y = this->y / o;
				return temp;
			}
			void operator=(V2d o) {
				this->x = o.x;
				this->y = o.y;
			}	
			void operator=(float o) {
				this->x = o;
				this->y = o;
			}	
			bool operator== (V2d o) {
				return this->x == o.x && this->y == o.y;
			}
			bool operator== (float o) {
				return this->x == o && this->y == o;
			}
		};
		V2d<int> getPosFromIndex(int i, int sw, int sh ) {
			V2d<int> temp = V2d<int>(0, 0);
			temp.setY(floor(i / sw));
			temp.setX(i % sh);
			return temp;
		}
	}
	typedef	Skele_lib::Math::V2d<int>       V2dI;
	typedef Skele_lib::Math::V2d<float>     V2dF;
	typedef Skele_lib::Math::V2d<double>    V2dD;
}