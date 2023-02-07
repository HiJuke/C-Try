#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���

#define pi 3.14

using namespace std;

//----------------------------------------------------------------
//�B��ŭ���
//�[���B��ŭ���
class Person1 {
public:
	//������ƥ[���B��ŭ���	���謰 Person p3 = p1.operator+(p2);
	/*
	Person1 operator+(Person1& p) {
		Person1 temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}
	*/
	int m_A;
	int m_B;
};
//������ƥ[���B��ŭ��� ���謰 Person p3 = operator+(p1, p2);
Person1 operator+(Person1& p1, Person1& p2) {
	Person1 temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
void test01() {
	Person1 P1;
	P1.m_A = 20;
	P1.m_B = 20;
	Person1 P2;
	P2.m_A = 20;
	P2.m_B = 20;

	Person1 P3 = P1 + P2;	
	cout << P3.m_A << "\t" << P3.m_B << endl;
}
//�B��ŭ����]�i�o�ͨ�ƭ���
Person1 operator+(Person1& p1, int num) {
	Person1 temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}

//----------------------------------------------------------------
//�����B��ŭ���
class Person2 {
	friend ostream& operator<<(ostream& cout, Person2& p);
public:
	Person2(int a, int b) {
		m_A = a;
		m_B = b;
	}
private:
	//�Q�Φ�����ƭ��� �����B���
	//���� ���|�Q�Φ�����ƹ�{ �����B��� �]���L�k��{cout �b����
	int m_A;
	int m_B;
};
//������ƭ��������B���
ostream & operator<<(ostream&out, Person2 &p) {	//operator<<(cout, p) ²�Ƭ� cout << p
	cout << p.m_A << "\t" << p.m_B << endl;
	return out;		//�^��cout���F��{�즡�s�� ���M�u��cout << p ; ���� cout << p << endl; ������
}
void test02() {
	Person2 P1(22, 32);
	cout << P1 << endl;
}

//----------------------------------------------------------------
//���W�B��ŭ���
class MyInteger {
	friend ostream& operator<<(ostream& out, MyInteger p);
public:
	MyInteger() {
		m_Num = 0;
	}
	//�e�m++����
	MyInteger& operator++() {	//�����H�ޥΪ�^this ���F��@�Ӽƾڤ@�����W
		m_Num++;
		return *this;
	}

	//��m++����
	MyInteger operator++(int) {		//int�N�����Ѽ� �Ω�Ϥ��e�m��m �{�b�O��m�F �����H�ƭȪ�^
		MyInteger temp= *this;		//�� �O����ɵ��G
		m_Num++;					//�� ���W
		return temp;				//�̫�N�������G��^				
	}

	//�e�m--����
	MyInteger& operator--() {	//�����H�ޥΪ�^this ���F��@�Ӽƾڤ@��--
		m_Num--;
		return *this;
	}

	//��m--����
	MyInteger operator--(int) {		//int�N�����Ѽ� �Ω�Ϥ��e�m��m �{�b�O��m�F �����H�ƭȪ�^
		MyInteger temp = *this;		//�� �O����ɵ��G
		m_Num--;					//�� --
		return temp;				//�̫�N�������G��^				
	}


private:
	int m_Num;
};
//���d�w��������
ostream& operator<<(ostream& out, MyInteger p) {	//operator<<(cout, p) ²�Ƭ� cout << p
	cout << p.m_Num;
	return out;		//�^��cout���F��{�즡�s�� ���M�u��cout << p ; ���� cout << p << endl; ������
}
void test03() {
	MyInteger mying;
	cout << ++(++mying) << endl;
	cout << mying << endl;
	cout << mying++ << endl;
	cout << mying << endl;
	cout << --(--mying) << endl;
	cout << mying << endl;
	cout << mying-- << endl;
	cout << mying << endl;
}

//----------------------------------------------------------------
//��ȹB��ŭ���
//�sĶ���������|�Ө�� �c�y�B�R�c�B�����B��ȹB��� operator = 
class Person3 {
public:
	Person3(int a) {
		m_Age = new int(a);	//�Ыئb���
	}
	~Person3() {		//�N�Ŷ��Ѱ�Ϥ�����
		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL;
		}
	}

	//���� ��ȹB���
	Person3& operator= (Person3& p) {
		//���ӥ��P�_�O�_���ݩʦb��� �����ܥ����񰮲b �A�`����
		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);	//�`����
		return *this;
	}

	int* m_Age;
};
void test04() {
	Person3 p1(18);
	Person3 p2(28);
	Person3 p3(68);
	p2 = p1;	//�t�ιw�]����Ⱦާ@�ɭP�P�@��ϳQ�������� �|crash �ҥH�n�ۤv�g�@��
	cout << "p1 =" << *p1.m_Age << endl;
	cout << "p2 =" << *p2.m_Age << endl;

	p3 = p2 = p1;
	cout << "p1 =" << *p1.m_Age << endl;
	cout << "p2 =" << *p2.m_Age << endl;
	cout << "p3 =" << *p2.m_Age << endl;
}

//----------------------------------------------------------------
//���Y�B��ŭ���
class Person4 {
public:
	Person4(int a, string name) {
		m_Name = name;
		m_Age = a;
	}
	~Person4() {	

	}

	//���� ��ȹB���
	bool operator== (Person4& p) {
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
			return true;
		}
		return false;
	}

	bool operator!= (Person4& p) {
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
			return false;
		}
		return true;
	}

	string m_Name;
	int m_Age;
};
void test05() {
	Person4 p1(22, "Peter");
	Person4 p2(22, "Peter");
	Person4 p3(32, "Eilly");
	if (p1 == p2) {
		cout << "Same" << endl;
	}
	if (p1 != p3) {
		cout << "Different" << endl;
	}
}

//----------------------------------------------------------------
//�t�ƽեιB��ŭ���
//���ƫ��F���S���T�w�g�k
class MyPrint {
public:
	void operator()(string text) {
		cout << text << endl;
	}
};
class MyAdd {
public:
	int operator()(int a,int b) {
		return a+b;
	}
};
void test06() {
	//������()�ާ@�Ť]�٬�����
	MyPrint myFunc;
	myFunc("Welcome");
	MyAdd myAd;
	cout << myAd(6, 9) << endl;
	//�ΦW��ƹ�H	�g�k: ���W()(�ǤJ��) --- ���W + �p�A�� + ��J��
	cout << MyAdd()(8, 7) << endl;
}







int main() {
	srand((unsigned int)time(NULL));
	//�[���B��ŭ���
	//test01();
	//�����B��ŭ���
	//test02();
	//���W�B��ŭ���
	//test03();
	//��ȹB��ŭ���
	//test04();
	//���Y�B��ŭ���
	//test05();
	//�t�ƽեιB��ŭ���
	//test06();

	system("pause");
	return 0;
}
