#include <iostream>
#include <string>
using namespace std;

int main(){
    string city, area, street, building;
    
    cout<<"City: ";
    cin>>city;
    
    cout<<"Area: ";
    cin>>area;
    
    cout<<"Street: ";
    cin>>street;
    
    cout<<"Building: ";
    cin>>building;
    
    cout<<"Address: "<<city<<area<<street<<building<<endl;
    
    return 0;
}
