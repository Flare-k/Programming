#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
/**
*	Relation between two items.
*/
enum RelationType { LESS, GREATER, EQUAL};

/**
*	item information class.
*/

class ItemType 
{
public:
	/**
	*	default constructor.
	*/
	ItemType() {
		string mId = ""; //곡 ID(고유번호)
		int mType = -1; //곡 타입 저장 변수 1: 가요, 2: 연주곡, 초기값 : -1
		string mTitle = ""; //곡 이름 저장 변수
		string mComposer = ""; // 곡 작곡가 저장 변수
		string mArtist = ""; // 곡의 가수 또는 연주자
		int mGenre = 0; //곡의 장르
	}

	/**
	*	destructor.
	*/
	~ItemType() {}

	/**
	*	@brief	Get music id.
	*	@pre	music id is set.
	*	@post	none.
	*	@return	music id.
	*/

	string GetId() {
		return mId;
	}		
	/**
	*	@brief	Get music type.
	*	@pre	music type is set.
	*	@post	none.
	*	@return	music type.
	*/
	int GetType() {
		return mType;
	}		// 음악 타입 반환 함수

	/**
	*	@brief	Get music title.
	*	@pre	music title is set.
	*	@post	none.
	*	@return	music title.
	*/
	string GetTitle() {
		return mTitle;
	}		//음악 title 반환 함수

	/**
	*	@brief	Get music composer.
	*	@pre	music composer is set.
	*	@post	none.
	*	@return	music composer.
	*/
	string GetComposer() {
		return mComposer;
	}		//음악 작곡가 반환 함수
		/**
	*	@brief	Get music artist.
	*	@pre	music artist is set.
	*	@post	none.
	*	@return	music artist.
	*/
	string GetArtist() {
		return mArtist;
	}		//음악 가수or연주자 반환 함수
	/**
	*	@brief	Get music genre.
	*	@pre	music genre is set.
	*	@post	none.
	*	@return	music genre.
	*/
	int GetGenre() {
		return mGenre;
	}		//음악 장르 반환 함수

	/**
	*	@brief	Set music id.
	*	@pre	none.
	*	@post	music id is set.
	*	@param	inId	music id.
	*/
	void SetId(string inId) {
		mId = inId;
	}		// 음악 ID 저장 함수
	/**
	*	@brief	Set music type.
	*	@pre	none.
	*	@post	music type is set.
	*	@param	inType	music type.
	*/
	void SetType(int inType) {
			cin >> inType;
			mType = inType;

	}		// 음악 타입 저장 함수. 1또는 2만 입력받는 것으로 가정.

	/**
	*	@brief	Set music title.
	*	@pre	none.
	*	@post	music title is set.
	*	@param	inTitle		music title.
	*/
	void SetTitle(string inTitle) {
		mTitle = inTitle;
	}		//음악 이름 저장 함수
		/**
	*	@brief	Set music composer.
	*	@pre	none.
	*	@post	music composer is set.
	*	@param	inComposer	music composer.
	*/
	void SetComposer(string inComposer) {
		mComposer = inComposer;
	}		//음악 작곡가 저장 함수
	/**
	*	@brief	Set music artist.
	*	@pre	none.
	*	@post	music artist is set.
	*	@param	inArtist	music artist.
	*/
	void SetArtist(string inArtist) {
		mArtist = inArtist;
	}		//음악 가수 or 연주자 저장 함수
		/**
	*	@brief	Set music genre.
	*	@pre	none.
	*	@post	music type is genre.
	*	@param	inGenre		music genre.
	*/
	void SetGenre(int inGenre) {
		mGenre = inGenre;
	}
	/**
	*	@brief	Set music record.
	*	@pre	none.
	*	@post	music record is set.
	*	@param	inId		music id.
	*	@param	inType		music name.
	*	@param	inTitle		music title.
	*	@param	inComposer	music composer.
	*	@param	inArtist	music artist.
	*	@param	inGenre		music Genre.
	*/
	void SetRecord(string inId, int inType, string inTitle, string inComposer,
		string inArtist, int inGenre) {
		SetId(inId);
		SetType(inType);
		SetTitle(inTitle);
		SetComposer(inComposer);
		SetArtist(inArtist);
		SetGenre(inGenre);
	}		//음악 정보 저장 함수

		/**
	*	@brief	Display music id on screen.
	*	@pre	music id is set.
	*	@post	music id is on screen.
	*/
	void DisplayIdOnScreen() {
		cout << "\t ID : " << mId;
	}		// 음악 id 출력 함수
	/**
	*	@brief	Display music type on screen.
	*	@pre	music type is set.
	*	@post	music type is on screen.
	*/
	void DisplayTypeOnScreen() {
		if (mType == 1) {
			cout << "\t Type : 가요";
		}
		else if(mType == 2){
			cout << "\t Type : 연주곡";
		}
		
		}		//음악 타입 출력 함수
		/**
	*	@brief	Display music title on screen.
	*	@pre	music title is set.
	*	@post	music title is on screen.
	*/
	void DisplayTitleOnScreen() {
		cout << "\t Title : " << mTitle;
	}		//음악 타이틀 출력 함수
		/**
	*	@brief	Display music composer on screen.
	*	@pre	music composer is set.
	*	@post	music composer is on screen.
	*/
	void DisplayComposerOnScreen() {
		cout << "\t Composer : " << mComposer;
	}		//음악 작곡가 출력 함수
		/**
	*	@brief	Display music artist on screen.
	*	@pre	music artist is set.
	*	@post	music artist is on screen.
	*/
	void DisplayArtistOnScreen() {
		cout << "\t Artist : " << mArtist;
	}		// 음악 가수 or 연주자 출력 함수
	/**
	*	@brief	Display music genre on screen.
	*	@pre	music genre is set.
	*	@post	music genre is on screen.
	*/
	void DisplayGenreOnScreen() {
		cout << "\t Genre : " << mGenre << endl;
	}		// 음악 장르 출력 함수
		/**
	*	@brief	Display music record on screen.
	*	@pre	music record is set.
	*	@post	music record is on screen.
	*/
	void DisplayRecordOnScreen() {
		DisplayIdOnScreen();
		DisplayTypeOnScreen();
		DisplayTitleOnScreen();
		DisplayComposerOnScreen();
		DisplayArtistOnScreen();
		DisplayGenreOnScreen();
	}

	/**
	*	@brief	Set music id from keyboard.
	*	@pre	none.
	*	@post	music id is set.
	*/
	void SetIdFromKB() {
		cout << "\t* ID를 입력해주세요 : ";
		cin >> mId;
		cin.ignore(1000, '\n');
	}				// 키보드로 음악 ID 입력 함수
	/**
	*	@brief	Set music type from keyboard.
	*	@pre	none.
	*	@post	music type is set.
	*/
	void SetTypeFromKB() {
		cout << "\t* 음악의 타입을 입력해주세요(1 : 가요, 2 : 연주곡. 1 또는 2만 입력해 주세요.) : ";

		int inType;
		while (1) {
			cin >> inType;
			if (inType == 1 || inType == 2) {
				mType = inType;
				break;
			}
			else {
				cout << endl << "\t====1 또는 2만 입력되어야 합니다.====" << endl << endl;
				cout << "\t* 음악의 타입을 입력해주세요(1 : 가요, 2 : 연주곡. 1 또는 2만 입력해 주세요.) : ";
				cin.ignore(1000, '\n');
			}
		}

	}			// 키보드로 음악 타입 입력 입력이 바른 입력이 될 때까지 반복
		/**
	*	@brief	Set music title from keyboard.
	*	@pre	none.
	*	@post	music title is set.
	*/
	void SetTitleFromKB() {
		cout << "\t* 음악의 제목을 입력해주세요 : ";
		cin >> mTitle;
	}			// 키보드로 음악 타이틀 입력 함수
		/**
	*	@brief	Set music composer from keyboard.
	*	@pre	none.
	*	@post	music composer is set.
	*/
	void SetComposerFromKB() {
		cout << "\t* 작곡가의 이름을 입력해주세요 : ";
		cin >> mComposer;
	}			// 키보드로 작곡가 이름 입력 함수
			/**
	*	@brief	Set music artist from keyboard.
	*	@pre	none.
	*	@post	music artist is set.
	*/
	void SetArtistFromKB() {
		cout << "\t* 아티스트 이름을 입력해주세요 : ";
		cin >> mArtist;
	}			// 키보드로 아티스트 이름 입력 함수
			/**
	*	@brief	Set music genre from keyboard.
	*	@pre	none.
	*	@post	music genre is set.
	*/
	void SetGenreFromKB() {
		cout << "\t* 장르를 입력해주세요 : ";
		cin >> mGenre;
	}			// 키보드로 장르 입력 함수
			/**
	*	@brief	Set music record from keyboard.
	*	@pre	none.
	*	@post	music record is set.
	*/
	void SetRecordFromKB() {
		SetIdFromKB();
		SetTypeFromKB();
		SetTitleFromKB();
		SetComposerFromKB();
		SetArtistFromKB();
		SetGenreFromKB();
	}			// 키보드로 음악 정보 입력 함수
		/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	student record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);
	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new student record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout);
	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.id < data.id,
	*			return GREATER if this.id > data.id then,
	*			otherwise return EQUAL.
	*/
	RelationType Compare(const ItemType &data);
private:
	// 변수는 총 여섯 개. int변수의 초기값은 -1로 설정. string변수의 초기값은 ""로 설정.
	
	string mId; //곡 ID(고유번호)
	int mType; //곡 타입 저장 변수 1: 가요, 2: 연주곡, 초기값 : -1
	string mTitle; //곡 이름 저장 변수
	string mComposer; // 곡 작곡가 저장 변수
	string mArtist; // 곡의 가수 또는 연주자
	int mGenre; //곡의 장르
	



};









