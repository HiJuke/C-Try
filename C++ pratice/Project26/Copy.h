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

#include"Sort.h"

//拷貝與替換算法
/*
copy		//容器指定範圍的元素拷貝到另一容器
replace		//容器指定範圍元素改為新元素
replace_if	//容器指定範圍滿足條件的元素改為新元素
swap		//兩容器元素互換
*/


//-------------------------------------------------------------
//copy		//容器指定範圍的元素拷貝到另一容器
//copy (begin, end, dest);		//dest 是目標容器迭代器
//可以直接等號賦值 沒必要在每個時候都用這東西

void testCopy() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "容器拷貝與替換 拷貝至另一容器 原容器 遍歷" << endl;

	//拷貝
	vector<int>v2;
	v2.resize(v.size());

	copy(v.begin(), v.end(), v2.begin());
	for_each(v2.begin(), v2.end(), MyPrint);
	cout << "容器拷貝與替換 拷貝至另一容器 目標容器 遍歷" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//replace	//容器指定範圍元素改為新元素
//replace (begin, end, Old_value, New_value);	//舊換新

void testReplace() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand()%2);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "容器拷貝與替換 指定替換 替換前 遍歷" << endl;

	//替換
	replace(v.begin(), v.end(), 0, 9);
	for_each(v.begin(), v.end(), MyPrint);
	cout << "容器拷貝與替換 指定替換 替換後 遍歷" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//replace_if	//容器指定範圍滿足條件的元素改為新元素
//replace_if (begin, end, _pred, New_value);	//又看到妳了 謂詞

class ReIfGreater {
public:
	bool operator()(int val) {
		return val > 2;		//大於2 替換
	}
};

void testReplaceIf() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand() % 5);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "容器拷貝與替換 條件替換 替換前 遍歷" << endl;

	//將大於 2 的數替換成 9
	replace_if(v.begin(), v.end(), ReIfGreater(), 9);
	for_each(v.begin(), v.end(), MyPrint);
	cout << "容器拷貝與替換 條件替換 替換後 遍歷" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//swap		//兩容器元素互換

void testSwap() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 4; i++)
	{
		v1.push_back((i+1)*11);
		v2.push_back((9 - i)*11);
	}
	for_each(v1.begin(), v1.end(), MyPrint);
	cout << "容器拷貝與替換 容器互換 替換前 容器1 遍歷" << endl;
	for_each(v2.begin(), v2.end(), MyPrint);
	cout << "容器拷貝與替換 容器互換 替換前 容器2 遍歷" << endl;

	//互換整活
	cout << "\t|" << endl;
	cout << "\t|" << endl;
	cout << "\t|" << endl;
	cout << "\tV" << endl;

	//互換
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), MyPrint);
	cout << "容器拷貝與替換 容器互換 互換後 容器1 遍歷" << endl;
	for_each(v2.begin(), v2.end(), MyPrint);
	cout << "容器拷貝與替換 容器互換 互換後 容器2 遍歷" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

