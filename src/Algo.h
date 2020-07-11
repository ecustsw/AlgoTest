#ifndef __ALGO_H__
#define __ALGO_H__

#ifdef __cplusplus
extern "C" {
#endif
	
void eight();

void quickSort(int f[],int l,int r);
int KMinus(int f[], int l, int r,int k);
void mergeSort(int f[],int l,int r,int tmp[]);
void reversePairNum(int f[], int l, int r, int tmp[],long long* pairs);
void rangeOfNumber(int f[],int l,int r,int k);

#ifdef __cplusplus
}
#endif // __cplusplus




#endif // __ALGO_H__
