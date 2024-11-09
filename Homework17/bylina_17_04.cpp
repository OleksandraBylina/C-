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


    double modul() const {
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
        if (this->modul() >= 1) {
            throw logic_error("Division by zero");
        }
        Complex sum(0, 0);
        Complex term(*this);
        int n = 1;
        while (term.modul() > epsilon) {
            if (n % 2 == 0) term = term * -1;
            sum = sum + term / n;
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
            throw runtime_error("Memory leaked");
        }
    }
};

ostream& operator<<(ostream& os, const Complex& z) {
    os << z.real << " + " << z.imag << "i";
    return os;
}


istream& operator>>(istream& is, Complex& z) {
    cout << "Write Re-part:";
    if (!(is >> z.real)) {
        throw invalid_argument("Incorrect");
    }
    cout << "Write Im-part: ";
    if (!(is >> z.imag)) {
        throw invalid_argument("Incorrect");
    }
    return is;
}

int main() {
    try {
        Complex z;
        cout << "Write a number";
        cin >> z;
        if (z.modul() >= 1) {
            throw logic_error("Incorrect");
        }


        z.allocateMemory(1000);

        double epsilon = 0.00001;
        Complex result = z.arctan_series_sum(epsilon);
        cout << "Sum: " << result << endl;

    } catch (const exception& e) {
        cerr << "Error" << e.what() << endl;
    }

    return 0;
}
