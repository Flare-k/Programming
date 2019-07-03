#include <iostream>
#include <string>
using namespace std;

void convert_str(string* str);

int main() {
    string str = "This is default value";
    cout<<"Read Default >> "<<str<<endl;
    
    cout<<"Input >> ";
    convert_str(&str);
    cout<<"Read Result >> "<<str<<endl;

    return 0;
}


void convert_str(string* str){
    cin>>*str;
}
