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
	// ���� �ð��� Id�� ����
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

// ȭ�鿡 ���� ���� ���
void BestType::DisplayIdOnScreen()
{
	cout << "\t���̵�: " << GetId() << endl;
}

void BestType::DisplayNameOnScreen()
{
	cout << "\t�� ��: " << GetName() << endl;
}

void BestType::DisplaySingerOnScreen()
{
	cout << "\t���� Ȥ�� ������: " << GetSinger() << endl;
}

void BestType::DisplayRecordOnScreen()
{
	DisplayIdOnScreen();
	DisplayNameOnScreen();
	DisplaySingerOnScreen();
	cout << endl;
}

// Ű����� �Է� �ޱ�
void BestType::SetIdFromKB()
{
	cout << "\t(1) �α� ��Ʈ �� ���̵� �Է�: ";
	cin >> m_bId;
}

void BestType::SetNameFromKB()
{
	cout << "\t(2) �α� ��Ʈ �� �� �Է�: ";
	cin >> m_bName;
}


void BestType::SetSingerFromKB()
{
	cout << "\t(3) �α� ��Ʈ ���� Ȥ�� ������ �Է�: ";
	cin >> m_bSinger;
}

void BestType::SetRecordFromKB()
{
	SetIdFromKB();
	SetNameFromKB();
	SetSingerFromKB();
}

// ������ ���� �ҷ�����
int BestType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_bId;
	fin >> m_bName;
	fin >> m_bSinger;

	return 1;
}

// ������ ���Ͽ� ����
int BestType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_bId << " ";
	fout << m_bName << " ";
	fout << m_bSinger << " ";
	
	return 1;
}

// ���̵�� ��
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