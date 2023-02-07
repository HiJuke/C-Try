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

using namespace std;

class Person {
public:
	Person(string name, int age) {
		this->m_name = name;
		this->m_age = age;
		//this->m_Height = height;
	}

	string m_name;
	int m_age;
	//int m_Height;
};

//map / multimap
/*
²��:
	-map�� �Ҧ������Ҭ�pair
	-map�� �Ĥ@�Ӥ�����key �_����ާ@�� �ĤG�Ӥ�����value (���)
	-�Ҧ��������|�ھڤ�������� �۰ʱƧ�
����:
	-map / multimap �ݩ� ���p���e�� ���h���c�O�H�G�e���{
�u�I:
	-�i�H�ھ� key �� �ֳt���value��
map & multimap�ϧO:
	-map �����\�e��������key ����
	-multimap ���\�e��������key ����
*/

void printMap(const map<int, int>& mp) {
	for (map<int, int>::const_iterator it = mp.begin(); it != mp.end(); it++) {
		cout << "key = " << it->first << "\tvalue = " << it->second << endl;
	}
	cout << endl;
}


//----------------------------------------------------------------
//�c�y�M���
/*
�c�y:
	map<T1, T2> mp:						//�q�{�c�y
	map(const map &mp);					//�����c�y

���:	
	map& operator = (const map &mp);	//���������ާ@��
*/
//�O�� map �O�̾�key�ȱƧ� ���O�̾�value

void test01() {
	map<int, int> m;

	m.insert(pair<int, int>(1, 10));	//1 ���Ω���ު�key 10�h�O��誺�ƭ�
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	printMap(m);
	//�O�� map �O�̾�key�ȱƧ� ���O�̾�value

	map<int, int> m2(m);
	printMap(m2);

	map<int, int> m3;
	m3 = m;
	printMap(m3);
}


//----------------------------------------------------------------
//�j�p�M�洫
/*
size();		//��^�e���������ƥ�
empty();	//��^�e���O�_����
swap(st);	//�洫��Ӷ��X�e��
*/
void test02() {
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));	//1 ���Ω���ު�key 10�h�O��誺�ƭ�
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	printMap(m);

	if (m.empty()) {
		cout << "�e������" << endl;
	}
	else {
		cout << "�e�������� \t��j�p��: " << m.size() << endl;
	}

	map<int, int> m2;
	m2.insert(pair<int, int>(10, 100));	//1 ���Ω���ު�key 10�h�O��誺�ƭ�
	m2.insert(pair<int, int>(30, 300));
	m2.insert(pair<int, int>(20, 200));
	m2.insert(pair<int, int>(40, 400));
	printMap(m2);

	//�洫
	m.swap(m2);
	cout << "m" << endl;
	printMap(m);
	cout << "m2" << endl;
	printMap(m2);
}

//----------------------------------------------------------------
//���J�M�R��
/*
insert(ele);			-���J���� ele
erase(pos);				-�R�����N�����V������					��^�U�@�Ӽƾڪ���m
erase(start, end);		-�R�����N�� start �� end ����������		��^�U�@�Ӽƾڪ���m
erase(key);				-�R���e����key �Ȫ�����
*/
void test03() {
	map<int, int> m;
	//���J
	//�Ĥ@��
	m.insert(pair<int, int>(10, 100));
	m.insert(pair<int, int>(30, 300));
	m.insert(pair<int, int>(20, 200));
	m.insert(pair<int, int>(40, 400));
	//�ĤG��
	m.insert(make_pair(15, 150));
	//�ĤT��
	m.insert(map<int, int>::value_type(25, 250));
	//�ĥ|��
	m[35] = 350;
	printMap(m);

	//erase
	m.erase(++(++(++m.begin())));
	printMap(m);

	m.erase(++m.begin(), --m.end());
	printMap(m);

	m.erase(40);
	printMap(m);
}

//----------------------------------------------------------------
//�d��M�έp
/*
find(key);	//��key�O�_�s�b �s�b���ܪ�^�Ӥ��������N�� ���s�b���ܪ�^set.end();
count(key);	//�έpkey �����Ӽ�
*/
void test04() {
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));	//1 ���Ω���ު�key 10�h�O��誺�ƭ�
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	printMap(m);

	map<int, int>::iterator pos = m.find(2);

	if (pos != m.end()) {
		cout << "�ؼ�key" << pos->first<< " �s�b \t�ƭȬ�" << pos->second << endl;
	}
	else {
		cout << "�ؼ�key ���s�b" << endl;
	}

	//map���i���J����key �ҥHcount���h��1
	//multimap�N���i�঳�j��1 ��count
	cout << m.count(3) << endl;
	cout << m.count(9) << endl;
}

//----------------------------------------------------------------
//�Ƨ�
//�Q�Υ��Ƨ��ܱƧǳW�h
class MyCompare {
public:
	bool operator()(int a, int b) const {
		return a > b;
	}
};

void test05() {
	map<int, int, MyCompare> m;
	m.insert(pair<int, int>(1, 10));	//1 ���Ω���ު�key 10�h�O��誺�ƭ�
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	

	for (map<int, int, MyCompare>::const_iterator it = m.begin(); it != m.end(); it++) {
		cout << "key = " << it->first << "\tvalue = " << it->second << endl;
	}
	cout << endl;
}

//----------------------------------------------------------------

int main() {
	//���U�@�U�����|�Ψ쪺�H����
	srand((unsigned int)time(NULL));

	//�c�y�M���
	//test01();

	//�j�p�M�洫
	//test02();

	//���J�M�R��
	//test03();

	//�d��M�έp
	//test04();

	//�Ƨ�
	test05();

	
	system("pause");
	return 0;
}


