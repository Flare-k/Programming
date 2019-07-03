#include <iostream>
#include <string>
#include <vector>
#include "coffee.hpp"
#include "handdrip.hpp"
#include "espresso.hpp"

using namespace std;
int main(){
    coffee* curCoffee;
    vector<coffee*> coffeeShop;
    int select;
    
    cout<<"<<<<SoftCon Cafe management program>>>>"<<endl;
    
    curCoffee = new handDrip("YegaCheff", "city", 30, 93.2, 2, 49, "Kalita");
    coffeeShop.push_back(curCoffee);
    
    cout<<endl<<"First Order"<<endl;
    curCoffee->makeCoffee();
    
    curCoffee = new espresso("KenyaAA", "fullcity", 40, 92.7, 9.7, 29);
    coffeeShop.push_back(curCoffee);
    
    cout<<endl<<"Second Order"<<endl;
    curCoffee->makeCoffee();
    
    cout<<endl<<endl<<"<<<<Close the Cafe>>>>"<<endl<<"Read the Today Shop"<<endl;
    for(coffee* temp : coffeeShop)
        temp->printinfo();
    
    
    delete curCoffee;
    
    
    return 0;
}
