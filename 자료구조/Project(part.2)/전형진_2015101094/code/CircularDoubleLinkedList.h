#pragma once

#define MAAX 10
/**
*	연결리스트에서 쓰이는 NodeType의 구조체
*/
template <typename T>
struct DoubleNodeType
{
    T info; ///< 각 노드의 데이터
    DoubleNodeType<T>* next; ///< 노드의 다음를 가리키는 포인터.
    DoubleNodeType<T>* prev; ///< 노드의 앞을 가리키는 포인터.

};

/**
*	더블순환연결리스트 클래스
*/
template <typename T>
class CircularDoubleLinkedList {
public:
    /**
    *	디폴트 생성자.
    */
    CircularDoubleLinkedList();

    /**
    *	소멸자.
    */
    ~CircularDoubleLinkedList();

    /**
    *	@brief	리스트를 비운다.
    *	@pre	없음.
    *	@post	topPtr endPtr를 제외한 모든 데이터를 지운다.
    */
	void MakeEmpty();

    /**
    *	@brief	리스트의 길이를 반환한다.
    *	@pre	없음.
    *	@post	리스트의 길이를 반환.
    *	@return	m_Length 리스트의 길이 반환.
    */
    int GetLength();

    /**
    *	@brief	리스트가 비었는지 아닌지 검사한다.
    *	@pre	m_Length가 값을 가지고 있어야 한다.
    *	@post	비었는지 아닌지를 알려준다.
    *	@return	비어있으면 true, 아니면 false를 반환.
    */
	bool IsEmpty() const;

    /**
    *	@brief	리스트가 가득 찼는지 아닌지 검사한다.
    *	@pre	m_Length가 값을 가지고 있어야 한다.
    *	@post	가득 찼는지 아닌지를 알려준다.
    *	@return	가득 차있으면 true, 아니면 false를 반환.
    */
	bool IsFull() const;

    /**
    *	@brief	새로운 아이템을 리스트에 추가한다.
    *	@pre	item을 입력받는다.
    *	@post	아이템을 리스트에 추가한다.
    *	@return	같은 아이템이 있으면 0을 반환하고, 입력에 성공하면 1을 반환. 리스트가 꽉 차있으면 -1 반환.
    */
    int Add(T newItem);

    /**
    *	@brief	m_pCurPointer를 초기화한다.
    *	@post	m_pCurPointer를 nullptr로 초기화한다.
    */
    void ResetList();

    /**
    *	@brief	다음 포인터의 아이템을 가져온다.
    *	@pre	item을 입력받는다.
    *	@post	다음 포인터의 아이템을 item에 넣는다.
    */
    void GetNextItem(T& item);

    /**
    *	@brief	입력받은 아이템을 리스트에서 삭제한다.
    *	@pre	item을 입력받는다.
    *	@post	입력받은 아이템을 리스트에서 찾아 삭제한다.
    */
    bool Delete(T data);

    /**
    *	@brief	입력받은 아이템의 정보와 비교하여 같은 리스트의 아이템을 가져온다.
    *	@pre	item을 입력받는다.
    *	@post	검색된 데이터를 아이템에 넣는다.
    *	@return	일치하는 데이터를 찾으면 true, 그렇지 않으면 false을 반환.
    */
    bool Retrieve(T& item);

    /**
    *	@brief	입력받은 index의 아이템을 list에서 가져온다.
    *	@pre	index을 입력받는다.
    *	@post	검색된 데이터를 아이템에 넣는다.
    *	@return	입력받은 index의 아이템.
    */
    T at(int index);

    /**
    *	@brief	두 개의 아이템의 info를 서로 swap한다.
    *	@pre	index 2개를 입력받는다.
    *	@post	두 개의 아이템의 info를 서로 swap한다.
    */
    void ChangeSequence(int, int);


private:
    DoubleNodeType<T>* topPtr; ///< 리스트의 맨ㅓㅅ버 처음.
    DoubleNodeType<T>* endPtr;  ///< 리스트의 맨 끝.
    DoubleNodeType<T>* m_pCurPointer; ///< 리스트 포인터.
    int m_length; ///< 리스트의 길이.
};

// 리스트의 길이를 0으로 초기화시켜놓는다.
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
