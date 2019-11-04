#include "ItemType.h"

//ItemType 클래스


void ItemType::SetIdFromKB(){
    cout<<"\t ID: ";
    cin>>m_Id;
}
void ItemType::SetNameFromKB(){
    cout<<"\t Name: ";
    cin>>m_sName;
}
void ItemType::SetAddressFromKB(){
    cout<<"\t Address: ";
    cin>>m_sAddress;
}
void ItemType::SetRecordFromKB(){
    SetIdFromKB();
    SetNameFromKB();
    SetAddressFromKB();
}
int ItemType::ReadDataFromFile(ifstream& fin){      //객체를 파일로부터 읽어온다.
    fin>>m_Id>>m_sName>>m_sAddress;
    return 1;
}
int ItemType::WriteDataToFile(ofstream& fout){      //객체를 파일에 저장해준다.
    fout<<endl;
    fout<<m_Id<<" ";
    fout<<m_sName<<" ";
    fout<<m_sAddress;
    
    return 1;
}


// 비교연산자 오버로딩 ' == '
bool ItemType::operator==(const ItemType& data) const {
    if(this->m_Id == data.GetId())
        return true;
    else
        return false;
}

// 비교연산자 오버로딩 ' != '
bool ItemType::operator!=(const ItemType& data) const {
    if(this->m_Id != data.GetId())
        return true;
    else
        return false;
}


// 비교연산자 오버로딩 ' > '
bool ItemType::operator>(const ItemType& data) const {
    if(this->m_Id > data.GetId())
        return true;
    else
        return false;
}

// 비교연산자 오버로딩 ' < '
bool ItemType::operator<(const ItemType& data) const {
    if(this->m_Id < data.GetId())
        return true;
    else
        return false;
}
