#include <iostream>
#include <ctime>	//	time 時間系統頭文件
#include"CRoomSystem.h"

using namespace std;

void SystemStart() {
	while (true) {
		FirstMenu();
	}
}

int main() {
	//照顧一下等等可能會用到的隨機數
	srand((unsigned int)time(NULL));

	SystemStart();

	system("pause");
	return 0;
}

