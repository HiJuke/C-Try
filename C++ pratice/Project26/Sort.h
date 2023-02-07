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

#include"Find.h"

//常用排序算法
/*
sort				//對容器內元素進行排序
random_shuffle		//洗牌 指定範圍元素隨機調整次序
merge				//容器元素合併  並儲存到另一容器中
reverse				//反轉指定範圍的元素
*/

class Person {
public:
	Person(string name, int age) {
		this->m_name = name;
		this->m_age = age;
	}

	string m_name;
	int m_age;
};

//-------------------------------------------------------------
//sort				//對容器內元素進行排序
//sort(begin(), end(), _Pred);	//_Pred可以不填 默認升序 要填的話得填謂詞

void testSort() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand()%10);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "容器排序 元素排序 排序前 遍歷" << endl;

	//排序 升序
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint);
	cout << "容器排序 排序後 升序 遍歷" << endl;

	//排序 降序
	sort(v.begin(), v.end(), greater<int>());	//greater 是 #include <functional> 內建的函數對象
	for_each(v.begin(), v.end(), MyPrint);
	cout << "容器排序 排序後 降序 遍歷" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//random_shuffle	//洗牌 指定範圍元素隨機調整次序
//random_shuffle(begin(), end())
//如果main 中沒有加入 srand((unsigned int)time(NULL)); 那麼會像沒加此行的rand一樣 說是隨機但每次洗牌後都一樣

void testRandomShuffle(){
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "容器排序 元素洗牌 排序前 遍歷" << endl;

	//洗牌
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint);
	cout << "容器排序 元素洗牌 洗牌後 遍歷" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//merge				//容器元素合併  並儲存到另一容器中
//merge (begin 1, end 1, begin 2, end 2, dest);		//dest 是目標容器
//兩個容器必須為有序的

void testMerge() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 8; i++)
	{
		v1.push_back(i);
		v2.push_back(i+1);
	}
	for_each(v1.begin(), v1.end(), MyPrint);
	cout << "容器排序 元素合併 容器1 遍歷" << endl;

	for_each(v2.begin(), v2.end(), MyPrint);
	cout << "容器排序 元素合併 容器2 遍歷" << endl;

	//容器合併
	vector<int>vTarget;
	vTarget.resize(v1.size() + v2.size());	//為目標容器開闢空間

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), MyPrint);
	cout << "容器排序 元素合併 目標容器 遍歷" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//reverse			//反轉指定範圍的元素
//reverse(begin(), end());

void testReverse() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "容器排序 元素反轉 反轉前 遍歷" << endl;

	//反轉元素
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint);
	cout << "容器排序 元素反轉 反轉後 遍歷" << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}
