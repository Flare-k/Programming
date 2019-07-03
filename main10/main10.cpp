//Soft
#include <iostream>
using namespace std;

class Point{
private:
    int x;
    int y;
    static int numCreatedObjects;       //몇개의 객체가 생성되었는지 세줌.
    //ifstream fin;
public:
    Point(): x(0), y(0){
        numCreatedObjects++;
        //fin.open("test.txt");
        //ary = new int[100];
    }       //아무것도 안 들어갈 경우.
    Point(int _x, int _y): x(_x), y(_y){
        numCreatedObjects++;            //static은 객체 밖에서 초기화 해줘야한다.
    }
                                //함수가 같고 입력이 다른경우 함수 오버로딩이라고 함 (이 줄에선 생성자 함수를 오버로딩함)
    ~Point(){
        //fin.close();
        //delete[] ary;
        cout<<"Destructed.."<<endl;     //객체가 사라질때마다 나타남 delete를 만날때마다..
    }                                   //객체가 내부적으로 파일 등을 가지고 있을때 마지막으로 프로그램이 끝날때 파일을 닫아줘야하는데 그때 소멸자를 쓴다.
    
    void setXY(int _x, int _y);
    
    int getX() const{return x;}
    int getY() const{return y;}     //print함수 때메 const를 설정함.
    
    //operator overloading
    Point operator+(Point& pt2){            //클래스 멤버함수이기 때문에 안보이지만 좌측에 자기자신이 있고 우측엔 다음과 같은 입력파라미터를 받는다.
        Point result(x + pt2.x, y + pt2.y);     //현재객체 + pt2  즉 x or y + pt2
        return result;
    }friend ostream& operator<<(ostream& cout, Point& pt);  //private에도 접근 가능하게 해줌
    
    /*      //멤버함수가 아닐경우 다음과 같이 매개변수 둘 다 써줘야 한다.
     Point operator+(Point& pt1, Point&pt2){
     Point result(pt1.getX() + pt2.getX(), pt1.getY()+pt2.getY());
     return result;
     }
     */
    
    Point operator = (Point& pt){
        x = pt.x;
        y = pt.y;
        return (*this); //현재 연산자로 리턴
    }
    static int getNumCreatedObjects(){return numCreatedObjects;}    //처음에 선언할땐 static 적어줘야함
    
    friend class SpyPoint;      //하지만 포인트클래스는 스파이클래스 내용을 사용하지 못함. 포인트도 스파이꺼를 쓰고 싶으면 스파이 클래스에 가서 프렌드를 해줘야한다.
    
};

//객체를 const로 입력 받으면 반드시 const로 선언된 멤버 함수만 사용가능.
void print(const Point& pt){  //참조자를 주면 값을 복사하지 않아도된다.
    cout<<pt.getX()<<", "<<pt.getY()<<endl<<endl;
}



//1.cout<<pt<<endl;
//2.(cout<<pt)<<endl;       괄호친부분이 먼저 출력
//3.cout << endl;       cout을 리턴해줘야 endl이 그다음에 출력이 되는 것.
ostream& operator<<(ostream& cout, Point& pt){              //클래스의 멤버함수가 아니라 외부함수이기 때문에 입력매개변수를 좌우로 2개받음
    cout << pt.getX() <<", "<<pt.getY();
    return cout;
}



class SpyPoint{             //Point 클래스에 있는 모든 함수들을 가져와서 출력해주는 클래스. Point를 friend로 가져와야함
public:
    void hack_all_info(Point& pt){
        cout<<"Hacked by SpyPoint"<<endl;
        cout<<"x: "<<pt.x<<endl;
        cout<<"y: "<<pt.y<<endl;
        cout<<"numCreatedObjects: "<<pt.numCreatedObjects<<endl;
    }
};


int main(){
    
    Point pt1(1, 2);  //두번째 생성자가 호출이됨                   //1, 2
    print(pt1);
    
    //객체도 포인터로 선언해서 사용할 수 있다.
    Point *pPt1 = &pt1;                 //pPt1이 pt1의 주소를 가리킴
    cout<<(*pPt1).getX()<<", "<<(*pPt1).getY()<<endl;       //1, 2
    //cout<<pt1.getX()<<", "<<pt1.getY()<<endl;
    //좀 더 쉽게 접근하는 방법
    cout<<pPt1->getX()<<", "<<pPt1->getY()<<endl;           //1, 2
    
    //동적으로 객체를 할당 받으려면??? cin을 통해 배열의 길이를 입력받고 원할때마다 바꿀수있다.
    Point *pPt2 = new Point(10, 20);     //10,20으로 초기화시킴 -> 어떤 메모리 공간에 이름없는 객체하나를 만들고 그 객체안에 엑스엔 10 와이엔 20을 집어 넣음
                                         //그 객체의 시작주소값을 pt2에 집어 넣음
    cout<<pPt2->getX()<<", "<<pPt2->getY()<<endl;
    delete pPt2;    //단일 객체라 delete[]라고 표시안해줌 ... 배열의 경우는 []를 해줌
    
    //Point* pPt3;  pPt3->setXY(x , y);  //이렇게 하면 말이 안됨!
    
    
    
    //함수 오버로딩을 통해 연산자 오버로딩을 할 수 있다.
 //   int a = 3+5;
    Point pt2(10, 20), pt3(30, 40);
    //pt2 + pt3 == pt2 + (pt3)
    Point pt4 = pt2 + pt3; //연산자 오버로딩을 통해 이 수식이 가능하게 만들 수 있다.
                            //Operator + (Point& pt2, Point& pt3)
    cout<<"pt2:"<<pt2<<endl;
    cout<<"pt3:"<<pt3<<endl;        //operator<(cout, pt2)
    cout<<"pt4 = pt2 + pt3 : "<<pt4<<endl;

    cout<<pt4.getNumCreatedObjects()<<endl<<endl;   //몇개의 객체가 만들어졌는지 알려줌   pt1, pt2 뭐라고 쓰든 같은 값을 공유하므로 값이 같게나온다.
    
    
    Point* ptAry = new Point[5];    //5개의 객체가 있는 배열을 만듬
    cout<<pt2.getNumCreatedObjects()<<endl;
    delete [] ptAry; // 배열 할당해제
    
    SpyPoint spy;
    spy.hack_all_info(pt1);
    spy.hack_all_info(pt4);
    
    return 0;
}

//static 멤버 변수 초기화
int Point:: numCreatedObjects = 0;


void Point::setXY(int _x, int _y){x = _x; y = _y;}; //함수 밖에다가 클래스의 멤버함수를 정의하면 보기에 더 깔끔하다.















/*
 <복습>
 연산자 오버로딩
 디스포인터
 객체 포인터
 */

/*
 [this pointer] 객체 자신의 시작 주소값을 담고있다.
 void setXY(int x, int y){
    this->x = x;
    this->y = y;
 
 }
 int getX() const{return this->x;}
 int getY() const{return this->y;}
 
 
 */


