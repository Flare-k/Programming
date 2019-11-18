#pragma once
#include "DoublyLinkedList.h" //이거 안써야 NodeType<T>가 먹힘..
#include <iostream>
using namespace std;

template <typename T> class DoublyLinkedList;//이걸 왜 써줘야..
template <typename T> class NodeType;//이걸 왜 써줘야..?
template <typename T>
class DoublyIterator {
private:
	friend class DoublyLinkedList<T>;
	friend class NodeType<T>;

	const DoublyLinkedList<T> &m_List; // 사용할 리스트의 참조 변수 
	NodeType<T> *m_pCurPointer; // Iterator 변수

public:
	DoublyIterator(const DoublyLinkedList<T> &list) :
		m_List(list), m_pCurPointer(list.head) {}; // Default constructor 
	bool Null(); // list의 현재 원소가 Null이 아닌지 검사
	bool NextNull(); // list의 다음 원소가 Null이 아닌지 검사
	T FirstData(); // list의 처음 node의 item을 리턴 
	T NextData(); // 다음 node로 이동하고 해당 node의 item을 리턴
	T LastData();
	T GetData();
	NodeType<T>* GetCurrentNode();
	void Reset();
	void GetNext();
	void GetPre();
};

//template<typename T>
//NodeType<T>* DoublyIterator<T>::G

template<typename T>
bool DoublyIterator<T>::Null()
{

	return (m_pCurPointer == NULL);
}
template<typename T>
bool DoublyIterator<T>::NextNull()
{
	return (m_pCurPointer->next == NULL);
}
template<typename T>
T DoublyIterator<T>::FirstData()
{
	m_pCurPointer = m_List.head;
	return (m_pCurPointer->data);
}

template<typename T>
T DoublyIterator<T>::NextData()
{
	m_pCurPointer = m_pCurPointer->next;
	return (m_pCurPointer->data);
}

template<typename T>
T DoublyIterator<T>::LastData()
{
	m_pCurPointer = m_List.tail;
	return m_pCurPointer->data;
}

template<typename T>
T DoublyIterator<T>::GetData()
{
	return m_pCurPointer->data;

}

template<typename T>
NodeType<T>* DoublyIterator<T>::GetCurrentNode()
{
	return (m_pCurPointer);
}

template<typename T>
void DoublyIterator<T>::Reset()
{
	m_pCurPointer = m_List.head;
}

template<typename T>
void DoublyIterator<T>::GetNext()
{
	m_pCurPointer = m_pCurPointer->next;
}

template<typename T>
void DoublyIterator<T>::GetPre()
{
	m_pCurPointer = m_pCurPointer->prev;
}

