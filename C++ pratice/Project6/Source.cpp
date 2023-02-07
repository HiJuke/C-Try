#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include "circle.h"	//Circle & point + ������m��L���
#include "point.h"	//Circle & point + ������m��L���


#define pi 3.14

using namespace std;

//���M��H �ʸ� �~�� �h�A
//public	�����i�X��	���~�i�X��
//protected	�����i�X��	���~���i�X�� �~�Ӫ���l�i�H�X�ݤ����O������
//private	�����i�X��	���~���i�X�� �~�Ӫ���l���i�H�X�ݤ����O������

//Class & Struct
//class		�q�{�v����private
//struct	�q�{�v����public

/*
//�]�p�@����: �ǥ�
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

//�]�p�@����: Person
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

//�]�p�@����: �ߤ���
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

	//���n
	int calculateS() {
		return 2 * mL * mW + 2 * mW * mH + 2 * mL * mH;
	}
	//��n
	int calculateV() {
		return mL * mW * mH;
	}

	//�Q�Φ�����ƧP�_��ߤ���O�_�۵�
	bool ISC(Cube& c2) {
		if (GetH() == c2.GetH() && GetL() == c2.GetL() && GetW() == c2.GetW()) {
			return true;
		}
		return false;
	}

};

//�Q�Υ�����ƧP�_��ߤ���O�_�۵�
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
//�c�y��� & �R�c���	Name(){}  &  ~Name(){}
/*
�c�y���
* �S����^�� ���gvoid
* �W�ٻP���W�ۦP
* �i�H���Ѽ� �i����
* �{�ǽեι�H�ɷ|�۰ʽեκc�y �L����� �B�u�եΤ@��

�R�c���
* �S����^�� ���gvoid
* �W�ٻP���W�ۦP �[�W~
* ���i�H���Ѽ� ���i����
* �{�Ǧb��H�P���e�۰ʽեΪR�c �L����� �B�u�եΤ@��
*/
/*
�c�y���
�����覡: 
	�Ѽ�:	���Ѽ�		�L�Ѽ�(�q�{�c�y)
	����:	���q�c�y	�����c�y
�եΤ覡: 
	�A���k		��ܪk		�����ഫ�k
*/

//�����c�y��ƽեήɾ�
/*
1. �ϥΤ@�ӥH�Ыا�������H�Ӫ�l�Ƥ@�ӷs��H
2. �H�ȶǻ����覡����ưѼƶǭ�
3. �Ȥ覡��^������H
*/

class Person {
public:
	//�c�y��� & �R�c��ƶ��bpublic�~�i�ѥ~���ե�
	Person() {		//�L�Ѻc�y(�q�{�c�y)
		age = 0;
		cout << "�L�Ѻc�y�c�y���" << endl;
	}

	//�ǲΪ�l�ƾާ@
	Person(int a, int Height) {	//���Ѻc�y
		age = a;
		hight = new int(Height);
		cout << "���Ѻc�y�c�y���" << endl;
	}

	//�����c�y���
	Person(const Person &P) {	//�����ݥ[�J const �M &�ޥ�
		age = P.age;
		//hight = P.hight;	//�o��|�ɭP��ϫ��w���D �sĶ���q�{��{�N�O����
		//�`�����ާ@
		hight = new int(*P.hight);
		cout << "�����c�y���" << endl;
	}

	//�R�c���
	~Person() {
		if (hight != NULL) {
			delete hight;
			hight = NULL;
		}
		cout << "�R�c���" << endl;
	}

	int getAge() { return age; }
	void setAge(int a) { age = a; }
	int* hight;
private:
	int age;
};

void textPerson() {
	//�A���k
	/*
	Person P1;		//�q�{�c�y��ƽե�
	Person P2(20);	//���Ѻc�y��ƽե�
	Person P3(P2);	//�����c�y��ƽե�
	cout << P1.getAge() << endl;
	cout << P2.getAge() << endl;
	cout << P3.getAge() << endl;
	//Person PP();	//�ե��q�{�c�y��Ʈɤ��n�[() �|�Q�sĶ���{���O����n��
	*/
	//��ܪk
	/*
	Person P1;		//�q�{�c�y��ƽե�
	Person P2 = Person(20);	//���Ѻc�y��ƽե�
	Person P3 = Person(P2);	//�����c�y��ƽե�
	cout << P1.getAge() << endl;
	cout << P2.getAge() << endl;
	cout << P3.getAge() << endl;
	Person(10);	//��@Person(10)���ΦW��H �S�I:��e�@����浲���� �t�η|�ߧY�^�����ΦW��H
	cout << "-----" << endl;	//�i���W��b�P�@��N�����إ߻P����
	//Person(P3);	//���n�Ϋ����c�y��ƪ�l�ưΦW��H �sĶ���|�{��Person(P3) === Person P3; �ɭP���w�q
	*/
	//�����ഫ�k
	/*
	Person P1 = 20;	//����g�F Person P1 = Person(20);	���Ѻc�y��ƽե�
	Person P2 = P1; //�����c�y
	*/		


}

//�����c�y��ƽեήɾ�
/*
//1. �ϥΤ@�ӥH�Ыا�������H�Ӫ�l�Ƥ@�ӷs��H
void test01() {
	Person p1(20);
	Person p2(p1);
}
//2. �H�ȶǻ����覡����ưѼƶǭ�
void dowork(Person p) {}
void test02() {
	Person p1;
	dowork(p1);
}
//3. �Ȥ覡��^������H
Person dowork2() {
	Person p1;
	return p1;
}
void test03() {
	Person p = dowork2();
}
*/

//�c�y��ƽեγW�h
/*
C++�sĶ���b�q�{���p�U�K�[�����
�q�{�c�y���
�q�{�R�c���
�q�{�����c�y���
*/
/*-
//�p�G���w�q�c�y��� C++�������q�{�c�y��� �����q�{�����c�y
//�p�G�w�q�����c�y��� C++�����Ѻc�y���
void test00() {
	Person p;
	p.setAge(20);
	Person PP(p);
	cout << PP.getAge() << endl;
}
*/

//�`���� �P �L����
/*
void test01() {
	Person p1(18, 160);
	cout << p1.getAge() << "\t" << *p1.hight << endl;
	Person p2(p1);
	cout << p2.getAge() << "\t" << *p2.hight << endl;
}
*/

//��l�ƦC��
/*
class PList {
public:
	//��l�ƦC��
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
	//�Ыض�
	/*
	Circle c1;
	c1.m_r = 20;
	cout << c1.calculateZC() << endl;
	*/

	//�ǥ�
	/*
	Student StA;
	StA.SetName("Peter");
	StA.SetId(3);
	StA.ShowInf();
	*/

	//�ߤ���
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
		cout << "��̬۵�" << endl;
	}
	else {
		cout << "���@�P" << endl;
	}
	ret = c1.ISC(c2);
	if (ret) {
		cout << "��̬۵�" << endl;
	}
	else {
		cout << "���@�P" << endl;
	}
	*/

	//Circle & point + ������m��L���
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
	//�c�y��� & �R�c���
	/*
	//Person p;
	textPerson();	//�̰Ϫ��ƾڰ��槹����N�|���� Ĳ�o�R�c���
	*/
	//�����c�y��ƽեήɾ�
	/*
	test01();
	test02();
	test03();
	*/
	/*
	test00();
	*/
	//�`���� �P �L����
	/*
	test01();
	*/

	//��l�ƦC��
	/*
	//PList p;
	PList p(23, 55, 69);
	p.testPList();
	*/





	system("pause");
	return 0;
}