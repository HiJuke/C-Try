#include"speechManager.h"


//構造
SpeechManager::SpeechManager() {
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
}

//析構
SpeechManager::~SpeechManager() {

}

//測試用 選手資料遍歷
void SpeechManager::testSpeaker01(map<int, Speaker> &mp) {
	for (map<int, Speaker>::iterator it = mp.begin(); it != mp.end(); it++) {
		cout << "選手編號: " << it->first
			<< "\t\t姓名: " << it->second.m_name
			<< "\t\t成績: " << it->second.m_score[0] << endl;
	}
}

//開始比賽成員函數 初始化
void SpeechManager::initSpeech() {
	this->v1.clear();
	this->v2.clear();
	this->vVectory.clear();
	this->m_Speaker.clear();
	this->m_Index = 1;
	this->m_Record.clear();
}

//開始比賽成員函數 比賽型態
void SpeechManager::createSpeaker() {
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++) {
		//該位選手姓名
		string name = "Player";
		name += nameSeed[i];

		//該位選手分數歸零
		Speaker sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++) {
			sp.m_score[j] = 0;
		}

		//12人編號
		this->v1.push_back(i + 10001);

		//編號與選手存入map
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}

	//測試
	//testSpeaker01(this->m_Speaker);
}

//1. 開始競賽
//1 --- 抽籤
void SpeechManager::speechDraw() {
	cout << "選手抽籤 第" << this->m_Index << "輪" << endl;
	cout <<"---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---" << endl;
	cout << "抽籤後演講順序如下" << endl;
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
//1 --- 競賽
void SpeechManager::speechBattleBody() {
	cout << "---+---+---+---+---+---+---第" << this->m_Index << "輪比賽開始---+---+---+---+---+---+---" << endl;
	//臨時容器
	multimap<int, int, greater<int>> groupScore;
	//記錄人員數
	int num = 0;

	//比賽用容器
	vector<int>v_Src;
	if (this->m_Index == 1) {
		v_Src = v1;
	}
	else {
		v_Src = v2;
	}

	//遍歷與打分
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {
		num++;

		//打分 分數容器
		deque<int>d;
		//10個評審
		for (int i = 0; i < 10; i++) {
			int score = rand() % 100 + 1;
			d.push_back(score);
		}
		//排序	使用greater
		sort(d.begin(), d.end(), greater<int>());
		//去頭去尾
		d.pop_back();
		d.pop_front();

		//取平均
		int avg = accumulate(d.begin(), d.end(), 0.0f) / d.size();
		//輸入數據
		this->m_Speaker[*it].m_score[this->m_Index - 1] = avg;

		//存入臨時容器 直到達到六人
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0){	//這樣會剛好在num = 6 & 12的時候觸發
			cout << "小組 " << num / 6 << " 名次與分數:" << endl;
			//先顯示所有6人的成績
			for(multimap<int, int, greater<int>>::iterator mit = groupScore.begin(); mit!=groupScore.end(); mit++){
				cout << mit->second << "\t\t姓名: " << this->m_Speaker[mit->second].m_name 
					<< "\t\t成績: " << this->m_Speaker[mit->second].m_score[this->m_Index - 1] << endl;
			}
			cout << "---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---" << endl;

			//取出晉級者
			int count = 0;
			cout << "晉級選手為" << endl;
			//顯示該組三位晉級者的成績
			for (multimap<int, int, greater<int>>::iterator mit = groupScore.begin(); mit != groupScore.end() && count <3 ; mit++, count++) {
				cout << mit->second << "\t\t姓名: " << this->m_Speaker[mit->second].m_name
					<< "\t\t成績: " << this->m_Speaker[mit->second].m_score[this->m_Index - 1] << endl;

				//推入下一輪容器
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


	cout << "---+---+---+---+---+---+---第" << this->m_Index << "輪比賽結束---+---+---+---+---+---+---" << endl;

	//測試
	//testSpeaker01(this->m_Speaker);
	system("pause");
	system("cls");
}
//1 --- 亮分
void SpeechManager::showScore() {
	cout << "---+---+---+---+---+---+---第" << this->m_Index << "輪晉級信息---+---+---+---+---+---+---" << endl;

	vector<int>v;
	if (this->m_Index == 1) {
		v = v2;
	}
	else {
		v = vVectory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it) 
			<< "\t\t姓名: " << m_Speaker[*it].m_name 
			<< "\t\t得分: " << m_Speaker[*it].m_score[this->m_Index - 1] << endl;
	}
	cout << "---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---" << endl;

}
//1 --- 保存
void SpeechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);	//用輸出的方式打開文件

	//將每個人的數據寫入
	for (vector<int>::iterator it = vVectory.begin(); it != vVectory.end(); it++) {
		ofs << *it << "," << this->m_Speaker[*it].m_score[1] << ",";
	}
	ofs << endl;

	ofs.close();
	cout << "已完成保存" << endl;

	this->fileIsEmpty = false;	//文件不再為空
}
//1 --- 正式競賽
void SpeechManager::startSpeech() {
	//第一輪
	//抽籤
	this->speechDraw();
	//比賽
	this->speechBattleBody();
	//顯示比分與晉級結果
	this->showScore();


	//第二輪
	this->m_Index++;
	//抽籤
	this->speechDraw();
	//比賽
	this->speechBattleBody();
	//顯示比分
	this->showScore();
	//保存結果
	this->saveRecord();

	//比賽結束 重製狀態
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();

	cout << "本屆比賽完畢" << endl;
	system("pause");
}

//0.退出系統
void SpeechManager::exitSystem() {
	cout << "感謝使用 歡迎下次使用" << endl;
	system("pause");
	exit(0);
}

//2. 查看往屆
//2 --- 獲取文件
void SpeechManager::loadRecord() {
	ifstream ifs("speech.csv", ios::in);
	
	//檢查文件是否為空
	if (!ifs.is_open()) {
		this->fileIsEmpty = true;
		cout << "文件不存在!" << endl;
		ifs.close();
		return;
	}

	//文件不為空
	this->fileIsEmpty = false;

	string data;
	int index = 0;
	while (ifs >> data) {
		vector<string>v;
		int pos = -1;
		int start = 0;

		while (true) {
			//找 , 找不到就返回
			pos = data.find(",", start);
			if (pos == -1) {
				break;
			}
			//找到了 進行分割 參數一為起始位置 參數二為擷取長度
			string tmp = data.substr(start, pos - start);

			v.push_back(tmp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}
//2 --- 展示紀錄
void SpeechManager::showRecord() {
	if (this->fileIsEmpty) {
		cout << "文件不存在 或為空" << endl;
	}

	for (int i = 0; i < this->m_Record.size(); i++) {
		cout << "第" << i + 1 << "屆"
			<< "  冠軍: " << this->m_Record[i][0] << "  得分: " << this->m_Record[i][1]
			<< "  亞軍: " << this->m_Record[i][2] << "  得分: " << this->m_Record[i][3]
			<< "  季軍: " << this->m_Record[i][4] << "  得分: " << this->m_Record[i][5]
			<< endl;
	}
	system("pause");
}

//3. 清空文件
void SpeechManager::clearRecord() {
	cout << "確認清空 ??" << endl;
	cout << "1. 確認" << endl;
	cout << "2. 返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		this->initSpeech();
		this->createSpeaker();
		this->loadRecord();

		cout << "完成清空" << endl;
	}
}

//輸入菜單
void SpeechManager::enter_Menu() {
	int choice = 0;
	cin >> choice;
	switch (choice) {
	case 1:		//開始演講競賽
		startSpeech();
		system("cls");
		break;
	case 2:		//查看往屆紀錄
		showRecord();
		system("cls");
		break;
	case 3:		//清空比賽紀錄
		clearRecord();
		system("cls");
		break;
	case 0:		//退出比賽程序
		exitSystem();
		system("cls");
		break;
	default:
		system("cls");
		break;
	}
}

//展示菜單
void SpeechManager::show_Menu() {
	cout << "******************************************************" << endl;
	cout << "******************************************************" << endl;
	cout << "**************** +------------------+ ****************" << endl;
	cout << "**************** | 歡迎參加演講競賽 | ****************" << endl;
	cout << "**************** | 1. 開始演講競賽  | ****************" << endl;
	cout << "**************** | 2. 查看往屆紀錄  | ****************" << endl;
	cout << "**************** | 3. 清空比賽紀錄  | ****************" << endl;
	cout << "**************** | 0. 退出比賽程序  | ****************" << endl;
	cout << "**************** +------------------+ ****************" << endl;
	cout << "******************************************************" << endl;
	cout << "******************************************************" << endl;
}
