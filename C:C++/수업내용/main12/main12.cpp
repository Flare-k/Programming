//[Inheritance II] _5/7(화)
/*
 다형성(Polymorphism)을 아는가? 객체지향프로그래밍의 핵심이다.
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
class Base{
public:
    
    void f(){cout<<"Base::f()"<<endl;}      //이 함수를 클래스내 뿐만아니라 메인에서도 사용가능하다.
    virtual void vf(){cout<<"Base::vf()"<<endl;}

};

class Derived: public Base{  //부모클래스에서 protected 면 여기선 private, public이면 public
public:                         //부모클래스에서 private이면 얘는 상속 못 함
    void f(){cout<<"Derived::f()"<<endl;}
    void vf() override {cout<<"Derived::vf()"<<endl;}
};
//
int main(){
    Base base;
    Derived derived;
    Base *pBase;
    cout<<"[ 정적바인딩 ]"<<endl;

    base.f();           //부모클래스의 객체이므로 부모클래스의 메소드를 실행함
    base.vf();           //부모클래스의 객체이므로 부모클래스의 메소드를 실행함
    derived.f();         //자식클래스의 객체이므로 자신의 메소드를 실행함
    derived.vf();           //여기까지 정적바인딩..
    cout<<"[ 동적바인딩 ]"<<endl;
   // 동적 바인딩은 베이스클래스의 포인터를 가지고
   // 변수안의 시작 주소값이 들어간다..
    pBase = &derived;           //부모클래스 객체의 주소값을 가져오면(pBase = &base)?? 부모클래스의 멤버함수를 가져온다.
    pBase -> f();               //부모 클래스의 객체가 부모 클래스를 뱉는다.
    pBase -> vf();              //부모 클래스의 객체가 자식 클래스를 뱉는다.
                                //차이는??? virtual override이다. f는 virtual override를 쓰지 않고 vf는 virtual override를 씀.
                                //virtual override를 쓰므로써,, [동적바인딩(다형성)이란 부모클래스의 포인터로 자식클래스 멤버함수 사용한다.]
                                //즉, 다형성에서의 키워드는 virtual override라고 할 수 있다.
                                //부모클래스의 포인터(single interface)   자식 클래스의 맴버 변수/함수(entities of different types)
                                //다형성.. 부모클래스의 포인터를 가지고 상황에 맞게 자식클래스의 객체들을 동적할당하여 이용하는 것이다.(중요)
   
    return 0;
    
}
*/

/*
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Base{
public:
    void f(){cout<<"Base::f()"<<endl;}      //이함수를 클래스 내 뿐만아니라 메인에서도 사용가능하다.
    virtual void vf(){cout<<"Base::vf()"<<endl;}
};
class Derived: public Base{  //베이스에서 protected 면 여기선 private, public이면 public
public:                         //private이면 얘는 이용못함
    void f(){cout<<"Derived::f()"<<endl;}
    void vf() override {cout<<"Derived::vf()"<<endl;}           //동적바인딩할거임
    
};
//
int main(){
   // Base base;
   // Derived derived;
    Base* pBase;
    vector<Base*> v{new Base,           //벡터 안에 부모클래스의 포인터를 넣음.
                    new Derived,
                    new Base};
                        //v안에는 객체가 아니라 주소값이 들어가는 것이다. 벡터안에 동적바인딩 기술을 이용하여 베이스 객체, 드라이브 객체도 넣을 수 있게해준다.
                        //다양한 객체들을 하나의 벡터에 저장할 수 있다.
    pBase = new Derived;
    v.push_back(pBase); //시작 주소값이 저장된다.
    pBase = new Base;
    v.push_back(pBase);
    cout<<"........"<<endl;
    for(Base* elem : v)   // == for(auto elem : v)          //Base가 가리키는 것들을 다 출력함
        elem -> vf();               //derived는 virtual override한 부분이 출력되는것.
    
    return 0;
}
*/
// vtable = 객체 안에서 어떤 멤버함수로 호출할지 결정하는 table, 멤버함수 시작 주소값 list


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//지난시간에 한 내용을 가져옴..(다형성을 복습)
class Text{
private:
    string text;
public:
    Text(string _t) : text(_t){}
    
    virtual string get(){return text;}
    virtual void append(string _extra){text += _extra;}
};
class FancyText: public Text{
private:
    string left_brac;
    string right_brac;
    string connector;
public:
    FancyText(string _t, string _lb, string _rb, string _con):
    Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_con){}
    
    string get() override{return left_brac + Text::get() + right_brac;}         //함수 오버라이딩함.
    
    void append(string _extra) override{
        Text::append(connector + _extra);
    }
};
class FixedText : public Text{
public:
    FixedText():Text::Text("FIXTED"){}
    void append(string _extra) override{
        //아무것도 수행안함..
        //nope!!
    }//즉, 항상 FIXED라는 값만 같는다.
};
//다형성: 부모클래스의 포인터로 자식클래스 객체를 사용
//핵심 Keywords : virtual, override


int main(){
    vector<Text*> v{new Text("Plain"),
                    new FancyText("Fancy1", "<", ">", "-"),
                    new FixedText};
    
    Text * pText;
    pText = new FancyText("Fancy2", "[", "]", "*");
    v.push_back(pText);
    pText = new Text("Plain2");
    v.push_back(pText);
    
    for(auto elem : v)
        elem -> append("A");
    //함수는 자식클래스의 함수가 실행이 된다.
    for(unsigned i = 0; i < v.size(); i++)
        cout<< i <<" : "<<v.at(i)->get()<<endl;   //v.at(i)->get()     .은 객체의 멤버변수/함수를 사용,, ->는 객체포인터일 경우..
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//virtual 함수~~ = 0 이라고 하면 아무런 동작을 하지 않는다. 순수 가상함수 ... 자식클래스에서 구현해야한다.
    //메인함수에서 선언할 수 없다.

//Abstract class : 적어도 하나의 멤버 함수가 순수 가상 함수
//특징: 메인에서 객체선언 못함 (포인터로는 가능)
//Text text(x), Text * pText (o)
//자식 클래스에서 반드시 순수 가상함수를 구현해야 함
/*
class Text{
private:
    string text;
public:
    Text(string _t) : text(_t){}
    
    virtual string get() = 0;                   //자식클래스에서 get & append를 구현해줘야한다.
    virtual void append(string _extra) = 0;
    
};


class FancyText: public Text{
private:
    string left_brac;
    string right_brac;
    string connector;
public:
    FancyText(string _t, string _lb, string _rb, string _con):
    Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_con){}
    string get() override{return left_brac + Text::get() + right_brac;}         //함수 오버라이딩함.
    void append(string _extra) override{
        Text::append(connector + _extra);
    }
};


class FixedText : public Text{
public:
    FixedText():Text::Text("FIXTED"){}
    void append(string _extra) override{
        //아무것도 수행안함..
        //noop!!
    }//즉, 항상 FIXED라는 값만 같는다.
    
};

//다형성: 부모클래스의 포인터로 자식클래스 객체를 사용
//핵심 Keywords : virtual, override
int main(){
    vector<Text*> v{new Text("Plain"),
        new FancyText("Fancy1", "<", ">", "-"),
        new FixedText};
    
    Text * pText;
    pText = new FancyText("Fancy2", "[", "]", "*");
    v.push_back(pText);
    pText = new Text("Plain2");
    v.push_back(pText);
    
    for(auto elem : v)
        elem -> append("A");
    //함수는 자식클래스의 함수가 실행이 된다.
    for(unsigned i = 0; i < v.size(); i++)
        cout<<i<<" : "<<v.at(i)->get()<<endl;           //v.at(i)->get()     .은 객체의 멤버변수/함수를 사용,, ->는 객체포인터일 경우..
    return 0;
}

*/
/////////////////////////////////////////////////////////////////////////////////////
/*
//[파일 분할]
//클래스를 효율적으로 관리하기 위해 클래스를 2가지로 나눔.
//.h파일과 .cpp파일로 나눠서..
//클래스 마법사 클래스 추가, 클래스이름(CText) (Windows)
//Text.h(선언부)    >>  ctrl+x 해서 헤더파일에 붙이기
//#pragma once 라고 쓰면 같은 클래스끼리 겹치지 않게 해준다.(헤더파일 내에서)
//메인함수쪽에 #include "CText.h"선언만 해주면 된다.
class Text{
private:
    string text;
public:
    Text(string _t);
    
    virtual string get();
    virtual void append(string _extra);
    
};
//Text.cpp(구현부)
// #include "CText.h"  헤더파일을 인클루드 해준다.
Text::Text(string _t) : text(_t){}
string Text:: get(){return text;}
void Text:: append(string _extra){text += _extra;}
//자료형 Text:: 함수명() {구현내용}

//CFancyText.h
//#include <string>
//#include "CText.h"
class FancyText: public Text{
private:
    string left_brac;
    string right_brac;
    string connector;
public:
    FancyText(string _t, string _lb, string _rb, string _con);
    string get() override;        //함수 오버라이딩함.
    void append(string _extra) override;
    
};
//#include "CText.h"
//CFancyText.cpp
//메인에선 헤더파일만 인클루드 해주면된다. #include "CFancyText.h"
FancyText::FancyText(string _t, string _lb, string _rb, string _con):
Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_con){}
string FancyText:: get(){return left_brac + Text::get() + right_brac;}
void FancyText:: append(string _extra){
    Text::append(connector + _extra);

    
    
class FixedText : public Text{
public:
    FixedText():Text::Text("FIXTED");
    void append(string _extra) override;
};

    FixedText::FixedText():Text::Text("FIXTED"){}
    void FixedText::append(string _extra) {
        //아무것도 수행안함..
        //noop!!
    }//즉, 항상 FIXED라는 값만 같는다.
    
    
    
//다형성: 부모클래스의 포인터로 자식클래스 객체를 사용
//핵심 Keywords : virtual, override
int main(){
    vector<Text*> v{new Text("Plain"),
        new FancyText("Fancy1", "<", ">", "-"),
        new FixedText};
    
    Text * pText;
    pText = new FancyText("Fancy2", "[", "]", "*");
    v.push_back(pText);
    pText = new Text("Plain2");
    v.push_back(pText);
    
    for(auto elem : v)
        elem -> append("A");
    //함수는 자식클래스의 함수가 실행이 된다.
    for(unsigned i = 0; i < v.size(); i++)
        cout<<i<<" : "<<v.at(i)->get()<<endl;           //v.at(i)->get()     .은 객체의 멤버변수/함수를 사용,, ->는 객체포인터일 경우..
    return 0;
}
*/
