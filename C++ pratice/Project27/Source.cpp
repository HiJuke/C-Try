#include <iostream>
#include <ctime>	//	time 時間系統頭文件

using namespace std;

//基於STL 演講比賽流程管理系統

//比賽規則
/*
-- 12人參加 共兩輪 第一輪淘汰賽 第二輪決賽
-- 每人皆有編號 10001 ~ 10012
-- 比賽方式: 分組競賽 每組6人
-- 第一輪分為兩小組 依編號進行抽籤後順序演講
-- 十個評委打分 去掉最高與最低 八個分數平均為選手本輪分數
-- 淘汰小組後三人 前三人晉級
-- 第二輪決賽 前三人勝出
-- 每輪比賽後 需顯示晉級選手的信息
*/

//程序功能
/*
-- 開始演講比賽: 
-- 查看往屆比賽: 
-- 清空比賽紀錄: 
-- 退出比賽程序: 
*/

//---------------------------------------------------------------

//創建管理類
/*
-- 提供菜單介面與用戶交互
-- 對演講比賽流程進行控制
-- 與文件讀寫交互
*/
#include"speechManager.h"

//創建選手類
/*
-- 包含選手姓名與分數
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
	//照顧一下等等可能會用到的隨機數
	srand((unsigned int)time(NULL));

	//test01();

	gameStart();

	system("pause");
	return 0;
}
