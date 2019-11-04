#include "Stack.h"


// Allocate dynamic array whose size is maxStack 500.
Stack::Stack()
{
	items = new ItemType [maxStack];
	top = -1;	
}


// Destruct the object. Free the array dynamically allocated.
Stack::~Stack()
{
	delete[] items;
}


// Determines whether the stack is full.
bool Stack::IsEmpty() const
{
	if(top <= -1)
		return true;
	else
		return false;
}


// Determines whether the stack is empty.
bool Stack::IsFull() const
{
	if(top >= maxStack - 1)
		return true;
	else
		return false;
}


// Adds newItem to the top of the stack.
void Stack::Push(ItemType newItem) 
{	
	if (IsFull())
		throw FullStack();
	else
	{
		top++;
		items[top] = newItem;
	}
}


// Removes top item from the stack.
ItemType Stack::Pop()
{
	ItemType temp;

	if (IsEmpty())
		throw EmptyStack();
	else
	{
		temp = Top();
		top--;
		return temp;
	}
}


// Removes top item from the stack.
ItemType Stack::Top()
{
	if (IsEmpty())
		throw EmptyStack();
	else
		return items[top];
}


// Print all the items in the stack on screen
void Stack::Print()
{
	cout << "Stack: ";
	// Stack 내의 모든 element 출력.
	for (int i = top ; i >= 0 ; i--)
	{
		cout << items[i] << " - ";
	}
	cout << endl;
}