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
	// ���� �ð��� Id�� ����
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

// ȭ�鿡 ���� ���� ���
void MusicType::DisplayIdOnScreen()
{
	cout << "\t���̵�: " << GetId() << endl;
}

void MusicType::DisplayNameOnScreen()
{
	cout << "\t�� ��: " << GetName() << endl;
}

void MusicType::DisplayComposerOnScreen()
{
	cout << "\t�۰: " << GetComposer() << endl;
}

void MusicType::DisplaySingerOnScreen()
{
	cout << "\t���� Ȥ�� ������: " << GetSinger() << endl;
}

void MusicType::DisplayGenreOnScreen()
{
	cout << "\t�帣: " << GetGenre() << endl;
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

// Ű����� �Է� �ޱ�
void MusicType::SetIdFromKB()
{
	cout << "\t(1) �� ���̵� �Է�: ";
	cin >> m_mId;
}

void MusicType::SetNameFromKB()
{
	cout << "\t(2) �� �� �Է�: ";
	cin >> m_mName;
}

void MusicType::SetComposerFromKB()
{
	cout << "\t(3) �۰ �Է�: ";
	cin >> m_mComposer;
}

void MusicType::SetSingerFromKB()
{
	cout << "\t(4) ���� Ȥ�� ������ �Է�: ";
	cin >> m_mSinger;
}

void MusicType::SetGenreFromKB()
{
	cout << "\t(5) �帣 �Է�: ";
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

// ������ ���� �ҷ�����
int MusicType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_mId;
	fin >> m_mName;
	fin >> m_mComposer;
	fin >> m_mSinger;
	fin >> m_mGenre;

	return 1;
}

// ������ ���Ͽ� ����
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

// ���̵�� ��
RelationType MusicType::CompareByID(const MusicType& data)
{
	if (this->m_mId > data.m_mId)
		return GREATER;
	else if (this->m_mId < data.m_mId)
		return LESS;
	else
		return EQUAL;
}

