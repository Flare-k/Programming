#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

void print_DOB(int year=2000, int month=1, int day=1);

int main(){
    int x, y, z;
    print_DOB();

    cout<<"Enter year : ";
    cin>>x;
    cout<<"Enter month : ";
    cin>>y;
    cout<<"Enter day : ";
    cin>>z;
    print_DOB(x,y,z);
}

void print_DOB(int year, int month, int day){
    cout<<"My brithday is "<<year<<"year "<<month<<"month "<<day<<"day."<<endl;
}
