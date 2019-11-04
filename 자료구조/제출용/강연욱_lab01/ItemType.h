#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAXSIZE 5

enum RelationType {LESS, GREATER, EQUAL};

class ItemType{
private:
    int type;   //곡타입(1.가요, 2.연주곡)
    string music;//곡명
    string composer;//작곡자
    string artist;//가수 또는 연주자
    int genre;//장르
    string primary;//고유번호
public:

    ItemType(){
        type = 0;       //곡 타입
        music = "";     //곡명
        composer = "";  //작곡자
        artist = "";    //가수, 연주자
        genre = 0;      //장르
        primary = "";   //곡의 고유번호
    }
    ~ItemType(){}
    
    int GetType() const {
        return type;
    }
    string GetMusic(){
        return music;
    }
    string GetComposer(){
        return composer;
    }
    string GetArtist(){
        return artist;
    }
    int GetGenre(){
        return genre;
    }
    string GetPrimary(){
        return primary;
    }
    
    void SetType(int inType){
        type = inType;
    }
    void SetMusic(string inMusic){
        music = inMusic;
    }
    void SetComposer(string inComposer){
        composer = inComposer;
    }
    void SetArtist(string inArtist){
        artist = inArtist;
    }
    void SetGenre(int inGenre){
        genre = inGenre;
    }
    void SetPrimary(string inPri){
        primary = inPri;
    }
    void SetRecord(int inType, string inMusic, string inComposer,string inArtist, int inGenre, string inPri){
        SetType(inType);
        SetMusic(inMusic);
        SetComposer(inComposer);
        SetArtist(inArtist);
        SetGenre(inGenre);
        SetPrimary(inPri);
    }
    //곡타입 / 곡이름 / 작곡가 / 가수 / 장르 / 고유번호
    void DisplayTypeOnScreen(){
        cout<<"\t Type: "<<type<<endl;
    }
    void DisplayMusicOnScreen(){
        cout<<"\t Music: "<<music<<endl;
    }
    void DisplayComposerOnScreen(){
        cout<<"\t Composer: "<<composer<<endl;
    }
    void DisplayArtistOnScreen(){
        cout<<"\t Artist: "<<artist<<endl;
    }
    void DisplayGenreOnScreen(){
        cout<<"\t Genre: "<<genre<<endl;
    }
    void DisplayPrimaryOnScreen(){
        cout<<"\t Primary: "<<primary<<endl;
    }
    void DisplayRecordOnScreen(){
        DisplayTypeOnScreen();
        DisplayMusicOnScreen();
        DisplayComposerOnScreen();
        DisplayArtistOnScreen();
        DisplayGenreOnScreen();
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
    
    
    //bool operator==(const ItemType& data) const;
    bool operator==(ItemType& data) const;
};

