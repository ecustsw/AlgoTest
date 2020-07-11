#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <unordered_map>

#include "Algo.h"

using namespace std;
const int N = 9;
string start;

queue<string> nodes;

void bfs()
{
    int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
    unordered_map<string,pair<string,char>> path;
    unordered_map<string,bool> st;
    string end = "12345678x";
    char op[4] = {'l','u','r','d'};
    nodes.push(start);
    while(nodes.size())
    {
        string state = nodes.front();
        nodes.pop();
        if(state == end)
        {
            break;
        }
        if(st[state]) continue;
        st[state] = true;

        int x,y;
        for(int i = 0;i < 9;i ++)
        {
            if(state[i] == 'x')
            {
                x = i % 3;
                y = i / 3;
                break;
            }
        }
        string source = state;
        for(int i = 0;i < 4;i++)
        {
            int nx = x + dx[i],ny = y + dy[i];
            if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
            {
                swap(state[y * 3 + x], state[ny * 3 + nx]);
                if (st.count(state) == 0)
                {
                    nodes.push(state);
                    path[state] = { source,op[i] };
                }
                swap(state[y * 3 + x], state[ny * 3 + nx]);
            } 
        }
    }
    string res;
    while (end != start)
    {
        res += path[end].second;
        end = path[end].first;
    }
    cout << res;
}

void eight()
{
    string temp;
    char c = 0;
    for(int i = 0;i < N;i++){
        cin >> c;
        start += c;
        if(c != 'x'){
            temp += c;
        }
    }

    int count = 0;
    for(int i = 0;i < 8;i++){
        for(int j = i + 1;j < N;j++){
            if(temp[i] > temp[j]){
                count ++;
            }
        }
    }
    if(count % 2){
        cout << "unsolvable";
    }
    else{
        bfs();
    }
}

void quickSort(int f[], int l, int r)
{
    if (l >= r) return;

    int num = f[l];//划分点的选择
    int i = l - 1, j = r + 1;

    while (i < j)
    {
        while (f[++i] < num) {}
        while (f[--j] > num) {}
        if (i < j) swap(f[i], f[j]);
    }

    quickSort(f, l, j);

    quickSort(f, j + 1, r);

    return;
}
