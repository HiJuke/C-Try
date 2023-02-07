#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include <fstream>	//	文件操作系統頭文件
#include <vector>
#include <algorithm>

using namespace std; \

//------------------------------------------------------
//string 容器 構造函數
/*
string();					//創建一空字串
string(const char* s);		//使用字符串s 初始化
string(const string& str);	//使用一string對象初始化
string(int a, chat b);		//使用a個字符b 初始化
*/
void test01() {
	string s1;		//默認構造

	const char* str = "Hello World";
	string s2(str);
	cout << "s2= " << s2 << endl;	//Hello World

	//string s3(s2);
	string s3("SSS333");
	cout << "s3= " << s3 << endl;	//SSS333

	string s4(10, 'a');
	cout << "s4= " << s4 << endl;	//aaaaaaaaaa

}

//------------------------------------------------------
//string 容器 賦值操作
/*
string& operator = (const char *s);		//把字符串s				賦予單前字串
string& operator = (const string &s);	//把字串s				賦予當前字串
string& operator = (char c );			//把字符c				賦予當前字串
string& assign(const char *s);			//把字符串s				賦予當前字串
string& assign(const char *s, int n);	//把字符串s的前n個字符	賦予當前字串
string& assign(const string &s);		//用字串s				賦予當前字串
string& assign(int n, char c);			//用n個字符c			賦予當前字串

*/

void test02() {
	string str1;
	str1 = "Hello World";
	cout << "Str1 = " << str1 << endl;	//Hello World

	string str2;
	str2 = str1;
	cout << "Str2 = " << str2 << endl;	//Hello World

	string str3;
	str3 = 'A';
	cout << "Str3 = " << str3 << endl;	//A

	string str4;
	str4.assign("Str4 C++");
	cout << "Str4 = " << str4 << endl;	//Str4 C++

	string str5;
	str5.assign("Str5 C++", 4);
	cout << "Str5 = " << str5 << endl;	//Str5

	string str6;
	str6.assign(str5);
	cout << "Str6 = " << str6 << endl;	//Str5

	string str7;
	str7.assign(7,'P');					
	cout << "Str7 = " << str7 << endl;	//PPPPPPP
}


//------------------------------------------------------
//string 容器 字符串拼接

void test03() {

}

//------------------------------------------------------
//string 容器 字符查找和替換
/*
int find(const string& str, int pos = 0) const;		//查找str		第一次出現位置		從pos開始找
int find(const char* s, int pos = 0) const;			//查找s			第一次出現位置		從pos開始找
int find(const char* s, int pos, int n) const;		//查找s前n字符	第一次出現位置		從pos開始找
int find(const char c, int pos = 0) const;			//查找c			第一次出現位置		從pos開始找
int rfind(const string& str, int pos = npos) const;	//查找str		最後一次出現位置	從pos開始找
int rfind(const char* s, int pos = npos) const;		//查找s			最後一次出現位置	從pos開始找
int rfind(const char* s, int pos, int n) const;		//查找s前n字符	最後一次出現位置	從pos開始找
int rfind(const char c, int pos = 0) const;			//查找c			最後一次出現位置	從pos開始找
string& replace(int pos, int n, const string& str);	//替換從pos開始n個字符為	str
string& replace(int pos, int n, const char* s);		//替換從pos開始n個字符為	s
*/

void test04() {
	//find
	string str1 = "abcdefg";
	int pos1 = str1.find("cde");		//沒找到時會回傳 - 1
	cout << "pos1 = " << pos1 << endl;	//2		

	pos1 = str1.find("e");
	cout << "pos1 = " << pos1 << endl;	//4

	pos1 = str1.find("cdeGGG", 0, 3);
	cout << "pos1 = " << pos1 << endl;	//2

	pos1 = str1.find('e');
	cout << "pos1 = " << pos1 << endl;	//4

	//rfind
	int pos2;
	pos2 = str1.rfind("de");
	cout << "pos2 = " << pos2<< endl;	//如果字串裡有兩個以上的de 從後往前找 從前往後找 回傳值便會有所不同



}
void test05() {
	//replace
	string str1 = "abcdefg";
	str1.replace(2, 2, "NOOB");
	cout << "str1 = " << str1 << endl;

}


//------------------------------------------------------
//string 容器 字符串比較
/*
以ASCII碼對比  =返回 0	||  >返回 1  ||  <返回-1
int compare(const string &s) const;	//跟S比較
int compare(const char* s) const;	//跟S比較
*/
void test06() {
	string str1 = "hello";
	string str2 = "hello";
	if (str1.compare(str2) == 0) {
		cout << "一樣地 一樣地" << endl;
	}
	else if (str1.compare(str2) > 0) {
		cout << "字串一比較大??" << endl;
	}
	else{ cout << "字串二比較大??" << endl; }
}

//------------------------------------------------------
//string 容器 字符存取
/*
char& operator[](int n);	//通過[]方法獲取字符
char& at(int n);			//通過at發法獲取字符
*/

void test07() {
	string str = "Mission Complete!";
	//兩者也可都用於修改
	//str[str.size() - 1] = '?';
	//str.at(str.size() - 1) = '?';
	for (int i = 0; i < str.size(); i++) {
		cout << str[i];
	}
	cout << endl;
	for (int i = 0; i < str.size(); i++) {
		cout << str.at(i);
	}
	cout << endl;
}

//------------------------------------------------------
//string 容器 字符串插入刪除
/*
string& insert(int pos, const char* s);		//插入字符串
string& insert(int pos, const string& str);	//插入字符串
string& insert(int pos, int n, char c);		//指定位置插入n個字符c
string& erase(int pos, int n = npos);		//刪除從Pos開始的n個字符
*/

void test08() {
	string str1 = "Join me";
	str1.insert(4, " with");
	cout << str1 << endl;

	str1.insert(9, 3, '1');
	cout << str1 << endl;

	str1.erase(9, 3);
	cout << str1 << endl;
}

//------------------------------------------------------
//string 容器 子串獲取
//string substr (int pos = 0; int n = npos) const;	//返回由pos開始的n個字符組成的字符串

void test09() {
	string str = "xxx Hello xxx";
	string text = str.substr(4, 5);
	cout << text << endl;
}

//------------------------------------------------------

int main() {


	//string 基本概念
	//test01();

	//string 容器 構造函數
	//test02();

	//string 容器 字符串拼接
	test03();

	//string 容器 字符查找和替換
	//test04();
	//test05();

	//string 容器 字符串比較
	//test06();

	//string 容器 字符存取
	//test07();

	//string 容器 字符串插入刪除
	//test08();

	//string 容器 子串獲取
	test09();









	system("pause");
	return 0;
}