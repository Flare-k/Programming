#pragma once
#ifndef _BASE_H
#define _BASE_H
#include<conio.h>
#include<Windows.h>

#define UP 72
#define DOWN 80
#define ENTER 13
#define CLS system("cls")
#define PAUSE system("PAUSE")

class ItemType;
class PlayList;
class ArtistList;

template<typename T>
class SortedList;

class Base
{
public:
	void gotoxy(int x, int y) {
		COORD Cur = { x - 1, y - 1 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	}
	

	static SortedList<ItemType> m_List;///< item list.
	static PlayList m_PlayList;
	static ArtistList artistList;
};

#endif