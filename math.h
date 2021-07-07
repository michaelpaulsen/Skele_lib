#pragma once; 
#include <utility>
#include <math.h>

namespace Skele_lib::Math{
	const long double PI = 3.14159265358979323846;
	const long double RAD_TO_DEG = 180 / PI; 
	const long double PHI = 1.61803398874989484820;
	std::pair<long double,long double> quadratic_equation(double a,double b,double c ){ 
		/**
		* using the quadratic formula this function gives the values for x where y == 0 
		* the pramiters are as follows ax^2+bx+c 
		* the first long double in the pair is the "positve" one 
		* the second long double in the pair is the "negitive" 
		*/
		std::pair<long double, long double> temp; 
		temp.first  = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		temp.second = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	}
}