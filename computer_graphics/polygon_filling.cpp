#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Point {
public:
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

void drawLine(int x1, int y1, int x2, int y2, vector<vector<char>>& canvas) {
    int dx = abs(x2 - x1);
    int sx = 1;
    if (x1 >= x2) sx = -1;
    int dy = -abs(y2 - y1);
    int sy = 1;
    if (y1 >= y2) sy = -1;
    int err = dx + dy, e2;

    while (true) {
        canvas[y1][x1] = '#';
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) err += dy; x1 += sx;
        if (e2 <= dx) err += dx; y1 += sy;
    }
}

void fillPolygon(const vector<Point>& polygon, vector<vector<char>>& canvas) {
    for (size_t i = 0; i < polygon.size(); i++) {
        size_t next = (i + 1) % polygon.size();
        drawLine(polygon[i].x, polygon[i].y, polygon[next].x, polygon[next].y, canvas);
    }
}

void displayCanvas(const vector<vector<char>>& canvas) {
    for (auto it : canvas) {
        for (char itr : it) cout << itr;
        cout << endl;
    }
}

int main() {
    vector<Point> polygon = {Point(100, 50), Point(300, 100), Point(250, 200), Point(150, 250), Point(50, 200)};

    int minX = polygon.front().x, minY = polygon.front().y, maxX = polygon.front().x, maxY = polygon.front().y;
    for (auto it : polygon) {
        minX = min(minX, it.x);
        minY = min(minY, it.y);
        maxX = max(maxX, it.x);
        maxY = max(maxY, it.y);
    }

    vector<vector<char>> canvas(maxY + 1, vector<char>(maxX + 1, '.'));
    fillPolygon(polygon, canvas);
    displayCanvas(canvas);

    return 0;
}
