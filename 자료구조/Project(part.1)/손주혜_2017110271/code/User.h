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
	void StoreInfoInFile();//ȸ�����Կ�. id�� pw�� �Է��Ͽ� txt���Ͽ� ����
	void run(string _id, string _pw);
	int login(string &_id, string &_pw,int &customer);
//	int JoinMember();
	//int 
//	void StoreInfoInFile();
};

