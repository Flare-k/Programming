#include "User.h"



User::User(){	}

void User::SetIdPwKeyboard()
{
	cout << "���̵� : ";
	cin >> id;
	cout << "��й�ȣ";
	cin >> pw;

}


User::~User()
{
}

User::User(string id, string pw){}

int User::login(string &_id, string &_pw, int &customer)
{
	
		cout << "���̵� : ";
		cin >> searchid;
		cout << "��й�ȣ : ";
		cin >> searchpw;
		fin.open(textfile);
		int num = 0;
		while (1) {
			num++;
			fin >> id >> pw;
			if (!fin) { 
				cout << "���̵� Ȥ�� ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
				break; 
			}
			if (id == searchid && pw == searchpw) {
				cout << "�α��� �Ϸ�" << endl;
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
	cout << "����� ���̵� : ";
	cin >> id;
	cout << "����� ��й�ȣ : ";
	cin >> pw;
	fout << id << " " << pw << endl;
	fout.close();
}

void User::run(string _id, string _pw)
{
//	app.Run();
}


