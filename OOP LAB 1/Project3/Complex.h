#include <iostream>
class Complex {
private:
    double re;
    double im;

public:
    Complex(double real = 0.0, double imag = 0.0) : re(real), im(imag) {}

    Complex operator+(const Complex& c) const {
        return Complex(re + c.re, im + c.im);
    }

    Complex operator-(const Complex& c) const {
        return Complex(re - c.re, im - c.im);
    }

    bool operator==(const Complex& c) const {
        return re == c.re && im == c.im;
    }

    bool operator!=(const Complex& c) const {
        return !(*this == c);
    }

    friend std::istream& operator>>(std::istream& in, Complex& c);
    friend std::ostream& operator<<(std::ostream& out, const Complex& c);
};
