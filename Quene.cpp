#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include "Quene.h"

Quene::Quene()
{
    n = 0;
    total = 0;
    memset(col, 0, sizeof col);
}
Quene::~Quene()
{

}

void Quene::run()
{
    for (; n < 15; n++)
    {
        memset(col, 0, sizeof col);
        total = 0;
        long begin = (long)time(NULL);
        dfs(0);//每次都从第一行开始放
        long end = (long)time(NULL);
        printf("when n is %d,total is %d,eclipse time is %lds\n", n, total,(end - begin));
    }
}

bool Quene::check(int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        if (col[i] == c || (abs(col[i] - c) == abs(i - r)))
        {
            return false;
        }
    }
    return true;
}

void Quene::dfs(int r)
{
    if (r == n)//放了n 行，这种方案可行，返回继续搜索
    {
        total++;
        return;
    }
    for (int c = 0; c < n; c++)//对每一行，都从第一列开始找合适的位置
    {
        if (check(r, c))
        {
            col[r] = c;
            dfs(r + 1);
        }
    }
}