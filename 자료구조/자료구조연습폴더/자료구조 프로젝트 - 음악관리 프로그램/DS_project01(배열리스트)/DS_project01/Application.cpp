#include "Application.h"


Application::Application()
{
	m_CurCommand = 0;
	ReadMusicListFromFile();
}

Application::~Application()
{
	WriteMusicListToFile();
}


//===================================================================================
// Function: Program driver
// Pre: none
// Post : none
//===================================================================================
void Application::Run()
{
	while(1)
	{
		m_CurCommand = GetCommand(); //�޴��κ��� ����� �޾ƿ�

		switch(m_CurCommand)
		{
		case 1:		
			AddMusic();			//���Ǹ���Ʈ�� ���� �߰�
			break;	
		case 2:		
			DeleteMusic();		//���Ǹ���Ʈ���� ���� ����
			break;
		case 3:		
			ModifyMusic();		//���Ǹ���Ʈ�� ���� ����
			break;
		case 4:		
			DisplayAllMusic();	//���Ǹ���Ʈ ��� ���
			break;
		case 5:		
			AddPlayList();		//�����Ͽ� �߰�
			break;
		case 6:		
			ShowPlayList();		//������ ���
			break;
		case 7:		
			RetrieveRecordByMusicName();	//�����̸����� �˻�
			break;
		case 8:		
			RetrieveRecordByArtistName();	//��Ƽ��Ʈ �̸����� �˻�
			break;
		case 9:		
			RetrieveRecordByGenre();		//�帣�� �˻�
			break;
		case 10:
			RetrieveRecordByReleaseDate();	//�߸űⰣ���� �˻�
			break;
		case 11:
			PlayMusic();		//�����Ͽ� �ִ� ������ �÷���
 			break;
		case 0:					//���α׷� ����
			return;
		default:
			cout << "\t�޴��� �߸� �Է��ϼ̽��ϴ�!!!\n";
			break;
		}
	}
}

//===================================================================================
// Function: Display command on screen and get a input from keyboard
// Pre: none
// Post : return command number.
//===================================================================================
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : ���� �߰� " << endl;
	cout << "\t   2 : ���� ���� " << endl;
	cout << "\t   3 : ���� ���� " << endl;
	cout << "\t   4 : ���� ����Ʈ ��ü ���� " << endl;
	cout << "\t   5 : �����Ͽ� �߰� " << endl;
	cout << "\t   6 : ������ ���� " << endl;
	cout << "\t   7 : ���� �̸����� �˻� " << endl;
	cout << "\t   8 : ��Ƽ��Ʈ �̸����� �˻� " << endl;
	cout << "\t   9 : �帣�� �˻� " << endl;
	cout << "\t   10: �߸� �Ⱓ���� �˻� " << endl;
	cout << "\t   11: Music Play " << endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

//===================================================================================
// Function: Add new Music record to list
// Pre: 
// Post : list is added new Music record. if list is full, do not add the record to list and return 0, Otherwise return 1
//===================================================================================
int Application::AddMusic()
{
	ItemType newData;
		
	cin.ignore();
	cin.clear();

	newData.GetRecordFromKB(); //�� ���ڵ带 Ű����� �Է¹���

	// �Է¹��� ���ڵ带 ����Ʈ�� add, ����Ʈ�� full�� ���� add���� �ʰ� 0�� ����
	if(!m_MusicList.IsFull())	
		m_MusicList.Add(newData);
	else	
		return 0;

	// ���� list ���
	//DisplayAllMusics();

	return 1;
}

//===================================================================================
// Function: Delete a Music record in list
// Pre: 
// Post : list is deleted a Music record.
//===================================================================================
int Application::DeleteMusic()
{
	ItemType target;
	
	cin.ignore();
	cin.clear();
	
	target.GetMusicNameFromKB();	// ������ ����� ã�� ���� �����̸� �Է�
	m_MusicList.Delete(target);	//�ش� Music ���ڵ� ����
	cout << "\t�ش� ������ �����߽��ϴ�." << endl;

	return 1;
}

//===================================================================================
// Function: Modify a Music record in list
// Pre: 
// Post : list is modified a Music record.
//===================================================================================
int Application::ModifyMusic()
{
	ItemType target;

	cin.ignore();
	cin.clear();

	target.GetRecordFromKB();	// ������ ����� �˻��ϰ� �����ϱ� ���� ���ڵ� �Է�
	m_MusicList.Replace(target);	// Music ���ڵ� ����

	return 1;
}

//===================================================================================
// Function: Search a Music by music name
// Pre: inData contains the music name to be searched
// Post : inData holds the record matched with input music name. If found, return 1. Otherwise 0
//===================================================================================
int Application::SearchListByMusicName(ItemType& inData)
{
	ItemType data; // �񱳸� ���� list pointer�� ���� �����ϴ� ����
	int sw = 0;

	// list �����͸� �ʱ�ȭ
	m_MusicList.ResetList();

	while(m_MusicList.GetNextItem(data) < m_MusicList.GetLength())
	{
		// �̸��� ���� ���ڵ尡 �����ϸ� �� ���ڵ带 �����ϰ� 1�� ����
		if(data.GetMusicName().find(inData.GetMusicName()) != -1)
		{
			data.PutRecordOnScreen();
			sw = 1;
		}
	}

	return sw;
}

//===================================================================================
// Function: Search a Music by artist name
// Pre: inData contains the artist name to be searched
// Post : inData holds the record matched with input artist name. If found, return 1. Otherwise 0
//===================================================================================
int Application::SearchListByArtistName(ItemType& inData)
{
	ItemType data; // �񱳸� ���� list pointer�� ���� �����ϴ� ����
	int sw = 0;

	// list �����͸� �ʱ�ȭ
	m_MusicList.ResetList();

	while(m_MusicList.GetNextItem(data) < m_MusicList.GetLength())
	{
		// �̸��� ���� ���ڵ尡 �����ϸ� �� ���ڵ带 �����ϰ� 1�� ����
		if(data.GetArtistName().find(inData.GetArtistName()) != -1)
		{
			data.PutRecordOnScreen();
			sw = 1;
		}
	}

	return sw;
}


//===================================================================================
// Function: Search a Music by genre
// Pre: inData contains the genre to be searched
// Post : inData holds the record matched with input genre. If found, return 1. Otherwise 0
//===================================================================================
int Application::SearchListByGenre(ItemType& inData)
{
	ItemType data; // �񱳸� ���� list pointer�� ���� �����ϴ� ����
	int sw = 0;

	// list �����͸� �ʱ�ȭ
	m_MusicList.ResetList();

	while(m_MusicList.GetNextItem(data) < m_MusicList.GetLength())
	{
		// �̸��� ���� ���ڵ尡 �����ϸ� �� ���ڵ带 �����ϰ� 1�� ����
		if(data.GetGenre().find(inData.GetGenre()) != -1)
		{
			data.PutRecordOnScreen();
			sw = 1;
		}
	}

	return sw;
}


//===================================================================================
// Function: Search a Music by release date
// Pre: inData contains the release date to be searched
// Post : inData holds the record matched with input release date. If found, return 1. Otherwise 0
//===================================================================================
int Application::SearchListByReleaseDate(ItemType& inData1, ItemType& inData2, ItemType& returnData)
{
	ItemType data; // �񱳸� ���� ����Ʈ �������� ���� �����ϴ� ����

	while(m_MusicList.GetNextItem(data) < m_MusicList.GetLength())
	{
		if ((inData1.GetReleaseDate() <= data.GetReleaseDate()) && (data.GetReleaseDate() <= inData2.GetReleaseDate()))
		{
			returnData.CopyRecord(data);
			return 1;
		}
	}

	return 0;
}


//===================================================================================
// Function: Read in a music name from keyboard, search the record by music name, 
//			and display on the screen
// Pre: none
// Post : record on screen. If found, return 1. Otherwise 0
//===================================================================================
int Application::RetrieveRecordByMusicName()
{
	ItemType target; // ã���� �ϴ� ���ڵ带 ���� ��������
		
	cin.ignore();
	cin.clear();

	target.GetMusicNameFromKB(); // Ű����κ��� ã���� �ϴ� ���ڵ� �Է¹���
	cout << "\t--------------------" << endl;
	
	// ã���� �ϴ� ���ڵ尡 ����Ʈ�� ������ ȭ�鿡 ����ϰ� 1
	if(SearchListByMusicName(target))
	{
		return 1;
	}
	else
	{
		cout << "\tDo not find" << endl;
		return 0;
	}

	return 0;
}

//===================================================================================
// Function: Read in artist name from keyboard, search the record by artist name, and display on the screen
// Pre: none
// Post : record on screen. If found, return 1. Otherwise 0
//===================================================================================
int Application::RetrieveRecordByArtistName()
{
	ItemType target; // ã���� �ϴ� ���ڵ带 ���� ��������
		
	cin.ignore();
	cin.clear();
	
	target.GetArtistNameFromKB(); // Ű����κ��� ã���� �ϴ� ���ڵ� �Է¹���
	cout << "\t--------------------" << endl;

	// ã���� �ϴ� ���ڵ尡 ����Ʈ�� ������ ȭ�鿡 ����ϰ� 1
	if(SearchListByArtistName(target))
	{
		return 1;
	}
	else
	{
		cout << "\tDo not find" << endl;
		return 0;
	}

	return 0;
}

//===================================================================================
// Function: Read in genre from keyboard, search the record by genre, and display on the screen
// Pre: none
// Post : record on screen. If found, return 1. Otherwise 0
//===================================================================================
int Application::RetrieveRecordByGenre()
{
	ItemType target; // ã���� �ϴ� ���ڵ带 ���� ��������
		
	cin.ignore();
	cin.clear();
	
	target.GetGenreFromKB(); // Ű����κ��� ã���� �ϴ� ���ڵ� �Է¹���
	cout << "\t--------------------" << endl;

	// ã���� �ϴ� ���ڵ尡 ����Ʈ�� ������ ȭ�鿡 ����ϰ� 1
	if(SearchListByGenre(target))
	{
		return 1;
	}
	else
	{
		cout << "\tDo not find" << endl;
		return 0;
	}

	return 0;
}


//===================================================================================
// Function: Read in release date from keyboard, search the record by release date, 
//			and display on the screen
// Pre: none
// Post : record on screen. If found, return 1. Otherwise 0
//===================================================================================
int Application::RetrieveRecordByReleaseDate()
{
	ItemType target1, target2, returnData; //���۳�¥, ����¥, �񱳳�¥



	cout << "\t���� �߸� �Ⱓ���� �˻��ϴ� ����Դϴ�." << endl;
	cout << "\t�˻��� ���� ��¥�� �Է����ּ���" << endl;
	
	cin.ignore();
	cin.clear();

	target1.GetReleaseDateFromKB();
	cout << "\t�˻��� �� ��¥�� �Է����ּ���" << endl;
	target2.GetReleaseDateFromKB();
	cout << "\t----------------------------------------" << endl;

	int sw = 0;
	this->m_MusicList.ResetList();

	while(SearchListByReleaseDate(target1,target2, returnData))
	{
		returnData.PutRecordOnScreen();
		sw=1;
	}
	if(sw==0)
	{
		cout << "\tNo data in the list.." << endl;
		return 0;
	}
	return 1;

}


//===================================================================================
// Function: Display all record in the Music list on screen
// Pre: 
// Post : Music records on screen
//===================================================================================
void Application::DisplayAllMusic()
{
	ItemType data;

	m_MusicList.ResetList();

	cout << "\n\tCurrent list" << endl;
	// list�� ��� �����͸� ȭ�鿡 ���
	int length = m_MusicList.GetLength();
	int curIndex = m_MusicList.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.PutRecordOnScreen();
		curIndex = m_MusicList.GetNextItem(data);
	}
}

//===================================================================================
// Function: Open an input file
// Pre: name should be valid
// Post: m_InFile holds input file information. 
//       if file open error occur, return 0. Otherwise return 1
//===================================================================================
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName, ios::app);	// file open for read

	// if file open error occur, return 0. Otherwise return 1
	if(!m_InFile)
		return 0;
	else
		return 1;
}

//===================================================================================
// Function: Open an output file
// Pre: name should be valid
// Post: m_OutFile holds output file information. 
//       if file open error occur, return 0. Otherwise return 1
//===================================================================================
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName, ios::trunc);	// file open for write

	// if file open error occur, return 0. Otherwise return 1
	if(!m_OutFile)
		return 0;
	else
		return 1;
}

//===================================================================================
// Function: Open an input file and read all the Music record from a file
// Pre: file is not opened
// Post: studeList holds all Music records read from a file. The m_InFile is closed
//       if file open error or file read error occur, return 0. Otherwise return 1
//===================================================================================
int Application::ReadMusicListFromFile()
{
	int index = 0;
	ItemType data;	// �б�� �ӽ� ����

	/*
	//������ �������� ����
	char filename[80];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;
	*/

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenInFile("MusicList.txt"))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while(!m_InFile.eof())
	{
		//array�� �л����� ������ ����ִ� structure ����
		data.GetRecordFromFile(m_InFile);
		m_MusicList.Add(data);
		m_InFile.ignore();
	}

	m_InFile.close();	// file close


	return 1;
}

//===================================================================================
// Function: Open an output file and write all Music records to the file
// Pre: None
// Post: the Music list is stored in the output file
//       if file open error or file write error occur, return 0. Otherwise return 1
//===================================================================================
int Application::WriteMusicListToFile()
{
	ItemType data;	// ����� �ӽ� ����

	/*
	//������ �������� ����
	char filename[80];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;
	*/

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenOutFile("MusicList.txt"))
		return 0;

	// list �����͸� �ʱ�ȭ
	m_MusicList.ResetList();

	// list�� ��� �����͸� ���Ͽ� ����
	int length = m_MusicList.GetLength();
	int curIndex = m_MusicList.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.PutRecordToFile(m_OutFile);
		curIndex = m_MusicList.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}


//===================================================================================
// Function: Play music and display the play list
// Pre: m_PlayList contains music list
// Post: play the music and add the playing date to record
//===================================================================================
void Application::PlayMusic()
{
	ItemType inData;

	do
	{
		system("cls");
		cout << endl << "\t======���� ���=======" << endl << endl;
		cout << "\t���� ������� ����===>>";
		this->m_PlayList.Print();
		cout << "\t=============================" << endl;
		m_PlayList.DeQueue(inData);
		inData.GetDateFromKB();

		this->m_MusicList.Replace(inData);
		
		cout << "���� ������ ����Ϸ��� �ƹ�Ű�� �����ʽÿ�!" << endl;
		system("pause>null"); //"����Ϸ��� �ƹ�Ű�� �����ÿ�" �޼��� ���� 

	}while(!m_PlayList.IsEmpty());
}


//===================================================================================
// Function: add music to play list(queue)
// Pre: none
// Post: enqueue the music to play list queue
//===================================================================================
void Application::AddPlayList()
{
	ItemType target;
	
	cin.ignore();
	cin.clear();
	
	cout << "\t�����Ͽ� �߰��� ������ �̸��� �Է����ּ���." << endl;
	target.GetMusicNameFromKB();	// �����Ͽ� �߰��� ������ �Է¹���
	
	cout << "-----------------------------------------------" << endl;
	
	ItemType data; //�ӽú��� ����

	if(m_MusicList.Get(target)) //����� ã��
	{
		this->m_PlayList.EnQueue(target); //ã�� ����� �����Ͽ� enqueue
		cout << "\t�ش� ������ �����Ͽ� �߰��Ͽ����ϴ�." << endl;
	}
	else
	{
		cout << "\tNot found record in the list.." << endl;
	
	}
}


//===================================================================================
// Function: Display the play list
// Pre: none
// Post: 
//===================================================================================
void Application::ShowPlayList()
{
	if(!m_PlayList.IsEmpty())
	{
		this->m_PlayList.Print();
	}
	else
	{
		cout << "\t�������� ����ֽ��ϴ�. ���ϴ� ������ �����Ͽ� �߰������ּ���" << endl;
		cout << "\t-----------------------------------------------------------------" << endl << endl;
	}
	
}