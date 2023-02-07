#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include "swap.h"	// �ޤJ�ۤv�g���Y���H�ϥΤ����� function
#define Day 7	//�w�q���`�q
//�`�q�w�q�覡 1. #define �ܼ� 
//�`�q�w�q�覡 2. const �׹����ܶq
using namespace std;

//�ХܲũR�W�W�h
//1.�Ѧr�� �Ʀr �U�e�u�c��		abc_abc
//2.���Ӧr���u�i���r���ΤU�e�u	_abcabc
//3.�Ϥ��j�p�g					_abc =/= _ABC
//4.���i������r				���i�� int double ������


// function
	/*
	���B�J
	1	��^������
	2	��ƦW
	3	�Ѽƪ�C
	4	�����y�y
	5	return��F��
	*/

int add(int a, int b) {
	int sum = a + b;
	return sum;
}

void swap2(int *p, int *p2) {
	int temp = *p;
	*p = *p2;
	*p2 = temp;
}

void ArrowArrayBubbleSort(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

/*
void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
*/

//--------------------------------------------------------------------------
	//���c��
struct student {
	string name;
	int age;
	int score;
}sss;		//sss�����K�Ыت����c���ܶq

struct teacher {
	int id;
	string name;
	int age;
	struct student stu;
};

//���c�鰵��ưѼ�
void printStuS(struct student s) {
	cout << s.name << "    " << s.age << "    " << s.score << endl;
}

/*
void printStuP(struct student* p) {	
	//�ϥΫ��w�i��֤��s�Ŷ����� �]���|�ƻs�s���ƥ�
	//p->name = "Michal";	//���ի��w���ƥi�v�T��ڼƭ�
	cout << p->name << "    " << p->age << "    " << p->score << endl;
}
*/
//���c��+const�ϥ�
void printStuP(const student* p) {
	//�[�Jconst�O���F����ӧ��ܪ��ƾڳQ��� �Y�Q����ܷ|����
	//p->name = "Michal";	//���ի��w���ƥi�v�T��ڼƭ� const�O�@�U�K�|����
	cout << p->name << "    " << p->age << "    " << p->score << endl;
}

int main()
{
	srand((unsigned int)time(NULL));

	/*
	cout << "Hello world" << endl;	//

	int a = 10;
	cout << "a = " << a << endl;

	cout << "-------------------------------------------------------------------------" << endl;	*/
//--------------------------------------------------------------------------
	
	//�`�q�w�q�覡 
	/*
	//1. #define �ܼ� 
	//Day = 14;		//�`�q���i�ק� ����Ѱ����ѫK�|�X��
	cout << "A week " << Day << " days." << endl;
	//�`�q�w�q�覡 2. const �׹����ܶq
	const int month = 12;
	//month = 24;		//�`�q���i�ק� ����Ѱ����ѫK�|�X��
	cout << "A year " << month << " month." << endl;

	cout << "-------------------------------------------------------------------------" << endl;	*/
//--------------------------------------------------------------------------

	//sizeof
	/*
	cout << "short�����Ҧ��ΪŶ�" << sizeof(short) << endl;
	cout << "int�����Ҧ��ΪŶ�" << sizeof(int) << endl;
	cout << "long�����Ҧ��ΪŶ�" << sizeof(long) << endl;
	cout << "long long�����Ҧ��ΪŶ�" << sizeof(long long) << endl;

	cout << "-------------------------------------------------------------------------" << endl;
	*/
//--------------------------------------------------------------------------
	//���� float
	/*
	float fi = 3.14f;
	cout << "fi = " << fi << endl;
	//����� double
	double di = 3.1415926;	
	cout << "di = " << di << endl;	//���`��X�u���X�����

	//�έpfloat�Pdouble�e�Ϊ����s�Ŷ�
	cout << "Size of float: " << sizeof(float) << endl;
	cout << "Size of double: " << sizeof(double) << endl;

	//��ǰO�ƪk
	float f2 = 3e2;			// 3*10^2
	cout << "f2 = " << f2 << endl;

	float f3 = 3e-2;			// 3*(0.1)^2
	cout << "f3 = " << f3 << endl;

	cout << "-------------------------------------------------------------------------" << endl;	*/
//--------------------------------------------------------------------------
	//char
	/*

	char ch = 'a';	//""���~ ���i�����޸� ch = 'abcd'�]���~ ��@�r�ťu��s�@�� �h�ӭn�}�C
	cout << ch << endl;
	cout << sizeof(char) << endl;	//�r�ū��ܶq�Ҧ����s
	cout << "�r�ū�������ASCII�X " << (int)ch << endl;	//����ASCII�X ex: a-97 A-65

	cout << "-------------------------------------------------------------------------" << endl;	*/
//--------------------------------------------------------------------------
	//��q�r��
	/*
	//���� \n
	cout << "Hello world \n";
	cout << "Hello world \n" << endl;

	//�ϱ׽u  \\  
	cout << "\\" << endl;

	//�������� \t ���F�i�H�����X�ƾ�
	cout << "aaaa \t ChickenDinner" << endl;
	cout << "aa \t ChickenDinner" << endl;
	cout << "aaaaaa \t ChickenDinner" << endl;

	cout << "-------------------------------------------------------------------------" << endl;	*/
//--------------------------------------------------------------------------
	//�r��
	/*
	//C����
	char str1[] = "CharOne";
	cout << str1 << endl;

	//C++����	�n�b�Y���[�J#include <string> �~�i�ϥ�
	string str2 = "CharTwo";
	cout << str2 << endl;

	cout << "-------------------------------------------------------------------------" << endl;	*/
//--------------------------------------------------------------------------
	// bool
	/*
	bool flag = true;
	cout << flag << endl;	// 1

	flag = false;
	cout << flag << endl;	// 0

	cout << "Size of bool: " << sizeof(bool) << endl;

	cout << "-------------------------------------------------------------------------" << endl;	*/
//--------------------------------------------------------------------------
	//��J
	/*//�㫬��J
	int a1 = 0;
	cout << "Key In int number: " << endl;
	cin >> a1;
	cout << a1 << endl;

	//�B�I�ƿ�J
	double d1 = 0;
	cout << "Key In double number: " << endl;
	cin >> d1;
	cout << d1 << endl;

	float f1 = 3.14f;
	cout << "Key In float number; " << endl;
	cin >> f1;
	cout << f1 << endl;

	//�r�ū���J
	char ch1 = 'a';
	cout << "Key In char world: " << endl;
	cin >> ch1;
	cout << ch1 << endl;
	*/
	/*
	//�r�ꫬ��J
	string st = "hello";
	cout << "Key In string world: " << endl;
	cin >> st;
	cout << st << endl;

	//bool
	bool flag1 = false;
	cout << "Key In bool flag number" << endl;
	cin >> flag1;
	cout << flag1 << endl;

	cout << "-------------------------------------------------------------------------" << endl;	*/
//--------------------------------------------------------------------------
	//+-*/	%�����l�� 10%3 = 1
	/*
	==
	!=
	<
	>
	<=
	>=
	*/
	/*
	cout << (20 == 20) << endl;
	cout << (20 != 20) << endl;
	cout << (20 > 20) << endl;
	cout << (20 < 20) << endl;
	cout << (20 >= 20) << endl;
	cout << (20 >= 20) << endl;
	*/

	//cout << "-------------------------------------------------------------------------" << endl;
//--------------------------------------------------------------------------
	//�޿�B���
	/*
	!	!a a��false !a��true �Ϥ�
	&&	and		a&&b ab�Ҭ�true�~�i��true
	||  or		a||b ab��@��true �Y��true
	*/
	/*
	int a = 6;
	int b = 5;
	cout << !a << endl;		// 0
	cout << !!a << endl;	// 1

	a = 2;	 b = 0;
	cout << (a && b) << endl;	//0
	a = 2;	 b = 2;
	cout << (a && b) << endl; //1

	a = 2;	b = 0;
	cout << (a || b) << endl;	// 1
	a = 0;	b = 0;
	cout << (a || b) << endl;	// 0
	*/

	//cout << "-------------------------------------------------------------------------" << endl;
//--------------------------------------------------------------------------
	//�y�{���c ��ܵ��c if
	/*
	int a = 5;
	if (a) {
		cout << "A is Real" << endl;
	}
	else {
		cout << "A is Nothing" << endl;
	}
	*/
	/*
	int a = 0;
	if (a) {
		cout << "A is Real" << endl;
	}
	else {
		cout << "A is Nothing" << endl;
	}
	*/
	/*
	int a = 2; int b = 0;
	if (a && b) {
		cout << "AB is Real" << endl;
	}
	else if(a){
		cout << "A is Real" << endl;
	}
	else if (b) {
		cout << "B is Real" << endl;
	}
	else {
		cout << "AB is Nothing" << endl;
	}
	*/

	//cout << "-------------------------------------------------------------------------" << endl;
//--------------------------------------------------------------------------
	//switch
	/*
	int score = 0;
	cout << "Enter your score: " << endl;
	cin >> score;

	switch (score)	//�u��P�_�㫬�Φr�� ����if��P�w�j�϶� ���p�϶����ӲM�� ����|��if���I
	{
		case 10:
			cout << "Best score" << endl;
			break;
		case 9:
			cout << "Great score" << endl;
			break;
		case 8:
			cout << "Well score" << endl;
			break;
		case 7:
			cout << "Good score" << endl;
			break;
		case 6:
			cout << "Normal score" << endl;
			break;
		default:
			cout << "Suck" << endl;
			break;
	}


	cout << "-------------------------------------------------------------------------" << endl;
	*/
//--------------------------------------------------------------------------
	//while
	/*
	int i = 0;
	while (i < 10) {
		cout << i << endl;
		i++;
	}

	cout << "-------------------------------------------------------------------------" << endl;
	*/
	
	// do while 
	/*	�ۤ�while�Ado while�|������@��
	int i = 0;
	do {
		cout << i << endl;
		i++;
	} while (i < 10);
	cout << "-------------------------------------------------------------------------" << endl;
	*/
//--------------------------------------------------------------------------
	//�H����
	/*
	//int num = rand() % 100; //�ͦ� 0~99 �������H���� �u���o��|�o�{�C���H���Ƴ��@�� �ҥH�n�[�J�ɶ����H��(�U������) �i�H�[�b�}�Y�Y�i
	srand((unsigned int)time(NULL)); //�[�J�ɶ����H�� �����[�b�U�����椧�e �ӥB���}�Y�ݦ� #include<ctime> �Y��� ���Mtime�|����
 	int num = rand() % 100 + 1;
	cout << num << endl;

	cout << "-------------------------------------------------------------------------" << endl;
	*
	
	//����P���(�T���ABC A^3+B^3+C^3=ABC)
	/*
	int num = 100;
	do {
		int a = num / 100;			//�ʦ��
		int b = (num % 100) / 10;	//�Q���
		int c = num % 10;			//�Ӧ��

		if (a * a * a + b * b * b + c * c * c == num) {
			cout << num << endl;
		}
		num++;

	} while (num < 1000);
	*/
	
//--------------------------------------------------------------------------
	//for
	/*
	for (int i = 0; i < 10; i++) {
		cout << i << endl;
	}
	*/
	/*
	//��P�C�������� �m��
	for (int i = 1; i <= 100; i++) {
		if (i / 10 == 7 || i % 10 == 7 || i % 7 == 0) {
			cout << i << endl;
		}
	}

	cout << "-------------------------------------------------------------------------" << endl;
	*/
	/*
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << "* ";
		}	
		cout << endl;
	}
	*/

//--------------------------------------------------------------------------
	//continue
	/*���L�����`���b���椧�᪺�{�� ��������U�@���`��
	for (int i = 0; i < 10; i++) {
		if (i == 2) {
			continue;		// i == 2���ɭԷ|���L�����`�� ������U�@��i=3���`��
		}
		cout << i << endl;
	}
	
	cout << "-------------------------------------------------------------------------" << endl;
	*/
//--------------------------------------------------------------------------
	//goto �O�� �e����bug
	//cout << "-------------------------------------------------------------------------" << endl;
//--------------------------------------------------------------------------
	//�Ʋ�
	/*
	//1. �ƾ����� �ƲզW[����];
	//2. �ƾ����� �ƲզW[����] = {0,2,4,.....};
	//3. �ƾ����� �ƲզW[] = {0,2,4

	int arr1[5] = { 0,2,4,6,8 };
	cout << sizeof(arr1) << endl;					//��ӼƲթҦ��Ŷ�
	cout << sizeof(arr1[0]) << endl;				//�ӭӤ����ҥe�Ŷ�
	cout << sizeof(arr1) / sizeof(arr1[0]) << endl;	//�Ʋդ����Ӽ�
	cout << endl;
	for (int i = 0; i < 5; i++) {
		cout << arr1[i] << endl;
	}

	int arr2[] = { 0,2,4,6,8,22,44,66,88 };

	cout << (int)arr1 << endl;		//�Ʋխ��a�}
	cout << (int)&arr1[0] << endl;	//�ƲղĤ@�����a�}
	cout << (int)&arr1[1] << endl;	//�ƲղĤG�����a�}

	cout << "-------------------------------------------------------------------------" << endl;
	*/
//--------------------------------------------------------------------------
	//bubble sort
	/*
	int arr[] = { rand() % 100 ,rand() % 100 ,rand() % 100 ,rand() % 100 ,rand() % 100 ,rand() % 100 ,rand() % 100 ,rand() % 100 ,rand() % 100 ,rand() % 100 };
	for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++) {
		for (int j = 0; j < (sizeof(arr) / sizeof(arr[0])); j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++) {
		cout << arr[i] << endl;
	}

	cout << "-------------------------------------------------------------------------" << endl;
	*/
//--------------------------------------------------------------------------
	//�G���Ʋ�
	/*
	1. �ƾ����� �ƲզW[���][�C��];
	2. �ƾ����� �ƲզW[���][�C��] = {{��1, ��2},{��3, ��4}..};
	3. �ƾ����� �ƲզW[���][�C��] = { ��1 ��2 ��3 ��4};
	4. �ƾ����� �ƲզW[ ][�C��] = { ��1 ��2 ��3 ��4};
	*/
	/*
	int arr[2][3];
	cout << sizeof(arr) << endl;	//�Ʋդj�p
	cout << sizeof(arr) / sizeof(arr[0]) << endl;		// 2 �Ʋզ��
	cout << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;	// 3 �ƲզC��

	cout << (int)arr << endl;	//�Ʋխ�����}
	cout << (int)arr[1] << endl;	// �ƲղĤG��}�Y��}
	cout << (int)arr[1][1] << endl;	// �ƲղĤG��G�C��} 

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		for (int j = 0; j < sizeof(arr[0]) / sizeof(arr[0][0]); j++) {
			arr[i][j] = i + j;
			cout << arr[i][j];
		}
		cout << endl;
	}
	*/
	/*
	int arr[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	cout << sizeof(arr) / sizeof(arr[0]) << endl;		// 2
	cout << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;	// 3

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		for (int j = 0; j < sizeof(arr[0]) / sizeof(arr[0][0]); j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	*/ 
	/*
	int arr[2][3] = {4,5,6,7,8,9};		// �|�ۤv���� 456 789 ���
	cout << sizeof(arr) / sizeof(arr[0]) << endl;		// 2
	cout << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;	// 3

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		for (int j = 0; j < sizeof(arr[0]) / sizeof(arr[0][0]); j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	*/
	/*
	int arr[][3] = {4,5,6,7,8,9};		//���]�w�C�ƴN�i�H�ۤv������
	cout << sizeof(arr) / sizeof(arr[0]) << endl;		// 2
	cout << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;	// 3

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		for (int j = 0; j < sizeof(arr[0]) / sizeof(arr[0][0]); j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}

	cout << "-------------------------------------------------------------------------" << endl;
	*/
//--------------------------------------------------------------------------
	// function
	/*
	���B�J
	1	��^������
	2	��ƦW
	3	�Ѽƪ�C
	4	�����y�y
	5	return��F��
	*/
	/*
	int ad = add(22, 30);	//�b��26�� main��󤧫e
	cout << ad << endl;

	cout << "-------------------------------------------------------------------------" << endl;
	*/
	/*
	int a = 20;
	int b = 35;
	swap(a, b);
	cout << a << endl;
	cout << b << endl;
	*/
	/*
	int a = 20;
	int b = 35;
	swap(a, b);	//�q��L�����ofunction
	*/
//--------------------------------------------------------------------------
	//���w
	/*
	�q�L���w�X�ݤ��s�a�}
	
	int a = 20;
	int* p = &a;	//�إ߫��wp���Va����}
	cout << &a << endl;
	cout << p << endl;

	���w�e�[�@��*�N��ѤޥΡA�����w���V�����s�����ƾ�
	cout << *p << endl; // ���ɷ|��X���Oa��20
	*p = 5500;	//�����ק�*p�ƾ� �N�|�����ק�a
	cout << a << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	*/
	/*
	int a = 20;
	int* p = &a;	//�إ߫��wp���Va����}

	cout << *p << endl;
	cout << sizeof(p) << endl;
	//�s���w���ݭn�Ӧh�Ŷ�
	cout << sizeof(int*) << endl;
	cout << sizeof(float*) << endl;
	cout << sizeof(double*) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(*p) << endl;
	*/
	/*
	//�ū��w �Ω󵹫��w�ܶq��l��
	//�ū��w ���i�i��X��
	int* p = NULL;
	// *p = 200;	 //���榹��K�|�X�� �]���ū��wNULL�|���V�t�Υe�Ϊ����s �����\�X��

	//�����w (�@�ؿ��~)
	int* p = (int*)0x1100;	//�i�sĶ ���H�K���V�����s����ϥΪ� �p�G�ϥΫK�|���楢��
	//�ȥ��קK�ϥ�
	//�ū��w�P�����w�����O�g�L�����ӽЪ��Ŷ� �ҥH���קK�ޥ�
	*/
//--------------------------------------------------------------------------
	//const�׹����w
	/*
	const�׹����w �`�q���w
	const�׹��`�q ���w�`�q
	const�Y�׹����w �S�׹��`�q
	*/
	/*
	int a = 10;
	int b = 10;
	int* p = &a;
	
	const int* p = &a;	//�`�q���w �S�I: ���w�����V�i�ק� �����w���V���Ƥ��i��
	*p = 20;	//���~ ���w���V���ƭȤ��i��
	p = &b;		//�i���� ���w���V�i�ק�
	
	int* const p = &a;	//���w�`�q �S�I: ���w���V���i�� �����w���V���ƥi��
	*p = 20;	//�i���� ���w���V���ƭȥi��
	p = &b;		//���~ ���w���V���i�ק�

	const int* const p = &a;	//�׹��`�q �S�I: ���w���V���i�� ���w���V���Ƥ��i��
	*p = 20;	//���~ ���w���V���ƭȤ��i��
	p = &b;		//���~ ���w���V���i�ק�
	
	cout << "-------------------------------------------------------------------------" << endl;
	*/
//--------------------------------------------------------------------------
	//���w�P�Ʋ�	���w�P���
	/*
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = arr;	//���w���Varr�Ʋխ���a�}
	cout << *p << endl;	//1
	p++;
	cout << *p << endl;	//2

	int* p2 = arr;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		cout << *p2 << endl;
		p2++;
	}

	cout << "-------------------------------------------------------------------------" << endl;
	*/
	/*
	int a = 10;
	int b = 32;
	swap2(&a, &b);
	cout << a << endl;
	cout << b << endl;
	//�o�^����Ưu��Ʀr��F �S�Ϋ��Хu���ܼƵL�k�p��
	*/
	/*
	int arr[10] = { 4,2,7,9,10,5,1,8,3,6 };
	int* p = arr;	//���w���Varr�Ʋխ���a�}
	int* p2 = p;	//��ӫ��V�ۦP��m������
	cout << p << p2 << endl;
	ArrowArrayBubbleSort(p, sizeof(arr) / sizeof(arr[0]));	//�A�Ϋ���array��bubble sort
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		cout << arr[i] << endl;
		cout << *p2 << endl;
		p2++;
	}
	*/
//--------------------------------------------------------------------------
	//���c��
	/*
	struct student {
		string name;
		int age;
		int score;
	};
	*/
	/*
	struct student s1;	//��󭺫إߪ����c��
	s1.name = "Leon";
	s1.age = 24;
	s1.score = 990;
	cout << s1.name << "    " << s1.age << "    " << s1.score << endl;

	struct student s2 = { "Peter", 20, 870 };
	cout << s2.name << "    " << s2.age << "    " << s2.score << endl;

	//�إߵ��c��ɶ��K�إߪ��ܶq �����
	sss.name = "Jeams";
	sss.age = 33;
	sss.score = 900;
	cout << sss.name << "    " << sss.age << "    " << sss.score << endl;

	cout << "-------------------------------------------------------------------------" << endl;
	*/

	//���c��Ʋ�
	/*
	struct student StuArr[3] = {
		{"Leon",22,870},
		{"Peter",25,990},
		{"Jeams",20,900}
	};

	//�קﵲ�c��Ʋդ�����
	StuArr[2].age = 30;

	//�˵�
	for (int i = 0; i < sizeof(StuArr) / sizeof(StuArr[0]); i++) {
		cout << StuArr[i].name << "    " << StuArr[i].age << "    " << StuArr[i].score << endl;
	}
	*/

	//���c����w
	/*
	struct student s = { "Peter", 20, 870 };
	struct student* p = &s;
	cout << p->name << "    " << p->age << "    " << p->score << endl;
	*/

	//���c��Xù���M��
	/*
	teacher t;
	t.age = 50;
	t.id = 11058;
	t.name = "Wang";
	t.stu.age = 20;
	t.stu.score = 900;
	t.stu.name = "Ammy";
	cout << t.name << "    " << t.age << "    " << t.id << endl;
	cout << t.stu.name << "    " << t.stu.age << "    " << t.stu.score << endl;
	*/

	//���c�鰵��ưѼ�
	/*
	struct student s = { "Peter", 20, 870 };
	printStuS(s);	//���i��ƭ�
	struct student* p = &s;
	printStuP(p);	//�i�H��ƭ�
	*/

	//���c��+const�ϥ�
	/*
	struct student s = { "Peter", 20, 870 };
	//printStuS(s);
	printStuP(&s);
	*/
	
//--------------------------------------------------------------------------

	cout << "-------------------------------------------------------------------------" << endl;
//--------------------------------------------------------------------------

	cout << "-------------------------------------------------------------------------" << endl;
//--------------------------------------------------------------------------


	cout << "-------------------------------------------------------------------------" << endl;
//--------------------------------------------------------------------------


	cout << "-------------------------------------------------------------------------" << endl;
//--------------------------------------------------------------------------


	cout << "-------------------------------------------------------------------------" << endl;
//--------------------------------------------------------------------------




	system("pause");

	return 0;
}


