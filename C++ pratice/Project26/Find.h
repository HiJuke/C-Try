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

#include"ForEach.h"

//查找算法
/*
find			//查找元素
find_if			//查找元素 按條件
adjacend_find	//查找元素 找相鄰重複
binary_cearch	//查找元素 二分查找法
count			//統計元素個數
count_if		//統計元素個數 按條件
*/

//-------------------------------------------------------------
//find			//查找元素
//find (begin(), end(), value);
//begin ~ end 之間找 value

//查找內置數據類型
void testFind01() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "查找函數 內置數據類型 原容器 遍歷" << endl;

	//查找容器中 使否有"5"存在
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end()) {
		cout << "未尋獲" << endl;
	}
	else {
		cout << "尋獲: " << *it << endl;
	}
	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//查找自訂數據類型
class FindPerson {
public:
	FindPerson(string name, int age) {
		m_name = name;
		m_age = age;
	}
	//在類中重載等號操作符 才能讓底層find 知道如何對比 FindPerson類型
	bool operator==(const FindPerson& p) {
		if (this->m_name == p.m_name && this->m_age == p.m_age) {
			return true;
		}
		else {
			return false;
		}
	}
	string m_name;
	int m_age;
};
void FindPersonPrint(FindPerson &p) {		//遍歷
	cout << p.m_name << "  " << p.m_age << endl;
}
void testFind02() {
	vector<FindPerson>v;
	string strName = { "ABCDEFGHIJ" };
	for (int i = 0; i < 10; i++)
	{	
		string tt = "Person";
		tt += strName[i];
		FindPerson p(tt, i * 10);
		v.push_back(p);
	}

	for_each(v.begin(), v.end(), FindPersonPrint);
	cout << "查找函數 自訂數據類型 原容器 遍歷" << endl;

	//查找容器中 使否有"PersonD,30"存在
	//此時需要在類中重載等號操作符 才能讓底層find 知道如何對比 FindPerson類型
	FindPerson p("PersonD", 30);
	cout << "尋找目標: " << p.m_name << "  Age = " << p.m_age << "\t\t";
	vector<FindPerson>::iterator it = find(v.begin(), v.end(), p);
	if (it == v.end()) {
		cout << "未尋獲" << endl;
	}
	else {
		cout << "尋獲: " << it->m_name << "  Age = "  << it->m_age << endl;
	}
	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//find_if			//查找元素 按條件
//find_if (begin(), end(), _Pred);
//begin ~ end 之間 _Pred函數或是謂詞(返回bool類型的仿函數)

//內置數據類型
class GreaterFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};
void testFindIf01() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "查找函數 按條件 內置數據類型 原容器 遍歷" << endl;

	//查找容器中 使否有大於5存在
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end()) {
		cout << "未尋獲" << endl;
	}
	else {
		cout << "尋獲大於5的數字為: " << *it << endl;
	}

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//自訂數據類型
class FindIfPerson {
public:
	FindIfPerson(string name, int age) {
		m_name = name;
		m_age = age;
	}
	//在類中重載操作符 才能讓底層find 知道如何對比 FindIfPerson類型
	bool operator==(const FindIfPerson& p) {
		return this->m_age == p.m_age;
	}
	
	string m_name;
	int m_age;
};
void FindIfPersonPrint(FindIfPerson& p) {		//遍歷
	cout << p.m_name << "  " << p.m_age << endl;
}
//謂詞
class FindIfGreater {
public:
	bool operator()(FindIfPerson& p) {
		return p.m_age > 40;
	}
};

void testFindIf02() {
	vector<FindIfPerson>v;
	string strName = { "ABCDEFGHIJ" };
	for (int i = 0; i < 10; i++)
	{
		string tt = "Person";
		tt += strName[i];
		FindIfPerson p(tt, i * 10);
		v.push_back(p);
	}
	for_each(v.begin(), v.end(), FindIfPersonPrint);
	cout << "查找函數 按條件 自訂數據類型 原容器 遍歷" << endl;

	//找年齡大於40歲的人 使用謂詞
	vector<FindIfPerson>::iterator it = find_if(v.begin(), v.end(), FindIfGreater());
	if (it == v.end()) {
		cout << "未尋獲" << endl;
	}
	else {
		while (it != v.end()) {
			cout << "尋獲大於 40年齡的成員為: " << it->m_name << "\t\tAge " << it->m_age << endl;
			it++;
		}
	}

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//adjacend_find	//查找元素 找相鄰重複
//adjacent_find(begin(), end());

void testAdjacendFind() {
	vector<int>v;
	for (int i = 0; i < 20; i++)
	{
		v.push_back(rand()%4);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "查找函數 找相鄰重複 內置數據類型 原容器 遍歷" << endl;

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end()) {
		cout << "未尋獲相鄰重複" << endl;
	}
	else {
		cout << "尋獲首位相鄰重複數為: " << *it << endl;
	}

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//binary_search	//查找元素 二分查找法 用bool 回覆指定元素是否存在 速度非常快
//bool binary_search (begin(), end(), value);
//不可用於無序序列 (必須為升序 或是 降序)

void testBinarySearch() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		if (i == 7) {
			int r = rand() % 2;
			if (r == 0) {
				v.push_back(8);
			}
			else {
				v.push_back(7);
			}
		}
		else {
			v.push_back(i);
		}
		
	}
	
	for_each(v.begin(), v.end(), MyPrint);
	cout << "查找函數 二分查找法 指定元素是否存在 內置數據類型 原容器 遍歷" << endl;

	//找找看容器中是否有元素"7"
	bool ret = binary_search(v.begin(), v.end(), 7);
	if (ret) {
		cout << "成功尋獲元素 7 " << endl;
	}
	else {
		cout << "未能尋獲元素 7 " << endl;
	}

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//count			//統計元素個數
//count(begin(), end(), value);

//內置數據類型
void testCount01() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand() % 3);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "查找函數 統計元素個數 內置數據類型 原容器 遍歷" << endl;
	//統計元素個數
	cout << "容器中 0 的個數為 " << count(v.begin(), v.end(), 0) << endl;
	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//自訂數據類型
void testCount02() {
	vector<FindIfPerson>v;
	string strName = { "ABCDEFGHIJ" };
	for (int i = 0; i < 10; i++)
	{
		string tt = "Person";
		tt += strName[i];
		FindIfPerson p(tt, rand()%3);
		v.push_back(p);
	}
	for_each(v.begin(), v.end(), FindIfPersonPrint);
	cout << "查找函數 統計元素個數 自訂數據類型 原容器 遍歷" << endl;

	//統計元素個數	尋找跟Target 一樣同為0的人
	//在類中重載等號操作符 才能讓底層find 知道如何對比 FindIfPerson類型
	FindIfPerson Target("Target", 0);	
	cout << "容器中 跟Target 一樣同為0的人 的個數為 " << count(v.begin(), v.end(), Target) << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//-------------------------------------------------------------
//count_if		//統計元素個數 按條件
//count(begin(), end(), _Pred);		//_Pred為謂詞

//內置數據類型
class CountIf01 {
public:
	bool operator()(int val) {
		return val > 3;
	}
};
void testCountIf01() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand() % 5+1);
	}
	for_each(v.begin(), v.end(), MyPrint);
	cout << "查找函數 統計元素個數 按條件 內置數據類型 原容器 遍歷" << endl;
	//統計 大於3 元素個數
	cout << "容器中 大於3 的個數為 " << count_if(v.begin(), v.end(), CountIf01()) << endl;
	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}

//自訂數據類型
class CountIf02 {
public:
	bool operator()(const FindIfPerson &p) {
		return p.m_age > 3;
	}
};
void testCountIf02() {
	vector<FindIfPerson>v;
	string strName = { "ABCDEFGHIJ" };
	for (int i = 0; i < 10; i++)
	{
		string tt = "Person";
		tt += strName[i];
		FindIfPerson p(tt, rand() % 5+1);
		v.push_back(p);
	}
	for_each(v.begin(), v.end(), FindIfPersonPrint);
	cout << "查找函數 統計元素個數 按條件 自訂數據類型 原容器 遍歷" << endl;

	//統計元素個數	尋找大於3的人
	//在類中重載等號操作符 才能讓底層find 知道如何對比 FindIfPerson類型
	cout << "容器中 大於3的人 的個數為 " << count_if(v.begin(), v.end(), CountIf02()) << endl;

	cout << "--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--" << endl;
}
