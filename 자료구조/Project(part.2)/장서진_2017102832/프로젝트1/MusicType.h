#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum RelationType { LESS, GREATER, EQUAL };

class MusicType
{
public:

	MusicType() {};							// ������
	~MusicType() {};						// �Ҹ���

	virtual void operator=(MusicType& tmp)
	{
		m_mId = tmp.GetId();
		m_mName = tmp.GetName();
		m_mComposer = tmp.GetComposer();
		m_mSinger = tmp.GetSinger();
		m_mGenre = tmp.GetGenre();
	}

	string GetId();							// ���̵� ��ȯ �Լ�
	string GetName();						// ��� ��ȯ �Լ�
	string GetComposer();                   // �۰��� ��ȯ �Լ�
	string GetSinger();                     // ���� Ȥ�� ������ ��ȯ �Լ�
	int GetGenre();							// �帣 ��ȯ �Լ�
	void SetId(string inId);				// ���̵� ���� �Լ�
	void SetName(string inName);			// ��� ���� �Լ�
	void SetComposer(string inComposer);	// �۰��� ���� �Լ�
	void SetSinger(string inSinger);		// ���� Ȥ�� ������ ���� �Լ�
	void SetGenre(int inGenre);				// �帣 ���� �Լ�
	void SetRecord(string inId, string inName, string inComposer, string inSinger, int inGenre); // ��ü ��� ���� �Լ�
	void DisplayIdOnScreen();				// ȭ�鿡 ID ���
	void DisplayNameOnScreen();				// ȭ�鿡 ��� ���
	void DisplayComposerOnScreen();			// ȭ�鿡 �۰ ��� 
	void DisplaySingerOnScreen();			// ȭ�鿡 ���� Ȥ�� ������ ���
	void DisplayGenreOnScreen();			// ȭ�鿡 �帣 ���
	void DisplayRecordOnScreen();			// ȭ�鿡 ��� ���
	void SetIdFromKB();						// ID Ű����� �ޱ�
	void SetNameFromKB();					// ��� Ű����� �ޱ�
	void SetComposerFromKB();				// �۰ Ű����� �ޱ�
	void SetSingerFromKB();					// ���� Ű����� �ޱ�
	void SetGenreFromKB();					// �帣 Ű����� �ޱ�
	void SetRecordFromKB();					// ��� ��ü Ű����� �ޱ�
	int ReadDataFromFile(ifstream& fin);	// ��� txt�κ��� �о� ����
	int WriteDataToFile(ofstream& fout);	// ��� txt�κ��� ����

	RelationType CompareByID(const MusicType& data);	// ���̵� ���ϱ�

private:

	string m_mId;					// ���� ID
	string m_mName;				// ���� ���
	string m_mComposer;			// ���� �۰
	string m_mSinger;			// ���� ���� Ȥ�� ������
	int m_mGenre;				// ���� �帣
};
