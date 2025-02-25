#include <iostream>
#include <cmath>

using namespace std;

class ComplexNumber {
public:
    double real;
    double imag;
    ComplexNumber(double = 0, double = 0);

    ComplexNumber operator+(const ComplexNumber &);
    ComplexNumber operator+(double);
    friend ComplexNumber operator+(double, const ComplexNumber &);

    ComplexNumber operator-(const ComplexNumber &);
    ComplexNumber operator-(double);
    friend ComplexNumber operator-(double, const ComplexNumber &);

    ComplexNumber operator*(const ComplexNumber &);
    ComplexNumber operator*(double);
    friend ComplexNumber operator*(double, const ComplexNumber &);

    ComplexNumber operator/(const ComplexNumber &);
    ComplexNumber operator/(double);
    friend ComplexNumber operator/(double, const ComplexNumber &);

    bool operator==(const ComplexNumber &);
    bool operator==(double);
    friend bool operator==(double, const ComplexNumber &);

    double abs();
    double angle();

    friend ostream &operator<<(ostream &, const ComplexNumber &);
};

ComplexNumber::ComplexNumber(double x, double y) {
    real = x;
    imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c) {
    return ComplexNumber(real + c.real, imag + c.imag);
}

ComplexNumber ComplexNumber::operator+(double d) {
    return ComplexNumber(real + d, imag);
}

ComplexNumber operator+(double d, const ComplexNumber &c) {
    return ComplexNumber(d + c.real, c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c) {
    return ComplexNumber(real - c.real, imag - c.imag);
}

ComplexNumber ComplexNumber::operator-(double d) {
    return ComplexNumber(real - d, imag);
}

ComplexNumber operator-(double d, const ComplexNumber &c) {
    return ComplexNumber(d - c.real, -c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c) {
    return ComplexNumber(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

ComplexNumber ComplexNumber::operator*(double d) {
    return ComplexNumber(real * d, imag * d);
}

ComplexNumber operator*(double d, const ComplexNumber &c) {
    return ComplexNumber(c.real * d, c.imag * d);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c) {
    double x = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((real * c.real + imag * c.imag) / x,(imag * c.real - real * c.imag) / x);
}

ComplexNumber ComplexNumber::operator/(double d) {
    return ComplexNumber(real / d, imag / d);
}

ComplexNumber operator/(double d, const ComplexNumber &c) {
    double x = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((d * c.real) / x, (-d * c.imag) / x);
}

bool ComplexNumber::operator==(const ComplexNumber &c) {
    return (real == c.real && imag == c.imag);
}

bool ComplexNumber::operator==(double d) {
    return (real == d && imag == 0);
}

bool operator==(double d, const ComplexNumber &c) {
    return (c.real == d && c.imag == 0);
}

double ComplexNumber::abs() {
    return sqrt(real * real + imag * imag);
}

double ComplexNumber::angle() {
    return atan2(imag, real) * (180.0 / M_PI);
}

ostream &operator<<(ostream &out, const ComplexNumber &c) {
    if (c.real == 0 && c.imag == 0) return out << "0";
    if (c.real == 0) return out << c.imag << "i";
    if (c.imag == 0) return out << c.real;
    if (c.imag > 0) return out << c.real << "+" << c.imag << "i";
    return out << c.real << c.imag << "i";
}

int main() {
    ComplexNumber a(1.5, 2), b(3.2, -2.5), c(-1, 1.2);
    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";
    cout << a + 2.5 << "\n";
    cout << 2.5 + a << "\n";
    cout << a - 1.5 << "\n";
    cout << 1.5 - a << "\n";
    cout << b + ComplexNumber(0, 2.5) << "\n";
    cout << c - c << "\n";
    cout << "-----------------------------------\n";

    ComplexNumber d = (a + b) / c;
    ComplexNumber e = b / (a - c);
    cout << d << "\n";
    cout << e << "\n";
    cout << c * 2 << "\n";
    cout << 0.5 * c << "\n";
    cout << 1 / c << "\n";
    cout << "-----------------------------------\n";

    cout << ComplexNumber(1, 1).abs() << "\n";
    cout << ComplexNumber(-1, 1).abs() << "\n";
    cout << ComplexNumber(1.5, 2.4).abs() << "\n";
    cout << ComplexNumber(3, 4).abs() << "\n";
    cout << ComplexNumber(69, -9).abs() << "\n";
    cout << "-----------------------------------\n";

    cout << ComplexNumber(1, 1).angle() << "\n";
    cout << ComplexNumber(-1, 1).angle() << "\n";
    cout << ComplexNumber(-1, -1).angle() << "\n";
    cout << ComplexNumber(1, -1).angle() << "\n";
    cout << ComplexNumber(5, 2).angle() << "\n";
    cout << "-----------------------------------\n";

    cout << (ComplexNumber(1, 1) == ComplexNumber(1, 2)) << "\n";
    cout << (ComplexNumber(1, 1) == 1) << "\n";
    cout << (0 == ComplexNumber()) << "\n";

    return 0;
}
