#include <iostream>
using namespace std;

template <typename T>
void testException(T num1, T num2, T num3) {
    try {
        if (num1 > 50) {
            throw num1;
        }
        if (num2 > 500) {
            throw num2;
        }
        if (num1 == num2 && num2 == num3) {
            throw num3;
        }
        cout << "No exception thrown in the program." << endl;
    } catch (T num) {
        cout << "Exception thrown: " << num << endl;
    }
}

int main() {
    int num1, num2, num3;

    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    testException(num1, num2, num3);

    return 0;
}
