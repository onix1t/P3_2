#include "ex6.h"

int orientation(const FeltPoint& a, const FeltPoint& b, const FeltPoint& c) {
    double val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : -1;
}

vector<FeltPoint> convexHull(vector<FeltPoint>& points) {
    int n = points.size();
    if (n < 3) return points;

    sort(points.begin(), points.end());

    vector<FeltPoint> hull;

    for (const auto& p : points) {
        while (hull.size() >= 2 && orientation(hull[hull.size() - 2], hull[hull.size() - 1], p) != -1) {
            hull.pop_back();
        }
        hull.push_back(p);
    }

    size_t t = hull.size() + 1;
    for (int i = n - 1; i >= 0; --i) {
        while (hull.size() >= t && orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) != -1) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    hull.pop_back();

    return hull;
}
