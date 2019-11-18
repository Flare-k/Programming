#pragma once
#include <iostream>
#include <string>
using namespace std;

class keyboard{
private:
    int numKey;
    string language;
public:
    keyboard(int _numkey, string _language);
    ~keyboard();       //순수가상함수 소멸자.
    
    void setNum(int _numkey);
    void setLan(string _language);
    virtual int getNum();
    virtual string getLan();
    virtual void print();;
};

