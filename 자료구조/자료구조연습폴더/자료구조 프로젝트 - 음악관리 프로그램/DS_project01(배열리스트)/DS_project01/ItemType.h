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

	string GetMusicName()		// 음악의 이름(곡명)을 불러온다.
	{
		return m_MusicName;
	}

	string GetArtistName()		// 음악의 아티스트이름을 불러온다.
	{
		return m_ArtistName;
	}

	string GetGenre()			// 음악의 장르를 불러온다.
	{
		return m_Genre;
	}

	string GetPlayTime()		// 음악의 재생시간을 불러온다.
	{
		return m_PlayTime;
	}

	string GetReleaseDate()			// 음악의 가사를 불러온다.
	{
		return m_ReleaseDate;
	}

	string GetDate()			// 음악의 최근 재생 날짜를 불러온다.
	{
		return m_Date;
	}

	
	/*===================================================================================
	// Function : 멤버변수에 음악의 이름을 저장한다.
	// Pre		: None
	// Post		: 멤버변수에 m_MusicName에 저장된다.
	=====================================================================================*/
	void PutMusicName(string MusicName)		// 음악의 이름(곡명)을 저장한다.
	{
		this->m_MusicName = MusicName;
	}
	void PutArtistName(string ArtistName)		// 음악의 아티스트이름을 저장한다.
	{
		this->m_ArtistName = ArtistName;
	}
	void PutGenre(string Genre)			// 음악의 장르를 저장한다.
	{
		this->m_Genre = Genre;
	}
	void PutPlayTime(string PlayTime)			// 음악의 재생시간을 저장한다.
	{
		this->m_PlayTime = PlayTime;
	}
	void PutReleaseDate(string ReleaseDate)			// 음악의 발매일을 저장한다.
	{
		this->m_ReleaseDate = ReleaseDate;
	}
	void PutDate(string Date)				// 음악의 최근 재생 날짜를 저장한다.
	{
		this->m_Date = Date;
	}

	/*===================================================================================
	// Function : 멤버변수들에 음악이름, 아티스트이름, 최근 실행 날짜, 재생시간, 발매일
	장르를 저장한다. 멤버변수에 데이터를 저장하는 함수의 집합체
	// Pre		: None
	// Post		: 멤버변수 m_MusicName, m_ArtistName, m_RecentDate, m_PlayTime, m_ReleaseDate, 
	m_Genre에 저장된다.
	=====================================================================================*/
	void PutRecord(string MusicName, string ArtistName, string Date, string PlayTime,
		string ReleaseDate, string Genre); // 레코드를 저장한다.

	void CopyRecord(ItemType data);

	void PutMusicNameOnScreen();	// 음악의 이름(곡명)을 화면에 출력한다.
	void PutArtistNameOnScreen();	// 음악의 아티스트이름을 화면에 출력한다.
	void PutDateOnScreen();			// 음악의 최근 재생 날짜를 화면에 출력한다.
	void PutPlayTimeOnScreen();		// 음악의 재생시간을 화면에 출력한다.
	void PutReleaseDateOnScreen();	// 음악의 발매일을 화면에 출력한다.
	void PutGenreOnScreen();		// 음악의 장르를 화면에 출력한다.
	void PutRecordOnScreen();		// 레코드를 화면에 출력한다.


	int GetMusicNameFromKB();		// 음악의 이름(곡명)을 키보드에서 가져온다.
	int GetArtistNameFromKB();		// 음악의 아티스트이름을 키보드에서 가져온다.
	int GetDateFromKB();			// 음악의 최근 재생 날짜를 키보드에서 가져온다.
	int GetPlayTimeFromKB();		// 음악의 재생시간을 키보드에서 가져온다.
	int GetReleaseDateFromKB();		// 음악의 발매일을 키보드에서 가져온다.
	int GetGenreFromKB();			// 음악의 장르를 키보드에서 가져온다.
	int GetRecordFromKB();			// 레코드의 내용을 키보드에서 가져온다.
	

	/*===================================================================================
	// Function	: read 1 record from file.
	// Pre		: a file is opened and a file pointer is located on the record read.
	// Post		: variables, id and name, get record information, file pointer is located to the back.
	=====================================================================================*/
	int GetRecordFromFile(ifstream& fin);		// 레코드를 파일에서 가져온다.

	/*===================================================================================
	// Function : 레코드를 파일에 쓴다.
	// Pre		: a file is opened and a file pointer is located on the position for record write.
	//			  variables, id and name, have record information for writing.
	// Post		: write to the file and the file pointer is located to the back.
	=====================================================================================*/
	int PutRecordToFile(ofstream& fout);			// 레코드를 파일에 저장한다.


	//===================================================================================
	// Fuction : Determines the ordering of two ItemType objects based on their primary key.
	// Function	: compare this primary key to data's primary key
	// Pre		: none
	// Pose		: this primary key < data's primary key then return -1
	//			  this primary key > data's primary key then return 1
	//			  else									return 0
	//===================================================================================
	int CompareTo(ItemType data);

	RelationType CompareByMusicName(ItemType data);	// 음악의 이름(곡명)으로 비교
	RelationType CompareByArtistName(ItemType data);// 음악의 아티스트이름으로 비교
	RelationType CompareByDate(ItemType data);		// 음악의 최근 재생 날짜로 비교
	RelationType CompareByGenre(ItemType data);		// 음악의 장르로 비교
	RelationType CompareByPlayTime(ItemType data);	// 음악의 재생시간으로 비교

};




#endif