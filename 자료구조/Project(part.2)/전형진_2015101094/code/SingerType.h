#pragma once
#include <string>
#include <fstream>
#include "UnsortedList.h"
using namespace std;

//SingerType에서 사용될 특정 가수의 곡 structure
struct SingerSong {
    /**
    *	디폴트 생성자
    */
    SingerSong(){}

    /**
    *   생성자
    */
    SingerSong(int in_id, string in_title):id(in_id),
        title(in_title){}

    /**
    *   소멸자
    */
    ~SingerSong(){}

    int id; // song id
    string title; // song 제목

    /**
    *	@brief	'=='를 재정의한다.
    *	@pre	기존 '=='으로 정의 되어있다.
    *	@post	'==' 재정의 된 것으로 사용할 수 있다.
    *	@return	해당 케이스면 TRUE, 그렇지 않으면 FALSE.
    */
    bool operator==(SingerSong temp)
    {
        return this->id == temp.id;
    }

};


class SingerType {
public:
    /**
    *	@brief	노래 나이를 가져온다.
    *	@pre	노래 나이를 설정한다.
    *	@post	없음.
    *	@return	노래 나이.
    */
    int getAge() const;

    /**
    *	@brief	노래 이름을 가져온다.
    *	@pre	노래 이름을 설정한다.
    *	@post	없음.
    *	@return	노래 이름.
    */
    string getName() const;

    /**
    *	@brief	노래 성별을 가져온다.
    *	@pre	노래 성별을 설정한다.
    *	@post	없음.
    *	@return	노래 성별.
    */
    string getGender() const;

    /**
    *	@brief	노래 사진의 filname 가져온다.
    *	@pre	노래 사진의 filname 설정한다.
    *	@post	없음.
    *	@return	노래 사진의 filname.
    */
    string getPicture() const;

    /**
    *	@brief	노래 생년월일을 가져온다.
    *	@pre	노래 생년월일을 설정한다.
    *	@post	없음.
    *	@return	노래 생년월일.
    */
    string getBorn() const;

    /**
    *	@brief	노래 데뷔일을 가져온다.
    *	@pre	노래 데뷔일을 설정한다.
    *	@post	없음.
    *	@return	노래 데뷔일.
    */
    string getDebut() const;

    /**
    *	@brief	노래의 나이를 설정한다.
    *	@pre	없음.
    *	@post	노래의 나이를 설정한다.
    *	@param	Age	노래의 나이.
    */
    void setAge(int Age);

    /**
    *	@brief	노래의 이름을 설정한다.
    *	@pre	없음.
    *	@post	노래의 이름을 설정한다.
    *	@param	name	노래의 이름.
    */
    void setName(string name);

    /**
    *	@brief	노래의 성별을 설정한다.
    *	@pre	없음.
    *	@post	노래의 성별을 설정한다.
    *	@param	gender	노래의 성별.
    */
    void setGender(string gender);

    /**
    *	@brief	노래의 사진을 설정한다.
    *	@pre	없음.
    *	@post	노래의 사진을 설정한다.
    *	@param	picture	노래의 사진.
    */
    void setPicture(string picture);

    /**
    *	@brief	노래의 데뷔일을 설정한다.
    *	@pre	없음.
    *	@post	노래의 데비윌을 설정한다.
    *	@param	debut	노래의 데뷔일.
    */
    void setDebut(string debut);

    /**
    *	@brief	노래의 생년원일을 설정한다.
    *	@pre	없음.
    *	@post	노래의 생년원일을 설정한다.
    *	@param	born	노래의 생년원일.
    */
    void setborn(string born);

    /**
    *	@brief	가수 발매곡에 노래를 추가한다.
    *	@pre	노래의 정보를 모두 설정한다.
    *	@post	가수 발매곡에 노래를 추가한다.
    *	@param	item	노래의 발매곡.
    */
    void addSong(SingerSong item);

    /**
    *	@brief	가수 발매곡에 노래를 삭제한다.
    *	@pre	발매곡의 ID를 설정한다.
    *	@post	가수 발매곡에 동일한 id의 노래를 삭제한다.
    *	@param	item	노래의 발매곡.
    */
    void deleteSong(SingerSong item);

    /**
    *	@brief	파일로부터 노래의 정보를 읽어온다.
    *	@pre	정해진 파일을 연다.
    *	@post	노래의 모든 정보를 설정한다.
    *	@param	fin	파일 디스크립터.
    *	@return	함수가 잘 작동하면 1을 리턴하고, 그렇지 않으면 0을 리턴한다.
    */
    int ReadDataFromFile(ifstream& fin);

    /**
    *	@brief	파일에 노래의 정보를 쓴다.
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
    bool operator==(const SingerType& temp);


private:
    string s_Name; // 가수 이름
    int s_Age; // 가수 나이
    string s_Gender; // 가수 성별
    string s_Debut; // 가수 데뷔일자
    string s_Born; // 가수 생년월일
    string s_Picture; // 가수 사진 파일명
    UnsortedList<SingerSong> s_SongList; // 가수 발매곡
};
