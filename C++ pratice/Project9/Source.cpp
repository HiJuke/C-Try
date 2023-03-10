#include <iostream>
#include <string>
#include <ctime>	//	time 丁╰参繷ゅン

#define pi 3.14

using namespace std;

//----------------------------------------------------------------
//笲衡才更
//腹笲衡才更
class Person1 {
public:
	//Θㄧ计腹笲衡才更	セ借 Person p3 = p1.operator+(p2);
	/*
	Person1 operator+(Person1& p) {
		Person1 temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}
	*/
	int m_A;
	int m_B;
};
//Ыㄧ计腹笲衡才更 セ借 Person p3 = operator+(p1, p2);
Person1 operator+(Person1& p1, Person1& p2) {
	Person1 temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
void test01() {
	Person1 P1;
	P1.m_A = 20;
	P1.m_B = 20;
	Person1 P2;
	P2.m_A = 20;
	P2.m_B = 20;

	Person1 P3 = P1 + P2;	
	cout << P3.m_A << "\t" << P3.m_B << endl;
}
//笲衡才更祇ネㄧ计更
Person1 operator+(Person1& p1, int num) {
	Person1 temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}

//----------------------------------------------------------------
//オ簿笲衡才更
class Person2 {
	friend ostream& operator<<(ostream& cout, Person2& p);
public:
	Person2(int a, int b) {
		m_A = a;
		m_B = b;
	}
private:
	//ノΘㄧ计更 オ簿笲衡才
	//挡阶 ぃ穦ノΘㄧ计龟瞷 オ簿笲衡才 礚猭龟瞷cout オ凹
	int m_A;
	int m_B;
};
//Ыㄧ计更オ簿笲衡才
ostream & operator<<(ostream&out, Person2 &p) {	//operator<<(cout, p) 虏て cout << p
	cout << p.m_A << "\t" << p.m_B << endl;
	return out;		//肚cout龟瞷渺Α絪Θ ぃ礛cout << p ; ぃ cout << p << endl; ぇ摸
}
void test02() {
	Person2 P1(22, 32);
	cout << P1 << endl;
}

//----------------------------------------------------------------
//患糤笲衡才更
class MyInteger {
	friend ostream& operator<<(ostream& out, MyInteger p);
public:
	MyInteger() {
		m_Num = 0;
	}
	//玡竚++更
	MyInteger& operator++() {	//ゲ斗まノthis 癸计沮患糤
		m_Num++;
		return *this;
	}

	//竚++更
	MyInteger operator++(int) {		//int把计 ノ跋だ玡竚竚 瞷琌竚 ゲ斗计
		MyInteger temp= *this;		// 癘魁讽挡狦
		m_Num++;					// 患糤
		return temp;				//程盢魁挡狦				
	}

	//玡竚--更
	MyInteger& operator--() {	//ゲ斗まノthis 癸计沮--
		m_Num--;
		return *this;
	}

	//竚--更
	MyInteger operator--(int) {		//int把计 ノ跋だ玡竚竚 瞷琌竚 ゲ斗计
		MyInteger temp = *this;		// 癘魁讽挡狦
		m_Num--;					// --
		return temp;				//程盢魁挡狦				
	}


private:
	int m_Num;
};
//穌﹚オ簿更
ostream& operator<<(ostream& out, MyInteger p) {	//operator<<(cout, p) 虏て cout << p
	cout << p.m_Num;
	return out;		//肚cout龟瞷渺Α絪Θ ぃ礛cout << p ; ぃ cout << p << endl; ぇ摸
}
void test03() {
	MyInteger mying;
	cout << ++(++mying) << endl;
	cout << mying << endl;
	cout << mying++ << endl;
	cout << mying << endl;
	cout << --(--mying) << endl;
	cout << mying << endl;
	cout << mying-- << endl;
	cout << mying << endl;
}

//----------------------------------------------------------------
//结笲衡才更
//絪亩竟倒摸ㄧ计 篶硑猂篶ī结笲衡才 operator = 
class Person3 {
public:
	Person3(int a) {
		m_Age = new int(a);	//承帮跋
	}
	~Person3() {		//盢丁パ帮跋い睦
		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL;
		}
	}

	//更 结笲衡才
	Person3& operator= (Person3& p) {
		//莱赣耞琌Τ妮┦帮跋 Τ杠睦爱瞓 瞏ī
		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);	//瞏ī
		return *this;
	}

	int* m_Age;
};
void test04() {
	Person3 p1(18);
	Person3 p2(28);
	Person3 p3(68);
	p2 = p1;	//╰参箇砞结巨旧璓帮跋砆狡睦 穦crash ┮璶糶
	cout << "p1 =" << *p1.m_Age << endl;
	cout << "p2 =" << *p2.m_Age << endl;

	p3 = p2 = p1;
	cout << "p1 =" << *p1.m_Age << endl;
	cout << "p2 =" << *p2.m_Age << endl;
	cout << "p3 =" << *p2.m_Age << endl;
}

//----------------------------------------------------------------
//闽玒笲衡才更
class Person4 {
public:
	Person4(int a, string name) {
		m_Name = name;
		m_Age = a;
	}
	~Person4() {	

	}

	//更 结笲衡才
	bool operator== (Person4& p) {
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
			return true;
		}
		return false;
	}

	bool operator!= (Person4& p) {
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
			return false;
		}
		return true;
	}

	string m_Name;
	int m_Age;
};
void test05() {
	Person4 p1(22, "Peter");
	Person4 p2(22, "Peter");
	Person4 p3(32, "Eilly");
	if (p1 == p2) {
		cout << "Same" << endl;
	}
	if (p1 != p3) {
		cout << "Different" << endl;
	}
}

//----------------------------------------------------------------
//计秸ノ笲衡才更
//ラㄧ计艶⊿Τ㏕﹚糶猭
class MyPrint {
public:
	void operator()(string text) {
		cout << text << endl;
	}
};
class MyAdd {
public:
	int operator()(int a,int b) {
		return a+b;
	}
};
void test06() {
	//更()巨才嘿ラㄧ计
	MyPrint myFunc;
	myFunc("Welcome");
	MyAdd myAd;
	cout << myAd(6, 9) << endl;
	//拔ㄧ计癸禜	糶猭: 摸()(肚) --- 摸 + 珹腹 + 块
	cout << MyAdd()(8, 7) << endl;
}







int main() {
	srand((unsigned int)time(NULL));
	//腹笲衡才更
	//test01();
	//オ簿笲衡才更
	//test02();
	//患糤笲衡才更
	//test03();
	//结笲衡才更
	//test04();
	//闽玒笲衡才更
	//test05();
	//计秸ノ笲衡才更
	//test06();

	system("pause");
	return 0;
}
