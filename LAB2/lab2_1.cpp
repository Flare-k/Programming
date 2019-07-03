#include <iostream>
using namespace std;

int sum(int a, int b);
int sub(int a, int b);
int mult(int a, int b);
int idiv(int a, int b);

int main(){
    int x, y;
    cout<<"Enter x : ";
    cin>>x;
    cout<<"Enter y : ";             //메인함수의 변수를 함수에 실인수로 넣을 수 있음
    cin>>y;
    
    cout<<"x+y="<<sum(x,y)<<endl;
    cout<<"x-y="<<sub(x,y)<<endl;
    cout<<"x*y="<<mult(x,y)<<endl;
    cout<<"x/y="<<idiv(x,y)<<endl;
    return 0;
}

int sum(int a, int b){
    return a+b;
}
int sub(int a, int b){
    return a-b;
}
int mult(int a, int b){
    return a*b;
}
int idiv(int a, int b){
    return a/b;
}
