#include <iostream>
#include <vector>
using namespace std;

class Point {
public:
    double x, y;
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
};

Point getIntersection(const Point& p1, const Point& p2, double xMin, double yMin, double xMax, double yMax, int side) {
    Point intersect;

    if (side == 0) {
        intersect.x = xMin;
        intersect.y = p1.y + (p2.y - p1.y) * (xMin - p1.x) / (p2.x - p1.x);
    } 
    else if (side == 1) {
        intersect.x = xMax;
        intersect.y = p1.y + (p2.y - p1.y) * (xMax - p1.x) / (p2.x - p1.x);
    } 
    else if (side == 2) {
        intersect.x = p1.x + (p2.x - p1.x) * (yMin - p1.y) / (p2.y - p1.y);
        intersect.y = yMin;
    } 
    else if (side == 3) {
        intersect.x = p1.x + (p2.x - p1.x) * (yMax - p1.y) / (p2.y - p1.y);
        intersect.y = yMax;
    }
    return intersect;
}

// Sutherland-Hodgman algorithm
vector<Point> sutherlandHodgman(const vector<Point>& polygon, double xMin, double yMin, double xMax, double yMax) {
    vector<Point> clippedPolygon = polygon;

    for (int side = 0; side < 4; side++) {
        vector<Point> input = clippedPolygon;
        clippedPolygon.clear();

        Point prev = input.back();

        for (const Point& current : input) {
            bool prevInside = (prev.x >= xMin && prev.x <= xMax && prev.y >= yMin && prev.y <= yMax);
            bool currentInside = (current.x >= xMin && current.x <= xMax && current.y >= yMin && current.y <= yMax);

            if (prevInside && currentInside) {
                clippedPolygon.push_back(current);
            } 
            else if (prevInside && !currentInside) {
                clippedPolygon.push_back(getIntersection(prev, current, xMin, yMin, xMax, yMax, side));
            } 
            else if (!prevInside && currentInside) {
                clippedPolygon.push_back(getIntersection(prev, current, xMin, yMin, xMax, yMax, side));
                clippedPolygon.push_back(current);
            }
            prev = current;
        }
    }
    return clippedPolygon;
}

void displayPoints(const vector<Point>& points) {
    for (auto it : points) cout << "(" << it.x << ", " << it.y << ") ";
    cout << endl;
}

int main() {
    vector<Point> polygon = {Point(50, 150), Point(200, 50), Point(350, 150), Point(350, 300), Point(250, 300), Point(200, 250), Point(150, 350), Point(100, 250), Point(100, 200)};

    double xMin = 100, yMin = 100, xMax = 300, yMax = 300;

    cout << "Original Polygon: ";
    displayPoints(polygon);

    vector<Point> clippedPolygon = sutherlandHodgman(polygon, xMin, yMin, xMax, yMax);

    cout << "Clipped Polygon: ";
    displayPoints(clippedPolygon);

    return 0;
}
