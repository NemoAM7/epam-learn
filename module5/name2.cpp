#include<iostream>
using namespace std;

namespace Geometry {
	struct Point {
		int x, y;
	};

	void printPoint(const Point& pt) {
		cout << "(" << pt.x << ", " << pt.y << ")";
	}
}

int main() {
	namespace G = Geometry;
	G::Point p{ 3, 4 };
	G::printPoint(p);
	return 0;
}
