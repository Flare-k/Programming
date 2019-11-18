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
	cout << "\t=== 1��: ������ | 2��: �̿��� === " << endl<< endl;
	cout << "\t	1 : ������" << endl;
	cout << "\t	2 : �����" << endl;
	cout << endl << "\t���ڸ� �Է��ϼ��� =====> ";
	
	cin >> command;
	cout << endl;

	return command;
}


int Application::FirstGetCommand()
{
	int command_Ad;
	cout << endl << endl;
	cout << "\t==== (1) ������ ver. =================" << endl << endl;
	cout << "\t==== ���� ���� ���� ==================" << endl;
	cout << "\t1 : ���� ���� ����" << endl;
	cout << "\t2 : ���� ���� ����" << endl;
	cout << "\t3 : ���� ���� ��ü" << endl;
	cout << "\t4 : ���� ���� .txt�� ����" << endl;
	cout << "\t5 : ID�� ���� ���� �ҷ�����" << endl;
	cout << "\t6 : ��ü ���� ���� .txt�� �ҷ�����" << endl << endl;
	cout << "\t==== �α� ��Ʈ ���� ==================" << endl;
	cout << "\t7 : ���� �α� ��Ʈ .txt�� �ҷ�����" << endl;
	cout << "\t8 : �α� ��Ʈ ���� �߰�" << endl;
	cout << "\t9 : �α� ��Ʈ ���� ����" << endl;
	cout << "\t10 : �α� ��Ʈ ���� ��ü" << endl;
	cout << "\t11 : �� ������ ���� �ҷ�����" << endl;
	cout << "\t12 : ���� �α� ��Ʈ .txt�� ����" << endl;
	cout << "\t13 : ��ü �α� ��Ʈ ���� �ҷ�����" << endl;
	cout << "\t		" << endl;
	cout << endl << "\t���ڸ� �Է��ϼ��� =====> ";

	cin >> command_Ad;
	cout << endl;

	return command_Ad;
}

int Application::SecondGetCommand() // 2�� User�� ���
{
	int command_User;
	cout << endl << endl;
	cout << "\t==== (2) ����� ver. =======" << endl << endl;
	cout << "\t�α���Ʈ�� ������ 1���� �Է��ϼ���."<< endl;
	cout << endl << "\t==== ��� ��� ���� ========" << endl;
	cout << "\t1 : �α� ��Ʈ ��� ����" << endl;
	cout << "\t2 : ��� ��� ���� �߰�" << endl;
	cout << "\t3 : ��� ��� ���� ����" << endl;
	cout << "\t4 : ��� ��� ���� ����" << endl;
	cout << "\t5 : ��� ��� ���� ���" << endl;
	cout << "\t==== ���� �˻� ========" << endl;
	cout << "\t6 : ��� ��� ���� �˻�" << endl;
	cout << "\t" << endl;
	cout << endl << "\t���ڸ� �Է��ϼ��� =====> ";

	cin >> command_User;
	cout << endl;

	return command_User;
}

int Application::AddMusic()
{
	MusicType item;

	// Ű����� ���� ���� �Է� �޾�
	item.SetRecordFromKB();

	// List�� ���ĵǰ� �߰�
	m_List.Add(item);

	cout << endl;
	cout << "\t=== �߰��Ǿ����ϴ�. ===" << endl;

	return 1;
}

int Application::DeleteMusic()
{
	MusicType item;
	// Ű����� ���̵� �Է� �޾�
	item.SetIdFromKB();

	// �ش� ���̵� ���� ����Ʈ ����
	m_List.Delete(item);
	cout << endl;
	cout << "\t=== �����Ǿ����ϴ�. ===" << endl;

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
		// ��ü�� ������ �Է� �ޱ�
		item.SetRecordFromKB();

		// Replace �Լ� ���
		if (m_List.Replace(item))
		{
			item.DisplayRecordOnScreen();
			cout << endl;
			cout << "\t === ��ü�Ǿ����ϴ�. ===" << endl;
		}
		else
		{
			cout << endl;
			cout << "\t === �����߽��ϴ�. ===" << endl;
		}
	}

	return 0;
}

int Application::DisplayById_Binary()
{
	MusicType item;

	// id �Է� �ޱ�
	item.SetIdFromKB();

	// binary search
	if (m_List.Retrieve_Binary(item))
	{
		item.DisplayRecordOnScreen();
		cout << endl;
		cout << "\t=== ���� ������ ã�ҽ��ϴ�. ===" << endl;
	}
	else
	{
		cout << endl;
		cout << "\t=== ���� ������ ã�� ���Ͽ����ϴ�. ===" << endl;
	}
	return 1;
}


int Application::DisplayAllMusic()
{
	MusicType item;
	m_List.ResetList();

	int i = m_List.GetNextItem(item);

	// list ������ ȭ�鿡 ���
	while (i != -1 && i < m_List.GetLength()) {
		item.DisplayRecordOnScreen();
		i = m_List.GetNextItem(item);
	}
	return 1;
}

int Application::OpenInFile(char* fileName)
{
	// ���� �б�
	m_InFile.open(fileName);

	// �����ϸ� 1, �ƴϸ� 0 ��ȯ
	if (!m_InFile)
		return 0;
	else
		return 1;

}

int Application::OpenOutFile(char* fileName)
{
	// ���� �б�
	m_OutFile.open(fileName);

	// �����ϸ� 1, �ƴϸ� 0 ��ȯ
	if (!m_OutFile)
		return 0;
	else
		return 1;
}

int Application::ReadMusicDataFromFile()
{
	int index = 0;
	MusicType data;	// �б�� �ӽ� ����

	char filename[FILENAMEMAX];
	cout << "\n\t���� �̸� �Է� : ";
	cin >> filename;

	if (!OpenInFile(filename))
		return 0;

	while(!m_InFile.eof())
	{ 
		// ������ ��� ������ �о� list�� �߰�
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// ���� list ���
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

	// list pointer �ʱ�ȭ
	m_List.ResetList();

	int curpointer = m_List.GetNextItem(item);

	// list ������ ���� ���Ͽ� �ۼ�
	while (curpointer < m_List.GetLength())
	{
		item.WriteDataToFile(m_OutFile);
		int getItem = m_List.GetNextItem(item);
	}

	// ��Ʈ���� ����
	return 1;
}

int Application::AddBest()
{
	MusicType item;
	BestType best;
	
	item.SetIdFromKB();
	
	// ���� ���� ���̳ʸ��ϰ� ��ġ�Ͽ� ����Ʈ�� �ִ��� ���� �˻�
	if (m_List.Retrieve_Binary(item))
	{
		best.SetIdFromKB();
		best.SetRecord(best.GetId(), item.GetName(), item.GetSinger()); // master list(MusicSorted)�� �������� BestSorted�� ����

		m_bestList.Add(best); // �α� ��Ʈ�� �߰�

		cout << "\t=== �α� ��Ʈ�� �߰� �Ǿ����ϴ�. ===" << endl;
	}
	else
	{
		cout << "\t=== ���� ������ �����ϴ�. ===" << endl;
	}

	cout << endl;
	best.DisplayRecordOnScreen(); // ����Ʈ�� �� �߰� �Ǿ����� ���

	return 0;
}


int Application::DeleteBest()
{
	BestType item;
	item.SetIdFromKB(); // Ű����� ���̵� �Է� �޾�
	
	m_bestList.Delete(item); // �ش� ���̵� ���� ����Ʈ ����

	cout << endl;
	cout << "\t=== �����Ǿ����ϴ�. ===" << endl;

	return 1;
}

int Application::ReplaceBest()
{
	BestType item;
	item.SetIdFromKB();

	if (m_bestList.Retrieve_Binary_Id(item))
	{
		// ��ü�� ������ �Է� �ޱ�
		item.SetRecordFromKB();

		// Replace �Լ� ���
		if (m_bestList.Replace(item))
		{
			item.DisplayRecordOnScreen();
			cout << endl;
			cout << "\t=== ��ü�Ǿ����ϴ�. ===" << endl;
		}
		else
		{
			cout << endl;
			cout << "\t=== �����߽��ϴ�. ===" << endl;
		}
	}

	return 0;
}

int Application::DisplayAllBest()
{
	BestType item;
	m_bestList.ResetList();

	int i = m_bestList.GetNextItem(item);

	// list ������ ȭ�鿡 ���
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

	// list ������ ȭ�鿡 ���
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
		// ���� ���� ����Ʈ���� ã��
		if (item.GetName().find(data.GetName()) != -1)
		{
			item.DisplayRecordOnScreen();
			cout << endl;
			cout << "\t=== �ش� �� ������ ã�ҽ��ϴ�. ===" << endl;
		}
		else
		{
			cout << endl;
			cout << "\t=== �ش� �� ������ ã�� ���߽��ϴ�. ====" << endl;
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
		best.DisplayRecordOnScreen(); // ����Ʈ�� �� �߰� �Ǿ����� ���
	}
	else
	{
		cout << "\t=== ���� ������ �α� ��Ʈ�� �����ϴ�. ===" << endl;
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

	// list pointer �ʱ�ȭ
	m_bestList.ResetList();

	int curpointer = m_bestList.GetNextItem(item);

	// list ������ ���� ���Ͽ� �ۼ�
	while (curpointer < m_bestList.GetLength())
	{
		item.WriteDataToFile(m_OutFile);
		int getItem = m_bestList.GetNextItem(item);
	}

	// ��Ʈ���� ����
	return 1;
}

int Application::ReadBestDataFromFile()
{
	char filename2[FILENAMEMAX];
	cin >> filename2;

	// ������ ������ �ʴ� ��� "Cannot Open" ���
	if (!OpenInFile(filename2))
	{
		cout << endl;
		cout << "\t=== �� �� �����ϴ�. ===" << endl;
	}
	else
	{
		BestType item;
		m_bestList.ResetList();
		// ���Ͽ� ���� ���� ����
		item.ReadDataFromFile(m_InFile);
		m_bestList.Add(item);

	}
		DisplayAllBest();
		cout << endl;
		cout << "\t=== ���� ���� �������� �Ϸ� ===" << endl;

	// ���� �ݱ�
	m_InFile.close();

	return 1;
}

int Application::AddRecordToPL()
{
	PlayType item;	
	item.SetNamePLByKB();

	m_playList.EnQueue(item);
	cout << endl;
	cout << "\t=== ��� ��Ͽ� �߰��Ǿ����ϴ�. ===" << endl << endl;

	item.DisplayPLNameOnScreen();

	return 0;
}

int Application::DeletePL()
{
	PlayType item;		//main���� Application���� ����� �ڷ����� �����ϳ� ����
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
		cout << "\t=== ��� ����� ������ϴ�. ===" << endl;
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

	// ������ ������ �ʴ� ��� "Cannot Open" ���
	if (!OpenInFile(filename3))
	{
		cout << endl;
		cout << "\t=== �� �� �����ϴ�. ===" << endl;
	}
	else
	{
		LyricType item;
		m_lyricList.ResetList();
		// ���Ͽ� ���� ���� ����
		item.ReadDataFromFile(m_InFile);
		m_lyricList.Add(item);
		item.DisplayPLLyricOnScreen();
	}
	
	cout << endl;
	cout << "\t=== ���� ���� �������� �Ϸ� ===" << endl;

	// ���� �ݱ�
	m_InFile.close();

	return 1;
}


