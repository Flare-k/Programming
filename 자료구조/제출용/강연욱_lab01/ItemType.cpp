#include "ItemType.h"

void ItemType::SetTypeFromKB(){ //키보드로 '곡타입' 입력
    cout<<"\t Type(1.pop, 2.repertoire): ";
    cin>>type;
}
void ItemType::SetMusicFromKB(){ //키보드로 '곡제목' 입력
    cout<<"\t Music: ";
    cin>>music;
}
void ItemType::SetComposerFromKB(){ //키보드로 '작곡자' 입력
    cout<<"\t Composer: ";
    cin>>composer;
}
void ItemType::SetArtistFromKB(){ //키보드로 '가수 또는 연주자' 입력
    cout<<"\t Artist: ";
    cin>>artist;
}
void ItemType::SetGenreFromKB(){ //키보드로 '장르' 입력
    cout<<"\t Genre(num): ";
    cin>>genre;
}
void ItemType::SetPrimaryFromKB(){ //키보드로 '고유번호' 입력
    cout<<"\t Primary Key: ";
    cin>>primary;
}
void ItemType::SetRecordFromKB(){ //키보드로 '전체정보' 입력
    SetTypeFromKB();
    SetMusicFromKB();
    SetComposerFromKB();
    SetArtistFromKB();
    SetGenreFromKB();
    SetPrimaryFromKB();
}

int ItemType::ReadDataFromFile(ifstream& fin){      //객체에 파일의 내용을 읽어온다.
    fin>>type;
    fin>>music;
    fin>>composer;
    fin>>artist;
    fin>>genre;
    fin>>primary;

    return 1;
}

int ItemType::WriteDataToFile(ofstream& fout){      //객체의 내용을 파일에 저장해준다.
    fout<<endl;
    fout<<type<<" ";
    fout<<music<<" ";
    fout<<composer<<" ";
    fout<<artist<<" ";
    fout<<genre<<" ";
    fout<<primary;
    
    return 1;
}

//비교연산을 위해서 여기서 연산자 오버로딩을 만들어줘야 Generic하다고 할 수 있다.
bool ItemType::operator==(ItemType& data) const {
    
    if(this->primary == data.GetPrimary())       //'고유번호'의 비교를 나타내었다.
        return 1;
    return 0;
}
