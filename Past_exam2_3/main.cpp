#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Item.hpp"
#include "FoodItem.hpp"
#include "OfficeItem.hpp"
using namespace std;

int main(){
    string inFileName1 = "foodItem.txt";
    string inFileName2 = "officeItem.txt";
    vector<Item*> vItem;

    ifstream fin1(inFileName1);
    while(!fin1.eof()){ //파일로부터 Item 읽어서 vector에 추가
        Item* pItem = new FoodItem;     // 1) foodItem.txt로부터 FoodItem 맴버 변수를 읽어와서 vItem에 저장
        pItem->readItemFromFile(fin1);
        vItem.push_back(pItem);
    }
    fin1.close();

    ifstream fin2(inFileName2);
    while(!fin2.eof()){
    Item* pItem = new OfficeItem;          // 2) officeItem.txt로부터 OfficeItem 맴버 변수를 읽어와서 vItem에 저장
    pItem->readItemFromFile(fin2);  //파일로부터 Item 읽어서 vector에 추가
    vItem.push_back(pItem);
    }
    fin2.close();

    // 3) vItem에 있는 Item들의 정보를 순차적으로 화면에 출력
    for(auto elem : vItem)
        elem->displayItem();

    return 0;
}
