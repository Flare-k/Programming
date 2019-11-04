#include "ItemType.h"
#include <time.h>



//===================================================================================
// Function: ItemType의 멤버변수들을 초기화해준다.
// Pre: none
// Post: none
//===================================================================================
ItemType::ItemType()		//	생성자
{
	this->m_ArtistName = "";
	this->m_Date = "";
	this->m_Genre = "";
	this->m_ReleaseDate = "";
	this->m_MusicName = "";
	this->m_PlayTime = "";

}


//===================================================================================
// Function: 소멸자
// Pre: none
// Post: none
//===================================================================================
ItemType::~ItemType()	// 소멸자
{
}


//===================================================================================
// Function: 넘겨받은 파라미터 값을 레코드에 넣어준다.
// Pre: 파라미터로 각각의 값을 전달받음
// Post: 레코드에 해당 값들이 입력된다.
//===================================================================================
void ItemType::PutRecord(string MusicName, string ArtistName, string Date, string PlayTime,
	string ReleaseDate, string Genre)	
{
	PutMusicName(MusicName);
	PutArtistName(ArtistName);
	PutGenre(Genre);	
	PutPlayTime(PlayTime);
	PutReleaseDate(ReleaseDate);
	PutDate(Date);
}

//===================================================================================
// Function: 
// Pre: none
// Post: 
//===================================================================================
void ItemType::CopyRecord(ItemType data)		// 레코드를 복사한다.
{
	PutRecord(data.GetMusicName(), data.GetArtistName(), data.GetDate(), data.GetPlayTime(),
		data.GetReleaseDate(), data.GetGenre());
}


//===================================================================================
// Function: 스크린에 각각의 데이터를 출력한다.
// Pre: 멤버변수를 전달받음
// Post: 콘솔화면에 각각의 값을 출력해준다.
//===================================================================================
void ItemType::PutMusicNameOnScreen()	// 음악의 이름(곡명)을 화면에 출력한다.
{
	cout << "\tMusic Name	: " << m_MusicName << endl;
}
void ItemType::PutArtistNameOnScreen()	// 음악의 아티스트이름을 화면에 출력한다.
{
	cout << "\tArtist Name	: " << m_ArtistName << endl;
}
void ItemType::PutDateOnScreen()			// 음악의 최근 재생 날짜를 화면에 출력한다.
{
	cout << "\tDate		: " << m_Date << endl;
}
void ItemType::PutPlayTimeOnScreen()		// 음악의 재생시간을 화면에 출력한다.
{
	cout << "\tPlay Time	: " << m_PlayTime << endl;
}
void ItemType::PutReleaseDateOnScreen()		// 음악의 가사를 화면에 출력한다.
{
	cout << "\tRelease Date	: " << m_ReleaseDate << endl;
}
void ItemType::PutGenreOnScreen()		// 음악의 장르를 화면에 출력한다.
{
	cout << "\tGenre		: " << m_Genre << endl;
}


//===================================================================================
// Function: 레코드를 스크린에 출력한다.
// Pre: none
// Post: 
//===================================================================================
void ItemType::PutRecordOnScreen()		// 레코드를 화면에 출력한다.
{
	this->PutMusicNameOnScreen();
	this->PutArtistNameOnScreen();
	this->PutGenreOnScreen();
	this->PutPlayTimeOnScreen();
	this->PutReleaseDateOnScreen();
	this->PutDateOnScreen();
	cout << "\t---------------------------" << endl;
}


//===================================================================================
// Function: 각각의 멤버변수를 키보드로부터 받아온다
// Pre: none
// Post: 
//===================================================================================
int ItemType::GetMusicNameFromKB()		// 음악의 이름(곡명)을 키보드에서 가져온다.
{
	cout << "\tMusic Name	: ";
	getline(cin, m_MusicName);


	return 1;
}
int ItemType::GetArtistNameFromKB()		// 음악의 아티스트이름을 키보드에서 가져온다.
{	
	cout << "\tArtist Name	: ";
	getline(cin, m_ArtistName);


	return 1;
}
int ItemType::GetReleaseDateFromKB()			// 음악의 발매일을 키보드에서 가져온다.
{
	cout << "\tRelease Date(ex:yyyy-mm-dd) : ";
	getline(cin, m_ReleaseDate);

	while (m_ReleaseDate.length() != 10)
	{
		cout << "\t다시 입력해주세요" << endl;
		cout << "\tRelease Date(ex:yyyy-mm-dd) : ";
		getline(cin, m_ReleaseDate);
	}

	return 1;
}
int ItemType::GetPlayTimeFromKB()		// 음악의 재생시간을 키보드에서 가져온다.
{
	cout << "\tPlay Time(ex : mm:ss)	: ";
	getline(cin, m_PlayTime);

	while (m_PlayTime.length() != 5)
	{
		cout << "\t다시 입력해주세요" << endl;
		cout << "\tPlay Time(ex : mm:ss)	: ";
		getline(cin, m_PlayTime);
	}

	return 1;
}

int ItemType::GetGenreFromKB()			// 음악의 장르를 키보드에서 가져온다.
{	
	
	cout << "\tGenre		: ";
	getline(cin, m_Genre);

	return 1;

}


//===================================================================================
// Function: 음악을 재생했을 때 날짜, 시간을 해당 멤버변수에 대입해준다.
// Pre: none
// Post: 
//===================================================================================
int ItemType::GetDateFromKB()			
{	
	//cout << "\tDate	: ";
	//getline(cin, m_Date);

	struct tm *timeInfo;
	time_t playTime;

	time(&playTime);
	timeInfo = localtime(&playTime);
	m_Date = ctime(&playTime);


	return 1;
}

//===================================================================================
// Function: 레코드의 내용을 키보드에서 가져온다
// Pre: none
// Post: 
//===================================================================================
int ItemType::GetRecordFromKB()		
{	
	this->GetMusicNameFromKB();
	this->GetArtistNameFromKB();
	this->GetGenreFromKB();
	this->GetPlayTimeFromKB();
	this->GetReleaseDateFromKB();
	//this->GetDateFromKB();

	return 1;
}




int ItemType::GetRecordFromFile(ifstream& fin)		// 레코드를 파일에서 가져온다.
{
	/*
	fin >> m_MusicName;
	fin >> m_ArtistName;
	fin >> m_Genre;
	fin >> m_PlayTime;
	fin >> m_ReleaseDate;
	fin >> m_Date;
	*/


	//fin.ignore();
	fin.clear();

	getline(fin, m_MusicName, '/');
	if(m_MusicName.find('\n') != std::string::npos)
	{
		m_MusicName.erase(0, 1);
	}
	getline(fin, m_ArtistName, '/');
	getline(fin, m_Genre, '/');
	getline(fin, m_PlayTime, '/');
	getline(fin, m_ReleaseDate, '/');
	getline(fin, m_Date, '/');


	return 1;

}

int ItemType::PutRecordToFile(ofstream& fout)			// 레코드를 파일에 저장한다.
{
	fout << endl << this->m_MusicName << "/";
	fout << this->m_ArtistName << "/";
	fout << this->m_Genre << "/";
	fout << this->m_PlayTime << "/";
	fout << this->m_ReleaseDate << "/";
	fout << this->m_Date << "/";

	return 1;
}



int ItemType::CompareTo(ItemType data)				// 음악의 여러 내용들을 비교한다.
{
	int menu = 0;

	switch(menu)
	{
	case 0:
		if(this->CompareByMusicName(data) == GREATER)
			return 1;
		if(this->CompareByMusicName(data) == LESS)
			return -1;
		else
			return 0;
		break;

	case 1:
		if(this->CompareByArtistName(data) == GREATER)
			return 1;
		if(this->CompareByArtistName(data) == LESS)
			return -1;
		else
			return 0;
		break;

	case 2:
		if(this->CompareByDate(data) == GREATER)
			return 1;
		if(this->CompareByDate(data) == LESS)
			return -1;
		else
			return 0;
		break;

	case 3:
		if(this->CompareByPlayTime(data) == GREATER)
			return 1;
		if(this->CompareByPlayTime(data) == LESS)
			return -1;
		else
			return 0;
		break;

	case 4:
		if(this->CompareByGenre(data) == GREATER)
			return 1;
		if(this->CompareByGenre(data) == LESS)
			return -1;
		else
			return 0;
		break;
	}

	return -2;
}


/////////멤버변수 기준 멤버변수가 더 크면 GREATER 멤버변수가 더 작으면 LESS
RelationType ItemType::CompareByMusicName(ItemType data)	// 음악의 이름(곡명)으로 비교
{
	if(this->m_MusicName > data.m_MusicName)
		return GREATER;
	else if(this->m_MusicName < data.m_MusicName)
		return LESS;
	else
		return EQUAL;
}
RelationType ItemType::CompareByArtistName(ItemType data)	// 음악의 아티스트이름으로 비교
{
	if(this->m_ArtistName > data.m_ArtistName)
		return GREATER;
	else if(this->m_ArtistName < data.m_ArtistName)
		return LESS;
	else
		return EQUAL;
}
RelationType ItemType::CompareByDate(ItemType data)		// 음악의 최근 재생 날짜로 비교
{
	if(this->m_Date > data.m_Date)
		return GREATER;
	else if(this->m_Date < data.m_Date)
		return LESS;
	else
		return EQUAL;
}


RelationType ItemType::CompareByGenre(ItemType data)		// 음악의 장르로 비교
{
	if(this->m_Genre > data.m_Genre)
		return GREATER;
	else if(this->m_Genre < data.m_Genre)
		return LESS;
	else
		return EQUAL;
}
RelationType ItemType::CompareByPlayTime(ItemType data)	// 음악의 재생시간으로 비교
{
	if(this->m_PlayTime > data.m_PlayTime)
		return GREATER;
	else if(this->m_PlayTime < data.m_PlayTime)
		return LESS;
	else
		return EQUAL;
}