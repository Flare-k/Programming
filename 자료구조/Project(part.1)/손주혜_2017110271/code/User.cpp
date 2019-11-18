#include "User.h"



User::User(){	}

void User::SetIdPwKeyboard()
{
	cout << "아이디 : ";
	cin >> id;
	cout << "비밀번호";
	cin >> pw;

}


User::~User()
{
}

User::User(string id, string pw){}

int User::login(string &_id, string &_pw, int &customer)
{
	
		cout << "아이디 : ";
		cin >> searchid;
		cout << "비밀번호 : ";
		cin >> searchpw;
		fin.open(textfile);
		int num = 0;
		while (1) {
			num++;
			fin >> id >> pw;
			if (!fin) { 
				cout << "아이디 혹은 비밀번호가 일치하지 않습니다." << endl;
				break; 
			}
			if (id == searchid && pw == searchpw) {
				cout << "로그인 완료" << endl;
				id = _id;
				pw = _pw;
				fin.close();
				customer = num;
				return num;
			}
		}
		fin.close();
	
	return 0;
}


void User::StoreInfoInFile()
{
	fout.open(textfile);
	cout << "등록할 아이디 : ";
	cin >> id;
	cout << "등록할 비밀번호 : ";
	cin >> pw;
	fout << id << " " << pw << endl;
	fout.close();
}

void User::run(string _id, string _pw)
{
//	app.Run();
}


