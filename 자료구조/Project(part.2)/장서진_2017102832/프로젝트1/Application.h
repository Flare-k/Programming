#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include "BestSorted.h"
#include "BestType.h"
#include "LyricList.h"
#include "LyricType.h"
#include "MusicSorted.h"
#include "MusicType.h"
#include "PlayQueue.h"
#include "PlayType.h"

#define FILENAMEMAX 100000

using namespace std;

class Application
{
public:
	// 1: Admin 2: User �� �� 1
	void RunAdminOrUser(); // �ɼ� ����
	int GetCommand(); // Ű����� �ɼ� �ޱ�

	void RunAdmin(); // Admin �ɼ� ����
	void RunUser(); // User �ɼ� ����

	int FirstGetCommand(); // 1�� Admin�� ��� ���� ���� �� �α���Ʈ ������ Ű���� �ޱ�
	int SecondGetCommand(); // 2�� User�� ��� ��� ��� ������ Ű���� �ޱ�

	// 1. Admin (��ü ���� ���� ���� & �α� ��Ʈ ����)
	// ���� ���� ����
	int AddMusic(); // ���� ���� �߰�
	int DeleteMusic(); // id ��ġ�ϴ� ���� ����
	int ReplaceMusic(); // id ��ġ�ϴ� ���� ���� Ű����� �Է� ���� ���� ������ �ٲٱ� 
	int DisplayById_Binary(); // list���� id binary�ϰ� ã��
	int DisplayAllMusic(); // ��� ���� ���� ȭ�鿡 ���
	int MakeEmpty(); // ��� ���� ���� ����
	int ReadMusicDataFromFile(); // Ű����� �Է¹��� ���� �̸��� ��ġ�ϴ� ���� �ҷ�����
	int WriteMusicDataToFile(); // ���� ���� �Է��� ���� �̸����� ���Ͽ� �����ϱ�
	
	// �α� ��Ʈ ����
	int AddBest(); //�� ������ ���� �߰�
	int DeleteBest(); // �� ��� ��ġ�ϴ� ���� ����
	int ReplaceBest(); // �� ��� ��ġ�ϴ� ���� ���� Ű����� �Է� ���� �� �ٲٱ�
	int GetBestByName_Binary(BestType& data); // �α� ��Ʈ �̸��� ���
	int DisplayBestByName(); // �α� ��Ʈ�� �� ������ ã�Ƽ� ���
	int DisplayAllBest(); // �α� ��Ʈ ����Ʈ ���� ���� ���
	int WriteBestDataToFile(); // ���� ���� �Է��� ���� �̸����� ���Ͽ� �����ϱ� 
	int ReadBestDataFromFile(); //  Ű����� �Է¹��� ���� �̸��� ��ġ�ϴ� ���� �ҷ�����
	
	int OpenInFile(char* fileName); // ���� ����
	int OpenOutFile(char* fileName); // ���� ����

	// 2. User (��� ��� ���� & ���� �˻�)
	int DisplayBestNames(); // �α� ��Ʈ�� �� ������ ã�Ƽ� ���
	int AddRecordToPL(); // Id�� Ű��Ʈ�κ��� �о list class�� ��� �Լ��� �̿��Ͽ� list���� ã�� ã�� ���ڵ� PlayList Enque�߰�
	int DeletePL(); // Ű����κ��� Id�� �о �ش� ���ڵ带 PL���� ã�Ƽ� ����
	int DisplayPL(); // PlayList�� ����� �׸��� ȭ�鿡 ���
	int PlayPL(); // ������ �� �� ������� ���
	int SearchLyric();// ��� ��� ��� ���� �˻� (���簡 ��� �ؽ�Ʈ�� �̸� ������ ����Ǿ� ����)
	
private:

	MusicSorted<MusicType> m_List; // ���� ����Ʈ	
	BestSorted<BestType> m_bestList; // �α� ��Ʈ ����Ʈ
	PlayList<PlayType> m_playList; // ��� ���
	LyricList<LyricType> m_lyricList; // ���� ���� ����Ʈ
	
	ifstream m_InFile; ///< input file descriptor.
	ofstream m_OutFile; ///< output file descriptor.
	int m_Command = 0; // Ŀ��� �ޱ�
	int m_Command_Ad = 0; // Admin Ŀ�ǵ� �ޱ�
	int m_Command_User = 0; // User Ŀ�ǵ� �ޱ�
};