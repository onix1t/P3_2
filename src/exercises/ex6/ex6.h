#ifndef EX6_H
#define EX6_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct FeltPoint {
    double x, y;

    bool operator<(const FeltPoint& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

int orientation(const FeltPoint& a, const FeltPoint& b, const FeltPoint& c);
vector<FeltPoint> convexHull(vector<FeltPoint>& points);

#endif
