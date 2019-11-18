#pragma once
#include <fstream>
#define FSIZE 2000
using namespace std;
#include "ItemType.h"
#include "DoublyLinkedList.h"
#include "DoublyIterator.h"

class ManagerApp
{
private:
	ifstream m_InFile;///< input file descriptor.
	ofstream m_OutFile;///< output file descriptor.
protected:
	int m_Command;
	int AllUserNumPlay;
	DoublyLinkedList<ItemType>m_List;


public:
	ManagerApp();
	~ManagerApp();

	void Run();
	int AddMusic();	//마스터리스트에 추가
	int ReplaceMusic();	//음원 내용 바꾸기
	int RetrieveMusic();	//primary key를 받아 음원 찾기
	int GetCommand();
	void DisplayAllMusic();	//모든 음원 정보 display

	int ReadDataFromFile();
	int OpenInFile(char *fileName);




};

