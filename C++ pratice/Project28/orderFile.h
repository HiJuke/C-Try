#pragma once
#include<iostream>
#include <fstream>
#include<map>
#include"globalFile.h"
using namespace std;

class OrderFile {
public:
	OrderFile();

	//更新預約紀錄
	void updateOrder();

	//紀錄的容器
	map<int, map<string, string>> m_orderData;
	/*
	大map 的key  存的是預約個數
	小map 的key  存的是data, room, stuid之類的類型信息
	小map 的數值 存的是該類型該有的資訊
		key		|	information
		data	|	5
		room	|	3
		stuid	|	10005
		stuname	|	student05
		.
		.
		.
	*/

	//預約記錄條數
	int m_Size;
};

