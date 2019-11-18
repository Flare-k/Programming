#include "keyboard.hpp"
keyboard::keyboard(int _numkey, string _language):
numKey(_numkey),language(_language){}
keyboard::~keyboard(){}       //순수가상함수 소멸자.

void keyboard::setNum(int _numkey){numKey = _numkey;}
void keyboard::setLan(string _language){language = _language;}
int keyboard::getNum(){return numKey;}
string keyboard::getLan(){return language;}

void keyboard::print(){}
