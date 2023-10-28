#include <iostream>
using namespace std;

// ejercicio 1
class Rectangle
{
	public:
		Rectangle();
		Rectangle(float h, float w);
		~Rectangle();
		
		float CalculateArea();
		
	private:
		float _height;
		float _width;
};

Rectangle::Rectangle()
{
	_height = 1;
	_width = 1;
}

Rectangle::Rectangle(float h, float w)
{
	_height = h;
	_width = w;
}

Rectangle::~Rectangle()
{
}

float Rectangle::CalculateArea()
{
	return _height * _width;
}

// ejercicio 2
class Point
{
	public:
		Point();
		Point(float x, float y);
		~Point();
		
		void setX(float x);
		float getX();
		void setY(float y);
		float getY();
		
		void MovePoint(float new_x, float new_y);
		
	private:
		float _x;
		float _y;
};

Point::Point()
{
	_x = 0;
	_y = 0;
}

Point::Point(float x, float y)
{
	_x = x;
	_y = y;
}

Point::~Point()
{
}

void Point::setX(float x)
{
	_x = x;
}

void Point::setY(float y)
{
	_y = y;
}

float Point::getX()
{
	return _x;
}

float Point::getY()
{
	return _y;
}

void Point::MovePoint(float new_x, float new_y)
{
	cout << "Moving Point by:" << endl << _x-new_x << " in x axis" << endl << _y-new_y << " in y axis";
	_x = new_x;
	_y = new_y;
}

int main()
{
	Rectangle rec(5.2, 4.6);
	
	cout << "Area: " << rec.CalculateArea() << endl;
	
	Point po(5,3.5);
	
	po.MovePoint(1.76, 3.2);
	
	return 0;
}
