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
#include <map>

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

//map / multimap
/*
簡介:
	-map中 所有元素皆為pair
	-map中 第一個元素為key 起到索引作用 第二個元素為value (實值)
	-所有元素都會根據元素的鍵值 自動排序
本質:
	-map / multimap 屬於 關聯式容器 底層結構是以二叉樹實現
優點:
	-可以根據 key 值 快速找到value值
map & multimap區別:
	-map 不允許容器有重複key 元素
	-multimap 允許容器有重複key 元素
*/

void printMap(const map<int, int>& mp) {
	for (map<int, int>::const_iterator it = mp.begin(); it != mp.end(); it++) {
		cout << "key = " << it->first << "\tvalue = " << it->second << endl;
	}
	cout << endl;
}


//----------------------------------------------------------------
//構造和賦值
/*
構造:
	map<T1, T2> mp:						//默認構造
	map(const map &mp);					//拷貝構造

賦值:	
	map& operator = (const map &mp);	//重載等號操作符
*/
//記住 map 是依據key值排序 不是依據value

void test01() {
	map<int, int> m;

	m.insert(pair<int, int>(1, 10));	//1 為用於索引的key 10則是實質的數值
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	printMap(m);
	//記住 map 是依據key值排序 不是依據value

	map<int, int> m2(m);
	printMap(m2);

	map<int, int> m3;
	m3 = m;
	printMap(m3);
}


//----------------------------------------------------------------
//大小和交換
/*
size();		//返回容器中元素數目
empty();	//返回容器是否為空
swap(st);	//交換兩個集合容器
*/
void test02() {
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));	//1 為用於索引的key 10則是實質的數值
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	printMap(m);

	if (m.empty()) {
		cout << "容器為空" << endl;
	}
	else {
		cout << "容器不為空 \t其大小為: " << m.size() << endl;
	}

	map<int, int> m2;
	m2.insert(pair<int, int>(10, 100));	//1 為用於索引的key 10則是實質的數值
	m2.insert(pair<int, int>(30, 300));
	m2.insert(pair<int, int>(20, 200));
	m2.insert(pair<int, int>(40, 400));
	printMap(m2);

	//交換
	m.swap(m2);
	cout << "m" << endl;
	printMap(m);
	cout << "m2" << endl;
	printMap(m2);
}

//----------------------------------------------------------------
//插入和刪除
/*
insert(ele);			-插入元素 ele
erase(pos);				-刪除迭代器指向的元素					返回下一個數據的位置
erase(start, end);		-刪除迭代器 start 到 end 之間的元素		返回下一個數據的位置
erase(key);				-刪除容器中key 值的元素
*/
void test03() {
	map<int, int> m;
	//插入
	//第一種
	m.insert(pair<int, int>(10, 100));
	m.insert(pair<int, int>(30, 300));
	m.insert(pair<int, int>(20, 200));
	m.insert(pair<int, int>(40, 400));
	//第二種
	m.insert(make_pair(15, 150));
	//第三種
	m.insert(map<int, int>::value_type(25, 250));
	//第四種
	m[35] = 350;
	printMap(m);

	//erase
	m.erase(++(++(++m.begin())));
	printMap(m);

	m.erase(++m.begin(), --m.end());
	printMap(m);

	m.erase(40);
	printMap(m);
}

//----------------------------------------------------------------
//查找和統計
/*
find(key);	//找key是否存在 存在的話返回該元素的迭代器 不存在的話返回set.end();
count(key);	//統計key 元素個數
*/
void test04() {
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));	//1 為用於索引的key 10則是實質的數值
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	printMap(m);

	map<int, int>::iterator pos = m.find(2);

	if (pos != m.end()) {
		cout << "目標key" << pos->first<< " 存在 \t數值為" << pos->second << endl;
	}
	else {
		cout << "目標key 不存在" << endl;
	}

	//map不可插入重複key 所以count做多為1
	//multimap就有可能有大於1 的count
	cout << m.count(3) << endl;
	cout << m.count(9) << endl;
}

//----------------------------------------------------------------
//排序
//利用仿函數改變排序規則
class MyCompare {
public:
	bool operator()(int a, int b) const {
		return a > b;
	}
};

void test05() {
	map<int, int, MyCompare> m;
	m.insert(pair<int, int>(1, 10));	//1 為用於索引的key 10則是實質的數值
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	

	for (map<int, int, MyCompare>::const_iterator it = m.begin(); it != m.end(); it++) {
		cout << "key = " << it->first << "\tvalue = " << it->second << endl;
	}
	cout << endl;
}

//----------------------------------------------------------------

int main() {
	//照顧一下等等會用到的隨機數
	srand((unsigned int)time(NULL));

	//構造和賦值
	//test01();

	//大小和交換
	//test02();

	//插入和刪除
	//test03();

	//查找和統計
	//test04();

	//排序
	test05();

	
	system("pause");
	return 0;
}


