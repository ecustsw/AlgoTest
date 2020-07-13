#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#include "src/Algo.h"
#include "CClock.h"
#include "SWBitOp.h"

void testQickSort(int src[],int n)
{
	CClock clock;

	quickSort(src,0,n - 1);
	//std::sort(src,src + n);

	clock.end();

	for (int i = 0; i < n; i++)
		printf("%d ",src[i]);

	return ;
}

void testKMins(int src[], int n,int k)
{
	CClock clock;

	int num = KMinus(src, 0, n - 1,k - 1);

	clock.end();

	printf("%dth min number is %d",k, num);

	return;
}

void testMergeSort(int src[], int n,int tmp[])
{
	CClock clock;

	mergeSort(src, 0, n - 1,tmp);

	clock.end();

	for (int i = 0; i < n; i++)
		printf("%d ", src[i]);

	return;
}

void testReversePairNum(int src[], int n, int tmp[],long long *pairs)
{
	CClock clock;

	reversePairNum(src, 0, n - 1, tmp,pairs);

	clock.end();

	printf("pairs is %lld",*pairs);

	return;
}

void testRangeOfNumber(int src[], int n,int k)
{
	CClock clock;

	rangeOfNumber(src, 0, n - 1,k);

	clock.end();

	return;
}

void testAdd(vector<int>& l, vector<int>& r)
{
	CClock clock;

	auto res =  SWBitOp::add(l,r);

	for (int i = res.size() - 1; i >= 0; i--)
		cout << res[i];
		
	cout << endl;

	clock.end();

	return;
}

void testSub(vector<int>& l, vector<int>& r)
{
	CClock clock;

	auto res = SWBitOp::sub(l, r);

	for (int i = res.size() - 1; i >= 0; i--)
		cout << res[i];

	cout << endl;

	clock.end();

	return;
}

void testMulti(vector<int>& l, int r)
{
	CClock clock;

	auto res = SWBitOp::multi(l, r);

	for (int i = res.size() - 1; i >= 0; i--)
		cout << res[i];

	cout << endl;

	clock.end();

	return;
}

void testDiv(vector<int>& l, int r,int & rem)
{
	CClock clock;

	auto res = SWBitOp::div(l, r,rem);

	for (int i = res.size() - 1; i >= 0; i--)
		cout << res[i];

	cout << endl << rem << endl;

	clock.end();

	return;
}