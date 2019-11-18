#pragma once
#include <iostream>
#include <string>
#include "MusicType.h"
#include "BestSorted.h"
#include "BestType.h"

#define MAXSIZE 6000 // �����ڰ� 
using namespace std;

template <typename T>
class MusicSorted
{
public:
	MusicSorted();		// ������
	~MusicSorted();		// �Ҹ���

	void operator=(const MusicSorted<T>& tmp);
	void operator<(const MusicSorted<T>& tmp);

	void MakeEmpty(); 			// ����Ʈ ����
	int GetLength();			// ����Ʈ ��� ���� ��ȯ
	bool IsFull();				// ����Ʈ �� á����
	int Add(T& data);		// ���ο� ������ �߰�
	void ResetList();			// current pointer �ʱ�ȭ
	int GetNextItem(T& data);	// current pointer�� �ϳ� ������Ű�� ���� �ƴϸ� ������ �ε����� ���� ���̸� -1�� ����
	bool IsEmpty();				// ����Ʈ ������� ����
	int Delete(T data);			// ���� ���ڵ� ���� 
	int Replace(T data);		// �Էµ� data�� Primary key�� ������ ����� ã�Ƽ� List�� �ش� ����� �Էµ� data�� ġȯ�Ѵ�. 
	int Retrieve_Binary(T& data); // binary search�� ����Ʈ �˻�
	
private:
	MusicType m_Array[MAXSIZE];  		// ���ڵ� �迭
	int m_Length;						// ����Ʈ�� ����� ���ڵ� ��
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
	// list�� �� �������� 
	if (IsFull())
	{
		cout << endl;
		cout << "\t--- List is full ---";
		return 0;
	}

	bool found = false;
	int i = 0;

	// ���ο� �����Ͱ� �� ��ġ ã��
	while (!found && i < m_Length)
	{
		// List�� Id�� data �� 
		switch (m_Array[i].CompareByID(data))
		{
			// List�� Id�� data ��ġ --> �ߺ��� ���̵� ����
		case EQUAL:
			cout << endl;
			break;
			return 0;
			// List�� Id���� data�� ū ��� �ٷ� ����
		case GREATER:
			found = true;
			break;
			// List�� Id���� data�� ���� �� pointer �ڷ� �ű��
		case LESS:
			i++;
			break;
		}
	}

	// �� �ڿ� ���� ���� ��� �� �ڿ� ����
	if (i == m_Length)
	{
		m_Array[i] = data;
		m_Length++;
		return 1;
	}

	// �� �̿��� ���, List ������ �����ʿ��� �������� j�� ������
	// List �ε��� j ���� j-1 ��ġ�� �ű��.
	for (int j = m_Length; j > i; j--)
		m_Array[j] = m_Array[j - 1];

	//List �ε��� i�� data ����
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
		// List�� id�� data�� ��ġ�ϸ�
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
		int a = 0; // list ù ��°��
		int b = m_Length - 1; // list ������ ��
		int c = (a + b) / 2; // list �߾Ӱ�

		while (true)
		{
			// data�� primary key�� c�� ���� ��� 1����
			if (m_Array[c].CompareByID(data) == EQUAL)
			{
				data = m_Array[c];
				return 1;
			}
			// data�� primary key�� c���� ���� ��� a�� c��
			else if (m_Array[c].CompareByID(data) == LESS)
				a = c;
			// a�� b�� ������ ��� 0����
			else if (a == b)
				return 0;
			// data�� primary key�� c���� ū ��� b�� c��
			else
				b = c;
		}
	}
}
