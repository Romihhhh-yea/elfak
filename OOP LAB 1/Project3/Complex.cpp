#include "Complex.h"

std::istream& operator>>(std::istream& in, Complex& c) {
    in >> c.re >> c.im;    
    return in;
}

std::ostream& operator<<(std::ostream& out, const Complex& c) {
    out << c.re;
    if (c.im >= 0) out << " + " << c.im << "i";
    else out << " - " << (-c.im) << "i";
    return out;
}