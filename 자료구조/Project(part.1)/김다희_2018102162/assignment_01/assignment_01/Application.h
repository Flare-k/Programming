#pragma once
#include "Base.h"
#include"SortedList.h"
#include"PlayList.h"
#include"ArtistList.h"
#include<iostream>
#include <fstream>
#include<string>


#define FILENAMESIZE 1024

using namespace std;


/**
*	application class for item management simply.
*/
class Application : public Base
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_Command = 0;
	}
	/**
	*	destructor.
	*/
	~Application() {}
	int HomeCommand();
	void HomeRun();
	void Login();
	void SignUp();
	
	void GeneralUserRun();
	int GeneralUserCommand();

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();
	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddMusic() {
		if (m_List.IsFull()) {
			cout << "\t* 리스트가 가득 찼습니다. 더 이상 추가할 수 없습니다." << endl;
			return 0;
		}

		cout << "\t===== 아이템을 추가합니다. =====" << endl;
		ItemType item;

		item.SetRecordFromKB();
		cout << "\t================================" << endl;
		int find = m_List.Add(item);

		if (find != 0) {
			AddSong(item);
//			m_OutFile.open("admin.txt", ios::app);
//			m_OutFile << endl <<item.GetId() << " " << item.GetType() << " " << item.GetTitle() << " "
//				<< item.GetComposer() << " " << item.GetArtist() << " " << item.GetGenre();
			
		}
		DisplayAllMusic();

		
		return 1;
	}
	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllMusic() {
		ItemType data;

		cout << "\n\t<<======= Current list =======>>" << endl;

		// list의 모든 데이터를 화면에 출력
		m_List.ResetList(); //list의 m_curpointer를 0으로 초기화.
		int length = m_List.GetLength(); // length라는 변수에 list의 길이를 저장.
		int curIndex = m_List.GetNextItem(data); // curIndex라는 display한 curlpointer index를 저장. 
		while (curIndex < length && curIndex != -1)
		{
			data.DisplayRecordOnScreen();
			curIndex = m_List.GetNextItem(data);
		}
		cout << "\t<<============================>>" << endl;
	}
	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char *fileName) {
		m_InFile.open(fileName);	// file open for reading.

									// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
		if (!m_InFile)	return 0;
		else	return 1;
	}
	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char *fileName) {
		m_OutFile.open(fileName);	// file open for writing.

									// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
		if (!m_OutFile)	return 0;
		else	return 1;
	}
	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFilePL(string filename) {
		int index = 0;
		ItemType data;	// 읽기용 임시 변수

		// 파일의 모든 내용을 읽어 list에 추가
		while (!m_InFile.eof())
		{
			// array에 학생들의 정보가 들어있는 structure 저장
			data.ReadDataFromFile(m_InFile);
			PlayItem insertData;
			insertData.setId(data.GetId());
			m_PlayList.AddPlayList(insertData);
		}

		m_InFile.close();	// file close

					

		return 1;
	}
	int ReadDataFromFileMaster(string filename) {
		int index = 0;
		ItemType data;	// 읽기용 임시 변수

						// 파일의 모든 내용을 읽어 list에 추가
		while (!m_InFile.eof())
		{
			// array에 학생들의 정보가 들어있는 structure 저장
			data.ReadDataFromFile(m_InFile);
			m_List.Add(data);
		}

		m_InFile.close();	// file close

			

		return 1;
	}

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile() {
		ItemType data;	// 쓰기용 임시 변수
		string filename = A_id;
		m_OutFile.open(filename.c_str());
		m_OutFile << A_pw;
		
		// list 포인터를 초기화
		m_List.ResetList();

		// list의 모든 데이터를 파일에 쓰기
		int length = m_List.GetLength();
		int curIndex = m_List.GetNextItem(data);
		while (curIndex < length && curIndex != -1)
		{
			data.WriteDataToFile(m_OutFile);
			curIndex = m_List.GetNextItem(data);
		}

		m_OutFile.close();	// file close

		return 1;
	}

	int WriteUserDataToFile() {
		PlayItem data;	// 쓰기용 임시 변수
		string filename = A_id;
		
		m_OutFile.open(filename);
		m_OutFile << A_pw;
		// list 포인터를 초기화
		
		DoublyNodeType<PlayItem> *t = m_PlayList.GetFirst();
		t = t->next;
		// list의 모든 데이터를 파일에 쓰기
		while (1)
		{
			if (t->next == NULL) break;
			t->data.WriteDataToFile(m_OutFile);
			t = t->next;
		}

		m_OutFile.close();	// file close

		return 1;
	}
	/**
	*	@brief	리스트에서 해당 id를 가진 item을 찾는다.
	*	@pre	없음.
	*	@post	찾은 item을 출력한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int	RetrieveMusic(); // 키보드로부터 음악 ID를 받아서 List에서 기록을 찾아서 화면에 출력

	/**
	*	@brief	리스트에 입력된 모든 곡을 삭제한다.
	*	@pre	없음.
	*	@post	m_length를 0으로 바꾼다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int MakeEmpty(); // 리스트에 입력된 모든 곡을 삭제

	/**
	*	@brief	id가 일치하는 item을 찾아서 해당 item을 제거한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에 해당 item이 제거된다.
	*	@param	data	제거하고자 하는 id가 입력된 ItemType값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int	DeleteMusic(); // 키보드로부터 음악 ID를 받아서 List에서 해당 학생을 삭제
		/**
	*	@brief	id가 일치하는 item을 찾아서 해당 item을 입력받은 item으로 바꾼다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에 해당 item이 대체된다.
	*	@param	data	대체하고자 하는 id가 입력된 ItemType값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int	ReplaceMusic(); //키보드로부터 음악 기록을 받은 다음에 list에서 같은 기록을 찾아 새로 입력된 기록으로 치환
		/**
	*	@brief	리스트에서 해당 id를 가진 item을 Binary로 찾아 출력한다.
	*	@pre	ID값으로 숫자만 입력받는다.
	*	@post	해당 id를 가진 item의 detail한 정보를 콘솔에 출력한다.
	*	@return 해당 item이 있을시 1을 리턴, 아닐시 0을 리턴.
	*/
	int SearchById_BinaryS();

	/**
	*	@brief	리스트에서 해당 검색어를 포함하는 Artist Name을 가진 data들을 모두 출력한다.
	*	@post	해당 검색어를 포함하고 있는 data들이 출력된다.
	*	@return 해당 item이 있을시 1을 리턴, 아닐시 0을 리턴.
	*/
	int SearchByArtist();
	/**
	*	@brief	리스트에서 해당 검색어를 장르로 가진 data들을 모두 출력한다.
	*	@post	해당 검색어를 포함하고 있는 data들이 출력된다.
	*	@return 해당 item이 있을시 1을 리턴, 아닐시 0을 리턴.
	*/
	int SearchByGenre();

	/**
	*	@brief	user로부터 command를 입력받는다.
	*	@return user의 input이 리턴된다.

	*/
	int SelectSearchType();
	/**
	*	@brief	selectsearchtype에서 입력받은 커맨드에 따라 해당하는 검색 기능을 수행한다.
	*	@pre	커맨드 값이 0~4에서 유효해야한다. 
	*	@post	커맨드 값에 해당하는 기능이 수행된다.
	*/
	void UserSearchTypeRun();

	void SearchTypeRun();
	//3차 추가
	/**
	*	@brief	input string과 일치하는 id를 가진 레코드를 찾아 파라미터 데이터에 복사시킨다. 
	*	@pre	input string에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	input string과 일치하는 id를 가진 레코드가 파라미터 데이터에 복사된다.
	*	@param	input	찾고자하는 id값 data	복사받을 데이터 
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int SearchIdAddBinaryS(string input, ItemType &data);
	/**
	*	@brief	키보드에서 playlist에 추가하고자 하는 음악의 id를 받아 list에서 검색한 후 playlist에 추가한다.
	*	@pre	키보드에서 입력받은 id값을 가진 레코드가 list에 존재해야한다.
	*	@post	플레이 리스트에 입력받은 id를 가진 음악이 추가된다.
	*	@param	none
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int AddToPlayList();
	/**
	*	@brief	플레이 리스트에 들어있는 모든 음악이 출력된다. 출력 후 사용자에게 재출력 여부를 묻고 재출력 요청이 끝날 때까지 출력이 반복된다.
	*	@pre	플레이리스트에 음악이 존재해야한다.
	*	@post	콘솔에 플레이리스트가 출력된다.
	*	@param	none
	*	@return none
	*/
	void PlayIOAddTime();
	

	void PlayIOFreq();
	
	/**
	*	@brief	playlist에서 삭제하고자 하는 음악의 id값을 키보드로부터 입력받고, 해당 음악을 playlist에서 삭제한다.
	*	@pre	키보드에서 입력받은 id값을 가진 레코드가 list에 존재해야한다.
	*	@post	플레이리스트에서 입력받은 id를 가진 레코드가 playlist에서 삭제된다.
	*	@param	none
	*	@return none
	*/
	void DeleteFrPlayList();
	
	/**
	*	@brief	selectplaylisttype에서 입력받은 커맨드에 따라 해당하는 검색 기능을 수행한다.
	*	@pre	커맨드 값이 0~4에서 유효해야한다.
	*	@post	커맨드 값에 해당하는 기능이 수행된다.
	*/
	void PlaylistRun();
	/**
	*	@brief	user로부터 command를 입력받는다.
	*	@return user의 input이 리턴된다.

	*/
	int SelectPlaylistType();
	

	/**
	*	@brief	추가할 곡의 가수를 검색하고 가수가 존재하면 해당 가수의 songlist에 곡 추가. 존재하지 않으면 가수를 추가하고 입력된 곡 추가한다.
	*	@pre	addmusic함수가 동작할 때 같이 동작해야한다,
	*	@post	가수의 songlist에 노래가 추가된다.
	*	@param	item 추가할 가수의 노래
	*	@return none
	*/
	void AddSong(ItemType item);
	/**
	*	@brief	artistlist에서 가수를 검색하고 해당 가수가 부른 모든 곡의 자세한 정보를 화면에 출력한다
	*	@pre	해당하는 가수가 artistlist에 존재해야한다.
	*	@post	해당 가수의 모든 곡이 출력된다.
	*	@param	none
	*	@return 해당하는 가수가 artistlist에 존재하면 return0, 존재하지 않으면 return 1;
	*/
	int SearchByArtistWithSL();

private:
	ifstream m_InFile;///< input file descriptor.
	ofstream m_OutFile;///< output file descriptor.
	
	string A_id;
	string A_pw;
	int m_Command;///< current command number.
	
};

