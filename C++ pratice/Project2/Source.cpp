#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���

#define MAX 1000

using namespace std;

//-----------------------------------------
//C++ �{�Ǥ���	������	�M	�N�X��
/*
//�N�X�Ϭ��@��+�uŪ
//�����Ϧs�� �����ܶq �R�A�ܶq �`�q
//�`�q�Ϥ��s�� const�׹��������`�q+�r�Ŧ�`�q

//�����ܶq �R�A�`�q(static)	�`�q	�b�@�Ӥ��s�϶�
//�����ܶq	�b�@�Ӥ��s�϶�
*/

//-----------------------------------------

//������
/*
//�����ܶq
int g_a = 10;
int g_b = 10;

//const�׹��������ܶq �����`�q
const int c_g_a = 10;
const int c_g_b = 10;
*/

/*
//�����ܶq �R�A�ܶq �`�q
//�P�����ܶq�a�}�W�h
void class1() {
	//�����ܶq �R�A�ܶq �`�q

	//�Ыش��q�����ܶq
	int a = 10;		int b = 10;
	cout << "�����ܶqa�a�}\t" << (int)&a << endl;
	cout << "�����ܶqb�a�}\t" << (int)&b << endl;

	//�����ܶq
	cout << "�����ܶqg_a�a�}\t" << (int)&g_a << endl;
	cout << "�����ܶqg_b�a�}\t" << (int)&g_b << endl;

	//�R�A�ܶq
	static int s_a = 10;
	static int s_b = 10;
	cout << "�R�A�ܶqs_a�a�}\t" << (int)&s_a << endl;
	cout << "�R�A�ܶqs_a�a�}\t" << (int)&s_a << endl;

	//�i�������ܶq���R�A�ܶq��m�a�}�ܱ���

	//�r�Ŧ�`�q�a�}
	cout << "�r�Ŧ�`�q�a�}\t" << (int)&"Hello World!" << endl;

	//const�׹����ܶq
	//const�׹��������ܶq
	cout << "const�׹��������ܶqc_g_a�a�}\t" << (int)&c_g_a << endl;
	cout << "const�׹��������ܶqc_g_b�a�}\t" << (int)&c_g_b << endl;

	//�i�������ܶq���R�A�ܶq�Y�ϫ��A���P��m�a�}�]�ܱ���



	//const�׹��������ܶq
	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "const�׹��������ܶqc_l_a�a�}\t" << (int)&c_l_a << endl;
	cout << "const�׹��������ܶqc_l_a�a�}\t" << (int)&c_l_a << endl;

}
*/

//-----------------------------------------

//�̰� �ΥH�x�s�����ܶq
/*
//�̰ϼƾڪ`�N�ƶ� --- ���n��^�����ܶq���a�}
//�̰ϼƾڥѽsĶ���޲z�}�P&����
//�̰ϯS�ʥi�B�Ω�Y�ǫO�K��T

int * func(int b) {	//�ΰ�b�]��b�̰�
	b = 100;
	int a = 10;	//�����ܶq �s��b�̰� �̰Ϫ��ƾڦb��ư��槹��۰�����
	return &a;	//��^�����ܶq�a�}
}
*/

//��� �ѵ{�ǭ��޲z���t���� �Y�{�ǭ������� �{�ǵ����ɥѾާ@�t�Φ^��
/*
//C++���Q�� new �b��Ϥ��}�P���s	delete ���񤺦s
int* fu() {
	//�Q��new
	int *p = new int(10);	//�|��^new int(10)�ƾڪ��a�}
	//���w ���������ܶq��m��̰� �����w�O�s���ƾڦ����
	return p;	//�o�̱N��ϼƾڪ��a�}�s�� ��m��̰ϫ�^�Ǧa�}
}

void test01() {
	int* p = fu();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	//�T���]�S�O��
	//�u�n�{�ǭ���������� ��ϴN���|����(���D�{�ǰ���)

	delete p;	//�Q��delete�����Ϥ��s
	//cout << *p << endl;	//���s�H���� �A������K�|�X�{����
}

void test02(){
	//�Ы�10�Ӿ㫬�Ʋ� �b���
	int *arr = new int[10];

	for (int i = 0; i < 10; i++) {
		arr[i] = i + 100;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}

	//�����ϼƲ�
	delete[] arr;
}
*/



int main() {
	srand((unsigned int)time(NULL));

	//�����ϴ���
	//class1();
	
	//�̰ϴ���
	/*
	int t = 3;
	int* p = func(t);
	cout << *p << endl;	//�Ĥ@���i�H��ܥ��T�ƾ� �]���sĶ�����F�O�d
	cout << *p << endl;	//�ĤG���N�O�ɤF
	*/


	//�b��϶}�P�ƾ�
	/*
	test01();
	test02();
	*/



	system("pause");
	return 0;
}