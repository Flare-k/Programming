#include <iostream>
#include <string>
//#include "keyboard.hpp"
//#include "membrane.hpp"
//#include "mechanical.hpp"
using namespace std;

class keyboard{
private:
    int numKey;
    string language;
public:
    keyboard(int _numkey, string _language):
    numKey(_numkey),language(_language){}
    ~keyboard(){}       //순수가상함수 소멸자.
    
    void setNum(int _numkey){numKey = _numkey;}
    void setLan(string _language){language = _language;}
    virtual int getNum(){return numKey;}
    virtual string getLan(){return language;}
    
    virtual void print(){};
    
};
class mechanical: public keyboard{
public:
    mechanical(int _numkey, string _language):
    keyboard::keyboard(_numkey, _language){}
    ~mechanical(){}
    
    void print() override{
        cout<<"키 배열: "<<keyboard::getNum()<<endl;
        cout<<"언어: "<<keyboard::getLan()<<endl;
        cout<<"스위치: mechanical"<<endl;
        cout<<"타건음: 도각도각"<<endl;
        cout<<endl;
    }
};

class membrane: public keyboard{
public:
    membrane(int _numkey, string _language):
    keyboard::keyboard(_numkey, _language){}
    ~membrane(){}
    
    void print() override {
        cout<<"키 배열: "<<keyboard::getNum()<<endl;
        cout<<"언어: "<<keyboard::getLan()<<endl;
        cout<<"스위치: membrane"<<endl;
        cout<<"타건음: 투닥투닥"<<endl;
        cout<<endl;
    }
    
};

int main(){
    keyboard* keyP[2];
    keyP[0] = new membrane(106, "영어");
    keyP[1] = new mechanical(87, "한글");
    
    keyP[0]->print();
    keyP[1]->print();
    
    delete keyP[0];
    delete keyP[1];
    
    return 0;
}
