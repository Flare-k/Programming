#pragma once
#include <iostream>
#include <string>
#include "BestType.h"
#define Maxsize 15 // �α� ��Ʈ�� 15���� ����
using namespace std;

template <typename T>
class BestSorted
{
public:
	BestSorted();		// ������
	~BestSorted();		// �Ҹ���

	inline void operator=(BestSorted<T> list)
	{
		for (int i = 0; i < m_Length; i++)
		{
			this->m_Array[i] = list[i];
		}
	}

	void MakeEmpty(); 			// ����Ʈ ����
	int GetLength();			// ����Ʈ ��� ���� ��ȯ
	bool IsFull();				// ����Ʈ �� á����
	int Add(T data);			// ���ο� ������ �߰�
	void ResetList();			// current pointer �ʱ�ȭ
	int GetNextItem(T& data);	// current pointer�� �ϳ� ������Ű�� ���� �ƴϸ� ������ �ε����� ���� ���̸� -1�� ����
	bool IsEmpty();				// ����Ʈ ������� ����
	void Get(T& data);			// Primary key�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������
	int Delete(T data);			// ���� ���ڵ� ���� 
	int Replace(T data);		// �Էµ� data�� Primary key�� ������ ����� ã�Ƽ� List�� �ش� ����� �Էµ� data�� ġȯ�Ѵ�. 
	int Retrieve_Binary_Id(T& data); // binary search�� ���̵� ����Ʈ �˻�
	int Retrieve_Binary_Name(T& data); // binary search�� �� �� ����Ʈ �˻�

private:
	BestType m_bestArray[Maxsize];  	// �α���Ʈ ���ڵ� �迭
	int m_Length;						// ����Ʈ�� ����� �α���Ʈ ���ڵ� ��
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
	// list�� �� �������� 
	if (IsFull())
	{
		cout << endl;
		cout << "\t=== List is full ====";
		return 0;
	}

	bool found = false;
	int i = 0;

	// ���ο� �����Ͱ� �� ��ġ ã��
	while (!found && i < m_Length)
	{
		// List�� Id�� data �� 
		switch (m_bestArray[i].CompareByID(data))
		{
			// List�� Id�� data ��ġ --> �ߺ��� ���̵� ����
		case EQUAL:
			cout << endl;
			cout << "\t=== �ߺ��� ���̵� �����մϴ�. ===";
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
		m_bestArray[i] = data;
		m_Length++;
		return 1;
	}

	// �� �̿��� ���, List ������ �����ʿ��� �������� j�� ������
	// List �ε��� j ���� j-1 ��ġ�� �ű��
	for (int j = m_Length; j > i; j--)
		m_bestArray[j] = m_bestArray[j - 1];

	//List �ε��� i�� data ����
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
		// list ���̵�� data�� �����ϴٸ�
		if (data.CompareByID(m_bestArray[i]) == EQUAL)
		{
			// data�� �ش� list�� �ε����� set
			data = m_bestArray[i];
		}
	}
}

template <typename T>
int BestSorted<T>::Delete(T data)
{
	for (int i = 0; i < m_Length; i++) {
		// List�� id�� data�� ��ġ�ϸ�
		if (m_bestArray[i].CompareByID(data) == EQUAL) {
			for (int j = i + 1; j < m_Length; j++)
				// �����Ǵ� ������ ��ġ���� �ε��� �� �ϳ��� ����
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
		// data�� ���� id�� �߰��ϸ� 
		if (data.CompareByID(m_bestArray[i]) == EQUAL)
		{
			// ���� id ��ġ�� data �� �ֱ�
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
		int a = 0; // list ù ��°��
		int b = m_Length - 1; // list ������ ��
		int c = (a + b) / 2; // list �߾Ӱ�

		while (true)
		{
			// data�� primary key�� c�� ���� ��� 1����
			if (m_bestArray[c].CompareByID(data) == EQUAL)
			{
				data = m_bestArray[c];
				return 1;
			}
			// data�� primary key�� c���� ���� ��� a�� c��
			else if (m_bestArray[c].CompareByID(data) == LESS)
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

template <typename T>
int BestSorted<T>::Retrieve_Binary_Name(T& data)
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
			if (m_bestArray[c].CompareByName(data) == EQUAL)
			{
				data = m_bestArray[c];
				return 1;
			}
			// data�� primary key�� c���� ���� ��� a�� c��
			else if (m_bestArray[c].CompareByName(data) == LESS)
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
