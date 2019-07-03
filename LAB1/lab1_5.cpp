#include <iostream>
using namespace std;

int main(){
    int degree_celsius;
    int degree_fahrenheit;
    
    cout<<"Please enter Fahrenheit value:";
    cin>>degree_fahrenheit;

    degree_celsius=(5/9)*((double)degree_fahrenheit-32);

    cout<<"Celsius value is "<<degree_celsius<<endl;
    
}
