#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "D_LinkedList.h"
using namespace std;


template<typename T>
class DNode;
template<typename T>
class D_LinkedList;
//=============================================================================
template<typename T>
class DIterator{
    friend class D_LinkedList<T>;
private:
    const D_LinkedList<T> &D_List;  //사용할 리스트의 참조변수
    DNode<T>* cur;  //Iterator 변수
public:
    DIterator(const D_LinkedList<T>& list): D_List(list), cur(list.head){};
    //Default Constructor
    bool NotNull();     //list의 현재 원소가 Null이 아닌지 검사
    bool NextNotNull(); //list의 다음 원소가 Null이 아닌지 검사
    T First(); // list의 처음 node의 item을 리턴
    T Next();  // 다음 node로 이동하고 해당 node
    bool NextData();
    DNode<T> GetCurNode();
    void ResetList();
    void GetCurItem(T& data);
};

template<typename T>
bool DIterator<T>::NotNull(){
    if(cur != NULL)
        return true;
    else
        return false;
}

template<typename T>
bool DIterator<T>::NextNotNull(){
    if(cur->next == NULL)
        return false;
    else
        return true;
}

template<typename T>
T DIterator<T>::First(){
    return D_List.head->data;
}

template<typename T>
T DIterator<T>::Next(){
    cur = cur->next;
    return cur->data;
}

template<typename T>
DNode<T> DIterator<T>::GetCurNode(){
    return *cur;
}

template<typename T>
bool DIterator<T>::NextData(){
    return cur = cur->next;
}



template <typename T>
void DIterator<T>::ResetList(){
    cur = D_List.head; //더미노드를 가리키기 위해.
}


// current pointer를 하나 증가시키고 끝이 아니면 record index를 리턴 끝이면 -1을 리턴
template <typename T>
void DIterator<T>::GetCurItem(T& data){
    if(cur == D_List.head)
        cur = D_List.head->next;     //cur이 NULL이면 더미노드 옆에 있는 사실상 첫값을 가리키게함.
    else
        cur = cur->next; //현재 가리켰던 값의 다음 값.
    data = cur->data;
    //현재의 데이터를 객체에 담아준다. 빈 객체가 들어올 예정
}
