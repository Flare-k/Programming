#include <iostream>
#include <string>
using namespace std;

void compare(string& randstr){
    string sum;
    for(int i = randstr.size()-1; i >= 0; i--){
        sum += randstr[i];
    }
    cout<<sum<<endl;

    if(randstr == sum){
        cout<<"이 문자는 회문입니다."<<endl;
    }
    else
        cout<<"이 문자는 회문이 아닙니다."<<endl;
}

int main(){
    string randstr;
    cout<<"문자열 하나를 입력해주세요: ";
    cin>>randstr;

    cout<<"입력하신 문자열의 역순: ";
    [](string randstr){compare(randstr);}(randstr);
  
    return 0;
}



/*
 reverse(randstr.begin(), randstr.end());
 */
