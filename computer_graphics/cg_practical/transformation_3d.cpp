#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

struct Point3D {
    int x, y, z;
};

// Define the 3D object vertices
Point3D vertices[] = {{-50, -50, -50}, {50, -50, -50}, {50, 50, -50}, {-50, 50, -50},
                      {-50, -50, 50}, {50, -50, 50}, {50, 50, 50}, {-50, 50, 50}};
int num_vertices = sizeof(vertices) / sizeof(vertices[0]);

// Function to draw the 3D object
void draw3DObject() {
    for (int i = 0; i < 4; i++) {
        line(vertices[i].x, vertices[i].y, vertices[(i + 1) % 4].x, vertices[(i + 1) % 4].y);
        line(vertices[i + 4].x, vertices[i + 4].y, vertices[((i + 1) % 4) + 4].x, vertices[((i + 1) % 4) + 4].y);
        line(vertices[i].x, vertices[i].y, vertices[i + 4].x, vertices[i + 4].y);
    }
}

// Function to perform translation
void translate3D(int tx, int ty, int tz) {
    for (int i = 0; i < num_vertices; i++) {
        vertices[i].x += tx;
        vertices[i].y += ty;
        vertices[i].z += tz;
    }
}

// Function to perform rotation about x-axis
void rotateX(int angle) {
    double rad = angle * (M_PI / 180);
    for (int i = 0; i < num_vertices; i++) {
        int newY = round(vertices[i].y * cos(rad) - vertices[i].z * sin(rad));
        int newZ = round(vertices[i].y * sin(rad) + vertices[i].z * cos(rad));
        vertices[i].y = newY;
        vertices[i].z = newZ;
    }
}

// Function to perform rotation about y-axis
void rotateY(int angle) {
    double rad = angle * (M_PI / 180);
    for (int i = 0; i < num_vertices; i++) {
        int newX = round(vertices[i].x * cos(rad) + vertices[i].z * sin(rad));
        int newZ = round(-vertices[i].x * sin(rad) + vertices[i].z * cos(rad));
        vertices[i].x = newX;
        vertices[i].z = newZ;
    }
}

// Function to perform rotation about z-axis
void rotateZ(int angle) {
    double rad = angle * (M_PI / 180);
    for (int i = 0; i < num_vertices; i++) {
        int newX = round(vertices[i].x * cos(rad) - vertices[i].y * sin(rad));
        int newY = round(vertices[i].x * sin(rad) + vertices[i].y * cos(rad));
        vertices[i].x = newX;
        vertices[i].y = newY;
    }
}

// Function to perform scaling
void scale3D(double sx, double sy, double sz) {
    for (int i = 0; i < num_vertices; i++) {
        vertices[i].x *= sx;
        vertices[i].y *= sy;
        vertices[i].z *= sz;
    }
}

// Function to apply parallel projection
void parallelProjection(double d) {
    for (int i = 0; i < num_vertices; i++) {
        vertices[i].x = vertices[i].x + vertices[i].z * d;
        vertices[i].y = vertices[i].y + vertices[i].z * d;
    }
}

// Function to apply perspective projection
void perspectiveProjection(double d) {
    for (int i = 0; i < num_vertices; i++) {
        vertices[i].x = vertices[i].x * d / (vertices[i].z + d);
        vertices[i].y = vertices[i].y * d / (vertices[i].z + d);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setbkcolor(WHITE);
    draw3DObject();
    translate3D(100, 100, 100);
    rotateX(30);
    rotateY(45);
    scale3D(2, 2, 2);
    draw3DObject();
    parallelProjection(2);
    draw3DObject();
    for (int i = 0; i < num_vertices; i++) {
        vertices[i].x = vertices[i].x * 100 / 2 + 320;
        vertices[i].y = vertices[i].y * 100 / 2 + 240;
    }
    perspectiveProjection(50);
    draw3DObject();
    getch();
    closegraph();
    return 0;
}