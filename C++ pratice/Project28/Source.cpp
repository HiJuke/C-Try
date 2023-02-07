#include <iostream>
#include <ctime>	//	time 丁╰参繷ゅン
#include"CRoomSystem.h"

using namespace std;

void SystemStart() {
	while (true) {
		FirstMenu();
	}
}

int main() {
	//酚臮单单穦ノ繦诀计
	srand((unsigned int)time(NULL));

	SystemStart();

	system("pause");
	return 0;
}

