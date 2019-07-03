#pragma once
#include "Item.hpp"

class ApplicationClass{
private:
    vector<Item*> vItem;    //아이템들의 배열
    string foodItemFileName;    //식품 정보가 저장된 파일
    string officeItemFileName;  //사무용품 정보가 저장된 파일
public:
    ApplicationClass(string fif, string oif);
    
    
    string getCommand();
    
    void displayAllItems();
    
    void displayFoodItems();
    void displayOfficeItems();
    
    void searchItemByCode();
    
    
    void run();
    
};
