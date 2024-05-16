#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <algorithm>
using namespace std;

// function to draw line using dda line drawing algorithm
void ddaLineDraw(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));

    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;

    float x = x1;
    float y = y1;
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += Xinc;
        y += Yinc;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");  // Initialize graphics
    drawDDALine(50, 50, 200, 200);
    getch();
    closegraph();
    return 0;
}
