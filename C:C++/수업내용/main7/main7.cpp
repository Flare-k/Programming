//   #4/2_(화)수업내용
#include <iostream>
#include <vector> //vector객체 사용가능.
using namespace std;

//      [Pointer]
//&a = 'a의 주소값을 리턴'
// *pa = 'pa에 저장된 주소값이 있는 곳으로 점프!'
//두가지를 잘 쓰면 메모리를 직접 컨트롤 가능하다.
/*
int main() {
    int a= 10;  //0x00에 10이라는 값이 들어감
    int *pa;    //pa는 주소값을 저장하는 변수이다.
    pa = &a;  //a의 주소값이 pa에 들어감
    cout<<pa<<", "<<&a<<endl;  //같은 주소를 출력
    cout<<*pa<<", "<<a<<endl; // *pa는 pa가 저장하고있는 주소 즉, a로 점프해서 a의 값을 출려함
 
    return 0;
}
*/


//int& x = a; int& y=b
//메인함수에 있는 a,b가 x,y와 같은 메모리를 갖게된다..
/*
void swap(int& x, int& y){
    int temp =x;
    x=y;
    y=temp;
}

int main(){
    int a=10, b=20;
    cout<<a<<", "<<b<<endl;
    swap(a,b);
    cout<<a<<", "<<b<<endl;
    return 0;
}
*/
//call by reference는 그냥 같은 값이라 생각하면 쉽다. pass by address는 p라는 새로운 공간이 할당되고 그 안에 포인터변수기 때문에 a의 주소값이 들어가는것..
/*
//pass by address라는 방법도 있다. int *x = &a; int *y = &b; 이렇게 같은 주소를 가리키도록.
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a=10, b=20;
    cout<<a<<", "<<b<<endl;
    swap(&a,&b); //메인함수에 있는 변수에 &를 넣어주고 함수호출해야한다.(컴파일러가 발전해서 사실 &를 안써도 에러가 안 나긴 함)
    cout<<a<<", "<<b<<endl;
    return 0;
}
*/

//      [Function Pointer]
/*
int sum(int x, int y){
    return x+y;
}

int mult(int x, int y){
    return x*y;
}
int evaluate(int(*func)(int, int), int x, int y){
    return func(x, y);              //함수의 주소를 저장해서 함수를 리턴하게 함
} //function r??  함수를 입력으로 받는 함수. (Function Pointer)
//왜 함수포인터를 만들었냐.. 적재적소에 쓰고 싶어서 ..
//최적화 이론에서 많이쓰인다.

int main(){
    int(*func)(int, int);
  //[의미]_ *func는 함수의 주소값을 저장. 입력이 두개인 정수를 가지고 출력이 정수인 함수의 주소값을 가리키는 포인터. 주소값을 저장하는 일종의 변수를 만듬.
    func = &sum;  //func에 sum함수의 주소가 옴.
    cout << func(10,20) << endl;
    func = &mult;           //같은 func라도 다른 기능을 가지게함. _ func에 mult의 주소값이 들어감.
    cout << func(10,20) << endl;
    
    cout << evaluate(&sum,100,200) << endl;  //sum과 mult에 반드시 &을넣어줘야함. 함수의 주소값이 저장되어있기때문에
    cout << evaluate(&mult,100,200) << endl;

    return 0;
}
*/
/////////////////////////////////////////////////////[Vector]////////////////////////////////////////////////////
/*
//      [Vector] = 다양한 변수/함수들을 한번에 관리하고 저장할 수 있는 객체. 메모리 블럭(여러개의 변수가 들어있음, 연속적으로 들어있음)을 관리.

int main(){ //index:0   1   2
    
    int size=0;
    cout<<"벡터의 크기를 입력해주세요 = ";
    cin>>size;
    vector<int> vec(size);     //vector<int>:데이터타입, vec:변수명, {10, 20, 30}:변수의 원소
                                    //다양한 값을 가지고 n차원 벡터는 n개의 값을 가짐 -> value들의 collection
                                    //[쓰는 방법] => vector<데이터타입_ex,int, float..>변수명{요소1, 요소2, 요소3 ...}
                                    //인덱스를 통해 값들을 조작 가능하다.
 for(int i = 0; i < vec.size(); i++) //0~2(or -1)까지 1씩 늘어나며 출력
        cout<<vec[i]<<'\t';
    cout<<endl;
    
    vec[0] = 100;                   //0번째 인덱스에 있는 10 대신에 100을 집어넣겠다.
    vec.at(1) = 200;                //[n] = .at(n)   ( 빠른속도 = [n]  , 안정성우선 = 변수.at(n) )
                                    //기존의 벡터요소들을 수정.
 for(int i = 0; i < vec.size(); i++) //0 ~ 2(or -1)까지 1씩 늘어나며 출력
        cout<<vec[i]<<'\t';
    cout<<endl;
    
    vec.push_back(400);             //맨뒤에 추가(append)를 하는 것... 길이는 n+1만큼 늘리고 입력파라미터에 있는 값을 넣어줌.
 for(int i = 0; i < vec.size(); i++) //0~2(or -1)까지 1씩 늘어나며 출력
        cout<<vec[i]<<'\t';
    cout<<endl;
    
    
    vec.pop_back();                 //맨뒤부터 지워줌
    for(int i = 0; i < vec.size(); i++) //0~2(or -1)까지 1씩 늘어나며 출력
        cout << vec[i] << '\t';
    cout << endl;

    return 0;
}
*/

/*
//벡터안에 있는 아이템을 출력하는 부분을 동일하게 만들어서 함수로 묶어주면 간단하게 만들수 있다.
void print(const vector<int>&v){            //print함수의 입력은 벡터로.. call by value는 단순 값 복사이기 때문에 처리 내용이적으면 괜찮으나 많아지면 처리하기 힘들어짐.. 그땐 call by reference필요
                                            //객체가 커지면 &을 쓰면 값을 복사하지 않고도(=call by value하지 않고) 그대로 쓸 수 있다.
    for(unsigned int i = 0; i < v.size(); i++)  //unsigned로 해줘야 warning이 안 생긴다. 크기에 대한 내용이므로..(unsigned로 바꿔주는 이유? size라는 함수가 return값이 unsigned이기 때문에.)
        cout << v[i] << '\t';
    cout << endl;
 
 //     [for문을 좀더 간략하게 나타내기 위한 방법] : Simplified Expression
    //  1)
    //for(int elem : vec) vec라는 객체로부터 0번째 아이템이 elem으로 들어가고 블록부분이 실행.. 끝나면 순서대로 쭉 들어가면서 실행됨.
    //   cout << elem << '\t';
    // cout << endl;                    (더 간략한 for문)
 
    //  2)
    //for(int &elem : vec)      &가 붙어있음 >> elem은 vec에 있는 아이템하나를 복사해서 저장하는 임시변수. 임시변수가 가리키는 주소와 vec의 elem이 실제 가리키는 주소가 같아지는 것.
    //     cin >> elem;
    //                          즉, elem의 값을 바꾸면 vec의 값도 바뀜. &를 붙이므로써 벡터의 아이템을 바꿀수있다. (Call by reference)
 
}                                           //print라는 함수가 내부적으로 값이 바뀌는 함수가 아니다. 단지 현재있는 값을 화면에 출력해주는 기능만..
                                            //'const를 해주면 함수안에서 벡터 값이 바뀌지 않는다'라는 의미 >> 다른 프로그래머들이 리턴값이 바뀌지 않는다고 알아보기 쉬움..
 
int main(){
    vector<int> vec(3);             //vector<int>:데이터타입, vec{10, 20, 30}:변수명
                                            //변수뒤에 아무것도 안 적어주면?? >> NULL vector
                                            //if, vector<int>v(10)이라 써주면? 10개의 아이템을 가진 10차원 벡터가 나옴(아이템 값이 뭔지는 모름) (10, 8)이라 쓰면 아이템이 8이고 10차원 배열
    print(vec);
    
    vec[0] = 100;                           //0번째인덱스에있는 10 대신에 100을 집어넣겠다.
    vec.at(1) = 200;                        //[n] = .at(n)
    
    print(vec);

    vec.push_back(400);                     //맨뒤에 추가를 하는 것... 길이는 n+1만큼 늘리고 입력파라미터에 있는 값을 넣어줌.
    print(vec);

    
    vec.pop_back();                         //맨뒤부터 지워줌
    print(vec);
    
    

    return 0;
}
*/



//한번 자료형을 정해주면 바꿀수없다... 하나의 벡터엔 하나의 자료형만 쓸 수 있다.


//      [Returning Vector] _ lower~upper사이에 소수를 저장하는 프로그램.
/*
bool is_prime(int num){
    if(num < 2)
        return false;
    for(int i = 2; i < num; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

vector<int> primes(int lower, int upper){
    vector<int> v;                           //프라임을 집어넣을 벡터생성.
    for(int i = lower; i <= upper; i++){
        if(is_prime(i))
            v.push_back(i);                 //v라는 벡터에 푸쉬백.
    }
    return v;
}                   //여기서 프라임을 처리하는 벡터함수만듬

int main(){
    int lower = 10, upper = 100;
    vector<int> vec = primes(lower, upper);
    for(int elem : vec)                         //메인에서 벡터만들어서 메인벡터에 프라임벡터를 집어넣음.
        cout << elem << '\t';
    cout << endl;
}
*/

