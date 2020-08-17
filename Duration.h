#pragma once
#include <math.h>
namespace Skele_lib {
	class Duration {
		int hours;
		int minutes;
		float seconds;
	public:
		
		static Duration averageDur(Duration* dirs) {
			float total = 0.0f;
			for (int x = 0; x < sizeof(dirs)-1; x++) {
				total += dirs[x].toSeconds();
			}
			total /= sizeof(dirs)-1; 
			return Duration(total);
		}
		Duration(            ) = default;//default constructor 
		Duration(Duration& o ) = default;//copy constructor 
		Duration(Duration&& o) = default;// forward referance(?) copy constructor 
		Duration(int hours, int minutes, float seconds) {
			this->hours = hours;
			this->minutes = minutes;
			this->seconds = seconds;
		}
		float toSeconds() {
			return (((this->hours * 60) + this->minutes) * 60) + this->seconds;
		};
		int getMinutes() {
			return this->minutes;
		}
		int getHours() {
			return this->hours;
		}
		float getSeconds() {
			return this->seconds;
		}
		void set(int h, int m, float s) {
			this->hours = h;
			this->minutes = m;
			this->seconds = s;
		}
		Duration operator+ (Duration o) {
			return Duration(this->hours + o.getHours(), this->minutes + o.getMinutes(), this->seconds + o.getSeconds());
		}
		Duration operator- (Duration o) {
			return Duration(this->hours - o.getHours(), this->minutes - o.getMinutes(), this->seconds - o.getSeconds());
		}
		bool operator== (Duration o) {
			return (this->hours == o.getHours() && this->minutes == o.getMinutes() && this->seconds == o.getSeconds());
		}
		bool operator>= (Duration o) {
			return (this->hours >= o.getHours() && this->minutes >= o.getMinutes() && this->seconds >= o.getSeconds());
		}
		bool operator<= (Duration o) {
			return (this->hours <= o.getHours() && this->minutes <= o.getMinutes() && this->seconds <= o.getSeconds());
		}
		bool operator< (Duration o) {
			return (this->hours < o.getHours() && this->minutes < o.getMinutes() && this->seconds < o.getSeconds());
		}
		bool operator> (Duration o) {
			return (this->hours > o.getHours() && this->minutes > o.getMinutes() && this->seconds > o.getSeconds());
		}
	};
}