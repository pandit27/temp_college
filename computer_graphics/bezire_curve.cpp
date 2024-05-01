#include <iostream>
#include <GL/glut.h>

class Point {
public:
    float x, y;
    Point(float _x, float _y) : x(_x), y(_y) {}
};b

Point p0(100, 100);
Point p1(200, 400);
Point r0(50, 50);
Point r1(150, 150);

void drawLine(Point p0, Point p1) {
    glBegin(GL_LINES);
    glVertex2f(p0.x, p0.y);
    glVertex2f(p1.x, p1.y);
    glEnd();
}

Point computeHermite(float t) {
    float t2 = t * t;
    float t3 = t2 * t;
    float h1 = 2 * t3 - 3 * t2 + 1;
    float h2 = -2 * t3 + 3 * t2;
    float h3 = t3 - 2 * t2 + t;
    float h4 = t3 - t2;

    Point result;
    result.x = h1 * p0.x + h2 * p1.x + h3 * r0.x + h4 * r1.x;
    result.y = h1 * p0.y + h2 * p1.y + h3 * r0.y + h4 * r1.y;
    return result;
}

Point computeBezier(float t) {
    float u = 1 - t;
    float t2 = t * t;
    float u2 = u * u;
    float u3 = u2 * u;
    float t3 = t2 * t;

    Point result;
    result.x = u3 * p0.x + 3 * u2 * t * p1.x + 3 * u * t2 * r0.x + t3 * r1.x;
    result.y = u3 * p0.y + 3 * u2 * t * p1.y + 3 * u * t2 * r0.y + t3 * r1.y;
    return result;
}

void drawCurve(void (*computeCurve)(float)) {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for (float t = 0; t <= 1; t += 0.01) {
        Point pt = computeCurve(t);
        glVertex2f(pt.x, pt.y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glOrtho(0, 500, 0, 500, -1, 1);
    drawCurve(computeHermite);
    glColor3f(0.0, 0.0, 1.0);
    drawLine(p0, r0);
    drawLine(p1, r1);
    drawCurve(computeBezier);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Hermite and Bezier Curves");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
