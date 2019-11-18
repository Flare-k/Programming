#include "Application.h"

void textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void Application::RunAdminOrUser()
{
	while (1)
	{
		textcolor(14);
		m_Command = GetCommand();
		switch (m_Command)
		{
		case 1: 
			RunAdmin();
			break;
		case 2:
			RunUser();
			break;
		default:
			break;
		}
	}
}

void Application::RunAdmin()
{
	while (1)
	{
		textcolor(10);
		m_Command_Ad = FirstGetCommand();

		switch (m_Command_Ad)
		{
		case 1:
			AddMusic();
			break;
		case 2:
			DeleteMusic();
			break;
		case 3: 
			ReplaceMusic();
			break;
		case 4: 
			WriteMusicDataToFile();
			break;
		case 5:
			DisplayById_Binary();
			break;
		case 6:
			ReadMusicDataFromFile();
		case 7:
			ReadBestDataFromFile();
			break;
		case 8:
			AddBest();
			break;
		case 9:
			DeleteBest();
			break;
		case 10:
			ReplaceBest();
			break;
		case 11:
			DisplayBestByName();
			break;
		case 12:
			WriteBestDataToFile();
			break;
		case 13:
			DisplayAllBest();
			break;
		default:
			break;
		}
	}
}

void Application::RunUser()
{
	while (1)
	{
		textcolor(11);
		m_Command_User = SecondGetCommand();

		switch (m_Command_User)
		{
		case 1:
			ReadBestDataFromFile();
			break;
		case 2:
			AddRecordToPL();
			break;
		case 3:
			DeletePL();
			break;
		case 4:
			DisplayPL();
			break;
		case 5:
			PlayPL();
			break;
		case 6:
			SearchLyric();
			break;
		default:
			break;
		}
	}
}

int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t=== 1번: 관리자 | 2번: 이용자 === " << endl<< endl;
	cout << "\t	1 : 관리자" << endl;
	cout << "\t	2 : 사용자" << endl;
	cout << endl << "\t숫자를 입력하세요 =====> ";
	
	cin >> command;
	cout << endl;

	return command;
}


int Application::FirstGetCommand()
{
	int command_Ad;
	cout << endl << endl;
	cout << "\t==== (1) 관리자 ver. =================" << endl << endl;
	cout << "\t==== 음원 정보 관리 ==================" << endl;
	cout << "\t1 : 음원 정보 삽입" << endl;
	cout << "\t2 : 음원 정보 삭제" << endl;
	cout << "\t3 : 음원 정보 대체" << endl;
	cout << "\t4 : 음원 정보 .txt에 저장" << endl;
	cout << "\t5 : ID로 음원 정보 불러오기" << endl;
	cout << "\t6 : 전체 음원 정보 .txt로 불러오기" << endl << endl;
	cout << "\t==== 인기 차트 관리 ==================" << endl;
	cout << "\t7 : 현재 인기 차트 .txt로 불러오기" << endl;
	cout << "\t8 : 인기 차트 음원 추가" << endl;
	cout << "\t9 : 인기 차트 음원 삭제" << endl;
	cout << "\t10 : 인기 차트 음원 대체" << endl;
	cout << "\t11 : 곡 명으로 음원 불러오기" << endl;
	cout << "\t12 : 현재 인기 차트 .txt에 저장" << endl;
	cout << "\t13 : 전체 인기 차트 정보 불러오기" << endl;
	cout << "\t		" << endl;
	cout << endl << "\t숫자를 입력하세요 =====> ";

	cin >> command_Ad;
	cout << endl;

	return command_Ad;
}

int Application::SecondGetCommand() // 2번 User인 경우
{
	int command_User;
	cout << endl << endl;
	cout << "\t==== (2) 사용자 ver. =======" << endl << endl;
	cout << "\t인기차트를 보려면 1번을 입력하세요."<< endl;
	cout << endl << "\t==== 재생 목록 관리 ========" << endl;
	cout << "\t1 : 인기 차트 목록 보기" << endl;
	cout << "\t2 : 재생 목록 음원 추가" << endl;
	cout << "\t3 : 재생 목록 음원 삭제" << endl;
	cout << "\t4 : 재생 목록 음원 보기" << endl;
	cout << "\t5 : 재생 목록 음원 재생" << endl;
	cout << "\t==== 가사 검색 ========" << endl;
	cout << "\t6 : 재생 목록 가사 검색" << endl;
	cout << "\t" << endl;
	cout << endl << "\t숫자를 입력하세요 =====> ";

	cin >> command_User;
	cout << endl;

	return command_User;
}

int Application::AddMusic()
{
	MusicType item;

	// 키보드로 음원 정보 입력 받아
	item.SetRecordFromKB();

	// List에 정렬되게 추가
	m_List.Add(item);

	cout << endl;
	cout << "\t=== 추가되었습니다. ===" << endl;

	return 1;
}

int Application::DeleteMusic()
{
	MusicType item;
	// 키보드로 아이디 입력 받아
	item.SetIdFromKB();

	// 해당 아이디 정보 리스트 삭제
	m_List.Delete(item);
	cout << endl;
	cout << "\t=== 삭제되었습니다. ===" << endl;

	return 1;
}

int Application::MakeEmpty()
{
	m_List.MakeEmpty();
	return 1;
}

int Application::ReplaceMusic()
{
	MusicType item;
	item.SetIdFromKB();

	if (m_List.Retrieve_Binary(item))
	{
		// 대체할 데이터 입력 받기
		item.SetRecordFromKB();

		// Replace 함수 사용
		if (m_List.Replace(item))
		{
			item.DisplayRecordOnScreen();
			cout << endl;
			cout << "\t === 대체되었습니다. ===" << endl;
		}
		else
		{
			cout << endl;
			cout << "\t === 실패했습니다. ===" << endl;
		}
	}

	return 0;
}

int Application::DisplayById_Binary()
{
	MusicType item;

	// id 입력 받기
	item.SetIdFromKB();

	// binary search
	if (m_List.Retrieve_Binary(item))
	{
		item.DisplayRecordOnScreen();
		cout << endl;
		cout << "\t=== 음원 정보를 찾았습니다. ===" << endl;
	}
	else
	{
		cout << endl;
		cout << "\t=== 음원 정보를 찾지 못하였습니다. ===" << endl;
	}
	return 1;
}


int Application::DisplayAllMusic()
{
	MusicType item;
	m_List.ResetList();

	int i = m_List.GetNextItem(item);

	// list 데이터 화면에 출력
	while (i != -1 && i < m_List.GetLength()) {
		item.DisplayRecordOnScreen();
		i = m_List.GetNextItem(item);
	}
	return 1;
}

int Application::OpenInFile(char* fileName)
{
	// 파일 읽기
	m_InFile.open(fileName);

	// 성공하면 1, 아니면 0 반환
	if (!m_InFile)
		return 0;
	else
		return 1;

}

int Application::OpenOutFile(char* fileName)
{
	// 파일 읽기
	m_OutFile.open(fileName);

	// 성공하면 1, 아니면 0 반환
	if (!m_OutFile)
		return 0;
	else
		return 1;
}

int Application::ReadMusicDataFromFile()
{
	int index = 0;
	MusicType data;	// 읽기용 임시 변수

	char filename[FILENAMEMAX];
	cout << "\n\t파일 이름 입력 : ";
	cin >> filename;

	if (!OpenInFile(filename))
		return 0;

	while(!m_InFile.eof())
	{ 
		// 파일의 모든 내용을 읽어 list에 추가
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// 현재 list 출력
	DisplayAllMusic();

	return 1;

}

int Application::WriteMusicDataToFile()
{
	char filename1[FILENAMEMAX];
	cin >> filename1;

	if (!OpenOutFile(filename1))
	{
		return 0;
	}

	MusicType item;

	// list pointer 초기화
	m_List.ResetList();

	int curpointer = m_List.GetNextItem(item);

	// list 데이터 전부 파일에 작성
	while (curpointer < m_List.GetLength())
	{
		item.WriteDataToFile(m_OutFile);
		int getItem = m_List.GetNextItem(item);
	}

	// 스트럭쳐 저장
	return 1;
}

int Application::AddBest()
{
	MusicType item;
	BestType best;
	
	item.SetIdFromKB();
	
	// 음원 정보 바이너리하게 서치하여 리스트에 있는지 여부 검사
	if (m_List.Retrieve_Binary(item))
	{
		best.SetIdFromKB();
		best.SetRecord(best.GetId(), item.GetName(), item.GetSinger()); // master list(MusicSorted)의 정보까지 BestSorted에 저장

		m_bestList.Add(best); // 인기 차트에 추가

		cout << "\t=== 인기 차트에 추가 되었습니다. ===" << endl;
	}
	else
	{
		cout << "\t=== 음원 정보가 없습니다. ===" << endl;
	}

	cout << endl;
	best.DisplayRecordOnScreen(); // 리스트에 잘 추가 되었는지 출력

	return 0;
}


int Application::DeleteBest()
{
	BestType item;
	item.SetIdFromKB(); // 키보드로 아이디 입력 받아
	
	m_bestList.Delete(item); // 해당 아이디 정보 리스트 삭제

	cout << endl;
	cout << "\t=== 삭제되었습니다. ===" << endl;

	return 1;
}

int Application::ReplaceBest()
{
	BestType item;
	item.SetIdFromKB();

	if (m_bestList.Retrieve_Binary_Id(item))
	{
		// 대체할 데이터 입력 받기
		item.SetRecordFromKB();

		// Replace 함수 사용
		if (m_bestList.Replace(item))
		{
			item.DisplayRecordOnScreen();
			cout << endl;
			cout << "\t=== 대체되었습니다. ===" << endl;
		}
		else
		{
			cout << endl;
			cout << "\t=== 실패했습니다. ===" << endl;
		}
	}

	return 0;
}

int Application::DisplayAllBest()
{
	BestType item;
	m_bestList.ResetList();

	int i = m_bestList.GetNextItem(item);

	// list 데이터 화면에 출력
	while (i != -1 && i < m_bestList.GetLength()) {
		item.DisplayRecordOnScreen();
		i = m_bestList.GetNextItem(item);
	}
	return 1;

}

int Application::DisplayBestNames()
{
	BestType item;
	m_bestList.ResetList();

	int i = m_bestList.GetNextItem(item);

	// list 데이터 화면에 출력
	while (i != -1 && i < m_bestList.GetLength()) {
		item.DisplayNameOnScreen();
		i = m_bestList.GetNextItem(item);
	}
	return 1;
}

int Application::GetBestByName_Binary(BestType& data)
{
	BestType item;
	
	for (int i = 0; i < m_bestList.GetLength(); i++)
	{
		// 가수 정보 리스트에서 찾기
		if (item.GetName().find(data.GetName()) != -1)
		{
			item.DisplayRecordOnScreen();
			cout << endl;
			cout << "\t=== 해당 곡 정보를 찾았습니다. ===" << endl;
		}
		else
		{
			cout << endl;
			cout << "\t=== 해당 곡 정보를 찾지 못했습니다. ====" << endl;
		}
	}

	return 0;
}
int Application::DisplayBestByName()
{
	MusicType item;
	BestType best;

	best.SetNameFromKB();
	best.GetName() = item.GetName();

	if (m_bestList.Retrieve_Binary_Name(best))
	{
		best.DisplayRecordOnScreen(); // 리스트에 잘 추가 되었는지 출력
	}
	else
	{
		cout << "\t=== 음원 정보가 인기 차트에 없습니다. ===" << endl;
	}

	cout << endl;
	
	return 0;
}

int Application::WriteBestDataToFile()
{
	char filename2[FILENAMEMAX];
	cin >> filename2;

	if (!OpenOutFile(filename2))
	{
		return 0;
	}

	BestType item;

	// list pointer 초기화
	m_bestList.ResetList();

	int curpointer = m_bestList.GetNextItem(item);

	// list 데이터 전부 파일에 작성
	while (curpointer < m_bestList.GetLength())
	{
		item.WriteDataToFile(m_OutFile);
		int getItem = m_bestList.GetNextItem(item);
	}

	// 스트럭쳐 저장
	return 1;
}

int Application::ReadBestDataFromFile()
{
	char filename2[FILENAMEMAX];
	cin >> filename2;

	// 파일이 열리지 않는 경우 "Cannot Open" 출력
	if (!OpenInFile(filename2))
	{
		cout << endl;
		cout << "\t=== 열 수 없습니다. ===" << endl;
	}
	else
	{
		BestType item;
		m_bestList.ResetList();
		// 파일에 음원 정보 저장
		item.ReadDataFromFile(m_InFile);
		m_bestList.Add(item);

	}
		DisplayAllBest();
		cout << endl;
		cout << "\t=== 음원 정보 가져오기 완료 ===" << endl;

	// 파일 닫기
	m_InFile.close();

	return 1;
}

int Application::AddRecordToPL()
{
	PlayType item;	
	item.SetNamePLByKB();

	m_playList.EnQueue(item);
	cout << endl;
	cout << "\t=== 재생 목록에 추가되었습니다. ===" << endl << endl;

	item.DisplayPLNameOnScreen();

	return 0;
}

int Application::DeletePL()
{
	PlayType item;		//main에서 Application으로 선언된 자료형의 변수하나 생성
	item.SetNamePLByKB();

	m_playList.DeQueue(item);
	
	return 0;
}

int Application::DisplayPL()
{
	PlayType item;
	item.SetNamePLByKB();

	m_playList.ResetList();

	if (m_playList.IsEmpty() == true)
		cout << "\t=== 재생 목록이 비었습니다. ===" << endl;
	else
	{
		for (int i = 0; i < m_playList.Top(); i++)
		{
			m_playList.GetNextitem(item);
			item.DisplayPLNameOnScreen();
			cout << endl;
		}
	}
	return 0;
}

int Application::PlayPL() 
{
	PlayType play;

	play.SetNamePLByKB();

	if (m_playList.Search(play))
	{
		SearchLyric();
	}
	
	return 0;
}

int Application::SearchLyric()
{
	char filename3[FILENAMEMAX];
	cin >> filename3;

	// 파일이 열리지 않는 경우 "Cannot Open" 출력
	if (!OpenInFile(filename3))
	{
		cout << endl;
		cout << "\t=== 열 수 없습니다. ===" << endl;
	}
	else
	{
		LyricType item;
		m_lyricList.ResetList();
		// 파일에 음원 정보 저장
		item.ReadDataFromFile(m_InFile);
		m_lyricList.Add(item);
		item.DisplayPLLyricOnScreen();
	}
	
	cout << endl;
	cout << "\t=== 음원 정보 가져오기 완료 ===" << endl;

	// 파일 닫기
	m_InFile.close();

	return 1;
}


