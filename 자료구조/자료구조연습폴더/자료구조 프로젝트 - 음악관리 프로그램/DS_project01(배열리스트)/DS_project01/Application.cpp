#include "Application.h"


Application::Application()
{
	m_CurCommand = 0;
	ReadMusicListFromFile();
}

Application::~Application()
{
	WriteMusicListToFile();
}


//===================================================================================
// Function: Program driver
// Pre: none
// Post : none
//===================================================================================
void Application::Run()
{
	while(1)
	{
		m_CurCommand = GetCommand(); //메뉴로부터 명령을 받아옴

		switch(m_CurCommand)
		{
		case 1:		
			AddMusic();			//음악리스트에 음악 추가
			break;	
		case 2:		
			DeleteMusic();		//음악리스트에서 음악 삭제
			break;
		case 3:		
			ModifyMusic();		//음악리스트의 음악 수정
			break;
		case 4:		
			DisplayAllMusic();	//음악리스트 모두 출력
			break;
		case 5:		
			AddPlayList();		//재생목록에 추가
			break;
		case 6:		
			ShowPlayList();		//재생목록 출력
			break;
		case 7:		
			RetrieveRecordByMusicName();	//음악이름으로 검색
			break;
		case 8:		
			RetrieveRecordByArtistName();	//아티스트 이름으로 검색
			break;
		case 9:		
			RetrieveRecordByGenre();		//장르로 검색
			break;
		case 10:
			RetrieveRecordByReleaseDate();	//발매기간으로 검색
			break;
		case 11:
			PlayMusic();		//재생목록에 있는 음악을 플레이
 			break;
		case 0:					//프로그램 종료
			return;
		default:
			cout << "\t메뉴를 잘못 입력하셨습니다!!!\n";
			break;
		}
	}
}

//===================================================================================
// Function: Display command on screen and get a input from keyboard
// Pre: none
// Post : return command number.
//===================================================================================
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : 음악 추가 " << endl;
	cout << "\t   2 : 음악 삭제 " << endl;
	cout << "\t   3 : 음악 수정 " << endl;
	cout << "\t   4 : 음악 리스트 전체 보기 " << endl;
	cout << "\t   5 : 재생목록에 추가 " << endl;
	cout << "\t   6 : 재생목록 보기 " << endl;
	cout << "\t   7 : 음악 이름으로 검색 " << endl;
	cout << "\t   8 : 아티스트 이름으로 검색 " << endl;
	cout << "\t   9 : 장르로 검색 " << endl;
	cout << "\t   10: 발매 기간으로 검색 " << endl;
	cout << "\t   11: Music Play " << endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

//===================================================================================
// Function: Add new Music record to list
// Pre: 
// Post : list is added new Music record. if list is full, do not add the record to list and return 0, Otherwise return 1
//===================================================================================
int Application::AddMusic()
{
	ItemType newData;
		
	cin.ignore();
	cin.clear();

	newData.GetRecordFromKB(); //각 레코드를 키보드로 입력받음

	// 입력받은 레코드를 리스트에 add, 리스트가 full일 경우는 add하지 않고 0을 리턴
	if(!m_MusicList.IsFull())	
		m_MusicList.Add(newData);
	else	
		return 0;

	// 현재 list 출력
	//DisplayAllMusics();

	return 1;
}

//===================================================================================
// Function: Delete a Music record in list
// Pre: 
// Post : list is deleted a Music record.
//===================================================================================
int Application::DeleteMusic()
{
	ItemType target;
	
	cin.ignore();
	cin.clear();
	
	target.GetMusicNameFromKB();	// 삭제할 대상을 찾기 위한 음악이름 입력
	m_MusicList.Delete(target);	//해당 Music 레코드 삭제
	cout << "\t해당 음악을 삭제했습니다." << endl;

	return 1;
}

//===================================================================================
// Function: Modify a Music record in list
// Pre: 
// Post : list is modified a Music record.
//===================================================================================
int Application::ModifyMusic()
{
	ItemType target;

	cin.ignore();
	cin.clear();

	target.GetRecordFromKB();	// 수정할 대상을 검색하고 수정하기 위한 레코드 입력
	m_MusicList.Replace(target);	// Music 레코드 수정

	return 1;
}

//===================================================================================
// Function: Search a Music by music name
// Pre: inData contains the music name to be searched
// Post : inData holds the record matched with input music name. If found, return 1. Otherwise 0
//===================================================================================
int Application::SearchListByMusicName(ItemType& inData)
{
	ItemType data; // 비교를 위해 list pointer의 값을 저장하는 변수
	int sw = 0;

	// list 포인터를 초기화
	m_MusicList.ResetList();

	while(m_MusicList.GetNextItem(data) < m_MusicList.GetLength())
	{
		// 이름이 같은 레코드가 존재하면 그 레코드를 복사하고 1을 리턴
		if(data.GetMusicName().find(inData.GetMusicName()) != -1)
		{
			data.PutRecordOnScreen();
			sw = 1;
		}
	}

	return sw;
}

//===================================================================================
// Function: Search a Music by artist name
// Pre: inData contains the artist name to be searched
// Post : inData holds the record matched with input artist name. If found, return 1. Otherwise 0
//===================================================================================
int Application::SearchListByArtistName(ItemType& inData)
{
	ItemType data; // 비교를 위해 list pointer의 값을 저장하는 변수
	int sw = 0;

	// list 포인터를 초기화
	m_MusicList.ResetList();

	while(m_MusicList.GetNextItem(data) < m_MusicList.GetLength())
	{
		// 이름이 같은 레코드가 존재하면 그 레코드를 복사하고 1을 리턴
		if(data.GetArtistName().find(inData.GetArtistName()) != -1)
		{
			data.PutRecordOnScreen();
			sw = 1;
		}
	}

	return sw;
}


//===================================================================================
// Function: Search a Music by genre
// Pre: inData contains the genre to be searched
// Post : inData holds the record matched with input genre. If found, return 1. Otherwise 0
//===================================================================================
int Application::SearchListByGenre(ItemType& inData)
{
	ItemType data; // 비교를 위해 list pointer의 값을 저장하는 변수
	int sw = 0;

	// list 포인터를 초기화
	m_MusicList.ResetList();

	while(m_MusicList.GetNextItem(data) < m_MusicList.GetLength())
	{
		// 이름이 같은 레코드가 존재하면 그 레코드를 복사하고 1을 리턴
		if(data.GetGenre().find(inData.GetGenre()) != -1)
		{
			data.PutRecordOnScreen();
			sw = 1;
		}
	}

	return sw;
}


//===================================================================================
// Function: Search a Music by release date
// Pre: inData contains the release date to be searched
// Post : inData holds the record matched with input release date. If found, return 1. Otherwise 0
//===================================================================================
int Application::SearchListByReleaseDate(ItemType& inData1, ItemType& inData2, ItemType& returnData)
{
	ItemType data; // 비교를 위해 리스트 포인터의 값을 저장하는 변수

	while(m_MusicList.GetNextItem(data) < m_MusicList.GetLength())
	{
		if ((inData1.GetReleaseDate() <= data.GetReleaseDate()) && (data.GetReleaseDate() <= inData2.GetReleaseDate()))
		{
			returnData.CopyRecord(data);
			return 1;
		}
	}

	return 0;
}


//===================================================================================
// Function: Read in a music name from keyboard, search the record by music name, 
//			and display on the screen
// Pre: none
// Post : record on screen. If found, return 1. Otherwise 0
//===================================================================================
int Application::RetrieveRecordByMusicName()
{
	ItemType target; // 찾고자 하는 레코드를 담을 변수선언
		
	cin.ignore();
	cin.clear();

	target.GetMusicNameFromKB(); // 키보드로부터 찾고자 하는 레코드 입력받음
	cout << "\t--------------------" << endl;
	
	// 찾고자 하는 레코드가 리스트에 있으면 화면에 출력하고 1
	if(SearchListByMusicName(target))
	{
		return 1;
	}
	else
	{
		cout << "\tDo not find" << endl;
		return 0;
	}

	return 0;
}

//===================================================================================
// Function: Read in artist name from keyboard, search the record by artist name, and display on the screen
// Pre: none
// Post : record on screen. If found, return 1. Otherwise 0
//===================================================================================
int Application::RetrieveRecordByArtistName()
{
	ItemType target; // 찾고자 하는 레코드를 담을 변수선언
		
	cin.ignore();
	cin.clear();
	
	target.GetArtistNameFromKB(); // 키보드로부터 찾고자 하는 레코드 입력받음
	cout << "\t--------------------" << endl;

	// 찾고자 하는 레코드가 리스트에 있으면 화면에 출력하고 1
	if(SearchListByArtistName(target))
	{
		return 1;
	}
	else
	{
		cout << "\tDo not find" << endl;
		return 0;
	}

	return 0;
}

//===================================================================================
// Function: Read in genre from keyboard, search the record by genre, and display on the screen
// Pre: none
// Post : record on screen. If found, return 1. Otherwise 0
//===================================================================================
int Application::RetrieveRecordByGenre()
{
	ItemType target; // 찾고자 하는 레코드를 담을 변수선언
		
	cin.ignore();
	cin.clear();
	
	target.GetGenreFromKB(); // 키보드로부터 찾고자 하는 레코드 입력받음
	cout << "\t--------------------" << endl;

	// 찾고자 하는 레코드가 리스트에 있으면 화면에 출력하고 1
	if(SearchListByGenre(target))
	{
		return 1;
	}
	else
	{
		cout << "\tDo not find" << endl;
		return 0;
	}

	return 0;
}


//===================================================================================
// Function: Read in release date from keyboard, search the record by release date, 
//			and display on the screen
// Pre: none
// Post : record on screen. If found, return 1. Otherwise 0
//===================================================================================
int Application::RetrieveRecordByReleaseDate()
{
	ItemType target1, target2, returnData; //시작날짜, 끝날짜, 비교날짜



	cout << "\t음반 발매 기간으로 검색하는 기능입니다." << endl;
	cout << "\t검색할 시작 날짜를 입력해주세요" << endl;
	
	cin.ignore();
	cin.clear();

	target1.GetReleaseDateFromKB();
	cout << "\t검색할 끝 날짜를 입력해주세요" << endl;
	target2.GetReleaseDateFromKB();
	cout << "\t----------------------------------------" << endl;

	int sw = 0;
	this->m_MusicList.ResetList();

	while(SearchListByReleaseDate(target1,target2, returnData))
	{
		returnData.PutRecordOnScreen();
		sw=1;
	}
	if(sw==0)
	{
		cout << "\tNo data in the list.." << endl;
		return 0;
	}
	return 1;

}


//===================================================================================
// Function: Display all record in the Music list on screen
// Pre: 
// Post : Music records on screen
//===================================================================================
void Application::DisplayAllMusic()
{
	ItemType data;

	m_MusicList.ResetList();

	cout << "\n\tCurrent list" << endl;
	// list의 모든 데이터를 화면에 출력
	int length = m_MusicList.GetLength();
	int curIndex = m_MusicList.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.PutRecordOnScreen();
		curIndex = m_MusicList.GetNextItem(data);
	}
}

//===================================================================================
// Function: Open an input file
// Pre: name should be valid
// Post: m_InFile holds input file information. 
//       if file open error occur, return 0. Otherwise return 1
//===================================================================================
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName, ios::app);	// file open for read

	// if file open error occur, return 0. Otherwise return 1
	if(!m_InFile)
		return 0;
	else
		return 1;
}

//===================================================================================
// Function: Open an output file
// Pre: name should be valid
// Post: m_OutFile holds output file information. 
//       if file open error occur, return 0. Otherwise return 1
//===================================================================================
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName, ios::trunc);	// file open for write

	// if file open error occur, return 0. Otherwise return 1
	if(!m_OutFile)
		return 0;
	else
		return 1;
}

//===================================================================================
// Function: Open an input file and read all the Music record from a file
// Pre: file is not opened
// Post: studeList holds all Music records read from a file. The m_InFile is closed
//       if file open error or file read error occur, return 0. Otherwise return 1
//===================================================================================
int Application::ReadMusicListFromFile()
{
	int index = 0;
	ItemType data;	// 읽기용 임시 변수

	/*
	//파일을 수동으로 열때
	char filename[80];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;
	*/

	// file open, open error가 발생하면 0을 리턴
	if(!OpenInFile("MusicList.txt"))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while(!m_InFile.eof())
	{
		//array에 학생들의 정보가 들어있는 structure 저장
		data.GetRecordFromFile(m_InFile);
		m_MusicList.Add(data);
		m_InFile.ignore();
	}

	m_InFile.close();	// file close


	return 1;
}

//===================================================================================
// Function: Open an output file and write all Music records to the file
// Pre: None
// Post: the Music list is stored in the output file
//       if file open error or file write error occur, return 0. Otherwise return 1
//===================================================================================
int Application::WriteMusicListToFile()
{
	ItemType data;	// 쓰기용 임시 변수

	/*
	//파일을 수동으로 열때
	char filename[80];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;
	*/

	// file open, open error가 발생하면 0을 리턴
	if(!OpenOutFile("MusicList.txt"))
		return 0;

	// list 포인터를 초기화
	m_MusicList.ResetList();

	// list의 모든 데이터를 파일에 쓰기
	int length = m_MusicList.GetLength();
	int curIndex = m_MusicList.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.PutRecordToFile(m_OutFile);
		curIndex = m_MusicList.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}


//===================================================================================
// Function: Play music and display the play list
// Pre: m_PlayList contains music list
// Post: play the music and add the playing date to record
//===================================================================================
void Application::PlayMusic()
{
	ItemType inData;

	do
	{
		system("cls");
		cout << endl << "\t======음악 재생=======" << endl << endl;
		cout << "\t현재 재생중인 음악===>>";
		this->m_PlayList.Print();
		cout << "\t=============================" << endl;
		m_PlayList.DeQueue(inData);
		inData.GetDateFromKB();

		this->m_MusicList.Replace(inData);
		
		cout << "다음 음악을 재생하려면 아무키나 누르십시오!" << endl;
		system("pause>null"); //"계속하려면 아무키나 누르시오" 메세지 삭제 

	}while(!m_PlayList.IsEmpty());
}


//===================================================================================
// Function: add music to play list(queue)
// Pre: none
// Post: enqueue the music to play list queue
//===================================================================================
void Application::AddPlayList()
{
	ItemType target;
	
	cin.ignore();
	cin.clear();
	
	cout << "\t재생목록에 추가할 음악의 이름을 입력해주세요." << endl;
	target.GetMusicNameFromKB();	// 재생목록에 추가할 음악을 입력받음
	
	cout << "-----------------------------------------------" << endl;
	
	ItemType data; //임시변수 생성

	if(m_MusicList.Get(target)) //대상을 찾음
	{
		this->m_PlayList.EnQueue(target); //찾은 대상을 재생목록에 enqueue
		cout << "\t해당 음악을 재생목록에 추가하였습니다." << endl;
	}
	else
	{
		cout << "\tNot found record in the list.." << endl;
	
	}
}


//===================================================================================
// Function: Display the play list
// Pre: none
// Post: 
//===================================================================================
void Application::ShowPlayList()
{
	if(!m_PlayList.IsEmpty())
	{
		this->m_PlayList.Print();
	}
	else
	{
		cout << "\t재생목록이 비어있습니다. 원하는 음악을 재생목록에 추가시켜주세요" << endl;
		cout << "\t-----------------------------------------------------------------" << endl << endl;
	}
	
}