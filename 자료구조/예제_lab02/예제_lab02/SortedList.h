#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ItemType.h"


class SortedList{
    
private:
    ItemType m_Array[MAXSIZE]; //레코드 배열, 객체를 배열의 형태로 만듬.
    int m_Length;       //리스트에 저장된 레코드 수
    int m_CurPointer;
    
public:
    SortedList(){
        m_Length = 0;
        ResetList();
    }
    ~SortedList(){}
    
    
    void MakeEmpty();
    int GetLength();
    bool IsFull();
    bool IsEmpty();
    void ResetList();
    int GetNextItem(ItemType& data);
    
    int Add(ItemType data);
    int Delete(ItemType data);
    
    int Replace(ItemType data);
    int Retrieve_Seq(ItemType& data);
    int Retrieve_Binary(ItemType& data);
    
    
};

