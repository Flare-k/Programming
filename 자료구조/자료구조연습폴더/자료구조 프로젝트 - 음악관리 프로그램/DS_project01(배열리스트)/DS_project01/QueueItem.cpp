#include "QueueItem.h"



//===================================================================================
// Function	: allocate dynamic array whose size is 10
// Pre		: max is defined
// Post		: items points the array allocated.
//===================================================================================
QueueItem::QueueItem()
{
	m_MaxQueue = MAX_ITEMS + 1;
	m_front = m_MaxQueue - 1;
	m_rear = m_MaxQueue - 1;
	m_QueueItem = new ItemType[m_MaxQueue];   // dynamically allocates
}

//===================================================================================
// Function	: allocate dynamic array whose size is max
// Pre		: max is defined
// Post		: items points the array allocated.
//===================================================================================
QueueItem::QueueItem(int max)
{
	m_MaxQueue = max + 1;
	m_front = m_MaxQueue - 1;
	m_rear = m_MaxQueue - 1;
	m_QueueItem = new ItemType[m_MaxQueue];   // dynamically allocates
}

//===================================================================================
// Function	: destruct the object. Free the array dynamically allocated
// Pre		: items is initialized.
// Post		: none
//===================================================================================
QueueItem::~QueueItem()
{
	delete [] m_QueueItem;
}

//===================================================================================
// Function	: Determines whether the Queue is full.
// Pre		: Queue has been initialized.
// Post		: Function value = (Queue is full)
//===================================================================================
bool QueueItem::IsFull()
{
	if((m_rear+1) == m_front)
		return true;
	else
		return false;

}

//===================================================================================
// Function	: Determines whether the Queue is empty.
// Pre		: Queue has been initialized.
// Post		: Function value = (Queue is empty)
//===================================================================================
bool QueueItem::IsEmpty()
{
	if(m_rear == m_front) // iRear와 iFront가 같다면 큐가 비어있다.
		return true; // 큐가 비었다면 true 반환
	else
		return false; // 큐가 비어있지 않다면 false 반환

}

//===================================================================================
// Function	: make queue to empty.
// Pre		: None
// Post		: queue is empty.
//===================================================================================
void QueueItem::MakeEmpty()
{
	m_front = m_rear;
}

//===================================================================================
// Function	: Adds newItem to the rear of Queue.
// Pre		: Queue has been initialized.
// Post		: If (Queue is full), FullQueue exception is thrown;
//			  otherwise, newItem is at the rear of Queue.
//			  If next index is become same maxQueue then go to start position
//===================================================================================
void QueueItem::EnQueue(ItemType newItem)
{
	// Queue가 차있는 지 확인
	// 현재 iRear가 가리키는 다음 장소에 저장. 다음 인덱스가 m_MaxQueue와 같아지면 처음으로
	if (IsFull())
	{
		throw FullQueue();
		//try-catch를 사용한다.
		//fullQueue를 넘겨주어 Application에서 객체 생성후 에러처리를 한다.
	}
	else
	{
		m_rear = (m_rear+1) % m_MaxQueue;
		//Circular Queue를 구현하기위해서 m_MaxQueue로 mod연산을 한다.
		this->m_QueueItem[m_rear] = newItem;
		//해당하는 위치에 넘겨받은 변수를 저장한다.
	}

}

//===================================================================================
// Function	: Removes front item of the queue
// Pre		: Queue has been initialized.
// Post		: If (queue is empty), EmptyQueue exception is thrown;
//			  otherwise, front element has been removed from queue.
//			  If next index is become same maxQueue then go to start position
//===================================================================================
void QueueItem::DeQueue(ItemType& item)
{

	// 빈 queue 검사
	// 현재 front 다음 인덱스에 있는 item을 빼온다. 다음 인텍스가 m_MaxQueue와 같아지면 처음으로 
	if (IsEmpty())
	{
		throw EmptyQueue();
		//try-catch를 사용한다.
		//EmptyQueue를 넘겨주어 Application에서 객체 생성후 에러처리를 한다.
	}
	else
	{
		m_front = (m_front+1) % m_MaxQueue;
		//Circular Queue를 구현하기위해서 m_MaxQueue로 mod연산을 한다.
		item = m_QueueItem[m_front];
		//변수에 위치하는 값을 저장한다.
	}

}

//===================================================================================
// Function	: Print all the items in the queue on screen
// Pre	: queue has been initialized.
// Post	: None
//===================================================================================
void QueueItem::Print()
{
	for(int i = (m_front + 1) % m_MaxQueue; i - 1 != m_rear; i++)
	{
		// i값이 MaxSize - 1보다 크면 0으로 값을 바꿔줌
		if(i > m_MaxQueue - 1)	
			i = 0;

		m_QueueItem[i].PutMusicNameOnScreen();
		//m_QueueItem[i].PutRecordOnScreen();
	}
	cout << endl;
}