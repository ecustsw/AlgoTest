#include <cstdio>
#include <cstring>
#include <algorithm>
#include "src/Algo.h"
#include "CClock.h"

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