#include <iostream>
#include "complex.hpp"

int main(void) {
	complex_number<float> c1(7.0,-2.0);
	complex_number<float> c2(2.5,3.0);
	complex_number<double> c3(4.0,3.5);
	float i = -2.7;
	double d = 3.14;
	
	std::cout << "the real part of " << c1 << " is " << c1.real() << std::endl;
	std::cout << "the imaginary part of " << c1 << " is " << c1.imaginary() << std::endl;
	std::cout << "the conjugate of " << c1 << " is " << c1.conjugate() << std::endl;
	std::cout << c1 << " + " << c2 << " = " << c1 + c2 << std::endl;
	std::cout << c1 << " * " << c2 << " = " << c1 * c2 << std::endl;
	std::cout << "if we compute c1 += c2: " << c1 << " += " << c2 << " the variable c1 is now " << (c1+=c2)<<std::endl;
	std::cout << "if we compute c1 *= c2: " << c1 << " *= " << c2 << " the variable c1 is now " << (c1*=c2)<<std::endl;
	std::cout << "we want to be able to sum a float/double number to respectively a complex<float>/complex<double> and we want the sum to be commutative: "
	<< c2 << " " << i << " = " << c2 + i << std::endl;
	std::cout << "we should obtain the same if we compute " << i << " + " << c2 << " = " << i + c2 << std::endl;
	std::cout << c3 << " * " << d << " = " << c3 * d << std::endl;
	std::cout << "we should obtain the same if we compute " << d << " * " << c3 << " = " << d*c3 << std::endl;

	
	return 0;
};