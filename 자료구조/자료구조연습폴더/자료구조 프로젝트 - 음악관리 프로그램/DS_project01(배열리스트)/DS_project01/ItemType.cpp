#include "ItemType.h"
#include <time.h>



//===================================================================================
// Function: ItemType�� ����������� �ʱ�ȭ���ش�.
// Pre: none
// Post: none
//===================================================================================
ItemType::ItemType()		//	������
{
	this->m_ArtistName = "";
	this->m_Date = "";
	this->m_Genre = "";
	this->m_ReleaseDate = "";
	this->m_MusicName = "";
	this->m_PlayTime = "";

}


//===================================================================================
// Function: �Ҹ���
// Pre: none
// Post: none
//===================================================================================
ItemType::~ItemType()	// �Ҹ���
{
}


//===================================================================================
// Function: �Ѱܹ��� �Ķ���� ���� ���ڵ忡 �־��ش�.
// Pre: �Ķ���ͷ� ������ ���� ���޹���
// Post: ���ڵ忡 �ش� ������ �Էµȴ�.
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
void ItemType::CopyRecord(ItemType data)		// ���ڵ带 �����Ѵ�.
{
	PutRecord(data.GetMusicName(), data.GetArtistName(), data.GetDate(), data.GetPlayTime(),
		data.GetReleaseDate(), data.GetGenre());
}


//===================================================================================
// Function: ��ũ���� ������ �����͸� ����Ѵ�.
// Pre: ��������� ���޹���
// Post: �ܼ�ȭ�鿡 ������ ���� ������ش�.
//===================================================================================
void ItemType::PutMusicNameOnScreen()	// ������ �̸�(���)�� ȭ�鿡 ����Ѵ�.
{
	cout << "\tMusic Name	: " << m_MusicName << endl;
}
void ItemType::PutArtistNameOnScreen()	// ������ ��Ƽ��Ʈ�̸��� ȭ�鿡 ����Ѵ�.
{
	cout << "\tArtist Name	: " << m_ArtistName << endl;
}
void ItemType::PutDateOnScreen()			// ������ �ֱ� ��� ��¥�� ȭ�鿡 ����Ѵ�.
{
	cout << "\tDate		: " << m_Date << endl;
}
void ItemType::PutPlayTimeOnScreen()		// ������ ����ð��� ȭ�鿡 ����Ѵ�.
{
	cout << "\tPlay Time	: " << m_PlayTime << endl;
}
void ItemType::PutReleaseDateOnScreen()		// ������ ���縦 ȭ�鿡 ����Ѵ�.
{
	cout << "\tRelease Date	: " << m_ReleaseDate << endl;
}
void ItemType::PutGenreOnScreen()		// ������ �帣�� ȭ�鿡 ����Ѵ�.
{
	cout << "\tGenre		: " << m_Genre << endl;
}


//===================================================================================
// Function: ���ڵ带 ��ũ���� ����Ѵ�.
// Pre: none
// Post: 
//===================================================================================
void ItemType::PutRecordOnScreen()		// ���ڵ带 ȭ�鿡 ����Ѵ�.
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
// Function: ������ ��������� Ű����κ��� �޾ƿ´�
// Pre: none
// Post: 
//===================================================================================
int ItemType::GetMusicNameFromKB()		// ������ �̸�(���)�� Ű���忡�� �����´�.
{
	cout << "\tMusic Name	: ";
	getline(cin, m_MusicName);


	return 1;
}
int ItemType::GetArtistNameFromKB()		// ������ ��Ƽ��Ʈ�̸��� Ű���忡�� �����´�.
{	
	cout << "\tArtist Name	: ";
	getline(cin, m_ArtistName);


	return 1;
}
int ItemType::GetReleaseDateFromKB()			// ������ �߸����� Ű���忡�� �����´�.
{
	cout << "\tRelease Date(ex:yyyy-mm-dd) : ";
	getline(cin, m_ReleaseDate);

	while (m_ReleaseDate.length() != 10)
	{
		cout << "\t�ٽ� �Է����ּ���" << endl;
		cout << "\tRelease Date(ex:yyyy-mm-dd) : ";
		getline(cin, m_ReleaseDate);
	}

	return 1;
}
int ItemType::GetPlayTimeFromKB()		// ������ ����ð��� Ű���忡�� �����´�.
{
	cout << "\tPlay Time(ex : mm:ss)	: ";
	getline(cin, m_PlayTime);

	while (m_PlayTime.length() != 5)
	{
		cout << "\t�ٽ� �Է����ּ���" << endl;
		cout << "\tPlay Time(ex : mm:ss)	: ";
		getline(cin, m_PlayTime);
	}

	return 1;
}

int ItemType::GetGenreFromKB()			// ������ �帣�� Ű���忡�� �����´�.
{	
	
	cout << "\tGenre		: ";
	getline(cin, m_Genre);

	return 1;

}


//===================================================================================
// Function: ������ ������� �� ��¥, �ð��� �ش� ��������� �������ش�.
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
// Function: ���ڵ��� ������ Ű���忡�� �����´�
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




int ItemType::GetRecordFromFile(ifstream& fin)		// ���ڵ带 ���Ͽ��� �����´�.
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

int ItemType::PutRecordToFile(ofstream& fout)			// ���ڵ带 ���Ͽ� �����Ѵ�.
{
	fout << endl << this->m_MusicName << "/";
	fout << this->m_ArtistName << "/";
	fout << this->m_Genre << "/";
	fout << this->m_PlayTime << "/";
	fout << this->m_ReleaseDate << "/";
	fout << this->m_Date << "/";

	return 1;
}



int ItemType::CompareTo(ItemType data)				// ������ ���� ������� ���Ѵ�.
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


/////////������� ���� ��������� �� ũ�� GREATER ��������� �� ������ LESS
RelationType ItemType::CompareByMusicName(ItemType data)	// ������ �̸�(���)���� ��
{
	if(this->m_MusicName > data.m_MusicName)
		return GREATER;
	else if(this->m_MusicName < data.m_MusicName)
		return LESS;
	else
		return EQUAL;
}
RelationType ItemType::CompareByArtistName(ItemType data)	// ������ ��Ƽ��Ʈ�̸����� ��
{
	if(this->m_ArtistName > data.m_ArtistName)
		return GREATER;
	else if(this->m_ArtistName < data.m_ArtistName)
		return LESS;
	else
		return EQUAL;
}
RelationType ItemType::CompareByDate(ItemType data)		// ������ �ֱ� ��� ��¥�� ��
{
	if(this->m_Date > data.m_Date)
		return GREATER;
	else if(this->m_Date < data.m_Date)
		return LESS;
	else
		return EQUAL;
}


RelationType ItemType::CompareByGenre(ItemType data)		// ������ �帣�� ��
{
	if(this->m_Genre > data.m_Genre)
		return GREATER;
	else if(this->m_Genre < data.m_Genre)
		return LESS;
	else
		return EQUAL;
}
RelationType ItemType::CompareByPlayTime(ItemType data)	// ������ ����ð����� ��
{
	if(this->m_PlayTime > data.m_PlayTime)
		return GREATER;
	else if(this->m_PlayTime < data.m_PlayTime)
		return LESS;
	else
		return EQUAL;
}