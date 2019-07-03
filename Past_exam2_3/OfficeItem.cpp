#include "OfficeItem.hpp"

int OfficeItem::readItemFromFile(ifstream& _fin){
    _fin>>code>>name>>price>>company;
    return 0;
}
int OfficeItem::writeItemToFile(ofstream& _fout){   //얜 사실필요없음
    _fout<<code<<name<<price<<company;
    return 0;
}
void OfficeItem::displayItem() const{
    cout<<code<<'\t'<<name<<'\t'<<price<<'\t'<<company<<endl;
}
