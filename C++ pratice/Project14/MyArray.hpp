#pragma once
#include<iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include <fstream>	//	���ާ@�t���Y���
using namespace std;

//�ۤv�q�Ϊ��Ʋ���
template<class T>
class MyArray {
public:
	//���Ѻc�y �ѼƮe�q
	MyArray(int capacity) {
		cout << "���Ѻc�y �ѼƮe�q�ե�" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//�����c�y
	MyArray(const MyArray& arr) {
		cout << "�����c�y" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//�`����
		this->pAddress = new T[arr.m_Capacity];
		//����arr�ƾ�
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator = ����L�������D
	MyArray& operator = (const MyArray& arr) {
		cout << "����L�������D" << endl;
		//�p�G�� �������ϼƾ�
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//�`����
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		//����arr�ƾ�
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//�����k
	void Push_Back(const T& val){
		//�P�_�e�q�O�_����j�p
		if (this->m_Capacity == this->m_Size) {
			return;	//���F �S�o���J�F
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;	//��s�Ʋդj�p
	}

	//���R�k
	void Pop_Back() {
		//���Τ�X�ݤ���̫�@�Ӥ���
		if (this->m_Size == 0) {
			return;	//�j�p��0 �S���ƾ� �󥲧R��
		}
		this->m_Size--;
	}

	//�q�L�U�Ф覡�X�ݼƲդ�����	arr[0] = 200	???	�Q����ȥi�� �����ϥΤޥ�
	T& operator[] (int index) {
		return this->pAddress[index];
	}

	//��^�Ʋծe�q
	int getCapacity() { return this->m_Capacity;	 }
	//��^�Ʋդj�p
	int getSize() { return this->m_Size;	 }

	//�R�c
	~MyArray(){
		cout << "�R�c" << endl;
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}



private:
	T* pAddress;	//���w���V��϶}�P���u��Ʋ�
	int m_Capacity;	//�Ʋծe�q
	int m_Size;		//�Ʋդj�p
};


