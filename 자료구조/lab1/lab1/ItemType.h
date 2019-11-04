#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAXSIZE 50
//ItemType 클래스
enum RelationType {LESS, GREATER, EQUAL};

class ItemType{
private:
    int m_Id;                      // 학생 ID
    string m_sName;                // 학생 이름 저장 변수
    string m_sAddress;             // 학생 주소 저장 변수
    
public:
    ItemType(){     //생성자   , 객체의 초기값
        m_Id = 0;
        m_sName = "";
        m_sAddress = "";
    }
    ~ItemType(){} //소멸자
    
    int GetId() const {        //객체의 ID를 리턴
        return m_Id;
    }
    string GetName(){   //객체의 이름을 리턴
        return m_sName;
    }
    string GetAddress(){//객체의 주소를 리턴
        return m_sAddress;
    }
    
    void SetId(int inId){       // 키보드로 학생 학번 입력 함수 -> 특정 객체의 학번의 값을 바꿔줌
        m_Id = inId;
    }
    void SetName(string inName){// 키보드로 학생 이름 입력 함수 -> 특정 객체의 이름의 값을 바꿔줌
        
        m_sName = inName;
    }
    void SetAddress(string inAddress){// 키보드로 학생 주소 입력 함수 -> 특정 객체의 주소의 값을 바꿔줌
        
        m_sAddress = inAddress;
    }
    void SetRecord(int inId, string inName, string inAddress){// 키보드로 학생 정보 입력 함수 -> 특정 객체의 전체 값을 바꿔줌
        SetId(inId);
        SetName(inName);
        SetAddress(inAddress);
    }
    void DisplayIdOnScreen(){
        cout<<"\t ID: "<<m_Id<<endl;
    }
    void DisplayNameOnScreen(){
        cout<<"\t Name: "<<m_sName<<endl;
    }
    void DisplayAddressOnScreen(){
        cout<<"\t Address: "<<m_sAddress<<endl;
    }
    void DisplayRecordOnScreen(){
        DisplayIdOnScreen();
        DisplayNameOnScreen();
        DisplayAddressOnScreen();
        cout<<endl;
    }
    void SetIdFromKB();
    void SetNameFromKB();
    void SetAddressFromKB();
    void SetRecordFromKB();
    int ReadDataFromFile(ifstream& fin);
    int WriteDataToFile(ofstream& fout);
    RelationType CompareByID(const ItemType &data);
    
    //bool operator==(const ItemType& data) const;
    bool operator==(const ItemType& data) const;
};

