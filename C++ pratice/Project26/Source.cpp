#include <iostream>
#include <string>
#include <ctime>	//	time �ɶ��t���Y���
#include <fstream>	//	���ާ@�t���Y���
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

//�`�κ�k
/*
--��k�D�n���Y��� <algorithm>  <numeric> <functional> �T�̲զ�
--<algorithm>	�Ҧ�STL �Y��󤤳̤j���@�� �A�Ψ� ��� �洫 �d�� �M�� �ƻs �ק� ...
--<numeric>		��n�ܤp �u�]�A�X�Ӧb�ǦC�W²��B�⪺�ҪO���
--<functional>	�w�q�@�ǼҪO�� �ΥH�n����ƹ�H
*/

//-------------------------------------------------------------
//�`�ιM����k
#include"ForEach.h"

//-------------------------------------------------------------
//�`�άd���k
#include"Find.h"

//-------------------------------------------------------------
//�`�αƧǺ�k
#include"Sort.h"

//-------------------------------------------------------------
//�`�Ϋ����P������k
#include"Copy.h"

//-------------------------------------------------------------
//�`�κ�ƥͦ���k
#include"Numeric.h"

//-------------------------------------------------------------
//�`�ζ��X��k
#include"InSet.h"


int main() {
	//���U�@�U�����i��|�Ψ쪺�H����
	srand((unsigned int)time(NULL));

	//-------------------------------------------------------------
	//�`�ιM����k
	//testForEach();
	//testTransform();

	//-------------------------------------------------------------
	//�`�άd���k
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
	//�`�αƧǺ�k
	//testSort();
	//testRandomShuffle();
	//testMerge();
	//testReverse();

	//-------------------------------------------------------------
	//�`�Ϋ����P������k	
	//testCopy();
	//testReplace();
	//testReplaceIf();
	//testSwap();

	//-------------------------------------------------------------
	//�`�κ�ƥͦ���k
	//testAccumulate();
	//testFill();

	//-------------------------------------------------------------
	//�`�ζ��X��k
	testSetItersection();
	testSetUnion();
	testSetDifference();




	system("pause");
	return 0;
}


