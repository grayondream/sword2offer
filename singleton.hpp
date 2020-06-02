#include "ios_lib.hpp"


class singleton
{
private:
    static mutex lock;
    static singleton *instance;
    singleton(){}
    singleton(const singleton&){}
    singleton& operator=(const singleton&){}

public:
    static singleton* get_instance()
    {
        if(nullptr == instance)
        {
            lock.lock();
            if(nullptr == instance)
            {
                instance = new singleton();
            }
        }

        return instance;
    }
};


int singleton_test();