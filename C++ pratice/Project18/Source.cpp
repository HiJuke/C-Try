#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include <fstream>	//	���ާ@�t���Y���
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

//deque�e��	�Y���	#include <deque>
//���ݼƲ�  �i�H���Y���i�洡�J�R�����ާ@

//�Pvector �ϧO
//-vector����Y�����J�R�����S�Ĳv �ƾڶq�V�j�Ĳv�V�C
//-deque�ۤ񤧤U����Y�����J�R����vector �ֳt
//-vector�X�ݤ������t�פ�deque �ֳt ���{�H�M��̪�������{����

void printDeque(const deque<int>& d) {		//�[const ����e�����ƾڳQ���
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}

//------------------------------------------------------
//�c�y���
/*
deque<T> deqT;				//�q�{�c�y����
deque(beg, end);			//�c�y��ƱN[beg, end] �϶�������������������
deque(n, elem)				//�c�y��ƱNn ��elem����������
deque(const deque &deq);	//�����c�y���
*/
void test01() {
	deque<int>d1;
	for (int i = 1; i <= 10; i++) {
		d1.push_back(i * 10);
	}
	printDeque(d1);

	deque<int>d2(d1.begin(), d1.end());
	printDeque(d2);

	deque<int>d3(10, 87);
	printDeque(d3);

	deque<int>d4(d3);
	printDeque(d4);

}

//------------------------------------------------------
//��Ⱦާ@
/*
deque& operator = (const deque &deq);	//���������ާ@��
assign(beg, end);						//�N[beg, end]�϶����ƾګ�����ȵ�����
assign(n, elem);						//�Nn��elem������ȵ�����
*/
void test02() {
	deque<int>d1;
	for (int i = 1; i <= 10; i++) {
		d1.push_back(i * 10);
	}
	printDeque(d1);

	//���
	//deque& operator = (const deque &deq);	//���������ާ@��
	deque<int>d2;
	d2 = d1;
	printDeque(d2);

	//assign(beg, end);		//�N[beg, end]�϶����ƾګ�����ȵ�����
	deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	printDeque(d3);

	//assign(n, elem);		//�Nn��elem������ȵ�����
	deque<int>d4;
	d4.assign(10, 30);
	printDeque(d4);

}

//------------------------------------------------------
//�j�p�ާ@
//deque�S���e�q���� ��ƾ������i�����X�i
/*
empty();				�P�_�e���O�_����
size();					��^�e���������Ӽ�
resize(num);		-���s���w�e�����׬�num �Y�e���ܦ��h�H �q�{�� 0 ��R�s��m
					-�Y�e���ܵu �����W�X���ת������Q�R��
resize(num, elem);	-���s���w�e�����׬�num �Y�e���ܦ��h�H   elem   ��R�s��m
					-�Y�e���ܵu �����W�X���ת������Q�R��
*/
void test03() {
	deque<int>d1;
	for (int i = 1; i <= 10; i++) {
		d1.push_back(i * 10);
	}
	printDeque(d1);

	if (d1.empty()) {		//���u �N��e������
		cout << "d1����" << endl;
	}
	else {
		cout << "d1������" << endl;
		cout << "�j�p��: " << d1.size() << endl;
	}

	//���s���w�j�p
	d1.resize(15);
	printDeque(d1);

	d1.resize(20, 33);
	printDeque(d1);
}

//------------------------------------------------------
//���J�M�R��
/*
push_back(ele);					-�������J����ele
push_front(ele);				-�Y�����J����ele
pop_back();						-�̧��R�������@��
pop_front();					-���Y�R�������@��

insert(pos, ele);				-���N�����V��mpos ���J���� ele
insert(pos, int count, ele);	-���N�����V��mpos ���J���� ele ���Jcount ��
insert(pos, start, end);		-���N�����V��mpos ���Jstart �� end ����������
erase(pos);						-�R�����N�����V������ ��^�U�@�Ӽƾڪ���m
erase(start, end);				-�R�����N�� start �� end ���������� ��^�U�@�Ӽƾڪ���m
clear();						-�R���e�����Ҧ�����
*/
void test04() {
	deque<int>d1;
	for (int i = 1; i <= 10; i++) {
		d1.push_back(i * 10);
	}
	printDeque(d1);

	d1.push_back(87);	//�������J����ele
	d1.push_front(87);	//�Y�����J����ele
	printDeque(d1);
	d1.pop_back();		//�̧��R�������@��
	d1.pop_front();		//���Y�R�������@��
	printDeque(d1);

	d1.insert(d1.begin()+5, 99999);		//���N�����V��mpos ���J���� ele
	printDeque(d1);
	d1.erase(d1.begin() + 5);			//�R�����N�����V������ ��^�U�@�Ӽƾڪ���m
	printDeque(d1);

	deque<int>d2;
	for (int i = 1; i <= 5; i++) {
		d2.push_back(i * 100);
	}
	printDeque(d2);

	d1.insert(d1.begin() + 5, 3, 4444 );		//���N�����V��mpos ���J���� 4444 ���J3 ��
	printDeque(d1);
	d1.erase(d1.begin() + 5, d1.begin()+8);		//�R�����N�����V���϶� ��^�U�@�Ӽƾڪ���m
	printDeque(d1);

	d1.insert(d1.begin() + 5, d2.begin(), d2.end());	//���N�����V��mpos ���Jstart �� end ����������
	printDeque(d1);

	d1.clear();
	printDeque(d1);
}

//------------------------------------------------------
//�ƾڦs��
/*
at(int idx);	//��^����idx�ҫ����ƾ�
operator[];		//��^����idx�ҫ����ƾ�
front();		//��^�e���Ĥ@�Ӽƾڤ���
back();			//��^�e���̫�@�Ӽƾڤ���
*/
void test05() {
	deque<int>d1;
	for (int i = 1; i <= 10; i++) {
		d1.push_back(i * 10);
	}
	printDeque(d1);

	//at(int idx);	//��^����idx�ҫ����ƾ�
	for (int i = 0; i < d1.size(); i++) {
		cout << d1.at(i) << "  ";
	}
	cout << endl;

	//operator[];		//��^����idx�ҫ����ƾ�
	for (int i = 0; i < d1.size(); i++) {
		cout << d1[i] << "  ";
	}
	cout << endl;

	cout << "�Ĥ@����:  " << d1.front()<< endl;
	cout << "��������:  " << d1.back() << endl;

}

//------------------------------------------------------
//�ƧǾާ@
//sort(iterator beg, iterator end);	//�� beg~end �϶��������i��Ƨ�

void test06() {
	deque<int>d1;
	for (int i = 1; i <= 10; i++) {
		d1.push_back(rand()%100+1);
	}
	printDeque(d1);

	sort(d1.begin(), d1.end());	//�ƧǾާ@
	cout << "�Ƨǫ�" << endl;
	printDeque(d1);
}
//------------------------------------------------------

int main() {
	//���U�@�U�����|�Ψ쪺�H����
	srand((unsigned int)time(NULL));

	//�c�y���
	//test01();

	//��Ⱦާ@
	//test02();

	//�j�p�ާ@
	//test03();

	//���J�M�R��
	//test04();

	//�ƾڦs��
	//test05();

	//�ƧǾާ@
	//test06();

	system("pause");
	return 0;
}
