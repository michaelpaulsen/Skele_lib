
#pragma once
#include <iostream>
#include <cmath>
#include "math.h"
namespace Skele_lib{
	namespace Math{
	
		class V2d
		{
		private:
			int x;
			int y;
		public:
			V2d(int x, int y) {
				this->x = x;
				this->y = y;
			}
			V2d() {
				this->x = 0;
				this->y = 0;
			}
			void set(int x, int y) {
				this->x = x;
				this->y = y;
			}
			float getAngle() {
				//std::printf("%f : %f", x, y);
				/*	if (this->x == this->y) {
						return 45.0f;
					}*/

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

			float getAngle(bool deg) {
				std::printf("%f : %f", x, y);
				double rad = std::atan(this->y / this->x);
				if (deg) {
					return rad * 180 / Skele_lib::Math::PI;
				}
			}
			V2d delta(V2d o) {
				V2d temp;
				temp.set(this->x - o.x, this->y - o.y); 
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
			}	
			bool operator== (V2d o) {
				return this->x == o.x && this->y == o.y;
			}
		};
	}
}