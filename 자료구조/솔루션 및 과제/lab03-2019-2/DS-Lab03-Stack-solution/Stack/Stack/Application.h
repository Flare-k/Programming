#ifndef _APPLICATION_H
#define _APPLICATION_H


#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Stack.h"


/**
*	application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_Command = 0;
	}
	
	/**
	*	destructor.
	*/
	~Application()	{}

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Push new record into the stack.
	*	@pre	The stack should be initialized.
	*	@post	A new record is pushed into the stack.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int PushItem();

	/**
	*	@brief	Pop a record of top from the stack.
	*	@pre	The stack should be initialized.
	*	@post	A top record is poped.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int PopItem();

	/**
	*	@brief	Check the stack is empty state.
	*	@pre	The stack should be initialized.
	*	@post	Display the state of stack on screen.
	*	@return	1 if the stack is empty, otherwise 0.
	*/
	int CheckEmpty();

	/**
	*	@brief	Check the stack is full state.
	*	@pre	The stack should be initialized.
	*	@post	Display the state of stack on screen.
	*	@return	1 if the stack is full, otherwise 0.
	*/
	int CheckFull();

	/**
	*	@brief	Test the exeception of empty stack.
	*	@pre	The stack should be initialized.
	*	@post	Do exception funciton when the stack is empty.
	*/
	void TestEmptyException();
	
	/**
	*	@brief	Test the exeception of full stack.
	*	@pre	The stack should be initialized.
	*	@post	Do exception funciton when the stack is full.
	*/
	void TestFullException();

	/**
	*	@brief	Display all records in the stack on screen.
	*	@pre	The stack should be initialized.
	*	@post	Display all records on screen.
	*/
	void DisplayAllItem();
	
private:
	Stack m_Stack;		///< item stack.
	int m_Command;			///< current command number.
};

#endif	// _APPLICATION_H