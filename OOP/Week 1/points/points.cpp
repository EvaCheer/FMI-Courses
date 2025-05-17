#include <iostream>

struct Point {
	int x = 0;
	int y = 0;
};

Point readPoint() {

	int x, y;
	std::cout << "Insert point coordinates x and y: ";
	std::cin >> x >> y;
	Point a = { x,y };
	return a;
}

void printPoint(const Point& a) {
	std::cout << "Point's coordinates are x = " << a.x << " and y = " << a.y << std::endl;
	return;
}

double findDistanceToCenter(const Point& a) {
	return sqrt(a.x * a.x + a.y * a.y) * 1.0;
}

bool sameSign(const int& num1, const int& num2) {
	return num1 < 0 && num2 < 0 || num1>0 && num2>0;
}

int findSide(int num1, int num2) {
	if (sameSign(num1, num2)) {
		if (num1 > num2) {
			return abs(num1 - num2);
		}
		return abs(num2 - num1);
	}
	return abs(num1) + abs(num2);
}

double findDistanceBetweenPoints(const Point& p1, const Point& p2) {
	//to find he distance between two points, we first need
	//the sides of the rectangle that the two points define.
	double sideA = findSide(p1.x, p2.x);
	double sideB = findSide(p1.y, p2.y);
	return sqrt(sideA * sideA + sideB * sideB);
}

int main()
{
	Point a = readPoint();
	printPoint(a);
	double distanceToCenter = findDistanceToCenter(a);
	std::cout << "The distance from point 1 to the center is: " << distanceToCenter << std::endl;
	Point b = readPoint();
	printPoint(b);
	distanceToCenter = findDistanceToCenter(b);
	std::cout << "The distance from point 2 to the center is: " << distanceToCenter << std::endl;

	double distance = findDistanceBetweenPoints(a, b);
	std::cout << "The distance between the points is: " << distance << std::endl;


}
