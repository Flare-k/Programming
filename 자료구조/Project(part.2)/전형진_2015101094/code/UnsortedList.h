#pragma once
#define MAXS 10

template <typename T>
class UnsortedList
{
public:
    UnsortedList();
    ~UnsortedList();	// default destructor

    void MakeEmpty();
    int GetLength();
	bool IsEmpty();
    bool IsFull();
    int Add(T data);
	void ResetList();
    int GetNextItem(T& data);
    bool Delete(T data);
    bool Replace(T data);
    bool Retrieve(T& inData);
    void ChangeSequence(int index1, int index2);
    T at(int i);


private:
    T m_Array[MAXS];  		// 레코드 배열
	int m_Length;				// 리스트에 저장된 레코드 수
	int m_CurPointer;			// current pointer
};

template <typename T>
UnsortedList<T>::UnsortedList() {
    m_Length = 0;
    ResetList();
}

template <typename T>
UnsortedList<T>::~UnsortedList() {
}

template <typename T>
bool UnsortedList<T>::IsEmpty() {
    return m_Length == 0;
}

template <typename T>
void UnsortedList<T>::MakeEmpty() {
    m_Length = 0;
}

template <typename T>
int UnsortedList<T>::GetLength() {
    return m_Length;
}

template <typename T>
bool UnsortedList<T>::IsFull() {
    return m_Length == MAXS;
}

template <typename T>
int UnsortedList<T>::Add(T data)
{
    if (IsFull())
        return -1;
    else if (Retrieve(data)== true)
        return 0;
    else //Array에 공간이 남아있을 경우 추가
    {
        m_Array[m_Length] = data;
        m_Length++;
        return 1;
    }

}

template <typename T>
void UnsortedList<T>::ResetList() {
    m_CurPointer = -1;
}

template <typename T>
int UnsortedList<T>::GetNextItem(T& data) {
    m_CurPointer++;
    if (m_CurPointer >= m_Length)
        return -1;
    else {
        data = m_Array[m_CurPointer];
        return m_CurPointer;
    }
}

template <typename T>
T UnsortedList<T>::at(int index)
{
    return m_Array[index];
}

template <typename T>
bool UnsortedList<T>::Delete(T data) {

    if (Retrieve(data)) {
        for (int i = m_CurPointer; i < m_Length - 1; i++) {
            m_Array[i] = m_Array[i + 1];
        }
        m_Length--;
        return true;
    }
    else
        return false;
}

template <typename T>
bool UnsortedList<T>::Replace(T data) {
    if (Retrieve(data))
    {
        m_Array[m_CurPointer] = data;
        return true;
    }
    return false;
}


template <typename T>
bool UnsortedList<T>::Retrieve(T& inData)
{
    ResetList();
    T temp;
    while (GetNextItem(temp) != -1)
    {
        if (inData == temp)
        {
            inData = temp;
            return true;
        }
    }
    return false;
}


template <typename T>
void UnsortedList<T>::ChangeSequence(int index1, int index2)
{
    T temp = m_Array[index1];
    m_Array[index1] = m_Array[index2];
    m_Array[index2] = temp;
}

