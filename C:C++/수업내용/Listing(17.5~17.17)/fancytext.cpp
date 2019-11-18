#include "fancytext.h"
using namespace std;

FancyText::FancyText(const string& t, const string& left,
                     const string& right, const string& conn):
Text(t), left_bracket(left), right_bracket(right), connector(conn) {}

string FancyText::get() const {
    return left_bracket + Text::get() + right_bracket;
}

void FancyText::append(const string& extra) {
    Text::append(connector + extra);
}
