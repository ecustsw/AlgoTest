#include <iostream>
#include "MinStack.h"
using namespace std;

//一些测试方法的声明
extern void testQickSort(int src[], int n);
extern void testKMins(int src[], int n, int k);
extern void testMergeSort(int src[], int n, int tmp[]);
extern void testReversePairNum(int src[], int n, int tmp[], long long* pairs);
extern void testRangeOfNumber(int src[], int n,int k);

int main()
{

	//MinStack::test();

	int f[] = { 1 ,2 ,2,2,3,4,5,5 };

	int *tmp = new int[sizeof(f)];

	long long pairs = 0;

	//testQickSort(f,sizeof(f) / sizeof(f[0]));

	//testKMins(f,sizeof(f) / sizeof(f[0]),4);

	//testMergeSort(f,sizeof(f) / sizeof(f[0]),tmp);

	//testReversePairNum(f, sizeof(f) / sizeof(f[0]), tmp, &pairs);

	testRangeOfNumber(f, sizeof(f) / sizeof(f[0]),2);

	delete [] tmp;
}