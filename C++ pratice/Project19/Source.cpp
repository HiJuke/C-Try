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

// STL 案例1 評委打分
/*
1. 創建五名選手 放到vector
2. 遍歷vector容器 取出每一個選手 fot循環 把十個打分分存到deque容器中
3. sort算法對分數排序 去除最高分最低分
4. deque容器 遍歷一遍 累加總分
5. 獲取平均分
*/

class Person {
public:
	Person(string name, int score) {
		this->m_name = name;
		this->m_score = score;
	}
	string m_name;
	int m_score;	//平均分
};

//這就是遍歷功能 我寫出來是為了糾錯 最後才察覺到
void printPerson(const vector<Person>& v) {		//加const 防止容器中數據被更改
	for (vector<Person>::const_iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it).m_name << "  " << (*it).m_score << endl;
	}
	cout << endl;
}

void createPerson(vector<Person>& v) {
	string nameSeed = "12345";
	//5人
	for (int i = 0; i < 5; i++) {
		string name = "Player";
		name += nameSeed[i];

		int score = 0;

		Person p(name, score);
		v.push_back(p);
	}
}

void setScore(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		//將分數放入deque容器
		deque<int>d1;
		for (int i = 1; i <= 10; i++) {
			d1.push_back(rand() % 100 + 1);
		}

		//排序並顯示去頭去尾的評分
		cout << (*it).m_name << ": ";
		sort(d1.begin(), d1.end());	//排序操作
		d1.pop_back();	//去尾
		d1.pop_front();	//去頭
		printDeque(d1);

		//取平均並顯示
		int sum = 0;
		for (deque<int>::const_iterator dit = d1.begin(); dit != d1.end(); dit++) {
			sum += *dit;
		}
		int avg = sum / d1.size();
		it->m_score = avg;
		cout << "總分: " << sum << "\t平均分: " << it->m_score << endl;
	}
}


void GameMenu() {
	vector<Person> vP;
	createPerson(vP);
	printPerson(vP);
	setScore(vP);
	cout << endl;
	printPerson(vP);
}


int main() {
	//照顧一下等等會用到的隨機數
	srand((unsigned int)time(NULL));

	GameMenu();



	system("pause");
	return 0;
}
