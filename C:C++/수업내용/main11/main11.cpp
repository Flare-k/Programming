//   연산자 오버로딩 복습

#include <iostream>
#include <string>
using namespace std;
/*
class Point{
private:
    int x;
    int y;
    
public:
    Point(int _x=0, int _y=0):x(_x),y(_y){}

    void print(){cout<<x<<", "<<y<<endl;}
    
    Point operator-(const Point& pt){       //const를 붙여줘야 동작이 잘된다. 어떤 빼기라도 내부적으로 피연산자를 바꾸진 않는다.
        Point result(this->x - pt.x, this->y - pt.y);   //pt1 - pt2
        return result;                      //마이너스 연산자를 만나면 연산자 오버로딩을 실행하여 result객체에 저장한다..
    }   //Point에 &을 쓰면 안된다.(녹음확인)
    Point operator*(const Point& pt){
        Point result(this->x * pt.x, this->y * pt.y);   //result로 저장된 마이너스 값들을 곱하기로 다시 result에 저장한다.
        return result;
    }   //Point에 &을 쓰면 안된다.(녹음확인)

//    Point operator=(const Point& pt){
//        this->x = pt.x;                     //=을 만나면 값을 리턴해준다.
//        this->y = pt.y;
//        return(*this); //현재 자기 자신의 시작주소값을 같는 포인터.
//    }

    //ex) pt1 = pt2 = pt3;
    //pt2가 자기 자신 pt3가 입력이됨
};

int main(){
    Point* pPt1 = new Point(1, 2);
    Point* pPt2 = new Point(3, 4);
    Point* pPt3 = new Point;
    
    *pPt3 = (*pPt1 - *pPt2)*(*pPt1 - *pPt3);         //객체끼리 빼기와 곱 assignment가 가능한 연산자가 필요.
            //1자기자신으로 빼기가 되고 2가 입력으로 들어간다.
    
    pPt3->print();
    return 0;
}
*/

 ///////////////////////////////////////////////////////////////////////////////////////////////////

//[Inheritance] _ 본 수업 내용.
/*
 부모클래스에서 만든걸
 자식클래스에서 쉐어할 수 있다.
 부모클래스 = 베이스클래스 / 슈퍼클래스
 자식클래스 = 디라이브드 클래스/ 서브클래스
 두번 코딩할걸 한번만 하면 된다.
 
 */

/*
class Base{
public:     //Base클래스의 타입
    void print_base(){cout<<"Base"<<endl;}
};

//  Base type  |     상속 type      |  Derived type
//   private   |    상관 없음        |(Base 함수로)접근 불가
//   protected |     상관 없음       |    private
//   public    |private/protected |     private
//   public    |     public       |     public

//protected = private과 비슷한데.. 부모와 자식 각각 private으로 동작하게 해준다.

class Derived: public Base{     //public이 상속타입이다.. 베이스에 있는 퍼블릭을 사용해옴.
                                //만약 private으로 상속받으면 더이상 메인에서 Base의 프린트함수를 쓸 수 없음.
public:
    void print_derived(){
        //Base::print_base();  private으로 가져올 경우 부모 함수를 자식클래스 내부에서만 사용가능
        cout<<"Derived"<<endl;}
    
};

int main(){
    Base base;
    base.print_base(); //base클래스는 자신의 멤버함수 이용가능한건 당연
    
    Derived derived;
    derived.print_base();   //부모클래스의 함수를 쓸수있고
    derived.print_derived();//자신의 함수를 쓸수도 있다.
    
    
    
    return 0;
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////

/*
함수 오버로딩 = 같은 이름을 가진 함수는 입력데이터타입, 입력데이터 갯수가 다른 것.
   ex)  int sum(int x, int y)
        double sum(double x, double y)
        float sum(float x, float y, float z)
 
함수 오버라이딩 = 상속에만 국환되어서 사용되는 개념, 부모클래스를 상속받았는데 별로여서 멤버변수만 그대로 쓰고 싶은데 함수는 고쳐쓰고 싶음,
    그 때는 오버라이딩을 한다. 즉, 이름과 아웃풋은 같은데 자식 클래스에서 재정의하는 개념이다.
 ex)    void Text::append(string _extra)
        void Fancy::append(string _extra)           (변수 이름은 달라도 되지만 타입이나 개수는 같아야 함)
 
 
 
 베이스에 프린트함수가 있고 자식클래스에 프린트를 다시정의.
 완전히 동일한 함수명, 입력파라미터를 가진다. 하지만 자식 클래스에서 좀 더 복잡하게 재정의한다.
 
 virtual은 Base에 붙여서 자식에서 재정의 될걸 알려줌
 override는 자식 클래스에 붙여서 오버라이딩 됨을 알려줌
*/
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


class Text{
private:
    string text;
public:
    Text(string _t) : text(_t){}

    virtual string get(){return text;}
    virtual void append(string _extra){text += _extra;}     //virtual 안 써줘도 오버라이딩이 잘 되기는 하지만 습관화하면 좋다.
};


class FancyText: public Text{
private:
    string left_brac;
    string right_brac;
    string connector;
public:
    FancyText(string _t, string _lb, string _rb, string _con):
    //innitialize list는 생성자를 호출할 수 있게 해준다.
        Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_con){}
    //맴버변수가 아닌 생성자를 집어넣음.. 부모클래스의 private을 바꾸는 유일한 방법은 함수를 이용하는 것..
    //부모의 string text를 호출하여 _t로 ...         (중요!!!!!!!!!!!!!!)
    //Text::Text(_t) == 부모클래스에 있는 생성자를 불러옴.. 생성자를 불러와서 함수를 이용하여 부모클래스에 있는 private을 이용할 수 있다.
    string get() override{return left_brac + Text::get() + right_brac;}         //함수 오버라이딩함.
                                            //Text::get()함으로써 부모클래스에있는 private의 text를 가져옴.
    void append(string _extra) override{
       // text = text + connector + _extra;
        Text::append(connector + _extra);       //부모 append의 input parameter로 connector+_extra가 들어가게 됨.
               // text = text + connector + _extra가 추가 된다.
    }
};


class FixedText : public Text{
public:
    FixedText():Text::Text("FIXTED"){}              //생성자에 부모클래스 생성자를 가져옴. FancyText에서 사용했듯이...
    void append(string _extra) override{
    //아무것도 수행안함..
        //nope!!
    }//즉, 항상 FIXED라는 값만 갖는다.
};

int main(){
    
    Text t1("Plain");
    t1.append("A");
    cout<<t1.get()<<endl;
    
    FancyText t2("Fancy", "<<", ">>", "***");
    t2.append("A");
    cout<<t2.get()<<endl;
    
    FixedText t3;
    t3.append("A");
    cout<<t3.get()<<endl;           //여기서 get은 부모클래스의 것을 사용한 것.
    
    //t1 = t2;    //드라이브를 베이스로 어사인할수는 있으나
    //t2 = t1;    //베이스를 디라이브로 어사인 할 수는 없다.
    
    return 0;
}

