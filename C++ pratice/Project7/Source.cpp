#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���

#define pi 3.14

using namespace std;

//����H�@��������
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

//�R�A����: �R�A�����ܶq �R�A�������
/*
�R�A�����ܶq
*�Ҧ���H�@�ɦP�@���ƾ�
*�sĶ���q�������s
*�����n�� ���~��l��
-----------------------
�R�A�������
*�Ҧ���H�@�ɦP�@�Ө��
*�R�A������ƥu��X���R�A�����ܶq
*/
class Person2 {
public:
	//�Ҧ���H�@�ɦP�@���ƾ�
	//�sĶ���q�������s
	//�����n�� ���~��l��
	static int m_A;
	int ns_A;
	//�R�A�������
	static void func() {
		cout << "Static Func Use" << endl;
		m_A = 399;	//�R�A������ƥi�H�X���R�A�����ܶq
		//ns_A = 225;	//�R�A������Ƥ��i�X�ݫD�R�A�����ܶq
	}

	//�R�A�����ܶq�]�O���X���v����
private:
	static int m_B;
};
int Person2::m_A = 100;	//�����n�� ���~��l��
int Person2::m_B = 150;	//�����n�� ���~��l��

//�Ҧ���H�@�ɦP�@���ƾ�
void test02() {
	Person2 p;
	cout << p.m_A << endl;	//100
	Person2 p2;
	p2.m_A = 200;
	cout << p2.m_A << endl;	//100 ? 200
	cout << p.m_A << endl;	//�o�{p�]�ܦ�200�F �o�N�O�Ҧ���H�@�ɦP�@���ƾڪ��N��
	cout << endl;
}

//�R�A�ܶq�X�ݤ覡
void test03() {
	//�q�L��H�i��X��
	Person2 p;
	cout << p.m_A << endl;	//100
	//�q�L���W�X��
	cout << Person2::m_A << endl;
	//cout << p.m_B << endl;	//���~�X�ݤ���Dpublic
	cout << endl;
}

//�R�A�������
void test04() {
	//�q�L��H�i��X��
	Person2 p;
	p.func();
	//�q�L���W�X��
	Person2::func();
	//cout << p.m_B << endl;	//���~�X�ݤ���Dpublic
	cout << endl;
}

//-------------------------------------------




int main() {
	srand((unsigned int)time(NULL));

	//����H�@��������
	//test01();	//���إ߳Q�եΪ� �b�إ߽եΪ� ||| �����X�եΪ� �A���X�Q�եΪ�

	//�R�A����: �R�A�����ܶq �R�A�������
	//test02();
	//test03();
	//test04();


	system("pause");
	return 0;
}