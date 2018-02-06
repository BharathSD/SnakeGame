#pragma once
struct Point
{
	int x;
	int y;

	Point():x(0), y(0)
	{
	}

	Point(int px, int py):x(px), y(py)
	{
	}

	void swap(Point &pointData)
	{
		Point TempPoint = *this;
		*this = pointData;
		pointData = TempPoint;
	}

	bool operator==(Point& point)
	{
		return ((this->x == point.x) && (this->y == point.y));
	}
};

enum eDirecton 
{ 
	STOP = 0, 
	LEFT, 
	RIGHT, 
	UP, 
	DOWN
};