#include "mylist.hpp"

ostream & operator<<(ostream &os, mylist *l)
{
    if(nullptr == l)
    {
        return os;
    }

    while(l != nullptr)
    {
        os<<l->val<<"\t";
        l = l->next;
    }

    return os;
}