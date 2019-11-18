#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename T>
void sort(vector<T>& v){
    T temp;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            if(v[j] > v[j+1]){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

template <typename T>
void print(vector<T>& v){
    for(auto iter = begin(v); iter != end(v); iter++){
        cout<<*iter<<", "<<'\t';
    }
    cout<<endl;
}

int main(){
    vector<int> int_list(5);
    int_list = {10, 5, 8, 1, 3};
    
    vector<double> double_list(5);
    double_list = {10.1, 5.1, 8.1, 1.1, 3.1};
    
    vector<string> string_list(5);
    string_list = {"하나", "둘", "셋", "넷", "다섯"};
    
    sort(int_list);
    sort(double_list);
    sort(string_list);
    
    print(int_list);
    print(double_list);
    print(string_list);
}
