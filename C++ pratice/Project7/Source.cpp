#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件

#define pi 3.14

using namespace std;

//類對象作為類成員
//Phone
class Phone {
public:
	Phone(string pName) { 
		m_PName = pName; 
		cout << "Phone Set" << endl;
	}

	~Phone(){ cout << "Phone Release." << endl; }
	string m_PName;

};
//Person
class Person1 {
public:
	Person1(string name, string pName): m_name(name), m_Phone(pName){
		cout << "Person Set" << endl;
		cout << m_name << "\t" << m_Phone.m_PName << endl;
	}
	~Person1() { cout << "Person Release." << endl; }

	string m_name;
	Phone m_Phone;
};
void test01() {
	Person1 p("Peter", "Apple");
}

//靜態成員: 靜態成員變量 靜態成員函數
/*
靜態成員變量
*所有對象共享同一份數據
*編譯階段分派內存
*類內聲明 類外初始化
-----------------------
靜態成員函數
*所有對象共享同一個函數
*靜態成員函數只能訪問靜態成員變量
*/
class Person2 {
public:
	//所有對象共享同一份數據
	//編譯階段分派內存
	//類內聲明 類外初始化
	static int m_A;
	int ns_A;
	//靜態成員函數
	static void func() {
		cout << "Static Func Use" << endl;
		m_A = 399;	//靜態成員函數可以訪問靜態成員變量
		//ns_A = 225;	//靜態成員函數不可訪問非靜態成員變量
	}

	//靜態成員變量也是有訪問權限的
private:
	static int m_B;
};
int Person2::m_A = 100;	//類內聲明 類外初始化
int Person2::m_B = 150;	//類內聲明 類外初始化

//所有對象共享同一份數據
void test02() {
	Person2 p;
	cout << p.m_A << endl;	//100
	Person2 p2;
	p2.m_A = 200;
	cout << p2.m_A << endl;	//100 ? 200
	cout << p.m_A << endl;	//發現p也變成200了 這就是所有對象共享同一份數據的意思
	cout << endl;
}

//靜態變量訪問方式
void test03() {
	//通過對象進行訪問
	Person2 p;
	cout << p.m_A << endl;	//100
	//通過類名訪問
	cout << Person2::m_A << endl;
	//cout << p.m_B << endl;	//類外訪問不到非public
	cout << endl;
}

//靜態成員函數
void test04() {
	//通過對象進行訪問
	Person2 p;
	p.func();
	//通過類名訪問
	Person2::func();
	//cout << p.m_B << endl;	//類外訪問不到非public
	cout << endl;
}

//-------------------------------------------




int main() {
	srand((unsigned int)time(NULL));

	//類對象作為類成員
	//test01();	//先建立被調用者 在建立調用者 ||| 先釋出調用者 再釋出被調用者

	//靜態成員: 靜態成員變量 靜態成員函數
	//test02();
	//test03();
	//test04();


	system("pause");
	return 0;
}