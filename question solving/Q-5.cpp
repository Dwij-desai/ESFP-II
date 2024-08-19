#include <iostream>
using namespace std;

class Complex {
private:
    int real, imaginary;

public:
    Complex() : real(0), imaginary(0) {}
    Complex(int r, int i) : real(r), imaginary(i) {}

    Complex add(const Complex& c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imaginary = imaginary + c.imaginary;
        return temp;
    }

    Complex subtract(const Complex& c) {
        Complex temp;
        temp.real = real - c.real;
        temp.imaginary = imaginary - c.imaginary;
        return temp;
    }

    void display() {
        cout << real << "+" << imaginary << "i";
    }

    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter value of Complex Number (a,b): ";
        in >> c.real >> c.imaginary;
        return in;
    }
};

int main() {
    Complex c1, c2, result;

    cout << "Enter the first complex number:\n";
    cin >> c1;

    cout << "Enter the second complex number:\n";
    cin >> c2;

    result = c1.add(c2);
    cout << "Addition of two complex numbers: ";
    result.display();
    cout << endl;

    result = c1.subtract(c2);
    cout << "Subtraction of two complex numbers: ";
    result.display();
    cout << endl;

    return 0;
}
