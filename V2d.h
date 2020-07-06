
#pragma once
#include <iostream>
#include <cmath>
#include "math.h"
namespace Skele_lib{
	namespace Math{
	
		class V2d
		{
		private:
			float x;
			float y;
		public:
			V2d(float x, float y) {
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
			float getX() {
				return this->x;
			}
			void setX(int sx) {
				this->x = sx;
			}
			float getY() {
				return this->y;
			}
			void setY(float sy) {
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
			V2d delta(V2d o) {
				V2d temp;
				temp = V2d(abs(this->x - o.x), abs(this->y - o.y));
				return temp;
			}
			V2d operator+(V2d o) {
				V2d temp = V2d(0, 0);
				temp.x = this->x + o.x;
				temp.y = this->y + o.y;
				return temp;
			}
			V2d operator-(V2d o) {
				V2d temp = V2d(0, 0);
				temp.x = this->x - o.x;
				temp.y = this->y - o.y;
				return temp;
			}
			V2d operator*(V2d o) {
				V2d temp = V2d(0, 0);
				temp.x = this->x * o.x;
				temp.y = this->y * o.y;
				return temp;
			}
			V2d operator/(V2d o) {
				V2d temp = V2d(0, 0);
				temp.x = this->x / o.x;
				temp.y = this->y / o.y;
				return temp;
			}
			V2d operator=(V2d o) {
				V2d temp = V2d(0, 0);
				temp.x = this->x = o.x;
				temp.y = this->y = o.y;
				return temp;
			void operator=(V2d o) {
				this->x = o.x;
				this->y = o.y;
			}	
			}	
			bool operator== (V2d o) {
				return this->x == o.x && this->y == o.y;
			}
		};
	}
}
