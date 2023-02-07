#pragma once
#include<iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include <fstream>	//	文件操作系統頭文件
using namespace std;

//自己通用的數組類
template<class T>
class MyArray {
public:
	//有參構造 參數容量
	MyArray(int capacity) {
		cout << "有參構造 參數容量調用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//拷貝構造
	MyArray(const MyArray& arr) {
		cout << "拷貝構造" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//深拷貝
		this->pAddress = new T[arr.m_Capacity];
		//拷貝arr數據
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator = 防止淺拷貝問題
	MyArray& operator = (const MyArray& arr) {
		cout << "防止淺拷貝問題" << endl;
		//如果有 先釋放堆區數據
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//深拷貝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		//拷貝arr數據
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//尾插法
	void Push_Back(const T& val){
		//判斷容量是否等於大小
		if (this->m_Capacity == this->m_Size) {
			return;	//滿了 沒得插入了
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;	//更新數組大小
	}

	//尾刪法
	void Pop_Back() {
		//讓用戶訪問不到最後一個元素
		if (this->m_Size == 0) {
			return;	//大小為0 沒有數據 何必刪除
		}
		this->m_Size--;
	}

	//通過下標方式訪問數組中元素	arr[0] = 200	???	想讓賦值可用 必須使用引用
	T& operator[] (int index) {
		return this->pAddress[index];
	}

	//返回數組容量
	int getCapacity() { return this->m_Capacity;	 }
	//返回數組大小
	int getSize() { return this->m_Size;	 }

	//析構
	~MyArray(){
		cout << "析構" << endl;
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}



private:
	T* pAddress;	//指針指向堆區開闢的真實數組
	int m_Capacity;	//數組容量
	int m_Size;		//數組大小
};


