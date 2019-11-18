//4/9(화) _ Pointer에 대한 Deep한 내용
#include <iostream>
#include <vector>
using namespace std;


/*
// [Review]
int main(){
    int a = 10;
    int* pa = &a;
    
    cout<<*pa<<'\t'<<a<<endl;
    
    return 0;
}
*/

//포인터를 이용하여 배열(=벡터)을 만들수있다. 하지만 배열은 객체가 아님. (벡터는 객체이다)     .at(n)은 존재하지 않음

/*
int main(){
    int ary[3] = {1,2,3};       //총 3갤 받고 요소의 값은 오른쪽과같다.
    
                                //array의 개수는 프로그래머가 기억하고있어야한다.
    for(int i = 0; i<3; i++){
        cout<<ary[i]<<'\t';
       //== cout<<*(ary+i)<<'\t';
    }
    cout<<endl;

    
    
    return 0;
}
*/
//      ary[i] == *(ary+i)  [중요]

/*
int main(){
    int ary[3] = {1,2,3};
    
    cout<<ary+0<<", "<<*(ary+0)<<", "<<ary[0]<<endl;    //ary+0은 배열의 시작 주소값
    cout<<ary+1<<", "<<*(ary+1)<<", "<<ary[1]<<endl;
    cout<<ary+2<<", "<<*(ary+2)<<", "<<ary[2]<<endl;
    //주소 값이 1씩 늘어났으나 정수는 4바이트이므로 주소값은 4씩 이동 'c->10->4'
    return 0;

}
*/
 
//배열을 함수의 인자로 만들줄도 알아야
/*
void print(int ary, int size){
    for(int i = 0; i < size; i++){
        cout<<ary<<'\t';            //0x01로 jump! 10이 나오게 됨
        ary++;  //+i의 역할을 대신해줌... ary+1 , ary+2 ..... 안쓸꺼면 *(ary+i)
    }
    cout<<endl;
}//call by address로 작동하게 됨 int *ary라고 써도됨(입력파라미터)

int sum(int *begin, int *end){
    int *curr = begin; //임시변수에 배열의 시작주소값을 넣어줌
    int result = 0;
    
    while(curr != end){
        result += *curr;
        curr++;
    }
    return result;
}

int main(){
    int size;
    cout<<"배열의 크기를 입력해주세요:";
    cin>>size;
 
    int *ary = new int[size];   //대괄호 안을 비워놔도 컴파일러가 알아서 알아듣는다.
    
    
    print(*ary, size);  //어레이의 길이를 넣어줌... 스스로 저장할 수 있는 능력이 없으므로!!!
                    //길이의 입력파라미터를 받아서 print함수 안에서 반복문을 돌려 배열을 다시 꺼낸다.
    
    int *begin, *end;    //시작주소값, 끝주소값
    begin = ary;    //ary배열의 시작 값.
    end = ary+size;    //ary배열의 끝 값.
   
    cout<<sum(begin,end)<<endl;
    
    delete[] ary;
    return 0;
}
      //여기까지 '정적배열'
*/

/*
// [정적배열] vs. [동적배열]
int main(){
    
    int size;
    while(1){
    cout<<"Size: ";
    cin>>size;
    
    //int staticArr[size];          //이문법자체는 정적배열을 만드는 문법.
                                    //크기만큼의 배열을 만드는것... 그래서 정적배열을 만들려면 상수 값을 넣어야한다.
    
    //1> const int len = 10
    // int staticArr[len];
    //2>
    //int staticArr[10];
    
    //---------------------
    //동적배열은 어떻게???
    //프로그램이 동작하는동안에 배열을 바꿀수있다.
    //new, delete
    int *dynamicArr;
    dynamicArr = new int[size];  //@@동적 배열 할당@@
                                    //동적 배열 10을 받으면 10의 배열을 100을 받으면 100의 배열을..
                                    //dynamicArr이라는 포인터에는 동적배열이 들어가있다.
    if(size == 10){
        cout<<"프로그램을 종료합니다"<<endl;
        break;
    }
    
    for(int i = 0; i<size; i++){
        *dynamicArr = rand()%11;
        cout<< *dynamicArr <<" ";
    }
    cout<<endl;
       
         delete[] dynamicArr;
    }
    //동적배열과 정적배열의 사용법은 완전히 동일
   // delete[] dynamicArr;            //@@할당 해제@@  _반드시 해줘야 남은 공간을 다른 프로그램들이 사용.
                                    //할당 해제를 안 해주면 엄청나게 많은 필요없는 메모리들이 쌓인다.
    return 0;
}
*/

//  배열의 3가지 1)벡터(속도가 느리고 메모리를 많이 먹음)
//            2)정적배열
//            3)동적배열

/*
//배열을 이용하여 행렬도 만들수 있다.
int main(){
 //   int matrix[2][3];  //2행 3열
    
    int matrix[2][3] = { {1,2,3}, {4,5,6}};//으로 해주면 같은 내용이된다.
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;

    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
 
    //출력은??
    for(int row = 0; row<2; row++){
        for(int col=0; col<3; col++){
            cout<<matrix[row][col]<<'\t';
        }
        cout<<endl;
    }
}
*/

/*
//문자열의 배열도 가능하다.
bool found_char(const char *s, char c){     //call-by-address
    while(*s != NULL){  //='마지막이 아니면~'
        if(*s == c)
            return true;
        s++; //다음 주소 값으로 업데이트.
    }
    return false;
}       //시작 주소값을 s에 넣어준다.

int main(){                              //012345(6)     (6)에는 널문자가 저장되어있음.. 공간하나를 더 잡아먹는다는 단점을 가짐,
                                         //문자열의 길이를 기억할 필요가 없는 장점도 있다.. 널문자나올때까지 찾으면 되니까.
    const char *ch = "phrase";           //ch[];
                        //c++은 메모리에 phrase(\0)이라고 저장됨 ... \0 = NULL
    for(char c = 'a'; c<='z'; c++){      //'a' == 65 'z' == 97
        cout<<"["<<c<<"] is";
        if(!found_char(ch, c))
            cout<<" NOT";       //조건문이 참이면 실행
        cout<<" in "<<ch<<endl; //조건문이 거짓이면 실행
    }
    return 0;
}
*/

/*
//벡터를 이용하여 n차원 행렬만들기
int main(){
    
    srand(1);
    
    vector<vector<int>>matrix(2, vector<int>(3));  //2x3 matrix
                                    //'벡터의 자료형은 벡터이다. 2개의 백터를 만들고 각각의 벡터마다 3개의 요소를 저장하겠다.' 라는 의미.. 각각의 행에 벡터를 중복하여 생성.
    //각각의 v1, v2안에는 원소가 3개씩..
    //row의 index & col의 index
    cout<<"행렬의 난수 원소를 입력하시오"<<endl;
    for(vector<int>&v : matrix){    //v1이 벡터형이어서 벡터로 써줌.  열 원소를 1행에 쓰고 그다음 열 원소를 2행에 쓰고 반복.. 열을 한 행에..
        for(int& elem : v){         //&를 붙여줘야 입력값대로 나오게 변한다.
            elem = rand()%19-9;
            //cin>>elem;              //for(vector<int>열원소를 : 한 행에)
        }
    }           //복습필요
    for(vector<int>&v : matrix){    //이때는 값이얼마나 큰지 모르므로 &를 써줘야함
        for(int elem : v){          //출력만하기때문에 &를 쓸 필요없음..
            cout<<elem<<'\t';
        }
        cout<<endl;
    }
    //꿀팁..
    //vector<int>를 일일이 기억못할경우 auto라고만 적어주면 알아서 컴파일러가 인식함.
    //Data Type에 auto로 쓰면 다 인식함..  auto a = 10  >> 알아서 int로 바꿔서 해석함
    return 0;
}

*/
