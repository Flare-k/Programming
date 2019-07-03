#pragma once
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

class Item{
protected:
    string code;
    string name;
    int price;
public:
    virtual void displayItem() const; // Item 맴버 변수를 화면에 출력
    virtual int readItemFromFile(ifstream& _fin);     //Derived Class에 재정의
    virtual int writeItemToFile(ofstream& _fout);
};
