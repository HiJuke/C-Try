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
#include"globalFile.h"
#include"computerRoom.h"
#include"orderFile.h"

using namespace std;

//������ �����~��
class Identity {
public:
	//�T�H�U�ۭn�����P��Menu
	virtual void openMenu() = 0;

	string m_Name;	
	string m_Pwd;	//�K�X
};
