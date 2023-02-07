#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include <fstream>	//	���ާ@�t���Y���
#include"person8.hpp"

using namespace std;

//�w��x���s�� �M STL �޳N�@�Բ�����
//�ҪO temeplate
//�إ߳q�Ϊ��Ҩ� �j�j�����ƥΩ�
//���� ��ƼҪO ���ҪO


//-----------------------��ƼҪO------------------------------
//��ƼҪO�򥻻y�k
//template	�n���ЫؼҪO
//typename	��ܨ���Ÿ��O�@�ؼƾ����� �i�H��class�N��
// T		�q�μƾ����� �W�٥i���� �q�����j�g�r��
template<typename T>	//����n���Ωw�q	��ƼҪO
void mySwap(T& a, T& b) {	//�w�w�Ƨ�
	T temp = a;
	a = b;
	b = temp;
}
//��بϥΨ�ƼҪO���覡
//1. �۰���������
//2. ��ܫ��w����
void test01() {
	int a = 22;
	int b = 99;
	cout << " a= " << a << "\t b= " << b << endl;
	//��بϥΨ�ƼҪO���覡
	//1. �۰���������
	mySwap(a, b);
	cout << " a= " << a << "\t b= " << b << endl;
	//2. ��ܫ��w����
	mySwap<int>(a, b);
	cout << " a= " << a << "\t b= " << b << endl;
}

//--------------------------------------------------------
//��ƼҪO�`�N�ƶ�
//�۰��������� �������ɥX�@�P���ƾ�����T �~�i�H�ϥ�
//�ҪO���T�w�XT ���ƾ����� �~�i�H�ϥ�
template<class T> //typename �i�H������class class�ܤ֨S��
void mySwap2(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
//1. �۰���������
void test02() {
	int a = 66;		//�۰��������� �������ɥX�@�P���ƾ�����T �~�i�H�ϥ�
	int b = 33;		//�p�Gb ��������a ���P ��pb�O char ����N�|����ϥ� �X��
	cout << " a= " << a << "\t b= " << b << endl;
	mySwap(a, b);
	cout << " a= " << a << "\t b= " << b << endl;
}
//�ҪO���T�w�XT ���ƾ����� �~�i�H�ϥ�
template<class T> //typename �i�H������class class�ܤ֨S��
void func1() {
	cout << "func 1 Using" << endl;
}
void test03() {
	//func();		//�ҪO���T�w�XT ���ƾ����� �~�i�H�ϥ� �o�̷|�X��
	func1<int>();	//�o�̽T�{T��int���� �~�i�H�ϥ�
}

//--------------------------------------------------------
//��ƼҪO�ר� �ƲձƧ�
//��{�q�� ��ƲձƧǪ���� �q�j��p ��ܱƧ� ����char�Ʋ� int�Ʋ�
template<class T> //typename �i�H������class class�ܤ֨S��
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
	//����char
	char charArr[] = "aerosekjd";
	mySort1(charArr, sizeof(charArr) / sizeof(char));
	printArray(charArr, sizeof(charArr) / sizeof(char));

	int intArr[] = { 8,6,7,44,55,99,87,36,220 };
	mySort1(intArr, sizeof(intArr) / sizeof(int));
	printArray(intArr, sizeof(intArr) / sizeof(int));
}

//--------------------------------------------------------
//���q��ƻP��ƼҪO�ϧO
/*
���q��ƽեήɥi�H�o�ͦ۰������ഫ (���������ഫ)
��ƼҪO�M�ή� �p�G�Q�Φ۰��������� ���|�o�����������ഫ
�p�G�Q����ܫ��w�������覡 �i�H�o�����������ഫ
*/

//���q���
int Add01(int a, int b) {
	return a + b;
}
//��ƼҪO
template<class T>
T Add02(T a, T b) {
	return a + b;
}

void test05() {
	int a = 22;
	int b = 33;
	char c = 'c';
	//���q���
	cout << Add01(a, b) << endl;	// 55
	cout << Add01(a, c) << endl;	// 121 ??? �]���L��r�ū��ܶq�ন�㫬�ܶq�F c�������㫬�O99
	//��ƼҪO �۰���������
	cout << Add02(a, b) << endl;	// 55
	//cout << Add02(a, c) << endl;	// �������@�P ��ƼҪO�����F
	//��ƼҪO ���w��������
	cout << Add02<int>(a, c) << endl;	//�S�����F �]�����w������c �]�ܦ��Fint���� 121 �i�o�����������ഫ
}

//--------------------------------------------------------
//���q��ƻP��ƼҪO�եγW�h
//���q��Ƹ��ƼҪO���i����
/*
���q��Ƹ��ƼҪO�ҥi��{ ���q����u��
�i�ΪżҪO�ѼƦC��j��եΨ�ƼҪO
��ƼҪO�]�i����
�Y��ƼҪO�i���ͧ�n���ǰt ���եΨ�ƼҪO
*/
void myPrint(int a, int b)
{
	cout << "���q��ƽե�" << endl;
}

template<class T>
void myPrint(T a, T b) {
	cout << "��ƼҪO�ե�" << endl;
}

template<class T>
void myPrint(T a, T b, T c) {
	cout << "��ƼҪO�����ե�" << endl;
}

void test06() {
	int a = 55;
	int b = 33;
	//���q��Ƹ��ƼҪO�ҥi��{ ���q����u��
	myPrint(a, b);	
	//�q�L�żҪO�ѼƦC��  �j��եΨ�ƼҪO
	myPrint<>(a, b);
	//��ƼҪO�]�i����
	myPrint(a, b, 200);
	//�Y��ƼҪO�i���ͧ�n���ǰt ���եΨ�ƼҪO
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);
}

//--------------------------------------------------------
//�ҪO���]����
/*
//template<class T>
//void f(T a, T b) { a = b; }	//�Y a b ���Ʋ� �N�L�k��{���

//template<class T>
//void f(T a, T b) { if( a > ){...} }	//�Y a b ���۩w�q�ƾ�����(class Person) �]�L�k���`�B��
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

//���Ѩ����Person�����J��ƼҪO �b��Person���ɭ��u���ե�
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
	bool ret = myCompare(p1, p2);	//�S�Ψ���ƼҪO �K�L�k���I�۩w�q�S��ƾ�����
}
//-----------------------��ƼҪO------------------------------

//------------------------���ҪO-------------------------------
//���ҪO�y�k
//�إߤ@�q���� �������� �ƾ������i�H�������w �Τ@�ӵ����������N��
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
	Person1<string, int>p1("Peter", 87);		//�]��Person1���c�y��ƬO�μҪO �S�����w���� �ҥH�b�����w<string, int>
	p1.showPerson();
}

//--------------------------------------------------------
//���ҪO�P��ƼҪO�ϧO
//1. ���ҪO�S���۰��������ɪ��ϥΤ覡
//2. ���ҪO�b�ҪO�ѼƦC���i�H���q�{�Ѽ�
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

//2. ���ҪO�b�ҪO�ѼƦC���i�H���q�{�Ѽ�
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
	//1. ���ҪO�S���۰��������ɪ��ϥΤ覡
	//Person2 p1("Peter", 87);					
	Person2<string, int>p1("Peter", 87);		//�]��Person1���c�y��ƬO�μҪO �S�����w���� �ҥH�b�����w<string, int>
	p1.showPerson();
	//2. ���ҪO�b�ҪO�ѼƦC���i�H���q�{�Ѽ�
	Person3<string>p2("Eills", 23);				//�]��template<class NameType, class AgeType = int>	��̤w�g�M�w�ƾګ��A �K���Ϋ��w
	p2.showPerson();							//�q�{�Ѽƥu�i�Ω����ҪO ��ƼҪO������
}

//--------------------------------------------------------
//���ҪO����Ʀ����Ыخɾ�
// * ���q����������ƥi��@�}�l�Ы�
// * ���ҪO��������ƽեήɤ~�|�Ы�
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

	//���ҪO���������
	//�o��Ӧ������ �ݦ��|�sĶ���~ ����ڤ��| �]�����ҪO������ƽեήɤ~�|�Ы�
	void func4() {
		obj.showPerson4();
	}
	void func5() {
		obj.showPerson5();
	}
};

void test11() {
	MyClass<Person4>m;
	m.func4();		//���欰Person4����� ������W�N�i����
	//m.func5();	//��������N�|�X��
}

//--------------------------------------------------------
//���ҪO��H����ưѼ�
//1. ���w�ǤJ����	---	������ܹ�H���ƾ�����
//2. �ѼƼҪO��		---	�N��H�����Ѽ��ܬ��ҪO�i��ǻ�
//3. ������ҪO��	---	�N����H���� �ҪO�ƶi��ǻ�
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
//1. ���w�ǤJ����	---	������ܹ�H���ƾ�����
void printPerson1(Person6<string, int >& p) {
	p.showPerson();
}
//2. �ѼƼҪO��		---	�N��H�����Ѽ��ܬ��ҪO�i��ǻ�
template<class T1, class T2>
void printPerson2(Person6<T1, T2 >p) {
	p.showPerson();
}
//3. ������ҪO��	---	�N����H���� �ҪO�ƶi��ǻ�
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
//���ҪO�P�~��
// 1. �l���~�Ӫ����������ҪO��  �����b�n�����ɭ�  �n���X������������
// 2. �p�G�����w �sĶ���L�k���t���s
// 3. �p�G�Q�F�����w������������ �l���]�ݬ����ҪO
template<class T>
class Base {
	T m;
};
//�l���O�����n���X������������
class Son : public Base<int> {	//�l���O�����n���X������������

};
//�p�G�Q�F�����w������������ �l���]�ݬ����ҪO
template<class T1, class T2>
class Son2 : public Base<T2> {	
	T1 obj;
};

void test13() {
	Son s1;
	Son2<int, char> S2;		//��char�ǵ�Son2��template �A��Base<T2>�Nchar�����w�q�������O��template
}

//--------------------------------------------------------
//���ҪO����������~��{
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
//���ҪO�����s�g
//���D: ���ҪO������Ʃ�եζ��q�Ы� �ɭP�����ɳs������
//��1: �����]�tcpp�����	(���`������ĳ����k)
//��2: �N�n���M��{�g��P�@������ ����Y�W��.hpp (��Y�W���O�j��)
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
	//��1: �����]�tcpp�����	(���`������ĳ����k)
	//�}�Y include person8.h �ɷ|���~ person.cpp�ɴN���| �]����̷|���sĶ���ƥ��ݹL�Ҧ���� �K�i�H���Q�ե�
	//���o�ا@�k���`��
	//Person8<string, int> p("Jess", 20);
	//p.showPerson();

	//��2: �N�n���M��{�g��P�@������ ����Y�W��.hpp (��Y�W���O�j��)
	Person8<string, int> p("Jess", 20);
	p.showPerson();
}

//--------------------------------------------------------
//���ҪO�M�ͤ� (���������g ���~�n�����sĶ�����D������ƪ��s�b)

//���e���sĶ�����DPerson9���s�b
template<class T1, class T2>
class Person9;

//������� ���~��{
template<class T1, class T2>
void printPerson5(Person9<T1, T2> p) {
	cout << p.m_Name << "\t" << p.m_Age << endl;
}

template<class T1, class T2>
class Person9 {
	//������� ������{
	friend void printPerson4(Person9<T1, T2> p) {
		cout << p.m_Name << "\t" << p.m_Age << endl;
	}

	//������� ���~��{
	//�[�żҪO�ѼƦC��
	//���~��{��������� �n�����sĶ�����D������ƪ��s�b �ҥH�n���e���sĶ�����DPerson9���s�b
	friend void printPerson5<>(Person9<T1, T2> p);
	//�ҥH ���~��{ �n�����sĶ�����D��Person9  �A�gPerson9�����~�ͤ�������� ����~��Բөw�qPerson9�������e

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
	//������� ������{
	Person9<string, int> p1("Peter", 35);
	printPerson4(p1);
	//������� ���~��{
	Person9<string, int> p2("Freeman", 49);
	printPerson5(p2);
}

//------------------------���ҪO-------------------------------
//--------------------------------------------------------

//��@�Ʋ���
	/*
	�i�H�鷺�m�ƾ������H�Φ۩w�q�ƾ������s�x
	�N�Ʋդ��ƾڦs����
	�c�y��ƥi�H�ǤJ�Ʋժ��e�q
	���ѹ��������c�y��ƥH��operator = ����L�������D
	���ѧ����k ���R�k ��Ʋդ��ƾڶi��W�[�M�R��
	�i�q�L�U�Ф覡�X�ݼƲդ���
	�i����Ʋդ���e�����ƩM�Ʋծe�q
	*/
	/*
	�ؼ�class{
		private
			�Ʋ�	T* pAddress
			�e�q	m_Capacity
			�j�p	m_Size
		public
			�c�y���(�e�q)
			�����c�y
			operator =
			�U�Ф覡�X�ݼƲդ���
			�����k
			���R�k
			����Ʋծe�q
			����Ʋդj�p
			�R�c
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
		arr1.Push_Back(i);	//�Q�Χ����k���J�ƾ�
	}
	cout << "arr1: " << endl;
	printIntArray(arr1);
	cout << "arr1 capacity: " << arr1.getCapacity() << endl;
	cout << "arr1 size: " << arr1.getSize() << endl;

	MyArray <int>arr2(arr1);	//���g�`���� ����
	cout << "arr2: " << endl;
	printIntArray(arr2);
	//���R
	arr2.Pop_Back();
	cout << "arr2: " << endl;
	printIntArray(arr2);
	cout << "arr2 capacity: " << arr2.getCapacity() << endl;
	cout << "arr2 size: " << arr2.getSize() << endl;

	//MyArray <int>arr3(100);
	//arr3 = arr1;
}

//�۩w�q�ƾ�����
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

	//-----------------------��ƼҪO------------------------------
	//��ƼҪO�򥻻y�k
	//test01();

	//��ƼҪO�`�N�ƶ�
	//test02();
	//test03();

	//��ƼҪO�ר� �ƲձƧ�
	//test04();

	//���q��ƻP��ƼҪO�ϧO
	//test05();

	//���q��ƻP��ƼҪO�եγW�h
	//test06();

	//�ҪO���]����
	//test07();
	//test08();
	//-----------------------��ƼҪO------------------------------

	//------------------------���ҪO-------------------------------
	//���ҪO�y�k
	//test09();

	//���ҪO�P��ƼҪO�ϧO
	//test10();

	//���ҪO����Ʀ����Ыخɾ�
	//test11();

	//���ҪO��H����ưѼ�
	//test12();

	//���ҪO�P�~��
	//test13();

	//���ҪO����������~��{
	//test14();

	//���ҪO�����s�g
	//test15();

	//���ҪO�M�ͤ�
	//test16();

	//------------------------���ҪO-------------------------------

	//��@�Ʋ���
	test17();
	test18();


	

	system("pause");
	return 0;
}