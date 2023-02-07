#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件

#define pi 3.14

using namespace std;

//多態 (封裝 繼承 多態 為類的三大特性)
/*
多態分為
* 靜態多態: 函數重載 和 運算符重載 (函數名重名)
* 動態多態: 派生類和虛函數實現運行時多態

區別
* 靜態多態函數地址早綁定 - 編譯階段確定函數地址
* 動態多態函數地址晚綁定 - 運行階段確定函數地址
*/

//----------------------------------------------------------------
//多態基本語法
class Animal {
public:
	//利用virtual 改變地址早綁定
	virtual void speak() {
		cout << "Animal Speaking" << endl;
	}
};
//貓
class Cat :public Animal {
public:
	void speak() {
		cout << "Cat Speaking" << endl;
	}
};
//狗
class Dog :public Animal {
public:
	void speak() {
		cout << "Dog Speaking" << endl;
	}
};
//說話函數
//因為地址早綁定 在編譯階段就確定函數地址為Animal 不是 Cat
//改變方法為 在Animal 的speak 改成 virtual
void doSpeak(Animal& animal) {	//Animal &animal = cat;
	animal.speak();
}
void test01() {
	Cat cat;
	doSpeak(cat);
	Dog dog;
	doSpeak(dog);
}
//動態多態滿足條件
//1. 有繼承關係
//2. 子類重寫父類的虛函數

//動態多態使用
//  父類的指針或者引用 指向子類對象

//----------------------------------------------------------------
//多態原理剖析
void test02() {
	// Animal	沒用virtual	sizeof = 1
	// Animal	有用vitrual	sizeof = 4
	cout << "Sizeof Animal = " << sizeof(Animal) << endl;	 // 差別在於指針	虛函數(表)指針
}

//----------------------------------------------------------------
//多態案例--計算機類
//普通寫法
class Calculator {
public:
	int getResult(string oper) {
		if (oper == "+") { return m_Num1 + m_Num2; }
		else if (oper == "-") { return m_Num1 - m_Num2; }
		else if (oper == "*") { return m_Num1 * m_Num2; }
		else if (oper == "/") { return m_Num1 / m_Num2; }
	}
	//如果想擴展新的功能 需要修改源碼
	int m_Num1;
	int m_Num2;
};
//普通寫法
void test03() {
	Calculator c;
	c.m_Num1 = 20;
	c.m_Num2 = 10;

	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
	cout << c.m_Num1 << " / " << c.m_Num2 << " = " << c.getResult("/") << endl;
	cout << "--------------------------------------------------------" << endl;
}

//多態寫法 實現計算機抽象類
class AbstractCalculator {
public:
	virtual int getResult() {
		return 0;
	}
	int m_Num1;
	int m_Num2;
};
//加法計算器類
class AddCalculator : public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 + m_Num2;
	}
};
//減法計算器類
class SubCalculator : public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 - m_Num2;
	}
};
//乘法計算器類
class MulCalculator : public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 * m_Num2;
	}
};
//除法計算器類
class DivCalculator : public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 / m_Num2;
	}
};

//動態多態使用
//父類的指針或者引用 指向子類對象
void test04() {
	//動態多態使用
	//父類的指針或者引用 指向子類對象
	//加法
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 20;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;

	//減法
	abc = new SubCalculator;
	abc->m_Num1 = 20;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;

	//乘法
	abc = new MulCalculator;
	abc->m_Num1 = 20;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;

	//除法
	abc = new DivCalculator;
	abc->m_Num1 = 20;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " / " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
}
//雖然代碼變多 但各個功能代碼分離 方便定位問題 也可提高代碼可讀性
//* 組織結構清晰
//* 可讀性強
//* 前期後期擴展以及維護性高

//----------------------------------------------------------------
//純虛函數和抽象類
//可能會有父類別虛函數沒意義 都給子類別調用 可以將虛函數改為純虛函數 此類也稱為抽象類
// virtual 類型 函數名 (參數) = 0;
//* 抽象類無法實例化對象
//* 子類必須重寫該類中的純虛函數 不然也會是抽象類
class Base1 {
public:
	virtual void func() = 0;	//純虛函數
	//只要有一個純虛函數 此類稱為抽象類
	//抽象類特點:
	//* 無法實例化對象	(不可 Base1 b; 或是 new Base;)
	//* 抽象類的子類必須重寫父類中的純虛函數
};
class Son1 :public Base1 {
public:
	// 抽象類的子類必須重寫父類中的純虛函數 沒重寫的話實例化時就會報錯
	//必須重寫才可順利實例化
	virtual void func() {
		cout << "Son1 func函數調用" << endl;
	};
};

void test05() {
	//Son1 s;
	Base1* base = new Son1;
	base->func();
}

//----------------------------------------------------------------
//多態案例--製作飲品
class AbstractDrinking {
public:
	//煮水
	virtual void Boil() = 0;
	//沖泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入佐料
	virtual void PutSomeThing() = 0;
	//製作飲品
	virtual void makeDringk() {
		Boil();
		Brew();
		PourInCup();
		PutSomeThing();
	}
};
//咖啡
class Coffee : public AbstractDrinking {
	//煮水
	virtual void Boil() { cout << "煮滾水" << endl; }
	//沖泡
	virtual void Brew() { cout << "沖泡咖啡" << endl; }
	//倒入杯中
	virtual void PourInCup() { cout << "倒入咖啡" << endl; }
	//加入佐料
	virtual void PutSomeThing() { cout << "加入砂糖與牛奶" << endl; }
};
//茶水
class Tea : public AbstractDrinking {
	//煮水
	virtual void Boil() { cout << "煮滾水" << endl; }
	//沖泡
	virtual void Brew() { cout << "沖泡茶葉" << endl; }
	//倒入杯中
	virtual void PourInCup() { cout << "倒入茶杯" << endl; }
	//加入佐料
	virtual void PutSomeThing() { cout << "加入檸檬花瓣" << endl; }
};
//製作函數
void doWork(AbstractDrinking* abs) {	//AbstractDrinking * abs = new Coffee/Drink 建立空間在堆區
	abs->makeDringk();
	cout << "----------------------------------------" << endl;
	delete abs;	//放在堆區 所以需要釋放出來
}
void test06() {
	//製作咖啡
	doWork(new Coffee);
	//製作茶水
	doWork(new Tea);
}

//----------------------------------------------------------------
//多態案例---虛析構 與 純虛析構
/*
多態使用時 若子類中有屬性開闢至堆區 那麼父類指針在釋放時無法調用到子類的析構代碼
解方:  將父類中的析構函數改為 虛析構 或是 純虛析構

虛析構 純虛析構 共性:
* 可以解決父類指針釋放子類對象
* 都需要具體函數實現

虛析構 純虛析構 區別:
* 若為純虛析構 此類為抽象類 無法實例化對象
*/
class Animal02 {
public:
	Animal02() {
		cout << "Animal 構造函數調用" << endl;
	}
	virtual void speak() = 0;
	//虛析構
	//virtual ~Animal02() {
	//	cout << "Animal 析構函數調用" << endl;
	//}

	//純虛析構 需要聲明 需要實現
	virtual ~Animal02() = 0;	
	//只有此行會報錯 因為不存在帶碼實現 一般純虛函數會要求子類一定得將其實現便是因此理由 但析構無法由子類實現
};
Animal02::~Animal02() {
	cout << "Animal 純虛析構函數調用" << endl;
}
//為了將純虛析構實現 必續類外實現處理
class Cat02 :public Animal02 {
public:
	Cat02(string name) {
		cout << "Cat 構造函數調用" << endl;
		m_Name = new string(name);	//子類具有堆區空間
	}
	virtual void speak() {
		cout << *m_Name <<" Cat Speaking" << endl;
	}
	string* m_Name;

	~Cat02() {
		cout << "Cat 析構函數調用" << endl;
		if (m_Name != NULL) {
			cout << "Cat 析構函數堆區刪除" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
};
void test07() {
	Animal02* animal = new Cat02("Tom");
	animal->speak();
	//父類指針在析構的時候 不會調用子類析構函數 導致子類若有堆區屬性 會出現內存洩漏
	//解法 把父類析構改為虛析構 virtual ~Animal02(){}
	delete animal;
}
//1. 虛析構或純虛析構是用來解決通過父類指針釋放子類對象
//2. 若子類沒有堆區數據 可以不寫虛析構或純虛析構
//3. 擁有虛析構或純虛析構的類 也屬於抽象類

//----------------------------------------------------------------
//多態案例---電腦組裝具體實現
//抽象不同零件
class CPU {
public:
	//抽象計算函數
	virtual void calculate() = 0;
};
class Graphic {
public:
	//抽象顯示函數
	virtual void display() = 0;
};
class Memory {
public:
	//抽象存儲函數
	virtual void storage() = 0;
};

class Computer {
public:
	Computer(CPU * c, Graphic* g, Memory* m){
		cpu = c;
		graphic = g;
		memory = m;
	}
	//工作函數
	void work() {
		cpu->calculate();
		graphic->display();
		memory->storage();
	}
	~Computer() {
		if (cpu != NULL) {
			delete cpu;
			cpu = NULL;
		}
		if (graphic != NULL) {
			delete graphic;
			graphic = NULL;
		}
		if (memory != NULL) {
			delete memory;
			memory = NULL;
		}
	}

private:
	CPU* cpu;
	Graphic* graphic;
	Memory* memory;
};

//具體廠商
//Intel
class IntelCpu : public CPU {
public:
	virtual void calculate() {
		cout << "Inter CPU is Running" << endl;
	}
};
class IntelGraphic : public Graphic {
public:
	virtual void display() {
		cout << "Intel Graphic is Running" << endl;
	}
};
class IntelMemory : public Memory {
public:
	virtual void storage() {
		cout << "Intel Memory is Running" << endl;
	}
};
//AMD
class AMDCpu : public CPU {
public:
	virtual void calculate() {
		cout << "AMD CPU is Running" << endl;
	}
};
class AMDGraphic : public Graphic {
public:
	virtual void display() {
		cout << "AMD Graphic is Running" << endl;
	}
};
class AMDMemory : public Memory {
public:
	virtual void storage() {
		cout << "AMD Memory is Running" << endl;
	}
};

void test08() {
	//Computer 01
	CPU* intC = new IntelCpu;
	Graphic* intG = new IntelGraphic;
	Memory* intM = new IntelMemory;

	Computer* computer01 = new Computer(intC, intG, intM);
	computer01->work();
	delete computer01;

	//Computer 02
	CPU* amdC = new AMDCpu;
	Graphic* amdG = new AMDGraphic;
	Memory* amdM = new AMDMemory;

	Computer* computer02 = new Computer(amdC, amdG, amdM);
	computer02->work();
	delete computer02;
}

//----------------------------------------------------------------

int main() {
	srand((unsigned int)time(NULL));

	//多態基本語法
	//test01();

	//多態原理剖析
	//test02();

	//多態案例--計算機類
	//test03();
	//test04();

	//純虛函數和抽象類
	//test05();

	//多態案例--製作飲品
	//test06();

	//多態案例---虛析構 與 純虛析構
	//test07();

	//多態案例---電腦組裝具體實現
	//test08();




	system("pause");
	return 0;
}
