#ifndef STP
#define STP
#endif
int factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		result = result * i;
	}

	return result;
}