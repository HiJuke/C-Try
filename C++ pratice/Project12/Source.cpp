#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include <fstream>	//	���ާ@�t���Y���

#define MAX 1000

using namespace std;

//���ާ@	���Y�ݥ[�J�Y���<fstream>
//1. �奻���		�H�奻��ASCII�Φ��s�x�b�p�����
//2. �G�i����		�H�奻���G�i��Φ��s�x�b�p�����  �@�뤣�ઽ��Ū��

//* ofstream:	�g�J�ާ@
//* ifstream:	Ū���ާ@
//* fstream:	Ū�g�ާ@

//------------------------------------------------------
//�奻��� �g��� ���B�J
void test01() {
	//1. �]�t�Y���<fstream>
	//2. �Ыجy��H
	ofstream ofs;
	//3. ���w���}�覡
	ofs.open("test.txt", ios::out);	// (���W�P���|, �ާ@�覡)
	//4. �g���e
	ofs << "Name --- Peter " << endl;
	ofs << "Male" << endl;
	ofs << "Age 28" << endl;
	//5. �������
	ofs.close();
}
//���槹test01�� �i�b�M�׸�Ƨ����test.txt

//------------------------------------------------------
//�奻��� Ū��� ���B�J
void test02() {
	//1. �]�t�Y���<fstream>
	//2. �Ыجy��H
	ifstream ifs;
	//3. ���w���}�覡 ���}�çP�_�O�_���}���\
	ifs.open("test.txt", ios::in);	// (���W�P���|, �ާ@�覡)
	if (!ifs.is_open()) {	//is_open() �|�P�_���O�_���} ���}�^�_true �S���h�Ofalse
		cout << "�}�ҥ���" << endl;
		return;
	}
	//4. Ū���e
	//�Ĥ@��
	/*
	char buf[1024] = { 0 };
	while (ifs >> buf) {
		cout << buf << endl;
	}
	*/
	//�ĤG��
	/*
	char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf))) {
		cout << buf << endl;
	}
	*/
	//�ĤT��
	/*
	string buf;
	while ( getline(ifs, buf)) {
		cout << buf << endl;
	}
	*/
	//�ĥ|��	������
	/*
	char c;
	while ( (c = ifs.get()) != EOF) {	//EOF end of file
		cout << c ;
	}*/

	//5. �������
	ifs.close();
}

//------------------------------------------------------
//�G�i���� �g��� ���B�J	(���}�u�n�� ios::binary )
//�D�n�Q�άy��H�եΦ������ write
class Person1 {
public:
	char m_Name[64];
	int m_Age;
};
void test03() {
	//1. �]�t�Y���
	//2. �Ыجy��H
	ofstream ofs;
	//ofstream ofs("person.txt", ios::out | ios::binary);	//�o�@�k�N�B�J2+3�X�@
	//3. ���}���
	ofs.open("person.txt", ios::out | ios::binary);
	//4. �g�J���
	Person1 p = { "Peter", 28 };
	ofs.write( (const char*)&p , sizeof(Person1) );
	//5. �������
	ofs.close();
}
//���}���|�ݨ�ܦh�ťթάO�ýX �o�O�G�i���󪺰��D �u�n��ΤG�i�Ū��Ū��N�S���D �����κޥL

//------------------------------------------------------
//�G�i���� Ū���
void test04() {
	//1. �]�t�Y���<fstream>
	//2. �Ыجy��H
	ifstream ifs;
	//3. ���w���}�覡 ���}�çP�_�O�_���}���\
	ifs.open("person.txt", ios::in | ios::binary);	// (���W�P���|, �ާ@�覡)
	if (!ifs.is_open()) {	//is_open() �|�P�_���O�_���} ���}�^�_true �S���h�Ofalse
		cout << "�}�ҥ���" << endl;
		return;
	}
	//4. Ū���e
	Person1 p;
	ifs.read((char*)&p, sizeof(Person1));
	cout << p.m_Name << "\t" << p.m_Age << endl;
	//5. �������
	ifs.close();
}

//------------------------------------------------------



int main() {
	srand((unsigned int)time(NULL));

	//�奻��� �g���
	//test01();

	//�奻��� Ū���
	//test02();

	//�G�i���� �g���
	//test03();

	//�G�i���� Ū���
	//test04();

	system("pause");
	return 0;
}