#include "singleton.hpp"


singleton* singleton::instance = nullptr;
mutex singleton::lock;

int singleton_test()
{
    cout<<singleton::get_instance()<<endl;
    cout<<singleton::get_instance()<<endl;
    cout<<singleton::get_instance()<<endl;
    cout<<singleton::get_instance()<<endl;
}