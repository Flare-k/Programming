#pragma once
#include <iostream>
#include <fstream>
using namespace std;


class playItem 
{
public:
    /**
    *	디폴트 생성자
    */
	playItem();

    /**
    *   생성자
    */
    playItem(int inId);

    /**
    *   소멸자
    */
	~playItem(){}

    /**
    *	@brief	노래 ID를 가져온다.
    *	@pre	노래 ID를 설정한다.
    *	@post	없음.
    *	@return	노래 ID.
    */
	int getId();

    /**
    *	@brief	노래의 고유 ID 설정한다.
    *	@pre	없음.
    *	@post	노래의 ID 설정한다.
    *	@param	inId	노래의 ID.
    */
	void setId(int inId);

    /**
    *	@brief	노래의 재생횟수 설정한다.
    *	@pre	없음.
    *	@post	노래의 ID 설정한다.
    *	@param	inNum	노래의 재생횟수.
    */
	void setNum(int inNum);

    /**
    *	@brief	노래의 input order를 설정한다.
    *	@pre	없음.
    *	@post	노래의 input 순서를 설정한다.
    *	@param	inTime	노래의 input order.
    */
	void setTime(int inTime);

    /**
    *	@brief	'=='를 재정의한다.
    *	@pre	기존 '=='으로 정의 되어있다.
    *	@post	'==' 재정의 된 것으로 사용할 수 있다.
    *	@return	해당 케이스면 TRUE, 그렇지 않으면 FALSE.
    */
	bool operator==(playItem temp);

    /**
    *	@brief	'>'를 재정의한다.
    *	@pre	기존 '>'으로 정의 되어있다.
    *	@post	'>' 재정의 된 것으로 사용할 수 있다.
    *	@return	해당 케이스면 TRUE, 그렇지 않으면 FALSE.
    */
    bool operator>(playItem temp);

    /**
    *	@brief	'<'를 재정의한다.
    *	@pre	기존 '<'으로 정의 되어있다.
    *	@post	'<' 재정의 된 것으로 사용할 수 있다.
    *	@return	해당 케이스면 TRUE, 그렇지 않으면 FALSE.
    */
    bool operator<(playItem temp);

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

private:
    int p_Id; // 곡 ID
    int p_numPlay; // 곡 재생횟수
    int p_Intime; // input order

};
