//  [06.04.Tue]
//main15_ExceptionHandling  [예외처리]
/*
 예외적인 상황을 마지막에 처리해주기 위해서 사용한다.
 고퀄리티 기술. 무결점의 프로그램을 만들 수 있다.
*/
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

//  1)
/*
//예외처리 핵심키워드: try/catch구문, throw문
//1. 예외가 발생하는 부분을 try에 넣는다.
//2. 예외가 발생하면 catch구문이 실행된다.

int main(){
    vector<int> v{1,2,3,4};
    
    int index;
    cout<<"원하는 벡터 인덱스를 입력해주세요 = ";
    cin>>index;
    try{
        cout<<"인덱스 "<<index<<"의 값: "<<v.at(index)<<endl;        //여기서 예외가 발생할 예정
        cout<<"인덱스 "<<index<<"의 값: "<<v[index]<<endl;
    }
    catch(exception& e){        //용량이 클수도 있으므로 &을 썼음.  반드시 exception이라는 객체를 사용해준다.
        cout<<e.what()<<endl;
        cout<<"인덱스 에러!"<<endl;
    }
    //try에서 예외가 발생하면 에러가 catch를 실행한다.
    //에러가 뭔지 보여주고 계속 돌아가고 있음.
    
    //if-else와 비슷하지만 다른게 있다.
    //한줄만 적더라도 반드시 중괄호로 감싸줘야 작동한다.
    
    cout<<"[Program is running]"<<endl; //catch문을 나가서 작동하는 line.
    
    return 0;
}
*/


//  2)
/*
class FileNotFoundException: public exception{      //exception이라는 부모클래스로 부터 상속받음.
    string message;
public:
    FileNotFoundException(string _m):       //m은 파일이름으로 해놓을려함.
    message("File not found: "+ _m){}
    
    virtual const char* what() const throw(){      //부모클래스 멤버함수를 오버라이딩(virtual 적어도되고 안적어도됨)
                                        //exception 클래스에 대해서는 override라 적지 않고 throw라고 적어준다. (그냥 암기사항)
        return message.c_str(); //c_str = 스트링을 캐릭터로 바꾸는 함수.
    }
};

vector<int> load_vector(string filename){
    ifstream fin(filename);
    //파일이 열리지 않으면 (파일이 존재하지 x)
    if(!fin){ //이 부분이 제일중요!!!!!!!!!!!!!!!
        //예외처리
        throw FileNotFoundException(filename);      //catch로 보냄. 메인에서 catch가 받아서 실행한다.
        //예외가 발생할 경우 throw를 실행.. throw는 catch로 보내고 메인에있는 catch가 실행된다.
    }
    vector<int> result; //임시 객체
    int num, value;
    //파일로 부터 값을 result에 저장.
    //파일의 form: size, elements (5, 1, 2, 3, 4, 4)
    fin>>num;   //5가 들어감.
    for(int i =0; i < num; i++){
        fin>>value; //(1,2,3,4,4)
        result.push_back(value);
    }
    return result;
    
}

int main(){
    try{
    vector<int> v = load_vector("test.txt");  //벡터값에 대해선.. 다음 파일에 있는 값들을 받아서 저장.
        for(auto elem: v)
            cout<<elem<<'\t';
    }
    catch(FileNotFoundException& e){ //FileNotFoundException 대신 exception이라고 써도 상관은 없다.
        cout<<e.what()<<endl;   //what()은 exception클래스의 멤버함수.
    }
    
    return 0;
}
*/


/*
exception 클래스 = 추상화 클래스
 
 *추상화 클래스는 왜 쓰는거지?
 => 부모클래스의 인터페이스로 자식클래스에서 상황에 맞게 쓰기 위해서 씀.
 
*/



//  3)
void filter(vector<int>& v, int i){
    v.at(i)++;
}

void compute(vector<int>& a){
    for(int i = 0; i < 6; i++){
        try{
            filter(a, i);
        }
        catch(exception& ex){//filter에서 이미 예외가 생겨서 throw를 통해 catch로 감, 근데 catch 안에 throw를 또 써줌..
                             // 다음 catch구문인 main에 있는 catch구문으로 접근하여 실행.
            cout<<"*********************************"<<endl;
            cout<<"* For loop terminated prematurely"<<endl;
            cout<<"* when i = "<<i<<endl;                       // i 번째 인덱스에서 예외가 발생함을 알려줌
            cout<<"*********************************"<<endl;
            throw ex; // Rethrow the same exception
        }
    }
}

int main(){
    vector<int> list {10, 20, 30, 40, 50};
    try{
        compute(list);
    }
    catch(exception& e){
        cout<<"Caught an exception: "<<e.what()<<endl;
    }
    
    cout << "Program finished"<<endl;
}


