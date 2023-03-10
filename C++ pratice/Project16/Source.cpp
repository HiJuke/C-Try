#include <iostream>
#include <string>
#include <ctime>	//	time 丁╰参繷ゅン
#include <fstream>	//	ゅン巨╰参繷ゅン
#include <vector>
#include <algorithm>

using namespace std; \

//------------------------------------------------------
//string 甧竟 篶硑ㄧ计
/*
string();					//承﹃
string(const char* s);		//ㄏノ才﹃s ﹍て
string(const string& str);	//ㄏノstring癸禜﹍て
string(int a, chat b);		//ㄏノa才b ﹍て
*/
void test01() {
	string s1;		//纐粄篶硑

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
//string 甧竟 结巨
/*
string& operator = (const char *s);		//р才﹃s				结ぉ虫玡﹃
string& operator = (const string &s);	//р﹃s				结ぉ讽玡﹃
string& operator = (char c );			//р才c				结ぉ讽玡﹃
string& assign(const char *s);			//р才﹃s				结ぉ讽玡﹃
string& assign(const char *s, int n);	//р才﹃s玡n才	结ぉ讽玡﹃
string& assign(const string &s);		//ノ﹃s				结ぉ讽玡﹃
string& assign(int n, char c);			//ノn才c			结ぉ讽玡﹃

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
//string 甧竟 才﹃钡

void test03() {

}

//------------------------------------------------------
//string 甧竟 才琩т㎝蠢传
/*
int find(const string& str, int pos = 0) const;		//琩тstr		材Ω瞷竚		眖pos秨﹍т
int find(const char* s, int pos = 0) const;			//琩тs			材Ω瞷竚		眖pos秨﹍т
int find(const char* s, int pos, int n) const;		//琩тs玡n才	材Ω瞷竚		眖pos秨﹍т
int find(const char c, int pos = 0) const;			//琩тc			材Ω瞷竚		眖pos秨﹍т
int rfind(const string& str, int pos = npos) const;	//琩тstr		程Ω瞷竚	眖pos秨﹍т
int rfind(const char* s, int pos = npos) const;		//琩тs			程Ω瞷竚	眖pos秨﹍т
int rfind(const char* s, int pos, int n) const;		//琩тs玡n才	程Ω瞷竚	眖pos秨﹍т
int rfind(const char c, int pos = 0) const;			//琩тc			程Ω瞷竚	眖pos秨﹍т
string& replace(int pos, int n, const string& str);	//蠢传眖pos秨﹍n才	str
string& replace(int pos, int n, const char* s);		//蠢传眖pos秨﹍n才	s
*/

void test04() {
	//find
	string str1 = "abcdefg";
	int pos1 = str1.find("cde");		//⊿т穦肚 - 1
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
	cout << "pos2 = " << pos2<< endl;	//狦﹃柑Τㄢde 眖┕玡т 眖玡┕т 肚獽穦Τ┮ぃ



}
void test05() {
	//replace
	string str1 = "abcdefg";
	str1.replace(2, 2, "NOOB");
	cout << "str1 = " << str1 << endl;

}


//------------------------------------------------------
//string 甧竟 才﹃ゑ耕
/*
ASCII絏癸ゑ  = 0	||  > 1  ||  <-1
int compare(const string &s) const;	//蛤Sゑ耕
int compare(const char* s) const;	//蛤Sゑ耕
*/
void test06() {
	string str1 = "hello";
	string str2 = "hello";
	if (str1.compare(str2) == 0) {
		cout << "妓 妓" << endl;
	}
	else if (str1.compare(str2) > 0) {
		cout << "﹃ゑ耕??" << endl;
	}
	else{ cout << "﹃ゑ耕??" << endl; }
}

//------------------------------------------------------
//string 甧竟 才
/*
char& operator[](int n);	//硄筁[]よ猭莉才
char& at(int n);			//硄筁at祇猭莉才
*/

void test07() {
	string str = "Mission Complete!";
	//ㄢ常ノэ
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
//string 甧竟 才﹃础埃
/*
string& insert(int pos, const char* s);		//础才﹃
string& insert(int pos, const string& str);	//础才﹃
string& insert(int pos, int n, char c);		//﹚竚础n才c
string& erase(int pos, int n = npos);		//埃眖Pos秨﹍n才
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
//string 甧竟 ﹃莉
//string substr (int pos = 0; int n = npos) const;	//パpos秨﹍n才舱Θ才﹃

void test09() {
	string str = "xxx Hello xxx";
	string text = str.substr(4, 5);
	cout << text << endl;
}

//------------------------------------------------------

int main() {


	//string 膀セ阀├
	//test01();

	//string 甧竟 篶硑ㄧ计
	//test02();

	//string 甧竟 才﹃钡
	test03();

	//string 甧竟 才琩т㎝蠢传
	//test04();
	//test05();

	//string 甧竟 才﹃ゑ耕
	//test06();

	//string 甧竟 才
	//test07();

	//string 甧竟 才﹃础埃
	//test08();

	//string 甧竟 ﹃莉
	test09();









	system("pause");
	return 0;
}