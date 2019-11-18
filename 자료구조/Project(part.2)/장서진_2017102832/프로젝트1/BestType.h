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

	BestType() {};							// ������
	~BestType() {};						// �Ҹ���

	string GetId();							// ���̵� ��ȯ �Լ�
	string GetName();						// ��� ��ȯ �Լ�
	string GetSinger();                     // ���� Ȥ�� ������ ��ȯ �Լ�
	void SetId(string inId);				// ���̵� ���� �Լ�
	void SetName(string inName);			// ��� ���� �Լ�
	void SetSinger(string inSinger);		// ���� Ȥ�� ������ ���� �Լ�
	void SetRecord(string inId, string inName, string inSinger); // ��ü ��� ���� �Լ�
	void DisplayIdOnScreen();				// ȭ�鿡 ID ���
	void DisplayNameOnScreen();				// ȭ�鿡 ��� ���
	void DisplaySingerOnScreen();			// ȭ�鿡 ���� Ȥ�� ������ ���
	void DisplayRecordOnScreen();			// ȭ�鿡 ��� ���
	void SetIdFromKB();						// ID Ű����� �ޱ�
	void SetNameFromKB();					// ��� Ű����� �ޱ�
	void SetSingerFromKB();					// ���� Ű����� �ޱ�
	void SetRecordFromKB();					// ��� ��ü Ű����� �ޱ�
	int ReadDataFromFile(ifstream& fin);	// ��� txt�κ��� �о� ����
	int WriteDataToFile(ofstream& fout);	// ��� txt�κ��� ����

	RelationType CompareByID(const BestType& data);	// ���̵� ���ϱ�
	RelationType CompareByName(const BestType& data);

private:
	string m_bId;					// �α� ��Ʈ ���� ID
	string m_bName;				// �α� ��Ʈ ���
	string m_bSinger;			// �α� ��Ʈ ���� Ȥ�� ������ ��
};
