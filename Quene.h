#pragma once
class Quene
{
public:
	Quene();
	~Quene();

	void run();
private:
	bool check(int r,int c);
	void dfs(int r);

	int n;
	char col[32];
	int total;
};

