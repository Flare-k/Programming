#include "OfficeItem.hpp"
#include "Item.hpp"
int OfficeItem::readItemFromFile(ifstream& _fin){
    _fin>>code>>name>>price>>company;
    return 0;
}
void OfficeItem::displayItem()const {
    cout<<code<<'\t'<<name<<'\t'<<price<<'\t'<<company<<endl;
    }
