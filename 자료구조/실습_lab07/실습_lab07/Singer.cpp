#include "Singer.h"

void Singer::SetArtistFromKB(){ //키보드로 '곡타입' 입력
    cout<<"\t Artist: ";
    cin>>name;
}
void Singer::SetAgeFromKB(){ //키보드로 '곡타입' 입력
    cout<<"\t Age: ";
    cin>>age;
}
void Singer::SetGenderFromKB(){ //키보드로 '곡타입' 입력
    cout<<"\t Gender: ";
    cin>>gender;
}

void Singer::SetSingerFromKB(){
    SetArtistFromKB();
    SetAgeFromKB();
    SetGenderFromKB();
}

// '=='를 가능하게 하는 연산자 오버로딩
bool Singer::operator==(const Singer& data) const {
    //  if(this->name.find(data.GetName()) != string::npos)
    if(this->item.GetId() == data.GetId())
        return true;
    else
        return false;
}
// '!='를 가능하게 하는 연산자 오버로딩
bool Singer::operator!=(const Singer& data) const {
    if(this->item.GetId() != data.GetId())
        return true;
    else
        return false;
}


// 비교연산자 오버로딩 ' > '
bool Singer::operator>(const Singer& data) const {
    if(this->item.GetId() > data.GetId())
        return true;
    else
        return false;
}

// 비교연산자 오버로딩 ' < '
bool Singer::operator<(const Singer& data) const {
    if(this->item.GetId() < data.GetId())
        return true;
    else
        return false;
}

/*
 SimpleItemType의 ID를 기준으로 하여 Sorted 정렬하였습니다.
 */
