#include <iostream>
using namespace std;

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

int computeCode(int x, int y, int xMin, int yMin, int xMax, int yMax) {
    int code = INSIDE;

    if (x < xMin) code |= LEFT;
    else if (x > xMax) code |= RIGHT;
    if (y < yMin) code |= BOTTOM;
    else if (y > yMax) code |= TOP;

    return code;
}

void cohenSutherland(int x1, int y1, int x2, int y2, int xMin, int yMin, int xMax, int yMax) {
    int code1 = computeCode(x1, y1, xMin, yMin, xMax, yMax);
    int code2 = computeCode(x2, y2, xMin, yMin, xMax, yMax);
    bool accept = false;

    while (true) {
        if (!(code1 | code2)) {
            accept = true;
            break;
        } 
        else if (code1 & code2) break;
        else {
            int codeOut = code1 ? code1 : code2;
            int x, y;

            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                y = yMax;
            } 
            else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                y = yMin;
            } 
            else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
                x = xMax;
            } 
            else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
                x = xMin;
            }

            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1, xMin, yMin, xMax, yMax);
            } 
            else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2, xMin, yMin, xMax, yMax);
            }
        }
    }

    if (accept)
        cout << "Line accepted from (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << endl;
    else
        cout << "Line rejected" << endl;
}

int main() {
    int x1, y1, x2, y2;
    cout << "Enter line coordinates: ";
    cin >> x1 >> y1 >> x2 >> y2;
    cohenSutherland(x1, y1, x2, y2, 100, 100, 300, 300);

    return 0;
}
