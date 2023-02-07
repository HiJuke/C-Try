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

//身分類 提供繼承
class Identity {
public:
	//三人各自要有不同的Menu
	virtual void openMenu() = 0;

	string m_Name;	
	string m_Pwd;	//密碼
};
