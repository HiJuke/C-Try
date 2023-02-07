#include <iostream>
#include <string>
#include <ctime>	//	time 時間系統頭文件
#include <fstream>	//	文件操作系統頭文件
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

//常用算法
/*
--算法主要由頭文件 <algorithm>  <numeric> <functional> 三者組成
--<algorithm>	所有STL 頭文件中最大的一個 涉及到 比較 交換 查找 遍歷 複製 修改 ...
--<numeric>		體積很小 只包括幾個在序列上簡單運算的模板函數
--<functional>	定義一些模板類 用以聲明函數對象
*/

//-------------------------------------------------------------
//常用遍歷算法
#include"ForEach.h"

//-------------------------------------------------------------
//常用查找算法
#include"Find.h"

//-------------------------------------------------------------
//常用排序算法
#include"Sort.h"

//-------------------------------------------------------------
//常用拷貝與替換算法
#include"Copy.h"

//-------------------------------------------------------------
//常用算數生成算法
#include"Numeric.h"

//-------------------------------------------------------------
//常用集合算法
#include"InSet.h"


int main() {
	//照顧一下等等可能會用到的隨機數
	srand((unsigned int)time(NULL));

	//-------------------------------------------------------------
	//常用遍歷算法
	//testForEach();
	//testTransform();

	//-------------------------------------------------------------
	//常用查找算法
	//testFind01();
	//testFind02();
	//testFindIf01();
	//testFindIf02();
	//testAdjacendFind();
	//testBinarySearch();
	//testCount01();
	//testCount02();
	//testCountIf01();
	//testCountIf02();

	//-------------------------------------------------------------
	//常用排序算法
	//testSort();
	//testRandomShuffle();
	//testMerge();
	//testReverse();

	//-------------------------------------------------------------
	//常用拷貝與替換算法	
	//testCopy();
	//testReplace();
	//testReplaceIf();
	//testSwap();

	//-------------------------------------------------------------
	//常用算數生成算法
	//testAccumulate();
	//testFill();

	//-------------------------------------------------------------
	//常用集合算法
	testSetItersection();
	testSetUnion();
	testSetDifference();




	system("pause");
	return 0;
}


