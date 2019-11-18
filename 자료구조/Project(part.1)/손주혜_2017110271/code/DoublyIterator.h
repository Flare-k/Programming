#pragma once
#include "DoublyLinkedList.h" //�̰� �Ƚ�� NodeType<T>�� ����..
#include <iostream>
using namespace std;

template <typename T> class DoublyLinkedList;//�̰� �� �����..
template <typename T> class NodeType;//�̰� �� �����..?
template <typename T>
class DoublyIterator {
private:
	friend class DoublyLinkedList<T>;
	friend class NodeType<T>;

	const DoublyLinkedList<T> &m_List; // ����� ����Ʈ�� ���� ���� 
	NodeType<T> *m_pCurPointer; // Iterator ����

public:
	DoublyIterator(const DoublyLinkedList<T> &list) :
		m_List(list), m_pCurPointer(list.head) {}; // Default constructor 
	bool Null(); // list�� ���� ���Ұ� Null�� �ƴ��� �˻�
	bool NextNull(); // list�� ���� ���Ұ� Null�� �ƴ��� �˻�
	T FirstData(); // list�� ó�� node�� item�� ���� 
	T NextData(); // ���� node�� �̵��ϰ� �ش� node�� item�� ����
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

