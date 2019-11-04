#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//#include "SimpleItemType.h"

//Song List

template<typename T>
class UnsortedList{
private:
    T *m_Array; //객체를 배열의 형태로 만듬.
    int m_Length;       //리스트에 저장된 레코드 수
    int m_CurPointer;   //current pointer  -> iterator
    
public:
    UnsortedList();
    ~UnsortedList();
    
    void MakeEmpty();
    /*
     비어있는지 확인하는 함수, 비어있음 = 배열의 길이 0
     */
    int GetLength();
    /*
     길이를 리턴하는 함수
     */
    bool IsFull();
    /*
     꽉 차 있는지 확인하는 함수
     */
    bool IsEmpty();
    /*
     리스트가 비어있는지 확인하는 함수
     */
    int Add(T& data);
    /*
     리스트에 추가하는 함수
     */
    int Get(T& data);
    /*
      Primary key를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
     */
    void ResetList();
    /*
     레코드 포인터(current pointer) 초기화   current pointer를 0으로 초기화
     */
    int GetNextItem(T& data);
    /*
      current pointer를 하나 증가시키고 끝이 아니면 record index를 리턴 끝이면 -1을 리턴
     */
    int Delete(T& data);
    /*
     기존 레코드 삭제
     */
    int ReplaceItem(T& data);
    /*
     입력된 data와 Primary key와 동일한 기록을 찾아서 List의 해당 기록을 입력된 data로 치환한다.
     */
    
    
};

template<typename T>
UnsortedList<T>::UnsortedList(){
    m_Length = 0;
    m_Array = new T[MAXSIZE];
    ResetList();
}
template<typename T>
UnsortedList<T>::~UnsortedList(){
    delete [] m_Array;
}
template<typename T>
void UnsortedList<T>::MakeEmpty(){
    m_Length = 0;
}

template<typename T>
int UnsortedList<T>::GetLength(){
    return m_Length;
}
template<typename T>
bool UnsortedList<T>::IsFull(){
    if(m_Length != MAXSIZE)
        return 0;
    else
        return 1;
}
template<typename T>
bool UnsortedList<T>::IsEmpty(){
    if(m_Length != 0)
        return 0;
    else
        return 1;
}
template<typename T>
int UnsortedList<T>::Add(T& data){
    if(!IsFull()){
        m_Array[m_Length] = data;
        m_Length++;
        return 1;
    }
    else
        return 0;
}
template<typename T>
int UnsortedList<T>::Delete(T& data){ // 기존 레코드 삭제
    if(IsEmpty())
        return 0;
    
    for(int i = 0; i < m_Length ; i++){
        if(data == m_Array[i]){
            if(i == m_Length-1)
                m_Length--;
            else{
                for(; i<m_Length ; i++){
                    m_Array[i] = m_Array[i+1];
                }
                m_Length--;
                return 1;
            }
        }
    }
    return 0;
}
template<typename T>
int UnsortedList<T>::Get(T& data){
    for(int i = 0; i < m_Length; i++){
        if(data == m_Array[i]){     //이때는 primary 가지고 만 비교
            data = m_Array[i];      //data에 m_Array에 있는 값을 넣어줌 -> 이 줄이 있어야 출력할 때, 해당 인덱스의 내용이 전달된다.
            cout<<endl;
            return 1;
        }
    }
    return 0;
}

template<typename T>
void UnsortedList<T>::ResetList(){
    m_CurPointer = -1;
}
template<typename T>
int UnsortedList<T>::GetNextItem(T& data){
    m_CurPointer++;
    
    if(m_Length == m_CurPointer)
        return -1;
    
    data = m_Array[m_CurPointer];
    
    return 1;
    
}
template<typename T>
int UnsortedList<T>::ReplaceItem(T& data){
    for(int i = 0; i < m_Length; i++){
        if(data == m_Array[i]){
            m_Array[i] = data;
            return 1;
        }
    }
    
    return 0;
}


