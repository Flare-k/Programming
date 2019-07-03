#include "coffee.hpp"
coffee::coffee(string _beans, string _roastingP):
    beans(_beans), roastingP(_roastingP){}
~
coffee(){}

void coffee::printinfo() const;
void coffee::makeCoffee() = 0;
