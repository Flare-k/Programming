#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAXSIZE 10


class ItemType{
private:
    int type;       //곡타입(1.가요, 2.연주곡)
    string music;   //곡명
    string artist;  //가수 또는 연주자
    string composer;//작곡가
    string genre;   //장르
    string primary; //고유번호
    int numPlay;    //실행된 횟수
    int inTime;     //들어온 순서
    int age;
    string gender;
    /*
     지난 과제는 Primary키를 string으로 하였고
     이번에는 int로 해보았습니다.
     */
public:
    ItemType(){
        type = 0;
        music = "";
        artist = "";
        composer = "";
        genre = "";
        primary = "";
        numPlay = 0;
        inTime = 0;
        age = 0;
        gender = "";
    }
    ItemType(ItemType& item){
        type = item.GetType();
        music = item.GetMusic();
        artist = item.GetArtist();
        composer = item.GetComposer();
        genre = item.GetGenre();
        primary = item.GetPrimary();
        numPlay = item.GetNumPlay();
        inTime = item.GetTime();
        age = item.GetAge();
        gender = item.GetGender();
    }
    ~ItemType(){}
    
    int GetType(){ return type;}
    string GetMusic(){return music;}
    string GetArtist(){return artist;}
    string GetComposer(){return composer;}
    string GetGenre(){return genre;}
    string GetPrimary() const{return primary;}
    int GetTime(){return inTime;}
    int GetNumPlay(){return numPlay;}
    int GetAge(){return age;}
    string GetGender(){return gender;}

    void SetType(int inType){type = inType;}
    void SetMusic(string inMusic){music = inMusic;}
    void SetArtist(string inArtist){artist = inArtist;}
    void SetComposer(string inComposer){composer = inComposer;}
    void SetGenre(string inGenre){genre = inGenre;}
    void SetPrimary(string inPri){primary = inPri;}
    void SetTime(int _inTime){inTime = _inTime;}
    void SetNumPlay(int _numPlay){numPlay = _numPlay;}
    void SetAge(int _age){age = _age;}
    void SetGender(string _gender){gender = _gender;}
    
    void SetRecord(int inType, string inMusic, string inComposer,string inArtist, string inGenre, string inPri, int _inTime, int _numPlay){
        SetType(inType);
        SetMusic(inMusic);
        SetArtist(inArtist);
        SetComposer(inComposer);
        SetGenre(inGenre);
        SetPrimary(inPri);
        SetTime(_inTime);
        SetNumPlay(_numPlay);
    }
    
    void SetSingerRecord(string inMusic,string inArtist, string inPri, string _gender, int _age){
        SetMusic(inMusic);
        SetArtist(inArtist);
        SetPrimary(inPri);
        SetGender(_gender);
        SetAge(_age);
    }
    
    
    //곡타입 / 곡이름 / 가수 / 작곡가 / 장르 / 고유번호 / 들어온 순서 / 실행 횟수 / 나이 / 성별
    void DisplayTypeOnScreen(){
        cout<<"\t Type: "<<type<<endl;
    }
    void DisplayMusicOnScreen(){
        cout<<"\t Music: "<<music<<endl;
    }
    void DisplayArtistOnScreen(){
        cout<<"\t Artist: "<<artist<<endl;
    }
    void DisplayComposerOnScreen(){
        cout<<"\t Composer: "<<composer<<endl;
    }
    void DisplayGenreOnScreen(){
        cout<<"\t Genre: "<<genre<<endl;
    }
    void DisplayPrimaryOnScreen(){
        cout<<"\t Primary: "<<primary<<endl;
    }
    void DisplayTimeOnScreen(){
        cout<<"\t Input Order: "<<inTime<<endl;
    }
    void DisplayNumPlayOnScreen(){
        cout<<"\t Play Times: "<<numPlay<<endl;
    }
    void DisplayAgeOnScreen(){
        cout<<"\t Age: "<<age<<endl;
    }
    void DisplayGenderOnScreen(){
        cout<<"\t Gender: "<<gender<<endl;
    }
    
    void DisplayRecordOnScreen(){
        DisplayTypeOnScreen();
        DisplayMusicOnScreen();
        DisplayArtistOnScreen();
        DisplayAgeOnScreen();
        DisplayGenderOnScreen();
        DisplayComposerOnScreen();
        DisplayGenreOnScreen();
        DisplayPrimaryOnScreen();
        cout<<endl;
    }
    void DisplayPLRecordOnScreen(){
        DisplayMusicOnScreen();
        DisplayArtistOnScreen();
        DisplayTimeOnScreen();
        DisplayNumPlayOnScreen();
        DisplayPrimaryOnScreen();
        cout<<endl;
    }
    
    void SetTypeFromKB();
    void SetMusicFromKB();
    void SetComposerFromKB();
    void SetArtistFromKB();
    void SetGenreFromKB();
    void SetPrimaryFromKB();
    void SetAgeFromKB();
    void SetGenderFromKB();
    void SetRecordFromKB();
    
    int ReadDataFromFile(ifstream& fin);
    int WriteDataToFile(ofstream& fout);
    
    bool operator==(const ItemType& data) const;
    bool operator!=(const ItemType& data) const;
    bool operator>(const ItemType& data) const;
    bool operator<(const ItemType& data) const;
};


