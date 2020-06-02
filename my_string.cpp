#include "my_string.hpp"
#include "ios_lib.hpp"


my_string::my_string()
{
    data = new char[1];
    *data = '\0';
    len = 0;
}

my_string::~my_string()
{
    if(nullptr != data)
    {
        delete data;
        data = nullptr;
        len = 0;
    }
}

bool my_string::copy_and_new(const char *src, char **dst, const int len)
{
    if(nullptr == src || len == 0)
        return false;

    if(nullptr != *dst)
    {
        delete *dst;
        *dst = nullptr;
    }

    *dst = new char[len + 1];
    strncpy(*dst, src, len);
    (*dst)[len] = '\0';
    return true;
}

my_string::my_string(const char *ptr)
{
    data = nullptr;
    assert(nullptr != ptr);
    int length = strnlen(ptr, 65535);
    bool ret = copy_and_new(ptr, &(this->data), length);
    len = length;
}

my_string::my_string(const my_string &str)
{
    data = nullptr;
    bool ret = copy_and_new(str.data, &(this->data), str.len);
    this->len = str.len;
}

my_string::my_string(const my_string &&str)
{
    this->data = str.data;
    len = str.len;
}

my_string& my_string::operator=(const my_string &str)
{
    if(*this == str)
        return *this;
    else
    {
        //异常安全，如果内存申请失败，类的构造也会随之失败
        my_string tmp(str);
        char *tmp_data = this->data;
        this->data = tmp.data;
        tmp.data = tmp_data;
        this->len = str.len;
    }

    return *this;
}

my_string& my_string::operator+=(const my_string &str)
{
    int total = str.len + this->len;
    char *new_ptr = new char[total + 1];
    int j = 0;
    for(int i = 0;i < this->len;)
        new_ptr[j++] = data[i++];

    for(int i = 0;i < str.len;)
        new_ptr[j++] = str.data[i++];

    delete this->data;
    data = new_ptr;
    data[total] = '\0';
    this->len = total;
    return *this;
}

bool my_string::operator==(const my_string &str)
{
    if(str.len != len)
        return false;

    for(int i = 0;i < len;i++)
    {
        if(str[i] != (*this)[i])
            return false;
    }

    return true;
}

char my_string::operator[](unsigned int id)
{
    assert(len >= 0 && len < len);
    return *(data + id);
}

const char my_string::operator[](unsigned int id) const
{
    return *(data + id);
}

my_string operator+(const my_string&rst, const my_string &snd)
{
    my_string tmp(rst);
    tmp += snd;
    return tmp;
}

ostream& operator<<(ostream&os, const my_string &str)
{
    for(int i = 0;i < str.size();i ++)
    {
        os<<str[i];
    }

    return os;
}

istream& operator>>(istream& is, const my_string&)
{
    char buffer[4096] = {'0'};
    char ch;
    int i = 0;
    my_string ret;
    while(is>>ch)
    {
        buffer[i++] = ch;
        if(i == 4096 - 1)
        {
            ret += my_string(buffer);
            memset(buffer, 0, 4096);
        }
    }

    return is;
}

void string_test()
{
    char *ptr = nullptr;

    //基本构造函数测试
    my_string str;
    my_string str1("123");
    // my_string str2(ptr);
    my_string str4(str1);
    my_string str5 = my_string("456");

    cout<<STR_VARIABLE(str)<<str<<endl;
    cout<<STR_VARIABLE(str1)<<str1<<endl;
    //cout<<STR_VARIABLE(s)<<s<<endl;
    // cout<<STR_VARIABLE(str2)<<str2<<endl;
    cout<<STR_VARIABLE(str4)<<str4<<endl;
    cout<<STR_VARIABLE(str5)<<str5<<endl;


    cout<<STR_VARIABLE(str1 + str5)<< (str1 + str5)<<endl;
}
