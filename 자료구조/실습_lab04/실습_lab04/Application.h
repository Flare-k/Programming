#pragma once
#include <iostream>
#include <string>
#include <fstream>

#include "ItemType.h"
#include "Singer.h"
#include "SimpleItemType.h"
#include "PlayItem.h"

#include "SortedList.h"
#include "SortedLinkedList.h"
#include "UnsortedList.h"
#include "CircularQueue.h"
using namespace std;

//Application 클래스

class Application
{
private:
    ifstream m_InFile;
    ofstream m_OutFile;
    SortedList<ItemType> m_List;        //Master List
    CircularQueue<PlayItem> q_List;     //Play List
    SortedLinkedList<Singer> s_List;    //Singer List
    UnsortedList<SimpleItemType> simple_List;//Song List
    
    int m_Command;
    int times = 0;
    
public:
    Application(){
        m_Command=0;
    }
    ~Application(){}
    
    void Run();
    int GetCommand();
    
    // Master List
    int AddMusic();
    int DeleteMusic();
    void ​​​DisplayAllMusic();
    int OpenInFile(string &fileName);
    int OpenOutFile(string &fileName);
    int ReadDataFromFile();
    int WriteDataToFile();
    void ReplaceMusic();
    void SearchByid_Seq();
    void SearchByid_BinaryS();
    int SearchByArtist();
    int SearchByGenre();
        
    // Play List
    void AddtoPlayList();
    int DeletetoPlayList();
    void PlayInsertOrder();
    void PrintPlayList();
    int SearchinPL_BinaryS();
    int ReplacePlayList();
    void TestEmptyException();
    void TestFullException();

    // Singer & Song List
    void ​​​DisplayAllSingerList();
    void ​​​DisplayAllSongList();
    int AddSinger();
    int AddSong();
    void SearchBySinger();
};
