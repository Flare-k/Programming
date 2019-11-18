#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "MusicType.h"

using namespace std;

class BestType
{
public:

	virtual void operator=(BestType& tmp)
	{
		m_bId = tmp.GetId();
		m_bName = tmp.GetName();
		m_bSinger = tmp.GetSinger();
	}

	BestType() {};							// 생성자
	~BestType() {};						// 소멸자

	string GetId();							// 아이디 반환 함수
	string GetName();						// 곡명 반환 함수
	string GetSinger();                     // 가수 혹은 연주자 반환 함수
	void SetId(string inId);				// 아이디 저장 함수
	void SetName(string inName);			// 곡명 저장 함수
	void SetSinger(string inSinger);		// 가수 혹은 연주자 저장 함수
	void SetRecord(string inId, string inName, string inSinger); // 전체 기록 저장 함수
	void DisplayIdOnScreen();				// 화면에 ID 출력
	void DisplayNameOnScreen();				// 화면에 곡명 출력
	void DisplaySingerOnScreen();			// 화면에 가수 혹은 연주자 출력
	void DisplayRecordOnScreen();			// 화면에 기록 출력
	void SetIdFromKB();						// ID 키보드로 받기
	void SetNameFromKB();					// 곡명 키보드로 받기
	void SetSingerFromKB();					// 가수 키보드로 받기
	void SetRecordFromKB();					// 기록 전체 키보드로 받기
	int ReadDataFromFile(ifstream& fin);	// 기록 txt로부터 읽어 오기
	int WriteDataToFile(ofstream& fout);	// 기록 txt로부터 쓰기

	RelationType CompareByID(const BestType& data);	// 아이디 비교하기
	RelationType CompareByName(const BestType& data);

private:
	string m_bId;					// 인기 차트 음원 ID
	string m_bName;				// 인기 차트 곡명
	string m_bSinger;			// 인기 차트 가수 혹은 연주자 명
};
