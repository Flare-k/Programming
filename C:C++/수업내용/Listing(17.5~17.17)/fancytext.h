#pragma once
#include "text.h"
using namespace std;
// Provides minimal decoration for the text
class FancyText: public Text {
    string left_bracket;
    string right_bracket;
    string connector;
public:
    FancyText(const string& t, const string& left,
              const string& right, const string& conn);
    
    string get() const override;
    
    void append(const string& extra) override;
};
