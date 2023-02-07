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

#include"Numeric.h"

//集合算法
/*
set_intersection	//兩容器交集
set_union			//兩容器聯集
set_different		//兩容器差集
*/
//注意 兩容器都必須為有序的


//-------------------------------------------------------------
//set_intersection		//兩容器交集
//set_intersection (begin1, end1, begin2, end2, dest);	//dest 為目標容器迭代器

void testSetItersection() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 15; i++)
	{
		v1.push_back(i+11);
		v2.push_back(i+16);
	}
	for_each(v1.begin(), v1.end(), MyPrint);
	cout << "集合算法 容器交集 原始容器1 遍歷" << endl;
	for_each(v2.begin(), v2.end(), MyPrint);
	cout << "集合算法 容器交集 原始容器2 遍歷" << endl;

	//兩容器交集
	vector<int> vTarget;
	vTarget.resize(min(v1.size(), v2.size()));	//以最特殊情況開闢空間 交集情況為較小容器的size

	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), MyPrint);
	cout << "集合算法 容器交集 依據目標容器 遍歷" << endl;
	for_each(vTarget.begin(), itEnd, MyPrint);
	cout << "集合算法 容器交集 依據回傳座標 遍歷" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//set_union		//兩容器聯集
//set_union(begin1, end1, begin2, end2, dest);

void testSetUnion() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 15; i++)
	{
		v1.push_back(i + 11);
		v2.push_back(i + 16);
	}
	for_each(v1.begin(), v1.end(), MyPrint);
	cout << "集合算法 容器聯集 原始容器1 遍歷" << endl;
	for_each(v2.begin(), v2.end(), MyPrint);
	cout << "集合算法 容器聯集 原始容器2 遍歷" << endl;

	//兩容器聯集
	vector<int> vTarget;
	vTarget.resize( v1.size() + v2.size());	//以最特殊情況開闢空間 聯集情況為兩者任一者所擁有的元素 最極端為兩者大小加總

	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), MyPrint);
	cout << "集合算法 容器聯集 依據目標容器 遍歷" << endl;
	for_each(vTarget.begin(), itEnd, MyPrint);
	cout << "集合算法 容器聯集 依據回傳座標 遍歷" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//set_difference		//兩容器差集
//set_difference(begin1, end1, begin2, end2, dest);

void testSetDifference() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 15; i++)
	{
		v1.push_back(i + 11);
		v2.push_back(i + 16);
	}
	for_each(v1.begin(), v1.end(), MyPrint);
	cout << "集合算法 容器差集 原始容器1 遍歷" << endl;
	for_each(v2.begin(), v2.end(), MyPrint);
	cout << "集合算法 容器差集 原始容器2 遍歷" << endl;

	//兩容器差集
	vector<int> vTarget;
	vTarget.resize(max(v1.size(), v2.size()));	//以最特殊情況開闢空間 差集情況為集合1中不與集合2重複的元素所組成的集合 最極端為兩者較大者的大小

	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), MyPrint);
	cout << "集合算法 容器差集 依據目標容器 遍歷" << endl;
	for_each(vTarget.begin(), itEnd, MyPrint);
	cout << "集合算法 容器差集 依據回傳座標 遍歷" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------



