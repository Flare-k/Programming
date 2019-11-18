#pragma once
#include <iostream>
#include <string>
#include "BestType.h"
#define Maxsize 15 // 인기 차트는 15개만 선정
using namespace std;

template <typename T>
class BestSorted
{
public:
	BestSorted();		// 생성자
	~BestSorted();		// 소멸자

	inline void operator=(BestSorted<T> list)
	{
		for (int i = 0; i < m_Length; i++)
		{
			this->m_Array[i] = list[i];
		}
	}

	void MakeEmpty(); 			// 리스트 비우기
	int GetLength();			// 리스트 요소 개수 반환
	bool IsFull();				// 리스트 꽉 찼는지
	int Add(T data);			// 새로운 데이터 추가
	void ResetList();			// current pointer 초기화
	int GetNextItem(T& data);	// current pointer를 하나 증가시키고 끝이 아니면 데이터 인덱스를 리턴 끝이면 -1을 리턴
	bool IsEmpty();				// 리스트 비었는지 여부
	void Get(T& data);			// Primary key를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
	int Delete(T data);			// 기존 레코드 삭제 
	int Replace(T data);		// 입력된 data와 Primary key와 동일한 기록을 찾아서 List의 해당 기록을 입력된 data로 치환한다. 
	int Retrieve_Binary_Id(T& data); // binary search로 아이디 리스트 검색
	int Retrieve_Binary_Name(T& data); // binary search로 곡 명 리스트 검색

private:
	BestType m_bestArray[Maxsize];  	// 인기차트 레코드 배열
	int m_Length;						// 리스트에 저장된 인기차트 레코드 수
	int m_CurPointer;					// current pointer
};

template <typename T>
BestSorted<T>::BestSorted()
{
	m_Length = 0;
	m_CurPointer = -1;
}

template <typename T>
BestSorted<T>:: ~BestSorted() {}

template <typename T>
void BestSorted<T>::MakeEmpty()
{
	m_Length = 0;
}

template <typename T>
int BestSorted<T>::GetLength()
{
	return m_Length;
}

template <typename T>
bool BestSorted<T>::IsFull()
{
	if (m_Length > Maxsize -1)
		return true;
	else
		return false;
}

/**/
template <typename T>
int BestSorted<T>::Add(T data)
{
	// list가 꽉 차있으면 
	if (IsFull())
	{
		cout << endl;
		cout << "\t=== List is full ====";
		return 0;
	}

	bool found = false;
	int i = 0;

	// 새로운 데이터가 들어갈 위치 찾기
	while (!found && i < m_Length)
	{
		// List의 Id와 data 비교 
		switch (m_bestArray[i].CompareByID(data))
		{
			// List의 Id와 data 일치 --> 중복된 아이디 존재
		case EQUAL:
			cout << endl;
			cout << "\t=== 중복된 아이디가 존재합니다. ===";
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
		m_bestArray[i] = data;
		m_Length++;
		return 1;
	}

	// 그 이외의 경우, List 끝부터 오른쪽에서 왼쪽으로 j가 훑으며
	// List 인덱스 j 값을 j-1 위치로 옮긴다
	for (int j = m_Length; j > i; j--)
		m_bestArray[j] = m_bestArray[j - 1];

	//List 인덱스 i에 data 삽입
	m_bestArray[i] = data;
	m_Length++;

	return 1;
}
/**/

template <typename T>
void BestSorted<T>::ResetList()
{
	m_CurPointer = -1;
}

template <typename T>
int BestSorted<T>::GetNextItem(T& data)
{
	m_CurPointer++;

	if (m_CurPointer == Maxsize)
		return -1;
	data = m_bestArray[m_CurPointer];

	return m_CurPointer;
}

template <typename T>
bool BestSorted<T>::IsEmpty()
{
	if (sizeof(m_Length) == 0)
		return true;
	else
		return false;
}

template <typename T>
void BestSorted<T>::Get(T& data)
{
	int i;

	for (i = 0; i < m_Length; i++)
	{
		// list 아이디와 data가 동일하다면
		if (data.CompareByID(m_bestArray[i]) == EQUAL)
		{
			// data는 해당 list의 인덱스로 set
			data = m_bestArray[i];
		}
	}
}

template <typename T>
int BestSorted<T>::Delete(T data)
{
	for (int i = 0; i < m_Length; i++) {
		// List의 id와 data가 일치하면
		if (m_bestArray[i].CompareByID(data) == EQUAL) {
			for (int j = i + 1; j < m_Length; j++)
				// 삭제되는 데이터 위치부터 인덱스 값 하나씩 당기기
				m_bestArray[j - 1] = m_bestArray[j];
			m_Length -= 1;
			return 1;
		}
	}
	return 0;
}

template <typename T>
int BestSorted<T>::Replace(T data)
{
	int i;
	for (i = 0; i < m_Length; i++)
	{	
		// data와 같은 id를 발견하면 
		if (data.CompareByID(m_bestArray[i]) == EQUAL)
		{
			// 기존 id 위치에 data 값 넣기
			m_bestArray[i] = data;
			return 1;
		}
	}
	return 0;
}

template <typename T>
int BestSorted<T>::Retrieve_Binary_Id(T& data)
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
			if (m_bestArray[c].CompareByID(data) == EQUAL)
			{
				data = m_bestArray[c];
				return 1;
			}
			// data의 primary key가 c보다 작은 경우 a를 c로
			else if (m_bestArray[c].CompareByID(data) == LESS)
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

template <typename T>
int BestSorted<T>::Retrieve_Binary_Name(T& data)
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
			if (m_bestArray[c].CompareByName(data) == EQUAL)
			{
				data = m_bestArray[c];
				return 1;
			}
			// data의 primary key가 c보다 작은 경우 a를 c로
			else if (m_bestArray[c].CompareByName(data) == LESS)
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
