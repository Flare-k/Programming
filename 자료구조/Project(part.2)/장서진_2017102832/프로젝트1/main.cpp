#include <iostream>
using namespace std;
#include "Application.h"
#include <windows.h>

int main() {
	Application app;
	
	app.RunAdminOrUser();
	return 0;
}