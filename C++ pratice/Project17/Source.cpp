#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include <fstream>	//	文件操作系統頭文件
#include <vector>
#include <algorithm>

using namespace std; 


//vector容器
/*
vector數據結構 跟 數組很類似 也稱為 單端數組
數組是靜態空間 vector可以動態擴展
* 動態擴展:  不是在原空間後接續新空間  而是找更大的空間將原數據拷貝進去  釋放原空間
* vector容器的迭代器是支持隨機訪問的迭代器
*/
void printVector(vector<int>v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//------------------------------------------------------
//構造函數
/*
vector<T> v;					//採用模板實現類實現  默認構造函數
vector(v.begin(), v.end() );	//將v[begin(), end()] 區間的元素拷貝給本身
vector( n, elem);				//構造函數將n 個elem 拷貝給本身
vector( const vector &vec);		//拷貝構造函數
*/
void test01() {
	vector<int> v1;		//默認構造 無參構造
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	//通過區間方式構造
	vector<int>v2(v1.begin(), v1.end());
	printVector(v2);	//成功拷貝v1 begin 到 v1 end

	//將n 個elem 拷貝給本身
	vector<int>v3(7, 20);	//拷貝七個20
	printVector(v3);

	//拷貝構造函數
	vector<int>v4(v3);
	printVector(v4);	//拷貝v3
}

//------------------------------------------------------
//賦值操作
/*
vector& operator = (const vector &vec);	//重載等號操作符
assign(beg, end);						//將[beg, end]區間的數據拷貝賦值給本身
assign(n, elem);						//將n個elem拷貝賦值給本身
*/
void test02() {
	vector<int> v1;		//默認構造 無參構造
	for (int i = 0; i < 10; i++) {
		v1.push_back(i*i);
	}
	printVector(v1);

	//賦值
	//vector& operator = (const vector & vec);	//重載等號操作符
	vector<int> v2;
	v2 = v1;			
	printVector(v2);	

	//assign(beg, end);		//將[beg, end]區間的數據拷貝賦值給本身
	vector<int> v3;
	v3.assign(v1.begin(), v1.end());
	printVector(v3);

	//assign(n, elem);		//將n個elem拷貝賦值給本身
	vector<int> v4;
	v4.assign(10, 300);
	printVector(v4);
}

//------------------------------------------------------
//容量和大小
/*
empty();				判斷容器是否為空
capacity();				容器的容量
size();					返回容器中元素個數
resize(int num);		-重新指定容器長度為num 若容器變成則以 默認值 0 填充新位置
						-若容器變短 末尾超出長度的元素被刪除						
resize(int num, elem);	-重新指定容器長度為num 若容器變成則以   elem   填充新位置
						-若容器變短 末尾超出長度的元素被刪除	
*/
void test03() {
	vector<int> v1;		//默認構造 無參構造
	for (int i = 0; i < 10; i++) {
		v1.push_back(i * i);
	}
	printVector(v1);

	if (v1.empty()) {		//為真 代表容器為空
		cout << "v1為空" << endl;
	}
	else {
		cout << "v1不為空" << endl;
		cout << "容量為: " << v1.capacity() << endl;
		cout << "大小為: " << v1.size() << endl;
	}

	//重新指定大小
	v1.resize(15);
	printVector(v1);

	v1.resize(20, 33);
	printVector(v1);
}

//------------------------------------------------------
//插入和刪除
/*
push_back(ele);										//尾部插入元素ele
pop_back();											//最尾刪除元素一個
insert(const_iterator pos, ele);					//迭代器指向位置pos 插入元素 ele
insert(const_iterator pos, int count, ele);			//迭代器指向位置pos 插入元素 ele 插入count 個
erase(const_iterator pos);							//刪除迭代器指向的元素
erase(const_iterator start, const_iterator end);	//刪除迭代器 start 到 end 之間的元素
clear();											//刪除容器中所有元素
*/
void test04() {
	vector<int> v1;		//默認構造 無參構造
	//尾部插入元素ele
	for (int i = 0; i < 10; i++) {
		v1.push_back(i * 10);
	}
	printVector(v1);

	//最尾刪除元素
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	printVector(v1);

	//插入元素
	v1.insert(v1.begin(), 222);	//頭部插入222
	printVector(v1);

	v1.insert(v1.begin(), 3, 99);	//頭部插入3個 99
	printVector(v1);

	//刪除
	v1.erase(v1.begin());		//刪除頭部一個
	printVector(v1);

	v1.erase(v1.begin(), v1.begin()+3);	//刪除頭部三個
	printVector(v1);

	//清空
	v1.clear();
	printVector(v1);
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
	vector<int> v1;		//默認構造 無參構造
	for (int i = 0; i < 10; i++) {
		v1.push_back(i * 10);
	}
	printVector(v1);
	
	for (int i = 0; i < 10; i++) {
		cout << v1.at(i) << "\t";					//at(int idx);	//返回索引idx所指的數據
		cout << v1[i] << "   " << endl;				//operator[];	//返回索引idx所指的數據
	}
	cout << "First One Is: " << v1.front() << endl;
	cout << "Latest One Is: " << v1.back() << endl;
}

//------------------------------------------------------
//互換容器
//swap (vec);	//將本身元素與vec 互換
void test06() {
	vector<int> v1;		//默認構造 無參構造
	vector<int> v2;		//默認構造 無參構造
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(10 - i);
	}
	cout << "交換前" << endl;
	printVector(v1);
	printVector(v2);

	cout << "交換後" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}

//實際用途	巧用swap可以收縮內存空間
void test07() {
	vector<int> v;		//默認構造 無參構造
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}
	cout << "V.容量 = " << v.capacity() << endl;	//容量
	cout << "V.大小 = " << v.size() << endl;		//大小
	cout << endl;

	v.resize(3);	//重新指定大小
	cout << "V.容量 = " << v.capacity() << endl;	//容量
	cout << "V.大小 = " << v.size() << endl;		//大小
	cout << endl;
	//可見空間浪費超慘烈

	//巧用swap可以收縮內存空間
	vector<int>(v).swap(v);
	cout << "V.容量 = " << v.capacity() << endl;	//容量
	cout << "V.大小 = " << v.size() << endl;		//大小
	cout << endl;
}

//------------------------------------------------------
//預留空間
//reserve(int len);	//容器預留len個元素長度 預留位置不初始化 元素不可訪問
void test08() {
	//沒有預留空間
	vector<int> v1;		//默認構造 無參構造
	int num1 = 0;	//統計開闢次數
	int* p1 = NULL;
	for (int i = 0; i < 100000; i++) {
		v1.push_back(i);

		if (p1 != &v1[0]) {	//如果首地址變化 意味著重新開闢內存 所以統計的開闢次數要++
			p1 = &v1[0];
			num1++;
		}
	}
	cout << "沒預留空間的開闢次數 = \t" << num1 << endl;

	//有預留空間
	vector<int> v2;		//默認構造 無參構造
	v2.reserve(100000);	//預留空間
	int num2 = 0;	//統計開闢次數
	int* p2 = NULL;
	for (int i = 0; i < 100000; i++) {
		v2.push_back(i);

		if (p2 != &v2[0]) {	//如果首地址變化 意味著重新開闢內存 所以統計的開闢次數要++
			p2 = &v2[0];
			num2++;
		}
	}
	cout << "有預留空間的開闢次數 = \t" << num2 << endl;


}
//------------------------------------------------------


int main() {

	//vector容器
	//構造函數
	//test01();
	
	//賦值操作
	//test02();
	
	//容量和大小
	//test03();
	
	//插入和刪除
	//test04();
	
	//數據存取
	//test05();
	
	//互換容器
	//test06();
	//test07();

	//預留空間
	test08();


	system("pause");
	return 0;
}