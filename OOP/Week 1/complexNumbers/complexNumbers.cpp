#include <iostream>

struct complexNumber {
	int a;
	int b;
};

//complex num looks like a+i*b

complexNumber addition(const complexNumber& x, const complexNumber& y) {
	complexNumber res;
	res.a = x.a + y.a;
	res.b = x.b + y.b;
	return res;
}

void printComplexNumber(const complexNumber& x) {
	std::cout << x.a << " + i*" << x.b;
	return;
}

int main()
{
	complexNumber x = { 2,4 };
	complexNumber y = { 1,6 };

	complexNumber sum = addition(x, y);
	printComplexNumber(sum);
}
