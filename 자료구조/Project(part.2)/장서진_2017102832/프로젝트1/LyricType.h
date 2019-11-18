#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include "MusicType.h"

using namespace std;


class LyricType
{
public:

	LyricType() {};							// 생성자
	~LyricType() {};						// 소멸자

	string GetName();					// 가사 곡 명(ID) 반환
	string GetLyric();					// 가사 반환
	void SetName(string m_Id);			// 가사 곡 명 저장
	void SetLyric(string m_Lyric);			// 가사 곡 명 저장
	void SetNamePLByKB();				// 가사 곡 명 키보드로 받기
	void DisplayPLNameOnScreen();			// 가사 곡 명 화면에 출력
	void DisplayPLLyricOnScreen();			// 가사 화면에 출력
	void DisplayNameLyricOnScreen();		// 곡 명과 가사 화면에 출력
	int ReadDataFromFile(ifstream& fin);	// 가사 txt로부터 읽어 오기
	int WriteDataToFile(ofstream& fout);	// 가사 txt로부터 쓰기

	RelationType ComparePLByName(const LyricType& data);

private:
	string name; // 곡명
	string lyric; // 곡의 가사
};