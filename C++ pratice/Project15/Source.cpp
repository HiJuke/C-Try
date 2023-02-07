#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include <fstream>	//	���ާ@�t���Y���
#include <vector>
#include <algorithm>

using namespace std;\

//STL
/*
�n��ɤ@���Ʊ�إߤ@�إi���ƧQ�Ϊ��F��
C++�����V��H �x���s�{��Q �ؼдN�O�ƥΩʴ���
�j�h���p �ƾڵ��c�M��k�����঳�@�M�з� �ɭP�Q���q�Ƥj�q���Ƥu�@
���إ߼ƾڵ��c�M��k���@�M�з� �إ�STL
*/
/*
STL (Standard Template Library, �зǼҪO�w)
STL �s�q�W���� �e��(container) ��k(algorithm) ���N��(itierator)
�e�� ��k ��̳z�L���N���L�_�s��
STL �X�G�Ҧ��N�X���ĥ� �ҪO�� �άO �ҪO���
*/
/*
STL ���j�ե�: �e�� ��k ���N�� ���� �A�t��(�t����) �Ŷ��t�m��
1. �e��:		�U�ؼƾڵ��c �pvector list deque set map...
2. ��k:		�U�ر`�κ�k �psort find copy for_each...
3. ���N��:		�e���P��k�����X��
4. ����:		������� �@����k���Y�ص���
5. �A�t��:		�Ψӭ׹� �e�� ���� ���N�����f ���F��
6. �Ŷ��t�m��:	�Ŷ��t�m�P�޲z
*/

//------------------------------------------------------
//vector�s�񤺸m�ƾ�����
//�e��: vector		��k: for_each		���N��: vector<int> itierator
void TempPrint(int val) { cout << val << endl; }
void test01() {
	//�Ыؤ@��vector�e��
	vector<int> v;

	//�V�e�������J�ƾ�
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);

	//�Ĥ@�عM���覡
	//�q�L���N���X�ݮe�����ƾ�
	cout << "\tWay One" << endl;
	vector<int>::iterator itBegin = v.begin();	//begin �_�l���N�� ���V�e�����Ĥ@�Ӥ���
	vector<int>::iterator itEnd = v.end();		//end �������N�� ���V�e�����̫�@�Ӥ������U�@�Ӧ�m
	while (itBegin != itEnd) {
		cout << *itBegin << endl;
		itBegin++;
	}

	//�ĤG�عM���覡
	cout << "\tWay Two" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}

	//�ĤT�عM���覡	�Q��STL���ѫK�Q��k ( ���]�t #include <algorithm> )
	cout << "\tWay Three" << endl;
	for_each(v.begin(), v.end(),TempPrint);	//�}�l�I �����I TempPrint�h�O�e���w�q����ƪ���ƦW
	//����F�� ��ƥ����ե� �bfor_each����ɤ~�̧ǽե�
}

//------------------------------------------------------
//vector�s��ۭq�ƾ�����
class Person1 {
public:
	Person1(string name, int age) {
		m_Age = age;
		m_Name = name;
	}
	string m_Name;
	int m_Age;
};
void test02() {
	vector<Person1>v;

	Person1 p1("Chandler", 35 );
	Person1 p2("Tony", 38 );
	Person1 p3("Michel",26 );
	Person1 p4("Liya",33 );
	Person1 p5("Leom",45 );

	//�V�e�������J�ƾ�
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//�M���e�����ƾ�
	for (vector<Person1>::iterator it = v.begin(); it != v.end(); it++) {
		//cout << (*it).m_Name << "\t" << (*it).m_Age <<endl;
		cout << it->m_Name << "\t" << it->m_Age << endl;
	}
}
//vector�s��ۭq�ƾ����� ���w
void test03() {
	vector<Person1*>v;

	Person1 p1("Peter", 35);
	Person1 p2("Tony", 38);
	Person1 p3("Michel", 26);
	Person1 p4("Liya", 33);
	Person1 p5("Leon", 45);

	//�V�e�������J�ƾ�
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	//�M���e�����ƾ�
	for (vector<Person1*>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it)->m_Name << "\t" << (*it)->m_Age <<endl;
		//cout << it->m_Name << "\t" << it->m_Age << endl;
	}
}

//------------------------------------------------------
//vector�e���O�M�e��

void test04() {
	vector<vector<int>>v;	//vector�e���O�M�e��

	//�Ыؤp�e��
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	vector<int>v5;

	//�V�p�e�����K�[�ƾ�
	for (int i = 0; i < 4; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
		v5.push_back(i + 5);
	}

	//�V�p�e�����J��j�e����
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);

	//�q�L�j�e�� ��Ҧ��ƾڹM���@�M
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		//(*it)�]�O�e�� �ҥH�]�n�M��
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
			cout << *vit << " ";
		}
		cout << endl;
	}
}

//------------------------------------------------------


//------------------------------------------------------


//------------------------------------------------------



int main() {
	//vector�s�񤺸m�ƾ�����
	//test01();

	//vector�s��ۭq�ƭp����
	//test02();
	//test03();

	//vector�e���O�M�e��
	test04();

	system("pause");
	return 0;
}