#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include <fstream>	//	���ާ@�t���Y���
#include <vector>
#include <algorithm>

using namespace std; 


//vector�e��
/*
vector�ƾڵ��c �� �Ʋի����� �]�٬� ��ݼƲ�
�ƲլO�R�A�Ŷ� vector�i�H�ʺA�X�i
* �ʺA�X�i:  ���O�b��Ŷ��ᱵ��s�Ŷ�  �ӬO���j���Ŷ��N��ƾګ����i�h  �����Ŷ�
* vector�e�������N���O����H���X�ݪ����N��
*/
void printVector(vector<int>v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//------------------------------------------------------
//�c�y���
/*
vector<T> v;					//�ĥμҪO��{����{  �q�{�c�y���
vector(v.begin(), v.end() );	//�Nv[begin(), end()] �϶�����������������
vector( n, elem);				//�c�y��ƱNn ��elem ����������
vector( const vector &vec);		//�����c�y���
*/
void test01() {
	vector<int> v1;		//�q�{�c�y �L�Ѻc�y
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	//�q�L�϶��覡�c�y
	vector<int>v2(v1.begin(), v1.end());
	printVector(v2);	//���\����v1 begin �� v1 end

	//�Nn ��elem ����������
	vector<int>v3(7, 20);	//�����C��20
	printVector(v3);

	//�����c�y���
	vector<int>v4(v3);
	printVector(v4);	//����v3
}

//------------------------------------------------------
//��Ⱦާ@
/*
vector& operator = (const vector &vec);	//���������ާ@��
assign(beg, end);						//�N[beg, end]�϶����ƾګ�����ȵ�����
assign(n, elem);						//�Nn��elem������ȵ�����
*/
void test02() {
	vector<int> v1;		//�q�{�c�y �L�Ѻc�y
	for (int i = 0; i < 10; i++) {
		v1.push_back(i*i);
	}
	printVector(v1);

	//���
	//vector& operator = (const vector & vec);	//���������ާ@��
	vector<int> v2;
	v2 = v1;			
	printVector(v2);	

	//assign(beg, end);		//�N[beg, end]�϶����ƾګ�����ȵ�����
	vector<int> v3;
	v3.assign(v1.begin(), v1.end());
	printVector(v3);

	//assign(n, elem);		//�Nn��elem������ȵ�����
	vector<int> v4;
	v4.assign(10, 300);
	printVector(v4);
}

//------------------------------------------------------
//�e�q�M�j�p
/*
empty();				�P�_�e���O�_����
capacity();				�e�����e�q
size();					��^�e���������Ӽ�
resize(int num);		-���s���w�e�����׬�num �Y�e���ܦ��h�H �q�{�� 0 ��R�s��m
						-�Y�e���ܵu �����W�X���ת������Q�R��						
resize(int num, elem);	-���s���w�e�����׬�num �Y�e���ܦ��h�H   elem   ��R�s��m
						-�Y�e���ܵu �����W�X���ת������Q�R��	
*/
void test03() {
	vector<int> v1;		//�q�{�c�y �L�Ѻc�y
	for (int i = 0; i < 10; i++) {
		v1.push_back(i * i);
	}
	printVector(v1);

	if (v1.empty()) {		//���u �N��e������
		cout << "v1����" << endl;
	}
	else {
		cout << "v1������" << endl;
		cout << "�e�q��: " << v1.capacity() << endl;
		cout << "�j�p��: " << v1.size() << endl;
	}

	//���s���w�j�p
	v1.resize(15);
	printVector(v1);

	v1.resize(20, 33);
	printVector(v1);
}

//------------------------------------------------------
//���J�M�R��
/*
push_back(ele);										//�������J����ele
pop_back();											//�̧��R�������@��
insert(const_iterator pos, ele);					//���N�����V��mpos ���J���� ele
insert(const_iterator pos, int count, ele);			//���N�����V��mpos ���J���� ele ���Jcount ��
erase(const_iterator pos);							//�R�����N�����V������
erase(const_iterator start, const_iterator end);	//�R�����N�� start �� end ����������
clear();											//�R���e�����Ҧ�����
*/
void test04() {
	vector<int> v1;		//�q�{�c�y �L�Ѻc�y
	//�������J����ele
	for (int i = 0; i < 10; i++) {
		v1.push_back(i * 10);
	}
	printVector(v1);

	//�̧��R������
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	printVector(v1);

	//���J����
	v1.insert(v1.begin(), 222);	//�Y�����J222
	printVector(v1);

	v1.insert(v1.begin(), 3, 99);	//�Y�����J3�� 99
	printVector(v1);

	//�R��
	v1.erase(v1.begin());		//�R���Y���@��
	printVector(v1);

	v1.erase(v1.begin(), v1.begin()+3);	//�R���Y���T��
	printVector(v1);

	//�M��
	v1.clear();
	printVector(v1);
}

//------------------------------------------------------
//�ƾڦs��
/*
at(int idx);	//��^����idx�ҫ����ƾ�
operator[];		//��^����idx�ҫ����ƾ�
front();		//��^�e���Ĥ@�Ӽƾڤ���
back();			//��^�e���̫�@�Ӽƾڤ���
*/
void test05() {
	vector<int> v1;		//�q�{�c�y �L�Ѻc�y
	for (int i = 0; i < 10; i++) {
		v1.push_back(i * 10);
	}
	printVector(v1);
	
	for (int i = 0; i < 10; i++) {
		cout << v1.at(i) << "\t";					//at(int idx);	//��^����idx�ҫ����ƾ�
		cout << v1[i] << "   " << endl;				//operator[];	//��^����idx�ҫ����ƾ�
	}
	cout << "First One Is: " << v1.front() << endl;
	cout << "Latest One Is: " << v1.back() << endl;
}

//------------------------------------------------------
//�����e��
//swap (vec);	//�N���������Pvec ����
void test06() {
	vector<int> v1;		//�q�{�c�y �L�Ѻc�y
	vector<int> v2;		//�q�{�c�y �L�Ѻc�y
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(10 - i);
	}
	cout << "�洫�e" << endl;
	printVector(v1);
	printVector(v2);

	cout << "�洫��" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}

//��ڥγ~	����swap�i�H���Y���s�Ŷ�
void test07() {
	vector<int> v;		//�q�{�c�y �L�Ѻc�y
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}
	cout << "V.�e�q = " << v.capacity() << endl;	//�e�q
	cout << "V.�j�p = " << v.size() << endl;		//�j�p
	cout << endl;

	v.resize(3);	//���s���w�j�p
	cout << "V.�e�q = " << v.capacity() << endl;	//�e�q
	cout << "V.�j�p = " << v.size() << endl;		//�j�p
	cout << endl;
	//�i���Ŷ����O�W�G�P

	//����swap�i�H���Y���s�Ŷ�
	vector<int>(v).swap(v);
	cout << "V.�e�q = " << v.capacity() << endl;	//�e�q
	cout << "V.�j�p = " << v.size() << endl;		//�j�p
	cout << endl;
}

//------------------------------------------------------
//�w�d�Ŷ�
//reserve(int len);	//�e���w�dlen�Ӥ������� �w�d��m����l�� �������i�X��
void test08() {
	//�S���w�d�Ŷ�
	vector<int> v1;		//�q�{�c�y �L�Ѻc�y
	int num1 = 0;	//�έp�}�P����
	int* p1 = NULL;
	for (int i = 0; i < 100000; i++) {
		v1.push_back(i);

		if (p1 != &v1[0]) {	//�p�G���a�}�ܤ� �N���ۭ��s�}�P���s �ҥH�έp���}�P���ƭn++
			p1 = &v1[0];
			num1++;
		}
	}
	cout << "�S�w�d�Ŷ����}�P���� = \t" << num1 << endl;

	//���w�d�Ŷ�
	vector<int> v2;		//�q�{�c�y �L�Ѻc�y
	v2.reserve(100000);	//�w�d�Ŷ�
	int num2 = 0;	//�έp�}�P����
	int* p2 = NULL;
	for (int i = 0; i < 100000; i++) {
		v2.push_back(i);

		if (p2 != &v2[0]) {	//�p�G���a�}�ܤ� �N���ۭ��s�}�P���s �ҥH�έp���}�P���ƭn++
			p2 = &v2[0];
			num2++;
		}
	}
	cout << "���w�d�Ŷ����}�P���� = \t" << num2 << endl;


}
//------------------------------------------------------


int main() {

	//vector�e��
	//�c�y���
	//test01();
	
	//��Ⱦާ@
	//test02();
	
	//�e�q�M�j�p
	//test03();
	
	//���J�M�R��
	//test04();
	
	//�ƾڦs��
	//test05();
	
	//�����e��
	//test06();
	//test07();

	//�w�d�Ŷ�
	test08();


	system("pause");
	return 0;
}