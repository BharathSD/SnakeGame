#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include <Windows.h>
#include "SnakeHeader.h"

class Snake
{
public:
	Snake(void);
	Snake(int width, int height);
	~Snake(void);
	void play();

private:
	bool m_isGameOver;
	const char m_boundary;
	const char m_fruit;
	const char m_HeadChar;
	const char m_TailCHar;
	const int m_width;
	const int m_height;
	int m_score;
	eDirecton m_dir;
	Point m_headLocation;
	Point m_fruitLocation;
	std::vector<Point> m_v_TailPoints;

	void initializePoints();
	void updateFruitLocation();

	void draw();
	void input();
	void logic();
};

