#pragma once
#include "Item.hpp"

class FoodItem: public Item{
private:
    int dueDate;
public:
    int readItemFromFile(ifstream& _fin)override;
    int writeItemToFile(ofstream& _fout)override;
    void displayItem() const override;
};
