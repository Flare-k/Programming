#pragma once

template <typename T>
struct NodeType
{
	T info;
	NodeType<T>* next;
};

template <typename T>
class SingleLinkedList {
public:
	SingleLinkedList();
	~SingleLinkedList();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
    int Push(T newItem);
	bool Pop(T& item);
    void GetNextItem(T& item);
    void ResetList();
    bool Retrieve(T& item);
    int getLength();

private:
	NodeType<T>* topPtr;
    NodeType<T>* m_pCurPointer;
    int m_length;
};

template <typename T>
SingleLinkedList<T>::SingleLinkedList()
{
    m_length =0;
    m_pCurPointer = nullptr;
}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
    //MakeEmpty();
}

template <typename T>
void SingleLinkedList<T>::MakeEmpty()
{
	NodeType<T>* tempPtr;

    while (topPtr)
	{
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
	}
}
template <typename T>
bool SingleLinkedList<T>::IsEmpty() const
{
    return topPtr == nullptr;
}
template <typename T>
bool SingleLinkedList<T>::IsFull() const
{
    return false;
}

template <typename T>
int SingleLinkedList<T>::Push(T newItem)
{
    T temp;
	if (IsFull())
        return -1;
    else if (Retrieve(newItem))
        return 0;
	NodeType<T>* location;
	location = new NodeType<T>;
	location->info = newItem;
	location->next = topPtr;
    topPtr = location;
    m_length++;
    return 1;
}
template <typename T>
bool SingleLinkedList<T>::Pop(T& item)
{
	if (IsEmpty())
		return false;
	NodeType<T>* temp;
	temp = topPtr;
	item = topPtr->info;
	topPtr = topPtr->next;
	delete temp;
    m_length--;

}

template <typename T>
void SingleLinkedList<T>::GetNextItem(T& item)
{
    if (m_pCurPointer==nullptr)
        m_pCurPointer = topPtr;
    else
    {
        m_pCurPointer = m_pCurPointer->next;
    }
    item = m_pCurPointer->info;
}

template <typename T>
void SingleLinkedList<T>::ResetList()
{
    m_pCurPointer =nullptr;
}

template <typename T>
bool SingleLinkedList<T>::Retrieve(T& item)
{
    T temp;
    ResetList();
    for (int i=0;i<m_length;i++)
    {
        GetNextItem(temp);
        if (temp==item)
        {
            item = temp;
            return true;
        }
    }
    return false;
}

template <typename T>
int SingleLinkedList<T>::getLength()
{
    return m_length;
}
