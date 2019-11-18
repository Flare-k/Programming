#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class coffee{
protected:
    string beans, roastingP;
public:
    coffee(string _beans, string _roastingP);
    virtual~coffee();
    virtual void printinfo() const;
    virtual void makeCoffee();
    
};
