#pragma once
#include<iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include <fstream>	//	文件操作系統頭文件
using namespace std;

//解1: 直接包含cpp源文件	(不常見不建議的方法)
/*
template<class T1, class T2>
class Person8 {
public:
	Person8(T1 name, T2 age);

	void showPerson();

	T1 m_Name;
	T2 m_Age;
};
*/

//解2: 將聲明和實現寫到同一份文件裡 更改後墜名為.hpp (後墜名不是強制)
template<class T1, class T2>
class Person8 {
public:
	Person8(T1 name, T2 age);

	void showPerson();

	T1 m_Name;
	T2 m_Age;
};

template<class T1, class T2>
Person8<T1, T2>::Person8(T1 name, T2 age) {
	this->m_Name = name;
	this->m_Age = age;
}
template<class T1, class T2>
void Person8<T1, T2>::showPerson() {
	cout << m_Name << "\t" << m_Age << endl;
}