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


//�]�p�t���޲z��
class SpeechManager {
public:
	//�c�y
	SpeechManager();
	//�R�c
	~SpeechManager();

	//��J���
	void enter_Menu();

	//�}�l���ɦ������ ��l��
	void initSpeech();

	//�}�l���ɦ������ ���ɫ��A
	void createSpeaker();

	//���ե� ����ƹM��
	void testSpeaker01(map<int, Speaker>& mp);

	//1. �}�l�v�ɬy�{
	void startSpeech();
	//1. �}�l�v��
	//1 --- ����
	void speechDraw();
	//1 --- �v��
	void speechBattleBody();
	//1 --- �G��
	void showScore();
	//1 --- �O�s
	void saveRecord();

	//0. �h�X�t��
	void exitSystem();

	//2. �d�ݩ���
	void loadRecord();	//�������
	void showRecord();	//�i�ܬ���
	bool fileIsEmpty;	//�O�_����
	map<int, vector<string >> m_Record;	//�e��

	//3. �M�Ť��
	void clearRecord();

	//�i�ܵ��
	void show_Menu();

public:
	//��l12�H�e��
	vector<int> v1;

	//�����ʯ�6�H�e��
	vector<int> v2;

	//�Ӫ�3�H�e��
	vector<int> vVectory;

	//�s���P�������e��
	map<int, Speaker> m_Speaker;

	//�������ɽ���
	int m_Index;
};

