#include <iostream>
#include <iomanip>
using namespace std;

void startGame(int *input, int *answer);


int main(){
    srand((unsigned int) time (NULL));
    
    int input[3];
    int answer[3];
    
    for(int i=0; i<3; i++){
        answer[i] = rand()%9+1;
        for(int j = 0; j<i; j++){
            if(answer[i] == answer[j] and i!=j){
                i--;
            }
        }
    }
    
    cout<<answer[0]<<answer[1]<<answer[2]<<endl;
    
    while(1){
        int i;
        for(i = 0; i < 9; i++ ){
            cout<<"=========="<<i+1<<"=========="<<endl;
            cout<<"Enter a number from 1 to 9."<<endl;
            cin>>input[0]>>input[1]>>input[2];
            if(input[0]<1 or input[0]>9 or
               input[1]<1 or input[1]>9 or
               input[2]<1 or input[2]>9){
                continue;
            }
            
            startGame(input, answer);
            
        }

        if(i==9)
            cout<<"You lose."<<endl;
            cout<<"The answer is "<<answer[0]<<setw(5)<<answer[1]<<setw(5)<<answer[2]<<endl;
            break;
    }
    
    return 0;
}

void startGame(int *input, int *answer){
    int strike=0;
    int ball = 0;
    
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (input[i] == answer[j]) {
                    if(i == j){
                        strike++;
                    }
                    else
                        ball++;
                }
            }
        }
    cout<<"Strike: "<<strike<<" Ball: "<<ball<<endl;
    if(strike == 3){
        cout<<"You Win!"<<endl;
        exit(1);
    }
}
