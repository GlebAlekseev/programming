#pragma once
double comb(int k, int n) {
	double resc = factorial(n) / (factorial(k) * factorial(n - k));
	return resc;
}