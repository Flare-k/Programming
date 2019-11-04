#ifndef _APPLICATION_
#define _APPLICATION_

#include <iostream>
#include <fstream>
#include <string>
#include "ItemType.h"
#include "ListItem.h"
#include "QueueItem.h"
using namespace std;

class Application {
private:
	ifstream m_InFile;		//input file descriptor
	ofstream m_OutFile;		//output file descriptor
	ListItem m_MusicList;	//music list
	QueueItem m_PlayList;	//play list
	int m_CurCommand;		//current command number

public:
	Application();	// default constructor
	~Application();	// default destructor
	
	//===================================================================================
	// Function: Program driver
	// Pre: none
	// Post : none
    //===================================================================================
	void Run();

	//===================================================================================
	// Function: Display command on screen and get a input from keyboard
	// Pre: 
	// Post : get command number.
    //===================================================================================
	int GetCommand();

	//===================================================================================
	// Function: Add new Music record to list
	// Pre: 
	// Post : list is added new Music record.
	//===================================================================================
	int AddMusic();

	//===================================================================================
	// Function: Delete a Music record in list
	// Pre: 
	// Post : list is deleted a Music record.
	//===================================================================================
	int DeleteMusic();
	
	//===================================================================================
	// Function: Modify a Music record in list
	// Pre: 
	// Post : list is modified a Music record.
	//===================================================================================
	int ModifyMusic();


	int SearchListByMusicName(ItemType& inData);	
	int SearchListByArtistName(ItemType& inData);
	int SearchListByGenre(ItemType& inData);
	int SearchListByReleaseDate(ItemType& inData1, ItemType& inData2, ItemType& returnData);


	//===================================================================================
	// Function: Read in a each key from keyboard, search the record by key, and display on the screen
	// Pre: none
	// Post : record on screen. If found, return 1. Otherwise 0
    //===================================================================================
	int RetrieveRecordByMusicName();
	int RetrieveRecordByArtistName();
	int RetrieveRecordByGenre();
	int RetrieveRecordByReleaseDate();
	

	//===================================================================================
	// Function: Display all record in the Music list on screen
	// Pre: 
	// Post : Music records on screen
	//===================================================================================
	void DisplayAllMusic();

	//===================================================================================
	// Function: Open an input file
	// Pre: name should be valid
	// Post: m_InFile holds input file information. 
	//       if file open error occur, return 0. Otherwise return 1
    //===================================================================================
	int OpenInFile(char *fileName);

	//===================================================================================
	// Function: Open an output file
	// Pre: name should be valid
	// Post: m_OutFile holds output file information. 
	//       if file open error occur, return 0. Otherwise return 1
    //===================================================================================
	int OpenOutFile(char *fileName);

	//===================================================================================
	// Function: Open an input fle and read all the Music record from a file
	// Pre: file is not opened
	// Post: studeList holds all Music records read from a file. The m_InFile is closed
	//       if file open error or file read error occur, return 0. Otherwise return 1
    //===================================================================================
	int ReadMusicListFromFile();

	//===================================================================================
	// Function: Open an output file and write all Music records to the file
	// Pre: None
	// Post: the Music list is stored in the output file
	//===================================================================================
	int WriteMusicListToFile();

	void PlayMusic();

	void AddPlayList();
	
	void ShowPlayList();

};

#endif