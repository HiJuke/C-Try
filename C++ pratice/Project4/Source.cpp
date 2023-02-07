#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���

#define MAX 1000

using namespace std;

//�ޥ� ���ܶq�_�O�W	�]�N�O���h���ܼƦW�٦P�ɥN��P�@�����s �䤤�@���ܼƧ��K���Ҧ��ܼ�
//�y�k: �ܼ����� &�O�W = ��W
//		int &b = a;
//1. �ޥΥ�����l��-----int &b;���i�H	����int &b = �Y��int
//2. �ޥΤ@����l�� �K���i���F	(b�w�ޥ�a �K���୫�s�ޥ�c)

//-------------------------------------------------------

//�i�H�Q�Τޥέ׹���ƶǻ��Ѽ� ²�ƫ��w�ק�
//�ȶǻ�
void mySwap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
//��}�ǻ�
void mySwap02(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//�ޥζǻ�
void mySwap03(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//-------------------------------------------------------

//�ޥΧ@����ƪ�^��
//1. ���n��^�����ܶq���ޥ�
int& test01() {
	int a = 10;
	return a;
}

//2. ��ƽեΥi�H��������
int& test02() {
	static int a = 10;	//�R�A�ܶq �s��b������ ��{�ǵ�����t������
	return a;
}

//-------------------------------------------------------

//�ޥΪ�����bc++������{�O�@�ӫ��w�`�q
//�o�{��Ƭ��ޥ� �ഫ�� int* const ref = &a;
void func(int& ref) {
	ref = 2000;
}

//-------------------------------------------------------
//�`�q�ޥ�: �Ψӭ׹��ΰ� ����~�ާ@
//�i�H�[const�׹�
void showValue1(int& v) {
	v = 200;
	cout << v << endl;
}

void showValue2(const int& v) {
	//v = 200;		//��const��ê��� �ϧ����� ����~�ާ@
	cout << v << endl;
}


int main() {
	srand((unsigned int)time(NULL));

	//�ޥ�
	int a = 10;
	/*
	int& b = a;
	int& c = b;
	cout << a << endl;	//10
	b = 100;
	cout << a << endl;	//��100
	c = 500;
	cout << a << endl;	//��500
	cout << b << endl;	//��500
	*/
	/*
	//int& b;	//���~ ������l��
	int& b = a;
	int c = 20;
	b = c;	//�Ȭ���� ���O���ޥ� �]������
	cout << a << endl;	//20
	cout << b << endl;	//20
	cout << c << endl;	//20
	//b���i�ޥ�c �ϦӪ������ۤv�P�ޥΪ�a�Qc��Ȧ���20
	*/
	/*
	int b = 20;
	//�ȶǻ�
	mySwap01(a, b);
	cout << a << "\t" << b << endl;

	//��}�ǻ�
	//mySwap02(&a, &b);
	//cout << a << "\t" << b << endl;

	//�ޥζǻ�
	mySwap03(a, b);
	cout << a << "\t" << b << endl;

	//�i���ޥΧ@�Ω��Ƥ]�i�����ڭק�
	*/
	/*
	int& ref = test01();	//1. ���n��^�����ܶq���ޥ�		�ޥΧ����ܶq����
	cout << ref << endl;	//�Ĥ@�����sĶ���O�@���|���h�ƭ�
	cout << ref << endl;	//�ĤG���N�Q���X �X�{�����ܶq���ƾڿ��~ �]���Ŷ��w�Q���X

	int& ref2 = test02();
	cout << ref2 << endl;	//�R�A�ܶq �����ϪŶ������X �ƾ�í�w
	cout << ref2 << endl;	//�R�A�ܶq �����ϪŶ������X �ƾ�í�w
	//�`�N
	test02() = 1000;		//2. ��ƽեΥi�H��������	 ��Ʀ^�Ǭ��ޥ�a test02���ޥ�
	cout << ref2 << endl;	//�P�ޥΤ@�P�אּ1000
	cout << ref2 << endl;	//�P�ޥΤ@�P�אּ1000
	*/
	/*
	int& ref = a;
	ref = 20;		//�����o�{ref�O�ޥ� �۰����ڭ��ഫ��*ref = 20;
	cout << "a:" << a << "\tref:" << ref << endl;

	func(a);
	cout << "a:" << a << "\tref:" << ref << endl;
	*/
	/*
	//�`�q�ޥ�: �Ψӭ׹��ΰ� ����~�ާ@
	//int& ref = 10;	//���~ �ޥλݶ��@���X�k���s�Ŷ�
	//const int & ref = 10;		//�[�Jconst �sĶ���N�N�X�ק� int temp = 10;		const int & ref = temp;
	//ref = 20;		//�[�Jconst ���ᬰ�uŪ ���i�ק�

	showValue1(a);
	cout << a << endl;	//�o�{a�Q���ק鷺�e����Ƽv�T�F

	a = 10;
	showValue2(a);
	cout << a << endl;	//��const�O�@
	*/


	system("pause");
	return 0;
}