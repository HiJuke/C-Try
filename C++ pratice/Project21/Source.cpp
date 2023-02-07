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

using namespace std;

class Person {
public:
	Person(string name, int age, int height) {
		this->m_name = name;
		this->m_age = age;
		this->m_Height = height;
	}
	string m_name;
	int m_age;
	int m_Height;
};
//----------------------------------------------------------------

//list �e��			include <list>
//�N�O��� ��C�O�o�� 
//�u�I: �i�H����N��m�ֳt���J�ΧR������
//���I: �M�������t�׺C��Ʋ�  ���ΪŶ��]���j (�ݭn�h�@�ժŶ��x�s�U�@�Ӥ�������m ���Ƿ|�ݭn��ժŶ� �e���Ӥ�����m���s)
//list �u��� ++ �P -- �����+1+2���H���X�� �n�N�ۤv�g����
void printList(const list<int>&L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}

//----------------------------------------------------------------
//�c�y���
/*
list<T> list;			//list�ĥμҪO����{ ��H���q�{�c�y�Φ�
list(beg, end);			//�c�y��ƱN(beg, end)�϶�����������������
list(n, elem);			//�c�y��ƱNn �� elem ����������
list(const list &list);	//�����c�y���
*/
void test01() {
	list<int>L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	list<int>L2(L1.begin(), L1.end());
	printList(L2);

	list<int>L3(L2);
	printList(L3);

	list<int>L4(5, 22);
	printList(L4);
}

//----------------------------------------------------------------
//��ȻP�洫
/*
assign(beg, end);					//�N(beg, end)�϶�����������������
assign(n, elem);					//�Nn �� elem ����������
list& operator(const list &list);	//���������ާ@��
swap(lst);							//�Nlst�P������������
*/
void test02() {
	list<int>L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	list<int>L2;
	L2 = L1;
	printList(L2);

	list<int>L3;
	L3.assign(L1.begin(), L1.end());
	printList(L3);

	list<int>L4;
	L4.assign(5, 200);
	printList(L4);

	//---------------------------------

	list<int>L5;
	L5.push_back(11);
	L5.push_back(22);
	L5.push_back(33);
	L5.push_back(44);
	L5.push_back(55);
	
	cout << "�洫�e:" << endl;
	printList(L1);
	printList(L5);

	cout << "�洫��: " << endl;
	L1.swap(L5);
	printList(L1);
	printList(L5);
}

//----------------------------------------------------------------
//�j�p�ާ@
/*
empty();				�P�_�e���O�_����
size();					��^�e���������Ӽ�
resize(num);		-���s���w�e�����׬�num �Y�e���ܦ��h�H �q�{�� 0 ��R�s��m
					-�Y�e���ܵu �����W�X���ת������Q�R��
resize(num, elem);	-���s���w�e�����׬�num �Y�e���ܦ��h�H   elem   ��R�s��m
					-�Y�e���ܵu �����W�X���ת������Q�R��
*/
void test03() {
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	if (L1.empty()) {		//���u �N��e������
		cout << "L1����" << endl;
	}
	else {
		cout << "L1������" << endl;
		cout << "�j�p��: " << L1.size() << endl;
	}

	//���s���w�j�p
	L1.resize(10);
	printList(L1);

	L1.resize(15, 33);
	printList(L1);

	cout << "�j�p��: " << L1.size() << endl;

}

//----------------------------------------------------------------
//���J�M�R��
/*
push_back(ele);					-�������J����ele
push_front(ele);				-�Y�����J����ele
pop_back();						-�̧��R�������@��
pop_front();					-���Y�R�������@��

insert(pos, ele);				-���N�����V��mpos ���J���� ele					��^�s������m
insert(pos, int count, ele);	-���N�����V��mpos ���J���� ele ���Jcount ��	�S����^��
insert(pos, start, end);		-���N�����V��mpos ���Jstart �� end ����������	�S����^��
erase(pos);						-�R�����N�����V������					��^�U�@�Ӽƾڪ���m
erase(start, end);				-�R�����N�� start �� end ����������		��^�U�@�Ӽƾڪ���m
clear();						-�R���e�����Ҧ�����
remove(elem);					-�R���e�����Ҧ��Pelem�ǰt������
*/
void test04() {
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	L1.push_front(10);
	L1.push_front(20);
	L1.push_front(30);
	L1.push_front(40);
	printList(L1);
	cout << "-----------------------------------------------------------------------" << endl;

	L1.pop_back();
	L1.pop_front();
	printList(L1);
	cout << "-----------------------------------------------------------------------" << endl;

	L1.insert(L1.begin(), 40);
	L1.insert(L1.end(), 3, 99);
	printList(L1);
	cout << "-----------------------------------------------------------------------" << endl;

	list<int>L2;
	L2.push_back(99);
	L2.push_back(99);
	L1.insert(++L1.begin(), L2.begin(), L2.end());
	printList(L1);
	cout << "-----------------------------------------------------------------------" << endl;

	L1.erase(++(++(++L1.begin())));
	printList(L1);
	L1.erase(++(++(++L1.begin())), --(--(--L1.end())));
	printList(L1);
	cout << "-----------------------------------------------------------------------" << endl;

	L1.remove(99);
	printList(L1);
	L1.clear();
	printList(L1);
	cout << "-----------------------------------------------------------------------" << endl;
}

//----------------------------------------------------------------
//�ƾڦs��
/*
front();	//�^�ǲĤ@�Ӥ���
back();		//�^�ǳ̫�@�Ӥ���
*/
void test05() {
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	cout << L1.front() << endl;
	cout << L1.back() << endl;

}
//----------------------------------------------------------------
//����M�Ƨ�
/*
reverse();	//����C��
sort();		//���Ƨ�
*/
bool DoneSort(int A, int B) {
	return A > B;
}

void test06() {
	list<int>L1;
	L1.push_back(rand()%100+1);
	L1.push_back(rand() % 100 + 1);
	L1.push_back(rand() % 100 + 1);
	L1.push_back(rand() % 100 + 1);
	L1.push_back(rand() % 100 + 1);
	printList(L1);

	//sort(L1.bagin(), L1.end());	������H���X�ݪ��e�� �L�k�ϥμзǺ�k
	//������H���X�ݭ��N�����e�� �����|���ѹ�����������k
	L1.sort();	//�ɧ�
	printList(L1);

	L1.sort(DoneSort);	//����
	printList(L1);

	L1.reverse();	//����
	printList(L1);
}

//----------------------------------------------------------------
//�ƧǮר�

//���w�ƧǳW�h
bool SortPerson(Person& PA, Person& PB) {
	//���Ӧ~�� �ɧ�
	//return PA.m_age < PB.m_age;

	if (PA.m_age == PB.m_age) {
		return PA.m_Height > PB.m_Height;
	}
	else {
		return PA.m_age < PB.m_age;
	}
}

void test07() {
	list<Person> LP;

	Person P1("HumanA", 35, 168);
	Person P2("HumanB", 45, 175);
	Person P3("HumanC", 45, 181);
	Person P4("HumanD", 76, 192);
	Person P5("HumanE", 45, 165);

	LP.push_back(P1);
	LP.push_back(P2);
	LP.push_back(P3);
	LP.push_back(P4);
	LP.push_back(P5);

	cout << "�̦~�ֱƧ� �~�֬ۦP�̨��� �Ƨǫe: " << endl;
	for (list<Person>::iterator it = LP.begin(); it != LP.end(); it++) {
		cout << "�m�W: " << it->m_name << "\t�~��: " << it->m_age << "\t����: " << it->m_Height << endl;
	}

	cout << "-----------------------------------------------------------------------" << endl;
	LP.sort(SortPerson);
	cout << "�̦~�ֱƧǫ� �~�֬ۦP�̨��� �Ƨǫe: " << endl;
	for (list<Person>::iterator it = LP.begin(); it != LP.end(); it++) {
		cout << "�m�W: " << it->m_name << "\t�~��: " << it->m_age << "\t����: " << it->m_Height << endl;
	}

}
//----------------------------------------------------------------








int main() {
	//���U�@�U�����|�Ψ쪺�H����
	srand((unsigned int)time(NULL));

	//�c�y���
	//test01();

	//��ȻP�洫
	//test02();

	//�j�p�ާ@
	//test03();
	
	//���J�M�R��
	//test04();
	
	//�ƾڦs��
	//test05();
	
	//����M�Ƨ�
	//test06();

	//�ƧǮר�
	test07();
	




	system("pause");
	return 0;
}
