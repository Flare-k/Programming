#pragma once
#include <iostream>
#include <string>
#include "LyricType.h"

using namespace std;
#define MAXSIZE 6000

template<typename T>
class LyricList
{
public:
	LyricList();	// 생성자
	~LyricList();	// 소멸자

	inline void operator=(LyricList<T> list)
	{
		for (int i = 0; i < m_Length; i++)
		{
			this->m_Array[i] = list[i];
		}
	}

	void MakeEmpty(); 			// Make list empty
	int GetLength();				// 레코드 수 반환
	bool IsFull();				// 모든 배열의 사용 여부
	int Add(T data);			// 새로운 데이터 추가
	void ResetList();			// 레코드 포인터(current pointer) 초기화
	int GetNextItem(T& data);	// current pointer를 하나 증가시키고 끝이 아니면 record index를 리턴 끝이면 -1을 리턴
	bool IsEmpty();	// 배열이 비었는지 여부
	void Get(T& data); // Primary key를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
	int Delete(T data); // 기존 레코드 삭제 
	void Replace(T data); // 입력된 data와 Primary key와 동일한 기록을 찾아서 List의 해당 기록을 입력된 data로 치환한다. 

private:
	T m_Array[MAXSIZE];  		// 레코드 배열
	int m_Length;				// 리스트에 저장된 레코드 수
	int m_CurPointer;			// current pointer
};

template<typename T>
LyricList<T>::LyricList()
{
	m_Length = 0;
	m_CurPointer = -1;
}
template<typename T>
LyricList<T>:: ~LyricList() {}

template<typename T>
void LyricList<T>::MakeEmpty()
{
	m_Length = 0;
}

template<typename T>
int LyricList<T>::GetLength()
{
	return m_Length;
}
template<typename T>
bool LyricList<T>::IsFull()
{
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}
template<typename T>
int LyricList<T>::Add(T data)
{
	if (!IsFull())
	{
		m_Array[m_Length] = data;
		m_Length++;
		return 1;
	}

	return 0;
}
template<typename T>
void LyricList<T>::ResetList()
{
	m_CurPointer = -1;
}
template<typename T>
int LyricList<T>::GetNextItem(T& data)
{
	m_CurPointer++;

	if (m_CurPointer == MAXSIZE)
		return -1;
	data = m_Array[m_CurPointer];

	return m_CurPointer;
}

template<typename T>
bool LyricList<T>::IsEmpty()
{
	if (sizeof(m_Length) == 0)
		return true;
	else
		return false;
}
template<typename T>
void LyricList<T>::Get(T& data)
{
	int i;

	for (i = 0; i < m_Length; i++)
	{
		// list 아이디와 data가 동일하다면
		if (data.CompareByID(m_Array[i]) == EQUAL)
		{
			// data는 해당 list의 인덱스로 set
			data = m_Array[i];
		}
	}
}
template<typename T>
int LyricList<T>::Delete(T data)
{
	for (int i = 0; i < m_Length; i++) {
		if (m_Array[i].CompareByID(data) == EQUAL) {
			for (int j = i + 1; j < m_Length; j++)
				m_Array[j - 1] = m_Array[j];
			m_Length -= 1;
			return 1;
		}
	}
	return 0;
}

template<typename T>
void LyricList<T>::Replace(T data)
{
	int i;
	for (i = 0; i < m_Length; i++)
	{
		if (data.CompareByID(m_Array[i]) == EQUAL)
		{
			m_Array[i] = data;
		}
	}
}