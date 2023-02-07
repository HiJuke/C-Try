#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include "swap.h"	// 引入自己寫的頭文件以使用內部的 function
#define Day 7	//定義宏常量
//常量定義方式 1. #define 變數 
//常量定義方式 2. const 修飾的變量
using namespace std;

//標示符命名規則
//1.由字母 數字 下畫線構成		abc_abc
//2.首個字母只可為字母或下畫線	_abcabc
//3.區分大小寫					_abc =/= _ABC
//4.不可為關鍵字				不可為 int double 之類的


// function
	/*
	五步驟
	1	返回值類型
	2	函數名
	3	參數表列
	4	函數體語句
	5	return表達式
	*/

int add(int a, int b) {
	int sum = a + b;
	return sum;
}

void swap2(int *p, int *p2) {
	int temp = *p;
	*p = *p2;
	*p2 = temp;
}

void ArrowArrayBubbleSort(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

/*
void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
*/

//--------------------------------------------------------------------------
	//結構體
struct student {
	string name;
	int age;
	int score;
}sss;		//sss為順便創建的結構體變量

struct teacher {
	int id;
	string name;
	int age;
	struct student stu;
};

//結構體做函數參數
void printStuS(struct student s) {
	cout << s.name << "    " << s.age << "    " << s.score << endl;
}

/*
void printStuP(struct student* p) {	
	//使用指針可減少內存空間消耗 也不會複製新的副本
	//p->name = "Michal";	//測試指針於函數可影響實際數值
	cout << p->name << "    " << p->age << "    " << p->score << endl;
}
*/
//結構體+const使用
void printStuP(const student* p) {
	//加入const是為了防止不該改變的數據被更改 若被更改變會報錯
	//p->name = "Michal";	//測試指針於函數可影響實際數值 const保護下便會報錯
	cout << p->name << "    " << p->age << "    " << p->score << endl;
}

int main()
{
	srand((unsigned int)time(NULL));

	/*
	cout << "Hello world" << endl;	//

	int a = 10;
	cout << "a = " << a << endl;

	cout << "-------------------------------------------------------------------------" << endl;	*/
//--------------------------------------------------------------------------
	
	//常量定義方式 
	/*
	//1. #define 變數 
	//Day = 14;		//常量不可修改 此行解除註解便會出錯
	cout << "A week " << Day << " days." << endl;
	//常量定義方式 2. const 修飾的變量
	const int month = 12;
	//month = 24;		//常量不可修改 此行解除註解便會出錯
	cout << "A year " << month << " month." << endl;

	cout << "-------------------------------------------------------------------------" << endl;	*/
//--------------------------------------------------------------------------

	//sizeof
	/*
	cout << "short類型所佔用空間" << sizeof(short) << endl;
	cout << "int類型所佔用空間" << sizeof(int) << endl;
	cout << "long類型所佔用空間" << sizeof(long) << endl;
	cout << "long long類型所佔用空間" << sizeof(long long) << endl;

	cout << "-------------------------------------------------------------------------" << endl;
	*/
//--------------------------------------------------------------------------
	//單精度 float
	/*
	float fi = 3.14f;
	cout << "fi = " << fi << endl;
	//雙精度 double
	double di = 3.1415926;	
	cout << "di = " << di << endl;	//正常輸出只能輸出六位數

	//統計float與double占用的內存空間
	cout << "Size of float: " << sizeof(float) << endl;
	cout << "Size of double: " << sizeof(double) << endl;

	//科學記數法
	float f2 = 3e2;			// 3*10^2
	cout << "f2 = " << f2 << endl;

	float f3 = 3e-2;			// 3*(0.1)^2
	cout << "f3 = " << f3 << endl;

	cout << "-------------------------------------------------------------------------" << endl;	*/
//--------------------------------------------------------------------------
	//char
	/*

	char ch = 'a';	//""錯誤 不可用雙引號 ch = 'abcd'也錯誤 單一字符只能存一個 多個要陣列
	cout << ch << endl;
	cout << sizeof(char) << endl;	//字符型變量所佔內存
	cout << "字符型對應的ASCII碼 " << (int)ch << endl;	//對應ASCII碼 ex: a-97 A-65

	cout << "-------------------------------------------------------------------------" << endl;	*/
//--------------------------------------------------------------------------
	//轉義字符
	/*
	//換行 \n
	cout << "Hello world \n";
	cout << "Hello world \n" << endl;

	//反斜線  \\  
	cout << "\\" << endl;

	//水平制表符 \t 為了可以整齊輸出數據
	cout << "aaaa \t ChickenDinner" << endl;
	cout << "aa \t ChickenDinner" << endl;
	cout << "aaaaaa \t ChickenDinner" << endl;

	cout << "-------------------------------------------------------------------------" << endl;	*/
//--------------------------------------------------------------------------
	//字串
	/*
	//C風格
	char str1[] = "CharOne";
	cout << str1 << endl;

	//C++風格	要在頭部加入#include <string> 才可使用
	string str2 = "CharTwo";
	cout << str2 << endl;

	cout << "-------------------------------------------------------------------------" << endl;	*/
//--------------------------------------------------------------------------
	// bool
	/*
	bool flag = true;
	cout << flag << endl;	// 1

	flag = false;
	cout << flag << endl;	// 0

	cout << "Size of bool: " << sizeof(bool) << endl;

	cout << "-------------------------------------------------------------------------" << endl;	*/
//--------------------------------------------------------------------------
	//輸入
	/*//整型輸入
	int a1 = 0;
	cout << "Key In int number: " << endl;
	cin >> a1;
	cout << a1 << endl;

	//浮點數輸入
	double d1 = 0;
	cout << "Key In double number: " << endl;
	cin >> d1;
	cout << d1 << endl;

	float f1 = 3.14f;
	cout << "Key In float number; " << endl;
	cin >> f1;
	cout << f1 << endl;

	//字符型輸入
	char ch1 = 'a';
	cout << "Key In char world: " << endl;
	cin >> ch1;
	cout << ch1 << endl;
	*/
	/*
	//字串型輸入
	string st = "hello";
	cout << "Key In string world: " << endl;
	cin >> st;
	cout << st << endl;

	//bool
	bool flag1 = false;
	cout << "Key In bool flag number" << endl;
	cin >> flag1;
	cout << flag1 << endl;

	cout << "-------------------------------------------------------------------------" << endl;	*/
//--------------------------------------------------------------------------
	//+-*/	%為取餘數 10%3 = 1
	/*
	==
	!=
	<
	>
	<=
	>=
	*/
	/*
	cout << (20 == 20) << endl;
	cout << (20 != 20) << endl;
	cout << (20 > 20) << endl;
	cout << (20 < 20) << endl;
	cout << (20 >= 20) << endl;
	cout << (20 >= 20) << endl;
	*/

	//cout << "-------------------------------------------------------------------------" << endl;
//--------------------------------------------------------------------------
	//邏輯運算符
	/*
	!	!a a為false !a為true 反之
	&&	and		a&&b ab皆為true才可為true
	||  or		a||b ab其一為true 即為true
	*/
	/*
	int a = 6;
	int b = 5;
	cout << !a << endl;		// 0
	cout << !!a << endl;	// 1

	a = 2;	 b = 0;
	cout << (a && b) << endl;	//0
	a = 2;	 b = 2;
	cout << (a && b) << endl; //1

	a = 2;	b = 0;
	cout << (a || b) << endl;	// 1
	a = 0;	b = 0;
	cout << (a || b) << endl;	// 0
	*/

	//cout << "-------------------------------------------------------------------------" << endl;
//--------------------------------------------------------------------------
	//流程結構 選擇結構 if
	/*
	int a = 5;
	if (a) {
		cout << "A is Real" << endl;
	}
	else {
		cout << "A is Nothing" << endl;
	}
	*/
	/*
	int a = 0;
	if (a) {
		cout << "A is Real" << endl;
	}
	else {
		cout << "A is Nothing" << endl;
	}
	*/
	/*
	int a = 2; int b = 0;
	if (a && b) {
		cout << "AB is Real" << endl;
	}
	else if(a){
		cout << "A is Real" << endl;
	}
	else if (b) {
		cout << "B is Real" << endl;
	}
	else {
		cout << "AB is Nothing" << endl;
	}
	*/

	//cout << "-------------------------------------------------------------------------" << endl;
//--------------------------------------------------------------------------
	//switch
	/*
	int score = 0;
	cout << "Enter your score: " << endl;
	cin >> score;

	switch (score)	//只能判斷整型或字符 不像if能判定大區間 但小區間更精細清晰 執行會比if快點
	{
		case 10:
			cout << "Best score" << endl;
			break;
		case 9:
			cout << "Great score" << endl;
			break;
		case 8:
			cout << "Well score" << endl;
			break;
		case 7:
			cout << "Good score" << endl;
			break;
		case 6:
			cout << "Normal score" << endl;
			break;
		default:
			cout << "Suck" << endl;
			break;
	}


	cout << "-------------------------------------------------------------------------" << endl;
	*/
//--------------------------------------------------------------------------
	//while
	/*
	int i = 0;
	while (i < 10) {
		cout << i << endl;
		i++;
	}

	cout << "-------------------------------------------------------------------------" << endl;
	*/
	
	// do while 
	/*	相比while，do while會先執行一次
	int i = 0;
	do {
		cout << i << endl;
		i++;
	} while (i < 10);
	cout << "-------------------------------------------------------------------------" << endl;
	*/
//--------------------------------------------------------------------------
	//隨機數
	/*
	//int num = rand() % 100; //生成 0~99 之間的隨機數 只有這行會發現每次隨機數都一樣 所以要加入時間序隨機(下面那行) 可以加在開頭即可
	srand((unsigned int)time(NULL)); //加入時間序隨機 必須加在下面那行之前 而且文件開頭需有 #include<ctime> 頭文件 不然time會報錯
 	int num = rand() % 100 + 1;
	cout << num << endl;

	cout << "-------------------------------------------------------------------------" << endl;
	*
	
	//找水仙花數(三位數ABC A^3+B^3+C^3=ABC)
	/*
	int num = 100;
	do {
		int a = num / 100;			//百位數
		int b = (num % 100) / 10;	//十位數
		int c = num % 10;			//個位數

		if (a * a * a + b * b * b + c * c * c == num) {
			cout << num << endl;
		}
		num++;

	} while (num < 1000);
	*/
	
//--------------------------------------------------------------------------
	//for
	/*
	for (int i = 0; i < 10; i++) {
		cout << i << endl;
	}
	*/
	/*
	//找與七有關的數 練習
	for (int i = 1; i <= 100; i++) {
		if (i / 10 == 7 || i % 10 == 7 || i % 7 == 0) {
			cout << i << endl;
		}
	}

	cout << "-------------------------------------------------------------------------" << endl;
	*/
	/*
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << "* ";
		}	
		cout << endl;
	}
	*/

//--------------------------------------------------------------------------
	//continue
	/*跳過本次循環在此行之後的程式 直接執行下一次循環
	for (int i = 0; i < 10; i++) {
		if (i == 2) {
			continue;		// i == 2的時候會跳過此次循環 直接到下一次i=3的循環
		}
		cout << i << endl;
	}
	
	cout << "-------------------------------------------------------------------------" << endl;
	*/
//--------------------------------------------------------------------------
	//goto 別用 容易有bug
	//cout << "-------------------------------------------------------------------------" << endl;
//--------------------------------------------------------------------------
	//數組
	/*
	//1. 數據類型 數組名[長度];
	//2. 數據類型 數組名[長度] = {0,2,4,.....};
	//3. 數據類型 數組名[] = {0,2,4

	int arr1[5] = { 0,2,4,6,8 };
	cout << sizeof(arr1) << endl;					//整個數組所佔空間
	cout << sizeof(arr1[0]) << endl;				//個個元素所占空間
	cout << sizeof(arr1) / sizeof(arr1[0]) << endl;	//數組元素個數
	cout << endl;
	for (int i = 0; i < 5; i++) {
		cout << arr1[i] << endl;
	}

	int arr2[] = { 0,2,4,6,8,22,44,66,88 };

	cout << (int)arr1 << endl;		//數組首地址
	cout << (int)&arr1[0] << endl;	//數組第一元素地址
	cout << (int)&arr1[1] << endl;	//數組第二元素地址

	cout << "-------------------------------------------------------------------------" << endl;
	*/
//--------------------------------------------------------------------------
	//bubble sort
	/*
	int arr[] = { rand() % 100 ,rand() % 100 ,rand() % 100 ,rand() % 100 ,rand() % 100 ,rand() % 100 ,rand() % 100 ,rand() % 100 ,rand() % 100 ,rand() % 100 };
	for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++) {
		for (int j = 0; j < (sizeof(arr) / sizeof(arr[0])); j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++) {
		cout << arr[i] << endl;
	}

	cout << "-------------------------------------------------------------------------" << endl;
	*/
//--------------------------------------------------------------------------
	//二維數組
	/*
	1. 數據類型 數組名[行數][列數];
	2. 數據類型 數組名[行數][列數] = {{數1, 數2},{數3, 數4}..};
	3. 數據類型 數組名[行數][列數] = { 數1 數2 數3 數4};
	4. 數據類型 數組名[ ][列數] = { 數1 數2 數3 數4};
	*/
	/*
	int arr[2][3];
	cout << sizeof(arr) << endl;	//數組大小
	cout << sizeof(arr) / sizeof(arr[0]) << endl;		// 2 數組行數
	cout << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;	// 3 數組列數

	cout << (int)arr << endl;	//數組首部位址
	cout << (int)arr[1] << endl;	// 數組第二行開頭位址
	cout << (int)arr[1][1] << endl;	// 數組第二行二列位址 

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		for (int j = 0; j < sizeof(arr[0]) / sizeof(arr[0][0]); j++) {
			arr[i][j] = i + j;
			cout << arr[i][j];
		}
		cout << endl;
	}
	*/
	/*
	int arr[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	cout << sizeof(arr) / sizeof(arr[0]) << endl;		// 2
	cout << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;	// 3

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		for (int j = 0; j < sizeof(arr[0]) / sizeof(arr[0][0]); j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	*/ 
	/*
	int arr[2][3] = {4,5,6,7,8,9};		// 會自己分為 456 789 兩行
	cout << sizeof(arr) / sizeof(arr[0]) << endl;		// 2
	cout << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;	// 3

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		for (int j = 0; j < sizeof(arr[0]) / sizeof(arr[0][0]); j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	*/
	/*
	int arr[][3] = {4,5,6,7,8,9};		//有設定列數就可以自己分辨行數
	cout << sizeof(arr) / sizeof(arr[0]) << endl;		// 2
	cout << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;	// 3

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		for (int j = 0; j < sizeof(arr[0]) / sizeof(arr[0][0]); j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}

	cout << "-------------------------------------------------------------------------" << endl;
	*/
//--------------------------------------------------------------------------
	// function
	/*
	五步驟
	1	返回值類型
	2	函數名
	3	參數表列
	4	函數體語句
	5	return表達式
	*/
	/*
	int ad = add(22, 30);	//在第26行 main文件之前
	cout << ad << endl;

	cout << "-------------------------------------------------------------------------" << endl;
	*/
	/*
	int a = 20;
	int b = 35;
	swap(a, b);
	cout << a << endl;
	cout << b << endl;
	*/
	/*
	int a = 20;
	int b = 35;
	swap(a, b);	//從其他文件取得function
	*/
//--------------------------------------------------------------------------
	//指針
	/*
	通過指針訪問內存地址
	
	int a = 20;
	int* p = &a;	//建立指針p指向a的位址
	cout << &a << endl;
	cout << p << endl;

	指針前加一個*代表解引用，找到指針指向的內存中的數據
	cout << *p << endl; // 此時會輸出的是a的20
	*p = 5500;	//直接修改*p數據 就會直接修改a
	cout << a << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	*/
	/*
	int a = 20;
	int* p = &a;	//建立指針p指向a的位址

	cout << *p << endl;
	cout << sizeof(p) << endl;
	//存指針不需要太多空間
	cout << sizeof(int*) << endl;
	cout << sizeof(float*) << endl;
	cout << sizeof(double*) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(*p) << endl;
	*/
	/*
	//空指針 用於給指針變量初始化
	//空指針 不可進行訪問
	int* p = NULL;
	// *p = 200;	 //執行此行便會出錯 因為空指針NULL會指向系統占用的內存 不允許訪問

	//野指針 (一種錯誤)
	int* p = (int*)0x1100;	//可編譯 但隨便指向的內存不能使用的 如果使用便會執行失敗
	//務必避免使用
	//空指針與野指針都不是經過正式申請的空間 所以請避免引用
	*/
//--------------------------------------------------------------------------
	//const修飾指針
	/*
	const修飾指針 常量指針
	const修飾常量 指針常量
	const即修飾指針 又修飾常量
	*/
	/*
	int a = 10;
	int b = 10;
	int* p = &a;
	
	const int* p = &a;	//常量指針 特點: 指針的指向可修改 但指針指向的數不可改
	*p = 20;	//錯誤 指針指向的數值不可改
	p = &b;		//可執行 指針指向可修改
	
	int* const p = &a;	//指針常量 特點: 指針指向不可改 但指針指向的數可改
	*p = 20;	//可執行 指針指向的數值可改
	p = &b;		//錯誤 指針指向不可修改

	const int* const p = &a;	//修飾常量 特點: 指針指向不可改 指針指向的數不可改
	*p = 20;	//錯誤 指針指向的數值不可改
	p = &b;		//錯誤 指針指向不可修改
	
	cout << "-------------------------------------------------------------------------" << endl;
	*/
//--------------------------------------------------------------------------
	//指針與數組	指針與函數
	/*
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = arr;	//指針指向arr數組首位地址
	cout << *p << endl;	//1
	p++;
	cout << *p << endl;	//2

	int* p2 = arr;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		cout << *p2 << endl;
		p2++;
	}

	cout << "-------------------------------------------------------------------------" << endl;
	*/
	/*
	int a = 10;
	int b = 32;
	swap2(&a, &b);
	cout << a << endl;
	cout << b << endl;
	//這回的函數真把數字改了 沒用指標只傳變數無法如此
	*/
	/*
	int arr[10] = { 4,2,7,9,10,5,1,8,3,6 };
	int* p = arr;	//指針指向arr數組首位地址
	int* p2 = p;	//兩個指向相同位置的指標
	cout << p << p2 << endl;
	ArrowArrayBubbleSort(p, sizeof(arr) / sizeof(arr[0]));	//適用指標array的bubble sort
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		cout << arr[i] << endl;
		cout << *p2 << endl;
		p2++;
	}
	*/
//--------------------------------------------------------------------------
	//結構體
	/*
	struct student {
		string name;
		int age;
		int score;
	};
	*/
	/*
	struct student s1;	//文件首建立的結構體
	s1.name = "Leon";
	s1.age = 24;
	s1.score = 990;
	cout << s1.name << "    " << s1.age << "    " << s1.score << endl;

	struct student s2 = { "Peter", 20, 870 };
	cout << s2.name << "    " << s2.age << "    " << s2.score << endl;

	//建立結構體時順便建立的變量 見文件首
	sss.name = "Jeams";
	sss.age = 33;
	sss.score = 900;
	cout << sss.name << "    " << sss.age << "    " << sss.score << endl;

	cout << "-------------------------------------------------------------------------" << endl;
	*/

	//結構體數組
	/*
	struct student StuArr[3] = {
		{"Leon",22,870},
		{"Peter",25,990},
		{"Jeams",20,900}
	};

	//修改結構體數組元素值
	StuArr[2].age = 30;

	//檢視
	for (int i = 0; i < sizeof(StuArr) / sizeof(StuArr[0]); i++) {
		cout << StuArr[i].name << "    " << StuArr[i].age << "    " << StuArr[i].score << endl;
	}
	*/

	//結構體指針
	/*
	struct student s = { "Peter", 20, 870 };
	struct student* p = &s;
	cout << p->name << "    " << p->age << "    " << p->score << endl;
	*/

	//結構體俄羅斯套娃
	/*
	teacher t;
	t.age = 50;
	t.id = 11058;
	t.name = "Wang";
	t.stu.age = 20;
	t.stu.score = 900;
	t.stu.name = "Ammy";
	cout << t.name << "    " << t.age << "    " << t.id << endl;
	cout << t.stu.name << "    " << t.stu.age << "    " << t.stu.score << endl;
	*/

	//結構體做函數參數
	/*
	struct student s = { "Peter", 20, 870 };
	printStuS(s);	//不可改數值
	struct student* p = &s;
	printStuP(p);	//可以改數值
	*/

	//結構體+const使用
	/*
	struct student s = { "Peter", 20, 870 };
	//printStuS(s);
	printStuP(&s);
	*/
	
//--------------------------------------------------------------------------

	cout << "-------------------------------------------------------------------------" << endl;
//--------------------------------------------------------------------------

	cout << "-------------------------------------------------------------------------" << endl;
//--------------------------------------------------------------------------


	cout << "-------------------------------------------------------------------------" << endl;
//--------------------------------------------------------------------------


	cout << "-------------------------------------------------------------------------" << endl;
//--------------------------------------------------------------------------


	cout << "-------------------------------------------------------------------------" << endl;
//--------------------------------------------------------------------------




	system("pause");

	return 0;
}


