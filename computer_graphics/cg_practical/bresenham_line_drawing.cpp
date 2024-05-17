#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <algorithm>
using namespace std;

void dda_draw(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1, dy = y2 - y1, p = 2 * dy - dx;
    while (x1 < x2) {
        putpixel(x1++, y1, WHITE);
        if (p >= 0) y1++, p += 2 * dy - 2 * dx;
        else p += 2 * dy;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setbkcolor(WHITE);
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    dda_draw(x1, y1, x2, y2);
    getch();
    closegraph();
    return 0;
}