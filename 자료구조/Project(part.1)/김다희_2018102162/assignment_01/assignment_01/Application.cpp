#include "Application.h"

int Application::HomeCommand() {
	int command = 1;
	cout << endl << endl;
	cout << "\t============ 음원마법사 ============" << endl;
	cout << "\t	1. 로그인" << endl;
	cout << "\t	2. 회원가입" << endl;
	cout << "\t====================================" << endl;
	int x = 9, y = 4;
	int key = 0;
	while (key != ENTER)
	{
		gotoxy(x, y);
		cout << "->";
		key = _getch();
		switch (key)
		{
		case UP:
			if (command != 1)
			{
				gotoxy(x, y);
				cout << "  ";
				command--;
				y--;
			}
			break;
		case DOWN:
			if (command != 11)
			{
				gotoxy(x, y);
				cout << "  ";
				command++;
				y++;
			}
			break;
		}
	}

	return command;
}

void Application::HomeRun() {
	int command = HomeCommand();
	CLS;
	cout << endl << endl;
	switch (command) {
	case 1:
		Login();
		break;
	case 2:
		SignUp();
		break;
	default:
		break;
	}
}

void Application::Login() 
{
	string id;
	string password;
	cout << "\t============ 로그인 ===============" << endl;
	cout << "\t ID :";
	cin >> id;
	id += ".txt";
	cout << "\t PASSWORD :";
	cin >> password;
	m_InFile.open(id);
	if (m_InFile.is_open()) {
		string pw;
		m_InFile >> pw;
		if (password == pw) {
			if (id == "admin.txt") 
			{
				ReadDataFromFileMaster(id);
				cout << "\n\t";
				A_id = id;
				A_pw = password;
				PAUSE;
				CLS;
				Run();
			}
			else
			{
				A_id = id;
				A_pw = password;
				ReadDataFromFilePL(id);
				m_InFile.open("admin.txt");
				string temp;
				m_InFile >> temp;
				ReadDataFromFileMaster("admin.txt");
				cout << "\n\t";
				PAUSE;
				CLS;
				GeneralUserRun();

			}
		}
		else {
			cout << "\t* 비밀번호가 일치하지 않습니다." << endl;
		}
	}
	else {
		cout << "\t* 해당하는 id가 존재하지 않습니다." << endl;
		cout << "\t";
		PAUSE;
		CLS;
		HomeRun();
	}
}

void Application::SignUp()
{
	string id;
	string password;
	cout << "\t============ 회원가입 ==============" << endl;
	cout << "\t ID :";
	cin >> id;
	cout << "\t PASSWORD :";
	cin >> password;
	id += ".txt";
	ifstream f;
	f.open(id);
	if (f.is_open() == true) {
		cout << "\t* 이미 존재하는 id입니다." << endl;
		PAUSE;
		CLS;
		HomeRun();
		f.close();
		return;
	}
	ofstream file;
	file.open(id);
	file << password << endl;
	file.close();
	cout << endl << "\t";
	PAUSE;
	CLS;
	GeneralUserRun();
}

void Application::GeneralUserRun()
{
	while (1)
	{
		m_Command = GeneralUserCommand();
		CLS;
		cout << endl << endl;
		switch (m_Command)
		{
		case 1:
			UserSearchTypeRun();//		SearchTypeRun();
			cout << "\n\t";
			PAUSE;
			CLS;
			break;
		case 2:		// 리스트에 저장된 모든 곡을 화면에 출력
			DisplayAllMusic();
			cout << "\n\t";
			PAUSE;
			CLS;
			break;
		case 3:		// load list data from a file.
			PlaylistRun();
			break;
		case 4:		// save list data into a file.
			SearchByArtistWithSL();
			cout << "\n\t";
			PAUSE;
			CLS;
			break;
		case 5:
			WriteUserDataToFile();
			return;
			break;
		default:
			cout << "\t* Illegal selection...\n";
			break;
		}

	}


}

int Application::GeneralUserCommand()
{
	CLS;
	cout << endl << endl;
	int command = 1;
	cout << "\t**********음원마법사**********" << endl;
	cout << "\t==============================" << endl;
	cout << "\t===ID == Command =============" << endl;
	cout << "\t   1 : 음악 검색하기" << endl;
	cout << "\t   2 : 모든 음악 출력하기" << endl;
	cout << "\t   3 : 플레이 리스트로 가기" << endl;
	cout << "\t   4 : 가수별 노래 찾기" << endl;
	cout << "\t   0 : Quit" << endl;
	cout << "\t==============================" << endl;
	int x = 9, y = 6;
	int key = 0;
	while (key != ENTER)
	{
		gotoxy(x, y);
		cout << "->";
		key = _getch();
		switch (key)
		{
		case UP:
			if (command != 1)
			{
				gotoxy(x, y);
				cout << "  ";
				command--;
				y--;
			}
			break;
		case DOWN:
			if (command != 5)
			{
				gotoxy(x, y);
				cout << "  ";
				command++;
				y++;
			}
			break;
		}
	}

	return command;
}

void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();
		CLS;
		cout << endl << endl;
		switch (m_Command)
		{
		case 1:
			AddMusic(); // 곡 정보를 입력 받아 리스트에 추가					AddMusic();
			break;
		case 2:
			DeleteMusic(); // 곡의 고유번호를 입력 받아 리스트에서 삭제					DeleteMusic();
			break;
		case 3:
			ReplaceMusic();// 곡 정보를 입력 받아서 리스트에서 해당 곡 정보를 갱신			ReplaceMusic();
			break;
		case 4:		
			SearchTypeRun();//		SearchTypeRun();
			break;
		case 5:		// 리스트에 저장된 모든 곡을 화면에 출력
			DisplayAllMusic();
			break;
		case 6: 		// 리스트에 입력된 모든 곡을 삭제
			MakeEmpty();
			break;
		case 7:		// save list data into a file.
			SearchByArtistWithSL();
			break;
		case 8:
			WriteDataToFile();
			return;
			break;
		default:
			cout << "\t* Illegal selection...\n";
			break;
		}

		cout << "\n\t";
		PAUSE;
		CLS;
	}


}

int Application::GetCommand()
{
	CLS;
	cout << endl << endl;
	int command = 1;
	cout << "\t*******음원마법사관리자*******" << endl;
	cout << "\t==============================" << endl;
	cout << "\t===ID == Command =============" << endl;
	cout << "\t   1 : Add music" << endl;
	cout << "\t   2 : Delete music" << endl;
	cout << "\t   3 : Replace music" << endl;
	cout << "\t   4 : Search music" << endl;
	cout << "\t   5 : Print all on screen" << endl;
	cout << "\t   6 : Delete all music" << endl;
	cout << "\t   7 : 가수별 노래 찾기" << endl;
	cout << "\t   8 : Quit" << endl;
	cout << "\t==============================" << endl;
	int x = 9, y = 6;
	int key = 0;
	while (key != ENTER)
	{
		gotoxy(x, y);
		cout << "->";
		key = _getch();
		switch (key)
		{
		case UP:
			if (command != 1)
			{
				gotoxy(x, y);
				cout << "  ";
				command--;
				y--;
			}
			break;
		case DOWN:
			if (command != 8)
			{
				gotoxy(x, y);
				cout << "  ";
				command++;
				y++;
			}
			break;
		}
	}

	return command;
}

int Application::RetrieveMusic() {
	ItemType item;
	item.SetIdFromKB();

	int find = m_List.Retrieve_Binary(item);
	if(find == 1) item.DisplayRecordOnScreen();
	else cout << "\t* 해당하는 id를 가진 음악이 존재하지 않습니다." << endl;
	return 0;
}

int Application::DeleteMusic()
{
	ItemType item;
	item.SetIdFromKB();
	m_List.Delete(item);
	return 0;
}

int Application::ReplaceMusic() {
	ItemType item;
	item.SetRecordFromKB();
	m_List.Replace(item);
	
	return 0;
}

int Application::MakeEmpty() {
	m_List.MakeEmpty();
	return 0;
}

//-------실습과제2---------//


int Application::SearchById_BinaryS() {
	ItemType item;
	item.SetIdFromKB();
	int isExist = m_List.Retrieve_Binary(item);
	if (isExist == 1) {
		item.DisplayRecordOnScreen();
		return 1;
	}
	cout << "\t* 해당하는 ID와 일치하는 데이터가 존재하지 않습니다." << endl;
	return 0;
}

int Application::SearchIdAddBinaryS(string input, ItemType &data) {
	ItemType item;
	item.SetId(input);
	int isExist = m_List.Retrieve_Binary(item);
	if (isExist == 1) {
		return 1;
	}
	return 0;
}

//가수 이름으로 검색. "김"을 입력하면 "김"이 포함된 것 다 출력.
int Application::SearchByArtist() {
	string input;
	cout << "\t* 검색어를 입력해주세요 : ";
	cin >> input;
	int have = 0;

	m_List.ResetList();
	for (int curPointer = 0; curPointer < m_List.GetLength(); curPointer++) {
		std::size_t pos;
		ItemType data;
		m_List.GetNextItem(data);
		if (pos = data.GetArtist().find(input, 0) != string::npos) {
			data.DisplayRecordOnScreen();
			have = 1;
		}
	}
	return have;
}

//장르로 검색
int Application::SearchByGenre() {
	int input;
	cout << "\t* 검색어를 입력해주세요 : ";
	cin >> input;
	int have = 0;
	m_List.ResetList();
	for (int curPointer = 0; curPointer < m_List.GetLength(); curPointer++) {
		ItemType data;
		m_List.GetNextItem(data);
		if (data.GetGenre() == input) {
			data.DisplayRecordOnScreen();
			have = 1;
		}
	}
	return have;
}

//--------------검색 기능 실행 start-----------------------//
int Application::SelectSearchType() {
	int command = 1;
	cout << "\t=== 검색창으로 이동합니다. ===" << endl << endl;
	cout << "\t==============================" << endl;
	cout << "\t===ID == Command =============" << endl;
	cout << "\t   1 : Search by Id" << endl;
	cout << "\t   2 : Search by Artist" << endl;
	cout << "\t   3 : Search by Genre" << endl;
	cout << "\t   4 : back" << endl;
	cout << "\t==============================" << endl;

	int x = 9, y =7;
	int key = 0;
	while (key != ENTER)
	{
		gotoxy(x, y);
		cout << "->";
		key = _getch();
		switch (key)
		{
		case UP:
			if (command != 1)
			{
				gotoxy(x, y);
				cout << "  ";
				command--;
				y--;
			}
			break;
		case DOWN:
			if (command != 4)
			{
				gotoxy(x, y);
				cout << "  ";
				command++;
				y++;
			}
			break;
		}
	}

	return command;

}

void Application::UserSearchTypeRun() {

	int m_Command;

		m_Command = SelectSearchType();
		CLS;
		cout << endl << endl;
		switch (m_Command)
		{
		case 1:
			RetrieveMusic();

			break;
		case 2:
			SearchByArtist();
			break;
		case 3:
			SearchByGenre();
			
			break;
		default:
			break;
		}

}

void Application::SearchTypeRun() {

	int m_Command;

	m_Command = SelectSearchType();
	CLS;
	cout << endl << endl;
	switch (m_Command)
	{
	case 1:
		RetrieveMusic();
		break;
	case 2:
		SearchByArtist();
		break;
	case 3:
		SearchByGenre();
		break;
	case 4:
		break;
	default:
		cout << "\tIllegal selection...\n";
		break;
	}

	Run();
}
//--------------검색 기능 실행 end-----------------------//


//--------------플레이리스트 start-----------------------//
int Application::SelectPlaylistType() {
	int command = 1;
	cout << "\t= 플레이리스트로 이동합니다. =" << endl << endl;
	cout << "\t==============================" << endl;
	cout << "\t===ID == Command =============" << endl;
	cout << "\t   1 : 플레이리스트 음악 추가" << endl;
	cout << "\t   2 : 추가한 순으로 재생" << endl;
	cout << "\t   3 : 자주 재생한 순으로 재생" << endl;
	cout << "\t   4 : 플레이리스트 음악 삭제" << endl;
	cout << "\t   5 : back" << endl;
	cout << "\t==============================" << endl;
	int x = 9, y = 7;
	int key = 0;
	while (key != ENTER)
	{
		gotoxy(x, y);
		cout << "->";
		key = _getch();
		switch (key)
		{
		case UP:
			if (command != 1)
			{
				gotoxy(x, y);
				cout << "  ";
				command--;
				y--;
			}
			break;
		case DOWN:
			if (command != 5)
			{
				gotoxy(x, y);
				cout << "  ";
				command++;
				y++;
			}
			break;
		}
	}

	return command;
}

void Application::PlaylistRun() {

	int m_Command;
	
	m_Command = SelectPlaylistType();
	CLS;
	cout << endl << endl;
	switch (m_Command)
	{
	case 1:
		AddToPlayList(); // 곡 정보를 입력 받아 리스트에 추가					
		break;
	case 2:
		PlayIOAddTime();
		break;
	case 3:
		PlayIOFreq();
		break;
	case 4:
		DeleteFrPlayList();
		break;
	case 5:
		break;
	default:
		cout << "\t* Illegal selection...\n";
		break;
	}
}

int Application::AddToPlayList() {
	string input;
	ItemType data;
	cout << "\t* Play List에 추가할 음악의 id를 입력해 주세요 :";
	cin >> input;
	if (SearchIdAddBinaryS(input, data) == 0) {
		cout << "\t* 해당하는 id를 가진 음악이 존재하지 않습니다." << endl;
		return 0;

	}
	PlayItem insertData;
	data.SetId(input);
	insertData.setId(data.GetId());
	m_PlayList.AddPlayList(insertData);
	return 1;
}


void Application::PlayIOAddTime() {

	int input = 1;
	
	do {
		m_PlayList.PrintAll();
		cout << "\t* 재생을 계속하시겠습니까? 종료 : 0, 계속 : 1" << endl << "\t* 입력 :";
		cin >> input;
	} while (input);
}

void Application::PlayIOFreq() {
	int input = 1;
	do {
		m_PlayList.PrintByFreq();
		cout << "\t* 재생을 계속하시겠습니까? 종료 : 0, 계속 : 1" << endl << "\t* 입력 :";
		cin >> input;
	} while (input);
}

void Application::DeleteFrPlayList() {
	string inputId;
	cout << "\t* Play List에서 삭제할 음악의 id를 입력해주세요 :";
	cin >> inputId;
	PlayItem deleteItem;
	deleteItem.setId(inputId);
	int result = m_PlayList.DeleteItem(deleteItem);
	if (result == 0) {
		cout << "\t* 해당하는 id를 가진 음악이 존재하지 않습니다." << endl;
	}
	else {
		cout << "\t* 삭제 성공!" << endl;
		return;
	}
}
//-------------플레이리스트 end-----------------------//

//-----------Artist List 관련 함수 start --------------//

//item은 가수 이름만 입력되어있는 artisttype객체.

// 새로운 가수 추가

//item은 일단 가수 이름만 입력되어있는 artisttype 객체,
void Application::AddSong(ItemType item) {
	artistList.AddSong(item);
}
// 추가할 곡의 가수를 검색하고 가수가 존재하면 해당 가수의 songlist에 곡을 추가한다. 
// 존재하지 않으면 가수를 추가하고 입력된 곡을 추가한다.

//AddSong은 application의 add()함수가 동작할 때 같이 동작해야한다. 
//즉 master list에 item이 추가될 때 AddSong도 동작해서 가수 검색하고 해당 가수의 song list에 곡 추가.. 
//없으면 가수 추가하고 노래 추가.

int Application::SearchByArtistWithSL() {
	ArtistType copy;
	string inArtistName;
	cout << "\t* 검색하실 아티스트의 이름을 입력해주세요 :";
	cin >> inArtistName;
	copy.setArtistName(inArtistName);
	int isFind = artistList.Get(copy);
	if (isFind == 1) {
		copy.DisplayRecordOnScreen();
		return 1;
	}
	else {
		cout << "\t* 해당하는 아티스트가 존재하지 않습니다." << endl;
		return 0;
	}
}
//Artist List 

//-----------Artist List 관련 함수 end ----------------//