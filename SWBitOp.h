#pragma once
class SWBitOp
{
public:
	SWBitOp();
	~SWBitOp();

	//#1 a^b % p��ֵ(32bit)
	static int NPower(int a, int b, int p);

	//#2 a * b % p ��ֵ(64bit)
	static long long Mutiple(long long a, long long b, long long p);
};

