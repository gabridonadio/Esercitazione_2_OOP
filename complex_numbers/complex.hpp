#pragma once

template<typename T> requires std::is_floating_point_v<T>
class complex_number {
	T re;
	T im;
public:
	complex_number() {
		re = 0;
		im = 0;
	};
	
	complex_number(T reale, T immaginario) {
		re = reale;
		im = immaginario;
	};
	
	T real(void) const{
		return re;
	};
	
	T imaginary(void) const{
		return im;
	};
	
	complex_number conjugate(void) const{
		return complex_number(re, -im);
	};
	
	complex_number& operator+=(const complex_number& other) {
        T a = re;
        T b = im;
        T c = other.re;
        T d = other.im;
        re = a + c;
        im = b + d;
        return *this;
	}
	
	complex_number operator+(const complex_number& other) const{
		complex_number first = *this;
		first += other;
		return first;
	}
	
	complex_number& operator*=(const complex_number& other) {
		T a = re;
        T b = im;
        T c = other.re;
        T d = other.im;
		re = a*c - b*d;
		im = a*d + c*b;
		return *this;
	}
	
	complex_number operator*(const complex_number& other) const{
		complex_number first = *this;
		first *= other;
		return first;
	}
	
	// += with the complex_number on the left and a number T on the right
	complex_number& operator+=(const T& other) {
        re += other;
        return *this;
	}
	
	// + with the complex_number on the left and a number T on the right
	complex_number operator+(const T& other) const{
		complex_number first = *this;
		first += other;
		return first;
	}
	
	// *= with the complex_number on the left and a number T on the right
	complex_number& operator*=(const T& other) {
		re *= other;
		im *= other;
		return *this;
	}
	
	// * with the complex_number on the left and a number T on the right
	complex_number operator*(const T& other) const{
		complex_number first = *this;
		first *= other;
		return first;
	}
	
};

// + with the T number on the left and the complex_number on the right
template<typename T>
complex_number<T> operator+(const T& other, const complex_number<T>& c) {
	return c + other;
}

// * with the T number on the left and the complex_number on the right
template<typename T>
complex_number<T> operator*(const T& other, const complex_number<T>& c) {
	return c * other;
}

// print a complex_number
template<typename T>
std::ostream& operator<<(std::ostream& os, const complex_number<T>& c) {
	if(c.imaginary() >= 0) {
		os << c.real() << "+" << c.imaginary() << "i";
	}
	else {
		os << c.real() << "" << c.imaginary() << "i";
	}
			
    return os;
}

