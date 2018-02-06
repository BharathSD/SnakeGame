#pragma once
#include <iostream>
#include <conio.h>
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
	const int m_width;
	const int m_height;
	int m_nTail;
	int m_score;
	eDirecton m_dir;
	Point m_headLocation;
	Point m_fruitLocation;
	Point m_TailPoints[100];

	void initializePoints();
	void updateFruitLocation();

	void draw();
	void input();
	void logic();
};

