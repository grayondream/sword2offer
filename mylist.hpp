#ifndef MYLIST_HPP
#define MYLIST_HPP

#include "ios_lib.hpp"

//带头结点的单链表
class mylist
{
    friend ostream& operator<<(ostream& os, mylist *l);
public:
    mylist *next;
    int val;

public:
    mylist(int val, mylist *next)
    {
        this->next = next;
        this->val = val;
    }

    mylist(initializer_list<int> l)
    {
        mylist *cur = this;
        this->next = nullptr;
        for(int val:l)
        {
            mylist *node = new mylist(val, nullptr);
            cur->next = node;
            cur = cur->next;
        }
    }
};


ostream & operator<<(ostream &os, mylist *l);

class com_list
{
public:
    int val;
    com_list *next;
    com_list *sibling;

public:
    com_list(int val, com_list *next = nullptr, com_list *sibling = nullptr)
    {
        this->val = val;
        this->next = next;
        this->sibling = sibling;
    }
};

#endif