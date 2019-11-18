#pragma once
#include <iostream>
#include "ItemType.h"
using namespace std;
template<typename T>
class BinaryTreeNode{
public:
    T data;             //노드에 들어갈 데이터
    BinaryTreeNode *left; //왼쪽
    BinaryTreeNode *right;//오른쪽
};

template<typename T>
class BinarySearchTree{
private:
    BinaryTreeNode<T> *root; //루트
public:
    BinarySearchTree();     //생성자
    ~BinarySearchTree();    //소멸자
    bool IsEmpty() const;   //비어있는지 확인
    bool IsFull() const;    //가득 차 있는지 확인
    void MakeEmpty();       //비우기
    int GetLength() const;  //길이
    void Add(T item);       //추가 하기
    void Delete(T item);    //트리의 노드 삭제
    void Retrieve(T& item, bool& found) const;  //트리에서 아이템 찾기
    void PrintTree(ostream& out) const;     //트리의 모든 노드를 InOrder, PreOrder, PostOrder로 출력
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree(){
    root = NULL;
}
template<typename T>
BinarySearchTree<T>::~BinarySearchTree(){
    Destruct(root);
}
template<typename T>
bool BinarySearchTree<T>::IsEmpty() const {
    if(root == NULL)
        return true;
    else
        return false;
}
template<typename T>
bool BinarySearchTree<T>::IsFull() const {
    //Full이 의미가 있을까...?
}
template<typename T>
void BinarySearchTree<T>::MakeEmpty(){
    MakeEmptyTree(root);
}
template<typename T>
int BinarySearchTree<T>::GetLength() const{
    return CountNodes(root);
}
template<typename T>
void BinarySearchTree<T>::Add(T item){
    Insert(root, item);
}
template<typename T>
void BinarySearchTree<T>::Delete(T item){
    DeleteItem(root, item);
}
template<typename T>
void BinarySearchTree<T>::Retrieve(T& item, bool& found) const{
    RetrieveItem(root, item, found);
}

template<typename T>
void BinarySearchTree<T>::PrintTree(ostream& out)const{
    cout<<"Print In Order = ";
    PrintInOrderTraversal(root, out);
    cout<<endl;
    cout<<"Print Pre Order = ";
    PrintPreOrderTraversal(root, out);
    cout<<endl;
    cout<<"Print Post Order = ";
    PrintPostOrderTraversal(root, out);
    cout<<endl;
}


// 전역함수 부분..
//Binary Search Tree의 초기화
template<typename T> void MakeEmptyTree(BinaryTreeNode<T> *&root){
    root = NULL;
}
//Binary Search Tree의 노드 개수
template<typename T> int CountNodes(BinaryTreeNode<T> *root){
    if(root == NULL)
        return 0;
    else{
        return CountNodes(root->left) + CountNodes(root->right) + 1;
    }
}
//Binary Search Tree에 새로운 노드 추가
template<typename T> void Insert(BinaryTreeNode<T>*& root, T item){
    if(root == NULL){
        root = new BinaryTreeNode<T>;   //root라는 주소를 저장하는 객체를 동적할당
        root->data = item;
        root->left = NULL;
        root->right = NULL;
    }
    else if(root->data > item){     //루트의 값이 입력한 데이터보다 크면??
        Insert(root->left, item);   //왼쪽으로 저장.(만약 그 자리가 비어있을 경우)
    }
    else if(root->data < item){     //루트의 값이 입력한 데이터보다 작으면??
        Insert(root->right, item);  //오른쪽으로 저장.(만약 그 자리가 비어있을 경우)
    }
}
//Binary Search Tree에 존재하는 노드 삭제
template<typename T> void GetPredecessor(BinaryTreeNode<T> *root, T& item){ //자식 노드중에서 가장 큰 값을 찾아야하므로 계속 오른쪽으로..
    if(root->right != NULL){
        GetPredecessor(root->right, item);
    }
    else
        item = root->data;      //마지막 노드의 right값이 NULL이면 가장 끝 값이므로 그 값을 복사해줌.
}




//이 부분 제대로 이해 필요
template<typename T> void DeleteNode(BinaryTreeNode<T>*& root){              //찾아서 복제
    T item;
    BinaryTreeNode<T> *temp;
    temp = root;    //삭제할 값을 임시로 저장해둘 것. 복사해온 값을 갱신시키면 할당 해제할 것.
    
    if(root->left == NULL){
        root = root->right;     //왼쪽 노드가 비어있으면 오른쪽 노드로 할당해놓고..
        delete temp;            //삭제할 루트는 삭제해준다.
    }   //자식 노드가 한쪽일 경우 가장 큰 건 하나밖에 없으므로..
    else if(root->right == NULL){
        root = root->left;     //오른쪽 노드가 비어있으면 왼쪽 노드로 할당해놓고..
        delete temp;            //삭제할 루트는 삭제해준다.
    }
    else{
        GetPredecessor(root->left, item);   //작은 자식(left 집합)에서 가장 큰 값이 저장됨
        root->data = item; //root->data는 현재 삭제되는 위치임. 그 위치에 item으로 갱신돼야 함.
        DeleteItem(root->left, item); //이게 무슨의미일까...?
        
    }
    
}





template<typename T> void DeleteItem(BinaryTreeNode<T>*& root, T item){          //중복되어진 값 삭제
    if(root->data > item){
        DeleteItem(root->left, item);   //왼쪽으로 이동하는 역할
    }
    else if(root->data < item){
        DeleteItem(root->right, item);  //오른쪽으로 이동하는 역할
    }
    else
        DeleteNode(root);           //여기서 삭제.
}

//Binary Search Tree 검색
template<typename T> void RetrieveItem(BinaryTreeNode<T> *root, T& item, bool& found){
    if(root == NULL)
        found = false;
    else if(root->data > item){         //삭제와 같은 구조를 보이고 있음.
        RetrieveItem(root->left, item, found);
    }
    else if(root->data < item){
        RetrieveItem(root->right, item, found);
    }
    else{
        item = root->data;
        found = true;
    }
    
}

//Binary Search Tree 출력
template<typename T> void PrintInOrderTraversal(BinaryTreeNode<T> *root, ostream &out){
    if(root != NULL){
        PrintInOrderTraversal(root->left, out);
        out<<root->data;
        PrintInOrderTraversal(root->right, out);
    }
}
template<typename T> void PrintPreOrderTraversal(BinaryTreeNode<T> *root, ostream &out){
    if(root != NULL){
        out<<root->data;
        PrintPreOrderTraversal(root->left, out);
        PrintPreOrderTraversal(root->right, out);
    }
}
template<typename T> void PrintPostOrderTraversal(BinaryTreeNode<T> *root, ostream &out){
    if(root != NULL){
        PrintPostOrderTraversal(root->left, out);
        PrintPostOrderTraversal(root->right, out);
        out<<root->data;
    }
}

template<typename T> void Destruct(BinaryTreeNode<T> *root){
    if(root != NULL){
        Destruct(root->left);
        Destruct(root->right);
        delete root;
    }
}
