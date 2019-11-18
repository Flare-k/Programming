#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "ItemType.h"
using namespace std;

class PlayType : public ItemType
{
private:
	int inTime = 0;
public:
	PlayType();
	~PlayType();
	void DisplayPlaylistOnScreen();

};
