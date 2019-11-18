#pragma once
#define MAXSIZE 30

template <typename T>
class SortedList
{
public:
    SortedList();
    ~SortedList();	// default destructor

	void MakeEmpty();
	int GetLength();
    bool IsFull() const;
    bool IsEmpty() const;
	int Add(T data); 
    void ResetList();
    int GetNextItem(T& data);
    int Delete(T& data);
	int Replace(T indata);
    bool Retrieve_Binary(T& inData);
    int GetCurPointer();
    T at(int i);

private:
	T* m_Array;	// 레코드 배열
	int m_Length;				// 리스트에 저장된 레코드 수
	int m_CurPointer;			// current pointer
};

template <typename T>
SortedList<T>::SortedList() {
	m_Array = new T[MAXSIZE];
	m_Length = 0;
	ResetList();
}

template <typename T>
SortedList<T>::~SortedList() {
    //delete[] m_Array;
}

template <typename T>
bool SortedList<T>::IsEmpty() const{
	if (m_Length == 0)
		return true;
	else
		return false;
}

template <typename T>
void SortedList<T>::MakeEmpty() {
	m_Length = 0;
}
template <typename T>
int SortedList<T>::GetLength() {
	return m_Length;
}
template <typename T>
int SortedList<T>::GetCurPointer(){
    return m_CurPointer;
}

template <typename T>
bool SortedList<T>::IsFull() const{
	if (m_Length == MAXSIZE)
		return true;
	else
		return false;
}
template <typename T>
int SortedList<T>::Add(T data) {
	if (IsFull())
        return -1;

	if (IsEmpty()) {
		m_Array[0] = data;
		m_Length++;
		return 1;
	}
	ResetList();
	T e_data;

	while (GetNextItem(e_data) != -1) {
        if (data < e_data) {
			for (int i = m_Length; i > m_CurPointer; i--) {
				m_Array[i] = m_Array[i - 1];
			}
			m_Array[m_CurPointer] = data;
			m_Length++;
			return 1;
		}
        else if (data == e_data) {
            return 0;
		}
	}
	m_Array[m_Length] = data; //새 항목이 마지막 항목보다 클때
	m_Length++;
	return 1;
}

template <typename T>
void SortedList<T>::ResetList() {
	m_CurPointer = -1;
}

template <typename T>
int SortedList<T>::GetNextItem(T& data) {
	m_CurPointer++;
	if (m_CurPointer >= m_Length)
		return -1;
	else {
		data = m_Array[m_CurPointer];
		return m_CurPointer;
	}
}

template <typename T>
int SortedList<T>::Delete(T& data) {
	int det = Retrieve_Binary(data);
	if (det) {
		for (int i = m_CurPointer; i < m_Length - 1; i++) {
			m_Array[i] = m_Array[i + 1];
		}
		m_Length--;
		return 1;
	}
	return 0;
}

template <typename T>
int SortedList<T>::Replace(T indata) {
	T temp = indata;
	int det = Retrieve_Binary(temp);
	if (det) {
		m_Array[m_CurPointer] = indata;
		return 1;
	}
	return 0;
}

template <typename T>
bool SortedList<T>::Retrieve_Binary(T& inData) {
    if (IsEmpty())
        return false;

    int max = m_Length-1;
	int min = 0;
	m_CurPointer = m_Length / 2;
    while (!(m_Array[m_CurPointer] == inData) && (min < max)) {

        if (m_Array[m_CurPointer] > inData) {
			max = m_CurPointer - 1;
		}
        else {
			min = m_CurPointer + 1;
		}
		m_CurPointer = (max + min) / 2;
	}
    if (m_Array[m_CurPointer] == inData) {
		inData = m_Array[m_CurPointer];
        return true;
	}
	else {
        return false;
	}

}

template <typename T>
T SortedList<T>::at(int index)
{
    return m_Array[index];
}
