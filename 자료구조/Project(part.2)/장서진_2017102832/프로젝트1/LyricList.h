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
	LyricList();	// ������
	~LyricList();	// �Ҹ���

	inline void operator=(LyricList<T> list)
	{
		for (int i = 0; i < m_Length; i++)
		{
			this->m_Array[i] = list[i];
		}
	}

	void MakeEmpty(); 			// Make list empty
	int GetLength();				// ���ڵ� �� ��ȯ
	bool IsFull();				// ��� �迭�� ��� ����
	int Add(T data);			// ���ο� ������ �߰�
	void ResetList();			// ���ڵ� ������(current pointer) �ʱ�ȭ
	int GetNextItem(T& data);	// current pointer�� �ϳ� ������Ű�� ���� �ƴϸ� record index�� ���� ���̸� -1�� ����
	bool IsEmpty();	// �迭�� ������� ����
	void Get(T& data); // Primary key�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������
	int Delete(T data); // ���� ���ڵ� ���� 
	void Replace(T data); // �Էµ� data�� Primary key�� ������ ����� ã�Ƽ� List�� �ش� ����� �Էµ� data�� ġȯ�Ѵ�. 

private:
	T m_Array[MAXSIZE];  		// ���ڵ� �迭
	int m_Length;				// ����Ʈ�� ����� ���ڵ� ��
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
		// list ���̵�� data�� �����ϴٸ�
		if (data.CompareByID(m_Array[i]) == EQUAL)
		{
			// data�� �ش� list�� �ε����� set
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