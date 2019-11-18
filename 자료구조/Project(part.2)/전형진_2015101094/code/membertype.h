#ifndef MEMBERTYPE_H
#define MEMBERTYPE_H
#include <string>
#include <fstream>
using namespace std;

class memberType
{
public:
    /**
    *	디폴트 생성자
    */
    memberType();

    /**
    *   생성자
    */
    memberType(string id, string password);

    /**
    *	@brief	member ID를 가져온다.
    *	@pre	member ID를 설정한다.
    *	@post	없음.
    *	@return	member ID.
    */
    string getId();

    /**
    *	@brief	member password를 가져온다.
    *	@pre	member password를 설정한다.
    *	@post	없음.
    *	@return	member password.
    */
    string getPw();

    /**
    *	@brief	파일로부터 member의 모든 정보를 읽어온다.
    *	@pre	정해진 파일을 연다.
    *	@post	member의 모든 정보를 설정한다.
    *	@param	fin	파일 디스크립터.
    *	@return	함수가 잘 작동하면 1을 리턴하고, 그렇지 않으면 0을 리턴한다.
    */
    int ReadDataFromFile(ifstream& fin);

    /**
    *	@brief	파일에 member의 모든 정보를 쓴다.
    *	@pre	정해진 파일을 연다.
    *	@post	정해진 파일에 새로운 member들을 설정한다.
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
    bool operator==(memberType);

    /**
    *	@brief	member의 ID를 설정한다.
    *	@pre	없음.
    *	@post	member의 ID를 설정한다.
    *	@param	in_id	member의 ID.
    */
    void setId(string in_id);

    /**
    *	@brief	member의 pw를 설정한다.
    *	@pre	없음.
    *	@post	member의 pw를 설정한다.
    *	@param	in_pw	member의 password.
    */
    void setPw(string in_pw);

    /**
    *	@brief	member의 레코드를 설정한다.
    *	@pre	없음.
    *	@post	member의 레코드를 설정한다.
    *	@param	in_id	member의 ID.
    *	@param	in_pw	member의 password.
    */
    void setRecord(string in_id, string in_pw);

private:
    string u_id; //member ID
    string u_password; //member password
};

#endif // MEMBERTYPE_H
