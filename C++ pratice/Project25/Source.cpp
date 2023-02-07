#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include <fstream>	//	���ާ@�t���Y���
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include<functional>

using namespace std;

//STL ��ƹ�H 

//����
/*
����:
	- ������ƽեξާ@�Ū��� ���H�٬���ƹ�H
	- ��ƹ�H�ϥέ����� �欰������ƽե� �]�٬� ����
����:
	- ���� �O�@���� ���O���
*/

//�ϥ�
/*
 - �ϥή� �i�H�����q��ƨ��˽ե� �i�H���Ѽ� �i�H����^��
 - �W�X���q��ƪ����� ���ƥi�H���ۤv�����A
 - �i�H�����Ѽƶǻ�
*/

//--------------------------------------------------------------------------
//��ƹ�H�򥻨ϥ�
//1. �����q��ƨ��˽ե�
class MyAdd {
public:
	int operator()(int a, int b) {
		return a + b;
	}
};
void test01() {
	MyAdd myadd;
	cout << myadd(22, 33) << endl;
}

//2. �W�X���q��Ʒ��� �i�H���ۤv�����A
class MyPrint {
public:
	MyPrint(){
		this->count = 0;
	}
	void operator()(string test) {
		cout << test << endl;
		this->count++;	//��s�ۤv�����A
	}
	int count;	//�����ۤv�����A
};
void test02() {
	MyPrint myprint;
	myprint("Hello World!!");
	myprint("Hello World!!");
	myprint("Hello World!!");
	myprint("Hello World!!");
	myprint("Hello World!!");
	cout << "myprint �եΦ��Ƭ�: " << myprint.count << endl;
}

//3. �i�H�����Ѽƶǻ�
void doPrint(MyPrint& mp, string test) {
	mp(test);
}
void test03() {
	MyPrint myprint;
	doPrint(myprint, "Hello C++");
}

//--------------------------------------------------------------------------
//�׵�
/*
-- ��^bool ���������ƺ٬��׵�
-- �poperator �����@�ӰѼ� �٬��@���׵�
-- �poperator ������ӰѼ� �٬��G���׵�
*/

//--------------------------------------------------------------------------
//�@���׵�
class GreaterFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};

void test04() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	//�d�䦳�L�j�󤭪��Ʀr
	//GreaterFive �ΦW��ƹ�H
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end()) {
		cout << "�S���" << endl;
	}
	else {
		cout << "���F �ӼƭȬ�: " << *it << endl;
	}
}

//--------------------------------------------------------------------------
//�G���׵�
class MyComFF {
public:
	bool operator()(int a, int b) {
		return a > b;
	}
};

void test05() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(rand()%90 +10);
	}
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "   ";
	}
	cout << endl<<"---------------------------------------------------------------------" << endl;

	//�ϥΨ�ƹ�H ���ܺ�k���� �令����
	sort(v.begin(), v.end(), MyComFF());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "   ";
	}
	cout << endl << "---------------------------------------------------------------------" << endl;
}

//--------------------------------------------------------------------------
//���ب�ƹ�H
/*
����:
	--STL���ت��@�Ǩ�ƹ�H
����:
	--��N����
	--���Y����
	--�޿����
�Ϊk:
	--�o�ǥ��ƩҲ��`����H �Ϊk�M�@���Ƨ����ۦP
	--�ϥΤ��ب�ƹ�H �ݭn�ޤJ�Y��� #include<functional>
*/

//--------------------------------------------------------------------------
//���ب�ƹ�H-��ƥ���
/*
--��{�|�h�B��
--�䤤negate �O�@���B�� ��L���O�G��

template<class T> T plus<T>			//�[�k����
template<class T> T minus<T>		//��k����
template<class T> T multiplies<T>	//���k����
template<class T> T divides<T>		//���k����
template<class T> T modulus<T>		//���ҥ���
template<class T> T negate<T>		//���ϥ���
*/

void test06() {
	//negate �@������ ���ϥ���
	negate<int>n;
	cout << n(50) << endl;	//-50

	//plus �G������ �[�k
	plus<int> p;
	cout << p(20, 50) << endl;
}

//--------------------------------------------------------------------------
//���ب�ƹ�H-���Y����
/*
--��{���Y���

template<class T> bool equal_to<T>			//����
template<class T> bool not_equal<T>			//������
template<class T> bool greater<T>			//�j��
template<class T> bool greater_equal<T>		//�j�󵥩�
template<class T> bool less<T>				//�p��
template<class T> bool less_equal<T>		//�p�󵥩�
*/

void test07(){
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
	//�ϥΨ�ƹ�H ���ܺ�k���� �令���� ���L�o��������Y�B���
	//sort(v.begin(), v.end(), MyComFF());
	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl << "---------------------------------------------------------------------" << endl;
}

//--------------------------------------------------------------------------
//���ب�ƹ�H-�޿����
/*
--��{�޿�B��

template<class T> bool logical_and<T>		//�޿�and
template<class T> bool logical_or<T>		//�޿�or
template<class T> bool logical_not<T>		//�޿�not
*/

void test08() {
	vector<bool> v;
	v.push_back(true);
	v.push_back(true);
	v.push_back(true);
	v.push_back(false);
	v.push_back(false);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;

	//�Q���޿�not �Nv �h��t�@�Ӯe���� ������Ͼާ@
	vector<bool>VV;
	//�Φ���k�ݭn�ƥ����t�@�Ӯe���}�P�Ŷ�
	VV.resize(v.size());

	transform(v.begin(), v.end(), VV.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = VV.begin(); it != VV.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}

//--------------------------------------------------------------------------


int main() {
	//���U�@�U�����|�Ψ쪺�H����
	srand((unsigned int)time(NULL));

	//��ƹ�H�򥻨ϥ�
	//test01();
	//test02();
	//test03();

	//�@���׵�
	//test04();

	//�G���׵�
	//test05();

	//���ب�ƹ�H-��ƥ���
	//test06();

	//���ب�ƹ�H-���Y����
	//test07();

	//���ب�ƹ�H-�޿����
	test08();



	system("pause");
	return 0;
}

