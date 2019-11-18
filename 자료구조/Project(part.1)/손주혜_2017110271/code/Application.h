#pragma once
#include "ItemType.h"
#include "PlayType.h"
#include "DoublyLinkedList.h"
#include "SortedList.h"
#include "User.h"
#include "ManagerApp.h"


class Application : public ManagerApp
{

public:
	Application();
	~Application();
	int login();//로그인함수
	int Join();//회원가입함수
	void Run();

	int GetCommand();
	void AddSongToPL();//곡의 primary key를 받고 모든 playlist에 넣기
	int DeleteSong();//곡의 primary key를 받고 모든 playlist에서 삭제
	
	void DisplayAllMusic();


	void DisplayUnsortedPL();//최신순리스트를 보여줌 tail->prev부터 보여주도록 한다.
	void DisplaySortedSong();//노래제목별 정렬된 순의 리스트를 보여줌
	void DisplayBySinger();//플레이리스트에 들어가있는 가수를 먼저 보여줌. 
	//그 안에서 a가수를 누르면 해당 목록이 나온다.
	
	//display를 누르면 play버튼이 그 안에 있다.
	void DisplayAllsong();

	int PlayByOrder();
	int PlayByFreq();
	int PlaySelectedMusic();

private:
	int time = 0;
	DoublyLinkedList<PlayType>m_UnsortedPL;
	ManagerApp* pManage;
//	DoublyLinkedList<PlayType>m_SingerList;
	int admit=0;
	//User user[10];
};

