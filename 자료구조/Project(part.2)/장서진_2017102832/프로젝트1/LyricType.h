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

	LyricType() {};							// ������
	~LyricType() {};						// �Ҹ���

	string GetName();					// ���� �� ��(ID) ��ȯ
	string GetLyric();					// ���� ��ȯ
	void SetName(string m_Id);			// ���� �� �� ����
	void SetLyric(string m_Lyric);			// ���� �� �� ����
	void SetNamePLByKB();				// ���� �� �� Ű����� �ޱ�
	void DisplayPLNameOnScreen();			// ���� �� �� ȭ�鿡 ���
	void DisplayPLLyricOnScreen();			// ���� ȭ�鿡 ���
	void DisplayNameLyricOnScreen();		// �� ��� ���� ȭ�鿡 ���
	int ReadDataFromFile(ifstream& fin);	// ���� txt�κ��� �о� ����
	int WriteDataToFile(ofstream& fout);	// ���� txt�κ��� ����

	RelationType ComparePLByName(const LyricType& data);

private:
	string name; // ���
	string lyric; // ���� ����
};