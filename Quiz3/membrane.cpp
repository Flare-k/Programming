#include "membrane.hpp"
membrane::membrane(int _numkey, string _language):
keyboard::keyboard(_numkey, _language){}
membrane::~membrane(){}

void membrane::print(){
    cout<<"키 배열: "<<keyboard::getNum()<<endl;
    cout<<"언어: "<<keyboard::getLan()<<endl;
    cout<<"스위치: membrane"<<endl;
    cout<<"타건음: 투닥투닥"<<endl;
    cout<<endl;
}
