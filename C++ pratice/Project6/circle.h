#pragma once
#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include "point.h"

#define pi 3.14

using namespace std;


class Circle {
public:
	double calculateZC();
	double calculateZP();
	void SetR(int R);
	void SetC(Point C);
	int GetR();
	Point GetC();

	void isInCircle(Point& p);
private:
	int m_r;
	Point m_Center;
};

