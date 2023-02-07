#include <iostream>
#include <string>
#include <ctime>	//	time 丁╰参繷ゅン

#define MAX 1000

using namespace std;

//ㄧ计矗蔼

//ㄧ计把计纐粄把计
/*
int func(int a, int b, int c = 20) {
	return a + b + c;
}
//猔種ㄆ兜
//1. 狦琘竚Τ纐粄把计 ぇオ常斗纐粄把计
	//int func(int a, int b = 30, int c){ return a + b + c;}		
	//岿粇 b纐粄把计 c碞ゲ斗琌
//2. 狦ㄧ计羘Τ纐粄把计, ㄧ计龟瞷碞ぃΤ纐粄把计
	//int func(int a, int b){}
	//int func(int a, int b){ return a+b; }
	//ㄧ计龟瞷碞ぃΤ纐粄把计 磅︽疧辽
*/

//ㄧ计把计把计
/*
void func(int a, int) {
	cout << "Test void." << endl;
}
*/

//ㄧ计更 ㄧ计嘿糤確ノ┦
/*
//ㄧ计更惠璶ㄧ计常ノ办
void func() {
	cout << "Func A Using~!" << endl;
}

void func(int a) {
	cout << "Func B Using~!" << endl;
}

void func(double a) {
	cout << "Func C Using~!" << endl;
}

void func(int a, double b) {
	cout << "Func D Using~!" << endl;
}

void func(double a, int b) {
	cout << "Func E Using~!" << endl;
}
//ㄧ计硓筁块Αぃ秸ノぃㄧ计

//ㄧ计ぃㄧ计更兵ン
int func(){ return 2 ;}
*/

//更猔種ㄆ兜
/*
//まノ更兵ン
void fun(int &a) {
	cout << "fun A using" << endl;
}

void fun(const int &a) {
	cout << "fun B using" << endl;
}
*/
//ㄧ计更笿纐粄ㄧ计
/*
void fun2(int a, int b = 20) {
	cout << "fun2 A" << endl;
}

void fun2(int a) {
	cout << "fun2 B" << endl;
}
*/


int main() {
	srand((unsigned int)time(NULL));

	//ㄧ计把计纐粄把计
	//ㄧ计Τ纐粄把计 ⊿肚薄猵蹦ノ纐粄计沮 Τ笆肚薄猵蹦ノ肚计沮
	/*
	cout << func(50, 40) << endl;		//110
	cout << func(50, 40, 30) << endl;	//120
	*/

	//ㄧ计把计把计
	/*
	//func(20);		  //把计惠Τ块 ぃ礛穦岿粇
	//func(20, 30);	//硂磅︽
	*/

	//ㄧ计更 ㄧ计嘿糤確ノ┦
	/*
	func();
	func(30);
	func(7.99);
	func(30, 7.99);
	func(7.99, 30);
	//ㄧ计硓筁块Αぃ秸ノぃㄧ计
	*/

	//更猔種ㄆ兜
	/*
	//まノ更兵ン
	int a = 20;
	fun(a);
	fun(20);
	*/

	//ㄧ计更笿纐粄ㄧ计
	/*
	//fun2(2);	  //絪亩竟穌ぃ来璶ノㄧ计 瞷竡┦
	//┮ㄧ计更荷秖ぃ璶笿纐粄ㄧ计 磷贺薄猵
	*/






	system("pause");
	return 0;
}