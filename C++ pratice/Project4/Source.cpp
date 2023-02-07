#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件

#define MAX 1000

using namespace std;

//引用 給變量起別名	也就是讓多個變數名稱同時代表同一塊內存 其中一個變數更改便更改所有變數
//語法: 變數類型 &別名 = 原名
//		int &b = a;
//1. 引用必須初始化-----int &b;不可以	必須int &b = 某個int
//2. 引用一旦初始化 便不可更改了	(b已引用a 便不能重新引用c)

//-------------------------------------------------------

//可以利用引用修飾函數傳遞參數 簡化指針修改
//值傳遞
void mySwap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
//位址傳遞
void mySwap02(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//引用傳遞
void mySwap03(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//-------------------------------------------------------

//引用作為函數返回值
//1. 不要返回局部變量的引用
int& test01() {
	int a = 10;
	return a;
}

//2. 函數調用可以做為左值
int& test02() {
	static int a = 10;	//靜態變量 存放在全局區 於程序結束後系統釋放
	return a;
}

//-------------------------------------------------------

//引用的本質在c++內部實現是一個指針常量
//發現函數為引用 轉換為 int* const ref = &a;
void func(int& ref) {
	ref = 2000;
}

//-------------------------------------------------------
//常量引用: 用來修飾形參 防止誤操作
//可以加const修飾
void showValue1(int& v) {
	v = 200;
	cout << v << endl;
}

void showValue2(const int& v) {
	//v = 200;		//用const阻礙更改 使更改報錯 防止誤操作
	cout << v << endl;
}


int main() {
	srand((unsigned int)time(NULL));

	//引用
	int a = 10;
	/*
	int& b = a;
	int& c = b;
	cout << a << endl;	//10
	b = 100;
	cout << a << endl;	//變100
	c = 500;
	cout << a << endl;	//變500
	cout << b << endl;	//變500
	*/
	/*
	//int& b;	//錯誤 必須初始化
	int& b = a;
	int c = 20;
	b = c;	//僅為賦值 不是更改引用 也不能更改
	cout << a << endl;	//20
	cout << b << endl;	//20
	cout << c << endl;	//20
	//b不可引用c 反而直接讓自己與引用的a被c賦值成為20
	*/
	/*
	int b = 20;
	//值傳遞
	mySwap01(a, b);
	cout << a << "\t" << b << endl;

	//位址傳遞
	//mySwap02(&a, &b);
	//cout << a << "\t" << b << endl;

	//引用傳遞
	mySwap03(a, b);
	cout << a << "\t" << b << endl;

	//可見引用作用於函數也可做到實際修改
	*/
	/*
	int& ref = test01();	//1. 不要返回局部變量的引用		引用局部變量測試
	cout << ref << endl;	//第一次有編譯器保護不會失去數值
	cout << ref << endl;	//第二次就被釋出 出現局部變量的數據錯誤 因為空間已被釋出

	int& ref2 = test02();
	cout << ref2 << endl;	//靜態變量 全局區空間未釋出 數據穩定
	cout << ref2 << endl;	//靜態變量 全局區空間未釋出 數據穩定
	//注意
	test02() = 1000;		//2. 函數調用可以做為左值	 函數回傳為引用a test02為引用
	cout << ref2 << endl;	//與引用一同改為1000
	cout << ref2 << endl;	//與引用一同改為1000
	*/
	/*
	int& ref = a;
	ref = 20;		//內部發現ref是引用 自動幫我們轉換為*ref = 20;
	cout << "a:" << a << "\tref:" << ref << endl;

	func(a);
	cout << "a:" << a << "\tref:" << ref << endl;
	*/
	/*
	//常量引用: 用來修飾形參 防止誤操作
	//int& ref = 10;	//錯誤 引用需飲一塊合法內存空間
	//const int & ref = 10;		//加入const 編譯器將代碼修改 int temp = 10;		const int & ref = temp;
	//ref = 20;		//加入const 之後為只讀 不可修改

	showValue1(a);
	cout << a << endl;	//發現a被有修改內容的函數影響了

	a = 10;
	showValue2(a);
	cout << a << endl;	//用const保護
	*/


	system("pause");
	return 0;
}