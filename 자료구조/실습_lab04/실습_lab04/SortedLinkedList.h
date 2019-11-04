#pragma once
#include <iostream>
#include <string>
#include <fstream>
//#include "Singer.h"
//#include "SimpleItemType.h"

using namespace std;

//Singer List

template<typename T>
class Node{
public:
    T data;
    Node *next;
};

template <typename T>
class SortedLinkedList{
private:
    int m_Length;
    Node<T>* head;  //첫번째 노드를 가리키는 부분
    Node<T>* cur;   //현재 노드를 가리키는 부분
public:
    SortedLinkedList();
    ~SortedLinkedList();
    
    void MakeEmpty();
    int GetLength();
    void ResetList();
    void GetCurItem(T& item);
    bool IsFull();
    bool IsEmpty();
    
    int Add(T& item);
    int Delete(T& item);
    int Get(T& item);
    int Replace(T& item);
    
};
template<typename T>
SortedLinkedList<T>::SortedLinkedList(){
    m_Length = 0;
    head = NULL;
    cur = NULL;
}

//길이를 0으로 초기화 시키는 함수
template <typename T>
void SortedLinkedList<T>::MakeEmpty(){
    Node<T>* temp;
    
    while(head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
    m_Length = 0;
}

template<typename T>
SortedLinkedList<T>::~SortedLinkedList(){
    MakeEmpty();
}

template<typename T>
bool SortedLinkedList<T>::IsEmpty(){
    if(head == NULL)
        return true;
    else
        return false;
}
template<typename T>
bool SortedLinkedList<T>::IsFull(){
    if(cur->next == NULL)
        return true;
    else
        return false;
}

//길이를 리턴하는 함수
template <typename T>
int SortedLinkedList<T>::GetLength(){
    return m_Length;
}

// 레코드 포인터(current pointer) 초기화
template <typename T>
void SortedLinkedList<T>::ResetList(){
    cur = NULL;
}


// current pointer를 하나 증가시키고 끝이 아니면 record index를 리턴 끝이면 -1을 리턴
template <typename T>
void SortedLinkedList<T>::GetCurItem(T& item){
    if(cur == NULL)
        cur = head;     //만약 현재가리키는 노드가 아무것도 없으면 헤드와 다를게 없으므로 헤드를 할당.
    else
        cur = cur->next; //현재 가리켰던 값의 다음 값을 저장. 즉, 저장되있는 값 중 끝값을 향하게 됨.
    
    item = cur->data;
    //현재의 데이터를 객체에 담아준다. 빈 객체가 들어올 예정
}


//배열에 추가하는 함수
template <typename T>
int SortedLinkedList<T>::Add(T& item){
    ResetList();        //cur을 NULL로 초기화해줌.
    
    Node<T>* newnode = new Node<T>;    //node라는 새로운 노드 생성, 여기다가 값을 받을 예정.
    Node<T>* pre;
    
    newnode->data = item;
    newnode->next = NULL;
    
    T dummyItem;
    

    if(head == NULL)    //노드에 아무것도 없으면?
        head = newnode; //새로 생성한 노드가 head가 된다.
    //제일 작거나 Empty에서 추가할때는 head가 바뀌어야한다.
    else{
        while(1){
            pre = cur;  //이전 노드를 NULL로 초기화 해준다. 처음부터 탐색해야하므로.
            //head에 노드값이 들어있으면 그때 cur는 NULL이 되고 pre를 다음 코드를 통해 NULL로 초기화.
            GetCurItem(dummyItem);//head에만 값이 있다고 가정하면 cur = head이다. 그런 후 두번째 조건문으로 가야 뒤에 값을 추가할 수 있고, 첫번째 조건문으로 가면 그보다 더 작은 값을 추가할 수 있다.
            //break가 없으므로 계속 돈다.
            
            if(cur->data > newnode->data){  //"입력한 데이터"가 "현재 데이터"보다 작다면
                if(pre==NULL){  //NULL번째와 0번째 사이에 오는 경우
                    newnode->next = cur;
                    head = newnode; //제일 작거나 Empty에서 추가할때는 head가 바뀌어야한다.
                    break;
                }
                //(NULL번째와 0번째 사이에 오는)이외의 경우.
                newnode->next = cur;
                pre->next = newnode;
                break;
            }
            if(cur->next == NULL){  //head에만 값이 있는경우. cur->next는 NULL이므로 cur->next에 newnode를 받아와야한다.
                cur->next = newnode;
                break;
                //제일 뒤에 추가할때는 node가 NULL이 되어야한다.
            }
            
            if(cur->data == newnode->data){ //현재 데이터와 입력한 데이터가 중복될경우 중복처리.
                return 0;
            }
        }
    }
    m_Length++;
    
    return 1;
}


// 기존 레코드 삭제
template <typename T>
int SortedLinkedList<T>::Delete(T& item){
    Node<T>* pre = NULL;
    
    cur = head; //시작점을 head로 고정.
    
    bool moreToSearch = (cur != NULL);
    bool found = false;
    
    while(moreToSearch && !found){
        if(item == cur->data){
            found = true;
            if(pre == NULL)
                head = cur->next;
            else{
                pre->next = cur->next;
                delete cur;
            }
            m_Length--;
        }
        else{//포인터가 하나씩 이동하므로 같지않은경우 그 다음 경우도 비교할 수 있도록 인위적으로 넘겨줘야 한다.
            pre = cur;
            cur = cur->next;
            moreToSearch = (cur != NULL); //cur값이 바뀌었으므로 다시 초기화 필요.
        }
    }
    if(found)
        return 1;
    else
        return 0;
}


template <typename T>
int SortedLinkedList<T>::Get(T& item){
    
    bool found = false;
    bool moreToSearch = (cur != NULL);
    cur = head; //시작점을 head로 고정.
    
    //그냥 쭉 탐색하고 그중에 맞는거 찾아서 할당만 하면 되니까 pre는 사용 안해도 되지않을까..?
    /* //#1
     while(cur != NULL){
     if(item == cur->data){
     item = cur->data;   //이때 cur은 head
     break;
     }
     else{   //첫 노드에서 같지 않으면 GetCurItem을 통해 다음 노드로 이동하여 비교한다. 같지 않으면 계속 다음 노드로 이동..
     GetCurItem(dummy);
     if(item == cur->data){
     item = cur->data;   //이때 cur은 head 다음 값들.
     break;
     }
     }
     }
     */
    /* //#2
    while(cur->next != NULL){
        if(item == cur->data){
            found = true;
            item = cur->data;
            break;
        }
        else{
            cur = cur->next;
        }
    }
    */
    while(moreToSearch && !found){
        if(item == cur->data){
            found = true;
            item = cur->data;
            break;
        }
        else{
            cur = cur->next;
            moreToSearch = (cur != NULL);
        }
    }
    
    if(found)
        return 1;
    else
        return 0;
}


template <typename T>
int SortedLinkedList<T>::Replace(T& item){
    
    bool found = false;
    bool moreToSearch = (cur != NULL);
    cur = head; //시작점을 head로 고정.
    
    while(moreToSearch && !found){
        if(item == cur->data){
            found = true;
            cur->data = item;
            break;
        }
        else{
            cur = cur->next;
            moreToSearch = (cur != NULL);
        }
    }
    
    
    if(found)
        return 1;
    else
        return 0;
}
