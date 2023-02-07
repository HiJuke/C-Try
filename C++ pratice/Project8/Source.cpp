#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���

#define pi 3.14

using namespace std;

//C++��H�ҫ� & this���w

//�����������ܶq�M������Ƥ��}�s�x
//*�u���D�R�A�����ܶq�~��O��������
class Person1 {};
void test01() {
	Person1 P;
	//�Ź�H�e�Ϊ����s�Ŷ� = 1 , �]��C++�sĶ���|���Ź�H�]���t�@�r�`���Ŷ� , �O���F�Ϥ��Ź�H�����s����m
	//�C�ӪŹ�H�]�����W�@�L�G�����s�a�}
	cout << "Size of Person = " << sizeof(P) << endl;
}

class Person2 {
	int m_A;		//�D�R�A�����ܶq
	static int m_B;	//�R�A�����ܶq
	void func(){}	//�D�R�A�������
};
void test02() {
	Person2 P;	//m_A�ݩ������������ܶq �|�v�T�����Ŷ��j�p �{�b���ܬ� 4 �F
	//m_B �٦� func ���O�ݩ��R�A�����ܶq �M �D�R�A������� �P�����������}�s�x ���v�Tsizeof(P)
	cout << "Size of Person = " << sizeof(P) << endl;
}
//----------------------------------------------
//this���w	�����w�q �����ϥ�
//*��ΰѩM�����ܶq�P�W�� �i��this���w�Ϥ� �ѨM�W�ٽĬ�
//*�������D�R�A������Ƥ���^��H���� �i�ϥ� return *this
class Person3 {
public:	
	Person3(int age) {
		//age = age;	//age�]�����W �S��this�|�ɭP�c�y��ƪ�age�ҫD�����ŧi�� ���ծɫK�X�{�ýX
		this->age = age;	//�Q��this���w��age���������ŧi��age �ѨM�W�ٽĬ�
	}

	Person3& PersonAddAge(Person3 &p) {
		this->age += p.age;
		return *this;	//this���V�������� �N�i����test04�����Ӿާ@ �����^�Ǭ�Person3&�ޥΤ~�|�O���� �^�Ǭ�Person3�N���|�O����
	}

	int age;
};
void test03() {
	Person3 P1(22);
	cout << P1.age << endl;
}
void test04() {
	Person3 P1(2);
	Person3 P2(23);
	P2.PersonAddAge(P1);
	cout << P2.age << endl;
	P2.PersonAddAge(P1).PersonAddAge(P1).PersonAddAge(P1).PersonAddAge(P1);
	cout << P2.age << endl;
}
//----------------------------------------------
//�ū��w�X�ݦ������
//*�ū��w�]�i�եΦ������ ���n�`�N���L this���w�ϥ�
class Person4 {
public:
	void showClassName() {
		cout << "Person class" << endl;
	}
	void showPersonAge() {
		if (this == NULL) { return; }	//�S�[�J����K�i��b�ū��w���p�U�X�� ����i��������������
		cout << "Age =" << m_Age << endl;	
	}
	int m_Age;
};
void test05(){
	Person4* p = NULL;
	p->showClassName();
	p->showPersonAge();	//�ū��w�ե������ƭȷ|�ɭP�X�� �]���ū��w�S������ƾ�
}

//----------------------------------------------
//const�׹��������
/*
�`���:
* ������ƫ�[const �٬��`���
* �`��Ƥ����i�ק令���ݩ�
* �����ݩ��n���ɥ[����r mutable ��  �b�`��Ƥ��̵M�i�H�ק�

�`��H
* �n����H�e�[const �٬��`��H
* ����H�u��եα`���
*/
//�`���
class Person5{
public:
	//this���w������ �O���w�`�q ���w�����V���i�H�ק諸
	//������ƫ᭱�[const �����Othis���V �����w���V���ƭȤ]���i�H�ק�
	void showPerson() { m_A = 100;}	//�i�ק�ƾ�
	void showPP() const { 
		//this->m_A = 100;	//�[�Jconst���i�ק�ƭ� this���w���i�ק���w���V��
		this->m_B = 200;	//�ŧi�ƭȮɮa�Jmutable �Y�i�ק�
	}	
	void func(){}

	int m_A;
	mutable int m_B;	//�]�p�@�Ӧb�`��Ƥ��]�i�H�ק諸 �S���ܶq
};
void test06() {
	Person5 p;
	p.showPP();
}
void test07() {
	const Person5 p;	//�ܬ��`��H
	//p.m_A = 166;		//����`��H���i��ƾڪ��W�h �|���~
	p.m_B = 299;		//�ŧi�ƭȮɦ�mutable �i�ק�

	//�`��H���i�եδ��q��� �]�����q��ƥi�ק�ƭ�
	p.showPP();			
	//p.func();		//�|�X��	
}
//----------------------------------------------
//�ͤ�	����rfriend
//���Ǩp���ݩʷQ���\�~�S���Ʃ����i��X�� ���@�Ө�Ʃ����X�ݥt�@�������p������

//������ư��ͤ�
class Building1 {
	//�w�qgoodGuy��Ƭ������O���ͤ� �i�H�X�ݨp������
	friend void goodGuy(Building1* build);
public:
	Building1() {
		m_SittingRoom = "���U";
		m_BedRoom = "�׫�";
	}
	string m_SittingRoom;
private:
	string m_BedRoom;
};
void goodGuy(Building1* build) {
	cout << "���b�X��: " << build->m_SittingRoom << endl;
	cout << "���b�X��: " << build->m_BedRoom << endl;	//�]���O�ͤ� �ҥH�i�X�ݨp������

}
void test08() {
	Building1 building;
	goodGuy(&building);
}

//�����ͤ�
class Building2 {
	//�w�qGoodGuy2���������O���ͤ� �i�H�X�ݨp������
	friend class GoodGuy2;
public:
	Building2() {
		m_SittingRoom = "���U";
		m_BedRoom = "�׫�";
	}
	string m_SittingRoom;
private:
	string m_BedRoom;
};
class GoodGuy2 {
public:
	GoodGuy2() {
		//�Ыثؿv����H
		building = new Building2;
	}

	void visit() {	//���[��ƳX�� building2�����ݩ�
		cout << "���b�X��: " << building->m_SittingRoom << endl;
		cout << "���b�X��: " << building->m_BedRoom << endl;	//�]���O�ͤ��� �ҥH�i�X�ݨp������
	}

	Building2* building;
};
void test09() {
	GoodGuy2 gg;
	gg.visit();
}

//������ư��ͤ�
class Building3;	//�������w�q GoodGuy3�~�i�H�ϥ�
class GoodGuy3 {	//�����w�q��Building3�����ͤ����e ���MBuilding3�u�|��쥼�w�q��GoodGuy3
public:
	GoodGuy3();

	void visit1();

	void visit2();

	Building3* building;	//�ݵ���building3�����w�q �ҥH��Ϋ���
};	 
class Building3 {
	//�w�qGoodGuy3 visit1 ��Ƭ������O���ͤ� �i�H�X�ݨp������
	friend void GoodGuy3::visit1();
public:
	Building3();
	string m_SittingRoom;
private:
	string m_BedRoom;
};
Building3::Building3() {
	m_SittingRoom = "���U";
	m_BedRoom = "�׫�";
}
//�H�U�ݽե�Building3�� �ݩw�q��Building3����w�q��
GoodGuy3::GoodGuy3() {
	//�Ыثؿv����H
	building = new Building3;
}
void GoodGuy3::visit1() {	//�i�X��Building3�p������
	cout << "V1���b�X��: " << building->m_SittingRoom << endl;
	cout << "V1���b�X��: " << building->m_BedRoom << endl;	//�]���O�ͤ�������� �ҥH�i�X�ݨp������
}
void GoodGuy3::visit2() {	//���i�X��Building3�p������
	cout << "V2���b�X��: " << building->m_SittingRoom << endl;
	//cout << "V2���b�X��: " << building->m_BedRoom << endl;	//�]�����O�ͤ�������� �ҥH���i�X�ݨp������
}
void test10() {
	GoodGuy3 gg;
	gg.visit1();
	gg.visit2();
}




int main() {
	srand((unsigned int)time(NULL));

	//�����������ܶq�M������Ƥ��}�s�x
	//test01();
	//test02();
	//----------------------------------------------
	//this���w
	//test03();
	//test04();
	//----------------------------------------------
	//�ū��w�X�ݦ������
	//test05();
	//----------------------------------------------
	//const�׹��������
	//test06();
	//test07();
	//----------------------------------------------
	//�ͤ�
	//test08();
	//test09();
	//test10();

	system("pause");
	return 0;
}
