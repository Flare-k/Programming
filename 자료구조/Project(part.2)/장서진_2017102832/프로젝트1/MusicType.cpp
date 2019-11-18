#pragma once
#include <time.h>
#include "MusicType.h"

//Get
string MusicType::GetId()
{
	return m_mId;
}

string MusicType::GetName()
{
	return m_mName;
}

string MusicType::GetComposer()
{
	return m_mComposer;
}

string MusicType::GetSinger()
{
	return m_mSinger;
}

int MusicType::GetGenre()
{
	return m_mGenre;
}

//Set
void MusicType::SetId(string inId)
{
	// 현재 시간을 Id로 설정
	m_mId = inId;
}

void MusicType::SetName(string inName)
{
	m_mName = inName;
}

void MusicType::SetComposer(string inComposer)
{
	m_mComposer = inComposer;
}

void MusicType::SetSinger(string inSinger)
{
	m_mSinger = inSinger;
}

void MusicType::SetGenre(int inGenre)
{
	m_mGenre = inGenre;
}

void MusicType::SetRecord(string inId, string inName, string inComposer, string inSinger, int inGenre)
{
	SetId(inId);
	SetName(inName);
	SetComposer(inComposer);
	SetSinger(inSinger);
	SetGenre(inGenre);
}

// 화면에 음원 정보 출력
void MusicType::DisplayIdOnScreen()
{
	cout << "\t아이디: " << GetId() << endl;
}

void MusicType::DisplayNameOnScreen()
{
	cout << "\t곡 명: " << GetName() << endl;
}

void MusicType::DisplayComposerOnScreen()
{
	cout << "\t작곡가: " << GetComposer() << endl;
}

void MusicType::DisplaySingerOnScreen()
{
	cout << "\t가수 혹은 연주자: " << GetSinger() << endl;
}

void MusicType::DisplayGenreOnScreen()
{
	cout << "\t장르: " << GetGenre() << endl;
}

void MusicType::DisplayRecordOnScreen()
{
	DisplayIdOnScreen();
	DisplayNameOnScreen();
	DisplayComposerOnScreen();
	DisplaySingerOnScreen();
	DisplayGenreOnScreen();
	cout << endl;
}

// 키보드로 입력 받기
void MusicType::SetIdFromKB()
{
	cout << "\t(1) 곡 아이디 입력: ";
	cin >> m_mId;
}

void MusicType::SetNameFromKB()
{
	cout << "\t(2) 곡 명 입력: ";
	cin >> m_mName;
}

void MusicType::SetComposerFromKB()
{
	cout << "\t(3) 작곡가 입력: ";
	cin >> m_mComposer;
}

void MusicType::SetSingerFromKB()
{
	cout << "\t(4) 가수 혹은 연주자 입력: ";
	cin >> m_mSinger;
}

void MusicType::SetGenreFromKB()
{
	cout << "\t(5) 장르 입력: ";
	cin >> m_mGenre;
}

void MusicType::SetRecordFromKB()
{
	SetIdFromKB();
	SetNameFromKB();
	SetComposerFromKB();
	SetSingerFromKB();
	SetGenreFromKB();
}

// 데이터 파일 불러오기
int MusicType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_mId;
	fin >> m_mName;
	fin >> m_mComposer;
	fin >> m_mSinger;
	fin >> m_mGenre;

	return 1;
}

// 데이터 파일에 쓰기
int MusicType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_mId << " ";
	fout << m_mName << " ";
	fout << m_mComposer << " ";
	fout << m_mSinger << " ";
	fout << m_mGenre << " ";

	return 1;
}

// 아이디로 비교
RelationType MusicType::CompareByID(const MusicType& data)
{
	if (this->m_mId > data.m_mId)
		return GREATER;
	else if (this->m_mId < data.m_mId)
		return LESS;
	else
		return EQUAL;
}

