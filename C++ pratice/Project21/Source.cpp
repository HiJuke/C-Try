#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include <fstream>	//	文件操作系統頭文件
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>

using namespace std;

class Person {
public:
	Person(string name, int age, int height) {
		this->m_name = name;
		this->m_age = age;
		this->m_Height = height;
	}
	string m_name;
	int m_age;
	int m_Height;
};
//----------------------------------------------------------------

//list 容器			include <list>
//就是鍊表 串列記得不 
//優點: 可以對任意位置快速插入或刪除元素
//缺點: 遍歷元素速度慢於數組  佔用空間也較大 (需要多一組空間儲存下一個元素的位置 有些會需要兩組空間 前後兩個元素位置都存)
//list 只支持 ++ 與 -- 不支持+1+2等隨機訪問 要就自己寫重載
void printList(const list<int>&L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}

//----------------------------------------------------------------
//構造函數
/*
list<T> list;			//list採用模板類實現 對象的默認構造形式
list(beg, end);			//構造函數將(beg, end)區間的元素拷貝給本身
list(n, elem);			//構造函數將n 個 elem 拷貝給本身
list(const list &list);	//拷貝構造函數
*/
void test01() {
	list<int>L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	list<int>L2(L1.begin(), L1.end());
	printList(L2);

	list<int>L3(L2);
	printList(L3);

	list<int>L4(5, 22);
	printList(L4);
}

//----------------------------------------------------------------
//賦值與交換
/*
assign(beg, end);					//將(beg, end)區間的元素拷貝給本身
assign(n, elem);					//將n 個 elem 拷貝給本身
list& operator(const list &list);	//重載等號操作符
swap(lst);							//將lst與本身元素互換
*/
void test02() {
	list<int>L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	list<int>L2;
	L2 = L1;
	printList(L2);

	list<int>L3;
	L3.assign(L1.begin(), L1.end());
	printList(L3);

	list<int>L4;
	L4.assign(5, 200);
	printList(L4);

	//---------------------------------

	list<int>L5;
	L5.push_back(11);
	L5.push_back(22);
	L5.push_back(33);
	L5.push_back(44);
	L5.push_back(55);
	
	cout << "交換前:" << endl;
	printList(L1);
	printList(L5);

	cout << "交換後: " << endl;
	L1.swap(L5);
	printList(L1);
	printList(L5);
}

//----------------------------------------------------------------
//大小操作
/*
empty();				判斷容器是否為空
size();					返回容器中元素個數
resize(num);		-重新指定容器長度為num 若容器變成則以 默認值 0 填充新位置
					-若容器變短 末尾超出長度的元素被刪除
resize(num, elem);	-重新指定容器長度為num 若容器變成則以   elem   填充新位置
					-若容器變短 末尾超出長度的元素被刪除
*/
void test03() {
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	if (L1.empty()) {		//為真 代表容器為空
		cout << "L1為空" << endl;
	}
	else {
		cout << "L1不為空" << endl;
		cout << "大小為: " << L1.size() << endl;
	}

	//重新指定大小
	L1.resize(10);
	printList(L1);

	L1.resize(15, 33);
	printList(L1);

	cout << "大小為: " << L1.size() << endl;

}

//----------------------------------------------------------------
//插入和刪除
/*
push_back(ele);					-尾部插入元素ele
push_front(ele);				-頭部插入元素ele
pop_back();						-最尾刪除元素一個
pop_front();					-最頭刪除元素一個

insert(pos, ele);				-迭代器指向位置pos 插入元素 ele					返回新元素位置
insert(pos, int count, ele);	-迭代器指向位置pos 插入元素 ele 插入count 個	沒有返回值
insert(pos, start, end);		-迭代器指向位置pos 插入start 到 end 之間的元素	沒有返回值
erase(pos);						-刪除迭代器指向的元素					返回下一個數據的位置
erase(start, end);				-刪除迭代器 start 到 end 之間的元素		返回下一個數據的位置
clear();						-刪除容器中所有元素
remove(elem);					-刪除容器中所有與elem匹配的元素
*/
void test04() {
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	L1.push_front(10);
	L1.push_front(20);
	L1.push_front(30);
	L1.push_front(40);
	printList(L1);
	cout << "-----------------------------------------------------------------------" << endl;

	L1.pop_back();
	L1.pop_front();
	printList(L1);
	cout << "-----------------------------------------------------------------------" << endl;

	L1.insert(L1.begin(), 40);
	L1.insert(L1.end(), 3, 99);
	printList(L1);
	cout << "-----------------------------------------------------------------------" << endl;

	list<int>L2;
	L2.push_back(99);
	L2.push_back(99);
	L1.insert(++L1.begin(), L2.begin(), L2.end());
	printList(L1);
	cout << "-----------------------------------------------------------------------" << endl;

	L1.erase(++(++(++L1.begin())));
	printList(L1);
	L1.erase(++(++(++L1.begin())), --(--(--L1.end())));
	printList(L1);
	cout << "-----------------------------------------------------------------------" << endl;

	L1.remove(99);
	printList(L1);
	L1.clear();
	printList(L1);
	cout << "-----------------------------------------------------------------------" << endl;
}

//----------------------------------------------------------------
//數據存取
/*
front();	//回傳第一個元素
back();		//回傳最後一個元素
*/
void test05() {
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	cout << L1.front() << endl;
	cout << L1.back() << endl;

}
//----------------------------------------------------------------
//反轉和排序
/*
reverse();	//反轉列表
sort();		//鍊表排序
*/
bool DoneSort(int A, int B) {
	return A > B;
}

void test06() {
	list<int>L1;
	L1.push_back(rand()%100+1);
	L1.push_back(rand() % 100 + 1);
	L1.push_back(rand() % 100 + 1);
	L1.push_back(rand() % 100 + 1);
	L1.push_back(rand() % 100 + 1);
	printList(L1);

	//sort(L1.bagin(), L1.end());	不支持隨機訪問的容器 無法使用標準算法
	//不支持隨機訪問迭代器的容器 內部會提供對應的部分算法
	L1.sort();	//升序
	printList(L1);

	L1.sort(DoneSort);	//降序
	printList(L1);

	L1.reverse();	//反轉
	printList(L1);
}

//----------------------------------------------------------------
//排序案例

//指定排序規則
bool SortPerson(Person& PA, Person& PB) {
	//按照年齡 升序
	//return PA.m_age < PB.m_age;

	if (PA.m_age == PB.m_age) {
		return PA.m_Height > PB.m_Height;
	}
	else {
		return PA.m_age < PB.m_age;
	}
}

void test07() {
	list<Person> LP;

	Person P1("HumanA", 35, 168);
	Person P2("HumanB", 45, 175);
	Person P3("HumanC", 45, 181);
	Person P4("HumanD", 76, 192);
	Person P5("HumanE", 45, 165);

	LP.push_back(P1);
	LP.push_back(P2);
	LP.push_back(P3);
	LP.push_back(P4);
	LP.push_back(P5);

	cout << "依年齡排序 年齡相同依身高 排序前: " << endl;
	for (list<Person>::iterator it = LP.begin(); it != LP.end(); it++) {
		cout << "姓名: " << it->m_name << "\t年齡: " << it->m_age << "\t身高: " << it->m_Height << endl;
	}

	cout << "-----------------------------------------------------------------------" << endl;
	LP.sort(SortPerson);
	cout << "依年齡排序後 年齡相同依身高 排序前: " << endl;
	for (list<Person>::iterator it = LP.begin(); it != LP.end(); it++) {
		cout << "姓名: " << it->m_name << "\t年齡: " << it->m_age << "\t身高: " << it->m_Height << endl;
	}

}
//----------------------------------------------------------------








int main() {
	//照顧一下等等會用到的隨機數
	srand((unsigned int)time(NULL));

	//構造函數
	//test01();

	//賦值與交換
	//test02();

	//大小操作
	//test03();
	
	//插入和刪除
	//test04();
	
	//數據存取
	//test05();
	
	//反轉和排序
	//test06();

	//排序案例
	test07();
	




	system("pause");
	return 0;
}
