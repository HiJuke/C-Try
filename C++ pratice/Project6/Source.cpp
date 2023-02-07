#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include "circle.h"	//Circle & point + 把類放置其他文件中
#include "point.h"	//Circle & point + 把類放置其他文件中


#define pi 3.14

using namespace std;

//類和對象 封裝 繼承 多態
//public	類內可訪問	類外可訪問
//protected	類內可訪問	類外不可訪問 繼承的兒子可以訪問父類別的此類
//private	類內可訪問	類外不可訪問 繼承的兒子不可以訪問父類別的此類

//Class & Struct
//class		默認權限為private
//struct	默認權限為public

/*
//設計一個類: 學生
class Student {
public:
	void ShowInf(){
		cout << name << "\t" << StNumber << endl;
	}

	void SetName(string n) {
		name = n;
	}

	void SetId(int i) {
		StNumber = i;
	}

protected:
	string protect;

private:
	string name;
	int StNumber;
};

//設計一個類: Person
class Person {
public:
	
protected:
	string m_car;
private:
	string m_name;
	int m_Age = 0;
	string m_love;
	int m_Password;
public:
	void SetName(string i) {
		m_name = i;
	}
	void SetAge(int a) {
		m_Age = a;
	}
	void SetLove(string l) {
		m_love = l;
	}

	int GetAge() {
		return m_Age;
	}
	string GetName() {
		return m_name;
	}
	string GetLove() {
		return m_love;
	}

};

//設計一個類: 立方體
class Cube {
private:
	int mL, mW, mH;
public:
	void SetL(int l) {
		mL = l;
	}
	void SetW(int w) {
		mW = w;
	}
	void SetH(int h) {
		mH = h;
	}

	int GetL() {
		return mL;
	}
	int GetW() {
		return mW;
	}
	int GetH() {
		return mH;
	}

	//面積
	int calculateS() {
		return 2 * mL * mW + 2 * mW * mH + 2 * mL * mH;
	}
	//體積
	int calculateV() {
		return mL * mW * mH;
	}

	//利用成員函數判斷兩立方體是否相等
	bool ISC(Cube& c2) {
		if (GetH() == c2.GetH() && GetL() == c2.GetL() && GetW() == c2.GetW()) {
			return true;
		}
		return false;
	}

};

//利用全局函數判斷兩立方體是否相等
bool isSame(Cube& c1, Cube& c2) {
	if (c1.GetH() == c2.GetH() && c1.GetL() == c2.GetL()&& c1.GetW() == c2.GetW()){
		return true;
	}
	return false;
}
*/
//Circle & point
/*
class Point {
private:
	int x;
	int y;
public:
	void SetX(int X) {
		x = X;
	}
	void SetY(int Y) {
		y = Y;
	}

	int getX() { return x; }
	int getY() { return y; }


};

class Circle {
public:
	double calculateZC() {
		return 2 * pi * m_r;
	}
	double calculateZP() {
		return m_r * pi * m_r;
	}
	void SetR(int R) {
		m_r = R;
	}
	void SetC(Point C) {
		m_Center = C;
	}
	int GetR() { return m_r; }
	Point GetC() { return m_Center; }

	void isInCircle(Point& p) {
		int tX = p.getX()-m_Center.getX();
		int tY = p.getY()-m_Center.getY();
		int tR = tX * tX + tY * tY;
		if (tR > m_r * m_r) {
			cout << "Outside the Circle" << endl;
		}
		else if (tR == m_r * m_r) {
			cout << "On the Circle" << endl;
		}
		else {
			cout << "In the Circle" << endl;
		}
	}

private:
	int m_r;
	Point m_Center;
};
*/

//-----------------------------------------------
//構造函數 & 析構函數	Name(){}  &  ~Name(){}
/*
構造函數
* 沒有返回值 不寫void
* 名稱與類名相同
* 可以有參數 可重載
* 程序調用對象時會自動調用構造 無須手動 且只調用一次

析構函數
* 沒有返回值 不寫void
* 名稱與類名相同 加上~
* 不可以有參數 不可重載
* 程序在對象銷毀前自動調用析構 無須手動 且只調用一次
*/
/*
構造函數
分類方式: 
	參數:	有參數		無參數(默認構造)
	類型:	普通構造	拷貝構造
調用方式: 
	括號法		顯示法		隱式轉換法
*/

//拷貝構造函數調用時機
/*
1. 使用一個以創建完畢的對象來初始化一個新對象
2. 以值傳遞的方式給函數參數傳值
3. 值方式返回局部對象
*/

class Person {
public:
	//構造函數 & 析構函數須在public才可由外部調用
	Person() {		//無參構造(默認構造)
		age = 0;
		cout << "無參構造構造函數" << endl;
	}

	//傳統初始化操作
	Person(int a, int Height) {	//有參構造
		age = a;
		hight = new int(Height);
		cout << "有參構造構造函數" << endl;
	}

	//拷貝構造函數
	Person(const Person &P) {	//拷貝需加入 const 和 &引用
		age = P.age;
		//hight = P.hight;	//這行會導致堆區指針問題 編譯器默認實現就是此行
		//深拷貝操作
		hight = new int(*P.hight);
		cout << "拷貝構造函數" << endl;
	}

	//析構函數
	~Person() {
		if (hight != NULL) {
			delete hight;
			hight = NULL;
		}
		cout << "析構函數" << endl;
	}

	int getAge() { return age; }
	void setAge(int a) { age = a; }
	int* hight;
private:
	int age;
};

void textPerson() {
	//括號法
	/*
	Person P1;		//默認構造函數調用
	Person P2(20);	//有參構造函數調用
	Person P3(P2);	//拷貝構造函數調用
	cout << P1.getAge() << endl;
	cout << P2.getAge() << endl;
	cout << P3.getAge() << endl;
	//Person PP();	//調用默認構造函數時不要加() 會被編譯器認為是函數聲明
	*/
	//顯示法
	/*
	Person P1;		//默認構造函數調用
	Person P2 = Person(20);	//有參構造函數調用
	Person P3 = Person(P2);	//拷貝構造函數調用
	cout << P1.getAge() << endl;
	cout << P2.getAge() << endl;
	cout << P3.getAge() << endl;
	Person(10);	//單一Person(10)為匿名對象 特點:當前一行執行結束後 系統會立即回收掉匿名對象
	cout << "-----" << endl;	//可見上行在同一行就坐掉建立與釋放
	//Person(P3);	//不要用拷貝構造函數初始化匿名對象 編譯器會認為Person(P3) === Person P3; 導致重定義
	*/
	//隱式轉換法
	/*
	Person P1 = 20;	//等於寫了 Person P1 = Person(20);	有參構造函數調用
	Person P2 = P1; //拷貝構造
	*/		


}

//拷貝構造函數調用時機
/*
//1. 使用一個以創建完畢的對象來初始化一個新對象
void test01() {
	Person p1(20);
	Person p2(p1);
}
//2. 以值傳遞的方式給函數參數傳值
void dowork(Person p) {}
void test02() {
	Person p1;
	dowork(p1);
}
//3. 值方式返回局部對象
Person dowork2() {
	Person p1;
	return p1;
}
void test03() {
	Person p = dowork2();
}
*/

//構造函數調用規則
/*
C++編譯器在默認情況下添加的函數
默認構造函數
默認析構函數
默認拷貝構造函數
*/
/*-
//如果有定義構造函數 C++不提供默認構造函數 提供默認拷貝構造
//如果定義拷貝構造函數 C++不提供構造函數
void test00() {
	Person p;
	p.setAge(20);
	Person PP(p);
	cout << PP.getAge() << endl;
}
*/

//深拷貝 與 淺拷貝
/*
void test01() {
	Person p1(18, 160);
	cout << p1.getAge() << "\t" << *p1.hight << endl;
	Person p2(p1);
	cout << p2.getAge() << "\t" << *p2.hight << endl;
}
*/

//初始化列表
/*
class PList {
public:
	//初始化列表
	//PList() :a(20), b(200), c(2000) {}
	PList(int A,int B,int C) :a(A), b(B), c(C) {}
	int a, b, c;
	void testPList() {
		cout << a << "\t" << b << "\t" << c << endl;
	}
};
*/




int main() {
	srand((unsigned int)time(NULL));

	/*
	//創建圓
	/*
	Circle c1;
	c1.m_r = 20;
	cout << c1.calculateZC() << endl;
	*/

	//學生
	/*
	Student StA;
	StA.SetName("Peter");
	StA.SetId(3);
	StA.ShowInf();
	*/

	//立方體
	/*
	Cube c1;
	c1.SetH(10);
	c1.SetL(10);
	c1.SetW(10);
	cout << "C1\tS:\t" << c1.calculateS() << "\tV:\t" << c1.calculateV() << endl;

	Cube c2;
	c2.SetH(10);
	c2.SetL(10);
	c2.SetW(10);
	cout << "C2\tS:\t" << c2.calculateS() << "\tV:\t" << c2.calculateV() << endl;

	bool ret = isSame(c1, c2);
	if (ret) {
		cout << "兩者相等" << endl;
	}
	else {
		cout << "不一致" << endl;
	}
	ret = c1.ISC(c2);
	if (ret) {
		cout << "兩者相等" << endl;
	}
	else {
		cout << "不一致" << endl;
	}
	*/

	//Circle & point + 把類放置其他文件中
	/*
	Circle C;
	Point Pc;
	Point P;
	Pc.SetX(0);
	Pc.SetY(0);
	C.SetC(Pc);
	C.SetR(5);
	P.SetX(4);
	P.SetY(3);
	C.isInCircle(P);
	*/

	//-----------------------------------------------
	//構造函數 & 析構函數
	/*
	//Person p;
	textPerson();	//棧區的數據執行完畢後就會釋放 觸發析構函數
	*/
	//拷貝構造函數調用時機
	/*
	test01();
	test02();
	test03();
	*/
	/*
	test00();
	*/
	//深拷貝 與 淺拷貝
	/*
	test01();
	*/

	//初始化列表
	/*
	//PList p;
	PList p(23, 55, 69);
	p.testPList();
	*/





	system("pause");
	return 0;
}