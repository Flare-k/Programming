#include <iostream>
#include <string>
//#include "text.h"
//#include "fancytext.h"
//#include "fixedtext.h"
using namespace std;

class Text{
    string text;
public:
    Text(const string& t): text(t) {}

    virtual string get() const {return text;}
    virtual void append(const string& extra) {text += extra;}
};

class FixedText: public Text {
public:
    FixedText();
    
    void append(const string&) override{
    }
};

class FancyText: public Text {
    string left_bracket;
    string right_bracket;
    string connector;
public:
    FancyText(const string& t, const string& left,
              const string& right, const string& conn):
    Text::Text(t), left_bracket(left), right_bracket(right), connector(conn) {}
    
    string get() const override{
        return left_bracket + Text::get() + right_bracket;
    }
    
    void append(const string& extra) override{
        Text::append(connector + extra);
    }
};

int main() {
    Text t1("plain");
    FancyText t2("fancy", "<<", ">>", "***");
    FixedText t3;
    
    cout << t1.get() << '\n';
    cout << t2.get() << '\n';
    cout << t3.get() << '\n';
    
    cout << "-------------------------\n";
    t1.append("A");
    t2.append("A");
    t3.append("A");
    cout << t1.get() << '\n';
    cout << t2.get() << '\n';
    cout << t3.get() << '\n';
    
    cout << "-------------------------\n";
    t1.append("B");
    t2.append("B");
    t3.append("B");
    cout << t1.get() << '\n';
    cout << t2.get() << '\n';
    cout << t3.get() << '\n';
}
