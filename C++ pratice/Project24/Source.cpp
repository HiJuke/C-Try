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

//�ר� ���u����
//�y�z
/*
-�s���u�Q�W �i�J���q��ݫ������u�b���ӳ����u�@
-���u�H��: �m�W �u��զ�;  ��������: ���e ���N ��o
-�H�����Q�W���u���t�����P�u��
-�q�Lmultimap �i��H�����J key�������и� value�����u
-��������ܭ��u�H��
*/

//�B�J
/*
1. �ЫؤQ�W���u ��Jvector
2. �M��vector�e�� ���X�C�ӭ��u�H������
3. ���ի� �N���u�����s���@��key ���u����value ��Jmultimap�e����
4. ��������ܭ��u�H��
*/

//���u
class employee {
public:
	employee(string name, int price) {
		this->m_name = name;
		this->m_price = price;
	}
	string m_name;
	int m_price;
};

//�ЫؤQ�W���u
void CreateEmployee(vector<employee>& v) {
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++){
		string tName = "Employee";
		tName += nameSeed[i];
		employee E(tName, rand() % 30000 + 25000);
		v.push_back(E);
	}
	/*
	employee E01("Employee A", rand() % 30000 + 25000);
	employee E02("Employee B", rand() % 30000 + 25000);
	employee E03("Employee C", rand() % 30000 + 25000);
	employee E04("Employee D", rand() % 30000 + 25000);
	employee E05("Employee E", rand() % 30000 + 25000);
	employee E06("Employee F", rand() % 30000 + 25000);
	employee E07("Employee G", rand() % 30000 + 25000);
	employee E08("Employee H", rand() % 30000 + 25000);
	employee E09("Employee I", rand() % 30000 + 25000);
	employee E10("Employee J", rand() % 30000 + 25000);

	v.push_back(E01);
	v.push_back(E02);
	v.push_back(E03);
	v.push_back(E04);
	v.push_back(E05);
	v.push_back(E06);
	v.push_back(E07);
	v.push_back(E08);
	v.push_back(E09);
	v.push_back(E10);
	*/
}

//�M��vector
void printEmployee(const vector<employee>& v) {
	for (vector<employee>::const_iterator it = v.begin(); it != v.end(); it++) {
		cout << "�m�W: " << it->m_name << "\t  �~��: " << it->m_price << endl;
	}
	cout << endl;
}

//�N���u����
void setGroup(const vector<employee>& v, multimap<int, employee>& m) {
	for (vector<employee>::const_iterator it = v.begin(); it != v.end(); it++) {
		m.insert(make_pair(rand() % 3 + 1, *it));
	}
}

//�M��multimap
void printMultimap(const multimap<int, employee>& m) {
	//for (multimap<int, employee>::const_iterator it = m.begin(); it != m.end(); it++) {
	//	cout << "�m�W: " << it->second.m_name << "\t  �~��: " << it->second.m_price;
	//
	//�έp�����H�ƥ[�`
	//�T�����H�� �p�e ���N ��o
	cout << "���e�����H��: " << m.count(1) << endl;
	multimap<int, employee>::const_iterator it = m.find(1);
	for (int i = 0; it != m.end() && i < m.count(1); it++, i++) {
		cout << "�m�W: " << it->second.m_name << "\t  �~��: " << it->second.m_price << endl;
	}
	cout << endl;

	cout << "���N�����H��: " << m.count(2) << endl;
	it = m.find(2);
	for (int i = 0; it != m.end() && i < m.count(2); it++, i++) {
		cout << "�m�W: " << it->second.m_name << "\t  �~��: " << it->second.m_price << endl;
	}
	cout << endl;

	cout << "��o�����H��: " << m.count(3) << endl;
	it = m.find(3);
	for (int i = 0; it != m.end() && i < m.count(3); it++, i++) {
		cout << "�m�W: " << it->second.m_name << "\t  �~��: " << it->second.m_price << endl;
	}
	cout << endl;
}

void CompanySystem() {
	//�إ�vector
	vector<employee> v;
	//�ЫؤQ�W���u
	CreateEmployee(v);
	printEmployee(v);

	//�N���u���� �����s���@��key ���u����value ��Jmultimap�e����
	multimap<int, employee> m;
	setGroup(v, m);
	
	//�M��multimap ��������ܭ��u
	printMultimap(m);
}

int main() {
	//���U�@�U�����|�Ψ쪺�H����
	srand((unsigned int)time(NULL));

	CompanySystem();


	system("pause");
	return 0;
}

