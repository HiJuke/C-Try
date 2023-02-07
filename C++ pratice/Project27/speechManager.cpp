#include"speechManager.h"


//�c�y
SpeechManager::SpeechManager() {
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
}

//�R�c
SpeechManager::~SpeechManager() {

}

//���ե� ����ƹM��
void SpeechManager::testSpeaker01(map<int, Speaker> &mp) {
	for (map<int, Speaker>::iterator it = mp.begin(); it != mp.end(); it++) {
		cout << "���s��: " << it->first
			<< "\t\t�m�W: " << it->second.m_name
			<< "\t\t���Z: " << it->second.m_score[0] << endl;
	}
}

//�}�l���ɦ������ ��l��
void SpeechManager::initSpeech() {
	this->v1.clear();
	this->v2.clear();
	this->vVectory.clear();
	this->m_Speaker.clear();
	this->m_Index = 1;
	this->m_Record.clear();
}

//�}�l���ɦ������ ���ɫ��A
void SpeechManager::createSpeaker() {
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++) {
		//�Ӧ���m�W
		string name = "Player";
		name += nameSeed[i];

		//�Ӧ�������k�s
		Speaker sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++) {
			sp.m_score[j] = 0;
		}

		//12�H�s��
		this->v1.push_back(i + 10001);

		//�s���P���s�Jmap
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}

	//����
	//testSpeaker01(this->m_Speaker);
}

//1. �}�l�v��
//1 --- ����
void SpeechManager::speechDraw() {
	cout << "������ ��" << this->m_Index << "��" << endl;
	cout <<"---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---" << endl;
	cout << "���ҫ�t�����Ǧp�U" << endl;
	if (this->m_Index == 1) {
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;

	}
	else {
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}

	cout << "---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---" << endl;
	system("pause");
	system("cls");
}
//1 --- �v��
void SpeechManager::speechBattleBody() {
	cout << "---+---+---+---+---+---+---��" << this->m_Index << "�����ɶ}�l---+---+---+---+---+---+---" << endl;
	//�{�ɮe��
	multimap<int, int, greater<int>> groupScore;
	//�O���H����
	int num = 0;

	//���ɥήe��
	vector<int>v_Src;
	if (this->m_Index == 1) {
		v_Src = v1;
	}
	else {
		v_Src = v2;
	}

	//�M���P����
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {
		num++;

		//���� ���Ʈe��
		deque<int>d;
		//10�ӵ��f
		for (int i = 0; i < 10; i++) {
			int score = rand() % 100 + 1;
			d.push_back(score);
		}
		//�Ƨ�	�ϥ�greater
		sort(d.begin(), d.end(), greater<int>());
		//�h�Y�h��
		d.pop_back();
		d.pop_front();

		//������
		int avg = accumulate(d.begin(), d.end(), 0.0f) / d.size();
		//��J�ƾ�
		this->m_Speaker[*it].m_score[this->m_Index - 1] = avg;

		//�s�J�{�ɮe�� ����F�줻�H
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0){	//�o�˷|��n�bnum = 6 & 12���ɭ�Ĳ�o
			cout << "�p�� " << num / 6 << " �W���P����:" << endl;
			//����ܩҦ�6�H�����Z
			for(multimap<int, int, greater<int>>::iterator mit = groupScore.begin(); mit!=groupScore.end(); mit++){
				cout << mit->second << "\t\t�m�W: " << this->m_Speaker[mit->second].m_name 
					<< "\t\t���Z: " << this->m_Speaker[mit->second].m_score[this->m_Index - 1] << endl;
			}
			cout << "---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---" << endl;

			//���X�ʯŪ�
			int count = 0;
			cout << "�ʯſ�⬰" << endl;
			//��ܸӲդT��ʯŪ̪����Z
			for (multimap<int, int, greater<int>>::iterator mit = groupScore.begin(); mit != groupScore.end() && count <3 ; mit++, count++) {
				cout << mit->second << "\t\t�m�W: " << this->m_Speaker[mit->second].m_name
					<< "\t\t���Z: " << this->m_Speaker[mit->second].m_score[this->m_Index - 1] << endl;

				//���J�U�@���e��
				if (this->m_Index == 1) {
					v2.push_back((*mit).second);
				}
				else {
					vVectory.push_back((*mit).second);
				}
			}
			cout << "---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---" << endl;
			groupScore.clear();
		}

	}


	cout << "---+---+---+---+---+---+---��" << this->m_Index << "�����ɵ���---+---+---+---+---+---+---" << endl;

	//����
	//testSpeaker01(this->m_Speaker);
	system("pause");
	system("cls");
}
//1 --- �G��
void SpeechManager::showScore() {
	cout << "---+---+---+---+---+---+---��" << this->m_Index << "���ʯūH��---+---+---+---+---+---+---" << endl;

	vector<int>v;
	if (this->m_Index == 1) {
		v = v2;
	}
	else {
		v = vVectory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it) 
			<< "\t\t�m�W: " << m_Speaker[*it].m_name 
			<< "\t\t�o��: " << m_Speaker[*it].m_score[this->m_Index - 1] << endl;
	}
	cout << "---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---" << endl;

}
//1 --- �O�s
void SpeechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);	//�ο�X���覡���}���

	//�N�C�ӤH���ƾڼg�J
	for (vector<int>::iterator it = vVectory.begin(); it != vVectory.end(); it++) {
		ofs << *it << "," << this->m_Speaker[*it].m_score[1] << ",";
	}
	ofs << endl;

	ofs.close();
	cout << "�w�����O�s" << endl;

	this->fileIsEmpty = false;	//��󤣦A����
}
//1 --- �����v��
void SpeechManager::startSpeech() {
	//�Ĥ@��
	//����
	this->speechDraw();
	//����
	this->speechBattleBody();
	//��ܤ���P�ʯŵ��G
	this->showScore();


	//�ĤG��
	this->m_Index++;
	//����
	this->speechDraw();
	//����
	this->speechBattleBody();
	//��ܤ��
	this->showScore();
	//�O�s���G
	this->saveRecord();

	//���ɵ��� ���s���A
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();

	cout << "�������ɧ���" << endl;
	system("pause");
}

//0.�h�X�t��
void SpeechManager::exitSystem() {
	cout << "�P�¨ϥ� �w��U���ϥ�" << endl;
	system("pause");
	exit(0);
}

//2. �d�ݩ���
//2 --- ������
void SpeechManager::loadRecord() {
	ifstream ifs("speech.csv", ios::in);
	
	//�ˬd���O�_����
	if (!ifs.is_open()) {
		this->fileIsEmpty = true;
		cout << "��󤣦s�b!" << endl;
		ifs.close();
		return;
	}

	//��󤣬���
	this->fileIsEmpty = false;

	string data;
	int index = 0;
	while (ifs >> data) {
		vector<string>v;
		int pos = -1;
		int start = 0;

		while (true) {
			//�� , �䤣��N��^
			pos = data.find(",", start);
			if (pos == -1) {
				break;
			}
			//���F �i����� �ѼƤ@���_�l��m �ѼƤG���^������
			string tmp = data.substr(start, pos - start);

			v.push_back(tmp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}
//2 --- �i�ܬ���
void SpeechManager::showRecord() {
	if (this->fileIsEmpty) {
		cout << "��󤣦s�b �ά���" << endl;
	}

	for (int i = 0; i < this->m_Record.size(); i++) {
		cout << "��" << i + 1 << "��"
			<< "  �a�x: " << this->m_Record[i][0] << "  �o��: " << this->m_Record[i][1]
			<< "  �ȭx: " << this->m_Record[i][2] << "  �o��: " << this->m_Record[i][3]
			<< "  �u�x: " << this->m_Record[i][4] << "  �o��: " << this->m_Record[i][5]
			<< endl;
	}
	system("pause");
}

//3. �M�Ť��
void SpeechManager::clearRecord() {
	cout << "�T�{�M�� ??" << endl;
	cout << "1. �T�{" << endl;
	cout << "2. ��^" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		this->initSpeech();
		this->createSpeaker();
		this->loadRecord();

		cout << "�����M��" << endl;
	}
}

//��J���
void SpeechManager::enter_Menu() {
	int choice = 0;
	cin >> choice;
	switch (choice) {
	case 1:		//�}�l�t���v��
		startSpeech();
		system("cls");
		break;
	case 2:		//�d�ݩ�������
		showRecord();
		system("cls");
		break;
	case 3:		//�M�Ť��ɬ���
		clearRecord();
		system("cls");
		break;
	case 0:		//�h�X���ɵ{��
		exitSystem();
		system("cls");
		break;
	default:
		system("cls");
		break;
	}
}

//�i�ܵ��
void SpeechManager::show_Menu() {
	cout << "******************************************************" << endl;
	cout << "******************************************************" << endl;
	cout << "**************** +------------------+ ****************" << endl;
	cout << "**************** | �w��ѥ[�t���v�� | ****************" << endl;
	cout << "**************** | 1. �}�l�t���v��  | ****************" << endl;
	cout << "**************** | 2. �d�ݩ�������  | ****************" << endl;
	cout << "**************** | 3. �M�Ť��ɬ���  | ****************" << endl;
	cout << "**************** | 0. �h�X���ɵ{��  | ****************" << endl;
	cout << "**************** +------------------+ ****************" << endl;
	cout << "******************************************************" << endl;
	cout << "******************************************************" << endl;
}
