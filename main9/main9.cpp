//  4/16(화)  Class

/*
 사람들은 모든 것들은 객체로 인식..
 객체를 만들어 객체들끼리 정보를 주고받으면 수월하지 않을까..  객체지향프로그래밍
 데이터와 함수를 가진 Component = 객체
 어떻게 객체를 만드는지 알아보자
 Class = 객체를 만드는 틀, 사람이 만들어낸 데이터 타입.
 틀로 부터 객체를 상황에 찍어내는 것... 예를 들자면 자동차라는 클래스를 만들고 소나타, 아반떼 등을 찍어내는 것.
 객체를 Class의 instance라고 한다. 객체 = instance
 */

#include <iostream>
#include <string>
using namespace std;
//      [Software Component]
//            [Class]
/*
class Point{
public:                 //클래스 안에 속해있는 변수들을 클래스 밖에서도 쓸 수 있게해줌 ...  =public
    int x;              //클래스에 속해 있는 멤버변수 (클래스에 종속되어있는 변수)
    int y;
    //private:  //class 안에서만 사용가능.
    //  int x;
    // int y;
    //private으로 하면 클래스 안에서만 동작하고 메인함수 등 다른 곳에선 사용불가능하게 만든다.
    
public:
    //생성자=\constructor   ,1) 클래스와 이름이 같다. 2)출력 데이터타입이 필요없고 리턴도 갖지않는다.
    Point(int _x, int _y){
        x = _x;
        y = _y;                 //값을 초기화하기 위해서 쓰인다. 생성자를 만들지 않으면 컴파일은 자동으로 디폴트 생성자를 만들어줌
    }                                                                         //디폴트 생성자?? Point(){} 이런식으로...
    void setXY(int _x, int _y){
        x = _x;
        y = _y;
    }               //생성자와 비슷한데.. 프로그램 도중에 값을 바꾸고 싶을때 쓴다.
    int getX(){return x;}   //멤버 변수인 x,y값을 출력해주는 함수
    int getY(){return y;}   //멤버 변수인 x,y값을 출력해주는 함수
    void print(){
        cout<<x<<", "<<y<<endl;   //멤버 변수인 x, y를 출력해줌.
    }
};


int main(){
    //Point pt1, pt2;     //pt1, pt2를 객체 또는 인스턴스라고 부른다.
    Point pt1(1, 2), pt2(3, 4); //생성자에 대한 코드..
    // pt1.x = 1;   //객체안에있는 멤버변수에 접근하기위해..   (즉, 함수 호출하듯이..)
    // pt1.y = 2;
    
    cout<<pt1.x<<", "<<pt1.y<<endl;         //
    
    
    pt1.setXY(10,20);               //x, y값이 1,2에서 10, 20으로 바뀜
    pt1.print();
    pt2.print();
    cout<<pt1.getX()<<endl;
    cout<<pt2.getY()<<endl;
    
    return 0;
}
*/

////////////////////////////////////////[활용]////////////////////////////////////////
/*
 class Account{
 
 private:            //private 안 적어도 c++ 자체에서 public을 만나기 전까지는 다 private으로 해석한다.
     string name;    //멤버변수
     string id;
     double balance;             //데이터를 저장하는 멤버변수. 보통 private으로 만든다.
 
 public:         //멤버함수.  = Method
     Account(string _name, string _id, double _bal):
        name(_name), id(_id), balance(_bal) { //생성자,, initialization list방식. 꼭 언더바를 써야하는건아님
        //name(customer_name), id(account_id), balance(account) {} 이런식으로 해도됨.
        if(balance < 0){
                cout<<"Error, negative balance"<<endl;
                balance = 0;
            }
        }
     //생성자를 여러개 만들수도있다.
     Account(): name(""), id(""), balance(0){}           //아무것도 입력 안 할때의 생성자
 
     Account(string _name, string _id):                  //입력을 두개를 받는 경우 이 생성자가 실행된다.
     name(_name), id(_id), balance(0) {}
 
     void deposit(double _amt){                         //입력된 값에서 돈이 들어오는 함수
         balance += _amt;                               //기존에 예금되어 있던 돈과 입력변수로 들어온 돈이 누적으로 더해져서 예금으로 다시저장
     }
     bool withdraw(double _amt){                        //입력된 값에서 돈이 나가는 함수
         if(balance - _amt < 0){
             return false;
         }
         balance -= _amt;       //기존에 예금되어 있던 돈과 입력변수로 나간 돈이 누적으로 나가서 예금으로 다시저장
         return true;
     }
     void print(){
         cout<<"이름:"<<name<<", "<<"계좌번호:"<<id<<", "<<"예금:"<<balance<<endl;
     }
 };
 
 int main(){
 
     Account ac1 ("강연욱", "241101-04-189991", 5000);
     Account ac2 ("김다솔", "534202-04-045836", 5000);
     Account ac3 ("김유민", "633904-64-253626", 5000);
     Account ac4 ("이한솔", "900876-42-089400", 5000);
     Account ac5 ("손주혜", "784324-12-522456", 5000);

 //Account ac2; 생성자를 만들면 이값에 아무것도 안들어가게됨..
 //이 값을 나오게하고싶으면 자료형에 default argument를 걸어주면 됨... ex) string name = "xxxx"이런식으로..
     cout<<"<계좌조회>"<<endl;
     ac1.print();
     ac2.print();
     ac3.print();
     ac4.print();
     ac5.print();
 
 ac1.deposit(10000);
     cout<<"<10000원 입금>"<<endl;
     ac1.print();
 
     cout<<"<20000원 출금>"<<endl;
 if(!ac1.withdraw(20000)){
     cout<<">>잔액이 부족합니다"<<endl;
    }
     ac1.print();
 
     cout<<"<5000원 출금>"<<endl;
     ac1.withdraw(5000);
     ac1.print();
 
 return 0;
 
 }
 //class는 자료형이라고 볼 수 있다.
 //벡터를 이용하면 더 많은 자료를 저장할 수 있다.

*/
