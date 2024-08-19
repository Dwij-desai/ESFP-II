#include <iostream>
#include <cmath>
#include <string> // Include the <string> header for string

using namespace std;

class Shape {
public:
    // Function to calculate the area of a circle
    double circleArea(double radius) {
        return 3.14 * radius * radius;
    }

    // Function to calculate the area of a rectangle
    double rectangleArea(double length, double breadth) {
        return length * breadth;
    }

    // Function to calculate the area of a triangle
    double triangleArea(double base, double height) {
        return 0.5 * base * height;
    }

    // Function to calculate the area of a square
    double squareArea(double side) {
        return side * side;
    }
};

int main() {
    Shape shape;

    double radius = 5.0;
    double length = 6.0;
    double breadth = 4.0;
    double base = 5.0;
    double height = 3.0;
    double side = 4.0;

    cout << "Area of circle with radius " << radius << " is: " << shape.circleArea(radius) << endl;
    cout << "Area of rectangle with length " << length << " and breadth " << breadth << " is: " << shape.rectangleArea(length, breadth) << endl;
    cout << "Area of triangle with base " << base << " and height " << height << " is: " << shape.triangleArea(base, height) << endl;
    cout << "Area of square with side " << side << " is: " << shape.squareArea(side) << endl;

    return 0;
}
