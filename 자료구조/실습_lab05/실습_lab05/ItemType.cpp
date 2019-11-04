#include "ItemType.h"

void ItemType::SetTypeFromKB(){ //키보드로 '곡타입' 입력
    cout<<"\t Type(1.pop, 2.repertoire): ";
    cin>>type;
}
void ItemType::SetMusicFromKB(){ //키보드로 '곡제목' 입력
    cout<<"\t Music: ";
    cin>>music;
}
void ItemType::SetArtistFromKB(){ //키보드로 '가수 또는 연주자' 입력
    cout<<"\t Artist: ";
    cin>>artist;
}
void ItemType::SetComposerFromKB(){ //키보드로 '작곡자' 입력
    cout<<"\t Composer: ";
    cin>>composer;
}
void ItemType::SetGenreFromKB(){ //키보드로 '장르' 입력
    cout<<"\t Genre: ";
    cin>>genre;
}
void ItemType::SetPrimaryFromKB(){ //키보드로 '고유번호' 입력
    cout<<"\t Primary Key: ";
    cin>>primary;
}
void ItemType::SetAgeFromKB(){ //키보드로 '고유번호' 입력
    cout<<"\t Age: ";
    cin>>age;
}
void ItemType::SetGenderFromKB(){ //키보드로 '고유번호' 입력
    cout<<"\t Gender: ";
    cin>>gender;
}
void ItemType::SetRecordFromKB(){ //키보드로 '전체정보' 입력
    SetTypeFromKB();
    SetMusicFromKB();
    SetArtistFromKB();
    SetAgeFromKB();
    SetGenderFromKB();
    SetComposerFromKB();
    SetGenreFromKB();
    SetPrimaryFromKB();
}

int ItemType::ReadDataFromFile(ifstream& fin){      //객체에 파일의 내용을 읽어온다.
    fin>>type;
    fin>>music;
    fin>>artist;
    fin>>age;
    fin>>gender;
    fin>>composer;
    fin>>genre;
    fin>>primary;
    
    return 1;
}

int ItemType::WriteDataToFile(ofstream& fout){      //객체의 내용을 파일에 저장해준다.
    fout<<endl;
    fout<<type<<" ";
    fout<<music<<" ";
    fout<<artist<<" ";
    fout<<age<<" ";
    fout<<gender<<" ";
    fout<<composer<<" ";
    fout<<genre<<" ";
    fout<<primary;
    
    return 1;
}



// '=='를 가능하게 하는 연산자 오버로딩
bool ItemType::operator==(const ItemType& data) const {
    if(this->primary == data.GetPrimary())
        return true;
    else
        return false;
}
// '!='를 가능하게 하는 연산자 오버로딩
bool ItemType::operator!=(const ItemType& data) const {
    if(this->primary != data.GetPrimary())
        return true;
    else
        return false;
}


// 비교연산자 오버로딩 ' > '
bool ItemType::operator>(const ItemType& data) const {
    if(this->primary > data.GetPrimary())
        return true;
    else
        return false;
}

// 비교연산자 오버로딩 ' < '
bool ItemType::operator<(const ItemType& data) const {
    if(this->primary < data.GetPrimary())
        return true;
    else
        return false;
}
