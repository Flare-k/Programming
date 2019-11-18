#pragma once
#include <iostream>
#include <string>

using namespace std;

#define songlistsize 100

class SimpleItemType
{
public:
	/**
	*	@brief	Get music id.
	*	@pre	music id is set.
	*	@post	none.
	*	@return	music id.
	*/

	string GetMId() {
		return mId;
	}
	/**
	*	@brief	Get music title.
	*	@pre	music id is set.
	*	@post	none.
	*	@return	music title.
	*/

	string GetMTitle() {
		return mTitle;
	}

	/**
	*	@brief	Set music id.
	*	@pre	none.
	*	@post	music id is set.
	*	@param	inId	music id.
	*/
	void setMId(string inId) {
		mId = inId;
	}
	/**
	*	@brief	Set music title.
	*	@pre	none.
	*	@post	music title is set.
	*	@param	inTitle	music title.
	*/
	void setMTitle(string inTitle) {
		mTitle = inTitle;
	}
	/**
	*	@brief	Set music record.
	*	@pre	none.
	*	@post	music record is set.
	*	@param	inId		music id.
	*	@param	inTitle		music title.
	*/
	void setRecord(string inId, string inTitle) {
		setMId(inId);
		setMTitle(inTitle);
	}

	

private:
	string mId;
	string mTitle;
};

class ArtistType {
public:

	/**
	*	default constructor.
	*/
	ArtistType() {
		artistName = "";
		artistAge = 0;
		artistGender = 0;
		songList = new SimpleItemType[songlistsize];
	}
	/**
	*	destructor.
	*/
	~ArtistType() {}

	void setArtistName(string inName) {
		artistName = inName;
	}

	void setArtistAge(int inAge) {
		artistAge = inAge;
	}

	void setArtistGender(int inGender) {
		artistGender = inGender;
	}

	void setRecord(string inName, int inAge, int inGender) {
		artistName = inName;
		artistAge = inAge;
		artistGender = inGender;
	}

	void setArtistNameFromKB() {
		string inName;
		cout << "\t* 아티스트 이름을 입력해주세요 : ";
		cin >> inName;
		artistName = inName;
	}

	void setArtistAgeFromKB() {
		int inAge;
		cout << "\t* 아티스트의 나이를 입력해주세요 : ";
		cin >> inAge;
		artistAge = inAge;
	}

	void setArtistGenderFromKB() {
		int inGender;
		cout << "\t* 아티스트의 성별을 입력해주세요(1 : 남 2 : 여) : ";
		while (true) {

			cin >> inGender;
			if (inGender == 1 || inGender == 2) {
				artistGender = inGender;
				break;
			}
			else {
				cout << endl << "\t====1 또는 2만 입력되어야 합니다.====" << endl << endl;
				cout << "\t* 아티스트의 성별을 입력해주세요(1 : 남 2 : 여) : ";
				cin.ignore(1000, '\n');
			}
		}
	}

	void setRecordFromKB() {
		setArtistAgeFromKB();
		setArtistAgeFromKB();
		setArtistGenderFromKB();
	}

	/**
	*	@brief	Get artist name.
	*	@pre	artist name is set.
	*	@post	none.
	*	@return	artist name.
	*/
	string getArtistName() {
		return artistName;
	}
	/**
	*	@brief	Get artist age.
	*	@pre	artist age is set.
	*	@post	none.
	*	@return	artist age.
	*/
	int getArtistAge() {
		return artistAge;
	}
	/**
	*	@brief	Get artist gender.
	*	@pre	artist gender is set.
	*	@post	none.
	*	@return	artist gender.
	*/
	int getArtistGender() {
		return artistGender;
	}
	/**
	*	@brief	Display artist name on screen.
	*	@pre	artist name is set.
	*	@post	artist name is on screen.
	*/
	void DisplayArtistNameOnScreen() {
		cout << "\t 아티스트 이름: " << artistName;
	}

	/**
	*	@brief	Display artist age on screen.
	*	@pre	artist age is set.
	*	@post	artist age is on screen.
	*/
	void DisplayArtistAgeOnScreen() {
		cout << "\t 아티스트 나이: " << artistAge;
	}
	/**
	*	@brief	Display artist gender on screen.
	*	@pre	artist gender is set.
	*	@post	artist gender is on screen.
	*/
	void DisplayArtistGenderOnScreen() {
		if (artistGender == 1) {
			cout << "\t 아티스트 성별: 남" << endl;
		}
		else {
			cout << "\t 아티스트 성별: 여" << endl;
		}
	}

	/**
	*	@brief	Display song list on screen.
	*	@pre	artist song list is set.
	*	@post	artist song list is on screen.
	*/
	void DisplaySongListOnScreen() {
		cout << "\t======= 아티스트 곡 목록 =======" << endl;
		ResetList();
		int isEnd = 1;
		while (isEnd != 0) {
			SimpleItemType data;
			isEnd = GetNextItem(data);
			cout << "\t ID : " << data.GetMId();
			cout << "\t Title : " << data.GetMTitle() << endl;
		}
		cout << "\t================================" << endl;
	}

	/**
	*	@brief	Display artist record on screen.
	*	@pre	artist record is set.
	*	@post	artist record is on screen.
	*/
	void DisplayRecordOnScreen() {
		DisplayArtistNameOnScreen();
		DisplayArtistAgeOnScreen();
		DisplayArtistGenderOnScreen();
		DisplaySongListOnScreen();
	}
	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return 1 if list capacity reached to the upper bound, otherwise return 0.
	*/
	int IsFull() {
		if (s_Length > songlistsize - 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList() {
		s_CurPointer = -1;
	}

	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(SimpleItemType data) {
		if (!IsFull()) {
			songList[s_Length] = data;
			s_Length++;
			return 1;
		}
		else {
			return 0;
		}
	}
	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	다음 아이템이 존재하여 data에 복사 성공하면 return 1. 존재하지 않아 복사 실패하면 return 0.
	*/
	int GetNextItem(SimpleItemType &data) {
		s_CurPointer++;
		if (s_CurPointer == s_Length - 1) {
			data = songList[s_CurPointer];
			return 0;
		}
		else {
			data = songList[s_CurPointer];
			return 1;
		}
	}

	//연산자 오버로딩
	bool operator > (ArtistType &data) {
		if (artistName.compare(data.artistName) > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	//연산자 오버로딩
	bool operator < (ArtistType &data) {
		if (artistName.compare(data.artistName) < 0) {
			return true;
		}
		else {
			return false;
		}
	}
	//연산자 오버로딩
	bool operator == (ArtistType &data) {
		if (artistName.compare(data.artistName) == 0) {
			return true;
		}
		else {
			return false;
		}
	}

private:
	string artistName;
	int artistAge;
	int artistGender; //1:남 2:여
	SimpleItemType *songList;
	int s_CurPointer;
	int s_Length;
};

