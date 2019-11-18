#pragma once
#include "ItemType.h"
#include<iostream>
#include <fstream>
#include<string>

#define MAXSIZE 100
template<typename T>
class SortedList {
public: 
	/**
	*	default constructor.
	*/
	SortedList() {
		m_Length = 0;
		m_CurPointer = -1;
		m_Array = new T[MAXSIZE];
	};

	/**
	*	객체 생성할 때 정수로 인자가 들어오면 들어온 정수 크기 만큼 배열 동적 할당.
	*/
	SortedList(int size) {
		m_Length = 0;
		m_CurPointer = -1;
		m_Array = new T[size];
	}
	/**
	*	destructor.
	*/
	~SortedList() {};
	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty(); // Make list empty(Initialize list)
		/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength(); // Return the number of records in the list 
		/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull(); // Check the list upper limit bool IsEmpty(); // Check the list is empty 
	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList(); // Initialize the iterator pointer 
		/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T& data); // Update pointer to point to next record and return this new record. 
	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(T data); // Add a new data to list  
	/**
	*	@brief	id가 일치하는 item을 찾아서 해당 item을 수정한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에 해당 item이 입력된 값으로 수정된다.
	*	@param	data	수정 하고자 하는 id가 입력된 data값. 
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Replace(T data); // Find to same record using primary key and replace it 
	
	/**
	*	@brief	item을 찾아서 해당 item을 반환한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 item이 data에 입력된다.
	*	@param	data	찾고자 하는 id가 입력된 data값. 발견한 item이 리턴된다.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int Retrieve(T& target); // Find the item whose primary key matches with the primary key of target 
										// and return the copy of the item in target. 
	
	/**
	*	@brief	입력받은 id와 일치하는 id를 가진 item을 Binary로 찾아 입력된 data에 복사한다.
	*	@pre	id가 일치하는 item이 존재해야한다.
	*	@post	입력된 data에 일치하는 id를 가진 item이 복사된다.
	*	@param	data	복사받을 data값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Retrieve_Binary(T& data);  // Retrieve by using binary search
	/**
	*	@brief	id가 일치하는 item을 찾아서 해당 item을 제거한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에 해당 item이 제거된다.
	*	@param	data	제거하고자 하는 id가 입력된 data값. 
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Delete(T data);
private:
	T *m_Array; // array for record 
	int m_Length; // number of record 
	int m_CurPointer; // current pointer
};


template<typename T>
void SortedList<T>::MakeEmpty() {
	m_Length = 0;
} // length를 0으로 바꿔서 list를 비운다.

template<typename T>
int SortedList<T>::GetLength() {
	return m_Length;
} // m_Length를 반환한다.

template<typename T>
bool SortedList<T>::IsFull() {
	if (m_Length > MAXSIZE - 1) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
void SortedList<T>::ResetList() {
	m_CurPointer = -1;
}

template<typename T>
int SortedList<T>::GetNextItem(T& data) {
	m_CurPointer++;	// list pointer 증가
	if (m_CurPointer == m_Length)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

template<typename T>
int SortedList<T>::Add(T data) {
	// List가 꽉 차있는 경우 0을 리턴
	if (IsFull()) return 0;
	// List가 비어 있으면 
	if (m_Length == 0) {
		//맨 앞에 삽입, length 증가, 1을 리턴
		m_Array[m_Length++] = data;
		return 1;
	}
	// 새 항목의 삽입 위치 iPos를 검색
	bool found = false;
	int iPos = 0;
	while (!found && iPos < m_Length) {
		switch (m_Array[iPos].Compare(data))
		{
		case EQUAL:
			cout << endl << "\t* 동일한 id를 가진 음악이 이미 존재합니다. \n";
			return 0;
		case GREATER:
			found = true;
			break;
		case LESS:
			iPos++;
			break;
		}
	}
	//iPos==length이면
	if (iPos == m_Length) {
		// 인덱스 length에 추가, length++, 1리턴
		m_Array[iPos] = data;
		m_Length++;
		return 1;
	}
	// iPos<length이면 iPos부터 length-1 사이의 모든 항목을 뒤로 한 칸씩 이동
	for (int i = m_Length; i > iPos; i--)
		m_Array[i] = m_Array[i - 1];
	// iPos에 추가,
	m_Array[iPos] = data;
	// Length++, 1리턴
	m_Length++;
	return 1;
}

template<typename T>
int SortedList<T>::Replace(T data) {
	ResetList();
	for (m_CurPointer; m_CurPointer < m_Length - 1; m_CurPointer++) {
		if (m_Array[m_CurPointer].Compare(data) == EQUAL) {
			m_Array[m_CurPointer] = data;
			cout << "\t* Replace Success!" << endl;
			return 1;
		}
	}
	cout << "\t* 해당하는 ID를 가진 데이터가 존재하지 않습니다." << endl;
	return 0;
}

template<typename T>
int SortedList<T>::Retrieve(T& target) {
	// curPos를 첫번째 항목을 가리키도록 세팅
	ResetList();
	// List를 차례대로 방문하면서 data의 Key와 일치하는 항목을 찾는다.
	for (; m_CurPointer < m_Length && m_Array[m_CurPointer].Compare(target) == LESS; m_CurPointer++);
	// curPos의 항목의 key가 data의 Key와 일치 하는 경우
	if (m_Array[m_CurPointer].Compare(target) == EQUAL)
	{
		target = m_Array[m_CurPointer];
		return 1;
	}
	else // key가 data의 Key보다 크거나 curPos가 맨 끝에 도달하는 경우
		return 0;
}

template<typename T>
int SortedList<T>::Retrieve_Binary(T& data) {
	int low = 0;
	int high = m_Length;
	int mid;
	while (low <= high) {
		mid = (high + low) / 2;
		if (m_Array[mid].Compare(data) == EQUAL) {
			data = m_Array[mid];
			return 1;
		}
		else if (m_Array[mid].Compare(data) == LESS) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return 0;
}

template<typename T>
int SortedList<T>::Delete(T data)
{
	if (Retrieve(data))	//Primary key가 일치하는 item을 발견한다면(1)
	{
		for (int i = m_CurPointer; i < m_Length; i++)	//현재 포인터부터 입력된 배열 끝까지 반복
		{
			m_Array[i] = m_Array[i + 1];
		}	//배열 뒤에걸 앞으로 하나씩 땡김
		m_Length--;	//아이템 개수를 하나 줄임
		cout << "\t* 삭제 성공!" << endl;
		return 1;	//성공(1)을 리턴
	}
	cout << "\t* 해당하는 id를 가진 데이터가 존재하지 않습니다." << endl;
	return 0;	//Primary key일치하는 item을 찾지 못한다면 실패(0)을 리턴
}
