#pragma once
#include <iostream>
#include <string>
#include <fstream>	
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <numeric>
#include <functional>
#include"Speaker.h"

using namespace std;


//設計演講管理類
class SpeechManager {
public:
	//構造
	SpeechManager();
	//析構
	~SpeechManager();

	//輸入菜單
	void enter_Menu();

	//開始比賽成員函數 初始化
	void initSpeech();

	//開始比賽成員函數 比賽型態
	void createSpeaker();

	//測試用 選手資料遍歷
	void testSpeaker01(map<int, Speaker>& mp);

	//1. 開始競賽流程
	void startSpeech();
	//1. 開始競賽
	//1 --- 抽籤
	void speechDraw();
	//1 --- 競賽
	void speechBattleBody();
	//1 --- 亮分
	void showScore();
	//1 --- 保存
	void saveRecord();

	//0. 退出系統
	void exitSystem();

	//2. 查看往屆
	void loadRecord();	//成員函數
	void showRecord();	//展示紀錄
	bool fileIsEmpty;	//是否為空
	map<int, vector<string >> m_Record;	//容器

	//3. 清空文件
	void clearRecord();

	//展示菜單
	void show_Menu();

public:
	//初始12人容器
	vector<int> v1;

	//首輪晉級6人容器
	vector<int> v2;

	//勝者3人容器
	vector<int> vVectory;

	//編號與對應選手容器
	map<int, Speaker> m_Speaker;

	//紀錄比賽輪數
	int m_Index;
};

