#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Item{
protected:
    string code;
    string name;
    int price;
public:
    virtual void displayItem() const;
    virtual int readItemFromFile(ifstream& _fin);
    virtual int writeItemToFile(ofstream& _fout);
    friend class ApplicationClass;
};
