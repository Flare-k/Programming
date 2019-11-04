#pragma once
#include <iostream>
using namespace std;
class tmp
{
public:
	tmp(void);
	tmp(int m)
	{
		id=m;
	}
	void ttt()
	{
		cout<<"please"<<id<<endl;
	}
	~tmp(void);
private:
	int id;
	
};

