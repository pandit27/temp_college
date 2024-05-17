#include <graphics.h>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
};

void sutherlandHodgman(vector<Point>& polygon, int xmin, int ymin, int xmax, int ymax) {
    vector<Point> output;
    int n = polygon.size();
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        if (polygon[i].x >= xmin && polygon[i].x <= xmax && polygon[i].y >= ymin && polygon[i].y <= ymax)
            output.push_back(polygon[i]);
        if ((polygon[i].x >= xmin && polygon[next].x <= xmax) || (polygon[next].x >= xmin && polygon[i].x <= xmax)) {
            if (polygon[i].x == polygon[next].x) {
                if ((polygon[i].y >= ymin && polygon[next].y <= ymax) || (polygon[next].y >= ymin && polygon[i].y <= ymax))
                    output.push_back({polygon[i].x, ymax});
                else if ((polygon[i].y <= ymin && polygon[next].y >= ymax) || (polygon[next].y <= ymin && polygon[i].y >= ymax))
                    output.push_back({polygon[i].x, ymin});
            } else {
                int y = polygon[i].y + (polygon[next].y - polygon[i].y) * (xmin - polygon[i].x) / (polygon[next].x - polygon[i].x);
                if (polygon[i].x >= xmin && polygon[i].x <= xmax)
                    output.push_back({xmin, y});
                else
                    output.push_back({xmax, y});
            }
        }
    }
    polygon = output;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setbkcolor(WHITE);
    int xmin = 100, ymin = 100, xmax = 400, ymax = 300;
    rectangle(xmin, ymin, xmax, ymax);
    vector<Point> polygon = {{150, 200}, {250, 100}, {350, 200}, {250, 300}};
    for (int i = 0; i < polygon.size(); i++) {
        int next = (i + 1) % polygon.size();
        line(polygon[i].x, polygon[i].y, polygon[next].x, polygon[next].y);
    }
    sutherlandHodgman(polygon, xmin, ymin, xmax, ymax);
    setcolor(RED);
    for (int i = 0; i < polygon.size(); i++) {
        int next = (i + 1) % polygon.size();
        line(polygon[i].x, polygon[i].y, polygon[next].x, polygon[next].y);
    }
    getch();
    closegraph();
    return 0;
}