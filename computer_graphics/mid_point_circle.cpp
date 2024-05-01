#include <iostream>
#include <vector>
using namespace std;

void drawCircleMidpoint(int xc, int yc, int radius) {
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    vector<pair<int, int>> points;

    // Plot the initial point in each octant
    points.push_back({xc + x, yc + y});
    points.push_back({xc + x, yc - y});
    points.push_back({xc - x, yc + y});
    points.push_back({xc - x, yc - y});
    points.push_back({xc + y, yc + x});
    points.push_back({xc + y, yc - x});
    points.push_back({xc - y, yc + x});
    points.push_back({xc - y, yc - x});

    while (x < y) {
        x++;
        if (p < 0) p += 2 * x + 1;
        else {
            y--; p += 2 * (x - y) + 1;
        }
        // Plot the points in each octant
        points.push_back({xc + x, yc + y});
        points.push_back({xc + x, yc - y});
        points.push_back({xc - x, yc + y});
        points.push_back({xc - x, yc - y});
        points.push_back({xc + y, yc + x});
        points.push_back({xc + y, yc - x});
        points.push_back({xc - y, yc + x});
        points.push_back({xc - y, yc - x});
    }

    // Display the circle points
    cout << "Circle Points: ";
    for (auto it : points) {
        cout << "(" << it.first << ", " << it.second << ") ";
    }
    cout << endl;
}

int main() {
    int xc, yc, radius;
    cout << "Enter center coordinates: ";
    cin >> xc >> yc;
    cout << "Enter radius: ";
    cin >> radius;
    drawCircleMidpoint(xc, yc, radius);

    return 0;
}
