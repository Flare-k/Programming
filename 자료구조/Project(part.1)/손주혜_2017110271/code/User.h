#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Application.h"

using namespace std;

class User 
{
private:
	string id, pw, searchid, searchpw;
	string textfile="UserData.txt";
	ofstream fout;
	ifstream fin;
	string anw;
//	Manager manager;

public:
	User();
	~User();
	User(string id, string pw);
	void SetIdPwKeyboard();
	void StoreInfoInFile();//회원가입용. id와 pw를 입력하여 txt파일에 저장
	void run(string _id, string _pw);
	int login(string &_id, string &_pw,int &customer);
//	int JoinMember();
	//int 
//	void StoreInfoInFile();
};

