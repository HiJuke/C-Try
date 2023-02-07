#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件

#define pi 3.14

using namespace std;

//----------------------------------------------------------------
//運算符重載
//加號運算符重載
class Person1 {
public:
	//成員函數加號運算符重載	本質為 Person p3 = p1.operator+(p2);
	/*
	Person1 operator+(Person1& p) {
		Person1 temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}
	*/
	int m_A;
	int m_B;
};
//全局函數加號運算符重載 本質為 Person p3 = operator+(p1, p2);
Person1 operator+(Person1& p1, Person1& p2) {
	Person1 temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
void test01() {
	Person1 P1;
	P1.m_A = 20;
	P1.m_B = 20;
	Person1 P2;
	P2.m_A = 20;
	P2.m_B = 20;

	Person1 P3 = P1 + P2;	
	cout << P3.m_A << "\t" << P3.m_B << endl;
}
//運算符重載也可發生函數重載
Person1 operator+(Person1& p1, int num) {
	Person1 temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}

//----------------------------------------------------------------
//左移運算符重載
class Person2 {
	friend ostream& operator<<(ostream& cout, Person2& p);
public:
	Person2(int a, int b) {
		m_A = a;
		m_B = b;
	}
private:
	//利用成員函數重載 左移運算符
	//結論 不會利用成員函數實現 左移運算符 因為無法實現cout 在左側
	int m_A;
	int m_B;
};
//全局函數重載左移運算符
ostream & operator<<(ostream&out, Person2 &p) {	//operator<<(cout, p) 簡化為 cout << p
	cout << p.m_A << "\t" << p.m_B << endl;
	return out;		//回傳cout為了實現鏈式編成 不然只能cout << p ; 不能 cout << p << endl; 之類的
}
void test02() {
	Person2 P1(22, 32);
	cout << P1 << endl;
}

//----------------------------------------------------------------
//遞增運算符重載
class MyInteger {
	friend ostream& operator<<(ostream& out, MyInteger p);
public:
	MyInteger() {
		m_Num = 0;
	}
	//前置++重載
	MyInteger& operator++() {	//必須以引用返回this 為了對一個數據一直遞增
		m_Num++;
		return *this;
	}

	//後置++重載
	MyInteger operator++(int) {		//int代表佔位參數 用於區分前置後置 現在是後置了 必須以數值返回
		MyInteger temp= *this;		//先 記錄當時結果
		m_Num++;					//後 遞增
		return temp;				//最後將紀錄結果返回				
	}

	//前置--重載
	MyInteger& operator--() {	//必須以引用返回this 為了對一個數據一直--
		m_Num--;
		return *this;
	}

	//後置--重載
	MyInteger operator--(int) {		//int代表佔位參數 用於區分前置後置 現在是後置了 必須以數值返回
		MyInteger temp = *this;		//先 記錄當時結果
		m_Num--;					//後 --
		return temp;				//最後將紀錄結果返回				
	}


private:
	int m_Num;
};
//先搞定左移重載
ostream& operator<<(ostream& out, MyInteger p) {	//operator<<(cout, p) 簡化為 cout << p
	cout << p.m_Num;
	return out;		//回傳cout為了實現鏈式編成 不然只能cout << p ; 不能 cout << p << endl; 之類的
}
void test03() {
	MyInteger mying;
	cout << ++(++mying) << endl;
	cout << mying << endl;
	cout << mying++ << endl;
	cout << mying << endl;
	cout << --(--mying) << endl;
	cout << mying << endl;
	cout << mying-- << endl;
	cout << mying << endl;
}

//----------------------------------------------------------------
//賦值運算符重載
//編譯器給類的四個函數 構造、析構、拷貝、賦值運算符 operator = 
class Person3 {
public:
	Person3(int a) {
		m_Age = new int(a);	//創建在堆區
	}
	~Person3() {		//將空間由堆區中釋放
		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL;
		}
	}

	//重載 賦值運算符
	Person3& operator= (Person3& p) {
		//應該先判斷是否有屬性在堆區 有的話先釋放乾淨 再深拷貝
		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);	//深拷貝
		return *this;
	}

	int* m_Age;
};
void test04() {
	Person3 p1(18);
	Person3 p2(28);
	Person3 p3(68);
	p2 = p1;	//系統預設的賦值操作導致同一堆區被重複釋放 會crash 所以要自己寫一個
	cout << "p1 =" << *p1.m_Age << endl;
	cout << "p2 =" << *p2.m_Age << endl;

	p3 = p2 = p1;
	cout << "p1 =" << *p1.m_Age << endl;
	cout << "p2 =" << *p2.m_Age << endl;
	cout << "p3 =" << *p2.m_Age << endl;
}

//----------------------------------------------------------------
//關係運算符重載
class Person4 {
public:
	Person4(int a, string name) {
		m_Name = name;
		m_Age = a;
	}
	~Person4() {	

	}

	//重載 賦值運算符
	bool operator== (Person4& p) {
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
			return true;
		}
		return false;
	}

	bool operator!= (Person4& p) {
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
			return false;
		}
		return true;
	}

	string m_Name;
	int m_Age;
};
void test05() {
	Person4 p1(22, "Peter");
	Person4 p2(22, "Peter");
	Person4 p3(32, "Eilly");
	if (p1 == p2) {
		cout << "Same" << endl;
	}
	if (p1 != p3) {
		cout << "Different" << endl;
	}
}

//----------------------------------------------------------------
//含數調用運算符重載
//仿函數很靈活沒有固定寫法
class MyPrint {
public:
	void operator()(string text) {
		cout << text << endl;
	}
};
class MyAdd {
public:
	int operator()(int a,int b) {
		return a+b;
	}
};
void test06() {
	//重載的()操作符也稱為仿函數
	MyPrint myFunc;
	myFunc("Welcome");
	MyAdd myAd;
	cout << myAd(6, 9) << endl;
	//匿名函數對象	寫法: 類名()(傳入值) --- 類名 + 小括號 + 輸入值
	cout << MyAdd()(8, 7) << endl;
}







int main() {
	srand((unsigned int)time(NULL));
	//加號運算符重載
	//test01();
	//左移運算符重載
	//test02();
	//遞增運算符重載
	//test03();
	//賦值運算符重載
	//test04();
	//關係運算符重載
	//test05();
	//含數調用運算符重載
	//test06();

	system("pause");
	return 0;
}
