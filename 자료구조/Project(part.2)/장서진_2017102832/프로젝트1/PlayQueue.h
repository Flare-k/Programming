#pragma once
#include <iostream>
#include <string>
using namespace std;

#define maxsize 800

template <typename T>
class PlayList
{
public:

	PlayList(); // create circular queue(default size) using dunamic allocation
	PlayList(int max); // create circular queue(max size) using dynamic allocation
	~PlayList(); //defaut destructor, release circular queue

	bool IsFull() const; // check the circular queue if full or not
	bool IsEmpty() const; // check the circular queue is empty or not
	void MakeEmpty(); // make empty circular queue
	void EnQueue(T item); // if circular has space then add item to top
	void DeQueue(T& item); // Removes first item from the queue
	void ResetCurPointer();

	int Top(); // ��� ����
	int ResetList(); // pointer�� front ����Ű���� ����
	int GetNextitem(T item); // empty�� �ƴϸ� pointer�� ������Ű�� pointer�� ����Ű�� item�� true�� ����
	int Search(T& item); // item�� Id�� ��ġ�ϴ� ���ڵ带 Queue���� ����
	int Delete(T item); // item�� Id�� ��ġ�ϴ� ���ڵ带 Queue���� ����
	int Replace(T item); // item�� Id�� ��ġ�ϴ� ���ڵ带 Queue���� ã�� item�� ����ִ� ������ ��ü
	void Print();

private:
	int m_iFront; // front index of the circular queue
	int m_iRear; // rear index of the circualr queue
	int m_nMaxQueue; // maximum size of the circular queue
	int top;

	T Id; // ���� primary key
	T numPlay; // ���� ��� Ƚ��
	T inTime;
	T* items;
};

template <typename T>
PlayList<T>::PlayList()
{
	// �� ������ �ʱ�ȭ
	items = new T[maxsize];
	m_iFront = maxsize - 1;
	m_iRear = maxsize - 1;
	m_nMaxQueue = maxsize;
	top = -1;
}

template <typename T>
PlayList<T>::PlayList(int max)
{
	items = new T[max];	//T�� �ڷ������� �����Ҵ�
	m_iFront = max - 1; // ù ��° ������ �ε��� ����
	m_iRear = max - 1; // ������ ������ �ε��� ����
	m_nMaxQueue = max;
	top = -1;
}

template <typename T>
PlayList<T>::~PlayList()
{
	delete[] items; //�����Ҵ��� �޸� ����
}

template <typename T>
bool PlayList<T>::IsFull() const
{
	if (m_iFront - m_iRear == 1 && m_iRear - m_iFront == m_nMaxQueue - 1)
		// ù��° �ε��� ���� ������ �ε��� ������ 1 �ռ��� Full &&
		// ù ��° �ε��� ���� 0�̶�� ������ �ε��� ���� m_nMaxQueue-1�� ����
		return true;
	else
		return false;
}

template <typename T>
bool PlayList<T>::IsEmpty() const
{
	if (m_iRear == m_iFront)
		return true;
	else
		return false;
}

template <typename T>
void PlayList<T>::MakeEmpty()
{
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;
}

template <typename T>
void PlayList<T>::EnQueue(T item)
{
	// ���� ���� ������ 
	if (IsFull())
		cout << "=== ��� ����� ���� á���ϴ�. ===" << endl;
	else
	{
		m_iRear = (m_iRear + 1) % m_nMaxQueue;
		items[m_iRear] = item;
		top++;
	}
}

template <typename T>
void PlayList<T>::DeQueue(T& item)
{
	top--;
	//����ִ��� �˻�
	if (IsEmpty())			
		cout << "\t=== ��� ����� ������ϴ�. ===" << endl;
	else
	{
		//front�� ������ �� ĭ �̵�
		m_iFront = (m_iFront + 1) % m_nMaxQueue; 
		cout << endl;
		cout << "\t=== ��� ��Ͽ��� �����Ǿ����ϴ�. ===" << endl << endl;

	}
}

template <typename T>
int PlayList<T>::Top()
{
	if (IsEmpty())
		cout << "\t--- Is Empty ---" << endl;
	else
		return top;
}


template <typename T>
int PlayList<T>::ResetList()
{
	return top = m_iFront;
}

template<typename T>
void PlayList<T>::ResetCurPointer()
{
	top = m_iFront;
}

template <typename T>
int PlayList<T>::GetNextitem(T item)
{
	if (IsEmpty())
		return -1;
	top = (top + 1) % m_nMaxQueue;
	item = items[top];
	if (top == m_iRear + 1) {

		return -1;
	}
}

template <typename T>
int PlayList<T>::Search(T& item)
{
	int i = 0;

	// i�� List �ε��� ���̱��� ������ && list�� i �ε��� ���� data ������ ������, i++�ϸ� ���ʴ�� list�� �ȴ´�.
	for (i; i < top && items[i].ComparePLByName(item) == LESS; i++) {
		// ���� data�� primary key�� �����Ͱ� ��ġ�ϸ� 1��ȯ
		if (items[i].ComparePLByName(item) == EQUAL)
		{
			item = items[i];
			return 1;
		}
		else
			return 0;
	}
}

template <typename T>
int PlayList<T>::Delete(T item)
{
	for (int i = 0; i < top; i++) {
		// List�� id�� data�� ��ġ�ϸ�
		if (items[i].ComparePLByID(item) == EQUAL) {
			for (int j = i + 1; j < top; j++)
				// �ε��� i+1���� ������ �ε��� 1�� ���̱�
				items[j - 1] = items[j];
			top -= 1;
			return 1;
		}
	}
	return 0;
}

template <typename T>
int PlayList<T>::Replace(T item)
{
	int i;
	for (i = 0; i < top; i++)
	{
		if (item.ComparePLByID(items[i]) == EQUAL)
		{
			// ��ü�� item�� 
			items[i] = item;
			return 1;
		}
	}
	return 0;
}

template <typename T>
void PlayList<T>::Print()
{
	if (IsEmpty())				//������� it is empty���. Empty Stack�� throw�ϸ� ���α׷��� ����Ǿ �ٽ� Enqueue�Ҽ������Ƿ�
		cout << "It is empty!" << endl;				//�ε����ϰ� ���ο� ����ó��
	else
	{
		cout << "CircularQueueType: ";
		// CircularQueueType ���Ǹ��element ���
		int first = m_iFront;
		int last = m_iRear;
		//Rear���� front�� ���� �������ȸ�. front�� �����ؼ� ���� �ϳ��� ���.Enqueue�ϸ� rear�� front�� ���� �ռ������Ƿ�
		while (first != last)				
		{
			cout << items[(first + 1) % m_nMaxQueue] << " - ";
			first = (first + 1) % m_nMaxQueue;
		}
		cout << endl;
	}
}
