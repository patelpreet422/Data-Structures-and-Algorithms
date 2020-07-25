#include <algorithm>
#include <cfloat>
#include <cmath>
#include <iostream>
#include <tuple>
using namespace std;
struct Point {
  int x, y;
  friend ostream &operator<<(ostream &os, const Point &point) {
    return os << "(" << point.x << ", " << point.y << ")";
  }
};
inline double distance(const Point &p1, const Point &p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
tuple<Point, Point, double> naiveClosestPair(Point *points, int n, Point &p1,
                                             Point &p2) {
  double min_distance = DBL_MAX;
  double temp_distance = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      temp_distance = distance(points[i], points[j]);
      if (temp_distance < min_distance) {
        min_distance = temp_distance;
        p1 = points[i];
        p2 = points[j];
      }
    }
  }
  return {p1, p2, min_distance};
}
tuple<Point, Point, double> closestPair(Point *points, int low, int high,
                                        Point *strip, Point &p1, Point &p2) {
  int n = (high - low) + 1;
  if (n <= 3)
    return naiveClosestPair(points, n, p1, p2);

  int mid = (low + high) / 2;
  double left_d = get<2>(closestPair(points, low, mid, strip, p1, p2));
  double right_d = get<2>(closestPair(points, mid + 1, high, strip, p1, p2));
  double delta = min(left_d, right_d);

  int j = 0;
  for (int i = 0; i < n; ++i) {
    if (abs(points[mid].x - points[i].x) < delta)
      strip[j++] = points[i];
  }

  sort(strip, strip + j,
       [](const Point &p1, const Point &p2) { return p1.y < p2.y; });

  double strip_d = DBL_MAX;
  double temp_d = 0;
  for (int i = 0; i < j; ++i) {
    for (int k = i + 1; k < j && (strip[k].y - strip[i].y) < delta; ++k) {
      temp_d = distance(strip[i], strip[k]);
      if (temp_d < strip_d) {
        strip_d = temp_d;
        p1 = strip[i];
        p2 = strip[k];
      }
    }
  }
  double min_distance = min(strip_d, delta);
  return {p1, p2, min_distance};
}
tuple<Point, Point, double> closestPair(Point *points, int n) {
  Point p1, p2;
  Point strip[n];
  sort(points, points + n,
       [](const Point &p1, const Point &p2) { return p1.x < p2.x; });

  return closestPair(points, 0, n - 1, strip, p1, p2);
}
int main() {
  Point points[] = {{0, 0}, {-4, 1}, {-7, -2}, {4, 5}, {1, 1}};
  int n = sizeof(points) / sizeof(points[0]);
  cout << get<0>(closestPair(points, n)) << ", "
       << get<1>(closestPair(points, n)) << ": "
       << get<2>(closestPair(points, n)) << '\n';

  return 0;
}
