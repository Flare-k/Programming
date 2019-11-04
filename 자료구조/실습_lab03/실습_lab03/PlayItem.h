#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class PlayItem{
private:
    string primary;    //고유번호
    int numPlay;    //실행된 횟수
    int inTime;     //들어온 순서
    
public:
    PlayItem(){
        primary = "";    //곡의 고유번호
        numPlay = 0;
        inTime = 0;     //삽입된 순서
    }
    ~PlayItem(){}
    
    
    string GetPrimary() const{
        return primary;
    }
    int GetTime(){
        return inTime;
    }
    int GetNumPlay(){
        return numPlay;
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
    
    void SetRecord(string inPri, int _inTime, int _numPlay){
        SetPrimary(inPri);
        SetTime(_inTime);
        SetNumPlay(_numPlay);
    }
    
    
    // 고유번호 / 들어온 순서 / 재생된 횟수
    void DisplayPrimaryOnScreen(){
        cout<<"\t Primary: "<<primary<<endl;
    }
    void DisplayTimeOnScreen(){
        cout<<"\t Input Order: "<<inTime<<endl;
    }
    void DisplayNumPlayOnScreen(){
        cout<<"\t Play Times: "<<numPlay<<endl;
    }
    void DisplayPLRecordOnScreen(){
        DisplayPrimaryOnScreen();
        DisplayTimeOnScreen();
        DisplayNumPlayOnScreen();
        cout<<endl;
    }
    
    bool operator==(const PlayItem& data) const;
    bool operator!=(const PlayItem& data) const;
    bool operator>(const PlayItem& data) const;
    bool operator<(const PlayItem& data) const;
};


