#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include <fstream>	//	文件操作系統頭文件
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <set>

using namespace std;

class Person {
public:
	Person(string name, int age) {
		this->m_name = name;
		this->m_age = age;
		//this->m_Height = height;
	}

	string m_name;
	int m_age;
	//int m_Height;
};
//----------------------------------------------------------------

//set/ multiset 容器			include <set>
//所有元素會再插入時被自動排序
//屬於關聯式容器 底層用二叉樹實現
//set		不允許容器中有重複元素
//multiset	可允許容器中有重複元素
void printSet(const set<int>& S) {
	for (set<int>::const_iterator it = S.begin(); it != S.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}

void printMsSet(const multiset<int>& S) {
	for (multiset<int>::const_iterator it = S.begin(); it != S.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}

//----------------------------------------------------------------
//賦值與構造函數
/*
set<T> S;			//默認構造函數	
set(const set &S);	//拷貝構造函數

set& operator = (const set &S);	//重載等號操作符
*/
void test01() {
	set<int> S;

	//1. set會自動排序
	//2. 若插入重複的數 會插入失敗 但依舊可執行 就是沒插進去
	S.insert(rand() % 100 + 1);
	S.insert(rand() % 100 + 1);
	S.insert(rand() % 100 + 1);
	S.insert(rand() % 100 + 1);
	S.insert(rand() % 100 + 1);
	printSet(S);

	//拷貝
	set<int>SS(S);
	printSet(SS);

	//賦值
	set<int>SSS;
	SSS = S;
	printSet(SSS);
}

//----------------------------------------------------------------
//大小操作與交換
/*
empty();		判斷容器是否為空
size();			返回容器中元素個數
swap(st);		交換兩個集合容器
*/
void test02() {
	set<int> S1;
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	printSet(S1);

	if (S1.empty()) {		//為真 代表容器為空
		cout << "S1為空" << endl;
	}
	else {
		cout << "S1不為空" << endl;
		cout << "大小為: " << S1.size() << endl;
	}

	cout << "------------------------------------------------------------" << endl;
	set<int> S2;
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);

	cout << "交換前" << endl;
	printSet(S1);
	printSet(S2);

	S1.swap(S2);
	cout << "交換後" << endl;
	printSet(S1);
	printSet(S2);

}

//----------------------------------------------------------------
//插入和刪除
/*
insert(ele);			-插入元素 ele							返回新元素位置
erase(pos);				-刪除迭代器指向的元素					返回下一個數據的位置
erase(start, end);		-刪除迭代器 start 到 end 之間的元素		返回下一個數據的位置
erase(ele);				-
clear();				-刪除容器中所有元素
*/
void test03() {
	set<int> S1;
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	printSet(S1);

	S1.erase(++(++S1.begin()));
	printSet(S1);

	S1.erase(++S1.begin(), S1.end());
	printSet(S1);

	cout << "------------------------------------------------------------" << endl;
	set<int> S2;
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);
	S2.insert(87);
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);
	printSet(S2);

	S2.erase(87);
	printSet(S2);

	S1.clear();
	S2.clear();
	printSet(S1);
	printSet(S2);

}

//----------------------------------------------------------------
//查找和統計
/*
find(key);		//查找元素key 是否存在 找到便會返回元素位置 不存在返回set.end();
count(key);		//統計key 元素個數 但因為set 不接受重複 所以只有 0 & 1
*/
void test04() {
	set<int> S1;
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(50);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	printSet(S1);

	set<int>::iterator pos1 = S1.find(50);
	set<int>::iterator pos2 = S1.find(30);
	if (pos1 != S1.end()) {
		cout << "找到50號" << endl;
	}
	else {
		cout << "沒找到50號" << endl;
	}

	if (pos2 != S1.end()) {
		cout << "找到30號" << endl;
	}
	else {
		cout << "沒找到30號" << endl;
	}

	//---------------------------------------------
	int num1 = S1.count(50);
	int num2 = S1.count(30);
	cout << "50 num = " << num1 << "\t30 num = " << num2 << endl;
}
//----------------------------------------------------------------
//set 和 multiset 區別
/*
set		不允許容器中有重複元素
multiset	可允許容器中有重複元素
multiset	不會檢測數據 所以可插入重複數據
*/
void test05() {
	set<int> S1;
	S1.insert(20);
	S1.insert(30);
	S1.insert(30);
	S1.insert(40);
	S1.insert(50);
	printSet(S1);
	//-----------------------------------------------------------------------
	pair<set<int>::iterator, bool> ret = S1.insert(60);
	if (ret.second) {
		cout << "插入成功" << endl;
	}
	else {
		cout << "插入失敗" << endl;
	}
	printSet(S1);
	//-----------------------------------------------------------------------
	ret = S1.insert(30);
	if (ret.second) {
		cout << "插入成功" << endl;
	}
	else {
		cout << "插入失敗" << endl;
	}
	printSet(S1);
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	cout << "multiset" << endl;
	multiset<int> MS;
	MS.insert(20);
	MS.insert(30);
	MS.insert(30);
	MS.insert(40);
	MS.insert(50);
	printMsSet(MS);
}
//----------------------------------------------------------------
//pair使用 pair對組的創建
//pair 成對出現數據 利用對組可以返回兩個數據
/*
pair<type, type> p (value1, value2);
pair<type, type> p = make_pair( value1, value2 );
*/
void test06() {
	pair<string, int> p1("Peter", 20);
	cout << "Name: " << p1.first << "\tAge: " << p1.second << endl;

	pair<string, int> p2 = make_pair("Frank", 72);
	cout << "Name: " << p2.first << "\tAge: " << p2.second << endl;
}

//----------------------------------------------------------------
//內置類型指定排序規則
//set默認由小排到大 如何改變排序規則?
//利用仿函數
class MyCompara {
public:
	//第一個()代表重載  第二個()代表數據格式
	//務必加入const 不然會報錯
	bool operator()(int v1, int v2) const {
		return v1 > v2;
	}
};

void test07() {
	set<int> S1;
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	S1.insert(rand() % 100 + 1);
	printSet(S1);

	//改成從大到小
	set<int, MyCompara> S2;
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);
	S2.insert(rand() % 100 + 1);
	for (set<int, MyCompara>::const_iterator it = S2.begin(); it != S2.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}
//----------------------------------------------------------------
//自定義數據類型 務必 指定排序規則

class comparePerson {
public:
	bool operator()(const Person& p1, const Person& p2) const {
		//依據年齡
		//降序
		return p1.m_age > p2.m_age;

		//升序
		//return p1.m_age < p2.m_age;
	}
};

void test08() {
	set<Person, comparePerson>S;

	Person P1("HumanA", 35);
	Person P2("HumanB", 45);
	Person P3("HumanC", 45);
	Person P4("HumanD", 76);
	Person P5("HumanE", 45);

	S.insert(P1);
	S.insert(P2);
	S.insert(P3);
	S.insert(P4);
	S.insert(P5);

	for (set<Person, comparePerson>::const_iterator it = S.begin(); it != S.end(); it++) {
		cout << "Name: "<< it->m_name << "\tAge: " << it->m_age << endl;
	}
	cout << endl;
}

//----------------------------------------------------------------


int main() {
	//照顧一下等等會用到的隨機數
	srand((unsigned int)time(NULL));

	//賦值與構造函數
	//test01();

	//大小操作與交換
	//test02();

	//插入和刪除
	//test03();

	//查找和統計
	//test04();

	//set 和 multiset 區別
	//test05();

	//pair使用 pair對組的創建
	//test06();

	//內置類型指定排序規則
	//test07();

	//自定義數據類型指定排序規則
	test08();

	system("pause");
	return 0;
}
