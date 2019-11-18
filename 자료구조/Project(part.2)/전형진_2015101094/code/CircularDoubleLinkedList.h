#pragma once

#define MAAX 10
/**
*	���Ḯ��Ʈ���� ���̴� NodeType�� ����ü
*/
template <typename T>
struct DoubleNodeType
{
    T info; ///< �� ����� ������
    DoubleNodeType<T>* next; ///< ����� ������ ����Ű�� ������.
    DoubleNodeType<T>* prev; ///< ����� ���� ����Ű�� ������.

};

/**
*	�����ȯ���Ḯ��Ʈ Ŭ����
*/
template <typename T>
class CircularDoubleLinkedList {
public:
    /**
    *	����Ʈ ������.
    */
    CircularDoubleLinkedList();

    /**
    *	�Ҹ���.
    */
    ~CircularDoubleLinkedList();

    /**
    *	@brief	����Ʈ�� ����.
    *	@pre	����.
    *	@post	topPtr endPtr�� ������ ��� �����͸� �����.
    */
	void MakeEmpty();

    /**
    *	@brief	����Ʈ�� ���̸� ��ȯ�Ѵ�.
    *	@pre	����.
    *	@post	����Ʈ�� ���̸� ��ȯ.
    *	@return	m_Length ����Ʈ�� ���� ��ȯ.
    */
    int GetLength();

    /**
    *	@brief	����Ʈ�� ������� �ƴ��� �˻��Ѵ�.
    *	@pre	m_Length�� ���� ������ �־�� �Ѵ�.
    *	@post	������� �ƴ����� �˷��ش�.
    *	@return	��������� true, �ƴϸ� false�� ��ȯ.
    */
	bool IsEmpty() const;

    /**
    *	@brief	����Ʈ�� ���� á���� �ƴ��� �˻��Ѵ�.
    *	@pre	m_Length�� ���� ������ �־�� �Ѵ�.
    *	@post	���� á���� �ƴ����� �˷��ش�.
    *	@return	���� �������� true, �ƴϸ� false�� ��ȯ.
    */
	bool IsFull() const;

    /**
    *	@brief	���ο� �������� ����Ʈ�� �߰��Ѵ�.
    *	@pre	item�� �Է¹޴´�.
    *	@post	�������� ����Ʈ�� �߰��Ѵ�.
    *	@return	���� �������� ������ 0�� ��ȯ�ϰ�, �Է¿� �����ϸ� 1�� ��ȯ. ����Ʈ�� �� �������� -1 ��ȯ.
    */
    int Add(T newItem);

    /**
    *	@brief	m_pCurPointer�� �ʱ�ȭ�Ѵ�.
    *	@post	m_pCurPointer�� nullptr�� �ʱ�ȭ�Ѵ�.
    */
    void ResetList();

    /**
    *	@brief	���� �������� �������� �����´�.
    *	@pre	item�� �Է¹޴´�.
    *	@post	���� �������� �������� item�� �ִ´�.
    */
    void GetNextItem(T& item);

    /**
    *	@brief	�Է¹��� �������� ����Ʈ���� �����Ѵ�.
    *	@pre	item�� �Է¹޴´�.
    *	@post	�Է¹��� �������� ����Ʈ���� ã�� �����Ѵ�.
    */
    bool Delete(T data);

    /**
    *	@brief	�Է¹��� �������� ������ ���Ͽ� ���� ����Ʈ�� �������� �����´�.
    *	@pre	item�� �Է¹޴´�.
    *	@post	�˻��� �����͸� �����ۿ� �ִ´�.
    *	@return	��ġ�ϴ� �����͸� ã���� true, �׷��� ������ false�� ��ȯ.
    */
    bool Retrieve(T& item);

    /**
    *	@brief	�Է¹��� index�� �������� list���� �����´�.
    *	@pre	index�� �Է¹޴´�.
    *	@post	�˻��� �����͸� �����ۿ� �ִ´�.
    *	@return	�Է¹��� index�� ������.
    */
    T at(int index);

    /**
    *	@brief	�� ���� �������� info�� ���� swap�Ѵ�.
    *	@pre	index 2���� �Է¹޴´�.
    *	@post	�� ���� �������� info�� ���� swap�Ѵ�.
    */
    void ChangeSequence(int, int);


private:
    DoubleNodeType<T>* topPtr; ///< ����Ʈ�� �Ǥä��� ó��.
    DoubleNodeType<T>* endPtr;  ///< ����Ʈ�� �� ��.
    DoubleNodeType<T>* m_pCurPointer; ///< ����Ʈ ������.
    int m_length; ///< ����Ʈ�� ����.
};

// ����Ʈ�� ���̸� 0���� �ʱ�ȭ���ѳ��´�.
template <typename T>
CircularDoubleLinkedList<T>::CircularDoubleLinkedList()
{
    topPtr = new DoubleNodeType<T>;
    endPtr = new DoubleNodeType<T>;

    topPtr->next = endPtr;
    topPtr->prev = endPtr;
    endPtr->next = topPtr;
    endPtr->prev = topPtr;

    m_length =0;
    m_pCurPointer = nullptr;
}

template <typename T>
CircularDoubleLinkedList<T>::~CircularDoubleLinkedList()
{
    /*DoubleNodeType<T>* current = topPtr;
    while(current)
    {
        DoubleNodeType<T>* next =current->next;
        delete current;
        current = next;
    }*/
}

template <typename T>
void CircularDoubleLinkedList<T>::MakeEmpty()
{
    DoubleNodeType<T>* tempPtr;

    while (topPtr-> next == endPtr)
    {
        tempPtr = topPtr->next;
        topPtr->next = tempPtr->next;
        delete tempPtr;
    }
}
template <typename T>
bool CircularDoubleLinkedList<T>::IsEmpty() const
{
    return topPtr == endPtr;
}
template <typename T>
bool CircularDoubleLinkedList<T>::IsFull() const
{
    return m_length == MAAX;
}

//full:-1, succeed:1
template <typename T>
int CircularDoubleLinkedList<T>::Add(T newItem)
{
	if (IsFull())
        return -1;
    else if (Retrieve(newItem))
        return 0;
    DoubleNodeType<T>* newlocation = new DoubleNodeType<T>;
    newlocation->info = newItem;

    if(IsEmpty())
    {
        newlocation->next = endPtr;
        newlocation->prev = topPtr;
        topPtr->next = newlocation;
        endPtr->prev = newlocation;
    }
    else
    {
        newlocation->next = topPtr->next;
        newlocation->prev = topPtr;
        topPtr->next = newlocation;
    }
    m_length++;
    return 1;
}


template <typename T>
void CircularDoubleLinkedList<T>::GetNextItem(T& item)
{
    if (m_pCurPointer == nullptr)
        m_pCurPointer = topPtr->next;

    else
    {
        m_pCurPointer = m_pCurPointer -> next;
        if (m_pCurPointer==topPtr || m_pCurPointer==endPtr)
        {
            m_pCurPointer = topPtr->next;
        }
    }
    item = m_pCurPointer->info;
}

template <typename T>
void CircularDoubleLinkedList<T>::ResetList()
{
    m_pCurPointer =nullptr;
}

template <typename T>
bool CircularDoubleLinkedList<T>::Retrieve(T& item)
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
int CircularDoubleLinkedList<T>::GetLength()
{
    return m_length;
}

template <typename T>
bool CircularDoubleLinkedList<T>::Delete(T item)
{
    if (Retrieve(item))
    {
        m_pCurPointer->prev->next = m_pCurPointer->next;
        m_pCurPointer->next->prev = m_pCurPointer->prev;

        delete m_pCurPointer;
        m_pCurPointer=nullptr;

        m_length--;
        return true;
    }
    return false;

}

template <typename T>
T CircularDoubleLinkedList<T>::at(int index)
{
    T temp;
    ResetList();
    for (int i=0;i<=index;i++)
    {
        GetNextItem(temp);
    }
    return temp;
}

template <typename T>
void CircularDoubleLinkedList<T>::ChangeSequence(int index1, int index2)
{
    T temp;
    ResetList();
    at(index1);
    DoubleNodeType<T>* node1 = m_pCurPointer;

    ResetList();
    at(index2);
    DoubleNodeType<T>* node2 = m_pCurPointer;

    temp = node1->info;
    node1->info = node2->info;
    node2->info = temp;
}
