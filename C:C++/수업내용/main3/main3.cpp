//2019.03.12

//로컬변수와 글로벌변수
//로컬변수_해당함수에서만 사용가능
//글로벌변수_모든함수에서 사용가능

#include <iostream>
using namespace std;
/*


void print(){                //void=없음 즉 입력값과 출력값이 없다는말
    int x=2000;
    cout<<"x in print():"<<x<<endl;     //x가 2000
}

int main(){
    int x = 20;
    cout<<"x in main():"<<x<<endl;  //x=20
    print();                        //x=2000
    cout<<"x in main():"<<x<<endl;  //x=20 (로컬변수의 한계.. 즉 프린트함수가 메인함수에있는 변수에 영향을 끼치지못한다)
    
    
    return 0;
}
*/
   //여기까지 로컬변수설명

/*

#include <iostream>
using namespace std;

int x; //글로벌 변수는 함수밖에서 선언 _ 모든함수에서 사용가능하다. 프로그램이 끝날때만 할당해제된다.
        //다른 함수에는 int를 지워준다.

void print(){                //void=없음 즉 입력값과 출력값이 없다는말
    x=2000;
    cout<<"x in print():"<<x<<endl;     //x가 2000
}

int main(){
    x = 20;
    cout<<"x in main():"<<x<<endl;  //x=20
    print();                        //x=2000
    cout<<"x in main():"<<x<<endl;  //x=2000 (프린트에서 받은 x값을 그대로)  //근데 메인함수에서 int x =20;으로 설정하면 20으로나온다
                                    //Why?? 로컬변수가 글로벌변수보다 우선순위가 높기때문이다.
    
    return 0;
}
*/
                //여기까지 글로벌변수설명


//참조변수              참조변수를 쓰는 행위 = Aliasing
/*
#include <iostream>
using namespace std;
 
int main(){
    int x = 10;
    int &y = x;    //참조변수를 쓰면 결과가 달라진다. &y=x
    //즉, 같은사람인데 이름만 달라질뿐이다.
    //같은 공간을 쉐어하는 다른 변수이름이 라고 할 수도 있다.
    cout<<"x="<<x<<", y="<<y<<endl;             //참조변수는 같은 메모리를 가리킨다.
   
    y=1000;
    cout<<"x="<<x<<", y="<<y<<endl;
 
    x=20;
    cout<<"x="<<x<<", y="<<y<<endl;

    return 0;

}
*/
////////////////////
/*
#include<iostream>
using namespace std;

void increment(int &a){ //참조변수를 쓰면 메모리에선 int &a=x로 x에 10이들어있으면 a도 같은 공간을 가리키게 만든다. 따라서 a를 증가시키면
    a++;//a를 1증가      //x도 증가하게 되는 것이다.
}

int main(){
    int x = 10;
    cout<<x<<endl;  //10
    increment(x);   //x에 10이들어가고 1증가함   //int a = x를 실행하게됨   //다른 메모리값에 11을 복사시켜넣을뿐 x는 그대로 10으로 유지한다.
    cout<<x<<endl;  //10
    
}
*/
//increment(int a)   >> pass(call) by value : 단순복사
//increment(int &a)  >> pass(call) by reference : 참조전달  (매애애애애애애애애우우우우우우우 중요)

/*
//swap함수_ 참조변수응용
#include <iostream>            //콜바이밸류일때는 스왑이 안된다.
using namespace std;

void swap(int a, int b){
    int temp = a;
    a=b;
    b=temp;
}

int main(){
    int x = 10, y = 20;
    
    cout<<x<<", "<<y<<endl;
    swap(x, y);
    cout<<x<<", "<<y<<endl;

    return 0;
    
}*/


//재귀함수=현재함수가 자기자신을 불러내는 함수...부분연산으로 분해될수있을때 사용
//예를들어..녹음참고25분대

int factorial(int n){
    if(n==0)                    //n이 0이될때까지... 0!은 1이니까
        return 1;
    else
        return n*factorial(n-1);
}

int main(){
    cout<<factorial(6)<<endl;
}




//https://kin.naver.com/qna/detail.nhn?d1id=1&dirId=1040101&docId=140737196&qb=Y2FsbCBieSB2YWx1ZQ==&enc=utf8&section=kin&rank=2&search_sort=0&spq=0&pid=U5KywwpySEsssaHjxiRssssstBC-028591&sid=Cfkq4mKP0ofPYebfZx51oQ%3D%3D
//https://blog.naver.com/afsdzvcx123/221394538078
//(call by value / call by reference)설명 링크참고

