#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Point
{
	Point(int x, int y):x(x), y(y) {}
	int x, y;
	friend std::ostream& operator<<(std::ostream& os, const Point &point)
	{
		return os << "(" << point.x << ", " << point.y << ")";
	}
};
double distance(Point &p1, Point &p2)
{
	return sqrt(pow((p1.x-p2.x), 2) + pow((p1.y-p2.y), 2));
}
const vector<Point> sortByX(const vector<Point> &points)
{
	vector<Point> temp = points;
	sort(temp.begin(), temp.end(), [](const auto &p1, const auto &p2) {return p1.x < p2.x; });
	return temp;
}
const vector<Point> sortByY(const vector<Point> &points)
{
	vector<Point> temp = points;
	sort(temp.begin(), temp.end(), [](const auto &p1, const auto &p2) {return p1.y < p2.y; });
	return temp;
}
class X
{
public:
	X() { std::cout << "X::X()" << std::endl; }
	X(X const &) { std::cout << "X::X( X const & )" << std::endl; }
	X& operator=(X const &) { std::cout << "X::operator=(X const &)" << std::endl; }
};
X f() {
	X tmp;
	return tmp;
}
int main()
{/*
	Point p1(1, 1);
	Point origin(0, 0);
	vector<Point> points{ p1, origin };
	auto sortedByX = sortByX(points);
	for (const auto &point : sortedByX)
	{
		cout << point << '\n';
	}*/
	X x = f();
	return 0;
}
