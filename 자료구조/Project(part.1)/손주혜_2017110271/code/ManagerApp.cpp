#include "ManagerApp.h"
#include "Application.h"
#include "ManagerApp.h"

ManagerApp::ManagerApp() {}
ManagerApp::~ManagerApp() {}

void ManagerApp::Run()
{
	while(1)
	{
	m_Command = GetCommand();

	switch (m_Command) {
		case 1:
			AddMusic(); break;
		case 2:
			ReplaceMusic(); break;
		case 3:
			RetrieveMusic(); break;
		case 4:
			ReadDataFromFile(); break;
		case 5:		// 리스트에 저장된 모든 곡을 화면에 출력
			DisplayAllMusic(); break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;

		}
	}
}

int ManagerApp::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add Music" << endl;
	cout << "\t   2 : Replace music" << endl;
	cout << "\t   3 : Retrieve music(Get data)" << endl;
	cout << "\t   4 : Get from file" << endl;
	cout << "\t   5 : Print all on screen" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


int ManagerApp::AddMusic()
{
	ItemType music;
	music.SetRecordFromKB();
	m_List.Add(music);
	DisplayAllMusic();
	return 0;
}

int ManagerApp::ReplaceMusic()
{
	ItemType data;
	cout << "-------------------- To Replace Data --------------------" << endl;
	data.SetRecordFromKB();
	m_List.Replace(data);


	return 0;
}

int ManagerApp::RetrieveMusic()
{
	ItemType data;
	cout << "To Find Music" << endl;
	data.SetIdFromKB();
	cout << "-------------------------------" << endl;
	m_List.Get(data);
	//data.DisplayRecordOnScreen();
	return 0;

}

int ManagerApp::ReadDataFromFile()
{
	ItemType data;
	char filename[FSIZE];

	OpenInFile(filename);

	while (1) {
		data.ReadDataFromFile(m_InFile);
		if (!m_InFile) break;
		m_List.Add(data);
	}
	m_InFile.close();

	DisplayAllMusic();
	return 0;
}

int ManagerApp::OpenInFile(char * fileName)
{
	cout << "file to get data : ";
	cin >> fileName;
	m_InFile.open(fileName);

	return 0;

}



void ManagerApp::DisplayAllMusic()
{
	cout << "------------------ 현재 목록 ------------------" << endl;
	ItemType music;
	DoublyIterator<ItemType> iter(m_List);

	int i = 0;
	iter.GetNext();
	while(!iter.NextNull()) {
		cout << ++i << endl;
		music=iter.GetData();
		music.DisplayRecordOnScreen();
		iter.GetNext();

	}


}




