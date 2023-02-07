#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include <fstream>	//	���ާ@�t���Y���
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

//deque�e��	�Y���	#include <deque>
//���ݼƲ�  �i�H���Y���i�洡�J�R�����ާ@

//�Pvector �ϧO
//-vector����Y�����J�R�����S�Ĳv �ƾڶq�V�j�Ĳv�V�C
//-deque�ۤ񤧤U����Y�����J�R����vector �ֳt
//-vector�X�ݤ������t�פ�deque �ֳt ���{�H�M��̪�������{����

void printDeque(const deque<int>& d) {		//�[const ����e�����ƾڳQ���
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}

// STL �ר�1 ���e����
/*
1. �Ыؤ��W��� ���vector
2. �M��vector�e�� ���X�C�@�ӿ�� fot�`�� ��Q�ӥ������s��deque�e����
3. sort��k����ƱƧ� �h���̰����̧C��
4. deque�e�� �M���@�M �֥[�`��
5. ���������
*/

class Person {
public:
	Person(string name, int score) {
		this->m_name = name;
		this->m_score = score;
	}
	string m_name;
	int m_score;	//������
};

//�o�N�O�M���\�� �ڼg�X�ӬO���F�ȿ� �̫�~��ı��
void printPerson(const vector<Person>& v) {		//�[const ����e�����ƾڳQ���
	for (vector<Person>::const_iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it).m_name << "  " << (*it).m_score << endl;
	}
	cout << endl;
}

void createPerson(vector<Person>& v) {
	string nameSeed = "12345";
	//5�H
	for (int i = 0; i < 5; i++) {
		string name = "Player";
		name += nameSeed[i];

		int score = 0;

		Person p(name, score);
		v.push_back(p);
	}
}

void setScore(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		//�N���Ʃ�Jdeque�e��
		deque<int>d1;
		for (int i = 1; i <= 10; i++) {
			d1.push_back(rand() % 100 + 1);
		}

		//�ƧǨ���ܥh�Y�h��������
		cout << (*it).m_name << ": ";
		sort(d1.begin(), d1.end());	//�ƧǾާ@
		d1.pop_back();	//�h��
		d1.pop_front();	//�h�Y
		printDeque(d1);

		//�����������
		int sum = 0;
		for (deque<int>::const_iterator dit = d1.begin(); dit != d1.end(); dit++) {
			sum += *dit;
		}
		int avg = sum / d1.size();
		it->m_score = avg;
		cout << "�`��: " << sum << "\t������: " << it->m_score << endl;
	}
}


void GameMenu() {
	vector<Person> vP;
	createPerson(vP);
	printPerson(vP);
	setScore(vP);
	cout << endl;
	printPerson(vP);
}


int main() {
	//���U�@�U�����|�Ψ쪺�H����
	srand((unsigned int)time(NULL));

	GameMenu();



	system("pause");
	return 0;
}
