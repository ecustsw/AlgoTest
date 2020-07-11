#include <cstdio>
#include <cstring>
#include <algorithm>
#include "src/Algo.h"

void testQickSort(int src[],int n)
{
	quickSort(src,0,n - 1);
	//std::sort(src,src + n);

	for (int i = 0; i < n; i++)
		printf("%d ",src[i]);

	return ;
}