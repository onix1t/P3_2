#ifndef EX1_H
#define EX1_H

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

struct Point {
    double x, y;
};

struct ClosestPairResult {
    Point point1, point2;
    double distance;
};

int main();

double distance(const Point& p1, const Point& p2);
bool compareByX(const Point& p1, const Point& p2);
bool compareByY(const Point& p1, const Point& p2);
ClosestPairResult bruteForce(const vector<Point>& points, int left, int right);
ClosestPairResult stripClosest(const vector<Point>& strip, double d);
ClosestPairResult closestUtil(vector<Point>& points, int left, int right);
ClosestPairResult closestPair(vector<Point>& points);

#endif