#include "Snake.h"

using namespace std;

Snake::Snake(void)
	:m_width(50)
	,m_height(20)
	,m_boundary('#')
	,m_fruit('*')
	,m_HeadChar('O')
	,m_TailCHar('o')
	,m_isGameOver(false)
	,m_dir(STOP)
	,m_score(0)
{
	initializePoints();
}

Snake::Snake(int width, int height)
	: m_width(width)
	, m_height(height)
	,m_boundary('#')
	,m_fruit('*')
	,m_HeadChar('O')
	,m_TailCHar('o')
	, m_isGameOver(false)
	,m_dir(STOP)
	,m_score(0)
{
	initializePoints();
}

Snake::~Snake(void)
{
}

void Snake::initializePoints()
{
	this->m_headLocation.x = m_width/2;
	this->m_headLocation.y = m_height/2;
	updateFruitLocation();
}

void Snake::updateFruitLocation()
{
	this->m_fruitLocation.x= rand() %m_width;
	this->m_fruitLocation.y= rand() %m_height;
}

void Snake::play()
{
	while (!m_isGameOver)
	{
		draw();
		input();
		logic();
		Sleep(60);
	}
}

void Snake::draw()
{
	system("cls");
	for (int itr(0); itr < m_width+2; itr++)	// for the first row
		cout << m_boundary;
	cout << endl;

	for(int rowIndex(0); rowIndex < m_height; ++rowIndex)
	{
		for(int colIndex(0); colIndex < m_width; ++colIndex)
		{
			if(colIndex == 0)
				cout << m_boundary;

			Point tempPoint(colIndex, rowIndex);

			if(m_headLocation == tempPoint)
			{
				cout << m_HeadChar;
			}
			else if(m_fruitLocation == tempPoint)
			{
				cout << m_fruit;
			}
			else
			{
				bool print(false);
				for(int k(m_v_TailPoints.size() - 1); k >=0 ; k--)
				{
					if(m_v_TailPoints[k] == tempPoint)
					{
						cout << m_TailCHar;
						print = true;
					}
				}

				if (!print)
					cout << " ";
			}
			if(colIndex == m_width-1)
				cout << m_boundary;
		}
		cout << endl;
	}
	for (int itr(0); itr < m_width+2; itr++)	// for the last row
		cout << m_boundary;
	cout << endl;

	cout << "Score:" << m_score << endl;

	cout << endl;

	cout << "use w,a,s,d to control the snake" << endl;
	cout << "Hit x to exit" << endl;
}

void Snake::input()
{
	if(_kbhit()) //  to check if the keyboard is pressed
	{
		switch (_getch())
		{
		case 'a':

			m_dir = LEFT;
			break;

		case 'd':

			m_dir = RIGHT;
			break;

		case 'w':

			m_dir = UP;
			break;

		case 's':

			m_dir = DOWN;
			break;

		case 'x':

			m_isGameOver = true;
			break;
		default:
			break;
		}
	}
}

void Snake::logic()
{
	if(m_v_TailPoints.size())
	{
		Point previousPoint = m_v_TailPoints[0];
		Point previous2Point;
		m_v_TailPoints[0] = m_headLocation;

		for(int itr(1); itr < m_v_TailPoints.size(); ++itr)
		{
			previous2Point = m_v_TailPoints[itr];
			m_v_TailPoints[itr] = previousPoint;
			previousPoint = previous2Point;
		}
	}

	switch (m_dir)
	{
	case LEFT:

		m_headLocation.x--;
		break;

	case RIGHT:

		m_headLocation.x++;
		break;

	case UP:

		m_headLocation.y--;
		break;

	case DOWN:
		m_headLocation.y++;
		break;

	default:
		break;

	}

	if (m_headLocation.x > m_width || m_headLocation.x < 0 || m_headLocation.y > m_height || m_headLocation.y < 0)
		m_isGameOver = true;

	for(int itr(0); itr < m_v_TailPoints.size(); ++itr)
	{
		if(m_headLocation == m_v_TailPoints[itr])
		{
			m_isGameOver = true;
			break;
		}
	}

	if(m_headLocation == m_fruitLocation)
	{
		m_v_TailPoints.push_back(m_headLocation);
		m_score += 10;
		updateFruitLocation();
	}
}
