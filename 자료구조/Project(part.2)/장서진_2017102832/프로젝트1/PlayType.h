#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "MusicType.h"

using namespace std;


class PlayType
{
public:

	PlayType() {};							// ������
	~PlayType() {};							// �Ҹ���

	string GetName();					// ������ �� ��ȯ
	void SetName(string m_Id);			// ������ �� ����
	void SetNamePLByKB();				// ��� ��� �� Ű����� �ޱ�
	void DisplayPLNameOnScreen();			// ������ �� ȭ�鿡 ���

	RelationType ComparePLByName(const PlayType& data);

private:
	string name; // ���� primary key
	 
};