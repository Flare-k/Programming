#include "Application.h"


// Program driver.
void Application::Run()
{
	try
	{
		while(1)
		{
			m_Command = GetCommand();

			switch(m_Command)
			{
			case 1:		// Push Element.
				PushItem();
				break;
			case 2:		// Pop Element.
				PopItem();
				break;
			case 3:		// Is Empty?
				CheckEmpty();
				break;
			case 4:		// Is Full?
				CheckFull();
				break;
			case 5:		// Test EmptyStack Exception.
				TestEmptyException();
				break;
			case 6:		// Test FullStack Exception.
				TestFullException();
				break;
			case 7:		// Print all the elements in the stack.
				DisplayAllItem();
				break;
			case 0:
				return;
			default:
				cout << "\tIllegal selection...\n";
				break;
			}
		}
	}
	catch (FullStack)
	{
		cout<< "FullStack exception thrown." << endl;
	}
	
	catch (EmptyStack e)
	{		
		e.print();
	}
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout<<"\t--- ID - Command -----"<<endl;
	cout<<"\t    1. Push Element"<<endl;
	cout<<"\t    2. Pop Element"<<endl;
	cout<<"\t    3. Is Empty?"<<endl;
	cout<<"\t    4. Is Full?"<<endl;
	cout<<"\t    5. EmptyStack Exception test"<<endl;
	cout<<"\t    6. FullStack Exception test"<<endl;
	cout<<"\t    7. Print all the elements in stack"<<endl;
	cout<<"\t    0. Quit"<<endl<<endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Push new record into the stack.
int Application::PushItem()
{
	if(!m_Stack.IsFull())
	{
		ItemType item;
		cout << "Input Element : ";
		cin >> item;

		m_Stack.Push(item);
		DisplayAllItem();
		
		return 1;
	}

	return 0;
}


// Pop a record of top from the stack.
int Application::PopItem()
{
	if(!m_Stack.IsEmpty())
	{
		ItemType item;
		item = m_Stack.Pop();
		cout << "Pop Element : " << item << endl << endl;
		
		DisplayAllItem();
		
		return 1;
	}

	return 0;
}


// Check the stack is empty state.
int Application::CheckEmpty()
{
	if(m_Stack.IsEmpty())
	{
		cout << "Stack is Empty." << endl << endl;
		return 1;
	}
	else
	{
		cout << "Stack is not Empty." << endl << endl;
		return 0;
	}
}


// Check the stack is full state.
int Application::CheckFull()
{
	if(m_Stack.IsFull())
	{
		cout << "Stack is Full." << endl << endl;
		return 1;
	}
	else
	{
		cout << "Stack is not Full." << endl << endl;
		return 0;
	}
}


// Test the exeception of empty stack.
void Application::TestEmptyException()
{
	ItemType item;
	
	while(1)
		item = m_Stack.Pop();
}


// Test the exeception of full stack.
void Application::TestFullException()
{
	ItemType item;
	srand((unsigned long)time(NULL));

	while(1)
	{
		item = rand();
		m_Stack.Print();
		m_Stack.Push(item);				
	}
}


// Display all records in the stack on screen.
void Application::DisplayAllItem()
{
	m_Stack.Print();
}