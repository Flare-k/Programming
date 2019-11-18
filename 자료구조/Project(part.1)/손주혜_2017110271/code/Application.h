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
	int login();//�α����Լ�
	int Join();//ȸ�������Լ�
	void Run();

	int GetCommand();
	void AddSongToPL();//���� primary key�� �ް� ��� playlist�� �ֱ�
	int DeleteSong();//���� primary key�� �ް� ��� playlist���� ����
	
	void DisplayAllMusic();


	void DisplayUnsortedPL();//�ֽż�����Ʈ�� ������ tail->prev���� �����ֵ��� �Ѵ�.
	void DisplaySortedSong();//�뷡���� ���ĵ� ���� ����Ʈ�� ������
	void DisplayBySinger();//�÷��̸���Ʈ�� ���ִ� ������ ���� ������. 
	//�� �ȿ��� a������ ������ �ش� ����� ���´�.
	
	//display�� ������ play��ư�� �� �ȿ� �ִ�.
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

