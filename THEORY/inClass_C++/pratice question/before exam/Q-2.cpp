#include <iostream>
#include <cmath>

using namespace std;

class AreaCalculator {
private:
    double area;

public:

    float PI = 3.14;

    // Constructor for calculating the area of a circle
    AreaCalculator(double radius) {
        area = PI * radius * radius;
    }

    // Constructor for calculating the area of a rectangle
    AreaCalculator(double length, double width) {
        area = length * width;
    }

    // Constructor for calculating the area of a triangle
    AreaCalculator(double base, double height, bool isTriangle) {
        area = 0.5 * base * height;
    }

    // Constructor for calculating the area of a square
    AreaCalculator(double side, bool isSquare) {
        area = side * side;
    }

    // Function to get the calculated area
    double getArea() {
        return area;
    }
};

int main() {
    // Calculate the area of a circle with radius 5
    AreaCalculator circle(5.0);
    cout << "Area of circle: " << circle.getArea() << endl;

    // Calculate the area of a rectangle with length 5 and width 3
    AreaCalculator rectangle(5.0, 3.0);
    cout << "Area of rectangle: " << rectangle.getArea() << endl;

    // Calculate the area of a triangle with base 4 and height 3
    AreaCalculator triangle(4.0, 3.0, true);
    cout << "Area of triangle: " << triangle.getArea() << endl;

    // Calculate the area of a square with side length 4
    AreaCalculator square(4.0, true);
    cout << "Area of square: " << square.getArea() << endl;

    return 0;
}
