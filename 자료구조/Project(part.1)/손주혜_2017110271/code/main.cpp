#include <iostream>
#include <string>
#include "User.h"
#include "Application.h"
#include "ManagerApp.h"
using namespace std;

int main() {
	/*�������� ���� main�� �߽����� �����ؾ��� ��...*/
	int anw;
	Application app;
	ManagerApp manager;
	while (1) {
		cout << "1. ȸ�������ϱ� \n2. �α��θ�� \n3. �����ڸ�� \n4. ������" << endl;
		cin >> anw;
		string id, pw;
		switch (anw) {
		case 2:

			app.Run(); continue;
		case 3:
			manager.Run(); continue;
		case 4:
			return 0;

		}
	}
}
