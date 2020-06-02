#include "ios_lib.hpp"

class myqueue
{
private:
    stack<int> rst;
    stack<int> snd;

public:
    myqueue() {}
    void push(int val)
    {
        rst.push(val);
    }

    int pop()
    {
        if (snd.empty())
        {
            if (rst.empty())
                return -1;
            else
            {
                while (!rst.empty())
                {
                    snd.push(rst.top());
                    rst.pop();
                }
            }
        }

        int ret = snd.top();
        snd.pop();
        return ret;
    }
};

//需要保证小根堆的数大于大根堆的数
class dynamic_array
{
    priority_queue<int, vector<int>, greater<int>> min; //存储大数
    priority_queue<int, vector<int>, less<int>> max;    //存储小数
public:
    void insert(int val)
    {
        if (((min.size() + max.size()) & 1) == 0) //当前存储的数据数量是偶数,新数据插入最小堆
        {
            if (!min.empty() && val < min.top()) //当前数字小于小根堆的
            {
                min.push(val);
                val = min.top();
                min.pop();
            }

            max.push(val);
        }
        else
        {
            if (!max.empty() && val > max.top())
            {
                max.push(val);
                val = max.top();
                max.pop();
            }

            min.push(val);
        }
    }

    double medium() //中位数
    {
        if (min.empty() && max.empty())
            throw out_of_range("nothing in the heap!");

        if (min.size() + max.size() & 1 == 1) //奇数
        {
            return max.top();
        }
        else
        {
            return (min.top() + max.top()) / 2.;
        }
    }
};

class max_queue
{
private:
    class internal_data
    {
    public:
        int id;
        int val;
    };

    deque<internal_data> maximum;
    deque<internal_data> data;
    int cur_id = 0;
public:
    void push_back(int val)
    {
        while(!maximum.empty() && maximum.back().val <= val)
            maximum.pop_back();

        internal_data tmp = {cur_id, val};

        data.push_back(tmp);
        maximum.push_back(tmp);
        cur_id ++;
    }

    int max()
    {
        if(maximum.empty())
            throw out_of_range("the container is empty");
        return maximum.front().val;
    }

    void pop_front()
    {
        if(maximum.empty())
            throw out_of_range("the container is empty");

        if(maximum.front().id == data.front().id)
            maximum.pop_front();

        data.pop_front();
    }
};

int test_queue_with_stack();