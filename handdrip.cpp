//
//  handdrip.cpp
//  2번째시험_3
//
//  Created by Flare_k on 16/05/2019.
//  Copyright © 2019 Kang. All rights reserved.
//

#include "handdrip.hpp"
handDrip::handDrip(string _beans, string _roastingP, int a, int tem,int t1, int t2, string d):
coffee::coffee(_beans, _roastingP), act(a), temper(tem), time1(t1), time2(t2), driper(d){}

void handDrip::printinfo() const {
    cout<<"Bean: "<<beans<<endl;
    cout<<"BaeJeonDo: "<<roastingP<<endl;
    cout<<"Amount: "<<act<<endl;
    cout<<"Temperature: "<<temper<<endl;
    cout<<"Time: "<<time1<<"min"<<time2<<"sec"<<endl;
    cout<<"Driper: "<<driper<<endl;
}
void handDrip::makeCoffee(){
    cout<<"Start press the espresso"<<endl;
    cout<<act<<"g's bean is pressed, and Time is "<<time1<<"min"<<time2<<"sec"<<endl;
    }
