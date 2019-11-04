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
	if(m_rear == m_front) // iRear�� iFront�� ���ٸ� ť�� ����ִ�.
		return true; // ť�� ����ٸ� true ��ȯ
	else
		return false; // ť�� ������� �ʴٸ� false ��ȯ

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
	// Queue�� ���ִ� �� Ȯ��
	// ���� iRear�� ����Ű�� ���� ��ҿ� ����. ���� �ε����� m_MaxQueue�� �������� ó������
	if (IsFull())
	{
		throw FullQueue();
		//try-catch�� ����Ѵ�.
		//fullQueue�� �Ѱ��־� Application���� ��ü ������ ����ó���� �Ѵ�.
	}
	else
	{
		m_rear = (m_rear+1) % m_MaxQueue;
		//Circular Queue�� �����ϱ����ؼ� m_MaxQueue�� mod������ �Ѵ�.
		this->m_QueueItem[m_rear] = newItem;
		//�ش��ϴ� ��ġ�� �Ѱܹ��� ������ �����Ѵ�.
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

	// �� queue �˻�
	// ���� front ���� �ε����� �ִ� item�� ���´�. ���� ���ؽ��� m_MaxQueue�� �������� ó������ 
	if (IsEmpty())
	{
		throw EmptyQueue();
		//try-catch�� ����Ѵ�.
		//EmptyQueue�� �Ѱ��־� Application���� ��ü ������ ����ó���� �Ѵ�.
	}
	else
	{
		m_front = (m_front+1) % m_MaxQueue;
		//Circular Queue�� �����ϱ����ؼ� m_MaxQueue�� mod������ �Ѵ�.
		item = m_QueueItem[m_front];
		//������ ��ġ�ϴ� ���� �����Ѵ�.
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
		// i���� MaxSize - 1���� ũ�� 0���� ���� �ٲ���
		if(i > m_MaxQueue - 1)	
			i = 0;

		m_QueueItem[i].PutMusicNameOnScreen();
		//m_QueueItem[i].PutRecordOnScreen();
	}
	cout << endl;
}