#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���

#define pi 3.14

using namespace std;

//�h�A (�ʸ� �~�� �h�A �������T�j�S��)
/*
�h�A����
* �R�A�h�A: ��ƭ��� �M �B��ŭ��� (��ƦW���W)
* �ʺA�h�A: �������M���ƹ�{�B��ɦh�A

�ϧO
* �R�A�h�A��Ʀa�}���j�w - �sĶ���q�T�w��Ʀa�}
* �ʺA�h�A��Ʀa�}�߸j�w - �B�涥�q�T�w��Ʀa�}
*/

//----------------------------------------------------------------
//�h�A�򥻻y�k
class Animal {
public:
	//�Q��virtual ���ܦa�}���j�w
	virtual void speak() {
		cout << "Animal Speaking" << endl;
	}
};
//��
class Cat :public Animal {
public:
	void speak() {
		cout << "Cat Speaking" << endl;
	}
};
//��
class Dog :public Animal {
public:
	void speak() {
		cout << "Dog Speaking" << endl;
	}
};
//���ܨ��
//�]���a�}���j�w �b�sĶ���q�N�T�w��Ʀa�}��Animal ���O Cat
//���ܤ�k�� �bAnimal ��speak �令 virtual
void doSpeak(Animal& animal) {	//Animal &animal = cat;
	animal.speak();
}
void test01() {
	Cat cat;
	doSpeak(cat);
	Dog dog;
	doSpeak(dog);
}
//�ʺA�h�A��������
//1. ���~�����Y
//2. �l�����g����������

//�ʺA�h�A�ϥ�
//  ���������w�Ϊ̤ޥ� ���V�l����H

//----------------------------------------------------------------
//�h�A��z��R
void test02() {
	// Animal	�S��virtual	sizeof = 1
	// Animal	����vitrual	sizeof = 4
	cout << "Sizeof Animal = " << sizeof(Animal) << endl;	 // �t�O�b����w	����(��)���w
}

//----------------------------------------------------------------
//�h�A�ר�--�p�����
//���q�g�k
class Calculator {
public:
	int getResult(string oper) {
		if (oper == "+") { return m_Num1 + m_Num2; }
		else if (oper == "-") { return m_Num1 - m_Num2; }
		else if (oper == "*") { return m_Num1 * m_Num2; }
		else if (oper == "/") { return m_Num1 / m_Num2; }
	}
	//�p�G�Q�X�i�s���\�� �ݭn�ק﷽�X
	int m_Num1;
	int m_Num2;
};
//���q�g�k
void test03() {
	Calculator c;
	c.m_Num1 = 20;
	c.m_Num2 = 10;

	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
	cout << c.m_Num1 << " / " << c.m_Num2 << " = " << c.getResult("/") << endl;
	cout << "--------------------------------------------------------" << endl;
}

//�h�A�g�k ��{�p�����H��
class AbstractCalculator {
public:
	virtual int getResult() {
		return 0;
	}
	int m_Num1;
	int m_Num2;
};
//�[�k�p�⾹��
class AddCalculator : public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 + m_Num2;
	}
};
//��k�p�⾹��
class SubCalculator : public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 - m_Num2;
	}
};
//���k�p�⾹��
class MulCalculator : public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 * m_Num2;
	}
};
//���k�p�⾹��
class DivCalculator : public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 / m_Num2;
	}
};

//�ʺA�h�A�ϥ�
//���������w�Ϊ̤ޥ� ���V�l����H
void test04() {
	//�ʺA�h�A�ϥ�
	//���������w�Ϊ̤ޥ� ���V�l����H
	//�[�k
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 20;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;

	//��k
	abc = new SubCalculator;
	abc->m_Num1 = 20;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;

	//���k
	abc = new MulCalculator;
	abc->m_Num1 = 20;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;

	//���k
	abc = new DivCalculator;
	abc->m_Num1 = 20;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " / " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
}
//���M�N�X�ܦh ���U�ӥ\��N�X���� ��K�w����D �]�i�����N�X�iŪ��
//* ��´���c�M��
//* �iŪ�ʱj
//* �e������X�i�H�κ��@�ʰ�

//----------------------------------------------------------------
//�µ��ƩM��H��
//�i��|�������O���ƨS�N�q �����l���O�ե� �i�H�N���Ƨאּ�µ��� �����]�٬���H��
// virtual ���� ��ƦW (�Ѽ�) = 0;
//* ��H���L�k��Ҥƹ�H
//* �l���������g���������µ��� ���M�]�|�O��H��
class Base1 {
public:
	virtual void func() = 0;	//�µ���
	//�u�n���@�ӯµ��� �����٬���H��
	//��H���S�I:
	//* �L�k��Ҥƹ�H	(���i Base1 b; �άO new Base;)
	//* ��H�����l���������g���������µ���
};
class Son1 :public Base1 {
public:
	// ��H�����l���������g���������µ��� �S���g���ܹ�ҤƮɴN�|����
	//�������g�~�i���Q��Ҥ�
	virtual void func() {
		cout << "Son1 func��ƽե�" << endl;
	};
};

void test05() {
	//Son1 s;
	Base1* base = new Son1;
	base->func();
}

//----------------------------------------------------------------
//�h�A�ר�--�s�@���~
class AbstractDrinking {
public:
	//�N��
	virtual void Boil() = 0;
	//�R�w
	virtual void Brew() = 0;
	//�ˤJ�M��
	virtual void PourInCup() = 0;
	//�[�J����
	virtual void PutSomeThing() = 0;
	//�s�@���~
	virtual void makeDringk() {
		Boil();
		Brew();
		PourInCup();
		PutSomeThing();
	}
};
//�@��
class Coffee : public AbstractDrinking {
	//�N��
	virtual void Boil() { cout << "�N�u��" << endl; }
	//�R�w
	virtual void Brew() { cout << "�R�w�@��" << endl; }
	//�ˤJ�M��
	virtual void PourInCup() { cout << "�ˤJ�@��" << endl; }
	//�[�J����
	virtual void PutSomeThing() { cout << "�[�J��}�P����" << endl; }
};
//����
class Tea : public AbstractDrinking {
	//�N��
	virtual void Boil() { cout << "�N�u��" << endl; }
	//�R�w
	virtual void Brew() { cout << "�R�w����" << endl; }
	//�ˤJ�M��
	virtual void PourInCup() { cout << "�ˤJ���M" << endl; }
	//�[�J����
	virtual void PutSomeThing() { cout << "�[�J�f�c��ä" << endl; }
};
//�s�@���
void doWork(AbstractDrinking* abs) {	//AbstractDrinking * abs = new Coffee/Drink �إߪŶ��b���
	abs->makeDringk();
	cout << "----------------------------------------" << endl;
	delete abs;	//��b��� �ҥH�ݭn����X��
}
void test06() {
	//�s�@�@��
	doWork(new Coffee);
	//�s�@����
	doWork(new Tea);
}

//----------------------------------------------------------------
//�h�A�ר�---��R�c �P �µ�R�c
/*
�h�A�ϥή� �Y�l�������ݩʶ}�P�ܰ�� ����������w�b����ɵL�k�եΨ�l�����R�c�N�X
�Ѥ�:  �N���������R�c��Ƨאּ ��R�c �άO �µ�R�c

��R�c �µ�R�c �@��:
* �i�H�ѨM�������w����l����H
* ���ݭn�����ƹ�{

��R�c �µ�R�c �ϧO:
* �Y���µ�R�c ��������H�� �L�k��Ҥƹ�H
*/
class Animal02 {
public:
	Animal02() {
		cout << "Animal �c�y��ƽե�" << endl;
	}
	virtual void speak() = 0;
	//��R�c
	//virtual ~Animal02() {
	//	cout << "Animal �R�c��ƽե�" << endl;
	//}

	//�µ�R�c �ݭn�n�� �ݭn��{
	virtual ~Animal02() = 0;	
	//�u������|���� �]�����s�b�a�X��{ �@��µ��Ʒ|�n�D�l���@�w�o�N���{�K�O�]���z�� ���R�c�L�k�Ѥl����{
};
Animal02::~Animal02() {
	cout << "Animal �µ�R�c��ƽե�" << endl;
}
//���F�N�µ�R�c��{ �������~��{�B�z
class Cat02 :public Animal02 {
public:
	Cat02(string name) {
		cout << "Cat �c�y��ƽե�" << endl;
		m_Name = new string(name);	//�l���㦳��ϪŶ�
	}
	virtual void speak() {
		cout << *m_Name <<" Cat Speaking" << endl;
	}
	string* m_Name;

	~Cat02() {
		cout << "Cat �R�c��ƽե�" << endl;
		if (m_Name != NULL) {
			cout << "Cat �R�c��ư�ϧR��" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
};
void test07() {
	Animal02* animal = new Cat02("Tom");
	animal->speak();
	//�������w�b�R�c���ɭ� ���|�եΤl���R�c��� �ɭP�l���Y������ݩ� �|�X�{���s���|
	//�Ѫk ������R�c�אּ��R�c virtual ~Animal02(){}
	delete animal;
}
//1. ��R�c�ίµ�R�c�O�ΨӸѨM�q�L�������w����l����H
//2. �Y�l���S����ϼƾ� �i�H���g��R�c�ίµ�R�c
//3. �֦���R�c�ίµ�R�c���� �]�ݩ��H��

//----------------------------------------------------------------
//�h�A�ר�---�q���ո˨����{
//��H���P�s��
class CPU {
public:
	//��H�p����
	virtual void calculate() = 0;
};
class Graphic {
public:
	//��H��ܨ��
	virtual void display() = 0;
};
class Memory {
public:
	//��H�s�x���
	virtual void storage() = 0;
};

class Computer {
public:
	Computer(CPU * c, Graphic* g, Memory* m){
		cpu = c;
		graphic = g;
		memory = m;
	}
	//�u�@���
	void work() {
		cpu->calculate();
		graphic->display();
		memory->storage();
	}
	~Computer() {
		if (cpu != NULL) {
			delete cpu;
			cpu = NULL;
		}
		if (graphic != NULL) {
			delete graphic;
			graphic = NULL;
		}
		if (memory != NULL) {
			delete memory;
			memory = NULL;
		}
	}

private:
	CPU* cpu;
	Graphic* graphic;
	Memory* memory;
};

//����t��
//Intel
class IntelCpu : public CPU {
public:
	virtual void calculate() {
		cout << "Inter CPU is Running" << endl;
	}
};
class IntelGraphic : public Graphic {
public:
	virtual void display() {
		cout << "Intel Graphic is Running" << endl;
	}
};
class IntelMemory : public Memory {
public:
	virtual void storage() {
		cout << "Intel Memory is Running" << endl;
	}
};
//AMD
class AMDCpu : public CPU {
public:
	virtual void calculate() {
		cout << "AMD CPU is Running" << endl;
	}
};
class AMDGraphic : public Graphic {
public:
	virtual void display() {
		cout << "AMD Graphic is Running" << endl;
	}
};
class AMDMemory : public Memory {
public:
	virtual void storage() {
		cout << "AMD Memory is Running" << endl;
	}
};

void test08() {
	//Computer 01
	CPU* intC = new IntelCpu;
	Graphic* intG = new IntelGraphic;
	Memory* intM = new IntelMemory;

	Computer* computer01 = new Computer(intC, intG, intM);
	computer01->work();
	delete computer01;

	//Computer 02
	CPU* amdC = new AMDCpu;
	Graphic* amdG = new AMDGraphic;
	Memory* amdM = new AMDMemory;

	Computer* computer02 = new Computer(amdC, amdG, amdM);
	computer02->work();
	delete computer02;
}

//----------------------------------------------------------------

int main() {
	srand((unsigned int)time(NULL));

	//�h�A�򥻻y�k
	//test01();

	//�h�A��z��R
	//test02();

	//�h�A�ר�--�p�����
	//test03();
	//test04();

	//�µ��ƩM��H��
	//test05();

	//�h�A�ר�--�s�@���~
	//test06();

	//�h�A�ר�---��R�c �P �µ�R�c
	//test07();

	//�h�A�ר�---�q���ո˨����{
	//test08();




	system("pause");
	return 0;
}
