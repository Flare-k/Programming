#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "DIterator.h"
using namespace std;


/*
 Iterator Class 작성해줘야 함.
 동시에 여러군데에서 Iterator를 사용할 수 있기 위해.
 cur 포인터는 없애야 한다.
 Iterator : 초기화는 생성자로 초기화
 
 */
template<typename T>
class DIterator;

template<typename T>
class DNode{
public:
    T data;     //가운데
    DNode *prev; //왼쪽
    DNode *next; //오른쪽
};


/*
 ==================================== Doubly Linked List ====================================
 */
template<typename T>
class D_LinkedList{
    
    friend class DIterator<T>;
private:
    int m_Length;
    DNode<T>* head;  //헤드의 더미노드를 위해.
    DNode<T>* tail;  //테일의 더미노드를 위해.
    DNode<T>* cur;   //현재 노드를 가리키는 부분 (삭제, 검색, 치환에 쓸 것)
public:
    D_LinkedList();
    /*
     객체가 생성되면 head와 tail에 대해 초기화를 해주고 더미노드를 생성해준다.
     */
    ~D_LinkedList();
    /*
     프로그램이 종료되면 모든 노드가 소멸된다.
     */
    void MakeEmpty();
    /*
     모든 노드를 제거해주기 위한 함수이다.
     */
    int GetLength();
    /*
     현재 노드의 길이를 임의로 나타내가 위한 함수이다.
     */
    bool IsFull();
    /*
     현재 리스트가 가득 차 있는지 확인하는 함수이다.
     */
    bool IsEmpty();
    /*
     현재 리스트가 비어있는지 확인하는 함수이다.
     */
    void ResetList();
    /*
     현재 노드를 head의 더미노드를 가리키기 위한 함수이다.
     */
    void GetCurItem(T& data);
    /*
     현재 노드를 갱신해주기 위한 함수이다.
     */
    int Add(T data);
    /*
     현재 리스트에 Unsorted 방식으로 노드에 추가해준다.
     */
    int Delete(T& data);
    /*
     특정 노드를 제거할 때 사용되는 함수이다.
     */
    int Get(T& data);
    /*
     특정 노드를 탐색할 때 사용되는 함수이다.
     */
    int Replace(T& data);
    /*
     특정 노드를 사용자가 원하는 내용으로 변경할 때 사용되는 노드이다.
     */
    
};

template<typename T>
D_LinkedList<T>::D_LinkedList(){
    head = new DNode<T>;    //더미노드 생성
    tail = new DNode<T>;    //더미노드 생성
    
    head->next = tail;      //head의 next에 tail 노드의 주소를 저장.
    head->prev= NULL;
    tail->next = NULL;  //더미노드의 양끝은 NULL값으로 지정.
    tail->prev = head;      //tail의 prev에 head 노드의 주소를 저장.
    m_Length = 0;
}
template<typename T>
D_LinkedList<T>::~D_LinkedList(){
    delete head;
    delete tail;
}
template <typename T>
void D_LinkedList<T>::MakeEmpty(){
    DNode<T>* temp;
    DIterator<T> iter(*this);
    iter.Next();
    
    while(iter.NextNotNull()){
        temp = iter.cur;
        iter.Next();
        delete temp;
    }
    head->next = tail;
    head->prev = NULL;
    tail->prev = head;
    tail->next = NULL;
}
template<typename T>
bool D_LinkedList<T>::IsEmpty(){
    if(m_Length == 0)
        return true;
    else
        return false;
}
template<typename T>
bool D_LinkedList<T>::IsFull(){
    DIterator<T> iter(*this);
    
    if(iter.cur->next == NULL)
        return true;
    else
        return false;
}
template <typename T>
void D_LinkedList<T>::ResetList(){
    cur = NULL; //더미노드를 가리키기 위해.
}


template <typename T>
void D_LinkedList<T>::GetCurItem(T& data){
    if(cur == NULL)
        cur = head->next;     //cur이 NULL이면 더미노드 옆에 있는 사실상 첫값을 가리키게함.
    else
        cur = cur->next; //현재 가리켰던 값의 다음 값.
    
    data = cur->data;
    //현재의 데이터를 객체에 담아준다. 빈 객체가 들어올 예정
}
template<typename T>
int D_LinkedList<T>::GetLength(){
    return m_Length;
}

template<typename T>
int D_LinkedList<T>::Add(T data){
    DNode<T>* newnode = new DNode<T>; //새로운 노드 할당.
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    
    newnode->prev = tail->prev;
    tail->prev->next = newnode;
    newnode->next = tail;
    tail->prev = newnode;
    
    m_Length++;
    
    return 1;
    /*
     DIterator<T> iter(*this);   //여기서 cur값이 계속 head로 초기화 된다.
     //iter.Next();
     iter.ResetList();   //iter의 cur를 더미노드로..
     T dummyItem;
     DNode<T>* pre;
     
     if(IsEmpty()){
     DNode<T>* newnode = new DNode<T>; //새로운 노드 할당.
     newnode->data = data;
     
     head->next = newnode;
     newnode->prev = head;
     tail->prev = newnode;
     newnode->next = tail;
     
     m_Length++;
     
     cout<<"\n\t 첫 노드일 때 출력문"<<endl;
     return 1;
     }
     else{
     while(1){
     pre = iter.cur; //cur는 head
     iter.Next();
     
     if(iter.cur->data > data or iter.NextNotNull()){
     DNode<T>* newnode = new DNode<T>; //새로운 노드 할당.
     newnode->data = data;
     if(pre == head){
     newnode->prev = iter.cur->prev;
     newnode->next = iter.cur;
     iter.cur->prev->next = newnode;
     iter.cur->prev = newnode;
     m_Length++;
     break;
     }
     newnode->prev = iter.cur->prev;
     newnode->next = iter.cur;
     iter.cur->prev->next = newnode;
     iter.cur->prev = newnode;
     m_Length++;
     cout<<"\n\t 새 데이터가 작을 때 출력문"<<endl;
     return 1;
     }
     
     if(iter.cur->next == tail){
     DNode<T>* newnode = new DNode<T>; //새로운 노드 할당.
     newnode->data = data;
     
     newnode->prev = tail->prev;
     tail->prev->next = newnode;
     newnode->next = tail;
     tail->prev = newnode;
     m_Length++;
     cout<<"\n\t 새 데이터가 클 때 출력문"<<endl;
     return 1;
     }
     
     
     if(data == iter.cur->data)
     return 0;
     }
     }
     */
    /*
     newnode->prev = tail->prev;
     tail->prev->next = newnode;
     newnode->next = tail;
     tail->prev = newnode;
     */
    
    
    return 1;
}

template<typename T>
int D_LinkedList<T>::Delete(T& data){
    DIterator<T> iter(*this);
    iter.cur = head; //시작점을 head로 고정.
    
    bool moreToSearch = (iter.cur != NULL);
    bool found = false;
    
    while(moreToSearch && !found){
        if(data == iter.cur->data){
            found = true;
            
            iter.cur->prev->next = iter.cur->next;
            iter.cur->next->prev = iter.cur->prev;
            //입력 받은 객체와 노드안에 있는 값이 같으면 해당 노드를 제거해준다.
            m_Length--;
        }
        else{
            iter.cur = iter.cur->next;
            //같지 않으면 다음 노드로 이동한다.
            moreToSearch = (iter.cur != NULL); //cur값이 바뀌었으므로 다시 초기화 필요.
        }
    }
    if(found)
        return 1;
    else
        return 0;
    
    
}


template <typename T>
int D_LinkedList<T>::Get(T& data){
    DIterator<T> iter(*this);
    bool found = false;
    bool moreToSearch = (iter.cur != NULL);
    iter.cur = head; //시작점을 head로 고정.
    
    
    while(moreToSearch && !found){
        if(data == iter.cur->data){
            found = true;
            data = iter.cur->data;
            break;
        }
        else{
            iter.cur = iter.cur->next;
            moreToSearch = (iter.cur != NULL);
        }
    }
    
    if(found)
        return 1;
    else
        return 0;
}

template <typename T>
int D_LinkedList<T>::Replace(T& data){
    DIterator<T> iter(*this);
    bool found = false;
    bool moreToSearch = (iter.cur != NULL);
    iter.cur = head; //시작점을 head로 고정.
    
    while(moreToSearch && !found){
        if(data == iter.cur->data){
            found = true;
            iter.cur->data = data;
            break;
        }
        else{
            iter.cur = iter.cur->next;
            moreToSearch = (iter.cur != NULL);
        }
    }
    
    if(found)
        return 1;
    else
        return 0;
}

