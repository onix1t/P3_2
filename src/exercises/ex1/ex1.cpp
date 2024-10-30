#include "ex1.h"

double distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool compareByX(const Point& p1, const Point& p2) {
    return p1.x < p2.x;
}

bool compareByY(const Point& p1, const Point& p2) {
    return p1.y < p2.y;
}

ClosestPairResult bruteForce(const vector<Point>& points, int left, int right) {
    ClosestPairResult result{};
    result.distance = numeric_limits<double>::infinity();
    
    for (int i = left; i < right; ++i) {
        for (int j = i + 1; j < right; ++j) {
            double dist = distance(points[i], points[j]);
            if (dist < result.distance) {
                result.distance = dist;
                result.point1 = points[i];
                result.point2 = points[j];
            }
        }
    }
    return result;
}

ClosestPairResult stripClosest(const vector<Point>& strip, double d) {
    ClosestPairResult result{};
    result.distance = d;

    vector<Point> sortedStrip = strip;
    sort(sortedStrip.begin(), sortedStrip.end(), compareByY);

    for (size_t i = 0; i < sortedStrip.size(); ++i) {
        for (size_t j = i + 1; j < sortedStrip.size() && (sortedStrip[j].y - sortedStrip[i].y) < result.distance; ++j) {
            double dist = distance(sortedStrip[i], sortedStrip[j]);
            if (dist < result.distance) {
                result.distance = dist;
                result.point1 = sortedStrip[i];
                result.point2 = sortedStrip[j];
            }
        }
    }
    return result;
}

ClosestPairResult closestUtil(vector<Point>& points, int left, int right) {

    if (right - left <= 3) {
        return bruteForce(points, left, right);
    }

    int mid = left + (right - left) / 2;
    ClosestPairResult leftResult = closestUtil(points, left, mid);
    ClosestPairResult rightResult = closestUtil(points, mid, right);

    ClosestPairResult result = (leftResult.distance < rightResult.distance) ? leftResult : rightResult;

    vector<Point> strip;
    for (int i = left; i < right; i++) {
        if (abs(points[i].x - points[mid].x) < result.distance) {
            strip.push_back(points[i]);
        }
    }

    ClosestPairResult stripResult = stripClosest(strip, result.distance);

    return (stripResult.distance < result.distance) ? stripResult : result;
}

ClosestPairResult closestPair(vector<Point>& points) {
    sort(points.begin(), points.end(), compareByX);
    return closestUtil(points, 0, points.size());
}
