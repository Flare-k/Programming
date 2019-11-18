#include <iostream>
using namespace std;

void pow(int *p){
    cout << (*p) * (*p) << endl;
}//call by address를 했기 때문에 리턴해줄 필요없다.

//기존에 리턴을 할때와의 차이는??
/*
 int pow(int x){
 return x*x;
 }
 //이건 그냥 입력파라미터의 값만 읽어와서 리턴해주는 것일뿐..
 */
int main(){
    int q;
    cout << "Input>> ";
    cin >> q;
    
    cout << "Result>> ";   //q의 주소값을 p가 가리키게 함 *p라고 하면 q의 값으로 점프
    pow(&q);
    
    return 0;
}
