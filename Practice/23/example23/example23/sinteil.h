double teilor(double x, int k) {
	double sinx = x;
	double temp = x;
	// x = 0; pi/4
	// k = 5
	for (int i = 1; i < k; i++)
	{
		double tempu = -(x * x);

		sinx = sinx + temp * tempu / factorial(2 * i + 1);
		temp = temp * tempu;
	}

	return sinx;
}