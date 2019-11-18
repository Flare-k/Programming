#pragma once
#include <string>
#include <fstream>
#include "UnsortedList.h"
using namespace std;

//SingerType���� ���� Ư�� ������ �� structure
struct SingerSong {
    /**
    *	����Ʈ ������
    */
    SingerSong(){}

    /**
    *   ������
    */
    SingerSong(int in_id, string in_title):id(in_id),
        title(in_title){}

    /**
    *   �Ҹ���
    */
    ~SingerSong(){}

    int id; // song id
    string title; // song ����

    /**
    *	@brief	'=='�� �������Ѵ�.
    *	@pre	���� '=='���� ���� �Ǿ��ִ�.
    *	@post	'==' ������ �� ������ ����� �� �ִ�.
    *	@return	�ش� ���̽��� TRUE, �׷��� ������ FALSE.
    */
    bool operator==(SingerSong temp)
    {
        return this->id == temp.id;
    }

};


class SingerType {
public:
    /**
    *	@brief	�뷡 ���̸� �����´�.
    *	@pre	�뷡 ���̸� �����Ѵ�.
    *	@post	����.
    *	@return	�뷡 ����.
    */
    int getAge() const;

    /**
    *	@brief	�뷡 �̸��� �����´�.
    *	@pre	�뷡 �̸��� �����Ѵ�.
    *	@post	����.
    *	@return	�뷡 �̸�.
    */
    string getName() const;

    /**
    *	@brief	�뷡 ������ �����´�.
    *	@pre	�뷡 ������ �����Ѵ�.
    *	@post	����.
    *	@return	�뷡 ����.
    */
    string getGender() const;

    /**
    *	@brief	�뷡 ������ filname �����´�.
    *	@pre	�뷡 ������ filname �����Ѵ�.
    *	@post	����.
    *	@return	�뷡 ������ filname.
    */
    string getPicture() const;

    /**
    *	@brief	�뷡 ��������� �����´�.
    *	@pre	�뷡 ��������� �����Ѵ�.
    *	@post	����.
    *	@return	�뷡 �������.
    */
    string getBorn() const;

    /**
    *	@brief	�뷡 �������� �����´�.
    *	@pre	�뷡 �������� �����Ѵ�.
    *	@post	����.
    *	@return	�뷡 ������.
    */
    string getDebut() const;

    /**
    *	@brief	�뷡�� ���̸� �����Ѵ�.
    *	@pre	����.
    *	@post	�뷡�� ���̸� �����Ѵ�.
    *	@param	Age	�뷡�� ����.
    */
    void setAge(int Age);

    /**
    *	@brief	�뷡�� �̸��� �����Ѵ�.
    *	@pre	����.
    *	@post	�뷡�� �̸��� �����Ѵ�.
    *	@param	name	�뷡�� �̸�.
    */
    void setName(string name);

    /**
    *	@brief	�뷡�� ������ �����Ѵ�.
    *	@pre	����.
    *	@post	�뷡�� ������ �����Ѵ�.
    *	@param	gender	�뷡�� ����.
    */
    void setGender(string gender);

    /**
    *	@brief	�뷡�� ������ �����Ѵ�.
    *	@pre	����.
    *	@post	�뷡�� ������ �����Ѵ�.
    *	@param	picture	�뷡�� ����.
    */
    void setPicture(string picture);

    /**
    *	@brief	�뷡�� �������� �����Ѵ�.
    *	@pre	����.
    *	@post	�뷡�� �������� �����Ѵ�.
    *	@param	debut	�뷡�� ������.
    */
    void setDebut(string debut);

    /**
    *	@brief	�뷡�� ��������� �����Ѵ�.
    *	@pre	����.
    *	@post	�뷡�� ��������� �����Ѵ�.
    *	@param	born	�뷡�� �������.
    */
    void setborn(string born);

    /**
    *	@brief	���� �߸Ű �뷡�� �߰��Ѵ�.
    *	@pre	�뷡�� ������ ��� �����Ѵ�.
    *	@post	���� �߸Ű �뷡�� �߰��Ѵ�.
    *	@param	item	�뷡�� �߸Ű�.
    */
    void addSong(SingerSong item);

    /**
    *	@brief	���� �߸Ű �뷡�� �����Ѵ�.
    *	@pre	�߸Ű��� ID�� �����Ѵ�.
    *	@post	���� �߸Ű ������ id�� �뷡�� �����Ѵ�.
    *	@param	item	�뷡�� �߸Ű�.
    */
    void deleteSong(SingerSong item);

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

    /**
    *	@brief	'=='�� �������Ѵ�.
    *	@pre	���� '=='���� ���� �Ǿ��ִ�.
    *	@post	'==' ������ �� ������ ����� �� �ִ�.
    *	@return	�ش� ���̽��� TRUE, �׷��� ������ FALSE.
    */
    bool operator==(const SingerType& temp);


private:
    string s_Name; // ���� �̸�
    int s_Age; // ���� ����
    string s_Gender; // ���� ����
    string s_Debut; // ���� ��������
    string s_Born; // ���� �������
    string s_Picture; // ���� ���� ���ϸ�
    UnsortedList<SingerSong> s_SongList; // ���� �߸Ű�
};
