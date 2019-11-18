//[5/21(화) _ Generic Programming]
//한 번 만들어 놓으면 다양한 곳에 사용할 수 있다. = Generic Program

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 template <typename T>
 //입력이 들어오는 자료형을 T가 치환해준다.
 
 bool less_than(T a, T b){   //함수의 입력인자를 정수인지 실수인지 문자열인지 등을 따로 받지 않는다.
    return a < b;
 }//less_than 이라는 함수를 만듬.
 
 int main(){
                    //오른쪽 수가 크면 참.
    cout<<less_than(2,3)<<endl;             //1
    cout<<less_than(2.1, 2.9)<<endl;        //1
    cout<<less_than(2.7, 2.2)<<endl;        //0
    //cout<<less_than(2, 2.2)<<endl;        //두개의 타입이 다를경우는 불가능하다..
            //해결하려면 템플릿을 여러개 만들어주면된다.
 
 //  template<class T, class V>
 //  bool less_than(T a, V b){return a<b;}
 //  이런식으로 해주면 여러 자료형입력에 대해 비교가 가능하다.
 
    string word1 = "ABC", word2 = "XYZ";
 
    cout<<less_than(word1, word2)<<endl;    //1
    cout<<less_than(word2, word1)<<endl;    //0
 //1 = True  ,  0 = False
 
 return 0;
 }
*/


/*
 만약 템플릿을 쓰지 않았다면 함수 오버로딩을 해야한다.
 ex)
 bool less_than(int x, int y){return x<y;}
 bool less_than(double x, double y){return x<y;}
 */



/*
 template <typename T>
 //입력이 들어오는 자료형을 T가 치환해준다.
 bool less_than(T a, T b){   //함수의 입력인자를 정수인지 실수인지 문자열인지 등을 따로 받지 않는다.
    return a < b;
 }//less_than 이라는 함수를 만듬.

 template<class T>           //함수별로 하나씩 적어주면 된다.. 1함수 1템플릿 으로 이해하면 된다.
T sum(const vector<T>& v){
    T result = 0;
    for(auto elem : v)
        result += elem;
    return result;
 }
 
 int main(){
 //오른쪽 수가 크면 참.
    cout<<less_than(2,3)<<endl;             //1
    cout<<less_than(2.1, 2.9)<<endl;        //1
    cout<<less_than(2.7, 2.2)<<endl;        //0
 
    vector<int> v1{1,2,3,5};
    vector<double> v2{10.1, 20.2, 30.3, 40.2};
    cout<<sum(v1)<<endl;
    cout<<sum(v2)<<endl;
 
 return 0;
 }
*/

//Template을 유용하게 쓸 수 있는 곳이 바로 Class이다.(무조건 시험출제)

//[Class에 적용]
/*
 template<class T>
 class Point{
 T x, y; //다양한 자료형을 받을 수 있음.
 public:
    Point(T _x, T _y):
    x(_x),y(_y){}
 
    void setXY(T _x, T _y){
        x = _x;
        y = _y;
    }
    T getX(){return x;}
    T getY(){return y;}
    void print(){
        cout<<x<<", "<<y<<endl;
    }
 };
 
 int main(){
    Point<int> pt1(1, 2);        //클래스를 템플릿으로 만들면 멤버변수가 어떤 데이터타입인지 선언해줘야한다.
    Point<double> pt2(1.1, 2.2);
 
    pt1.print();
    pt2.print();
 
 //클래스를 템플릿으로 만들면 어려운 점이하나가 있다. 선언부와 구현부를 분리하고싶다면 기존방법과 조금은 다르게 해야한다.
 
 }
*/


//선언부 구현부 나누는 경우

/*
 template<class T>
 class Point{
    T x, y; //다양한 자료형을 받을 수 있음.
 public:
    Point(T _x, T _y);          //1)
    void setXY(T _x, T _y);     //2)
    T getX();                   //3)
    T getY();                   //4)
    void print();               //5)
 };
 
 int main(){
    Point<int> pt1(1, 2);        //클래스를 템플릿으로 만들면 멤버변수가 어떤 데이터타입인지 선언해줘야한다.
    Point<double> pt2(1.1, 2.2);
 
    pt1.print();
    pt2.print();
        //클래스를 템플릿으로 만들면 어려운 점이하나가 있다. 선언부와 구현부를 분리하고싶다면 기존방법과 조금은 다르게 해야한다.
 }
 //템플릿의 경우 .cpp와 .hpp로 나눌수없다. 즉, 파일을 분리할 수는 없다.
 //이렇게 두 가지를 더 해줘야 한다..
 //멤버함수마다 template<class T>를 붙여주고
 //class<T>::를 해줘야한다.
 template<class T>
 Point<T>::Point(T _x, T _y):x(_x),y(_y){}   //1)
 
 template<class T>
 void Point<T>::setXY(T _x, T _y){           //2)
 x = _x;
 y = _y;
 }
 
 template<class T>
 T Point<T>::getX(){return x;}               //3)
 
 template<class T>
 T Point<T>::getY(){return y;}               //4)
 
 template<class T>
 void Point<T>::print(){cout<<x<<", "<<y<<endl;}//5)
 */
 //Listing 19.7~19.8 꼭 볼 것..


/*
 //[list]
 #include <list>     //vector와 동작이 비슷(상황에 따라 다르게 쓴다)
 //vector는 search가 빠르지만 pop/push가 느리다.
 //list는 search가 느리지만 pop/push가 빠르다.
 int main(){
    list<int> mylist{};
 
    char command;
    int inputval;
    bool finish = false;            //프로그램이 끝날때 알릴려고
    while(!finish){
    //command입력받음
    cout<<"I)nput, P)rint, L)ength, E)mpty, Q)uit >> ";
    cin >> command;
                    //command에 따라 기능수행
 
    switch(command){
        case 'I':
        case 'i':
        cin>>inputval;
        mylist.push_back(inputval);
        break;
 
        case 'P':
        case 'p':
        for(auto elem : mylist)
        cout<<elem<<'\t';
        cout<<endl;
        break;
 
        case 'L':
        case 'l':
        cout<<"Number of items: "<<mylist.size()<<endl;
        break;
 
        case 'E':
        case 'e':
        mylist.clear();
        cout<<"Clear the List"<<endl;
        break;
 
        case 'Q':
        case 'q':
        finish = true;
        cout<<"Exit the Program"<<endl;
        break;
 
        default:
        cout<<"Wrong Command"<<endl;
        break;
        }
    }
    return 0;
}
*/


/*
//[Standard Pointer-like Objects]_Iterator  (Pointer와 같은 기능을 한다)
//begin과 end라는 함수를 이용한다.
int main(){
    int ary[] = {1, 2, 3, 4};
    int *pBegin , *pEnd;
                    //0x00 = 1, 0x01 = 2, 0x02 = 3, 0x03 = 4
 
    pBegin = ary;   //ary의 시작 주소값.  (0x00)
    pEnd = ary+4;   //(0x04) 마지막 element주소값의 다음값(허공)을 가리킴.   (중요!!!!!!!)
    for(int *pIter = pBegin; pIter != pEnd; pIter++)
        cout<<*pIter<<'\t';         //0x04가 되기 직전까지 반복한다.
    cout<<endl;
 
 
    vector<int> v {10, 20, 30, 40};  //일종의 container(여러 오브젝트를 모아서 관리)
    vector<int>::iterator iter_begin = begin(v);        //시작 주소값을 저장(포인터랑 100%같은 내용)
     // == auto iter_begin = begin(v); 라 해도 똑같다.
    vector<int>::iterator iter_end = end(v);        //벡터의 끝 주소값을 리턴하는 함수
 
 
    for(auto iter = iter_begin; iter != iter_end; iter++)
        //auto == vector<int>::iterator
        cout<<*iter<<'\t';
    cout<<endl;
 //시작부터 끝까지 반복해서 출력
 //1) auto
 //2) begin()  시작 주소값을 리턴
 //3) end()    끝 주소값을 리턴
 
 //iterator는 베열, 벡터, 리스트에 동작.
    return 0;
 }
*/



 //[List, Vector, Array]
#include <list>

//container에 generic한 함수를 만들기 위해서는
// 1)template사용
// 2)begin(), end()를 입력 인자로 사용


//포인터는 연산이 가능하다.
//Iterator는 객체이기 때문에 몇가지의 연산은 가능한데..(iter++, iter--, *iter, iter != iter1, iter1 == iter2 )
//다른건 안됨 ex) iter += 2,   iter = iter - 4  이런건 안됨.
template<class Iter>
void print(Iter iter_begin, Iter iter_end){
    for(auto iter = iter_begin; iter != iter_end; iter++)
        cout<<*iter<<'\t';
    //마지막 주소값의 다음주소값까지..
    cout<<endl;
}
template<class Iter>
void print_reverse(Iter iter_begin, Iter iter_end){
    Iter iter = iter_end;
    while(iter != iter_begin){
        iter--;   //iter는 맨마지막 주소값의 그 다음 값을 가리키므로 비긴과 앤드가 값이 다르면 허공인 값을 가리키고 그값을 하나 빼야 마지막 원소가 나오게 된다.
        cout<<*iter<<'\t';
    }
    cout<<endl;
}

int main(){
    vector<int> v{1, 2, 3, 4};                  //vector
    list<double> l {1.1, 2.2, 3.3, 4.4};        //list
    int ary[] = {100, 200, 300, 400};           //array
                                                //3가지 타입에 대해 iterator가 가능하다.
    //프린트가 3개에 대해 다 동작하게끔..
    cout<<"-----NORMAL-----"<<endl;
    print(begin(v), end(v));
    print(begin(l), end(l));
    print(begin(ary), end(ary));
    
    cout<<"-----REVERSE-----"<<endl;
    print_reverse(begin(v), end(v));
    print_reverse(begin(l), end(l));
    print_reverse(begin(ary), end(ary));
    
    return 0;
}
