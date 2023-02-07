#pragma once
#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件

#define pi 3.14

using namespace std;


//Circle & point
class Point {
private:
	int x;
	int y;
public:
	void SetX(int X) {
		x = X;
	}
	void SetY(int Y) {
		y = Y;
	}

	int getX() { return x; }
	int getY() { return y; }


};

