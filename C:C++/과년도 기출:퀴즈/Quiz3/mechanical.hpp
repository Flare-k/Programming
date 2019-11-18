#pragma once
#include "keyboard.hpp"

/////mecha
class mechanical: public keyboard{
public:
    mechanical(int _numkey, string _language);
    ~mechanical();
    void print()override;
};

