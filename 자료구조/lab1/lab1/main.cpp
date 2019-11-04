#include "Application.h"
using namespace std;

int main(){
    
    Application app;
    app.Run();
    
    return 0;
}

/*
1) ArrayList 클래스가 전체 배열을 구성하고
2) 배열의 요소는 ItemType 클래스에서 구현한다. (학번, 이름, 주소) 즉, ItemType 클래스는 객체의 성격을 보여준다.
3) 그리고 자리에 대한 값은 ArrayList 클래스에 관리한다
4) Application 클래스에서는 말 그대로 작동을 구현해준다.
5) 고로 ArrayList 클래스의 기능과 Application 클래스의 기능은 함께 움직여야 한다.
*/
