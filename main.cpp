#include <iostream>
#include <vector>
#include "MinStack.h"
using namespace std;

//一些测试方法的声明
extern void testQickSort(int src[], int n);
extern void testKMins(int src[], int n, int k);
extern void testMergeSort(int src[], int n, int tmp[]);
extern void testReversePairNum(int src[], int n, int tmp[], long long* pairs);
extern void testRangeOfNumber(int src[], int n,int k);
extern void testAdd(vector<int>& l, vector<int>& r);
extern void testSub(vector<int>& l, vector<int>& r); 
extern void testMulti(vector<int>& l, int r);
extern void testDiv(vector<int>& l, int r, int& rem);

int main()
{

	//MinStack::test();

	int f[] = { 1 ,2 ,2,2,3,4,5,5 };

	int *tmp = new int[sizeof(f)];

	long long pairs = 0;

	vector<int> l = {2,2,1};
	vector<int> r = {3,2,1};

	//testQickSort(f,sizeof(f) / sizeof(f[0]));

	//testKMins(f,sizeof(f) / sizeof(f[0]),4);

	//testMergeSort(f,sizeof(f) / sizeof(f[0]),tmp);

	//testReversePairNum(f, sizeof(f) / sizeof(f[0]), tmp, &pairs);

	//testRangeOfNumber(f, sizeof(f) / sizeof(f[0]),2);

	testAdd(l,r);

	testSub(r,l);

	testMulti(l,30);

	int remain = 0;
	testDiv(l,3,remain);

	delete [] tmp;
}