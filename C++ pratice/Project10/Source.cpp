#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件

#define pi 3.14

using namespace std;

//繼承
//子類別繼承了上一代的特性 同時還有自己的特性
//可減少重複代碼
//語法 clase 子類 : 繼承方式 父類
//子類 也稱為 派生類
//父類 也稱為 基類

//----------------------------------------------------------------
//無繼承
/*
//Java 頁面
class Java {
public:
	void header() {
		cout << "首頁、課程、註冊...(頭部)" << endl;
	}
	void footer() {
		cout << "幫助、交流、地圖...(底部)" << endl;
	}
	void left() {
		cout << "Java、Pythin、C++...(左部)" << endl;
	}
	void contant() {
		cout << "Java Video Page." << endl;
	}
};
//Python 頁面
class Python {
public:
	void header() {
		cout << "首頁、課程、註冊...(頭部)" << endl;
	}
	void footer() {
		cout << "幫助、交流、地圖...(底部)" << endl;
	}
	void left() {
		cout << "Java、Pythin、C++...(左部)" << endl;
	}
	void contant() {
		cout << "Python Video Page." << endl;
	}
};
//C++ 頁面
class CPlus {
public:
	void header() {
		cout << "首頁、課程、註冊...(頭部)" << endl;
	}
	void footer() {
		cout << "幫助、交流、地圖...(底部)" << endl;
	}
	void left() {
		cout << "Java、Pythin、C++...(左部)" << endl;
	}
	void contant() {
		cout << "C++ Video Page." << endl;
	}
};
*/
//有繼承
//公共頁面類
class BasePage {
public:
	void header() {
		cout << "首頁、課程、註冊...(頭部)" << endl;
	}
	void footer() {
		cout << "幫助、交流、地圖...(底部)" << endl;
	}
	void left() {
		cout << "Java、Pythin、C++...(左部)" << endl;
	}
};
//Java 頁面
class Java : public BasePage{
public:
	void contant() {
		cout << "Java Video Page." << endl;
	}
};
//Python 頁面
class Python : public BasePage {
public:
	void contant() {
		cout << "Python Video Page." << endl;
	}
};
//C++ 頁面
class CPlus : public BasePage {
public:
	void contant() {
		cout << "C++ Video Page." << endl;
	}
};
void testJa() {
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.contant();
}
void testPh() {
	Python Ph;
	Ph.header();
	Ph.footer();
	Ph.left();
	Ph.contant();
}
void testCp() {
	CPlus cp;
	cp.header();
	cp.footer();
	cp.left();
	cp.contant();
}

//----------------------------------------------------------------
//繼承方式: 公有 保護 私有
/*
*父類別的private 子類別必定無法繼承訪問
公有: 父類別的 public protected 於子類別依舊
保護: 父類別的 public protected 於子類別變為protected  類別
私有: 父類別的 public protected 於子類別變為private  類別
*/
class Base1 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
//公共繼承
class Son1 : public Base1 {
public:
	void func() {
		m_A = 10;	//父類的public		依然是子類的public		可由任意者訪問
		m_B = 10;	//父類的protected	依然是子類的protected	可由類內函數訪問
		//m_C = 10;	//父類的pritave		禁止子類任意形式訪問	不可訪問所以會報錯
	}
};
void test01() {
	Son1 s1;
	s1.m_A = 100;	//父類的public		依然是子類的public		可由任意者訪問
	//s1.m_B = 100;	//父類的protected	依然是子類的protected	只可由類內函數訪問	類外不許訪問
}
//保護繼承 (protected)
class Son2 : protected Base1 {
public:
	void func() {
		m_A = 100;	//父類的public		此時為子類的protected	可由類內函數訪問
		m_B = 100;	//父類的protected	依然是子類的protected	可由類內函數訪問
		//m_C = 10;	//父類的pritave		禁止子類任意形式訪問	不可訪問所以會報錯
	}
};
void test02() {
	Son2 s1;
	//s1.m_A = 100;	//父類的public		此時為子類的protected	只可由類內函數訪問	類外不許訪問
	//s1.m_B = 100;	//父類的protected	依然是子類的protected	只可由類內函數訪問	類外不許訪問
}
//私有繼承 (pritave)
class Son3 : private Base1 {
public:
	void func() {
		m_A = 1000;	//父類的public		此時為子類的pritave		可由類內函數訪問
		m_B = 1000;	//父類的protected	依然是子類的pritave		可由類內函數訪問
		//m_C = 10;	//父類的pritave		禁止子類任意形式訪問	不可訪問所以會報錯
	}
};
void test03() {
	Son3 s1;
	//s1.m_A = 100;	//父類的public		此時為子類的pritave		只可由類內函數訪問	類外不許訪問
	//s1.m_B = 100;	//父類的protected	依然是子類的pritave		只可由類內函數訪問	類外不許訪問
}

//延伸 再次繼承 孫子出現了
class GrandSon3 : public Son3 {
public:
	void func() {
		//該數據在父類從爺類繼承時		已變成父類的pritave		禁止子類任意形式訪問	不可訪問所以會報錯
		//m_A = 10000;
		//m_B = 10000;
	}
};

//----------------------------------------------------------------
//繼承中的對象模型
class Base2 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;	//私有成員只是被隱藏 還是會繼承下去的
};
class Son4 : public Base2 {
public:
	int m_D;
};
void test04() {
	Son4 s1;
	//父類中所有非靜態成員都會被子類繼承下去 私有成員是被編譯器隱藏了
	cout << sizeof(Son4) << endl;	//答案為16	是四個int的大小 m_A ~ m_D 
}

//----------------------------------------------------------------
//繼承中構造和析構順序
class Base3 {
public:
	Base3() {
		cout << "父構造**" << endl;
	}
	~Base3() {
		cout << "父析構**" << endl;
	}
};
class Son5 : public Base3 {
public:
	Son5() {
		cout << "子構造--" << endl;
	}
	~Son5() {
		cout << "子析構--" << endl;
	}
};
void test05() {
	Son5 s1;	//先有父 再有子 子先關 父後關
}

//----------------------------------------------------------------
//同名成員處理
//* 訪問子類同名成員 直接訪問即可
//* 訪問父類同名成員 請加入作用域
class Base4 {
public:
	Base4() {
		m_A = 200;
	}
	void func() {
		cout << "父類別函數調用**" << endl;
	}
	void func(int a) {
			m_A = a;
	}
	int m_A;
};
class Son6 : public Base4 {
public:
	Son6() {
		m_A = 400;
	}
	void func() {
		cout << "子類別函數調用--" << endl;
	}
	void func(int a) {
		m_A = a;
	}
	int m_A;
};
void test06() {
	Son6 s1;
	cout << s1.m_A << endl;			//直接調用同名 會調用子類別
	s1.func();						//直接調用同名 會調用子類別
	cout << s1.Base4::m_A << endl;	//訪問父類同名成員 請加入作用域
	s1.Base4::func();				//訪問父類同名成員 請加入作用域
	s1.func(333);
	s1.Base4::func(222);
	cout << s1.m_A << endl;			//調用的子類同名 類內修改同名數據 只會修改自身
	cout << s1.Base4::m_A << endl;	//調用的父類同名 類內修改同名數據 只會修改自身
}

//----------------------------------------------------------------
//同名靜態成員處理
class Base5 {
public:
	static void func() {
		cout << "父類別靜態函數調用**" << endl;
	}
	static void func(int a) {
		cout << "父類別靜態函數 two 調用**" << endl;
		//m_A = a;
	}
	static int m_A;
};
int Base5::m_A = 200;
class Son7 : public Base5 {
public:
	static void func() {
		cout << "子類別靜態函數調用--" << endl;
	}
	static void func(int a) {
		cout << "子類別靜態函數 two 調用**" << endl;
		//m_A = a;
	}
	static int m_A;
};
int Son7::m_A = 400;
void test07() {
	//1. 通過對象訪問
	Son7 s1;
	cout << s1.m_A << endl;			//直接調用同名 會調用子類別
	s1.func();						//直接調用同名 會調用子類別
	cout << s1.Base5::m_A << endl;	//訪問父類同名成員 請加入作用域
	s1.Base5::func();				//訪問父類同名成員 請加入作用域
	cout << "------------------------------------------------" << endl;
	//2. 通過類名訪問
	cout << Son7::m_A << endl;
	Son7::func();
	cout << Son7::Base5::m_A << endl;	//第一個:代表通過子類類名方式訪問
	Son7::Base5::func();				//第二個:代表通過子類繼承的父類作用域訪問
	//通過類名不用宣告 Son7 s1;
}

//----------------------------------------------------------------
//多繼承語法	(開發時不建議)
class Base6 {
public:
	Base6() {
		m_A = 222;
	}
	int m_A;
};
class Base7 {
public:
	Base7() {
		m_A = 333;
	}
	int m_A;
};
//子類繼承兩個父類
class Son8 : public Base6, public Base7 {
public:
	Son8() {
		m_C = 300;
		m_D = 400;
	}
	int m_C;
	int m_D;
};
void test08() {
	Son8 s;
	cout << sizeof(s) << endl;	//兩個父各一int + 自己兩個int = 4, 4個int就是16的大小
	//當兩個父類別有重名的時候 要使用得靠作用域區分
	cout << "B6A: " << s.Base6::m_A << endl;
	cout << "B7A: " << s.Base7::m_A << endl;

}

//----------------------------------------------------------------
//菱形問題以及解決方法	(因為是多繼承 所以遇到這問題本身就不是很好)
/*
菱形繼承 A為BC兩者的父類 BC又同時為D的父類
		     +---(B父)---+
	(A爺)----|           |----(D孫)
		     +---(C父)---+
*/
//動物類
class Anima1 {
public:
	int m_Age;
};
//虛繼承 解決菱形繼承問題
//繼承前加上 virtual關鍵字	此時Animal稱為虛基類  
//羊
class Sheep :virtual public Anima1{};
//駝
class Tuo :virtual public Anima1{};
//羊駝
class SheepTuo : public Sheep, public Tuo{};
void test09() {
	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 20;
	cout << st.Sheep::m_Age <<"\t"<< st.Tuo::m_Age << "\t" << st.m_Age << endl;	//當菱形繼承 兩個父類有相同數據 需要加以作用域區分 但自己的呢??? 羊駝到底是幾歲
	//這份數據只要有一分就可以了 但菱形繼承導致數據有兩份 資源浪費
	//解決方式 虛繼承 請回370行
	//虛繼承後 兩者的m_Age 可視為共享 輸出的兩個m_Age都變成20了
}




int main() {
	srand((unsigned int)time(NULL));

	//公共頁面類
	//testJa();
	//testPh();
	//testCp();

	//繼承方式: 公有 保護 私有
	//test01();
	//test02();
	//test03();

	//繼承中的對象模型
	//test04();

	//繼承中構造和析構順序
	//test05();

	//同名成員處理
	//test06();

	//同名靜態成員處理
	//test07();

	//多繼承語法
	//test08();

	//菱形問題以及解決方法
	//test09();


	system("pause");
	return 0;
}
