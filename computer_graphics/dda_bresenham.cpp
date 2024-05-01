#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<pair<int, int>> drawLineDDA(int x1, int y1, int x2, int y2) {
    vector<pair<int, int>> line;
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;
    if (abs(dx) > abs(dy)) steps = abs(dx);
    else steps = abs(dy);
    float xIncrement = float(dx) / steps;
    float yIncrement = float(dy) / steps;
    float x = x1, y = y1;

    for (int i = 0; i <= steps; i++) {
        line.push_back({round(x), round(y)});
        x += xIncrement;
        y += yIncrement;
    }
    return line;
}

vector<pair<int, int>> drawLineBresenham(int x1, int y1, int x2, int y2) {
    vector<pair<int, int>> line;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int slope = dy > dx ? 1 : -1;
    int swap = 0;

    if (dy > dx) {
        int temp = dx; dx = dy; dy = temp; swap = 1;
    }

    int D = 2 * dy - dx;
    int y = y1;

    for (int x = x1; x <= x2; x++) {
        line.push_back({x, y});
        if (D > 0) y += slope, D -= 2 * dx;
        D += 2 * dy;
    }
    return line;
}

int main() {
    int x1, y1, x2, y2;
    cout << "Enter Co-ordinates";
    cin >> x1 >> y1 >> x2 >> y2;

    vector<pair<int, int>> ddaLine = drawLineDDA(x1, y1, x2, y2);
    vector<pair<int, int>> bresenhamLine = drawLineBresenham(x1, y1, x2, y2);

    cout << "DDA Line: ";
    for (auto it : ddaLine) {
        cout << "(" << it.first << ", " << it.second << ") ";
    }
    cout << endl;

    cout << "Bresenham Line: ";
    for (auto it : bresenhamLine) {
        cout << "(" << it.first << ", " << it.second << ") ";
    }
    cout << endl;

    return 0;
}
