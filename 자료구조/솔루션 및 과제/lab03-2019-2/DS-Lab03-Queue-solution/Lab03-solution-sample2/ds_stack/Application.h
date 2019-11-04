#ifndef _APPLICATION_H
#define _APPLICATION_H


#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "CircularQueueType.h"
#include "ItemType.h"

/**
*	application class for item management simply.
*/
//circular queue type의 자료형과 부합하게 하기 위해 template선언
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
	*	@brief	명령을 표출하고 키보드로 부터 입력받음
	*	@pre	none.
	*	@post	none.
	*	@return	사용자의 명령.
	*/
	int GetCommand();

	/**
	*	@brief	새로운 값을 queue에 추가
	*	@pre	queue과 꽉차지 않아야함.
	*	@post	새로운 값이 queue에 추가됨.
	*	@return	성공시 1, 실패시 0.
	*/
	int EnqueueItem();

	/**
	*	@brief	맨위의 queue값을 삭제
	*	@pre	queue에 값이 있어야함
	*	@post	맨위의 값이 삭제됨
	*	@return	성공시 1, 실패시 0.
	*/
	int DequeueItem();

	/**
	*	@brief	queue가 비었는지 확인
	*	@return	비어있으면 1 리턴  그렇지 않으면 0.
	*/
	int CheckEmpty();

	/**
	*	@brief	queue가 꽉찼는지 확인
	*	@return	꽉차면 1 리턴, 아니면 0.
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
	*	@brief	모든 값을 화면에 출력.
	*	@pre	큐가 비어있으면 안됨.
	*	@post	모든값을 출력, 비어있으면 It is empty 출력.
	*/
	void DisplayAllItem();
	/**
	*	@brief	queue를 텅비게 만듦
	*	@post	queue를 텅빈것처럼 만듦.front=rear;
	*/
	void EmptyItem();
	
private:
	CircularQueueType<ItemType> m_Stack;		///< item stack.
	int m_Command;			///< current command number.
};

#endif	// _APPLICATION_H