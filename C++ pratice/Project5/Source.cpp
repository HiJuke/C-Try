#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���

#define MAX 1000

using namespace std;

//��ƴ���

//��ưѼƥi���q�{�Ѽ�
/*
int func(int a, int b, int c = 20) {
	return a + b + c;
}
//�`�N�ƶ�
//1. �p�G�Y��m�w���q�{�Ѽ� ���ᥪ��k�������q�{�Ѽ�
	//int func(int a, int b = 30, int c){ return a + b + c;}		
	//���~ b���q�{�Ѽ� c�N�����]�O
//2. �p�G����n�����q�{�Ѽ�, ��ƹ�{�N���঳�q�{�Ѽ�
	//int func(int a, int b){}
	//int func(int a, int b){ return a+b; }
	//��ƹ�{�N���঳�q�{�Ѽ� �^�b����ɯO��
*/

//��ưѼƥi������Ѽ�
/*
void func(int a, int) {
	cout << "Test void." << endl;
}
*/

//��ƭ��� ��ƦW�٬ۦP�W�[�_�Ω�
/*
//��ƭ����ݭn��Ƴ��b�P�@�@�ΰ�U
void func() {
	cout << "Func A Using~!" << endl;
}

void func(int a) {
	cout << "Func B Using~!" << endl;
}

void func(double a) {
	cout << "Func C Using~!" << endl;
}

void func(int a, double b) {
	cout << "Func D Using~!" << endl;
}

void func(double a, int b) {
	cout << "Func E Using~!" << endl;
}
//�P�W��Ƴz�L��J�榡���P�եΤ��P���

//��ƪ�^�Ȥ��i�@����ƭ���������
int func(){ return 2 ;}
*/

//�����`�N�ƶ�
/*
//�ޥΧ@����������
void fun(int &a) {
	cout << "fun A using" << endl;
}

void fun(const int &a) {
	cout << "fun B using" << endl;
}
*/
//��ƭ����J���q�{���
/*
void fun2(int a, int b = 20) {
	cout << "fun2 A" << endl;
}

void fun2(int a) {
	cout << "fun2 B" << endl;
}
*/


int main() {
	srand((unsigned int)time(NULL));

	//��ưѼƥi���q�{�Ѽ�
	//��Ʀ��q�{�Ѽ� �b�S�ǤJ�����p�U�ĥ��q�{�ƾ� ���D�ʶǤJ�����p�U�ĥζǤJ�ƾ�
	/*
	cout << func(50, 40) << endl;		//110
	cout << func(50, 40, 30) << endl;	//120
	*/

	//��ưѼƥi������Ѽ�
	/*
	//func(20);		  //����ѼƤ]�ݦ���J�� ���M�|���~
	//func(20, 30);	//�o�~�����
	*/

	//��ƭ��� ��ƦW�٬ۦP�W�[�_�Ω�
	/*
	func();
	func(30);
	func(7.99);
	func(30, 7.99);
	func(7.99, 30);
	//�P�W��Ƴz�L��J�榡���P�եΤ��P���
	*/

	//�����`�N�ƶ�
	/*
	//�ޥΧ@����������
	int a = 20;
	fun(a);
	fun(20);
	*/

	//��ƭ����J���q�{���
	/*
	//fun2(2);	  //�sĶ���d�����n�έ��@�Ө�� �X�{�G�q��
	//�ҥH��ƭ����ɶq���n�J���q�{��� �H�קK���ر��p
	*/






	system("pause");
	return 0;
}