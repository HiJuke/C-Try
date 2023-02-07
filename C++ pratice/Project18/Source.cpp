#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include <fstream>	//	文件操作系統頭文件
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

//deque容器	頭文件	#include <deque>
//雙端數組  可以對頭部進行插入刪除等操作

//與vector 區別
//-vector對於頭部插入刪除較沒效率 數據量越大效率越低
//-deque相比之下對於頭部插入刪除比vector 快速
//-vector訪問元素的速度比deque 快速 此現象和兩者的內部實現有關

void printDeque(const deque<int>& d) {		//加const 防止容器中數據被更改
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}

//------------------------------------------------------
//構造函數
/*
deque<T> deqT;				//默認構造型式
deque(beg, end);			//構造函數將[beg, end] 區間中的元素拷貝給本身
deque(n, elem)				//構造函數將n 個elem拷貝給本身
deque(const deque &deq);	//拷貝構造函數
*/
void test01() {
	deque<int>d1;
	for (int i = 1; i <= 10; i++) {
		d1.push_back(i * 10);
	}
	printDeque(d1);

	deque<int>d2(d1.begin(), d1.end());
	printDeque(d2);

	deque<int>d3(10, 87);
	printDeque(d3);

	deque<int>d4(d3);
	printDeque(d4);

}

//------------------------------------------------------
//賦值操作
/*
deque& operator = (const deque &deq);	//重載等號操作符
assign(beg, end);						//將[beg, end]區間的數據拷貝賦值給本身
assign(n, elem);						//將n個elem拷貝賦值給本身
*/
void test02() {
	deque<int>d1;
	for (int i = 1; i <= 10; i++) {
		d1.push_back(i * 10);
	}
	printDeque(d1);

	//賦值
	//deque& operator = (const deque &deq);	//重載等號操作符
	deque<int>d2;
	d2 = d1;
	printDeque(d2);

	//assign(beg, end);		//將[beg, end]區間的數據拷貝賦值給本身
	deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	printDeque(d3);

	//assign(n, elem);		//將n個elem拷貝賦值給本身
	deque<int>d4;
	d4.assign(10, 30);
	printDeque(d4);

}

//------------------------------------------------------
//大小操作
//deque沒有容量概念 其數據類型可持續擴張
/*
empty();				判斷容器是否為空
size();					返回容器中元素個數
resize(num);		-重新指定容器長度為num 若容器變成則以 默認值 0 填充新位置
					-若容器變短 末尾超出長度的元素被刪除
resize(num, elem);	-重新指定容器長度為num 若容器變成則以   elem   填充新位置
					-若容器變短 末尾超出長度的元素被刪除
*/
void test03() {
	deque<int>d1;
	for (int i = 1; i <= 10; i++) {
		d1.push_back(i * 10);
	}
	printDeque(d1);

	if (d1.empty()) {		//為真 代表容器為空
		cout << "d1為空" << endl;
	}
	else {
		cout << "d1不為空" << endl;
		cout << "大小為: " << d1.size() << endl;
	}

	//重新指定大小
	d1.resize(15);
	printDeque(d1);

	d1.resize(20, 33);
	printDeque(d1);
}

//------------------------------------------------------
//插入和刪除
/*
push_back(ele);					-尾部插入元素ele
push_front(ele);				-頭部插入元素ele
pop_back();						-最尾刪除元素一個
pop_front();					-最頭刪除元素一個

insert(pos, ele);				-迭代器指向位置pos 插入元素 ele
insert(pos, int count, ele);	-迭代器指向位置pos 插入元素 ele 插入count 個
insert(pos, start, end);		-迭代器指向位置pos 插入start 到 end 之間的元素
erase(pos);						-刪除迭代器指向的元素 返回下一個數據的位置
erase(start, end);				-刪除迭代器 start 到 end 之間的元素 返回下一個數據的位置
clear();						-刪除容器中所有元素
*/
void test04() {
	deque<int>d1;
	for (int i = 1; i <= 10; i++) {
		d1.push_back(i * 10);
	}
	printDeque(d1);

	d1.push_back(87);	//尾部插入元素ele
	d1.push_front(87);	//頭部插入元素ele
	printDeque(d1);
	d1.pop_back();		//最尾刪除元素一個
	d1.pop_front();		//最頭刪除元素一個
	printDeque(d1);

	d1.insert(d1.begin()+5, 99999);		//迭代器指向位置pos 插入元素 ele
	printDeque(d1);
	d1.erase(d1.begin() + 5);			//刪除迭代器指向的元素 返回下一個數據的位置
	printDeque(d1);

	deque<int>d2;
	for (int i = 1; i <= 5; i++) {
		d2.push_back(i * 100);
	}
	printDeque(d2);

	d1.insert(d1.begin() + 5, 3, 4444 );		//迭代器指向位置pos 插入元素 4444 插入3 個
	printDeque(d1);
	d1.erase(d1.begin() + 5, d1.begin()+8);		//刪除迭代器指向的區間 返回下一個數據的位置
	printDeque(d1);

	d1.insert(d1.begin() + 5, d2.begin(), d2.end());	//迭代器指向位置pos 插入start 到 end 之間的元素
	printDeque(d1);

	d1.clear();
	printDeque(d1);
}

//------------------------------------------------------
//數據存取
/*
at(int idx);	//返回索引idx所指的數據
operator[];		//返回索引idx所指的數據
front();		//返回容器第一個數據元素
back();			//返回容器最後一個數據元素
*/
void test05() {
	deque<int>d1;
	for (int i = 1; i <= 10; i++) {
		d1.push_back(i * 10);
	}
	printDeque(d1);

	//at(int idx);	//返回索引idx所指的數據
	for (int i = 0; i < d1.size(); i++) {
		cout << d1.at(i) << "  ";
	}
	cout << endl;

	//operator[];		//返回索引idx所指的數據
	for (int i = 0; i < d1.size(); i++) {
		cout << d1[i] << "  ";
	}
	cout << endl;

	cout << "第一元素:  " << d1.front()<< endl;
	cout << "末尾元素:  " << d1.back() << endl;

}

//------------------------------------------------------
//排序操作
//sort(iterator beg, iterator end);	//對 beg~end 區間內元素進行排序

void test06() {
	deque<int>d1;
	for (int i = 1; i <= 10; i++) {
		d1.push_back(rand()%100+1);
	}
	printDeque(d1);

	sort(d1.begin(), d1.end());	//排序操作
	cout << "排序後" << endl;
	printDeque(d1);
}
//------------------------------------------------------

int main() {
	//照顧一下等等會用到的隨機數
	srand((unsigned int)time(NULL));

	//構造函數
	//test01();

	//賦值操作
	//test02();

	//大小操作
	//test03();

	//插入和刪除
	//test04();

	//數據存取
	//test05();

	//排序操作
	//test06();

	system("pause");
	return 0;
}
