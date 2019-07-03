#include "Application.hpp"
#include "Item.hpp"
#include "FoodItem.hpp"
#include "OfficeItem.hpp"
ApplicationClass::ApplicationClass(string fif, string oif):
foodItemFileName(fif), officeItemFileName(oif){
    cout<<"1. Display all items."<<endl;
    cout<<"2. Display food items."<<endl;
    cout<<"3. Display office items."<<endl;
    cout<<"4. Search item by code."<<endl;
    cout<<"5. Quit."<<endl;
    cout<<"Input>>";
}//생성자


string ApplicationClass::getCommand(){
    string s;
    cin>>s;
    return s;
}

void ApplicationClass::displayAllItems(){
    ifstream fin1(foodItemFileName);
    while(!fin1.eof()){ //파일로부터 Item 읽어서 vector에 추가
        Item* pItem = new FoodItem;     // 1) foodItem.txt로부터 FoodItem 맴버 변수를 읽어와서 vItem에 저장
        pItem->readItemFromFile(fin1);
        vItem.push_back(pItem);
    }
    fin1.close();
    
    ifstream fin2(officeItemFileName);
    while(!fin2.eof()){
        Item* pItem = new OfficeItem;          // 2) officeItem.txt로부터 OfficeItem 맴버 변수를 읽어와서 vItem에 저장
        pItem->readItemFromFile(fin2);  //파일로부터 Item 읽어서 vector에 추가
        vItem.push_back(pItem);
    }
    fin2.close();
    for(auto elem : vItem)
        elem -> displayItem();
    
}

void ApplicationClass::displayFoodItems(){
    ifstream fin1(foodItemFileName);
    while(!fin1.eof()){ //파일로부터 Item 읽어서 vector에 추가
        Item* pItem = new FoodItem;     // 1) foodItem.txt로부터 FoodItem 맴버 변수를 읽어와서 vItem에 저장
        pItem->readItemFromFile(fin1);
        vItem.push_back(pItem);
    }
    for(auto elem : vItem)
        elem -> displayItem();
}
void ApplicationClass::displayOfficeItems(){
    ifstream fin2(officeItemFileName);
    while(!fin2.eof()){
        Item* pItem = new OfficeItem;          // 2) officeItem.txt로부터 OfficeItem 맴버 변수를 읽어와서 vItem에 저장
        pItem->readItemFromFile(fin2);  //파일로부터 Item 읽어서 vector에 추가
        vItem.push_back(pItem);
    }
    fin2.close();
    for(auto elem : vItem)
        elem -> displayItem();
}

void ApplicationClass::searchItemByCode(){
    ifstream fin1(foodItemFileName);
    while(!fin1.eof()){ //파일로부터 Item 읽어서 vector에 추가
        Item* pItem = new FoodItem;     // 1) foodItem.txt로부터 FoodItem 맴버 변수를 읽어와서 vItem에 저장
        pItem->readItemFromFile(fin1);
        vItem.push_back(pItem);
    }
    ifstream fin2(officeItemFileName);
    while(!fin2.eof()){
        Item* pItem = new OfficeItem;          // 2) officeItem.txt로부터 OfficeItem 맴버 변수를 읽어와서 vItem에 저장
        pItem->readItemFromFile(fin2);  //파일로부터 Item 읽어서 vector에 추가
        vItem.push_back(pItem);
    }
    
    string cc;
    cout<<"Enter the Code:";
    cin>>cc;
    for(auto elem : vItem){
        if(cc == "C1001"){
            if(elem->code=="C1001"){
                elem->displayItem();
            }
        }
        else if(cc == "C1002"){
            if(elem->code=="C1002"){
                elem->displayItem();
            }
        }
        else if(cc == "C1003"){
            if(elem->code=="C1003"){
                elem->displayItem();
            }
        }
        else if(cc == "F1001"){
            if(elem->code=="F1001"){
                elem->displayItem();
            }
        }
        else if(cc == "F1002"){
            if(elem->code=="F1002"){        //해당문자에 해당하는(code)를 발견하면 그 값을 가리킴
                elem->displayItem();        //가리킨 부분에 대한 클래스 메소드로 가서 출력
            }
        }
        else
            cout<<"No items found."<<endl;
    }
}


void ApplicationClass::run(){
    string sOption;
    while(1){
        sOption = getCommand();         //string끼리 비교.
        if(sOption == "1"){
            displayAllItems();
            break;
        }
        else if(sOption == "2"){
            displayFoodItems();
            break;
        }
        else if(sOption == "3"){
            displayOfficeItems();
            break;
        }
        else if(sOption == "4"){
            searchItemByCode();
            break;
        }
        else if(sOption == "5")
            break;
    }
    cout<<"Exit the program..."<<endl;
}

