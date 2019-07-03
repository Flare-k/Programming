#include <iostream>
using namespace std;
/*
 int main(){
 int x;  //int = 정수
 int y;
 x = 10; //x라는 변수에 10이라는 값을 집어넣음을 의미
 y = 20;
 cout<<x<<endl;
 cout<<y<<endl;
 }
 */

/*
 int main(){
 unsigned short int siX;
 unsigned int iX;
 long int liX;
 long long int lliX;                     //헝가리언 표기법(앞글자따오기)
 
 cout<<sizeof(siX)<<endl;
 cout<<sizeof(iX)<<endl;
 cout<<sizeof(liX)<<endl;
 cout<<sizeof(lliX)<<endl;
 
 }
*/
 /*
const double PI = 3.14;

 int main(){
 
 char ch1 = 'A';
 char ch2 = 65+32;               //문자변수에 숫자를써넣음
    
     
     int a;
     cin>>a;
     cout<<char(a+1)<<endl;         //문자를 입력하면 다음 아스키 값이 나옴.. ex) 입력: a , 출력: b
 cout<<ch1<<endl;        //65는 A의 아스키코드값
 cout<<ch2<<endl;
 }
*/
 //계산기 만들기

int main(){
 int x, y, sum, mult;
 float div;
     std::cin>>x>>y;   //x입력 y입력 순
 sum = x+y;
 mult =x*y;
 div = (float)x/y;       //x를 실수로 형변환시킴
     cout<<"x+y="<<sum<<endl;
     cout<<"x*y="<<mult<<endl;
     cout<<"x/y="<<div<<endl;
 }
/*
int main(){
    
    cout<<(7==5)<<endl;
    cout<<(7>=5)<<endl;
    cout<<(7!=5)<<endl;
    cout<<(7<=5)<<endl;
    
    cout<<(7>=5? 100:-100)<<endl; //Conditional Ternary Operator
    //참이면 100 거짓이면 -100
}
*/
