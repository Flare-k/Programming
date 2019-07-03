#include <iostream>
using namespace std;

float sum(int x, int y);
float sub(int x, int y);
float mult(int x, int y);
float idiv(int x, int y);
float add_mult(int x, int y, int z);
float mult_div(int x, int y, int z);
float add_mult_add(int x, int y, int z);
float sub_div_sub(int x, int y, int z);

int main(){
    int x, y, z;
    cout<<"Enter x : ";
    cin>>x;
    cout<<"Enter y : ";
    cin>>y;
    cout<<"Enter z : ";
    cin>>z;

    cout<<"(x+y)*z="<<(1.0)*mult(sum(x,y),z)<<endl;
    cout<<"(x*y)/z="<<(1.0)*idiv(mult(x,y),z)<<endl;
    cout<<"(x+y)*(y+z)="<<(1.0)*mult(sum(x,y),sum(y,z))<<endl;
    cout<<"(x-y)/(x-z)="<<(1.0)*idiv(sub(x,y),sub(x,z))<<endl;
    
    return 0;
}

float sum(int x, int y){
    return (1.0)*(x+y);
}
float sub(int x, int y){
    return (1.0)*(x-y);
}
float mult(int x, int y){
    return (1.0)*(x*y);
}
float idiv(int x, int y){
    return (1.0)*(x/y);
}
float add_mult(int x, int y, int z){
    return (1.0)*mult(sum(x,y),z);
}
float mult_div(int x, int y, int z){
    return (1.0)*idiv(mult(x,y),z);
}
float add_mult_add(int x, int y, int z){
    return (1.0)*mult(sum(x,y),sum(y,z));
}
float sub_div_sub(int x, int y, int z){
    return (1.0)*idiv(sub(x,y),sub(x,z));
}
