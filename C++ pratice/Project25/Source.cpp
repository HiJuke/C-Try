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
#include<functional>

using namespace std;

//STL 函數對象 

//概念
/*
概念:
	- 重載函數調用操作符的類 其對象稱為函數對象
	- 函數對象使用重載時 行為類似函數調用 也稱為 仿函數
本質:
	- 仿函數 是一個類 不是函數
*/

//使用
/*
 - 使用時 可以像普通函數那樣調用 可以有參數 可以有返回值
 - 超出普通函數的概念 仿函數可以有自己的狀態
 - 可以做為參數傳遞
*/

//--------------------------------------------------------------------------
//函數對象基本使用
//1. 像普通函數那樣調用
class MyAdd {
public:
	int operator()(int a, int b) {
		return a + b;
	}
};
void test01() {
	MyAdd myadd;
	cout << myadd(22, 33) << endl;
}

//2. 超出普通函數概念 可以有自己的狀態
class MyPrint {
public:
	MyPrint(){
		this->count = 0;
	}
	void operator()(string test) {
		cout << test << endl;
		this->count++;	//更新自己的狀態
	}
	int count;	//內部自己的狀態
};
void test02() {
	MyPrint myprint;
	myprint("Hello World!!");
	myprint("Hello World!!");
	myprint("Hello World!!");
	myprint("Hello World!!");
	myprint("Hello World!!");
	cout << "myprint 調用次數為: " << myprint.count << endl;
}

//3. 可以做為參數傳遞
void doPrint(MyPrint& mp, string test) {
	mp(test);
}
void test03() {
	MyPrint myprint;
	doPrint(myprint, "Hello C++");
}

//--------------------------------------------------------------------------
//謂詞
/*
-- 返回bool 類型的仿函數稱為謂詞
-- 如operator 接受一個參數 稱為一元謂詞
-- 如operator 接受兩個參數 稱為二元謂詞
*/

//--------------------------------------------------------------------------
//一元謂詞
class GreaterFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};

void test04() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	//查找有無大於五的數字
	//GreaterFive 匿名函數對象
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end()) {
		cout << "沒找到" << endl;
	}
	else {
		cout << "找到了 該數值為: " << *it << endl;
	}
}

//--------------------------------------------------------------------------
//二元謂詞
class MyComFF {
public:
	bool operator()(int a, int b) {
		return a > b;
	}
};

void test05() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(rand()%90 +10);
	}
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "   ";
	}
	cout << endl<<"---------------------------------------------------------------------" << endl;

	//使用函數對象 改變算法測略 改成降序
	sort(v.begin(), v.end(), MyComFF());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "   ";
	}
	cout << endl << "---------------------------------------------------------------------" << endl;
}

//--------------------------------------------------------------------------
//內建函數對象
/*
概念:
	--STL內建的一些函數對象
分類:
	--算術仿函數
	--關係仿函數
	--邏輯仿函數
用法:
	--這些仿函數所產深的對象 用法和一般函數完全相同
	--使用內建函數對象 需要引入頭文件 #include<functional>
*/

//--------------------------------------------------------------------------
//內建函數對象-算數仿函數
/*
--實現四則運算
--其中negate 是一元運算 其他都是二元

template<class T> T plus<T>			//加法仿函數
template<class T> T minus<T>		//減法仿函數
template<class T> T multiplies<T>	//乘法仿函數
template<class T> T divides<T>		//除法仿函數
template<class T> T modulus<T>		//取模仿函數
template<class T> T negate<T>		//取反仿函數
*/

void test06() {
	//negate 一元仿函數 取反仿函數
	negate<int>n;
	cout << n(50) << endl;	//-50

	//plus 二元仿函數 加法
	plus<int> p;
	cout << p(20, 50) << endl;
}

//--------------------------------------------------------------------------
//內建函數對象-關係仿函數
/*
--實現關係對比

template<class T> bool equal_to<T>			//等於
template<class T> bool not_equal<T>			//不等於
template<class T> bool greater<T>			//大於
template<class T> bool greater_equal<T>		//大於等於
template<class T> bool less<T>				//小於
template<class T> bool less_equal<T>		//小於等於
*/

void test07(){
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
	//使用函數對象 改變算法測略 改成降序 不過這次改用關係運算符
	//sort(v.begin(), v.end(), MyComFF());
	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl << "---------------------------------------------------------------------" << endl;
}

//--------------------------------------------------------------------------
//內建函數對象-邏輯仿函數
/*
--實現邏輯運算

template<class T> bool logical_and<T>		//邏輯and
template<class T> bool logical_or<T>		//邏輯or
template<class T> bool logical_not<T>		//邏輯not
*/

void test08() {
	vector<bool> v;
	v.push_back(true);
	v.push_back(true);
	v.push_back(true);
	v.push_back(false);
	v.push_back(false);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;

	//利用邏輯not 將v 搬到另一個容器中 執行取反操作
	vector<bool>VV;
	//用此方法需要事先為另一個容器開闢空間
	VV.resize(v.size());

	transform(v.begin(), v.end(), VV.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = VV.begin(); it != VV.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}

//--------------------------------------------------------------------------


int main() {
	//照顧一下等等會用到的隨機數
	srand((unsigned int)time(NULL));

	//函數對象基本使用
	//test01();
	//test02();
	//test03();

	//一元謂詞
	//test04();

	//二元謂詞
	//test05();

	//內建函數對象-算數仿函數
	//test06();

	//內建函數對象-關係仿函數
	//test07();

	//內建函數對象-邏輯仿函數
	test08();



	system("pause");
	return 0;
}

