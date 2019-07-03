#pragma once
#include <string>
using namespace std;

class Text {
    string text;
public:

    Text(const string& t);

    virtual string get() const;

    virtual void append(const string& extra);
};
