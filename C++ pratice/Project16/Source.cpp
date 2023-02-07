#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include <fstream>	//	���ާ@�t���Y���
#include <vector>
#include <algorithm>

using namespace std; \

//------------------------------------------------------
//string �e�� �c�y���
/*
string();					//�Ыؤ@�Ŧr��
string(const char* s);		//�ϥΦr�Ŧ�s ��l��
string(const string& str);	//�ϥΤ@string��H��l��
string(int a, chat b);		//�ϥ�a�Ӧr��b ��l��
*/
void test01() {
	string s1;		//�q�{�c�y

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
//string �e�� ��Ⱦާ@
/*
string& operator = (const char *s);		//��r�Ŧ�s				�ᤩ��e�r��
string& operator = (const string &s);	//��r��s				�ᤩ��e�r��
string& operator = (char c );			//��r��c				�ᤩ��e�r��
string& assign(const char *s);			//��r�Ŧ�s				�ᤩ��e�r��
string& assign(const char *s, int n);	//��r�Ŧ�s���en�Ӧr��	�ᤩ��e�r��
string& assign(const string &s);		//�Φr��s				�ᤩ��e�r��
string& assign(int n, char c);			//��n�Ӧr��c			�ᤩ��e�r��

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
//string �e�� �r�Ŧ����

void test03() {

}

//------------------------------------------------------
//string �e�� �r�Ŭd��M����
/*
int find(const string& str, int pos = 0) const;		//�d��str		�Ĥ@���X�{��m		�qpos�}�l��
int find(const char* s, int pos = 0) const;			//�d��s			�Ĥ@���X�{��m		�qpos�}�l��
int find(const char* s, int pos, int n) const;		//�d��s�en�r��	�Ĥ@���X�{��m		�qpos�}�l��
int find(const char c, int pos = 0) const;			//�d��c			�Ĥ@���X�{��m		�qpos�}�l��
int rfind(const string& str, int pos = npos) const;	//�d��str		�̫�@���X�{��m	�qpos�}�l��
int rfind(const char* s, int pos = npos) const;		//�d��s			�̫�@���X�{��m	�qpos�}�l��
int rfind(const char* s, int pos, int n) const;		//�d��s�en�r��	�̫�@���X�{��m	�qpos�}�l��
int rfind(const char c, int pos = 0) const;			//�d��c			�̫�@���X�{��m	�qpos�}�l��
string& replace(int pos, int n, const string& str);	//�����qpos�}�ln�Ӧr�Ŭ�	str
string& replace(int pos, int n, const char* s);		//�����qpos�}�ln�Ӧr�Ŭ�	s
*/

void test04() {
	//find
	string str1 = "abcdefg";
	int pos1 = str1.find("cde");		//�S���ɷ|�^�� - 1
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
	cout << "pos2 = " << pos2<< endl;	//�p�G�r��̦���ӥH�W��de �q�᩹�e�� �q�e����� �^�ǭȫK�|���Ҥ��P



}
void test05() {
	//replace
	string str1 = "abcdefg";
	str1.replace(2, 2, "NOOB");
	cout << "str1 = " << str1 << endl;

}


//------------------------------------------------------
//string �e�� �r�Ŧ���
/*
�HASCII�X���  =��^ 0	||  >��^ 1  ||  <��^-1
int compare(const string &s) const;	//��S���
int compare(const char* s) const;	//��S���
*/
void test06() {
	string str1 = "hello";
	string str2 = "hello";
	if (str1.compare(str2) == 0) {
		cout << "�@�˦a �@�˦a" << endl;
	}
	else if (str1.compare(str2) > 0) {
		cout << "�r��@����j??" << endl;
	}
	else{ cout << "�r��G����j??" << endl; }
}

//------------------------------------------------------
//string �e�� �r�Ŧs��
/*
char& operator[](int n);	//�q�L[]��k����r��
char& at(int n);			//�q�Lat�o�k����r��
*/

void test07() {
	string str = "Mission Complete!";
	//��̤]�i���Ω�ק�
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
//string �e�� �r�Ŧ괡�J�R��
/*
string& insert(int pos, const char* s);		//���J�r�Ŧ�
string& insert(int pos, const string& str);	//���J�r�Ŧ�
string& insert(int pos, int n, char c);		//���w��m���Jn�Ӧr��c
string& erase(int pos, int n = npos);		//�R���qPos�}�l��n�Ӧr��
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
//string �e�� �l�����
//string substr (int pos = 0; int n = npos) const;	//��^��pos�}�l��n�Ӧr�Ųզ����r�Ŧ�

void test09() {
	string str = "xxx Hello xxx";
	string text = str.substr(4, 5);
	cout << text << endl;
}

//------------------------------------------------------

int main() {


	//string �򥻷���
	//test01();

	//string �e�� �c�y���
	//test02();

	//string �e�� �r�Ŧ����
	test03();

	//string �e�� �r�Ŭd��M����
	//test04();
	//test05();

	//string �e�� �r�Ŧ���
	//test06();

	//string �e�� �r�Ŧs��
	//test07();

	//string �e�� �r�Ŧ괡�J�R��
	//test08();

	//string �e�� �l�����
	test09();









	system("pause");
	return 0;
}