#include "ItemType.h"

#define MAX_ITEMS 20

// Exception class thrown by Enqueue when queue is full.
class FullQueue
{
public:
	void print()
	{
		cout << "FullQueue exception thrown." << endl;
	}
};

// Exception class thrown by DeQueue and Top when queue is empty.
class EmptyQueue
{
public:
	void print()
	{
		cout << "EmtpyQueue exception thrown." << endl;
	}
};

class QueueItem
{
private:
	int m_front;
	int m_rear;
	int m_MaxQueue;
	ItemType* m_QueueItem;

public:
		//===================================================================================
	// Function	: allocate dynamic array whose size is 100
	// Pre		: max is defined
	// Post		: items points the array allocated.
	//===================================================================================
	QueueItem();

	//===================================================================================
	// Function	: allocate dynamic array whose size is max
	// Pre		: max is defined
	// Post		: items points the array allocated.
	//===================================================================================
	QueueItem(int max);

	//===================================================================================
	// Function	: destruct the object. Free the array dynamically allocated
	// Pre		: items is initialized.
	// Post		: none
	//===================================================================================
	~QueueItem();

	//===================================================================================
    // Function	: Determines whether the Queue is full.
    // Pre		: Queue has been initialized.
	// Post		: Function value = (Queue is full)
	//===================================================================================
	bool IsFull();
 
	//===================================================================================
    // Function	: Determines whether the Queue is empty.
    // Pre		: Queue has been initialized.
	// Post		: Function value = (Queue is empty)
	//===================================================================================
	bool IsEmpty();

	//===================================================================================
    // Function	: make queue to empty.
    // Pre		: None
	// Post		: Queue is empty.
	//===================================================================================
    void MakeEmpty();

	//===================================================================================
    // Function	: Adds newItem to the rear of Queue.
    // Pre		: Queue has been initialized.
    // Post		: If (Queue is full), FullQueue exception is thrown;
	//			  otherwise, newItem is at the rear of Queue.
	//===================================================================================
	void EnQueue(ItemType newItem);

	//===================================================================================
    // Function	: Removes front item of the queue
    // Pre		: Queue has been initialized.
    // Post		: If (queue is empty), EmptyQueue exception is thrown;
	//			  otherwise, front element has been removed from queue.
	//===================================================================================
	void DeQueue(ItemType& item);

	//===================================================================================
    // Function	: Print all the items in the queue on screen
	// Pre	: queue has been initialized.
	// Post	: None
	//===================================================================================
   	void Print();
};

