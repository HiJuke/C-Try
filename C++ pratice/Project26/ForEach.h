#pragma once
#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include <fstream>	//	文件操作系統頭文件
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

//遍歷算法
/*
for_each	//遍歷容器
transform	//搬運容器到另一個容器中
*/

//-------------------------------------------------------------
//for_each		//遍歷容器
//for_each(iterator begin, iterator end, _func);

//普通函數
void MyPrint(int val) {
	cout << val << "  ";
}
//仿函數
class print02 {
public:
	void operator()(int val) {
		cout << val << "  ";
	}
};

void testForEach() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	} 

	for_each(v.begin(), v.end(), MyPrint);		//普通函數
	cout << "普通函數 for_each 遍歷" << endl;

	for_each(v.begin(), v.end(), print02());	//仿函數
	cout <<"仿函數 for_each 遍歷"<< endl;
	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//transform		//搬運容器到另一個容器中
//transform(iterator begin1, iterator end1, iterator begin2, _func);
// (原容器欲搬運元素首位,  原容器欲搬運元素末位, 目標容器欲搬運至的位置, 函數或函數對象)

//普通函數
int MyTransform(int val) {
	return val + 500;
}

//仿函數
class Transform {
public:
	int operator()(int val) {
		return val+200;
	}
};

void testTransform() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i+100);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "原使容器 搬運容器 Transform" << endl;

	//普通函數
	vector<int>vTarget01;	//目標容器
	vTarget01.resize(v.size());	//目標容器需提前開闢空間

	transform(v.begin(), v.end(), vTarget01.begin(), MyTransform);
	for_each(vTarget01.begin(), vTarget01.end(), MyPrint);
	cout << "目標容器 搬運容器 Transform 普通函數" << endl;

	//仿函數
	vector<int>vTarget02;	//目標容器
	vTarget02.resize(v.size());	//目標容器需提前開闢空間

	transform(v.begin(), v.end(), vTarget02.begin(), Transform());
	for_each(vTarget02.begin(), vTarget02.end(), MyPrint);
	cout << "目標容器 搬運容器 Transform 仿函數" << endl;
	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}


