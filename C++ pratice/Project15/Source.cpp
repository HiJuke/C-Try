#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include <fstream>	//	文件操作系統頭文件
#include <vector>
#include <algorithm>

using namespace std;\

//STL
/*
軟體界一直希望建立一種可重複利用的東西
C++的面向對象 泛型編程思想 目標就是複用性提升
大多情況 數據結構和算法都未能有一套標準 導致被迫從事大量重複工作
為建立數據結構和算法的一套標準 建立STL
*/
/*
STL (Standard Template Library, 標準模板庫)
STL 廣義上分為 容器(container) 算法(algorithm) 迭代器(itierator)
容器 算法 兩者透過迭代器無縫連接
STL 幾乎所有代碼都採用 模板類 或是 模板函數
*/
/*
STL 六大組件: 容器 算法 迭代器 仿函數 適配器(配接器) 空間配置器
1. 容器:		各種數據結構 如vector list deque set map...
2. 算法:		各種常用算法 如sort find copy for_each...
3. 迭代器:		容器與算法的接合劑
4. 仿函數:		類似函數 作為算法的某種策略
5. 適配器:		用來修飾 容器 仿函數 迭代器接口 的東西
6. 空間配置器:	空間配置與管理
*/

//------------------------------------------------------
//vector存放內置數據類型
//容器: vector		算法: for_each		迭代器: vector<int> itierator
void TempPrint(int val) { cout << val << endl; }
void test01() {
	//創建一個vector容器
	vector<int> v;

	//向容器中插入數據
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);

	//第一種遍歷方式
	//通過迭代器訪問容器中數據
	cout << "\tWay One" << endl;
	vector<int>::iterator itBegin = v.begin();	//begin 起始迭代器 指向容器中第一個元素
	vector<int>::iterator itEnd = v.end();		//end 結束迭代器 指向容器中最後一個元素的下一個位置
	while (itBegin != itEnd) {
		cout << *itBegin << endl;
		itBegin++;
	}

	//第二種遍歷方式
	cout << "\tWay Two" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}

	//第三種遍歷方式	利用STL提供便利算法 ( 須包含 #include <algorithm> )
	cout << "\tWay Three" << endl;
	for_each(v.begin(), v.end(),TempPrint);	//開始點 結束點 TempPrint則是前面定義的函數的函數名
	//此行達成 函數先不調用 在for_each執行時才依序調用
}

//------------------------------------------------------
//vector存放自訂數據類型
class Person1 {
public:
	Person1(string name, int age) {
		m_Age = age;
		m_Name = name;
	}
	string m_Name;
	int m_Age;
};
void test02() {
	vector<Person1>v;

	Person1 p1("Chandler", 35 );
	Person1 p2("Tony", 38 );
	Person1 p3("Michel",26 );
	Person1 p4("Liya",33 );
	Person1 p5("Leom",45 );

	//向容器中插入數據
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//遍歷容器中數據
	for (vector<Person1>::iterator it = v.begin(); it != v.end(); it++) {
		//cout << (*it).m_Name << "\t" << (*it).m_Age <<endl;
		cout << it->m_Name << "\t" << it->m_Age << endl;
	}
}
//vector存放自訂數據類型 指針
void test03() {
	vector<Person1*>v;

	Person1 p1("Peter", 35);
	Person1 p2("Tony", 38);
	Person1 p3("Michel", 26);
	Person1 p4("Liya", 33);
	Person1 p5("Leon", 45);

	//向容器中插入數據
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	//遍歷容器中數據
	for (vector<Person1*>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it)->m_Name << "\t" << (*it)->m_Age <<endl;
		//cout << it->m_Name << "\t" << it->m_Age << endl;
	}
}

//------------------------------------------------------
//vector容器嵌套容器

void test04() {
	vector<vector<int>>v;	//vector容器嵌套容器

	//創建小容器
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	vector<int>v5;

	//向小容器中添加數據
	for (int i = 0; i < 4; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
		v5.push_back(i + 5);
	}

	//向小容器插入到大容器中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);

	//通過大容器 把所有數據遍歷一遍
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		//(*it)也是容器 所以也要遍歷
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
			cout << *vit << " ";
		}
		cout << endl;
	}
}

//------------------------------------------------------


//------------------------------------------------------


//------------------------------------------------------



int main() {
	//vector存放內置數據類型
	//test01();

	//vector存放自訂數計類型
	//test02();
	//test03();

	//vector容器嵌套容器
	test04();

	system("pause");
	return 0;
}