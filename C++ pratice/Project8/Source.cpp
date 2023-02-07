#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件

#define pi 3.14

using namespace std;

//C++對象模型 & this指針

//類內的成員變量和成員函數分開存儲
//*只有非靜態成員變量才算是類的成員
class Person1 {};
void test01() {
	Person1 P;
	//空對象占用的內存空間 = 1 , 因為C++編譯器會給空對象也分配一字節的空間 , 是為了區分空對象佔內存的位置
	//每個空對象也應有獨一無二的內存地址
	cout << "Size of Person = " << sizeof(P) << endl;
}

class Person2 {
	int m_A;		//非靜態成員變量
	static int m_B;	//靜態成員變量
	void func(){}	//非靜態成員函數
};
void test02() {
	Person2 P;	//m_A屬於類內的成員變量 會影響類的空間大小 現在類變為 4 了
	//m_B 還有 func 分別屬於靜態成員變量 和 非靜態成員函數 與類內成員分開存儲 不影響sizeof(P)
	cout << "Size of Person = " << sizeof(P) << endl;
}
//----------------------------------------------
//this指針	不須定義 直接使用
//*當形參和成員變量同名時 可用this指針區分 解決名稱衝突
//*當類的非靜態成員函數中返回對象本身 可使用 return *this
class Person3 {
public:	
	Person3(int age) {
		//age = age;	//age因為重名 沒用this會導致構造函數的age皆非類內宣告的 測試時便出現亂碼
		this->age = age;	//利用this指定該age為此類內宣告的age 解決名稱衝突
	}

	Person3& PersonAddAge(Person3 &p) {
		this->age += p.age;
		return *this;	//this指向該類本體 就可做到test04的那個操作 但須回傳為Person3&引用才會是本體 回傳為Person3就不會是本體
	}

	int age;
};
void test03() {
	Person3 P1(22);
	cout << P1.age << endl;
}
void test04() {
	Person3 P1(2);
	Person3 P2(23);
	P2.PersonAddAge(P1);
	cout << P2.age << endl;
	P2.PersonAddAge(P1).PersonAddAge(P1).PersonAddAge(P1).PersonAddAge(P1);
	cout << P2.age << endl;
}
//----------------------------------------------
//空指針訪問成員函數
//*空指針也可調用成員函數 但要注意有無 this指針使用
class Person4 {
public:
	void showClassName() {
		cout << "Person class" << endl;
	}
	void showPersonAge() {
		if (this == NULL) { return; }	//沒加入此行便可能在空指針情況下出錯 此行可提升類型健壯性
		cout << "Age =" << m_Age << endl;	
	}
	int m_Age;
};
void test05(){
	Person4* p = NULL;
	p->showClassName();
	p->showPersonAge();	//空指針調用類內數值會導致出錯 因為空指針沒有實體數據
}

//----------------------------------------------
//const修飾成員函數
/*
常函數:
* 成完函數後加const 稱為常函數
* 常函數內不可修改成員屬性
* 成員屬性聲明時加關鍵字 mutable 後  在常函數中依然可以修改

常對象
* 聲明對象前加const 稱為常對象
* 成對象只能調用常函數
*/
//常函數
class Person5{
public:
	//this指針的本質 是指針常量 指針的指向不可以修改的
	//成員函數後面加const 指的是this指向 讓指針指向的數值也不可以修改
	void showPerson() { m_A = 100;}	//可修改數據
	void showPP() const { 
		//this->m_A = 100;	//加入const不可修改數值 this指針不可修改指針指向的
		this->m_B = 200;	//宣告數值時家入mutable 即可修改
	}	
	void func(){}

	int m_A;
	mutable int m_B;	//設計一個在常函數中也可以修改的 特殊變量
};
void test06() {
	Person5 p;
	p.showPP();
}
void test07() {
	const Person5 p;	//變為常對象
	//p.m_A = 166;		//延續常對象不可改數據的規則 會錯誤
	p.m_B = 299;		//宣告數值時有mutable 可修改

	//常對象不可調用普通函數 因為普通函數可修改數值
	p.showPP();			
	//p.func();		//會出錯	
}
//----------------------------------------------
//友元	關鍵字friend
//有些私有屬性想讓淚外特殊函數或類進行訪問 讓一個函數或類訪問另一個類中私有成員

//全局函數做友元
class Building1 {
	//定義goodGuy函數為此類別的友元 可以訪問私有成員
	friend void goodGuy(Building1* build);
public:
	Building1() {
		m_SittingRoom = "客廳";
		m_BedRoom = "臥室";
	}
	string m_SittingRoom;
private:
	string m_BedRoom;
};
void goodGuy(Building1* build) {
	cout << "正在訪問: " << build->m_SittingRoom << endl;
	cout << "正在訪問: " << build->m_BedRoom << endl;	//因為是友元 所以可訪問私有成員

}
void test08() {
	Building1 building;
	goodGuy(&building);
}

//類做友元
class Building2 {
	//定義GoodGuy2類為此類別的友元 可以訪問私有成員
	friend class GoodGuy2;
public:
	Building2() {
		m_SittingRoom = "客廳";
		m_BedRoom = "臥室";
	}
	string m_SittingRoom;
private:
	string m_BedRoom;
};
class GoodGuy2 {
public:
	GoodGuy2() {
		//創建建築物對象
		building = new Building2;
	}

	void visit() {	//參觀函數訪問 building2中的屬性
		cout << "正在訪問: " << building->m_SittingRoom << endl;
		cout << "正在訪問: " << building->m_BedRoom << endl;	//因為是友元類 所以可訪問私有成員
	}

	Building2* building;
};
void test09() {
	GoodGuy2 gg;
	gg.visit();
}

//成員函數做友元
class Building3;	//必須先定義 GoodGuy3才可以使用
class GoodGuy3 {	//必須定義於Building3給予友元之前 不然Building3只會找到未定義的GoodGuy3
public:
	GoodGuy3();

	void visit1();

	void visit2();

	Building3* building;	//需等待building3完成定義 所以選用指標
};	 
class Building3 {
	//定義GoodGuy3 visit1 函數為此類別的友元 可以訪問私有成員
	friend void GoodGuy3::visit1();
public:
	Building3();
	string m_SittingRoom;
private:
	string m_BedRoom;
};
Building3::Building3() {
	m_SittingRoom = "客廳";
	m_BedRoom = "臥室";
}
//以下需調用Building3者 需定義於Building3完整定義後
GoodGuy3::GoodGuy3() {
	//創建建築物對象
	building = new Building3;
}
void GoodGuy3::visit1() {	//可訪問Building3私有成員
	cout << "V1正在訪問: " << building->m_SittingRoom << endl;
	cout << "V1正在訪問: " << building->m_BedRoom << endl;	//因為是友元成員函數 所以可訪問私有成員
}
void GoodGuy3::visit2() {	//不可訪問Building3私有成員
	cout << "V2正在訪問: " << building->m_SittingRoom << endl;
	//cout << "V2正在訪問: " << building->m_BedRoom << endl;	//因為不是友元成員函數 所以不可訪問私有成員
}
void test10() {
	GoodGuy3 gg;
	gg.visit1();
	gg.visit2();
}




int main() {
	srand((unsigned int)time(NULL));

	//類內的成員變量和成員函數分開存儲
	//test01();
	//test02();
	//----------------------------------------------
	//this指針
	//test03();
	//test04();
	//----------------------------------------------
	//空指針訪問成員函數
	//test05();
	//----------------------------------------------
	//const修飾成員函數
	//test06();
	//test07();
	//----------------------------------------------
	//友元
	//test08();
	//test09();
	//test10();

	system("pause");
	return 0;
}
