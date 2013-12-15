double Power(double base, int exponent) {
	if (equal(base, 0.0) && exponent < 0)
		throw new exception();
	
	bool negatvie = false;
	if (exponent < 0) {
		exponent = -exponent;
		negatvie = true;
	}
	
	double result = 0.0;
	
	if (exponent == 0)
		result = 1.0;
	else if (exponent == 1)
		result = base;
	else {
		result = Power(base, exponent >> 1);
		result = (exponent & 0x1) ? result * result * base : result * result;
	}
	
	return negatvie ? 1.0 / result : result;
}

bool equal(double a, double b) {
	double offset = a - b;
	return offset <= 0.00001 && offset >= -0.00001;
}