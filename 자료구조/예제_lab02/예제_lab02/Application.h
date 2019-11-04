#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "SortedList.h"

using namespace std;

//Application 클래스
class Application
{
private:
    ifstream m_InFile;///< input file descriptor.
    ofstream m_OutFile;///< output file descriptor.
    SortedList m_List;///< item list.   ArrayList의 메소드를 쓰기위해 객체를 생성한 것일뿐이다.
    int m_Command;///< current command number.
    
public:
    Application(){
        m_Command=0;
    }
    ~Application(){}
    
    void Run();
    int GetCommand();
    
    int AddItem();
    int DeleteStudent();
    
    void DisplayAllItem();
    int OpenInFile(string &fileName);
    int OpenOutFile(string &fileName);
    int ReadDataFromFile();
    int WriteDataToFile();
    void RetrieveStudent();
    void ReplaceItem();
    void SearchByid_BinaryS();
};
