#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        memset(stack2,0x3f,sizeof stack2);
        pos = 0;
    }

    ~MinStack()
    {
    }

    void push(int x) {
        int oldMin = stack2[pos];
        stack1[++pos] = x;
        stack2[pos] = std::min(x, oldMin);
    }

    void pop() {
        --pos;
    }

    int top() {
        return stack1[pos];
    }

    int getMin() {
        return stack2[pos];
    }

    //≤‚ ‘∑Ω∑®
    static void test()
    {
        MinStack  minStack;
        minStack.push(-1);
        minStack.push(3);
        minStack.push(-4);
        cout << minStack.getMin() << endl; 
        minStack.pop();
        cout << minStack.top() << endl;
        cout << minStack.getMin() << endl;

        cout.flush();
    }
private:
    const static int N = 1024;
    int stack1[N];
    int stack2[N];
    
    int pos;
};
