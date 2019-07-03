#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Complex{
    double re, im;
public:
    Complex(double r, double i){
        re = r;
        im = i;
    }
    Complex(){re = 0; im = 0;}

    Complex& operator+(Complex& r){
        Complex result(this->re + r.re, this->im - r.im);
        return result;
    }
    
    Complex operator -(Complex& r){
        Complex result(this->re - r.re, this->im - r.im);
        return result;
    }
    void print(){
        cout<<re<<"+ i"<<im<<endl;
    }
};

int main(){
    
    Complex a(0.3, 8.4), b(4.5, 5.2), c(2.0, 7.7);
    Complex sum, dif;s
    sum = a + b;
    cout<<"a+b= ";
    sum.print();
    
    dif = a - b ;
    cout<<"a-b=";
    dif.print();
    
    sum = a + b - c ;
    cout<<"a + b - c = ";
    sum.print();
    
    return 0;
}
