#include <iostream>
#include <cmath>
#include <numbers>
using namespace std;

typedef struct {
    float x;
    float y;
}Punkt;



class Circle {
private:
    float x;
    float y;
    float r;

    void init(float x0, float y0, float r0) {
        if (x0 <= 0 || y0 <= 0 || r0 <= 0) {
            throw invalid_argument("The values cannot be zero or less");
        }
        this->x = x0;
        this->y = y0;
        this->r = r0;
    }

public:
    Circle(float x0, float y0, float r0): x(x0), y(y0), r(r0) {
        init(x0, y0, r0);
    }

    float perimeter() {
        return (static_cast<float>(numbers::pi) * r * 2.0f);
    }

    float diameter() {
        return (r * 2.0f);
    }

    float square() {
        return (static_cast<float>(numbers::pi) * r * r);
    }
    void printer() {
        cout << "Circle with radius " << r << " and coordinates (" << x << ", " << y << ")" << endl;
    }


    friend class CircleInteraction;
};

class CircleInteraction {
private:
    Circle A;
    Circle B;
    void init(Circle A, Circle B) {
        this->A = A;
        this->B = B;
    }
public:
    CircleInteraction(Circle A, Circle B): A(A), B(B) {
        init(A, B);
    }

    float length_between_centers() {
        return (sqrt(A.x - B.x ) * (A.x - B.x ) + (A.y - B.y) * (A.y - B.y));
    }

    Punkt* getIntersectionPoints() {
        float d = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
        Punkt* points = nullptr;
        int numPoints = 0;

        if ((d > A.r + B.r) || (d < abs(A.r - B.r)) || (d == 0 && A.r == B.r)) {

            return nullptr;
        } else if (d == A.r + B.r || d == abs(A.r - B.r)) {

            numPoints = 1;
            points = (Punkt*)malloc(sizeof(Punkt));
            if (points) {
                points[0].x = A.x + (B.x - A.x) * A.r / d;
                points[0].y = A.y + (B.y - A.y) * A.r / d;
            }
        } else {

            numPoints = 2;
            points = (Punkt*)malloc(2 * sizeof(Punkt));
            if (points) {
                float a = (pow(A.r, 2) - pow(B.r, 2) + pow(d, 2)) / (2 * d);
                float h = sqrt(pow(A.r, 2) - pow(a, 2));

                float x2 = A.x + a * (B.x - A.x) / d;
                float y2 = A.y + a * (B.y - A.y) / d;

                points[0].x = x2 + h * (B.y - A.y) / d;
                points[0].y = y2 - h * (B.x - A.x) / d;

                points[1].x = x2 - h * (B.y - A.y) / d;
                points[1].y = y2 + h * (B.x - A.x) / d;
            }
        }
        return points;
    }
    Circle calculateCenterOfMass() {
        float massA = A.square();
        float massB = B.square();

        float x_cm = (massA * A.x + massB * B.x) / (massA + massB);
        float y_cm = (massA * A.y + massB * B.y) / (massA + massB);
        float combinedRadius = sqrt((massA + massB) / static_cast<float>(numbers::pi));

        return Circle(x_cm, y_cm, combinedRadius);
    }
};

Circle CenterOfMass(Circle* circles, int count) {
    Circle combinedCenterOfMass = circles[0];
    for (int i = 1; i < count; ++i) {
        CircleInteraction interaction(combinedCenterOfMass, circles[i]);
        combinedCenterOfMass = interaction.calculateCenterOfMass();
    }

    return combinedCenterOfMass;
}

int main() {
    cout << "If you want to stop making circles, write 100\n";
    int counter = 0;
    Circle* array = (Circle*)malloc(sizeof(Circle));
    while (true) {
        float x, y, r;
        cout << "Enter x, y, r for the circle (or enter 100 for x to stop):";
        cin >> x;
        if (x == 100) {
            break;
        }
        cin >> y >> r;
        Circle circle(x, y, r);
        Circle* temp = (Circle*)realloc(array, (counter + 1) * sizeof(Circle));
        if (temp == nullptr) {
            cerr << "Memory allocation failed!\n";
            free(array);
            return 1;
        }
        array = temp;
        array[counter] = circle;
        counter++;
    }
    cout << "\nCreated circles:\n";
    for (int i = 0; i < counter; ++i) {
        array[i].printer();
    }
    Circle mass_circle = CenterOfMass(array, counter);
    cout << "Mass center: \n";
    mass_circle.printer();
    free(array);
    return 0;
}
