//
//  espresso.cpp
//  2번째시험_3
//
//  Created by Flare_k on 16/05/2019.
//  Copyright © 2019 Kang. All rights reserved.
//

#include "espresso.hpp"
espresso::espresso(string _beans, string _roastingP, int a, int tem,int p, int t):
coffee::coffee(_beans, _roastingP), act(a), temper(tem),press(p), time(t){}

void espresso::printinfo() const {
    cout<<"Bean: "<<beans<<endl;
    cout<<"BaeJeonDo: "<<roastingP<<endl;
    cout<<"Amount: "<<act<<endl;
    cout<<"Temperature: "<<temper<<endl;
    cout<<"Press: "<<press<<endl;
    cout<<"Time: "<<time<<endl;
    cout<<"Driper: "<<driper<<endl;
}
void espresso::makeCoffee() {
    cout<<"Start press the espresso"<<endl;
    cout<<act<<"g's bean is pressed, "<<press<<"bar and Time is "<<time<<endl;
}
