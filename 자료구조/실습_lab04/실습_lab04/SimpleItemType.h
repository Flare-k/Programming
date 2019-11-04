#pragma once
#include <iostream>
#include <fstream>
#include <string>
#define MAXSIZE 10
using namespace std;


class SimpleItemType{
private:
    string s_id;
    string music;
public:
    SimpleItemType(){
        s_id = "";
        music = "";
    }
    ~SimpleItemType(){}
    
    
    string GetId() const {
        return s_id;
    }
    string GetMusic(){
        return music;
    }
    void SetId(string _sid){ s_id = _sid; }
    void SetMusic(string _music){ music = _music;}
    
    void SetSimpleItem(string _sid, string _music){
        SetId(_sid);
        SetMusic(_music);
    }
    void DisplayIdOnScreen(){
        cout<<"\t ID: "<<s_id<<endl;
    }
    void DisplayMusicOnScreen(){
        cout<<"\t MUSIC: "<<music<<endl;
    }
    
    void DisplaySimpleItemOnScreen(){
        DisplayIdOnScreen();
        DisplayMusicOnScreen();
        cout<<endl;
    }
    
    
    void SetMusicFromKB();
    void SetIdFromKB();
    void SetSimpleFromKB();
    
    bool operator==(const SimpleItemType& data) const;
    
};
