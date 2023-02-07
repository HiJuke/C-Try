#pragma once
#include<iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include <fstream>	//	���ާ@�t���Y���
using namespace std;

//��1: �����]�tcpp�����	(���`������ĳ����k)
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

//��2: �N�n���M��{�g��P�@������ ����Y�W��.hpp (��Y�W���O�j��)
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