#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum RelationType { LESS, GREATER, EQUAL };

class MusicType
{
public:

	MusicType() {};							// 생성자
	~MusicType() {};						// 소멸자

	virtual void operator=(MusicType& tmp)
	{
		m_mId = tmp.GetId();
		m_mName = tmp.GetName();
		m_mComposer = tmp.GetComposer();
		m_mSinger = tmp.GetSinger();
		m_mGenre = tmp.GetGenre();
	}

	string GetId();							// 아이디 반환 함수
	string GetName();						// 곡명 반환 함수
	string GetComposer();                   // 작곡자 반환 함수
	string GetSinger();                     // 가수 혹은 연주자 반환 함수
	int GetGenre();							// 장르 반환 함수
	void SetId(string inId);				// 아이디 저장 함수
	void SetName(string inName);			// 곡명 저장 함수
	void SetComposer(string inComposer);	// 작곡자 저장 함수
	void SetSinger(string inSinger);		// 가수 혹은 연주자 저장 함수
	void SetGenre(int inGenre);				// 장르 저장 함수
	void SetRecord(string inId, string inName, string inComposer, string inSinger, int inGenre); // 전체 기록 저장 함수
	void DisplayIdOnScreen();				// 화면에 ID 출력
	void DisplayNameOnScreen();				// 화면에 곡명 출력
	void DisplayComposerOnScreen();			// 화면에 작곡가 출력 
	void DisplaySingerOnScreen();			// 화면에 가수 혹은 연주자 출력
	void DisplayGenreOnScreen();			// 화면에 장르 출력
	void DisplayRecordOnScreen();			// 화면에 기록 출력
	void SetIdFromKB();						// ID 키보드로 받기
	void SetNameFromKB();					// 곡명 키보드로 받기
	void SetComposerFromKB();				// 작곡가 키보드로 받기
	void SetSingerFromKB();					// 가수 키보드로 받기
	void SetGenreFromKB();					// 장르 키보드로 받기
	void SetRecordFromKB();					// 기록 전체 키보드로 받기
	int ReadDataFromFile(ifstream& fin);	// 기록 txt로부터 읽어 오기
	int WriteDataToFile(ofstream& fout);	// 기록 txt로부터 쓰기

	RelationType CompareByID(const MusicType& data);	// 아이디 비교하기

private:

	string m_mId;					// 음원 ID
	string m_mName;				// 음원 곡명
	string m_mComposer;			// 음원 작곡가
	string m_mSinger;			// 음원 가수 혹은 연주자
	int m_mGenre;				// 음원 장르
};
