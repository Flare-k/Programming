#include <iostream>
using namespace std;

int gcd(int x, int y);
int lcm(int x, int y);
int main(){
    int a, b;
    int result;
    int result1;

    cout<<"Enter number, X:";
    cin>>a;
    cout<<"Enter number, Y:";
    cin>>b;
    result = gcd(a, b);
    result1 = lcm(a,b);
    
    cout<<"GCD("<<a<<", "<<b<<")="<<result;
    cout<<endl;
    cout<<"LCM("<<a<<", "<<b<<")="<<result1;
    cout<<endl;
}
/*
int gcd(int x,int y){
    
    if(x<y){
        swap(x,y);
    }
    int r;
    r = x%y;
    
    if(r != 0)
        return gcd(y, r);
    else
        return y;
}
*/
//반복문으로 짜는 최대공약수
int gcd(int a, int b)
{
    int c;      //임의의 저장공간 같은기능..
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
//최소공배수
int lcm(int a,int b)
{
    return a * b / gcd(a, b);
}
