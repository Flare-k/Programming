#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

enum RelationType { EQUAL, GREATER, LESS };
class MusicType
{
public:
    /**
    *	디폴트 생성자
    */
    MusicType();

    /**
    *   생성자
    */
    MusicType(int in_id);

    /**
    *   소멸자
    */
    ~MusicType();

    /**
    *	@brief	노래 type을 가져온다.
    *	@pre	노래 type을 설정한다.
    *	@post	없음.
    *	@return	노래 type.
    */
    string GetType();

    /**
    *	@brief	노래 name을 가져온다.
    *	@pre	노래 name을 설정한다.
    *	@post	없음.
    *	@return	노래 name.
    */
	string GetName();

    /**
    *	@brief	노래 composer를 가져온다.
    *	@pre	노래 composer를 설정한다.
    *	@post	없음.
    *	@return	노래 composer.
    */
	string GetComposer();

    /**
    *	@brief	노래 artist를 가져온다.
    *	@pre	노래 artist를 설정한다.
    *	@post	없음.
    *	@return	노래 artist.
    */
	string GetArtist();

    /**
    *	@brief	노래 genre를 가져온다.
    *	@pre	노래 genre를 설정한다.
    *	@post	없음.
    *	@return	노래 genre.
    */
	string GetGenre();

    /**
    *	@brief	노래 lyrics를 가져온다.
    *	@pre	노래 lyrics를 설정한다.
    *	@post	없음.
    *	@return	노래 lyrics.
    */
    string GetLyrics();

    /**
    *	@brief	노래 album cover filename을 가져온다.
    *	@pre	노래 album cover filename을 설정한다.
    *	@post	없음.
    *	@return	노래 album cover.
    */
    string GetAlbumcover();

    /**
    *	@brief	노래 ID를 가져온다.
    *	@pre	노래 ID를 설정한다.
    *	@post	없음.
    *	@return	노래 ID.
    */
	int GetId();
	
    /**
    *	@brief	노래의 type을 설정한다.
    *	@pre	없음.
    *	@post	노래의 type을 설정한다.
    *	@param	inType	노래의 type.
    */
    void SetType(string inType);

    /**
    *	@brief	노래의 name을 설정한다.
    *	@pre	없음.
    *	@post	노래의 name을 설정한다.
    *	@param	inName	노래의 제목.
    */
	void SetName(string inName);

    /**
    *	@brief	노래의 composer를 설정한다.
    *	@pre	없음.
    *	@post	노래의 composer를 설정한다.
    *	@param	inComposer	노래의 composer 이름.
    */
	void SetComposer(string inComposer);

    /**
    *	@brief	노래의 type을 설정한다.
    *	@pre	없음.
    *	@post	노래의 type을 설정한다.
    *	@param	inArtist	노래의 aritst 이름.
    */
	void SetArtist(string inArtist);

    /**
    *	@brief	노래의 genre를 설정한다.
    *	@pre	없음.
    *	@post	노래의 genre를 설정한다.
    *	@param	inGenre	노래의 장르.
    */
    void SetGenre(string inGenre);

    /**
    *	@brief	노래의 고유 ID 설정한다.
    *	@pre	없음.
    *	@post	노래의 ID 설정한다.
    *	@param	inId	노래의 ID.
    */
    void SetId(int inId);

    /**
    *	@brief	노래의 가사를 설정한다.
    *	@pre	없음.
    *	@post	노래의 lyrics 설정한다.
    *	@param	inLyrics	노래의 lyrics.
    */
    void SetLyrics(string inLyrics);

    /**
    *	@brief	노래의 레코드를 설정한다.
    *	@pre	없음.
    *	@post	노래의 레코드를 설정한다.
    *	@param	inType	노래의 type.
    *   @param	inName	노래의 제목.
    *   @param	inComposer	노래의 작곡가명.
    *   @param	inArtist	노래의 아티스트명.
    *   @param	inGenre	노래의 장르.
    *   @param	inId	노래의 ID.
    */
    void SetRecord(string inType, string inName, string inComposer, string inArtist, string inGenre, int inId);

    /**
    *	@brief	노래의 앨범커버 설정한다.
    *	@pre	없음.
    *	@post	노래의 앨범커버 설정한다.
    *	@param	inAlbumcover    노래의 album cover filename.
    */
    void SetAlbumcover(string inAlbumcover);

    /**
    *	@brief	파일로부터 노래의 모든 정보를 읽어온다.
    *	@pre	정해진 파일을 연다.
    *	@post	노래의 모든 정보를 설정한다.
    *	@param	fin	파일 디스크립터.
    *	@return	함수가 잘 작동하면 1을 리턴하고, 그렇지 않으면 0을 리턴한다.
    */
	int ReadDataFromFile(ifstream& fin);

    /**
    *	@brief	파일에 노래의 모든 정보를 쓴다.
    *	@pre	정해진 파일을 연다.
    *	@post	정해진 파일에 새로운 노래들을 설정한다.
    *	@param	fout	파일 디스크립터.
    *	@return	함수가 잘 작동하면 1을 리턴하고, 그렇지 않으면 0을 리턴한다.
    */
	int WriteDataToFile(ofstream& fout);

    /**
    *	@brief	'=='를 재정의한다.
    *	@pre	기존 '=='으로 정의 되어있다.
    *	@post	'==' 재정의 된 것으로 사용할 수 있다.
    *	@return	해당 케이스면 TRUE, 그렇지 않으면 FALSE.
    */
    bool operator==(MusicType temp);

    /**
    *	@brief	'>'를 재정의한다.
    *	@pre	기존 '>'으로 정의 되어있다.
    *	@post	'>' 재정의 된 것으로 사용할 수 있다.
    *	@return	해당 케이스면 TRUE, 그렇지 않으면 FALSE.
    */
    bool operator>(MusicType temp);

    /**
    *	@brief	'<'를 재정의한다.
    *	@pre	기존 '<'으로 정의 되어있다.
    *	@post	'<' 재정의 된 것으로 사용할 수 있다.
    *	@return	해당 케이스면 TRUE, 그렇지 않으면 FALSE.
    */
    bool operator<(MusicType temp);

private:
    int m_Id; // 곡 ID
    string m_Type; // 곡 타입(연주곡, 노래)
    string m_Name; // 곡 제목
    string m_Composer; // 작곡가
    string m_Artist; // 가수명
    string m_Genre; // 장르명
    string m_Lyrics; //가사
    string m_Albumcover; // 앨범커버 파일명

};
