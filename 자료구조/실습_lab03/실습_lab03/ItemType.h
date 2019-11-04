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
    string primary;    //고유번호
    int numPlay;    //실행된 횟수
    int inTime;     //들어온 순서
    /*
     지난 과제는 Primary키를 string으로 하였고
     이번에는 int로 해보았습니다.
     */
public:
    ItemType(){
        type = 0;       //곡 타입
        music = "";     //곡명
        artist = "";    //가수, 연주자
        composer = "";  //작곡자
        genre = "";     //장르
        primary = "";    //곡의 고유번호
        numPlay = 0;
        inTime = 0;     //삽입된 순서
    }
    ~ItemType(){}
    
    int GetType() const {
        return type;
    }
    string GetMusic(){
        return music;
    }
    string GetArtist(){
        return artist;
    }
    string GetComposer(){
        return composer;
    }
    string GetGenre(){
        return genre;
    }
    string GetPrimary() const{
        return primary;
    }
    int GetTime(){
        return inTime;
    }
    int GetNumPlay(){
        return numPlay;
    }
    void SetType(int inType){
        type = inType;
    }
    void SetMusic(string inMusic){
        music = inMusic;
    }
    void SetArtist(string inArtist){
        artist = inArtist;
    }
    void SetComposer(string inComposer){
        composer = inComposer;
    }
    void SetGenre(string inGenre){
        genre = inGenre;
    }
    void SetPrimary(string inPri){
        primary = inPri;
    }
    void SetTime(int _inTime){
        inTime = _inTime;
    }
    void SetNumPlay(int _numPlay){
        numPlay = _numPlay;
    }
    
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

    //곡타입 / 곡이름 / 작곡가 / 가수 / 장르 / 고유번호 / 들어온 순서
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
    
    
    void DisplayRecordOnScreen(){
        DisplayTypeOnScreen();
        DisplayMusicOnScreen();
        DisplayArtistOnScreen();
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
    void SetRecordFromKB();
    
    int ReadDataFromFile(ifstream& fin);
    int WriteDataToFile(ofstream& fout);
    
    bool operator==(const ItemType& data) const;
    bool operator!=(const ItemType& data) const;
    bool operator>(const ItemType& data) const;
    bool operator<(const ItemType& data) const;
};


