#ifndef MEMBERTYPE_H
#define MEMBERTYPE_H
#include <string>
#include <fstream>
using namespace std;

class memberType
{
public:
    /**
    *	����Ʈ ������
    */
    memberType();

    /**
    *   ������
    */
    memberType(string id, string password);

    /**
    *	@brief	member ID�� �����´�.
    *	@pre	member ID�� �����Ѵ�.
    *	@post	����.
    *	@return	member ID.
    */
    string getId();

    /**
    *	@brief	member password�� �����´�.
    *	@pre	member password�� �����Ѵ�.
    *	@post	����.
    *	@return	member password.
    */
    string getPw();

    /**
    *	@brief	���Ϸκ��� member�� ��� ������ �о�´�.
    *	@pre	������ ������ ����.
    *	@post	member�� ��� ������ �����Ѵ�.
    *	@param	fin	���� ��ũ����.
    *	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
    */
    int ReadDataFromFile(ifstream& fin);

    /**
    *	@brief	���Ͽ� member�� ��� ������ ����.
    *	@pre	������ ������ ����.
    *	@post	������ ���Ͽ� ���ο� member���� �����Ѵ�.
    *	@param	fout	���� ��ũ����.
    *	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
    */
    int WriteDataToFile(ofstream& fout);

    /**
    *	@brief	'=='�� �������Ѵ�.
    *	@pre	���� '=='���� ���� �Ǿ��ִ�.
    *	@post	'==' ������ �� ������ ����� �� �ִ�.
    *	@return	�ش� ���̽��� TRUE, �׷��� ������ FALSE.
    */
    bool operator==(memberType);

    /**
    *	@brief	member�� ID�� �����Ѵ�.
    *	@pre	����.
    *	@post	member�� ID�� �����Ѵ�.
    *	@param	in_id	member�� ID.
    */
    void setId(string in_id);

    /**
    *	@brief	member�� pw�� �����Ѵ�.
    *	@pre	����.
    *	@post	member�� pw�� �����Ѵ�.
    *	@param	in_pw	member�� password.
    */
    void setPw(string in_pw);

    /**
    *	@brief	member�� ���ڵ带 �����Ѵ�.
    *	@pre	����.
    *	@post	member�� ���ڵ带 �����Ѵ�.
    *	@param	in_id	member�� ID.
    *	@param	in_pw	member�� password.
    */
    void setRecord(string in_id, string in_pw);

private:
    string u_id; //member ID
    string u_password; //member password
};

#endif // MEMBERTYPE_H
