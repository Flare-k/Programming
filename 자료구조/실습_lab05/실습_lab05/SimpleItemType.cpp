#include "SimpleItemType.h"


void SimpleItemType::SetMusicFromKB(){ //키보드로 '곡타입' 입력
    cout<<"\t Music: ";
    cin>>music;
}
void SimpleItemType::SetIdFromKB(){ //키보드로 '곡제목' 입력
    cout<<"\t Primary Key: ";
    cin>>s_id;
}
void SimpleItemType::SetSimpleFromKB(){
    SetMusicFromKB();
    SetIdFromKB();
}

bool SimpleItemType::operator==(const SimpleItemType& data) const {
    if(this->s_id == data.GetId())
        return true;
    else
        return false;
}
bool SimpleItemType::operator<(const SimpleItemType& data) const {
    if(this->s_id < data.GetId())
        return true;
    else
        return false;
}
bool SimpleItemType::operator>(const SimpleItemType& data) const {
    if(this->s_id > data.GetId())
        return true;
    else
        return false;
}
/*
 ID를 기준으로 하였으나, Unsorted로 정렬됨
 */
