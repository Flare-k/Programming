#include <iostream>
#include <vector>
using namespace std;

int main(){
    srand((unsigned int)time(NULL));
    int random = rand()%101;
    
    vector<int> list;
 
    for(int i = 0 ; i < random; i++){
        list.push_back(i);
    }

    int cnt = -1;
    
    while(1){
        cnt++;
        try{
            if(cnt == random){
                cout<<"현재 list는 "<<cnt<<"의 크기를 가지고 있다."<<endl;
                return 0;
            }
        }
        catch(exception& e){
            if(cnt != random){
                cout<<e.what()<<endl;
                break;
            }
        }
    }
    cout<<endl;
    
    return 0;
}
