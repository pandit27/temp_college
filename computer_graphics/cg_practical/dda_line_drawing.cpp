#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <algorithm>
using namespace std;

void dda_draw(int x1, int y1, int x2, int y2) {
    float dx, dy, steps, Xinc, Yinc;
    dx = (float)(x2 - x2), dy = (float)(y2 - y1);
    steps = max(abs(dx), abs(dy));
    Xinc = dx / steps, Yinc = dy / steps;
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x1), round(y1), WHITE);
        x1 += Xinc, y1 += Yinc;
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