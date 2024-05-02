#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
    double x, y, w;

    Point(double x = 0, double y = 0, double w = 1.0) : x(x), y(y), w(w) {}
};

class Transformation {
public:
    double matrix[3][3];

    Transformation() {
        // Initialize the transformation matrix as an identity matrix
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrix[i][j] = (i == j) ? 1.0 : 0.0;
            }
        }
    }

    Point operator*(const Point& p) {
        Point result(0, 0, 0);
        for (int i = 0; i < 3; i++) {
            result.x += matrix[0][i] * p.x;
            result.y += matrix[1][i] * p.y;
            result.w += matrix[2][i] * p.w;
        }
        return result;
    }
};

class Object {
public:
    Point vertices[4]; // For simplicity, let's consider a square object

    Object() {
        // Initialize vertices of a square
        vertices[0] = Point(-1, -1); // Bottom-left
        vertices[1] = Point(1, -1);  // Bottom-right
        vertices[2] = Point(1, 1);   // Top-right
        vertices[3] = Point(-1, 1);  // Top-left
    }

    void draw() {
        // Draw the square
        cout << "Drawing object:" << endl;
        for (int i = 0; i < 4; i++) {
            cout << "(" << vertices[i].x << ", " << vertices[i].y << ")" << endl;
        }
        cout << endl;
    }

    void transform(const Transformation& t) {
        // Apply transformation to all vertices
        for (int i = 0; i < 4; i++) {
            vertices[i] = t * vertices[i];
        }
    }
};

int main() {
    Object obj;
    obj.draw();

    Transformation translation;
    translation.matrix[0][2] = 2; // Translate by 2 units in x-axis
    translation.matrix[1][2] = 1; // Translate by 1 unit in y-axis
    obj.transform(translation);
    obj.draw();

    Transformation rotation;
    double angle = 45 * M_PI / 180; // Convert to radians
    rotation.matrix[0][0] = cos(angle);
    rotation.matrix[0][1] = -sin(angle);
    rotation.matrix[1][0] = sin(angle);
    rotation.matrix[1][1] = cos(angle);
    obj.transform(rotation);
    obj.draw();

    Transformation scaling;
    scaling.matrix[0][0] = 2; // Scale by 2 in x-axis
    scaling.matrix[1][1] = 0.5; // Scale by 0.5 in y-axis
    obj.transform(scaling);
    obj.draw();

    Transformation shearing;
    shearing.matrix[0][1] = 0.5; // Shear in x-direction
    shearing.matrix[1][0] = 0.5; // Shear in y-direction
    obj.transform(shearing);
    obj.draw();

    return 0;
}
