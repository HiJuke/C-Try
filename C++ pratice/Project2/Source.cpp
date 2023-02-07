#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件

#define MAX 1000

using namespace std;

//-----------------------------------------
//C++ 程序分為	全局區	和	代碼區
/*
//代碼區為共享+只讀
//全局區存放 全局變量 靜態變量 常量
//常量區中存放 const修飾的全局常量+字符串常量

//全局變量 靜態常量(static)	常量	在一個內存區間
//局部變量	在一個內存區間
*/

//-----------------------------------------

//全局區
/*
//全局變量
int g_a = 10;
int g_b = 10;

//const修飾的全局變量 全局常量
const int c_g_a = 10;
const int c_g_b = 10;
*/

/*
//全局變量 靜態變量 常量
//與局部變量地址規則
void class1() {
	//全局變量 靜態變量 常量

	//創建普通局部變量
	int a = 10;		int b = 10;
	cout << "局部變量a地址\t" << (int)&a << endl;
	cout << "局部變量b地址\t" << (int)&b << endl;

	//全局變量
	cout << "全局變量g_a地址\t" << (int)&g_a << endl;
	cout << "全局變量g_b地址\t" << (int)&g_b << endl;

	//靜態變量
	static int s_a = 10;
	static int s_b = 10;
	cout << "靜態變量s_a地址\t" << (int)&s_a << endl;
	cout << "靜態變量s_a地址\t" << (int)&s_a << endl;

	//可見全局變量跟靜態變量放置地址很接近

	//字符串常量地址
	cout << "字符串常量地址\t" << (int)&"Hello World!" << endl;

	//const修飾的變量
	//const修飾的全局變量
	cout << "const修飾的全局變量c_g_a地址\t" << (int)&c_g_a << endl;
	cout << "const修飾的全局變量c_g_b地址\t" << (int)&c_g_b << endl;

	//可見全局變量跟靜態變量即使型態不同放置地址也很接近



	//const修飾的局部變量
	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "const修飾的局部變量c_l_a地址\t" << (int)&c_l_a << endl;
	cout << "const修飾的局部變量c_l_a地址\t" << (int)&c_l_a << endl;

}
*/

//-----------------------------------------

//棧區 用以儲存局部變量
/*
//棧區數據注意事項 --- 不要返回局部變量的地址
//棧區數據由編譯器管理開闢&釋放
//棧區特性可運用於某些保密資訊

int * func(int b) {	//形參b也放在棧區
	b = 100;
	int a = 10;	//局部變量 存放在棧區 棧區的數據在函數執行完後自動釋放
	return &a;	//返回局部變量地址
}
*/

//堆區 由程序員管理分配釋放 若程序員不釋放 程序結束時由操作系統回收
/*
//C++中利用 new 在堆區中開闢內存	delete 釋放內存
int* fu() {
	//利用new
	int *p = new int(10);	//會返回new int(10)數據的地址
	//指針 仍為局部變量放置於棧區 但指針保存的數據位於堆區
	return p;	//這裡將堆區數據的地址編號 放置於棧區後回傳地址
}

void test01() {
	int* p = fu();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	//三次也沒烙賽
	//只要程序員不關閉堆區 堆區就不會釋放(除非程序停止)

	delete p;	//利用delete釋放堆區內存
	//cout << *p << endl;	//內存以釋放 再次執行便會出現報錯
}

void test02(){
	//創建10個整型數組 在堆區
	int *arr = new int[10];

	for (int i = 0; i < 10; i++) {
		arr[i] = i + 100;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}

	//釋放堆區數組
	delete[] arr;
}
*/



int main() {
	srand((unsigned int)time(NULL));

	//全局區測試
	//class1();
	
	//棧區測試
	/*
	int t = 3;
	int* p = func(t);
	cout << *p << endl;	//第一次可以顯示正確數據 因為編譯器做了保留
	cout << *p << endl;	//第二次就烙賽了
	*/


	//在堆區開闢數據
	/*
	test01();
	test02();
	*/



	system("pause");
	return 0;
}