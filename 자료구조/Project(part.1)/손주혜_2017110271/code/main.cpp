#include <iostream>
#include <string>
#include "User.h"
#include "Application.h"
#include "ManagerApp.h"
using namespace std;

int main() {
	/*다형성을 통해 main을 중심으로 구현해야할 듯...*/
	int anw;
	Application app;
	ManagerApp manager;
	while (1) {
		cout << "1. 회원가입하기 \n2. 로그인모드 \n3. 관리자모드 \n4. 나가기" << endl;
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
