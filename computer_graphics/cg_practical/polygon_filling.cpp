#include <graphics.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

void findMinMaxX(const vector<Point>& polygon, int& minX, int& maxX) {
    minX = polygon[0].x;
    maxX = polygon[0].x;
    for (int i = 1; i < polygon.size(); i++) {
        minX = min(minX, polygon[i].x);
        maxX = max(maxX, polygon[i].x);
    }
}

void fillScanLine(int x1, int y1, int x2, int y2) {
    for (int x = x1; x <= x2; x++) putpixel(x, y1, RED);
}

void scanLineFill(const vector<Point>& polygon) {
    int minY = polygon[0].y;
    int maxY = polygon[0].y;
    findMinMaxX(polygon, minX, maxX);
    for (int i = 1; i < polygon.size(); i++) {
        minY = min(minY, polygon[i].y);
        maxY = max(maxY, polygon[i].y);
    }
    for (int y = minY; y <= maxY; y++) {
        vector<int> intersections;
        for (int i = 0; i < polygon.size(); i++) {
            int next = (i + 1) % polygon.size();
            int y1 = polygon[i].y;
            int y2 = polygon[next].y;
            if ((y1 <= y && y < y2) || (y2 <= y && y < y1)) {
                int x = polygon[i].x + (y - y1) * (polygon[next].x - polygon[i].x) / (y2 - y1);
                intersections.push_back(x);
            }
        }
        sort(intersections.begin(), intersections.end());
        for (int i = 0; i < intersections.size(); i += 2) {
            fillScanLine(intersections[i], y, intersections[i + 1], y);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setbkcolor(WHITE);
    vector<Point> polygon = {{200, 100}, {300, 200}, {250, 300}, {150, 300}, {100, 200}};
    for (int i = 0; i < polygon.size(); i++) {
        int next = (i + 1) % polygon.size();
        line(polygon[i].x, polygon[i].y, polygon[next].x, polygon[next].y);
    }
    scanLineFill(polygon);
    getch();
    closegraph();
    return 0;
}