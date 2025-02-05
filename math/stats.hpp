#pragma once
#include <iostream>
namespace skc::math {
	using u64 = unsigned long long;
	double factorial(int n) {
		if (n == 0 || n == 1)
			return 1.0;
		double result = 1.0;
		for (int i = 2; i <= n; ++i)
			result *= i;
		return result;
	}
	namespace stats {

		

		// Function to calculate combinations (n choose k)
		double combination(int n, int k) {
			if (k > n) return 0.0;
			return factorial(n) / (factorial(k) * factorial(n - k));
		}

		
		//returns P(X=x) 
		double hypergeometric(int total, int success_states, int draws, int successess) {
			double numerator = combination(success_states, successess) * combination(total - success_states, draws - successess);
			double denominator = combination(total, draws);
			return numerator / denominator;
		}
		//returns P(X<x) 
		double hypergeometric_lt(int total, int success_states, int draws, int successess) {
			double su = 0; 
			for (int s = 1; s < successess; ++s) {
				su += hypergeometric(total, success_states, draws, s); 

			}
			return su; 
		}
		//returns P(X<=x) 
		double hypergeometric_lteq(int total, int success_states, int draws, int successess) {
			double su = 0;
			for (int s = 1; s <= successess; ++s) {
				su += hypergeometric(total, success_states, draws, s);

			}
			return su;

		}

		//returns P(X>x) 
		double hypergeometric_gt(int total, int success_states, int draws, int successess) {
			return 1 - hypergeometric_lteq(total, success_states, draws, successess);
		}
		//returns P(X>=x) 
		double hypergeometric_gteq(int total, int success_states, int draws, int successess) {
			return 1 - hypergeometric_lt(total, success_states, draws, successess);
		}
	}
}