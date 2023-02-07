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

#include"Copy.h"

//算數生成法
//屬於小型算法 使用時頭文件為 #include <numeric>
//accumulate	//計算容器元素累計總合
//fill			//向容器中添加元素


//-------------------------------------------------------------
//accumulate	//計算容器元素累計總合
//accumulate(begin, end, value);	//value 為起始的累加數值
//此算法有第四個參數可輸入 可用於自定義類型 所需的仿函數 或函數輸入

void testAccumulate() {
	vector<int>v;
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i+1);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "算數生成法 累計總合 原始容器 遍歷" << endl;

	//累計總和		此為1~100的累加
	int total = accumulate(v.begin(), v.end(), 0);
	cout << "算數生成法 累計總合 累加為: "<< total << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//fill			//向容器中添加元素
//fill (begin, end, value);	//在begin ~ end 中填滿 value

void testFill() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "算數生成法 添加元素 原始容器 遍歷" << endl;

	//添加元素
	fill(v.begin() + 1, v.end() - 1, 5);
	for_each(v.begin(), v.end(), MyPrint);
	cout << "算數生成法 添加元素 完成添加 遍歷" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------