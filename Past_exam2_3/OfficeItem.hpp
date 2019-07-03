#pragma once
#include "Item.hpp"

class OfficeItem: public Item{
private:
    string company;
public:
    int readItemFromFile(ifstream& _fin)override;
    int writeItemToFile(ofstream& _fout)override;
    void displayItem() const override;
};
