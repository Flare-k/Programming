#pragma once
#include "Base.h"
#include "DoublySortedLinkedList.h"
#include "PlayItem.h"
#include "SortedList.h"
#include <iostream>

using namespace std;



class PlayList : public Base
{
public:
	PlayList() {
		listInTime = 0;
	}
	~PlayList() {}
	
	/**
	*	@brief	playlist에 추가하고자 하는 음악을 parameter로부터 받아 추가한다. 배열이 꽉찼다면 오래된 것을 삭제하고 추가한다.
	*	@pre	none
	*	@post	playlist에 새로운 음악이 추가된다.
	*	@param	data	playlist에 추가하고자 하는 음악.
	*	@return none
	*/
	void AddPlayList(PlayItem data);
	

	/**
	*	@brief	파라미터로 들어온 id를 가진 데이터를 찾아 삭제한다.
	*	@pre	해당 id를 가진 데이터가 존재해야한다.
	*	@post	해당 데이터가 삭제된다.
	*	@param	data	삭제할 데이터
	*	@return 삭제 성공시 1, 실패시 0.
	*/
	int DeleteItem(PlayItem item);

	DoublyNodeType<PlayItem>* GetFirst() {
		return m_PlayArray.GetFirst();
	}
	void PrintAll();

	void PrintByFreq();

	void SetMaxPlayNum();
private:
	DoublySortedLinkedList<PlayItem> m_PlayArray;
	DoublyNodeType<PlayItem> curPointer;
	int maxPlayNum;
	int listInTime;
};






