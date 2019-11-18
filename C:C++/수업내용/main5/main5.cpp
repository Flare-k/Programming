//String 객체에 대한 실습..(3.26)

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

/*
int main(){
    string s1 = "fred"; //스트링 변수선언.. 정확히말하면 자료형이 아니라 객체이다.
    cout<<s1<<endl;     //문자열은 객체이고 그 객체에 해당하는 헤더를 인클루드 시켜야한다.
    cout<<s1.length()<<", "<<s1.size()<<endl;   //.을 찍는 이유는 객체를 사용하는 방법이다. [의미]a.b = 'a라는 객체가 가지고있는 b라는 함수를 사용한다.'
                                                //length = size 문자열의 길이, 크기를 세어주는 함수이다. 같은기능을 하지만 이름만 다르다.
    
    cout<<"빈 내용이면 '1', 아니면 '0': "<<s1.empty()<<endl;         //.empty()  => 비어있으면 true(=1) 안 비어있으면 false(=0)  ..  비어있는지 확인하는것이지 비우는게 아님

    s1.clear(); //문자열(s1) 안에 있는 모든 문자를 지워주는 함수.
    cout<<"빈 내용이면 '1', 아니면 '0': "<<s1.empty()<<endl;
    
    s1 = "good";
    s1 += "-bye";           //문자열끼리 공간을 할당하여 붙여주는 역할..
    cout<<s1<<endl;
    
    cout<<s1[0]<<", "<<s1.at(4)<<endl;      //s1[4] == s1.at(4) 서로 같은 기능을 한다.
    
                                            // .at(n)을 쓰는게 훨씬 안정적이므로 참고할 것!!!!!
    cout<<(s1=="good-bye")<<endl;
    cout<<(s1=="Good-bye")<<endl;       //문자는 관계연산자도 가능하다...
    cout<<(s1>"z")<<endl;       //맨 처음의 첫문자를 비교하여 대소관계를 따진다.
    
    cout<<s1.substr(5,3)<<endl; //문자열 중에 특정문자를 발췌하는 역할.. [매우 중요한 기능] 괄호안에는 찾고 싶은 문자의 인덱스를 써주면된다. s1.substr(5,3)= '5부터 3글자'
    
    cout<<"'od'의 시작인덱스: "<<s1.find("od")<<endl;           //원하는 단어를 찾게해주는 함수 [매우 중요한 기능]  //2를 출력할것임.. 찾고자하는단어의 시작인덱스가 출력됨.
    cout<<s1.find("od",5)<<endl;         //5번째 인덱스부터 시작해서 od가 있는지 찾겠다.. => 해당내용상 못찾게 됨.
                                        //18446744073709551615라고 출력되는데 이만큼 찾아보고 끝낸다음 출력한 내용임.
    
    cout<<(s1.find("korea") == string::npos)<<endl;              //npos 스트링이 찾을 수 있는 마지막 인덱스 값..
                                                        //npos는18446744073709551615 값을 갖기때문에 korea라고 입력해봤자 오류가 나기때문에 오류=오류 는 참이므로 1이 출력되는 것.
                                            //npos는 못찾았을 때 반환하는 값이다..(에러는 아니다.) 고로 npos와 'korea'둘다 못찾았을때의 값을 반환하므로 값이 같다. 즉, 참.
    return 0;
}
*/


//파일에 대한 실습..입출력
/*
int main(){
    ofstream fout;  //파일 객체를 써야함  fout = cout   화면이 아니라 파일에 저장해주는 역할(cout이 화면에 뿌려주듯 fout은 파일에 뿌려줌) ... 한가지 차이점은 어떤 파일에 보내줄지를 알려줘야한다.
    fout.open("example.txt");    //해당 텍스트가 만들어짐
    fout<<"Objective Oriented Programming"<<endl;       //파일에 이값이 저장됨
    fout<<"Random Variables"<<endl;
    fout<<"Linear Algebra"<<endl;
    fout.close();   //열었으니 닫아줘야 함.. 그래야 저장됨
                    //ofstream? 어떤 파일을 저장할때 쓰는 객체... fout을 써야하는데 그걸 쓰기 위한 자료형 or 객체.
    
    ifstream fin("example.txt"); //파일을 읽어올때 쓰는 객체..ifstream  fin = cin
    string s1;          //받아온 데이터를 저장해놓을 s1이라는 방을 만듬..
    //fin.open("example.txt");//같은 파일명이 있으면 덮어씀..fout.open("example.txt", ios::app)를 쓰면 이어쓰기가 가능하다. 같은내용으로 총 6줄이 나올 것이다.
                    //fin을 통해 파일에 있는것을 내 모니터에 입력해줌.(읽음)
 
        //다른 문자를 더불러올려면 ??  fin은 file끝에 도달하면 null값을 가짐.
  
    while(1){
    fin>>s1;  //받아온 데이터를 s1에 할당.. [중요]띄어쓰기 전까지만 읽어온다. 띄어쓰기를 기준으로 다른문자라고 생각함.
        if(!fin) //끝에 도달했다는 의미
            break;
    cout<<s1<<endl; //값이 잘들어갔는지 확인용..
    }
   //띄어쓰기 기준으로 읽는다.
                       //즉 오브젝티브 부터 알제브라까지 다 읽으면 0으로 끝남.
  
    if(!fin){
        cout<<"Error, no such file exists"<<endl;
        exit(100);   //파일을 못찾을때(이름을 다르게쓸때) 예외처리.. fin에 null이 들어가게 구현 exit(100)은 프로그램이 종료될때 프로그램에 보내는 시그널이라 할 수 있다.
}                       //100은 그냥 교수님이 임의로 작성..
   
   while(getline(fin, s1)){     //fin을 s1에 저장하여 한줄씩 읽는다.
        cout<<s1<<endl;         //한 줄씩 읽는다.
    }
    
    fin.close();
    
    return 0;
}
*/

/*
//setw와 같은 데코를 쓸 수 있다..(간격만들기&오른쪽 정렬)   => width
int main(){
    double a = 123.456788;
    cout<<a<<endl;
    cout.precision(4);//숫자 갯수를 따로 설정가능.

    cout.width(10); //우측으로 정렬   10칸 만들고 우측부터 정렬
    cout.precision(4);//숫자 갯수를 따로 설정가능.   (반올림됨) 숫자를 입력수만큼만 나타냄 4면 숫자 4개까지만...
    cout.fill('*');//정렬한뒤 공백있을 경우 공백채워주는 기능..... 문자를 5개만 받았으므로 *이 5개가 채워질것임.
    cout<<a<<endl;
    
    char ch;
    cin.unsetf(ios::skipws);//셋팅한걸 셋팅하지 않겠다.& 화이트 스페이스를 무시하지않는 의미
    cin>>ch;
    cout<<"("<<ch<<")"<<endl;       //cpp는 스페이스바를 무시한다
    
    return 0;
}
*/




////6/4 여기까지 복습함


//1)
bool getStudent(ifstream& fin, int& id, int& exam1, int& exam2, int& exam3){//메인에 읽힐수있도록 콜바이레퍼런스
    fin>>id>>exam1>>exam2>>exam3;
    if(!fin)
        return false;
    return true;
}
//2)
void calcAvgGrade(int exam1,int exam2,int exam3,int& avg,char& grade){            //exam은 바뀔필요없으므로 콜바이레퍼런스 안해도됨.
    avg = (exam1+exam2+exam3)/3;          //평균과 그레이드는 바뀔때마다 값을 넣어줘야하므로 레퍼런스 해야함.
    if(avg>=90)
        grade = 'A';
    else if(avg>=80)
        grade = 'B';
    else
        grade = 'F';
}
//3)
void writeGrade(ofstream& fout,int id,int avg,char grade){
    fout.fill('0');
    fout<<setw(4)<<id;
    fout.fill(' ');     //아이디에만 00을 넣어주고 그 다음부터는 다시 여백이 출력 되도록.
    fout<<setw(4)<<avg;
    fout<<setw(4)<<grade<<endl;
}

int main(){
    //스케치한다 = 수도코드를 짠다 = 유사코드를 짠다
    //반복:ch7STUFL.DAT에서 모든 학생을 읽어서 저장할 때까지.
    //ch7STUFL.DAT에서 학생정보읽기:id, exam1, exam2, exam3을 읽어야한다.
    //세 시험의 값의 평균을 내고 평균값을 grading
    //학점계산 : 시험점수 입력 -> 평균, 학점 출력
    //grade.txt에 저장 : id, avg, grade
    ifstream fin("ch7STUFL.DAT");       //선언과 동시에 오픈
    ofstream fout("grade.txt");
    int id, exam1, exam2, exam3, avg;
    char grade;
    
    while(getStudent(fin, id, exam1, exam2, exam3))     //while문 한번돌때마다 한명의 학생의 정보를 읽어옴.
        {
        calcAvgGrade(exam1, exam2, exam3, avg, grade);
        writeGrade(fout, id, avg, grade);                        //파일에 계산된 값을 저장해줘야함.
    }
    

}


//꼭 fin  fout이라고 안해도된다.
