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

    int num = f[(l + r) >> 1];//划分点的选择
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

int KMinus(int f[], int l, int r, int k)
{
    if (l >= r) return f[l];

    int num = f[(r + l) >> 1], i = l - 1, j = r + 1;
    while (i < j)
    {
        while (f[++i] < num) {}
        while (f[--j] > num) {}
        if (i < j) swap(f[i],f[j]);
    }

    if (j >= k) 
        return KMinus(f, l, j, k);
    else 
        return KMinus(f,j + 1,r,k);
}

void mergeSort(int f[], int l, int r,int tmp[])
{
    if (l >= r) return;

    int mid = (l + r) >> 1;
    mergeSort(f,l,mid,tmp);
    mergeSort(f, mid + 1, r,tmp);

    int i = l, j = mid + 1,pos = 0;
    while (i <= mid && j <= r)
    {
        if (f[i] <= f[j]) tmp[pos++] = f[i++];
        else tmp[pos++] = f[j++];
    }
    while (i <= mid) tmp[pos++] = f[i++];
    while (j <= r) tmp[pos++] = f[j++];

    for (int i = 0; i < pos; i++) f[l + i] = tmp[i];
}

void reversePairNum(int f[], int l, int r, int tmp[], long long  *pairs)
{
    if (l >= r) return;

    int mid = (l + r) >> 1;
    reversePairNum(f, l, mid, tmp,pairs);
    reversePairNum(f, mid + 1, r, tmp,pairs);

    int i = l, j = mid + 1, pos = 0;
    while (i <= mid && j <= r)
    {
        if (f[i] <= f[j]) tmp[pos++] = f[i++];
        else {
            tmp[pos++] = f[j++];
            *pairs += (long long)mid - i + 1;
        }
    }
    while (i <= mid)
        tmp[pos++] = f[i++];

    while (j <= r) tmp[pos++] = f[j++];

    for (int i = 0; i < pos; i++) f[l + i] = tmp[i];
}

void rangeOfNumber(int f[], int l, int r,int k)
{
    int i = l, j = r;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (f[mid] >= k) r = mid;
        else l = mid + 1;
    }

    if (k != f[l])
    {
        cout << "-1 -1" << endl;
        return;
    }
    cout << l << " ";
    l = i, r = j;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (f[mid] <= k) l = mid;
        else r = mid - 1;
    }

    cout << l << endl;

    return;
}