#ifndef _ITEMTYPE_
#define _ITEMTYPE_


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum RelationType {LESS, GREATER, EQUAL, DIFFERENT};


class ItemType {
protected:
	string m_MusicName;
	string m_ArtistName;
	string m_Genre;
	string m_PlayTime;
	string m_Date;
	string m_ReleaseDate;


public :
	ItemType();		// default constructor
	~ItemType();	// default destructor

	string GetMusicName()		// ������ �̸�(���)�� �ҷ��´�.
	{
		return m_MusicName;
	}

	string GetArtistName()		// ������ ��Ƽ��Ʈ�̸��� �ҷ��´�.
	{
		return m_ArtistName;
	}

	string GetGenre()			// ������ �帣�� �ҷ��´�.
	{
		return m_Genre;
	}

	string GetPlayTime()		// ������ ����ð��� �ҷ��´�.
	{
		return m_PlayTime;
	}

	string GetReleaseDate()			// ������ ���縦 �ҷ��´�.
	{
		return m_ReleaseDate;
	}

	string GetDate()			// ������ �ֱ� ��� ��¥�� �ҷ��´�.
	{
		return m_Date;
	}

	
	/*===================================================================================
	// Function : ��������� ������ �̸��� �����Ѵ�.
	// Pre		: None
	// Post		: ��������� m_MusicName�� ����ȴ�.
	=====================================================================================*/
	void PutMusicName(string MusicName)		// ������ �̸�(���)�� �����Ѵ�.
	{
		this->m_MusicName = MusicName;
	}
	void PutArtistName(string ArtistName)		// ������ ��Ƽ��Ʈ�̸��� �����Ѵ�.
	{
		this->m_ArtistName = ArtistName;
	}
	void PutGenre(string Genre)			// ������ �帣�� �����Ѵ�.
	{
		this->m_Genre = Genre;
	}
	void PutPlayTime(string PlayTime)			// ������ ����ð��� �����Ѵ�.
	{
		this->m_PlayTime = PlayTime;
	}
	void PutReleaseDate(string ReleaseDate)			// ������ �߸����� �����Ѵ�.
	{
		this->m_ReleaseDate = ReleaseDate;
	}
	void PutDate(string Date)				// ������ �ֱ� ��� ��¥�� �����Ѵ�.
	{
		this->m_Date = Date;
	}

	/*===================================================================================
	// Function : ��������鿡 �����̸�, ��Ƽ��Ʈ�̸�, �ֱ� ���� ��¥, ����ð�, �߸���
	�帣�� �����Ѵ�. ��������� �����͸� �����ϴ� �Լ��� ����ü
	// Pre		: None
	// Post		: ������� m_MusicName, m_ArtistName, m_RecentDate, m_PlayTime, m_ReleaseDate, 
	m_Genre�� ����ȴ�.
	=====================================================================================*/
	void PutRecord(string MusicName, string ArtistName, string Date, string PlayTime,
		string ReleaseDate, string Genre); // ���ڵ带 �����Ѵ�.

	void CopyRecord(ItemType data);

	void PutMusicNameOnScreen();	// ������ �̸�(���)�� ȭ�鿡 ����Ѵ�.
	void PutArtistNameOnScreen();	// ������ ��Ƽ��Ʈ�̸��� ȭ�鿡 ����Ѵ�.
	void PutDateOnScreen();			// ������ �ֱ� ��� ��¥�� ȭ�鿡 ����Ѵ�.
	void PutPlayTimeOnScreen();		// ������ ����ð��� ȭ�鿡 ����Ѵ�.
	void PutReleaseDateOnScreen();	// ������ �߸����� ȭ�鿡 ����Ѵ�.
	void PutGenreOnScreen();		// ������ �帣�� ȭ�鿡 ����Ѵ�.
	void PutRecordOnScreen();		// ���ڵ带 ȭ�鿡 ����Ѵ�.


	int GetMusicNameFromKB();		// ������ �̸�(���)�� Ű���忡�� �����´�.
	int GetArtistNameFromKB();		// ������ ��Ƽ��Ʈ�̸��� Ű���忡�� �����´�.
	int GetDateFromKB();			// ������ �ֱ� ��� ��¥�� Ű���忡�� �����´�.
	int GetPlayTimeFromKB();		// ������ ����ð��� Ű���忡�� �����´�.
	int GetReleaseDateFromKB();		// ������ �߸����� Ű���忡�� �����´�.
	int GetGenreFromKB();			// ������ �帣�� Ű���忡�� �����´�.
	int GetRecordFromKB();			// ���ڵ��� ������ Ű���忡�� �����´�.
	

	/*===================================================================================
	// Function	: read 1 record from file.
	// Pre		: a file is opened and a file pointer is located on the record read.
	// Post		: variables, id and name, get record information, file pointer is located to the back.
	=====================================================================================*/
	int GetRecordFromFile(ifstream& fin);		// ���ڵ带 ���Ͽ��� �����´�.

	/*===================================================================================
	// Function : ���ڵ带 ���Ͽ� ����.
	// Pre		: a file is opened and a file pointer is located on the position for record write.
	//			  variables, id and name, have record information for writing.
	// Post		: write to the file and the file pointer is located to the back.
	=====================================================================================*/
	int PutRecordToFile(ofstream& fout);			// ���ڵ带 ���Ͽ� �����Ѵ�.


	//===================================================================================
	// Fuction : Determines the ordering of two ItemType objects based on their primary key.
	// Function	: compare this primary key to data's primary key
	// Pre		: none
	// Pose		: this primary key < data's primary key then return -1
	//			  this primary key > data's primary key then return 1
	//			  else									return 0
	//===================================================================================
	int CompareTo(ItemType data);

	RelationType CompareByMusicName(ItemType data);	// ������ �̸�(���)���� ��
	RelationType CompareByArtistName(ItemType data);// ������ ��Ƽ��Ʈ�̸����� ��
	RelationType CompareByDate(ItemType data);		// ������ �ֱ� ��� ��¥�� ��
	RelationType CompareByGenre(ItemType data);		// ������ �帣�� ��
	RelationType CompareByPlayTime(ItemType data);	// ������ ����ð����� ��

};




#endif