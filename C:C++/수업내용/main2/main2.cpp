#include <iostream>  //cin cout이 들어있음
#include <cmath>
using namespace std;
//1.함수 선언
int sum(int a, int b);      //int형 함수를 선언     //만약 sum을 언제든지 많이 사용하고싶을땐 함수로 만들어준다.
int mult(int a, int b);
int get_data(int a);     //default augument 함수정의에서는 int a=0이라고 적어주지않는다.           //int get_data(int a);

int main(){
    int x=10, y=20;         //변수를 만들어줌과 동시에 초기화시킴
    x=get_data(1);          //(1)=첫번째받는숫자
    y=get_data(2);
  //  int result = sum(x,y);  //3.함수 호출(calling)
    int result_mult = mult(x,y);
    cout<<"x = "<<x<<", y = "<<y<<endl;     //'는 하나의 문자열을 나타낼때 씀, "aaa hhh"문자열을 나타낼때씀(특수기호포함)
    cout<<"x+y = "<<sum(x,y)<<endl;
    cout<<"x*y = "<<result_mult<<endl;   //result_mult대신 mult(x,y)를 넣어도됨
    cout<<"cos(x) = "<<cos(x)<<endl;
    cout<<"log(x) = "<<log(x)<<endl;
    cout<<"sqrt(x) = "<<sqrt(x)<<endl;   //sqrt=square root = 제곱근
    
}

//함수 정의(=구현)_메인함수 밑에다가 해줄 것.
int sum(int a, int b){
    return a+b; //실제적인 함수 내용 채우면 됨 (ex,채색하기)
}

int mult(int a, int b){
    return a*b;
}
                    //왜 선언과 정의를 메인을 사이로 나눠서 할까??? = 다른프로그래머들을 위해서...
                    //메인함수는 가장중요한 함수인데 제일 밑에다가 쓸 수 없기 때문이다.
                    //함수 선언을 하지 않으면 컴파일이 되지않는다. 왜? 맨 윗줄 부터 실행을 할텐데 메인함수에서 sum이나 mult를 갑자기 받아들이게 된 것이나  마찬가지이기 때문이다.  즉, 가독성과 기능성을 위해 나눠서 하는 것이다.

//코사인을 만들고싶으면??? 코사인 함수를 사용하면된다..cmath

int get_data(int a){
    int b;
    cout<<a<<"번째 숫자를 입력하세요:";                     //x와 y에 사용자가 원하는 수를 입력받게해줌
    cin>>b;
    return b;
}
