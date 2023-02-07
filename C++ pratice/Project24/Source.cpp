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
#include <set>
#include <map>

using namespace std;

//案例 員工分組
//描述
/*
-新員工十名 進入公司後需指派員工在哪個部門工作
-員工信息: 姓名 工資組成;  部門分為: 策畫 美術 研發
-隨機給十名員工分配部門與工資
-通過multimap 進行信息插入 key為部門標號 value為員工
-分部門顯示員工信息
*/

//步驟
/*
1. 創建十名員工 放入vector
2. 遍歷vector容器 取出每個員工隨機分組
3. 分組後 將員工部門編號作為key 員工做為value 放入multimap容器中
4. 分部門顯示員工信息
*/

//員工
class employee {
public:
	employee(string name, int price) {
		this->m_name = name;
		this->m_price = price;
	}
	string m_name;
	int m_price;
};

//創建十名員工
void CreateEmployee(vector<employee>& v) {
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++){
		string tName = "Employee";
		tName += nameSeed[i];
		employee E(tName, rand() % 30000 + 25000);
		v.push_back(E);
	}
	/*
	employee E01("Employee A", rand() % 30000 + 25000);
	employee E02("Employee B", rand() % 30000 + 25000);
	employee E03("Employee C", rand() % 30000 + 25000);
	employee E04("Employee D", rand() % 30000 + 25000);
	employee E05("Employee E", rand() % 30000 + 25000);
	employee E06("Employee F", rand() % 30000 + 25000);
	employee E07("Employee G", rand() % 30000 + 25000);
	employee E08("Employee H", rand() % 30000 + 25000);
	employee E09("Employee I", rand() % 30000 + 25000);
	employee E10("Employee J", rand() % 30000 + 25000);

	v.push_back(E01);
	v.push_back(E02);
	v.push_back(E03);
	v.push_back(E04);
	v.push_back(E05);
	v.push_back(E06);
	v.push_back(E07);
	v.push_back(E08);
	v.push_back(E09);
	v.push_back(E10);
	*/
}

//遍歷vector
void printEmployee(const vector<employee>& v) {
	for (vector<employee>::const_iterator it = v.begin(); it != v.end(); it++) {
		cout << "姓名: " << it->m_name << "\t  薪資: " << it->m_price << endl;
	}
	cout << endl;
}

//將員工分組
void setGroup(const vector<employee>& v, multimap<int, employee>& m) {
	for (vector<employee>::const_iterator it = v.begin(); it != v.end(); it++) {
		m.insert(make_pair(rand() % 3 + 1, *it));
	}
}

//遍歷multimap
void printMultimap(const multimap<int, employee>& m) {
	//for (multimap<int, employee>::const_iterator it = m.begin(); it != m.end(); it++) {
	//	cout << "姓名: " << it->second.m_name << "\t  薪資: " << it->second.m_price;
	//
	//統計部門人數加總
	//三部門人數 計畫 美術 研發
	cout << "策畫部門人數: " << m.count(1) << endl;
	multimap<int, employee>::const_iterator it = m.find(1);
	for (int i = 0; it != m.end() && i < m.count(1); it++, i++) {
		cout << "姓名: " << it->second.m_name << "\t  薪資: " << it->second.m_price << endl;
	}
	cout << endl;

	cout << "美術部門人數: " << m.count(2) << endl;
	it = m.find(2);
	for (int i = 0; it != m.end() && i < m.count(2); it++, i++) {
		cout << "姓名: " << it->second.m_name << "\t  薪資: " << it->second.m_price << endl;
	}
	cout << endl;

	cout << "研發部門人數: " << m.count(3) << endl;
	it = m.find(3);
	for (int i = 0; it != m.end() && i < m.count(3); it++, i++) {
		cout << "姓名: " << it->second.m_name << "\t  薪資: " << it->second.m_price << endl;
	}
	cout << endl;
}

void CompanySystem() {
	//建立vector
	vector<employee> v;
	//創建十名員工
	CreateEmployee(v);
	printEmployee(v);

	//將員工分組 部門編號作為key 員工做為value 放入multimap容器中
	multimap<int, employee> m;
	setGroup(v, m);
	
	//遍歷multimap 分部門顯示員工
	printMultimap(m);
}

int main() {
	//照顧一下等等會用到的隨機數
	srand((unsigned int)time(NULL));

	CompanySystem();


	system("pause");
	return 0;
}

