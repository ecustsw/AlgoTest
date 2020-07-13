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

vector<int> SWBitOp::add(vector<int>& l, vector<int>& r)
{
	vector<int> res;
	int bit = 0;
	for (int i = 0; i < l.size() || i < r.size() || bit; i++)
	{
		if (i < l.size()) bit += l[i];
		if (i < r.size()) bit += r[i];
		res.push_back(bit % 10);
		bit /= 10;
	}

	return res;
}

//besure content of l is bigger than content of r
vector<int> SWBitOp::sub(vector<int>& l, vector<int>& r)
{
	vector<int> res;
	int bit = 0;
	for (int i = 0; i < l.size() || bit; i++)
	{
		bit = l[i] - bit;
		if (i < r.size()) bit -= r[i];
		res.push_back((bit + 10) % 10);
		if (bit < 0)
			bit = 1;
		else
			bit = 0;
	}
	while (res.size() > 1 && res.back() == 0) res.pop_back();

	return res;
}

vector<int> SWBitOp::multi(vector<int>& l, int r)
{
	vector<int> res;
	int bit = 0;
	for (int i = 0; i < l.size() || bit; i++)
	{
		if(i < l.size()) bit += l[i] * r;
		res.push_back(bit % 10);
		bit /= 10;
	}
	while (res.size() > 1 && res.back() == 0) res.pop_back();
	return res;
}

vector<int> SWBitOp::div(vector<int>& l, int r,int &rem)
{
	vector<int> res;
	int bit = 0;
	for (int i = l.size() - 1; i >= 0; i--)
	{
		if (i >= 0)
			bit = bit * 10 + l[i];
		res.push_back(bit / r);
		bit %= r;
	}
	reverse(res.begin(),res.end());

	while (res.size() > 1 && res.back() == 0) res.pop_back();

	rem = bit;
	return res;
}


