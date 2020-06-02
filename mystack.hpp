#include "ios_lib.hpp"


class mystack
{
private:
    queue<int> rst;
    queue<int> snd;

public:
    mystack(){}
    void push(int val)
    {
        rst.push(val);
    }

    int pop()
    {
        if(rst.empty())
            return -1;

        while(rst.size() != 1)
        {
            snd.push(rst.front());
            rst.pop();
        }

        int ret = rst.front();
        rst.pop();
        swap(rst, snd);
        return ret;
    }
};


class min_stack
{
private:
    stack<int> data;
    stack<int> min_stk;

public:
    min_stack(){}

    void push(int val)
    {
        data.push(val);
        if(min_stk.empty() || val < min_stk.top())
            min_stk.push(val);
        else
            min_stk.push(min_stk.top());
    }

    void pop()
    {
        min_stk.pop();
        data.pop();
    }

    int min()
    {
        assert(!min_stk.empty() && !data.empty());
        return min_stk.top();
    }
};

void test_stack_with_queue();
void test_minstk();