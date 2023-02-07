#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include <fstream>	//	文件操作系統頭文件
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

//Stack  (FILO 先進後出)	記得#include <stack>
/*
構造函數:
	stack<T> stk;				//stack採用模板類實現 stack對象的默認構造形式
	stack(const stack &stk);	//拷貝構造函數
賦值操作:
	stack& operator = (const stack & stk);	//重載等號操作符
數據存取:
	push(elem);		//向棧頂添加元素
	pop();			//從棧頂移除第一個元素
	top();			//返回棧頂元素
大小操作:
	empty();		//是否為空
	size();			//大小
*/

void testStack() {

	stack<int>s;

	//入棧
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	cout << "棧大小: " << s.size() << endl;

	//設定一回圈 只要棧頂不為空 查看棧頂 並出棧
	while (!s.empty()) {	//是否為空
		cout << "棧頂元素: " << s.top() << endl;
		s.pop();	//出棧
	}

	cout << "棧大小: " << s.size() << endl;
}

//----------------------------------------------------------------

//Queue  (FIFO 先進先出)	記得#include <queue>  就是排隊喇
/*
構造函數:
	queue<T> que;				//queue採用模板類實現 queue對象的默認構造形式
	queue(const queue &que);	//拷貝構造函數
賦值操作:
	queue& operator = (const queue &que);	//重載等號操作符
數據存取:
	push(elem);		//向隊尾添加元素
	pop();			//從隊首移除第一個元素
	back();			//返回最後一個元素
	front();		//返回最先一個元素
大小操作:
	empty();		//是否為空
	size();			//大小
*/

class Person {
public:
	Person(string name, int age) {
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};

void testQueue() {
	queue<Person> q;

	Person p1("Member A", 23);
	Person p2("Member B", 44);
	Person p3("Member C", 62);
	Person p4("Member D", 35);

	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	
	cout << "隊列大小: " << q.size() << endl;

	while (!q.empty()) {	//是否為空
		cout << "隊伍首位: " << q.front().m_name << "\t年齡: " << q.front().m_age << endl;
		cout << "隊伍末位: " << q.back().m_name << "\t年齡: " << q.back().m_age << endl;
		q.pop();	//首位離隊
		cout << "---離隊程序已執行---" << endl;
	}

	cout << "隊列大小: " << q.size() << endl;
}

int main() {
	//照顧一下等等會用到的隨機數
	srand((unsigned int)time(NULL));

	testStack();

	cout << "---------------------------------------------------------------------" << endl;

	testQueue();

	system("pause");
	return 0;
}
