#pragma once
#define MAXSIZE 10
#include "ItemType.h"
#include <iostream>
using namespace std;

template <typename T>
class SortedList
{
public:
	SortedList();
	~SortedList();

	void MakeEmpty();
	int GetLength();
	bool IsFull();
	int Add(T data);
	void ResetList();
	int GetNextItem(T& data);
	bool IsEmpty();
	int Get(T& data);
	int Delete(T data);
	int Replace(T data);
	T GetOut(int a);
	int retrieveBS(T& data);
private:
	//T m_Array[MAXSIZE];
	T* m_Array;
	int m_Length = 0;
	int m_CurPointer;


};


template <typename T>
SortedList<T>::SortedList() {
	m_Array = new T[MAXSIZE];

}

template <typename T>
SortedList<T>::~SortedList() {
	delete[] m_Array;

}

template <typename T>
void SortedList<T>::MakeEmpty() {
	m_Length = 0;
}
template <typename T>
int SortedList<T>::GetLength() {
	return m_Length;
}//ok
template <typename T>
bool SortedList<T>::IsFull() {
	if (m_Length == MAXSIZE) {
		cout << "배열이 가득 찼습니다." << endl;
		return true;
	}
	else
		return false;
}//ok

template <typename T>
int SortedList<T>::Add(T data) {//set get 한 것을 실제로 집어넣는 제일 중요한..

	if (IsEmpty()) {//비어있는 배열이었다면 무조건 넣기
		m_Array[m_Length] = data;
		m_Length++;
		return 1;
	}
	else if (IsFull()) return -1;//꽉찬 배열은 더 넣지 못하도록
	else if (data > m_Array[m_Length - 1]) {//배열상 제일 큰 값보다 들어오는 데이터가 클 때
		m_Array[m_Length] = data;
		m_Length++;
	}
	else if (data == m_Array[m_Length - 1]) {
		cout << "ID가 끝값과 겹칩니다" << endl;
		return 0;
	}
	else {
		for (m_CurPointer = 0; m_CurPointer < m_Length; m_CurPointer++) {
			if (data < m_Array[m_CurPointer]) {
				if (data == m_Array[m_CurPointer - 1]) {//배열 상 제일 큰 값을 가진 아이디 안쪽 범위 한정
					cout << "ID가 중간에서 겹칩니다." << endl;
					return 0;
				}
				for (int i = m_Length; i > m_CurPointer; i--) {// 배열에 새로들어온 데이터 집어넣기
					m_Array[i] = m_Array[i - 1];

				}
				m_Length++;
				m_Array[m_CurPointer] = data;
				return 1;
			}


		}
	}
	return 0;
}

template <typename T>
void SortedList<T>::ResetList() {
	m_CurPointer = -1;
}//ok			// 레코드 포인터(current pointer) 초기화

template <typename T>
int SortedList<T>::GetNextItem(T& data) {
	m_CurPointer++;
	data = m_Array[m_CurPointer];
	if (m_CurPointer == m_Length)

		return -1;

	return 0;
}

template <typename T>
bool SortedList<T>::IsEmpty() {
	return (m_Length == 0);
}
template <typename T>
int SortedList<T>::Get(T& data) {
	for (int i = 0; i < m_Length; i++) {
		if (data == m_Array[i]) {
			data = m_Array[i];
			return 0;
		}

	}
	return -1;
}

template <typename T>
int SortedList<T>::Delete(T data) {
	for (int i = 0; i < m_Length; i++) {
		if (data == m_Array[i]) {
			for (int j = i; j < m_Length; j++) {
				m_Array[i] = m_Array[i + 1];
				i++;
			}
			m_Length--;
			m_CurPointer--;
			cout << "Successfully Delete." << endl;
			return 0;
		}
	}
	return -1;
}

template <typename T>
int SortedList<T>::Replace(T data) {
	for (int i = 0; i < m_Length; i++) {
		if (data == m_Array[i]) {
			m_Array[i] = data;
			cout << "Complete" << endl;
			return 0;
		}
	}
	return -1;
}

template <typename T>
T SortedList<T>::GetOut(int a) {
	return m_Array[a];
}

template <typename T>
int SortedList<T>::retrieveBS(T& data) {
	int head = 0;
	int tail = GetLength() - 1;
	int mid = (head + tail) / 2;
	while (tail >= head) {
		if (data > m_Array[mid]) {
			if (mid + 1 == tail) {
				if (m_Array[tail] == data) {
					data = m_Array[tail];
					return tail;
				}
				cout << "No data Found" << endl;
				return -1;
			}
			head = mid;
		}
		else if (data < m_Array[mid]) tail = mid;
		else {
			data = m_Array[mid];
			return mid;
		}
		mid = (head + tail) / 2;


	}
	return -1;
}
