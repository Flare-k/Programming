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
	int AddMusic();	//�����͸���Ʈ�� �߰�
	int ReplaceMusic();	//���� ���� �ٲٱ�
	int RetrieveMusic();	//primary key�� �޾� ���� ã��
	int GetCommand();
	void DisplayAllMusic();	//��� ���� ���� display

	int ReadDataFromFile();
	int OpenInFile(char *fileName);




};

