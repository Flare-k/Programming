#include "Application.h"

Application::Application() {}
Application::~Application() {}

int Application::login()
{
	string iid, ppw;
	int customer;
	User user;
	if (user.login(iid, ppw, customer)) {
		User user(iid, ppw);
		admit = 1;
		Run();
	}
	return 0;

}

void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 0:
			admit = 0;
			return;
		case 1:		// 곡 정보를 입력 받아 리스트에 추가
			DisplayAllMusic(); break;
		case 2:
			AddSongToPL();   break;
		case 3:		// 리스트에 저장된 모든 곡을 화면에 출력
//			DeleteSong();
		case 4:
			DisplayUnsortedPL(); break;
		case 5:
			//자주 듣는 순서대로 출력
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}
//
//
int Application::GetCommand() {
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   0 : LogOut" << endl;
	cout << "\t   1 : 모든 음원 보기" << endl;

	cout << "\t***********플레이리스트 추가 및 삭제***********\n" << endl;
	cout << "\t   2 : 내 플레이리스트에 추가" << endl;
	cout << "\t   3 : 내 플레이리스트에서 삭제(not yet)" << endl;
	cout << "\t***********나의 플레이리스트***********\n" << endl;
	cout << "\t   4 : 최신 순" << endl;
	cout << "\t   5 : 자주 듣는 순" << endl;





	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}
void Application::AddSongToPL()
{
	PlayType music;
	cout << "*************넣고 싶은 음악*************" << endl;
	music.SetIdFromKB();
	m_List.Get(music);
	m_UnsortedPL.Add(music);
	DisplayUnsortedPL();

}

void Application::DisplayAllMusic()
{
	pManage->DisplayAllMusic();
}

void Application::DisplayUnsortedPL()
{
	cout << "------------------ 현재 목록 ------------------" << endl;
	ItemType music;
	DoublyIterator<PlayType> iter(m_UnsortedPL);

	int i = 0;
	iter.GetPre();
	iter.GetPre();
	while (!iter.NextNull()) {
		cout << ++i << endl;
		music = iter.GetData();
		music.DisplayRecordOnScreen();
		iter.GetPre();

	}
}

void Application::DisplayAllsong()
{
	ManagerApp::DisplayAllMusic();
}
int Application::PlayByFreq()
{
	string anw;
	PlayType data;
	int num;

	DoublyIterator<PlayType>iter1(m_UnsortedPL);
	DoublyIterator<PlayType>iter2(m_UnsortedPL);

	int length = m_UnsortedPL.GetLength();
	PlayType *v = new PlayType[length];


	int cnt;

	for (int i = 0; i < length; i++) {
		iter1.GetNext();
		iter2.Reset();
		iter2.GetNext();
		int x1 = iter1.GetData().GetnumPlay();
		int x2 = iter2.GetData().GetnumPlay();

		cnt = 0;
		for (int j = 0; j < length; j++) {
			if (x1 < x2)cnt++;
			iter2.GetNext();
			x2 = iter2.GetData().GetnumPlay();
		}
		v[cnt] = iter1.GetData();
	}
	int i = 0;

	while (1) {

		data = v[i];
		num = data.GetnumPlay() + 1;
		data.SetnumPlay(num);
		m_UnsortedPL.Replace(data);
		v[i] = data;

		data.DisplaynumPlay();
		data.DisplayinTime();

		m_List.Get(data);//retrieve
		data.DisplayRecordOnScreen();


		cout << "다음 곡을 재생하시겠습니까? 계속 들으려면 아무키나, 정지하려면 n" << endl;
		cin >> anw;
		i++;

		if (i >= m_UnsortedPL.GetLength()) {
			i = 0;
		}
		if (anw == "n") break;
	}
	delete[] v;

	return 0;

}


