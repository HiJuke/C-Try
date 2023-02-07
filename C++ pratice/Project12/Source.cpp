#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include <fstream>	//	文件操作系統頭文件

#define MAX 1000

using namespace std;

//文件操作	標頭需加入頭文件<fstream>
//1. 文本文件		以文本的ASCII形式存儲在計算機中
//2. 二進制文件		以文本的二進制形式存儲在計算機中  一般不能直接讀懂

//* ofstream:	寫入操作
//* ifstream:	讀取操作
//* fstream:	讀寫操作

//------------------------------------------------------
//文本文件 寫文件 五步驟
void test01() {
	//1. 包含頭文件<fstream>
	//2. 創建流對象
	ofstream ofs;
	//3. 指定打開方式
	ofs.open("test.txt", ios::out);	// (文件名與路徑, 操作方式)
	//4. 寫內容
	ofs << "Name --- Peter " << endl;
	ofs << "Male" << endl;
	ofs << "Age 28" << endl;
	//5. 關閉文件
	ofs.close();
}
//執行完test01後 可在專案資料夾找到test.txt

//------------------------------------------------------
//文本文件 讀文件 五步驟
void test02() {
	//1. 包含頭文件<fstream>
	//2. 創建流對象
	ifstream ifs;
	//3. 指定打開方式 打開並判斷是否打開成功
	ifs.open("test.txt", ios::in);	// (文件名與路徑, 操作方式)
	if (!ifs.is_open()) {	//is_open() 會判斷文件是否打開 有開回復true 沒有則是false
		cout << "開啟失敗" << endl;
		return;
	}
	//4. 讀內容
	//第一種
	/*
	char buf[1024] = { 0 };
	while (ifs >> buf) {
		cout << buf << endl;
	}
	*/
	//第二種
	/*
	char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf))) {
		cout << buf << endl;
	}
	*/
	//第三種
	/*
	string buf;
	while ( getline(ifs, buf)) {
		cout << buf << endl;
	}
	*/
	//第四種	不推薦
	/*
	char c;
	while ( (c = ifs.get()) != EOF) {	//EOF end of file
		cout << c ;
	}*/

	//5. 關閉文件
	ifs.close();
}

//------------------------------------------------------
//二進制文件 寫文件 五步驟	(打開只要為 ios::binary )
//主要利用流對象調用成員函數 write
class Person1 {
public:
	char m_Name[64];
	int m_Age;
};
void test03() {
	//1. 包含頭文件
	//2. 創建流對象
	ofstream ofs;
	//ofstream ofs("person.txt", ios::out | ios::binary);	//這作法將步驟2+3合一
	//3. 打開文件
	ofs.open("person.txt", ios::out | ios::binary);
	//4. 寫入文件
	Person1 p = { "Peter", 28 };
	ofs.write( (const char*)&p , sizeof(Person1) );
	//5. 關閉文件
	ofs.close();
}
//打開文件會看到很多空白或是亂碼 這是二進制文件的問題 只要能用二進制的讀取讀到就沒問題 先不用管他

//------------------------------------------------------
//二進制文件 讀文件
void test04() {
	//1. 包含頭文件<fstream>
	//2. 創建流對象
	ifstream ifs;
	//3. 指定打開方式 打開並判斷是否打開成功
	ifs.open("person.txt", ios::in | ios::binary);	// (文件名與路徑, 操作方式)
	if (!ifs.is_open()) {	//is_open() 會判斷文件是否打開 有開回復true 沒有則是false
		cout << "開啟失敗" << endl;
		return;
	}
	//4. 讀內容
	Person1 p;
	ifs.read((char*)&p, sizeof(Person1));
	cout << p.m_Name << "\t" << p.m_Age << endl;
	//5. 關閉文件
	ifs.close();
}

//------------------------------------------------------



int main() {
	srand((unsigned int)time(NULL));

	//文本文件 寫文件
	//test01();

	//文本文件 讀文件
	//test02();

	//二進制文件 寫文件
	//test03();

	//二進制文件 讀文件
	//test04();

	system("pause");
	return 0;
}