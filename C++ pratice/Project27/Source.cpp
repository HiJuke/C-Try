#include <iostream>
#include <ctime>	//	time �ɶ��t���Y���

using namespace std;

//���STL �t�����ɬy�{�޲z�t��

//���ɳW�h
/*
-- 12�H�ѥ[ �@��� �Ĥ@���^�O�� �ĤG���M��
-- �C�H�Ҧ��s�� 10001 ~ 10012
-- ���ɤ覡: �����v�� �C��6�H
-- �Ĥ@��������p�� �̽s���i����ҫᶶ�Ǻt��
-- �Q�ӵ��e���� �h���̰��P�̧C �K�Ӥ��ƥ�������⥻������
-- �^�O�p�ի�T�H �e�T�H�ʯ�
-- �ĤG���M�� �e�T�H�ӥX
-- �C�����ɫ� ����ܮʯſ�⪺�H��
*/

//�{�ǥ\��
/*
-- �}�l�t������: 
-- �d�ݩ�������: 
-- �M�Ť��ɬ���: 
-- �h�X���ɵ{��: 
*/

//---------------------------------------------------------------

//�Ыغ޲z��
/*
-- ���ѵ�椶���P�Τ�椬
-- ��t�����ɬy�{�i�汱��
-- �P���Ū�g�椬
*/
#include"speechManager.h"

//�Ыؿ����
/*
-- �]�t���m�W�P����
*/

void gameStart() {
	SpeechManager sm;

	while (true) {
		sm.show_Menu();
		sm.enter_Menu();
	}
}

void test01() {
	SpeechManager sm;
	sm.initSpeech();
	sm.createSpeaker();
}

int main() {
	//���U�@�U�����i��|�Ψ쪺�H����
	srand((unsigned int)time(NULL));

	//test01();

	gameStart();

	system("pause");
	return 0;
}
