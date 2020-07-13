#pragma once
#include <vector>
using namespace std;
class SWBitOp
{
public:
	SWBitOp();
	~SWBitOp();

	//#1 a^b % p的值(32bit)
	static int NPower(int a, int b, int p);

	//#2 a * b % p 的值(64bit)
	static long long Mutiple(long long a, long long b, long long p);

	static vector<int> add(vector<int> & l,vector<int>& r);

	static vector<int> sub(vector<int>& l, vector<int>& r);

	static vector<int> multi(vector<int> & l,int r);

	static vector<int> div(vector<int> & l,int r,int& rem);
};

