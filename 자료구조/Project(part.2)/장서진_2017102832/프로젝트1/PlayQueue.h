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

	int Top(); // 요소 개수
	int ResetList(); // pointer가 front 가리키도록 세팅
	int GetNextitem(T item); // empty가 아니면 pointer를 증가시키고 pointer가 가리키는 item과 true를 리턴
	int Search(T& item); // item의 Id와 일치하는 레코드를 Queue에서 리턴
	int Delete(T item); // item의 Id와 일치하는 레코드를 Queue에서 삭제
	int Replace(T item); // item의 Id와 일치하는 레코드를 Queue에서 찾아 item에 들어있는 정보로 대체
	void Print();

private:
	int m_iFront; // front index of the circular queue
	int m_iRear; // rear index of the circualr queue
	int m_nMaxQueue; // maximum size of the circular queue
	int top;

	T Id; // 곡의 primary key
	T numPlay; // 곡의 재생 횟수
	T inTime;
	T* items;
};

template <typename T>
PlayList<T>::PlayList()
{
	// 각 변수들 초기화
	items = new T[maxsize];
	m_iFront = maxsize - 1;
	m_iRear = maxsize - 1;
	m_nMaxQueue = maxsize;
	top = -1;
}

template <typename T>
PlayList<T>::PlayList(int max)
{
	items = new T[max];	//T의 자료형으로 동적할당
	m_iFront = max - 1; // 첫 번째 값으로 인덱스 설정
	m_iRear = max - 1; // 마지막 값으로 인덱스 설정
	m_nMaxQueue = max;
	top = -1;
}

template <typename T>
PlayList<T>::~PlayList()
{
	delete[] items; //동적할당한 메모리 해제
}

template <typename T>
bool PlayList<T>::IsFull() const
{
	if (m_iFront - m_iRear == 1 && m_iRear - m_iFront == m_nMaxQueue - 1)
		// 첫번째 인덱스 값이 마지막 인덱스 값보다 1 앞서면 Full &&
		// 첫 번째 인덱스 값이 0이라면 마지막 인덱스 값이 m_nMaxQueue-1외 같다
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
	// 꽉차 있지 않으면 
	if (IsFull())
		cout << "=== 재생 목록이 가득 찼습니다. ===" << endl;
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
	//비어있는지 검사
	if (IsEmpty())			
		cout << "\t=== 재생 목록이 비었습니다. ===" << endl;
	else
	{
		//front를 앞으로 한 칸 이동
		m_iFront = (m_iFront + 1) % m_nMaxQueue; 
		cout << endl;
		cout << "\t=== 재생 목록에서 삭제되었습니다. ===" << endl << endl;

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

	// i가 List 인덱스 길이까지 돌도록 && list의 i 인덱스 값이 data 값보다 작으면, i++하며 차례대로 list를 훑는다.
	for (i; i < top && items[i].ComparePLByName(item) == LESS; i++) {
		// 만일 data의 primary key와 포인터가 일치하면 1반환
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
		// List의 id와 data가 일치하면
		if (items[i].ComparePLByID(item) == EQUAL) {
			for (int j = i + 1; j < top; j++)
				// 인덱스 i+1부터 끝까지 인덱스 1씩 줄이기
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
			// 대체할 item을 
			items[i] = item;
			return 1;
		}
	}
	return 0;
}

template <typename T>
void PlayList<T>::Print()
{
	if (IsEmpty())				//비었으면 it is empty출력. Empty Stack을 throw하면 프로그램이 종료되어서 다시 Enqueue할수없으므로
		cout << "It is empty!" << endl;				//부득이하게 새로운 예외처리
	else
	{
		cout << "CircularQueueType: ";
		// CircularQueueType 내의모든element 출력
		int first = m_iFront;
		int last = m_iRear;
		//Rear값과 front가 같지 않을동안만. front로 시작해서 값을 하나씩 출력.Enqueue하면 rear가 front에 비해 앞서있으므로
		while (first != last)				
		{
			cout << items[(first + 1) % m_nMaxQueue] << " - ";
			first = (first + 1) % m_nMaxQueue;
		}
		cout << endl;
	}
}
