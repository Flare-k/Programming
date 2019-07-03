//선택문(if-else, switch)
//반복문(for, while, do while)

#include <iostream>
#include <iomanip>      //=ip manipulate 입출력을 조작하고싶을때쓰는 라이브러리
#include <locale>
using namespace std;
/*


//bool = 자료형(논리값 저장)  참 또는 거짓을 저장가능
int main(){
    bool a = true;              //true는 1이고 false는 0이다
    bool b = false;
    bool c = (10>=5);
    bool d = (10<5);
    bool e = 1750;          //0이면 false 0이 아닌 모든 숫자는 true로 출력된다.
    bool f = -0.000001;
    cout<<a<<", "<<b<<", "<<c<<", "<<d<<endl;
    cout<<e<<", "<<f<<endl;

    return 0;
}
*/

/*

//if-else문
int main(){
    int score;
    char grade;
 
    cout<<"Enter the score:";
    cin>>score;
    //90점이상이면 A 그렇지 않으면 F

    if(score>=90)
        grade = 'A';            //90이상이면 참이어서 A가 나오고 거짓이면 F가 나오는 구조
    else
        grade = 'F';
    
    cout<<"Grade:"<<grade<<endl;
    
    return 0;
}
*/

/*
//if-else문(응용1)
int main(){
    int score;
    char grade;
 
    cout<<"Enter the score:";
    cin>>score;
    //90점이상이면 A 그렇지 않으면 F
    
    if(score>=90)
        grade = 'A';            //90이상이면 참이어서 A가 나오고 거짓이면 F가 나오는 구조
    else if(score>=80)
        grade = 'B';
    else if(score>=70)
        grade = 'C';
    else
        grade = 'F';            //최종적으로 디폴트로 수행되는 부분
    
    cout<<"Grade:"<<grade<<endl;
    
    return 0;
}
*/

/*
//if-else문(응용2)         &&=AND  ||=OR !=NOT //if문 안에 있는 if문의 경우
int main(){
    int score;
    char grade;
 
    cout<<"Enter the score[0~100]:";
    cin>>score;
    //90점이상이면 A 그렇지 않으면 F
    if(score>=0 && score<=100){         //if문에 속하는경우 중괄호를 써준다.
         if(score>=90)
             grade = 'A';            //90이상이면 참이어서 A가 나오고 거짓이면 F가 나오는 구조
         else if(score>=80)
             grade = 'B';
         else if(score>=70)
             grade = 'C';
         else
             grade = 'F';            //최종적으로 디폴트로 수행되는 부분
    
             cout<<"Grade:"<<grade<<endl;
    }
    else
        cout<<"ERROR!!!!"<<endl;
    
    return 0;
}

*/


//반복문       예를들어...1~100까지의 합??
/*
int main(){
    int i, sum=0;
    i = 1;
    sum = sum+i;    //sum이 1로 바뀌게됨
    i = 2;
    sum = sum+i;
    //쭉...하면 1~100까지 더하는거.... 반복문을 쓰면 이러한 수고를 줄일수있다.
    return 0;
}*/

/*
int main(){
    int i, sum=0;
    //i는 1부터 100까지 1씩 증가, sum=sum+i
    i=1;
 
    while(i<=100){          //조건이 거짓이 될때까지 계속 반복
        sum += i;
        cout<<i<<", "<<sum<<endl;
        i++;    //i가 100을 넘을때까지 계속 증가시켜준다
    }
                    //홀수의 합을 구하기 위해서는???? i++이 아니라 i+=2로 바꿔주면 된다.
                    //짝수의 합을 구하기 위해서는???? i=0 or i=2로 바꿔주면 된다.
    return 0;
}
*/

/*
//iomanip활용..._setw(integer)
int main(){
    int i, sum=0;
    //i는 1부터 100까지 1씩 증가, sum=sum+i
    cout.imbue(locale("")); //천단위로 콤마를 찍어주는 것... 가독성을 위해(잘 안씀)
    i=1;
    while(i<=1000){          //조건이 거짓이 될때까지 계속 반복
        sum += i;
        cout<<setw(4)<<i<<setw(10)<<sum<<endl;  //다음에 있는 항을 수식.. 4=4칸을만든다. 10= 10칸을 만든다.. 오른쪽 정렬로..함수안에 들어간 숫자만큼 스페이스바 공간을 만들어준다.__setw()의 기능..
        i++;    //i가 100을 넘을때까지 계속 증가시켜준다
    }
    //홀수의 합을 구하기 위해서는???? i++이 아니라 i+=2로 바꿔주면 된다.
    //짝수의 합을 구하기 위해서는???? i=0 or i=2로 바꿔주면 된다.
    return 0;
}
*/

/*
//이중 while문     행렬을 나타낼수있다
int main(){
    int row, column;
    row = 1;
    while(row<=5){
        column = 1;
        while(column<=5){
            cout<<setw(4)<<row+column;
            column++;
        }
        cout<<endl;
        
        row++;
    }
    
    return 0;
}

*/
                //행과열에 대한 크기를 비교하여 로우가 크고 같으면 로우의 수를 같고 그외엔 콜론의 수를 가짐
/*
int main(){
    int row, column;
    row = 1;
    while(row<=5){
        column = 1;
        while(column<=5){
            if(row>=column)
                cout<<setw(4)<<row;
            else
                cout<<setw(4)<<column;
            
            column++;
        }
        cout<<endl;
        
        row++;
    }
    
    return 0;
}
*/
/*
//무한반복문&강제종료
int main(){
    int input, sum=0;
    
    while(1){                   //while(1) 무한반복문        루프를 끝내고싶다면??
        cout<<"Input:";
        cin>>input;
        if(input < 0)
            break;          //break로 무한루프를 탈출
        
        sum += input;
        cout<<"Sum:"<<sum<<endl;
    }
    
    return 0;
}
*/

//무한반복문&컨티뉴
/*
int main(){
    int input, sum=0;
    
    while(1){                   //while(1) 무한반복문        루프를 끝내고싶다면??
        cout<<"Input:";
        cin>>input;
        if(input < 0)
            continue;   //밑에있는 부분을 수행하지않고 while문의 첫째줄로이동.
            //break;          //break로 무한루프를 탈출
        
        sum += input;
        cout<<"Sum:"<<sum<<endl;
    }
    
    return 0;
}
*/


/*
//Do while문 //잘안씀..시험엔 나올수도있다.
int main(){
    int value;
    do{
        cout<<"Enter the number[0, 10]:";
        cin>>value;                         //와일문은 조건을 먼저 검사
    }while(value>10 || value<0);            //먼저 내부를 실행을 한 후, 조건을 검사... 참이면 실행
    
    return 0;
}
*/

//반복문을 구성하는 4가지요소
/*
int main(){
    int i, sum=0;
    i=1;            //1.초기화를 한다
    while(i<=100){  //2.반복조건
        sum +=i;    //3.main statement, boy
        i++;        //4.modification
    }
    cout<<sum<<endl;
                    //4가지 요소를 한군데에 묶어놓은것이 for문
    
   // for(초기화; 반복조건; 변경)            ex..for(i=1; i<=100; i++)   sum+=i;
     //   main statement
    return 0;                   //모든 for문은 while문으로 대체가능하다..
}
*/

//for문 순서.. 1.초기화 ; 2.반복조건; 3.메인스테이트 실행 4.업데이트(modification)
//업데이트한 후 다시 반복조건 체크.

/*
//이중 for 문  //행과 열의 인덱스의 곱을 원소로 가지는 행렬구현해보기
int main(){
    for(int row = 1; row<=5; row++){            //1행부터 5행까지 행을 1씩증가
        for(int column=1; column<=5; column++){           //1행일때 열을 1~5만큼 증가
            cout<<setw(4)<<row*column;
        }
        cout<<'\n'; //한 행이 끝날때 엔터를 쳐주는 역할
    }
    return 0;
}
*/


//switch statement
int main(){
    char ch;
    cout<<"Please input (a/b): ";
    cin>>ch;
    switch(ch){
        case'A':            //A의 경우
        case'a':            //이렇게하면 대소문자 다 가능하게해줌.
            cout<<"Apple"<<endl;
            break;
        case'B':
        case'b':
            cout<<"Bear"<<endl;
            break;
        default:    //위의 값이 전부 거짓일때..
            cout<<"Error"<<endl;
    }
                            //트루가 나타는곳부터 아래로 전부다 출력해버림..A라고 입력하면 Apple, Bear, Error전부출력
                                //이걸 막아주려면 각각의 케이스마다 break;를 넣어주면된다.
    return 0;
}
