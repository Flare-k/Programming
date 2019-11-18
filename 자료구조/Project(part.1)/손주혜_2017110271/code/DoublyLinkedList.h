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
	NodeType<T> *head; // ����Ʈ�� ó�� ��带 ����Ű�� ������ 
	NodeType<T> *tail; // ����Ʈ�� ������ ��带 ����Ű�� ������ 
	NodeType<T> *listData;
	int m_nLength; // ����Ʈ�� ����� ���ڵ� �� 
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	bool IsEmpty();

	int GetLength() const; // ����Ʈ�� �����ϰ� �ִ� item ���� ��ȯ 
	void Add(T &item); // ���ο� ���ڵ� �߰� 
	void Delete(T &item); // ���� ���ڵ� ����
	void Replace(T& item); // ���� ���ڵ� ����
	int Get(T &item); // item�� primary key�� ���� ����Ʈ �� �������� �Ҵ���
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

	if (IsEmpty()) {//iter�� head���� ����Ŵ
		head->next = NewItem;

		tail->prev = NewItem;

		NewItem->prev = head;

		NewItem->next = tail;

		m_nLength++;//Ȯ��

	}
	else//��尡 �Ѱ� �̻� ���� ���
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
			cout << "playlist���� ����� �Ϸ�" << endl;
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

