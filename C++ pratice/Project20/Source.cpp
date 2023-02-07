#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include <fstream>	//	���ާ@�t���Y���
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

//Stack  (FILO ���i��X)	�O�o#include <stack>
/*
�c�y���:
	stack<T> stk;				//stack�ĥμҪO����{ stack��H���q�{�c�y�Φ�
	stack(const stack &stk);	//�����c�y���
��Ⱦާ@:
	stack& operator = (const stack & stk);	//���������ާ@��
�ƾڦs��:
	push(elem);		//�V�̳��K�[����
	pop();			//�q�̳������Ĥ@�Ӥ���
	top();			//��^�̳�����
�j�p�ާ@:
	empty();		//�O�_����
	size();			//�j�p
*/

void testStack() {

	stack<int>s;

	//�J��
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	cout << "�̤j�p: " << s.size() << endl;

	//�]�w�@�^�� �u�n�̳������� �d�ݴ̳� �åX��
	while (!s.empty()) {	//�O�_����
		cout << "�̳�����: " << s.top() << endl;
		s.pop();	//�X��
	}

	cout << "�̤j�p: " << s.size() << endl;
}

//----------------------------------------------------------------

//Queue  (FIFO ���i���X)	�O�o#include <queue>  �N�O�ƶ���
/*
�c�y���:
	queue<T> que;				//queue�ĥμҪO����{ queue��H���q�{�c�y�Φ�
	queue(const queue &que);	//�����c�y���
��Ⱦާ@:
	queue& operator = (const queue &que);	//���������ާ@��
�ƾڦs��:
	push(elem);		//�V�����K�[����
	pop();			//�q���������Ĥ@�Ӥ���
	back();			//��^�̫�@�Ӥ���
	front();		//��^�̥��@�Ӥ���
�j�p�ާ@:
	empty();		//�O�_����
	size();			//�j�p
*/

class Person {
public:
	Person(string name, int age) {
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};

void testQueue() {
	queue<Person> q;

	Person p1("Member A", 23);
	Person p2("Member B", 44);
	Person p3("Member C", 62);
	Person p4("Member D", 35);

	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	
	cout << "���C�j�p: " << q.size() << endl;

	while (!q.empty()) {	//�O�_����
		cout << "�����: " << q.front().m_name << "\t�~��: " << q.front().m_age << endl;
		cout << "�����: " << q.back().m_name << "\t�~��: " << q.back().m_age << endl;
		q.pop();	//��������
		cout << "---�����{�Ǥw����---" << endl;
	}

	cout << "���C�j�p: " << q.size() << endl;
}

int main() {
	//���U�@�U�����|�Ψ쪺�H����
	srand((unsigned int)time(NULL));

	testStack();

	cout << "---------------------------------------------------------------------" << endl;

	testQueue();

	system("pause");
	return 0;
}
