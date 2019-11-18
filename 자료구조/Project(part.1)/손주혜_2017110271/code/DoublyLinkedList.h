#pragma once
#include "DoublyIterator.h"

template <typename T>
class NodeType {
	friend class DoublyLinkedList<T>;
	friend class DoublyIterator<T>;

private:
	T data;
	NodeType *prev, *next;
};

template <class T>
class DoublyLinkedList {
	friend class DoublyIterator<T>;
private:
	NodeType<T> *head; // 리스트의 처음 노드를 가리키는 포인터 
	NodeType<T> *tail; // 리스트의 마지막 노드를 가리키는 포인터 
	NodeType<T> *listData;
	int m_nLength; // 리스트에 저장된 레코드 수 
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	bool IsEmpty();

	int GetLength() const; // 리스트가 보유하고 있는 item 개수 반환 
	void Add(T &item); // 새로운 레코드 추가 
	void Delete(T &item); // 기존 레코드 삭제
	void Replace(T& item); // 기존 레코드 갱신
	int Get(T &item); // item과 primary key가 같은 리스트 내 아이템을 할당함
};


template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	head = tail = NULL;
	head = new NodeType<T>;
	tail = new NodeType<T>;
	head->next = tail;
	head->prev = NULL;
	tail->prev = head;
	tail->next = NULL;

}


template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
	listData = head;
	while(listData!=tail){
		delete listData;
	}
	delete head;
	delete tail;
}

template<class T>
bool DoublyLinkedList<T>::IsEmpty()
{
	return (m_nLength == 0);
}

template<class T>
int DoublyLinkedList<T>::GetLength() const
{
	return m_nLength;
}

template<class T>
void DoublyLinkedList<T>::Add(T &item)
{
	DoublyIterator<T>iter(*this);

	NodeType<T> *NewItem;
	NewItem = new NodeType<T>;
	NewItem->data = item;

	if (IsEmpty()) {//iter은 head값을 가리킴
		head->next = NewItem;

		tail->prev = NewItem;

		NewItem->prev = head;

		NewItem->next = tail;

		m_nLength++;//확인

	}
	else//노드가 한개 이상 있을 경우
	{
		NewItem->prev = tail->prev;
		NewItem->next = tail;
		tail->prev->next = NewItem;
		tail->prev = NewItem;
		m_nLength++;
	}
		

	
}

template<class T>
void DoublyLinkedList<T>::Delete(T & item)
{
	DoublyIterator<T>iter(*this);
	iter.Reset();
	while (!iter.Null()) {
		if (item == iter.GetCurrentNode()->data) {
			listData = iter.GetCurrentNode();
			listData->prev->next = listData->next;
			listData->next->prev = listData->prev;
			delete iter.GetCurrentNode();
			m_nLength--;
			cout << "playlist에서 지우기 완료" << endl;
			break;
		}
		else
			iter.GetNext();

	}
}



template<class T>
void DoublyLinkedList<T>::Replace(T& item)
{

	listData = head->next;
	while (listData != tail) {

		if (item == listData->data) {
			listData->data = item;
			break;
		}
		else listData = listData->next;
	}

}


template<class T>
int DoublyLinkedList<T>::Get(T & item)
{
	listData = head->next;
	while (listData != tail) {
		if (item == listData->data) {
			item = listData->data;
			return 1;
		}
	}
	return 0;
}

