#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include <fstream>	//	文件操作系統頭文件
#include"person8.hpp"

using namespace std;

//針對泛型編成 和 STL 技術作詳細講解
//模板 temeplate
//建立通用的模具 大大提高複用性
//分為 函數模板 類模板


//-----------------------函數模板------------------------------
//函數模板基本語法
//template	聲明創建模板
//typename	表示其後方符號是一種數據類型 可以用class代替
// T		通用數據類型 名稱可替換 通成為大寫字母
template<typename T>	//函數聲明或定義	函數模板
void mySwap(T& a, T& b) {	//泡泡排序
	T temp = a;
	a = b;
	b = temp;
}
//兩種使用函數模板的方式
//1. 自動類型推導
//2. 顯示指定類型
void test01() {
	int a = 22;
	int b = 99;
	cout << " a= " << a << "\t b= " << b << endl;
	//兩種使用函數模板的方式
	//1. 自動類型推導
	mySwap(a, b);
	cout << " a= " << a << "\t b= " << b << endl;
	//2. 顯示指定類型
	mySwap<int>(a, b);
	cout << " a= " << a << "\t b= " << b << endl;
}

//--------------------------------------------------------
//函數模板注意事項
//自動類型推倒 必須推導出一致的數據類型T 才可以使用
//模板須確定出T 的數據類型 才可以使用
template<class T> //typename 可以替換成class class至少沒錯
void mySwap2(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
//1. 自動類型推導
void test02() {
	int a = 66;		//自動類型推倒 必須推導出一致的數據類型T 才可以使用
	int b = 33;		//如果b 的類型跟a 不同 比如b是 char 那麼就會不能使用 出錯
	cout << " a= " << a << "\t b= " << b << endl;
	mySwap(a, b);
	cout << " a= " << a << "\t b= " << b << endl;
}
//模板須確定出T 的數據類型 才可以使用
template<class T> //typename 可以替換成class class至少沒錯
void func1() {
	cout << "func 1 Using" << endl;
}
void test03() {
	//func();		//模板須確定出T 的數據類型 才可以使用 這裡會出錯
	func1<int>();	//這裡確認T為int類型 才可以使用
}

//--------------------------------------------------------
//函數模板案例 數組排序
//實現通用 對數組排序的函數 從大到小 選擇排序 測試char數組 int數組
template<class T> //typename 可以替換成class class至少沒錯
void mySort1(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (arr[i] < arr[j]) {
				mySwap(arr[i], arr[j]);
			}
		}
	}
}
template<class T>
void printArray(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void test04() {
	//測試char
	char charArr[] = "aerosekjd";
	mySort1(charArr, sizeof(charArr) / sizeof(char));
	printArray(charArr, sizeof(charArr) / sizeof(char));

	int intArr[] = { 8,6,7,44,55,99,87,36,220 };
	mySort1(intArr, sizeof(intArr) / sizeof(int));
	printArray(intArr, sizeof(intArr) / sizeof(int));
}

//--------------------------------------------------------
//普通函數與函數模板區別
/*
普通函數調用時可以發生自動類型轉換 (隱式類型轉換)
函數模板套用時 如果利用自動類型推倒 不會發生隱式類型轉換
如果利用顯示指定類型的方式 可以發生隱式類型轉換
*/

//普通函數
int Add01(int a, int b) {
	return a + b;
}
//函數模板
template<class T>
T Add02(T a, T b) {
	return a + b;
}

void test05() {
	int a = 22;
	int b = 33;
	char c = 'c';
	//普通函數
	cout << Add01(a, b) << endl;	// 55
	cout << Add01(a, c) << endl;	// 121 ??? 因為他把字符型變量轉成整型變量了 c對應的整型是99
	//函數模板 自動類型推倒
	cout << Add02(a, b) << endl;	// 55
	//cout << Add02(a, c) << endl;	// 類型不一致 函數模板報錯了
	//函數模板 指定類型推倒
	cout << Add02<int>(a, c) << endl;	//沒報錯了 因為指定類型把c 也變成了int類型 121 可發生隱式類型轉換
}

//--------------------------------------------------------
//普通函數與函數模板調用規則
//普通函數跟函數模板式可重載
/*
普通函數跟函數模板皆可實現 普通函數優先
可用空模板參數列表強制調用函數模板
函數模板也可重載
若函數模板可產生更好的匹配 先調用函數模板
*/
void myPrint(int a, int b)
{
	cout << "普通函數調用" << endl;
}

template<class T>
void myPrint(T a, T b) {
	cout << "函數模板調用" << endl;
}

template<class T>
void myPrint(T a, T b, T c) {
	cout << "函數模板重載調用" << endl;
}

void test06() {
	int a = 55;
	int b = 33;
	//普通函數跟函數模板皆可實現 普通函數優先
	myPrint(a, b);	
	//通過空模板參數列表  強制調用函數模板
	myPrint<>(a, b);
	//函數模板也可重載
	myPrint(a, b, 200);
	//若函數模板可產生更好的匹配 先調用函數模板
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);
}

//--------------------------------------------------------
//模板的侷限性
/*
//template<class T>
//void f(T a, T b) { a = b; }	//若 a b 為數組 就無法實現賦值

//template<class T>
//void f(T a, T b) { if( a > ){...} }	//若 a b 為自定義數據類型(class Person) 也無法正常運行
*/

class Person {
public:
	Person(string name, int age){
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

template<class T>
bool myCompare(T &a, T &b) {
	if (a == b) {	cout << "a == b" << endl;		return true; }
	else {			cout << "a != b" << endl;		return false; }
}

//提供具體化Person的重仔函數模板 在有Person的時候優先調用
template<> bool myCompare(Person& p1, Person& p2) {
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age) { cout << "Same Person" << endl;	return true; }
	else { cout << "Wrong Person" << endl;	return false; }
}

void test07() {
	int a = 20; 
	int b = 50;
	bool ret = myCompare(a, b);
}
void test08() {
	Person p1("Tom", 20);
	Person p2("Tom", 20);
	bool ret = myCompare(p1, p2);	//沒用具體化模板 便無法應付自定義特殊數據類型
}
//-----------------------函數模板------------------------------

//------------------------類模板-------------------------------
//類模板語法
//建立一通用類 類中成員 數據類型可以不具體制定 用一個虛擬的類型代表
//template<typename T>
//class...
template<class NameType, class AgeType>		//---+
class Person1 {								//   |
public:										//   |
	Person1(NameType name, AgeType age) {	//---+
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson() {
		cout << m_Name << "\t" << m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;
};

void test09() {	
	Person1<string, int>p1("Peter", 87);		//因為Person1的構造函數是用模板 沒有指定類型 所以在此指定<string, int>
	p1.showPerson();
}

//--------------------------------------------------------
//類模板與函數模板區別
//1. 類模板沒有自動類型推導的使用方式
//2. 類模板在模板參數列表中可以有默認參數
template<class NameType, class AgeType>		//---+
class Person2 {								//   |
public:										//   |
	Person2(NameType name, AgeType age) {	//---+
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson() {
		cout << m_Name << "\t" << m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;
};

//2. 類模板在模板參數列表中可以有默認參數
template<class NameType, class AgeType = int>		//---+
class Person3 {								//   |
public:										//   |
	Person3(NameType name, AgeType age) {	//---+
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson() {
		cout << m_Name << "\t" << m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;
};

void test10() {
	//1. 類模板沒有自動類型推導的使用方式
	//Person2 p1("Peter", 87);					
	Person2<string, int>p1("Peter", 87);		//因為Person1的構造函數是用模板 沒有指定類型 所以在此指定<string, int>
	p1.showPerson();
	//2. 類模板在模板參數列表中可以有默認參數
	Person3<string>p2("Eills", 23);				//因為template<class NameType, class AgeType = int>	後者已經決定數據型態 便不用指定
	p2.showPerson();							//默認參數只可用於類模板 函數模板做不到
}

//--------------------------------------------------------
//類模板中函數成員創建時機
// * 普通類中成員函數可於一開始創建
// * 類模板中成員函數調用時才會創建
class Person4 {
public:
	void showPerson4() {
		cout << "Show Person4." << endl;
	}
};
class Person5 {
public:
	void showPerson5() {
		cout << "Show Person5." << endl;
	}
};

template<class T>
class MyClass {
public:
	T obj;

	//類模板中成員函數
	//這兩個成員函數 看似會編譯錯誤 但實際不會 因為類模板成員函數調用時才會創建
	void func4() {
		obj.showPerson4();
	}
	void func5() {
		obj.showPerson5();
	}
};

void test11() {
	MyClass<Person4>m;
	m.func4();		//此行為Person4的函數 類型對上就可執行
	//m.func5();	//類型不對就會出錯
}

//--------------------------------------------------------
//類模板對象做函數參數
//1. 指定傳入類型	---	直接顯示對象的數據類型
//2. 參數模板化		---	將對象中的參數變為模板進行傳遞
//3. 整個類模板化	---	將此對象類型 模板化進行傳遞
template<class T1, class T2>			//---+
class Person6 {							//   |
public:									//   |
	Person6(T1 name, T2 age) {			//---+
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson() {
		cout << m_Name << "\t" << m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;
};
//1. 指定傳入類型	---	直接顯示對象的數據類型
void printPerson1(Person6<string, int >& p) {
	p.showPerson();
}
//2. 參數模板化		---	將對象中的參數變為模板進行傳遞
template<class T1, class T2>
void printPerson2(Person6<T1, T2 >p) {
	p.showPerson();
}
//3. 整個類模板化	---	將此對象類型 模板化進行傳遞
template<class T>
void printPerson3(T &p) {
	p.showPerson();
}

void test12() {
	Person6<string , int >p("Juke", 23);
	printPerson1(p);
	printPerson2(p);
	printPerson3(p);
}

//--------------------------------------------------------
//類模板與繼承
// 1. 子類繼承的父類為類模板時  資類在聲明的時候  要指出父類中的類型
// 2. 如果不指定 編譯器無法分配內存
// 3. 如果想靈活指定父類中的類型 子類也需為類模板
template<class T>
class Base {
	T m;
};
//子類別必須要指出父類中的類型
class Son : public Base<int> {	//子類別必須要指出父類中的類型

};
//如果想靈活指定父類中的類型 子類也需為類模板
template<class T1, class T2>
class Son2 : public Base<T2> {	
	T1 obj;
};

void test13() {
	Son s1;
	Son2<int, char> S2;		//把char傳給Son2的template 再由Base<T2>將char類型定義給父類別的template
}

//--------------------------------------------------------
//類模板成員函數類外實現
template<class T1, class T2>
class Person7 {
public:
	Person7(T1 name, T2 age);

	void showPerson();

	T1 m_Name;
	T2 m_Age;
};
template<class T1, class T2>
Person7<T1, T2>::Person7(T1 name, T2 age) {
	this->m_Name = name;
	this->m_Age = age;
}
template<class T1, class T2>
void Person7<T1, T2>::showPerson() {
	cout << m_Name << "\t" << m_Age << endl;
}

void test14() {
	Person7<string, int> p("Jess", 20);
	p.showPerson();
}

//--------------------------------------------------------
//類模板分文件編寫
//問題: 類模板成員函數於調用階段創建 導致分文件時連接不到
//解1: 直接包含cpp源文件	(不常見不建議的方法)
//解2: 將聲明和實現寫到同一份文件裡 更改後墜名為.hpp (後墜名不是強制)
/*
template<class T1, class T2>
class Person8 {
public:
	Person8(T1 name, T2 age);

	void showPerson();

	T1 m_Name;
	T2 m_Age;
};
template<class T1, class T2>
Person8<T1, T2>::Person8(T1 name, T2 age) {
	this->m_Name = name;
	this->m_Age = age;
}
template<class T1, class T2>
void Person8<T1, T2>::showPerson() {
	cout << m_Name << "\t" << m_Age << endl;
}
*/
void test15() {
	//解1: 直接包含cpp源文件	(不常見不建議的方法)
	//開頭 include person8.h 時會錯誤 person.cpp時就不會 因為後者會讓編譯器事先看過所有文件 便可以順利調用
	//但這種作法不常見
	//Person8<string, int> p("Jess", 20);
	//p.showPerson();

	//解2: 將聲明和實現寫到同一份文件裡 更改後墜名為.hpp (後墜名不是強制)
	Person8<string, int> p("Jess", 20);
	p.showPerson();
}

//--------------------------------------------------------
//類模板和友元 (類內直接寫 類外要先讓編譯器知道全局函數的存在)

//提前讓編譯器知道Person9類存在
template<class T1, class T2>
class Person9;

//全局函數 類外實現
template<class T1, class T2>
void printPerson5(Person9<T1, T2> p) {
	cout << p.m_Name << "\t" << p.m_Age << endl;
}

template<class T1, class T2>
class Person9 {
	//全局函數 類內實現
	friend void printPerson4(Person9<T1, T2> p) {
		cout << p.m_Name << "\t" << p.m_Age << endl;
	}

	//全局函數 類外實現
	//加空模板參數列表
	//類外實現的全局函數 要先讓編譯器知道全局函數的存在 所以要提前讓編譯器知道Person9類存在
	friend void printPerson5<>(Person9<T1, T2> p);
	//所以 類外實現 要先讓編譯器知道類Person9  再寫Person9的類外友元全局函數 之後才能詳細定義Person9類內內容

public:
	Person9(T1 name, T2 age) {			
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson() {
		cout << m_Name << "\t" << m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;
};

void test16() {
	//全局函數 類內實現
	Person9<string, int> p1("Peter", 35);
	printPerson4(p1);
	//全局函數 類外實現
	Person9<string, int> p2("Freeman", 49);
	printPerson5(p2);
}

//------------------------類模板-------------------------------
//--------------------------------------------------------

//實作數組類
	/*
	可以對內置數據類型以及自定義數據類型存儲
	將數組內數據存到堆區
	構造函數可以傳入數組的容量
	提供對應拷貝構造函數以及operator = 防止淺拷貝問題
	提供尾插法 尾刪法 對數組中數據進行增加和刪除
	可通過下標方式訪問數組元素
	可獲取數組中當前元素數和數組容量
	*/
	/*
	目標class{
		private
			數組	T* pAddress
			容量	m_Capacity
			大小	m_Size
		public
			構造函數(容量)
			拷貝構造
			operator =
			下標方式訪問數組元素
			尾插法
			尾刪法
			獲取數組容量
			獲取數組大小
			析構
	}
	*/
#include "MyArray.hpp"
void printIntArray(MyArray <int>& arr){
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << endl;
	}
}

void test17() {
	MyArray <int>arr1(5);
	for (int i = 0; i < 5; i++) {
		arr1.Push_Back(i);	//利用尾插法插入數據
	}
	cout << "arr1: " << endl;
	printIntArray(arr1);
	cout << "arr1 capacity: " << arr1.getCapacity() << endl;
	cout << "arr1 size: " << arr1.getSize() << endl;

	MyArray <int>arr2(arr1);	//不寫深拷貝 必錯
	cout << "arr2: " << endl;
	printIntArray(arr2);
	//尾刪
	arr2.Pop_Back();
	cout << "arr2: " << endl;
	printIntArray(arr2);
	cout << "arr2 capacity: " << arr2.getCapacity() << endl;
	cout << "arr2 size: " << arr2.getSize() << endl;

	//MyArray <int>arr3(100);
	//arr3 = arr1;
}

//自定義數據類型
class PMan {
public:
	PMan() {};
	PMan(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void printPManArray(MyArray<PMan>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i].m_Name << "\t" << arr[i].m_Age << endl;
	}

}
void test18() {
	MyArray <PMan>arr1(10);
	PMan p1("Peter", 23);
	PMan p2("Kevin", 44);
	PMan p3("Milly", 27);
	PMan p4("John", 39);
	PMan p5("Jack", 16);

	arr1.Push_Back(p1);
	arr1.Push_Back(p2);
	arr1.Push_Back(p3);
	arr1.Push_Back(p4);
	arr1.Push_Back(p5);

	printPManArray(arr1);
	cout << "arr1 capacity: " << arr1.getCapacity() << endl;
	cout << "arr1 size: " << arr1.getSize() << endl;

}


//--------------------------------------------------------

//--------------------------------------------------------

int main() {
	srand((unsigned int)time(NULL));

	//-----------------------函數模板------------------------------
	//函數模板基本語法
	//test01();

	//函數模板注意事項
	//test02();
	//test03();

	//函數模板案例 數組排序
	//test04();

	//普通函數與函數模板區別
	//test05();

	//普通函數與函數模板調用規則
	//test06();

	//模板的侷限性
	//test07();
	//test08();
	//-----------------------函數模板------------------------------

	//------------------------類模板-------------------------------
	//類模板語法
	//test09();

	//類模板與函數模板區別
	//test10();

	//類模板中函數成員創建時機
	//test11();

	//類模板對象做函數參數
	//test12();

	//類模板與繼承
	//test13();

	//類模板成員函數類外實現
	//test14();

	//類模板分文件編寫
	//test15();

	//類模板和友元
	//test16();

	//------------------------類模板-------------------------------

	//實作數組類
	test17();
	test18();


	

	system("pause");
	return 0;
}