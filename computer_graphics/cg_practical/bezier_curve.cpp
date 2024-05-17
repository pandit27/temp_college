#include <graphics.h>
#include <iostream>
using namespace std;

// function to calculate Hermite basis functions
double H(int i, double t) {
    if (i == 0) return 2 * t * t * t - 3 * t * t + 1;
    else if (i == 1) return -2 * t * t * t + 3 * t * t;
    else if (i == 2) return t * t * t - 2 * t * t + t;
    else return t * t * t - t * t;
}

// function to calculate Bezier basis functions
double B(int i, int n, double t) {
    double result = 1;
    for (int j = 0; j <= n; j++) {
        if (j != i) result *= (t - j) / (i - j);
    }
    return result;
}

// function to draw a Hermite curve
void drawHermiteCurve(int x0, int y0, int x1, int y1, int rx0, int ry0, int rx1, int ry1) {
    double step = 0.001;
    for (double t = 0; t <= 1; t += step) {
        double x = H(0, t) * x0 + H(1, t) * x1 + H(2, t) * rx0 + H(3, t) * rx1;
        double y = H(0, t) * y0 + H(1, t) * y1 + H(2, t) * ry0 + H(3, t) * ry1;
        putpixel(x, y, WHITE);
    }
}

// function to draw a Bezier curve
void drawBezierCurve(int x[], int y[], int n) {
    double step = 0.001;
    for (double t = 0; t <= 1; t += step) {
        double xval = 0, yval = 0;
        for (int i = 0; i <= n; i++) {
            xval += B(i, n, t) * x[i];
            yval += B(i, n, t) * y[i];
        }
        putpixel(xval, yval, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setbkcolor(WHITE);
    int x0 = 100, y0 = 100;
    int x1 = 300, y1 = 300;
    int rx0 = 150, ry0 = 200;
    int rx1 = 250, ry1 = 250;
    drawHermiteCurve(x0, y0, x1, y1, rx0, ry0, rx1, ry1);
    int xb[] = {100, 150, 250, 300};
    int yb[] = {400, 200, 200, 400};
    drawBezierCurve(xb, yb, 3);
    getch();
    closegraph();
    return 0;
}
