#pragma once
#include <iostream>

using namespace std;

#define maxsize 8

/**
*	@brief	Exception class thrown by Push when stack is full.
*/
class FullStack
{
public:
	/**
	*	@brief	Display a message for full stack on screen.
	*/
	void print()
	{
		cout << "FullStack exception thrown." << endl;
	}
};

/**
*	@brief	Exception class thrown by Pop and Top when stack is empty.
*/
class EmptyStack
{
public:
	/**
	*	@brief	Display a message for full stack on screen.
	*/
	void print()
	{
		cout << "EmtpyStack exception thrown." << endl;
	}
};

template <typename T>	//generic data을 위해 template 선언
class CircularQueueType
{
public:
	/**
	*	@brief	size에 해당하는 크기의 배열을 동적할당
	*	@post	size의 값에 해당되는 크기의 배열이 만들어짐,각 멤버변수들이 초기화됨
	*/
	CircularQueueType(int size);
	/**
	*	@brief	최대크기로 생성
	*	@pre	최대크기가 정해져야함
	*	@post	최대크기의 배열이 만들어지고, 각 멤버변수들이 초기화됨
	*/
	CircularQueueType();

	
	~CircularQueueType();



	/**
	*	@brief	queue가 가득차있는지 확인.
	*	@pre	queue가 초기화 되어야함.
	*	@post	차있으면 ture 아니면 false
	*/
	bool IsFull() const;

	/**
	*	@brief	queue가 비어있는지 확인
	*	@pre	queue가 초기화 되어야함.
	*	@post	비어있으면 ture 아니면 false
	*/
	bool IsEmpty() const;

	/**
	*	@brief	queue에 회전하면서 값을 채움.
	*	@pre	queue가 초기화 되어야함
	*	@post	가득차있으면 FullStack Exception을 throw함, 아니면 새로운 값을 추가함,rear값 증가
	*/
	void EnQueue(T item);

	/**
	*	@brief	queue에 회전하면서 값을 삭제(=front값이 하나 증가)
	*	@pre	Stack has been initialized.
	*	@post	비어있으면 empty Exception을 throw;아니면 맨위의 값을 삭제
	*/
	void DeQueue(T& item);

	/**
	*	@brief	Returns a copy of top item on the stack.
	*	@pre	Stack has been initialized.
	*	@post	If (stack is empty), EmptyStack exception is thrown; otherwise, top element has been removed from stack.
	*/
	T Top();

	/**
	*	@brief	Print all the items in the stack on screen
	*	@pre	Stack has been initialized.
	*	@post	None.
	*/
	void Print();

	void MakeEmpty();

	
	/**
	*	@brief	front값과 rare값을 일치시킨다.
	*	@pre	none
	*	@post	플레이리스트에서 입력받은 id를 가진 레코드가 playlist에서 삭제된다.
	*/
	void  ResetList();

	/**
	*	@brief	curpointer가 가리키는 아이템의 다음 아이템을 파라미터에 복사한다.
	*	@pre	다음 아이템이 존재해야한다.
	*	@post	파라미터 데이터에 다음 아이템이 복사된다.
	*	@param	data	복사받을 데이터.
	*	@return 복사 성공시 true, 실패시 false.
	*/
	bool GetNextItem(T &data);
	/**
	*	@brief	파라미터로 들어온 id를 가진 데이터를 찾아 파라미터에 복사한다.
	*	@pre	해당 id를 가진 데이터가 존재해야한다.
	*	@post	파라미터에 해당 데이터가 복사된다.
	*	@param	data	복사받을 데이터
	*	@return 찾아서 복사하면 1, 실패하면 0
	*/
	int Search(T &data);
	/**
	*	@brief	파라미터로 들어온 id를 가진 데이터를 찾아 삭제한다.
	*	@pre	해당 id를 가진 데이터가 존재해야한다.
	*	@post	해당 데이터가 삭제된다.
	*	@param	data	삭제할 데이터
	*	@return 삭제 성공시 1, 실패시 0.
	*/
	int Delete(T data);
	/**
	*	@brief	파라미터로 들어온 id를 가진 데이터를 찾아 파라미터 데이터로 변경한다.
	*	@pre	해당 id를 가진 데이터가 존재해야한다.
	*	@post	해당 데이터가 파라미터 데이터로 변환된다.
	*	@param	data	변환할 데이터
	*	@return 변환 성공시 1, 실패시 0.
	*/
	int Replace(T data);



	
private:
	int curPointer; //리스트의 요소에 접근하는 curpointer변수.
	int m_iFront;
	int m_iRear;
	int m_nMaxQueue;
	int top;	///< Number of elements.
	T *items;	///< Pointer for a stack.

};


template <typename T>
CircularQueueType<T>::CircularQueueType(int size)
{
	items = new T[size];	//T의 자료형으로 동적할당
	m_iFront = size - 1; 
	m_iRear = size - 1;
	m_nMaxQueue = size;
	top = -1;

}
template <typename T>
CircularQueueType<T>::CircularQueueType()
{
	items = new T[maxsize];
	m_iFront = maxsize - 1;
	m_iRear = maxsize - 1;
	m_nMaxQueue = maxsize;
	top = -1;
}


// Destruct the object. Free the array dynamically allocated.
template <typename T>
CircularQueueType<T>::~CircularQueueType()
{
	delete[] items;
}


// Determines whether the CircularQueueType is full.
template <typename T>
bool CircularQueueType<T>::IsEmpty() const
{
	if (m_iRear == m_iFront)
		return true;
	else
		return false;
}


// Determines whether the CircularQueueType is empty.
template <typename T>
bool CircularQueueType<T>::IsFull() const
{

	if ((m_iRear + 1) % m_nMaxQueue == m_iFront)	//rear의 다음칸에 front인지 아닌지 검사
		return true;
	else
		return false;

}


// Adds newItem to the top of the CircularQueueType.
template <typename T>
void CircularQueueType<T>::EnQueue(T newItem)
{
	if (IsFull())
		throw FullStack();
	else
	{
		m_iRear = (m_iRear + 1) % m_nMaxQueue;
		items[m_iRear%m_nMaxQueue] = newItem;
		top++;
	}
}


// Removes top item from the CircularQueueType.
template <typename T>
void CircularQueueType<T>::DeQueue(T& item)
{
	top--;
	if (IsEmpty())			//비어있는지 검사
		throw EmptyStack();
	else
	{
		m_iFront = (m_iFront + 1) % m_nMaxQueue; //front를 앞으로 한칸 이동
		item = items[m_iFront];	//지워지는, 접근되지 않을 값을 알기위해서 item에 해당 값을 전달

	}
}


// Removes top item from the CircularQueueType.
template <typename T>
T CircularQueueType<T>::Top()
{
	if (IsEmpty())
		throw EmptyStack();
	else
		return items[top];
}


// Print all the items in the CircularQueueType on screen
template <typename T>
void CircularQueueType<T>::Print()
{
	if (IsEmpty())				//비었으면 it is empty출력. Empty Stack을 throw하면 프로그램이 종료되어서 다시 Enqueue할수없으므로
		cout << "\t* It is empty!" << endl;				//부득이하게 새로운 예외처리
	else
	{
		cout << "\t* CircularQueueType: ";
		// CircularQueueType 내의모든element 출력.
		int first = m_iFront;
		int last = m_iRear;
		while (first != last)				//Rear값과 front가 같지 않을동안만. front로 시작해서 값을 하나씩 출력.Enqueue하면 rear가 front에 비해 앞서있으므로
		{
			cout << items[(first + 1) % m_nMaxQueue] << " - ";
			first = (first + 1) % m_nMaxQueue;
		}
		cout << endl;
	}
}
template <typename T>
void CircularQueueType<T>::MakeEmpty()
{
	m_iFront = m_iRear; //Front랑 rear랑 값이 같으면 isEmpty에서 텅빈것으로 연산됨
}


//	void  ResetList();
//tuple<T, bool> GetNextItem();
//T Search(T data);
//int Delete(T data);
//int Repalce(T data);

//queue 기능 추가

template<typename T>
void CircularQueueType<T>::ResetList() {
	curPointer = m_iFront;
}

template<typename T>
bool CircularQueueType<T>::GetNextItem(T &data) {
	if (IsEmpty() == false) {
		curPointer = (curPointer + 1)% m_nMaxQueue;
		data = items[curPointer];
		if (curPointer == (m_iRear+1)% m_nMaxQueue) {
			return false;
		}
		return true;
	}
	return false;
}

template<typename T>
int CircularQueueType<T>::Search(T &data) {
	for (int i = m_iFront + 1; i != m_iRear; i++) {
		if (i == m_nMaxQueue) {
			i = 0;
		}
		if (data == items[i]) {
			data = items[i];
			return 1;
		}
	}
	return 0;
}
/*
template<typename T>
int CircularQueueType<T>::Delete(T data) {
	for (int i = (m_iFront + 1)%m_nMaxQueue; i != m_iRear; i++) {
		if (i == m_nMaxQueue) {
			i = 0;
		}
		if (data == items[i]) {
			//m_iFront = (m_iFront + 1) % m_nMaxQueue;
			int iter = i - 1;
			if (iter == -1) {
				iter = m_nMaxQueue - 1;
			}
			while (iter != m_iFront) {
				items[iter + 1] = items[iter];
				iter--;
				if (iter == -1) {
					iter = m_nMaxQueue - 1;
				}
			}
			return 1;
		}
	}
	return 0;
}
*/
template<typename T>
int CircularQueueType<T>::Delete(T item)//item의 ID와 일치하는 레코드를 Queue에서삭제 
{
	int i = m_iFront;
	while (1)
	{
		i = (i + 1) % m_nMaxQueue;

		if (item == items[i])
		{
			while (i != m_iRear)
			{
				items[i] =items[(i + 1) % m_nMaxQueue];
				i = (i + 1) % m_nMaxQueue;
			}

			m_iRear = (m_iRear + m_nMaxQueue - 1) % m_nMaxQueue;
		
			return 1;
		}

		if (i == m_iRear)
			return 0;
	}
}

template<typename T>
int CircularQueueType<T>::Replace(T data) {
	for (int i = m_iFront + 1; i != m_iRear; i++) {
		if (i == m_nMaxQueue) {
			i = 0;
		}
		if (data == items[i]) {
			items[i] == data;
			return 1;
		}
	}
	return 0;
}