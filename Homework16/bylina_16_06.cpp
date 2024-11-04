#include <iostream>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void center() const = 0;

};

class Rectangle : public Figure {
    double x, y, width, height;
public:
    Rectangle(double x, double y, double width, double height)
        : x(x), y(y), width(width), height(height) {}

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }

    void center() const override {
        cout << "Center: (" << x + width / 2 << ", " << y - height / 2 << ")\n";
    }
};

class Triangle : public Figure {
    double x1, y1, x2, y2, x3, y3;
public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

    double area() const override {
        return fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
    }

    double perimeter() const override {
        double side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        double side2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
        double side3 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
        return side1 + side2 + side3;
    }

    void center() const override {
        double centerX = (x1 + x2 + x3) / 3;
        double centerY = (y1 + y2 + y3) / 3;
        cout << "Center: (" << centerX << ", " << centerY << ")\n";
    }
};

class Ellipse : public Figure {
    double x, y, radius1, radius2;
public:
    Ellipse(double x, double y, double radius1, double radius2)
        : x(x), y(y), radius1(radius1), radius2(radius2) {}

    double area() const override {
        return M_PI * radius1 * radius2;
    }

    double perimeter() const override {
        return M_PI * (3 * (radius1 + radius2) - sqrt((3 * radius1 + radius2) * (radius1 + 3 * radius2)));
    }

    void center() const override {
        cout << "Center: (" << x << ", " << y << ")\n";
    }
};

int main() {
    Rectangle rect(0, 0, 4, 2);
    Triangle tri(0, 0, 5, 0, 3, 4);
    Ellipse ell(1, 1, 3, 2);
    cout << "Rectangle:\n";
    cout << "Square: " << rect.area() << "\n";
    cout << "Perimeter: " << rect.perimeter() << "\n";
    rect.center();
    cout << "\nTriangle:\n";
    cout << "Square: " << tri.area() << "\n";
    cout << "Perimeter: " << tri.perimeter() << "\n";
    tri.center();
    cout << "\nEllipse:\n";
    cout << "Square: " << ell.area() << "\n";
    cout << "Perimeter: " << ell.perimeter() << "\n";
    ell.center();
}
