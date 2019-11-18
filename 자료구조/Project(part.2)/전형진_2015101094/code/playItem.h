#pragma once
#include <iostream>
#include <fstream>
using namespace std;


class playItem 
{
public:
    /**
    *	����Ʈ ������
    */
	playItem();

    /**
    *   ������
    */
    playItem(int inId);

    /**
    *   �Ҹ���
    */
	~playItem(){}

    /**
    *	@brief	�뷡 ID�� �����´�.
    *	@pre	�뷡 ID�� �����Ѵ�.
    *	@post	����.
    *	@return	�뷡 ID.
    */
	int getId();

    /**
    *	@brief	�뷡�� ���� ID �����Ѵ�.
    *	@pre	����.
    *	@post	�뷡�� ID �����Ѵ�.
    *	@param	inId	�뷡�� ID.
    */
	void setId(int inId);

    /**
    *	@brief	�뷡�� ���Ƚ�� �����Ѵ�.
    *	@pre	����.
    *	@post	�뷡�� ID �����Ѵ�.
    *	@param	inNum	�뷡�� ���Ƚ��.
    */
	void setNum(int inNum);

    /**
    *	@brief	�뷡�� input order�� �����Ѵ�.
    *	@pre	����.
    *	@post	�뷡�� input ������ �����Ѵ�.
    *	@param	inTime	�뷡�� input order.
    */
	void setTime(int inTime);

    /**
    *	@brief	'=='�� �������Ѵ�.
    *	@pre	���� '=='���� ���� �Ǿ��ִ�.
    *	@post	'==' ������ �� ������ ����� �� �ִ�.
    *	@return	�ش� ���̽��� TRUE, �׷��� ������ FALSE.
    */
	bool operator==(playItem temp);

    /**
    *	@brief	'>'�� �������Ѵ�.
    *	@pre	���� '>'���� ���� �Ǿ��ִ�.
    *	@post	'>' ������ �� ������ ����� �� �ִ�.
    *	@return	�ش� ���̽��� TRUE, �׷��� ������ FALSE.
    */
    bool operator>(playItem temp);

    /**
    *	@brief	'<'�� �������Ѵ�.
    *	@pre	���� '<'���� ���� �Ǿ��ִ�.
    *	@post	'<' ������ �� ������ ����� �� �ִ�.
    *	@return	�ش� ���̽��� TRUE, �׷��� ������ FALSE.
    */
    bool operator<(playItem temp);

    /**
    *	@brief	���Ϸκ��� �뷡�� ������ �о�´�.
    *	@pre	������ ������ ����.
    *	@post	�뷡�� ��� ������ �����Ѵ�.
    *	@param	fin	���� ��ũ����.
    *	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
    */
    int ReadDataFromFile(ifstream& fin);

    /**
    *	@brief	���Ͽ� �뷡�� ������ ����.
    *	@pre	������ ������ ����.
    *	@post	������ ���Ͽ� ���ο� �뷡���� �����Ѵ�.
    *	@param	fout	���� ��ũ����.
    *	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
    */
    int WriteDataToFile(ofstream& fout);

private:
    int p_Id; // �� ID
    int p_numPlay; // �� ���Ƚ��
    int p_Intime; // input order

};
