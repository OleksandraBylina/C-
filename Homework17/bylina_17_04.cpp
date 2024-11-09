

//
// Created by bylin on 09.11.2024.
//
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <new>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    friend ostream& operator<<(ostream& os, const Complex& z);
    friend istream& operator>>(istream& is, Complex& z);


    double modulus() const {
        return sqrt(real * real + imag * imag);
    }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        if (denom == 0) throw logic_error("Division by zero");
        return Complex((real * other.real + imag * other.imag) / denom,
                       (imag * other.real - real * other.imag) / denom);
    }


    Complex power(int n) const {
        Complex result(1, 0);
        Complex base(*this);
        while (n > 0) {
            if (n % 2 == 1) result = result * base;
            base = base * base;
            n /= 2;
        }
        return result;
    }


    Complex arctan_series_sum(double epsilon) const {
        if (this->modulus() >= 1) {
            throw logic_error("The modulus of the complex number must be less than 1 to sum the series.");
        }
        Complex sum(0, 0);
        Complex term(*this);
        int n = 1;
        while (term.modulus() > epsilon) {
            if (n % 2 == 0) term = term * Complex(-1, 0);
            sum = sum + (term / Complex(n, 0));
            term = term * (*this) * (*this);
            n += 2;
        }
        return sum;
    }


    void allocateMemory(int size) {
        try {
            double* array = new double[size];
            delete[] array;
        } catch (const bad_alloc&) {
            throw runtime_error("Memory allocation failed");
        }
    }
};

ostream& operator<<(ostream& os, const Complex& z) {
    os << z.real;
    if (z.imag >= 0) os << " + " << z.imag << "i";
    else os << " - " << -z.imag << "i";
    return os;
}

istream& operator>>(istream& is, Complex& z) {
    char op, i_char;
    cout << "Enter a complex number in the format a + bi:\n";
    if (!(is >> z.real >> op >> z.imag >> i_char) || (op != '+' && op != '-') || i_char != 'i') {
        throw invalid_argument("Invalid input format. Expected format a + bi.");
    }
    if (op == '-') {
        z.imag = -z.imag;
    }
    return is;
}

int main() {
    try {
        Complex z;
        cin >> z;

        z.allocateMemory(1000);

        double epsilon = 0.00001;
        Complex result = z.arctan_series_sum(epsilon);
        cout << "Series Sum: " << result << endl;

    } catch (const invalid_argument& e) {
        cerr << "Input Error: " << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << "Logical Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
