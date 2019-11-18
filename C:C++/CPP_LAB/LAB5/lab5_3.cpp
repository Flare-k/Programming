#include <iostream>
#include <vector>
using namespace std;

void ReverseVector(vector<int>& v){
    cout<<"Reverse한 Vector값 :"<<endl;
    for(int x = 9; 0 <= x; x--)
        cout<<v[x]<<'\t';
    cout<<endl;
}

int main() {
    vector<int> v{1,2,3,4,5,6,7,8,9,10};
    
    cout<<"기본 Vector 값 :"<<endl;
    for(int vec = 0 ; vec < 10 ; vec++)
        cout<<v[vec]<<'\t';
    cout<<endl;
    
    ReverseVector(v);
    
    return 0;
}
