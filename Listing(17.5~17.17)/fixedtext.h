#pragma once
#include "text.h"
using namespace std;


class FixedText: public Text {
public:
    FixedText();
    
    void append(const string&) override;
};
