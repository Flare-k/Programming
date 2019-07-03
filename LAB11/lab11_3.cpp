#include <iostream>
#include <iomanip>
using namespace std;

const int size = 100;
int arr[size][size]={0,};

int main()
{
    int odd;
    cout<<"홀수 숫자를 하나 입력해 주세요 : ";
    cin>>odd;
    if(odd%2 == 0){
        cout<<"잘못누르셨습니다. 프로그램을 종료합니다.";
        exit(1);
    }
    cout<<endl;

    
    
    int x = 0;
    int y = odd/2;
    
    for(int i=1; i<=odd*odd; i++){
        arr[x][y] = i;       //1st..number = 3이면 arr[0][1] = 1
       
        if(i%odd == 0){      //2nd.. i%3 == 1 이므로 x는 -1이 됨 y는 2
            x += 1;          //3rd.. i%3 == 2이므로 x는 -2 y는 3이 됨.. y가 2보다 커졌으며로 y=0 고로 (-2, 0) -> (2, 0) = 3
        }                    //전 값이 다음의 인덱스를 설정해줌.
        else{
            x -= 1;
            y += 1;
        }
        
        if(x < 0){      //-1되자마자 바꿔줌.
            x = odd-1; //  if n=3이라면, (a[-1] == a[n-1])  == (a[-1] == a[2])
        }
        
        if(y > odd-1){
            y = 0;          //n열을 넘어갈경우 1열로 가야하므로 인덱스는 0으로 초기화시켜줌
        }
    }
    
    int j, k;
    for(j=0; j<odd; j++){
        for(k = 0; k < odd; k++){
            cout<<setw(3)<<arr[j][k];
        }
        cout<<endl;
    }
    
    cout<<endl;

}

