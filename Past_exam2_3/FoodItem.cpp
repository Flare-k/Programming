#include "FoodItem.hpp"

int FoodItem::readItemFromFile(ifstream& _fin){
    _fin>>code>>name>>price>>dueDate;
    return 0;
}
int FoodItem::writeItemToFile(ofstream& _fout){   //얜 사실필요없음
    _fout<<code<<name<<price<<dueDate;
    return 0;
}
void FoodItem::displayItem() const{
    cout<<code<<'\t'<<name<<'\t'<<price<<'\t'<<dueDate<<endl;
}
