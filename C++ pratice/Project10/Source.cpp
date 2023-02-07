#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���

#define pi 3.14

using namespace std;

//�~��
//�l���O�~�ӤF�W�@�N���S�� �P���٦��ۤv���S��
//�i��֭��ƥN�X
//�y�k clase �l�� : �~�Ӥ覡 ����
//�l�� �]�٬� ������
//���� �]�٬� ����

//----------------------------------------------------------------
//�L�~��
/*
//Java ����
class Java {
public:
	void header() {
		cout << "�����B�ҵ{�B���U...(�Y��)" << endl;
	}
	void footer() {
		cout << "���U�B��y�B�a��...(����)" << endl;
	}
	void left() {
		cout << "Java�BPythin�BC++...(����)" << endl;
	}
	void contant() {
		cout << "Java Video Page." << endl;
	}
};
//Python ����
class Python {
public:
	void header() {
		cout << "�����B�ҵ{�B���U...(�Y��)" << endl;
	}
	void footer() {
		cout << "���U�B��y�B�a��...(����)" << endl;
	}
	void left() {
		cout << "Java�BPythin�BC++...(����)" << endl;
	}
	void contant() {
		cout << "Python Video Page." << endl;
	}
};
//C++ ����
class CPlus {
public:
	void header() {
		cout << "�����B�ҵ{�B���U...(�Y��)" << endl;
	}
	void footer() {
		cout << "���U�B��y�B�a��...(����)" << endl;
	}
	void left() {
		cout << "Java�BPythin�BC++...(����)" << endl;
	}
	void contant() {
		cout << "C++ Video Page." << endl;
	}
};
*/
//���~��
//���@������
class BasePage {
public:
	void header() {
		cout << "�����B�ҵ{�B���U...(�Y��)" << endl;
	}
	void footer() {
		cout << "���U�B��y�B�a��...(����)" << endl;
	}
	void left() {
		cout << "Java�BPythin�BC++...(����)" << endl;
	}
};
//Java ����
class Java : public BasePage{
public:
	void contant() {
		cout << "Java Video Page." << endl;
	}
};
//Python ����
class Python : public BasePage {
public:
	void contant() {
		cout << "Python Video Page." << endl;
	}
};
//C++ ����
class CPlus : public BasePage {
public:
	void contant() {
		cout << "C++ Video Page." << endl;
	}
};
void testJa() {
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.contant();
}
void testPh() {
	Python Ph;
	Ph.header();
	Ph.footer();
	Ph.left();
	Ph.contant();
}
void testCp() {
	CPlus cp;
	cp.header();
	cp.footer();
	cp.left();
	cp.contant();
}

//----------------------------------------------------------------
//�~�Ӥ覡: ���� �O�@ �p��
/*
*�����O��private �l���O���w�L�k�~�ӳX��
����: �����O�� public protected ��l���O����
�O�@: �����O�� public protected ��l���O�ܬ�protected  ���O
�p��: �����O�� public protected ��l���O�ܬ�private  ���O
*/
class Base1 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
//���@�~��
class Son1 : public Base1 {
public:
	void func() {
		m_A = 10;	//������public		�̵M�O�l����public		�i�ѥ��N�̳X��
		m_B = 10;	//������protected	�̵M�O�l����protected	�i��������ƳX��
		//m_C = 10;	//������pritave		�T��l�����N�Φ��X��	���i�X�ݩҥH�|����
	}
};
void test01() {
	Son1 s1;
	s1.m_A = 100;	//������public		�̵M�O�l����public		�i�ѥ��N�̳X��
	//s1.m_B = 100;	//������protected	�̵M�O�l����protected	�u�i��������ƳX��	���~���\�X��
}
//�O�@�~�� (protected)
class Son2 : protected Base1 {
public:
	void func() {
		m_A = 100;	//������public		���ɬ��l����protected	�i��������ƳX��
		m_B = 100;	//������protected	�̵M�O�l����protected	�i��������ƳX��
		//m_C = 10;	//������pritave		�T��l�����N�Φ��X��	���i�X�ݩҥH�|����
	}
};
void test02() {
	Son2 s1;
	//s1.m_A = 100;	//������public		���ɬ��l����protected	�u�i��������ƳX��	���~���\�X��
	//s1.m_B = 100;	//������protected	�̵M�O�l����protected	�u�i��������ƳX��	���~���\�X��
}
//�p���~�� (pritave)
class Son3 : private Base1 {
public:
	void func() {
		m_A = 1000;	//������public		���ɬ��l����pritave		�i��������ƳX��
		m_B = 1000;	//������protected	�̵M�O�l����pritave		�i��������ƳX��
		//m_C = 10;	//������pritave		�T��l�����N�Φ��X��	���i�X�ݩҥH�|����
	}
};
void test03() {
	Son3 s1;
	//s1.m_A = 100;	//������public		���ɬ��l����pritave		�u�i��������ƳX��	���~���\�X��
	//s1.m_B = 100;	//������protected	�̵M�O�l����pritave		�u�i��������ƳX��	���~���\�X��
}

//���� �A���~�� �]�l�X�{�F
class GrandSon3 : public Son3 {
public:
	void func() {
		//�Ӽƾڦb�����q�����~�Ӯ�		�w�ܦ�������pritave		�T��l�����N�Φ��X��	���i�X�ݩҥH�|����
		//m_A = 10000;
		//m_B = 10000;
	}
};

//----------------------------------------------------------------
//�~�Ӥ�����H�ҫ�
class Base2 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;	//�p�������u�O�Q���� �٬O�|�~�ӤU�h��
};
class Son4 : public Base2 {
public:
	int m_D;
};
void test04() {
	Son4 s1;
	//�������Ҧ��D�R�A�������|�Q�l���~�ӤU�h �p�������O�Q�sĶ�����äF
	cout << sizeof(Son4) << endl;	//���׬�16	�O�|��int���j�p m_A ~ m_D 
}

//----------------------------------------------------------------
//�~�Ӥ��c�y�M�R�c����
class Base3 {
public:
	Base3() {
		cout << "���c�y**" << endl;
	}
	~Base3() {
		cout << "���R�c**" << endl;
	}
};
class Son5 : public Base3 {
public:
	Son5() {
		cout << "�l�c�y--" << endl;
	}
	~Son5() {
		cout << "�l�R�c--" << endl;
	}
};
void test05() {
	Son5 s1;	//������ �A���l �l���� ������
}

//----------------------------------------------------------------
//�P�W�����B�z
//* �X�ݤl���P�W���� �����X�ݧY�i
//* �X�ݤ����P�W���� �Х[�J�@�ΰ�
class Base4 {
public:
	Base4() {
		m_A = 200;
	}
	void func() {
		cout << "�����O��ƽե�**" << endl;
	}
	void func(int a) {
			m_A = a;
	}
	int m_A;
};
class Son6 : public Base4 {
public:
	Son6() {
		m_A = 400;
	}
	void func() {
		cout << "�l���O��ƽե�--" << endl;
	}
	void func(int a) {
		m_A = a;
	}
	int m_A;
};
void test06() {
	Son6 s1;
	cout << s1.m_A << endl;			//�����եΦP�W �|�եΤl���O
	s1.func();						//�����եΦP�W �|�եΤl���O
	cout << s1.Base4::m_A << endl;	//�X�ݤ����P�W���� �Х[�J�@�ΰ�
	s1.Base4::func();				//�X�ݤ����P�W���� �Х[�J�@�ΰ�
	s1.func(333);
	s1.Base4::func(222);
	cout << s1.m_A << endl;			//�եΪ��l���P�W �����ק�P�W�ƾ� �u�|�ק�ۨ�
	cout << s1.Base4::m_A << endl;	//�եΪ������P�W �����ק�P�W�ƾ� �u�|�ק�ۨ�
}

//----------------------------------------------------------------
//�P�W�R�A�����B�z
class Base5 {
public:
	static void func() {
		cout << "�����O�R�A��ƽե�**" << endl;
	}
	static void func(int a) {
		cout << "�����O�R�A��� two �ե�**" << endl;
		//m_A = a;
	}
	static int m_A;
};
int Base5::m_A = 200;
class Son7 : public Base5 {
public:
	static void func() {
		cout << "�l���O�R�A��ƽե�--" << endl;
	}
	static void func(int a) {
		cout << "�l���O�R�A��� two �ե�**" << endl;
		//m_A = a;
	}
	static int m_A;
};
int Son7::m_A = 400;
void test07() {
	//1. �q�L��H�X��
	Son7 s1;
	cout << s1.m_A << endl;			//�����եΦP�W �|�եΤl���O
	s1.func();						//�����եΦP�W �|�եΤl���O
	cout << s1.Base5::m_A << endl;	//�X�ݤ����P�W���� �Х[�J�@�ΰ�
	s1.Base5::func();				//�X�ݤ����P�W���� �Х[�J�@�ΰ�
	cout << "------------------------------------------------" << endl;
	//2. �q�L���W�X��
	cout << Son7::m_A << endl;
	Son7::func();
	cout << Son7::Base5::m_A << endl;	//�Ĥ@��:�N��q�L�l�����W�覡�X��
	Son7::Base5::func();				//�ĤG��:�N��q�L�l���~�Ӫ������@�ΰ�X��
	//�q�L���W���Ϋŧi Son7 s1;
}

//----------------------------------------------------------------
//�h�~�ӻy�k	(�}�o�ɤ���ĳ)
class Base6 {
public:
	Base6() {
		m_A = 222;
	}
	int m_A;
};
class Base7 {
public:
	Base7() {
		m_A = 333;
	}
	int m_A;
};
//�l���~�Ө�Ӥ���
class Son8 : public Base6, public Base7 {
public:
	Son8() {
		m_C = 300;
		m_D = 400;
	}
	int m_C;
	int m_D;
};
void test08() {
	Son8 s;
	cout << sizeof(s) << endl;	//��Ӥ��U�@int + �ۤv���int = 4, 4��int�N�O16���j�p
	//���Ӥ����O�����W���ɭ� �n�ϥαo�a�@�ΰ�Ϥ�
	cout << "B6A: " << s.Base6::m_A << endl;
	cout << "B7A: " << s.Base7::m_A << endl;

}

//----------------------------------------------------------------
//�٧ΰ��D�H�θѨM��k	(�]���O�h�~�� �ҥH�J��o���D�����N���O�ܦn)
/*
�٧��~�� A��BC��̪����� BC�S�P�ɬ�D������
		     +---(B��)---+
	(A��)----|           |----(D�])
		     +---(C��)---+
*/
//�ʪ���
class Anima1 {
public:
	int m_Age;
};
//���~�� �ѨM�٧��~�Ӱ��D
//�~�ӫe�[�W virtual����r	����Animal�٬������  
//��
class Sheep :virtual public Anima1{};
//�m
class Tuo :virtual public Anima1{};
//�Ͼm
class SheepTuo : public Sheep, public Tuo{};
void test09() {
	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 20;
	cout << st.Sheep::m_Age <<"\t"<< st.Tuo::m_Age << "\t" << st.m_Age << endl;	//��٧��~�� ��Ӥ������ۦP�ƾ� �ݭn�[�H�@�ΰ�Ϥ� ���ۤv���O??? �Ͼm�쩳�O�X��
	//�o���ƾڥu�n���@���N�i�H�F ���٧��~�ӾɭP�ƾڦ���� �귽���O
	//�ѨM�覡 ���~�� �Ц^370��
	//���~�ӫ� ��̪�m_Age �i�����@�� ��X�����m_Age���ܦ�20�F
}




int main() {
	srand((unsigned int)time(NULL));

	//���@������
	//testJa();
	//testPh();
	//testCp();

	//�~�Ӥ覡: ���� �O�@ �p��
	//test01();
	//test02();
	//test03();

	//�~�Ӥ�����H�ҫ�
	//test04();

	//�~�Ӥ��c�y�M�R�c����
	//test05();

	//�P�W�����B�z
	//test06();

	//�P�W�R�A�����B�z
	//test07();

	//�h�~�ӻy�k
	//test08();

	//�٧ΰ��D�H�θѨM��k
	//test09();


	system("pause");
	return 0;
}
