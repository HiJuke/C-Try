#include <iostream>
#include <ctime>	//	time �ɶ��t���Y���
#include"CRoomSystem.h"

using namespace std;

void SystemStart() {
	while (true) {
		FirstMenu();
	}
}

int main() {
	//���U�@�U�����i��|�Ψ쪺�H����
	srand((unsigned int)time(NULL));

	SystemStart();

	system("pause");
	return 0;
}

