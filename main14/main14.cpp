//  5/28(화)
// [Iterator Review]    _ 깊게는 안 배우나 시험은 나온다.

#include <iostream>
#include <vector>
using namespace std;
/*
template<typename T>
void print(const T& iter_begin, const T& iter_end){
    //이때 T는 객체다..
    T iter = iter_begin; //시작 주소값을 넣어줌
    while(iter != iter_end){    //end직전까지만..
        cout<<*iter<<'\t';
        iter++;             //iter는 pointer like한 객체일뿐이다.
    }
    cout<<endl;
}

int main(){
    vector<int> v{1,2,3,4};
    print(begin(v), end(v));
 
    return 0;
}
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//[ Lambda Function ] _ 함수 객체이다.
//functional : f(x, z)가 아니라 f(h(x), k(z)) 함수의 입력값이 함수인 것..
// Lambda Function: 함수 이름없음, 단순(1~3줄)
// local function: 함수 안에서 만들어져서 함수가 끝나면 사라짐.
// 람다함수: [closure] (입력 매개변수) -> 리턴타입{본문}
// 일반함수: 리턴타입 함수이름이름 (입력 매개변수){본문}
// 언제 쓰는가?
//1. 어떤함수의 입력에.. / 2. 함수를 바로만들어서 호출할 때 / 3. 함수포인터로 로컬하게..
/*
int sum(int x, int y){return x+y;}
int mult(int x, int y){return x*y;}

//함수포인터
int evaluate(int (*func)(int, int), int x, int y){      //functional...   (함수포인터, 함수의 매개변수, 함수의 매개변수)
    return func(x, y);
}

int main(){
    int x, y;
    cout<<"임의의 정수 2개를 입력하라, >> ";
    cin>>x>>y;
    cout<<"Sum: "<<evaluate(sum, x, y)<<endl;      //함수 포인터 사용예시.
    cout<<"Mult: "<<evaluate(mult, x, y)<<endl;
    
    
    // []이건 그냥 무조건써주는거라 암기..
    // 1) [](int x, int y)->int {return x+y;}      람다함수 완성..
    cout<<evaluate([](int x, int y)->int {return x+y;}, 2, 3)<<endl;      //잠깐생겼다 사라지는 짧은 함수.
    cout<<evaluate([](int x, int y){return x*y;}, 2, 3)<<endl;;      //누구나 알수있는 리턴타입의 경우 생략가능하다. (->int 생략함)
    
    
    // 2) 람다함수 생성 및 호출       [](입력파라미터 자료형){내용}(입력파라미터 값)
    [](int x, int y) {cout<<x<<", "<<y<<endl;}(2, 4);
    
    
    // 3) 주소값저장가능.. , 람다함수를 함수포인터에 저장
    auto f = [](int x, int y){return x-y;};     //f는 로컬함수가 됨..메인함수가 끝나면 사라진다.
    
    cout<<f(20,30)<<endl;
    
    
    
    return 0;
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// [ Function Object ]
/*
#include <functional>  //function object를 쓰면 함수포인터를 안써도된다..


//int evaluate2(int(*func)(int, int), int x, int y){
//    return func(x, y);
//}
 //위에껄 이런식으로..

//function object : 변수/함수/객체 모두 대입가능한 object.
// [closure]: 주위의 값을 함수 내부에서 사용가능하도록 하는 기능.
//  [a]: 변수 a를 call by value로 함수 내부에 전달.
//  [&a]: 변수 a를 call by ref. 로 함수 내부에 전달.
//  [=]: 모든 외부변수를 call by value로 함수에 전달.
//  [&]: 모든 외부변수를 call by ref.로 함수에 전달.
//  [this]: 클래스의 멤버함수 안에서 람다함수를 쓸때, 그 클래스의 멤버변수를 쓰기 위해 사용.
int evaluate2(function<int(int, int)> func, int x, int y){
    return func(x, y);
}

int main(){
    
    int a = 100;        //[closure]사용위해..
    cout<<evaluate2([a](int x, int y){return a+x+y;}, 2, 3)<<endl; //a를 복사할뿐 메인에 있는 a에는 영향을 주지 않음.
                                                                    //call by ref.로 쓸 경우엔 메인에도 영향을 끼친다.
    
    int b = 200, c = 300;
    cout<<evaluate2([=](int x, int y){return b+x+y;}, 2, 3)<<endl;          //function object에서만 closure가 동작!!!!!!!!
    
    cout<<evaluate2([=](int x, int y){return c+x+y;}, 2, 3)<<endl;
    
    return 0;
}
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
#include <algorithm> //for_each, transform, copy란 함수가 존재함.
                    //for_each, transform 에서 람다함수를 사용한다.

int main(){
    vector<int> v{1,2,3,4};
    cout<<"[vector출력]"<<endl;
    for(auto& elem : v){
        elem++;         //벡터값을 하나 올려서 저장하고 출력해줌.
        cout<<elem<<'\t';
    }
    cout<<endl;
    
    //for_each(시작주소, 끝주소, 함수)
    
    cout<<"[for_each의 결과]"<<endl;
    for_each(begin(v), end(v), [](int& elem){   elem++;
                                                cout<<elem<<'\t'; });      //시작부터 끝까지 for문을 도는데 각각 본문을 수행..
    cout<<endl;
    
    cout<<"[for_each의 결과]"<<endl;
    for_each(begin(v)+1, end(v), [](int& elem){   elem++;
        cout<<elem<<'\t'; });      //시작부터 끝까지 for문을 도는데 각각 본문을 수행..
    cout<<endl;
    
    
    cout<<"[for_each의 결과]"<<endl;
    for_each(begin(v)+2, end(v), [](int& elem){   elem++;
        cout<<elem<<'\t'; });      //시작부터 끝까지 for문을 도는데 각각 본문을 수행..
    cout<<endl;
    
    cout<<"[for_each의 결과]"<<endl;
    for_each(begin(v)+3, end(v), [](int& elem){   elem++;
        cout<<elem<<'\t'; });      //시작부터 끝까지 for문을 도는데 각각 본문을 수행..
    cout<<endl;
    
    
    //transform(소스_시작주소, 소스_끝주소, 목적지_시작주소, 함수)  함수를 통해 시작값을 바꿔주고 목적지에 저장..
    vector<int> v2(v.size());  //v와 같은 수를 가짐 (4개)
    
    transform(begin(v), end(v), begin(v2), [](int elem){return elem*elem;});
    // v의 정보를 함수를 통해 변화가 이뤄진 후, 리턴된 값이 v2에 저장한다는 의미.
    
    cout<<"[Transform한 결과]"<<endl;
    for_each(begin(v2), end(v2), [](int& elem){cout<<elem<<'\t';});
    cout<<endl;

    
    //for_each는 리턴값이 없다. (자기 자신에 대한 것이기 때문에)
    //transform은 리턴값이 있다.(어딘가로 보내야하기 때문에)

    int a = 100;        //cin으로 받아서 결과를 맘대로 바꿀수도 있다.

    cout<<"Closure 적용[중요]"<<endl;
    for_each(begin(v), end(v), [a](int elem){cout<<a*elem<<'\t';} );        //외부변수를 내부에 적용.. closure
    cout<<endl;
    
    int sum = 0;
    cout<<"Closure 적용[중요]"<<endl;
    for_each(begin(v), end(v), [&sum](int elem){
        sum += elem;
        } );        //외부변수를 내부에 적용.. closure
    cout<<sum;
    cout<<endl;
    return 0;
}

*/
