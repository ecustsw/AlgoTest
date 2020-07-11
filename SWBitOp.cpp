#include "SWBitOp.h"

SWBitOp::SWBitOp()
{

}

SWBitOp::~SWBitOp()
{

}

int SWBitOp::NPower(int a, int b, int p)
{
	int res = 1;
	while (b)
	{
		if (b & 1) {
			res = (long long)res * a % p;
		}
		a = (long long)a * a % p;
		b >>= 1;
	}
	return res;
}

long long SWBitOp::Mutiple(long long a, long long b, long long p)
{
	long long res = 0;
	while (b)
	{
		if (b & 1) {
			res = (res + a) % p;
		}
		a = a * 2 % p;
		b >>= 1;
	}
	return res;
}