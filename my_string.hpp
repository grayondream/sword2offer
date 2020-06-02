#include <ostream>
#include <istream>
#include <cstring>
#include <cassert>


using std::ostream;
using std::istream;

class my_string
{
private:
    char *data;
    int len = 0;

private:
    bool copy_and_new(const char *src, char **dst, const int len);

public:
    my_string();
    my_string(const char *ptr);
    my_string(const my_string &);
    my_string(const my_string &&);
    ~my_string();

public:
    my_string& operator=(const my_string&);
    my_string& operator+=(const my_string&);
    bool operator==(const my_string &rst);
    char operator[](unsigned int id);
    const char operator[](unsigned int id) const;

public:
    friend my_string operator+(const my_string& rst, const my_string &snd);
    friend ostream& operator<<(ostream& os, const my_string&);
    friend istream& operator>>(istream& os, const my_string&);

public:
    size_t size() const
    {
        return len;
    }
};


my_string operator+(const my_string& rst, const my_string &snd);
ostream& operator<<(ostream& os, const my_string&);
istream& operator>>(istream& os, const my_string&);


void string_test();