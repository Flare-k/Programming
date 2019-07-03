#pragma once
#include "coffee.hpp"
class handDrip: public coffee{
private:
    int act;
    int temper, time1, time2;
    string driper;
public:
    handDrip(string _beans, string _roastingP, int a, int tem,int t1, int t2, string d);
    
    void printinfo() const override;
    void makeCoffee() override;
    
};
