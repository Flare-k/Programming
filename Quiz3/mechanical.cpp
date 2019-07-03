//
//  mechanical.cpp
//  Quiz3
//
//  Created by Flare_k on 16/05/2019.
//  Copyright © 2019 Kang. All rights reserved.
//

#include "mechanical.hpp"
mechanical::mechanical(int _numkey, string _language):
keyboard::keyboard(_numkey, _language){}
mechanical::~mechanical(){}

void mechanical::print(){
    cout<<"키 배열: "<<keyboard::getNum()<<endl;
    cout<<"언어: "<<keyboard::getLan()<<endl;
    cout<<"스위치: mechanical"<<endl;
    cout<<"타건음: 도각도각"<<endl;
    cout<<endl;
}
