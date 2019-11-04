#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "SimpleItemType.h"
using namespace std;


class Singer{
private:
    string name;
    int age;
    string gender;
    SimpleItemType item;
public:
    Singer(){
        name = "";
        age = 0;
        gender = "";
        item.GetId();   //SimpleItem에서 받아온 ID로 대소 비교하여 Sorted-Linked-List의 기능을 하는 SingerList를 구현하였습니다.
        item.GetMusic();
    }
    Singer(Singer& singer){
        name = singer.GetName();
        age = singer.GetAge();
        gender = singer.GetGender();
        item.GetId() = singer.GetId();
        item.GetMusic() = singer.GetMusic();
    }
    ~Singer(){}
    
    string GetName()const{return name;}
    int GetAge() {return age;}
    string GetGender(){return gender;}
    string GetId() const {return item.GetId();}
    string GetMusic(){return item.GetMusic();}
    
    void SetName(string _name){name = _name;}
    void SetAge(int _age){age = _age;}
    void SetGender(string _gender){gender = _gender;}
    void SetSonglist(SimpleItemType _item){item = _item;}
    void SetSinger(string _name, int _age, string _gender, SimpleItemType _item){
        SetName(_name);
        SetAge(_age);
        SetGender(_gender);
        SetSonglist(_item); //SongList를 구현하기위해 객체를 입력파라미터로 받았고, 'ID'와 '곡명' 총 두 가지의 정보를 가져오는 객체가 저장될 것입니다.
    }
    
    
    void DisplayNameOnScreen(){
        cout<<"\t NAME: "<<name<<endl;
    }
    void DisplayAgeOnScreen(){
        cout<<"\t AGE: "<<age<<endl;
    }
    void DisplayGenderOnScreen(){
        cout<<"\t GENDER(M/F): "<<gender<<endl;
    }
    void DisplayIdOnScreen(){
        cout<<"\t ID: "<<item.GetId()<<endl;
    }
    void DisplayMusicOnScreen(){
        cout<<"\t Music: "<<item.GetMusic()<<endl;
    }
    
    void DisplaySingerOnScreen(){
        DisplayNameOnScreen();
        DisplayAgeOnScreen();
        DisplayGenderOnScreen();
        cout<<endl;
    }
    void DisplaySongInSinger(){
        DisplayIdOnScreen();
        DisplayMusicOnScreen();
        cout<<endl;
    }
    
    void SetArtistFromKB();
    void SetAgeFromKB();
    void SetGenderFromKB();
    void SetPrimaryFromKB();
    void SetMusicFromKB();
    void SetSingerFromKB();
    
    bool operator==(const Singer& data) const;
    bool operator!=(const Singer& data) const;
    bool operator>(const Singer& data) const;
    bool operator<(const Singer& data) const;
    /*
     입력되는 객체는 Singer 객체지만 사실상 비교하는 것은 Singer 객체 안에 있는 SimpleItem 객체의 'ID' 내용을 가지고 비교하게끔 하였습니다.
     */
    
};
