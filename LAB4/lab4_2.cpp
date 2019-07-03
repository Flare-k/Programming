#include <iostream>
#include <string>
using namespace std;

int main(){
    string database = "love, programming, chair, a full of love, station, millennial love, refri, objective";
    string s2;
    
    cout<<"Keyword:";
    cin>>s2;
    cout<<"'Find' Results : "<<database.find(s2,0)<<","<<database.find(s2,4)<<","<<database.find(s2,40)<<endl;
    cout<<"Search Results : "<<database.substr(0,4)<<","<<database.substr(26,14)<<","<<database.substr(50,16)<<endl;
    return 0;

}
