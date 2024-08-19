#include <iostream>
#include <string>

using namespace std;

class Shape {
public:
    // Default constructor
    Shape() {
        type = "Unknown";
    }

    // Constructor with type
    Shape(string t) {
        type = t;
    }

    // Constructor for rectangle
    Shape(string t, double w, double h) {
        type = t;
        width = w;
        height = h;
    }

    // Constructor for circle
    Shape(string t, double r) {
        type = t;
        radius = r;
    }

    void display() {
        cout << "Type: " << type << endl;
        if (type == "Rectangle") {
            cout << "Width: " << width << ", Height: " << height << endl;
        } else if (type == "Circle") {
            cout << "Radius: " << radius << endl;
        }
    }

private:
    string type;
    double width = 0;
    double height = 0;
    double radius = 0;
};

int main() {
    // Using the default constructor
    Shape shape1;
    shape1.display();

    // Using the constructor with type
    Shape shape2("Rectangle");
    shape2.display();

    // Using the constructor for rectangle
    Shape shape3("Rectangle", 5.0, 3.0);
    shape3.display();

    // Using the constructor for circle
    Shape shape4("Circle", 2.5);
    shape4.display();

    return 0;
}
