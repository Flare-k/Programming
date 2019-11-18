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
    *	����Ʈ ������
    */
    MusicType();

    /**
    *   ������
    */
    MusicType(int in_id);

    /**
    *   �Ҹ���
    */
    ~MusicType();

    /**
    *	@brief	�뷡 type�� �����´�.
    *	@pre	�뷡 type�� �����Ѵ�.
    *	@post	����.
    *	@return	�뷡 type.
    */
    string GetType();

    /**
    *	@brief	�뷡 name�� �����´�.
    *	@pre	�뷡 name�� �����Ѵ�.
    *	@post	����.
    *	@return	�뷡 name.
    */
	string GetName();

    /**
    *	@brief	�뷡 composer�� �����´�.
    *	@pre	�뷡 composer�� �����Ѵ�.
    *	@post	����.
    *	@return	�뷡 composer.
    */
	string GetComposer();

    /**
    *	@brief	�뷡 artist�� �����´�.
    *	@pre	�뷡 artist�� �����Ѵ�.
    *	@post	����.
    *	@return	�뷡 artist.
    */
	string GetArtist();

    /**
    *	@brief	�뷡 genre�� �����´�.
    *	@pre	�뷡 genre�� �����Ѵ�.
    *	@post	����.
    *	@return	�뷡 genre.
    */
	string GetGenre();

    /**
    *	@brief	�뷡 lyrics�� �����´�.
    *	@pre	�뷡 lyrics�� �����Ѵ�.
    *	@post	����.
    *	@return	�뷡 lyrics.
    */
    string GetLyrics();

    /**
    *	@brief	�뷡 album cover filename�� �����´�.
    *	@pre	�뷡 album cover filename�� �����Ѵ�.
    *	@post	����.
    *	@return	�뷡 album cover.
    */
    string GetAlbumcover();

    /**
    *	@brief	�뷡 ID�� �����´�.
    *	@pre	�뷡 ID�� �����Ѵ�.
    *	@post	����.
    *	@return	�뷡 ID.
    */
	int GetId();
	
    /**
    *	@brief	�뷡�� type�� �����Ѵ�.
    *	@pre	����.
    *	@post	�뷡�� type�� �����Ѵ�.
    *	@param	inType	�뷡�� type.
    */
    void SetType(string inType);

    /**
    *	@brief	�뷡�� name�� �����Ѵ�.
    *	@pre	����.
    *	@post	�뷡�� name�� �����Ѵ�.
    *	@param	inName	�뷡�� ����.
    */
	void SetName(string inName);

    /**
    *	@brief	�뷡�� composer�� �����Ѵ�.
    *	@pre	����.
    *	@post	�뷡�� composer�� �����Ѵ�.
    *	@param	inComposer	�뷡�� composer �̸�.
    */
	void SetComposer(string inComposer);

    /**
    *	@brief	�뷡�� type�� �����Ѵ�.
    *	@pre	����.
    *	@post	�뷡�� type�� �����Ѵ�.
    *	@param	inArtist	�뷡�� aritst �̸�.
    */
	void SetArtist(string inArtist);

    /**
    *	@brief	�뷡�� genre�� �����Ѵ�.
    *	@pre	����.
    *	@post	�뷡�� genre�� �����Ѵ�.
    *	@param	inGenre	�뷡�� �帣.
    */
    void SetGenre(string inGenre);

    /**
    *	@brief	�뷡�� ���� ID �����Ѵ�.
    *	@pre	����.
    *	@post	�뷡�� ID �����Ѵ�.
    *	@param	inId	�뷡�� ID.
    */
    void SetId(int inId);

    /**
    *	@brief	�뷡�� ���縦 �����Ѵ�.
    *	@pre	����.
    *	@post	�뷡�� lyrics �����Ѵ�.
    *	@param	inLyrics	�뷡�� lyrics.
    */
    void SetLyrics(string inLyrics);

    /**
    *	@brief	�뷡�� ���ڵ带 �����Ѵ�.
    *	@pre	����.
    *	@post	�뷡�� ���ڵ带 �����Ѵ�.
    *	@param	inType	�뷡�� type.
    *   @param	inName	�뷡�� ����.
    *   @param	inComposer	�뷡�� �۰��.
    *   @param	inArtist	�뷡�� ��Ƽ��Ʈ��.
    *   @param	inGenre	�뷡�� �帣.
    *   @param	inId	�뷡�� ID.
    */
    void SetRecord(string inType, string inName, string inComposer, string inArtist, string inGenre, int inId);

    /**
    *	@brief	�뷡�� �ٹ�Ŀ�� �����Ѵ�.
    *	@pre	����.
    *	@post	�뷡�� �ٹ�Ŀ�� �����Ѵ�.
    *	@param	inAlbumcover    �뷡�� album cover filename.
    */
    void SetAlbumcover(string inAlbumcover);

    /**
    *	@brief	���Ϸκ��� �뷡�� ��� ������ �о�´�.
    *	@pre	������ ������ ����.
    *	@post	�뷡�� ��� ������ �����Ѵ�.
    *	@param	fin	���� ��ũ����.
    *	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
    */
	int ReadDataFromFile(ifstream& fin);

    /**
    *	@brief	���Ͽ� �뷡�� ��� ������ ����.
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
    bool operator==(MusicType temp);

    /**
    *	@brief	'>'�� �������Ѵ�.
    *	@pre	���� '>'���� ���� �Ǿ��ִ�.
    *	@post	'>' ������ �� ������ ����� �� �ִ�.
    *	@return	�ش� ���̽��� TRUE, �׷��� ������ FALSE.
    */
    bool operator>(MusicType temp);

    /**
    *	@brief	'<'�� �������Ѵ�.
    *	@pre	���� '<'���� ���� �Ǿ��ִ�.
    *	@post	'<' ������ �� ������ ����� �� �ִ�.
    *	@return	�ش� ���̽��� TRUE, �׷��� ������ FALSE.
    */
    bool operator<(MusicType temp);

private:
    int m_Id; // �� ID
    string m_Type; // �� Ÿ��(���ְ�, �뷡)
    string m_Name; // �� ����
    string m_Composer; // �۰
    string m_Artist; // ������
    string m_Genre; // �帣��
    string m_Lyrics; //����
    string m_Albumcover; // �ٹ�Ŀ�� ���ϸ�

};
