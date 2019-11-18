#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "MusicType.h"

using namespace std;


class PlayType
{
public:

	PlayType() {};							// 생성자
	~PlayType() {};							// 소멸자

	string GetName();					// 재생목록 곡 반환
	void SetName(string m_Id);			// 재생목록 곡 저장
	void SetNamePLByKB();				// 재생 목록 곡 키보드로 받기
	void DisplayPLNameOnScreen();			// 재생목록 곡 화면에 출력

	RelationType ComparePLByName(const PlayType& data);

private:
	string name; // 곡의 primary key
	 
};