#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

int points[][3] = {{100, 100, 1}, {200, 100, 1}, {200, 200, 1}, {100, 200, 1}, {100, 100, 1}};
int num_points = sizeof(points) / sizeof(points[0]);

// Function to draw the object
void drawObject() {
    for (int i = 0; i < num_points - 1; i++) {
        line(points[i][0], points[i][1], points[i + 1][0], points[i + 1][1]);
    }
    line(points[num_points - 1][0], points[num_points - 1][1], points[0][0], points[0][1]);
}

// Function to perform translation
void translate(int tx, int ty) {
    int translationMatrix[3][3] = {{1, 0, tx}, {0, 1, ty}, {0, 0, 1}};
    for (int i = 0; i < num_points; i++) {
        int newX = translationMatrix[0][0] * points[i][0] + translationMatrix[0][1] * points[i][1] + translationMatrix[0][2] * points[i][2];
        int newY = translationMatrix[1][0] * points[i][0] + translationMatrix[1][1] * points[i][1] + translationMatrix[1][2] * points[i][2];
        points[i][0] = newX;
        points[i][1] = newY;
    }
}

// Function to perform rotation
void rotate(double angle) {
    double rad = angle * (M_PI / 180);
    int rotationMatrix[3][3] = {{cos(rad), -sin(rad), 0}, {sin(rad), cos(rad), 0}, {0, 0, 1}};
    for (int i = 0; i < num_points; i++) {
        int newX = rotationMatrix[0][0] * points[i][0] + rotationMatrix[0][1] * points[i][1] + rotationMatrix[0][2] * points[i][2];
        int newY = rotationMatrix[1][0] * points[i][0] + rotationMatrix[1][1] * points[i][1] + rotationMatrix[1][2] * points[i][2];
        points[i][0] = newX;
        points[i][1] = newY;
    }
}

// Function to perform scaling
void scale(double sx, double sy) {
    int scalingMatrix[3][3] = {{sx, 0, 0}, {0, sy, 0}, {0, 0, 1}};
    for (int i = 0; i < num_points; i++) {
        int newX = scalingMatrix[0][0] * points[i][0] + scalingMatrix[0][1] * points[i][1] + scalingMatrix[0][2] * points[i][2];
        int newY = scalingMatrix[1][0] * points[i][0] + scalingMatrix[1][1] * points[i][1] + scalingMatrix[1][2] * points[i][2];
        points[i][0] = newX;
        points[i][1] = newY;
    }
}

// Function to perform shearing
void shear(double shx, double shy) {
    int shearMatrix[3][3] = {{1, shx, 0}, {shy, 1, 0}, {0, 0, 1}};
    for (int i = 0; i < num_points; i++) {
        int newX = shearMatrix[0][0] * points[i][0] + shearMatrix[0][1] * points[i][1] + shearMatrix[0][2] * points[i][2];
        int newY = shearMatrix[1][0] * points[i][0] + shearMatrix[1][1] * points[i][1] + shearMatrix[1][2] * points[i][2];
        points[i][0] = newX;
        points[i][1] = newY;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setbkcolor(WHITE);
    drawObject();
    translate(50, 50);
    rotate(30); 
    scale(1.5, 1.5);
    shear(0.5, 0);
    drawObject();
    getch();
    closegraph();
    return 0;
}