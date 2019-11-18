#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include "BestSorted.h"
#include "BestType.h"
#include "LyricList.h"
#include "LyricType.h"
#include "MusicSorted.h"
#include "MusicType.h"
#include "PlayQueue.h"
#include "PlayType.h"

#define FILENAMEMAX 100000

using namespace std;

class Application
{
public:
	// 1: Admin 2: User 중 택 1
	void RunAdminOrUser(); // 옵션 실행
	int GetCommand(); // 키보드로 옵션 받기

	void RunAdmin(); // Admin 옵션 실행
	void RunUser(); // User 옵션 실행

	int FirstGetCommand(); // 1번 Admin인 경우 음원 정보 및 인기차트 관리용 키보드 받기
	int SecondGetCommand(); // 2번 User인 경우 재생 목록 관리용 키보드 받기

	// 1. Admin (전체 음원 정보 관리 & 인기 차트 관리)
	// 음원 정보 관리
	int AddMusic(); // 음원 정보 추가
	int DeleteMusic(); // id 일치하는 음원 삭제
	int ReplaceMusic(); // id 일치하는 음원 정보 키보드로 입력 받은 음원 정보로 바꾸기 
	int DisplayById_Binary(); // list에서 id binary하게 찾기
	int DisplayAllMusic(); // 모든 음원 정보 화면에 출력
	int MakeEmpty(); // 모든 음원 정보 삭제
	int ReadMusicDataFromFile(); // 키보드로 입력받은 파일 이름과 일치하는 파일 불러오기
	int WriteMusicDataToFile(); // 음원 정보 입력한 파일 이름으로 파일에 저장하기
	
	// 인기 차트 관리
	int AddBest(); //곡 명으로 음원 추가
	int DeleteBest(); // 곡 명과 일치하는 음원 삭제
	int ReplaceBest(); // 곡 명과 일치하는 음원 정보 키보드로 입력 받은 뒤 바꾸기
	int GetBestByName_Binary(BestType& data); // 인기 차트 이름만 출력
	int DisplayBestByName(); // 인기 차트의 곡 명으로 찾아서 출력
	int DisplayAllBest(); // 인기 차트 리스트 정보 전부 출력
	int WriteBestDataToFile(); // 음원 정보 입력한 파일 이름으로 파일에 저장하기 
	int ReadBestDataFromFile(); //  키보드로 입력받은 파일 이름과 일치하는 파일 불러오기
	
	int OpenInFile(char* fileName); // 파일 열기
	int OpenOutFile(char* fileName); // 파일 쓰기

	// 2. User (재생 목록 관리 & 가사 검색)
	int DisplayBestNames(); // 인기 차트의 곡 명으로 찾아서 출력
	int AddRecordToPL(); // Id를 키보트로부터 읽어서 list class의 멤버 함수를 이용하여 list에서 찾고 찾은 레코드 PlayList Enque추가
	int DeletePL(); // 키보드로부터 Id를 읽어서 해당 레코드를 PL에서 찾아서 삭제
	int DisplayPL(); // PlayList에 저장된 항목을 화면에 출력
	int PlayPL(); // 재생목록 곡 들어간 순서대로 재생
	int SearchLyric();// 재생 목록 곡에서 가사 검색 (가사가 담긴 텍스트는 미리 폴더에 저장되어 있음)
	
private:

	MusicSorted<MusicType> m_List; // 음원 리스트	
	BestSorted<BestType> m_bestList; // 인기 차트 리스트
	PlayList<PlayType> m_playList; // 재생 목록
	LyricList<LyricType> m_lyricList; // 가사 저장 리스트
	
	ifstream m_InFile; ///< input file descriptor.
	ofstream m_OutFile; ///< output file descriptor.
	int m_Command = 0; // 커멘드 받기
	int m_Command_Ad = 0; // Admin 커맨드 받기
	int m_Command_User = 0; // User 커맨드 받기
};