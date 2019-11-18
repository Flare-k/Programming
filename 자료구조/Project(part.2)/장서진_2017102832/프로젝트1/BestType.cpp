#pragma once
#include <time.h>
#include "BestType.h"

//Get
string BestType::GetId()
{
	return m_bId;
}

string BestType::GetName()
{
	return m_bName;
}

string BestType::GetSinger()
{
	return m_bSinger;
}

//Set
void BestType::SetId(string inId)
{
	// 현재 시간을 Id로 설정
	m_bId = inId;
}

void BestType::SetName(string inName)
{
	m_bName = inName;
}

void BestType::SetSinger(string inSinger)
{
	m_bSinger = inSinger;
}

void BestType::SetRecord(string inId, string inName, string inSinger)
{
	SetId(inId);
	SetName(inName);
	SetSinger(inSinger);
}

// 화면에 음원 정보 출력
void BestType::DisplayIdOnScreen()
{
	cout << "\t아이디: " << GetId() << endl;
}

void BestType::DisplayNameOnScreen()
{
	cout << "\t곡 명: " << GetName() << endl;
}

void BestType::DisplaySingerOnScreen()
{
	cout << "\t가수 혹은 연주자: " << GetSinger() << endl;
}

void BestType::DisplayRecordOnScreen()
{
	DisplayIdOnScreen();
	DisplayNameOnScreen();
	DisplaySingerOnScreen();
	cout << endl;
}

// 키보드로 입력 받기
void BestType::SetIdFromKB()
{
	cout << "\t(1) 인기 차트 곡 아이디 입력: ";
	cin >> m_bId;
}

void BestType::SetNameFromKB()
{
	cout << "\t(2) 인기 차트 곡 명 입력: ";
	cin >> m_bName;
}


void BestType::SetSingerFromKB()
{
	cout << "\t(3) 인기 차트 가수 혹은 연주자 입력: ";
	cin >> m_bSinger;
}

void BestType::SetRecordFromKB()
{
	SetIdFromKB();
	SetNameFromKB();
	SetSingerFromKB();
}

// 데이터 파일 불러오기
int BestType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_bId;
	fin >> m_bName;
	fin >> m_bSinger;

	return 1;
}

// 데이터 파일에 쓰기
int BestType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_bId << " ";
	fout << m_bName << " ";
	fout << m_bSinger << " ";
	
	return 1;
}

// 아이디로 비교
RelationType BestType::CompareByID(const BestType& data)
{
	if (this->m_bId > data.m_bId)
		return GREATER;
	else if (this->m_bId < data.m_bId)
		return LESS;
	else
		return EQUAL;
}

RelationType BestType::CompareByName(const BestType& data)
{
	if (this->m_bName > data.m_bName)
		return GREATER;
	else if (this->m_bName < data.m_bName)
		return LESS;
	else
		return EQUAL;
}