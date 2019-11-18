#pragma once
#include <iostream>
#include <string>
#include "MusicType.h"
#include "BestSorted.h"
#include "BestType.h"

#define MAXSIZE 6000 // 관리자가 
using namespace std;

template <typename T>
class MusicSorted
{
public:
	MusicSorted();		// 생성자
	~MusicSorted();		// 소멸자

	void operator=(const MusicSorted<T>& tmp);
	void operator<(const MusicSorted<T>& tmp);

	void MakeEmpty(); 			// 리스트 비우기
	int GetLength();			// 리스트 요소 개수 반환
	bool IsFull();				// 리스트 꽉 찼는지
	int Add(T& data);		// 새로운 데이터 추가
	void ResetList();			// current pointer 초기화
	int GetNextItem(T& data);	// current pointer를 하나 증가시키고 끝이 아니면 데이터 인덱스를 리턴 끝이면 -1을 리턴
	bool IsEmpty();				// 리스트 비었는지 여부
	int Delete(T data);			// 기존 레코드 삭제 
	int Replace(T data);		// 입력된 data와 Primary key와 동일한 기록을 찾아서 List의 해당 기록을 입력된 data로 치환한다. 
	int Retrieve_Binary(T& data); // binary search로 리스트 검색
	
private:
	MusicType m_Array[MAXSIZE];  		// 레코드 배열
	int m_Length;						// 리스트에 저장된 레코드 수
	int m_CurPointer;					// current pointer
	int m_MAXSIZE;
};

template <typename T>
MusicSorted<T>::MusicSorted()
{
	m_Length = 0;
	m_CurPointer = -1;
	m_MAXSIZE = MAXSIZE;
}

template <typename T>
MusicSorted<T>:: ~MusicSorted() {}

template <typename T>
void MusicSorted<T>::MakeEmpty()
{
	m_Length = 0;
}

template <typename T>
int MusicSorted<T>::GetLength()
{
	return m_Length;
}

template <typename T>
bool MusicSorted<T>::IsFull()
{
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


template <typename T>
int MusicSorted<T>::Add(T& data)
{
	// list가 꽉 차있으면 
	if (IsFull())
	{
		cout << endl;
		cout << "\t--- List is full ---";
		return 0;
	}

	bool found = false;
	int i = 0;

	// 새로운 데이터가 들어갈 위치 찾기
	while (!found && i < m_Length)
	{
		// List의 Id와 data 비교 
		switch (m_Array[i].CompareByID(data))
		{
			// List의 Id와 data 일치 --> 중복된 아이디 존재
		case EQUAL:
			cout << endl;
			break;
			return 0;
			// List의 Id보다 data가 큰 경우 바로 삽입
		case GREATER:
			found = true;
			break;
			// List의 Id보다 data가 작을 때 pointer 뒤로 옮기기
		case LESS:
			i++;
			break;
		}
	}

	// 맨 뒤에 끼어 들어가는 경우 맨 뒤에 삽입
	if (i == m_Length)
	{
		m_Array[i] = data;
		m_Length++;
		return 1;
	}

	// 그 이외의 경우, List 끝부터 오른쪽에서 왼쪽으로 j가 훑으며
	// List 인덱스 j 값을 j-1 위치로 옮긴다.
	for (int j = m_Length; j > i; j--)
		m_Array[j] = m_Array[j - 1];

	//List 인덱스 i에 data 삽입
	m_Array[i] = data;
	m_Length++;

	return 1;
}

template <typename T>
void MusicSorted<T>::ResetList()
{
	m_CurPointer = -1;
}

template <typename T>
int MusicSorted<T>::GetNextItem(T& data)
{
	m_CurPointer++;

	if (m_CurPointer == MAXSIZE)
		return -1;
	data = m_Array[m_CurPointer];

	return m_CurPointer;
}

template <typename T>
bool MusicSorted<T>::IsEmpty()
{
	if (sizeof(m_Length) == 0)
		return true;
	else
		return false;
}

template <typename T>
int MusicSorted<T>::Delete(T data)
{
	for (int i = 0; i < m_Length; i++) {
		// List의 id와 data가 일치하면
		if (m_Array[i].CompareByID(data) == EQUAL) {
			for (int j = i + 1; j < m_Length; j++)
				m_Array[j - 1] = m_Array[j];
			m_Length -= 1;
			return 1;
		}
	}
	return 0;
}

template <typename T>
int MusicSorted<T>::Replace(T data)
{
	int i;
	for (i = 0; i < m_Length; i++)
	{
		if (data.CompareByID(m_Array[i]) == EQUAL)
		{
			m_Array[i] = data;
			return 1;
		}
	}
	return 0;
}

template <typename T>
int MusicSorted<T>::Retrieve_Binary(T& data)
{
	int i = 0;

	for (i; i < m_Length; i++)
	{
		int a = 0; // list 첫 번째값
		int b = m_Length - 1; // list 마지막 값
		int c = (a + b) / 2; // list 중앙값

		while (true)
		{
			// data의 primary key가 c와 같은 경우 1리턴
			if (m_Array[c].CompareByID(data) == EQUAL)
			{
				data = m_Array[c];
				return 1;
			}
			// data의 primary key가 c보다 작은 경우 a를 c로
			else if (m_Array[c].CompareByID(data) == LESS)
				a = c;
			// a와 b가 같아질 경우 0리턴
			else if (a == b)
				return 0;
			// data의 primary key가 c보다 큰 경우 b를 c로
			else
				b = c;
		}
	}
}
