#include <iostream>
using namespace std;

void swap_call_by_value(int x, int y){
    int temp = x;
    x=y;
    y=temp;
}
void swap_call_by_reference(int& x, int& y){
    int temp = x;
    x=y;
    y=temp;
}
void get_data(int& x, int& y);

int main(){
    int x, y;
    
    get_data(x,y);
    
    cout<<"----------------------------"<<endl;
    cout<<"Before, swap_call_by_value"<<endl;
    cout<<x<<", "<<y<<endl;
    
    swap_call_by_value(x, y);
    cout<<"After, swap_call_by_value"<<endl;
    cout<<x<<", "<<y<<endl;
    cout<<"----------------------------"<<endl;
    
    cout<<"Before, swap_call_by_reference"<<endl;
    cout<<x<<", "<<y<<endl;
    
    swap_call_by_reference(x, y);
    cout<<"After, swap_call_by_reference"<<endl;
    cout<<x<<", "<<y<<endl;
    cout<<"----------------------------"<<endl;
    
    return 0;
}

void get_data(int& x, int& y){
    cout << "x 입력 : ";
    cin >> x;
    cout << "y 입력 : ";
    cin >> y;
}
