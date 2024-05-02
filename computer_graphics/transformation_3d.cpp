#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Point3D {
public:
    double x, y, z;

    Point3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
};

class Transformation3D {
public:
    double matrix[4][4];

    Transformation3D() {
        // Initialize the transformation matrix as an identity matrix
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                matrix[i][j] = (i == j) ? 1.0 : 0.0;
            }
        }
    }

    Point3D operator*(const Point3D& p) {
        Point3D result;
        for (int i = 0; i < 4; i++) {
            result.x += matrix[0][i] * p.x;
            result.y += matrix[1][i] * p.y;
            result.z += matrix[2][i] * p.z;
            result.w += matrix[3][i] * p.w;
        }
        return result;
    }
};

class Object3D {
public:
    vector<Point3D> vertices;

    Object3D() {
        // Initialize vertices of a cube
        vertices.push_back(Point3D(-1, -1, -1)); // 0
        vertices.push_back(Point3D(1, -1, -1));  // 1
        vertices.push_back(Point3D(1, 1, -1));   // 2
        vertices.push_back(Point3D(-1, 1, -1));  // 3
        vertices.push_back(Point3D(-1, -1, 1));  // 4
        vertices.push_back(Point3D(1, -1, 1));   // 5
        vertices.push_back(Point3D(1, 1, 1));    // 6
        vertices.push_back(Point3D(-1, 1, 1));   // 7
    }

    void transform(const Transformation3D& t) {
        // Apply transformation to all vertices
        for (int i = 0; i < vertices.size(); i++) {
            vertices[i] = t * vertices[i];
        }
    }

    void draw() {
        // Draw the object
        for (int i = 0; i < vertices.size(); i++) {
            cout << "(" << vertices[i].x << ", " << vertices[i].y << ", " << vertices[i].z << ")" << endl;
        }
        cout << endl;
    }
};

class Projection {
public:
    virtual Point3D project(const Point3D& p) const = 0;
};

class ParallelProjection : public Projection {
public:
    Point3D project(const Point3D& p) const override {
        // Simply remove the z-coordinate for parallel projection
        return Point3D(p.x, p.y, 0);
    }
};

class PerspectiveProjection : public Projection {
public:
    double focal_length;

    PerspectiveProjection(double focal_length = 1.0) : focal_length(focal_length) {}

    Point3D project(const Point3D& p) const override {
        // Perform perspective projection
        double factor = focal_length / (focal_length + p.z);
        return Point3D(p.x * factor, p.y * factor, p.z);
    }
};

int main() {
    Object3D obj;

    cout << "Original object:" << endl;
    obj.draw();

    Transformation3D translation;
    translation.matrix[0][3] = 2; // Translate by 2 units in x-axis
    translation.matrix[1][3] = 1; // Translate by 1 unit in y-axis
    translation.matrix[2][3] = -3; // Translate by -3 units in z-axis
    obj.transform(translation);

    cout << "After translation:" << endl;
    obj.draw();

    Transformation3D rotation;
    double angle = 45 * M_PI / 180; // Convert to radians
    rotation.matrix[0][0] = cos(angle);
    rotation.matrix[0][1] = -sin(angle);
    rotation.matrix[1][0] = sin(angle);
    rotation.matrix[1][1] = cos(angle);
    obj.transform(rotation);

    cout << "After rotation:" << endl;
    obj.draw();

    Transformation3D scaling;
    scaling.matrix[0][0] = 2; // Scale by 2 in x-axis
    scaling.matrix[1][1] = 0.5; // Scale by 0.5 in y-axis
    scaling.matrix[2][2] = 3; // Scale by 3 in z-axis
    obj.transform(scaling);

    cout << "After scaling:" << endl;
    obj.draw();

    ParallelProjection parallelProjection;
    cout << "Parallel Projection:" << endl;
    for (int i = 0; i < obj.vertices.size(); i++) {
        Point3D projectedPoint = parallelProjection.project(obj.vertices[i]);
        cout << "(" << projectedPoint.x << ", " << projectedPoint.y << ")" << endl;
    }

    PerspectiveProjection perspectiveProjection(5); // Focal length = 5
    cout << "Perspective Projection:" << endl;
    for (int i = 0; i < obj.vertices.size(); i++) {
        Point3D projectedPoint = perspectiveProjection.project(obj.vertices[i]);
        cout << "(" << projectedPoint.x << ", " << projectedPoint.y << ")" << endl;
    }

    return 0;
}
