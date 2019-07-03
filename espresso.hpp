#pragma once
#include "coffee.hpp"

class espresso:public coffee{
private:
    int act;
    int temper, time, press;
    string driper;
public:
    espresso(string _beans, string _roastingP, int a, int tem,int p, int t);
    void printinfo() const override;
    void makeCoffee() override;
    
};
