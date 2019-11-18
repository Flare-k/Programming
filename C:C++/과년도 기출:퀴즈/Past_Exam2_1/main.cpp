#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Item{
private:
    string code;
    string name;
    int price;
    
public:
    Item(string c = "", string n = "", int p = 0):
    code(c), name(n), price(p){}
   
    void setCode(string c){code = c;}
    void setName(string n){name = n;}
    void setPrice(int p){price = p;}

    string getCode(){return code;}
    string getName(){return name;}
    int getPrice(){return price;}
    
    
};


int main(){
    
    Item item1("C1001", "계산기", 14000);
    Item item2;
    
    item2.setCode("F1002");
    item2.setName("계란빵");
    item2.setPrice(1000);
    
    cout<<item1.getCode()<<setw(10)<<item1.getName()<<setw(10)<<item1.getPrice()<<endl;
    cout<<item2.getCode()<<setw(10)<<item2.getName()<<setw(10)<<item2.getPrice()<<endl;

    return 0;
}
