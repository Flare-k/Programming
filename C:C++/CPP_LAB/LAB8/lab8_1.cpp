#include <iostream>
using namespace std;


class Polygon{
protected:
    int mPoint;
    double mLength;    
    
public:
    Polygon(){}
    Polygon(int point, float length): mPoint(point), mLength(length){}
    ~Polygon(){}
    
    virtual void calcGirth(){
        cout<<"Girth: empty"<<endl;
    }
    virtual void calcArea(){
        cout<<"Area: empty"<<endl;
    }
    

};

class Rectangle: public Polygon{
public:
    Rectangle(){}
    Rectangle(int point, float length): Polygon(point, length){}
    ~Rectangle(){}
    
    void calcGirth() override{
        cout<<"Girth:"<<mPoint*mLength;
    }
    void calcArea() override{
        cout<<endl;
        cout<<"Area:"<< mLength*mLength<<endl;
    }
};


int main(){
    
    Polygon pol;
    Rectangle rec(4, 10);
    
    cout<<"--- Polygon class ---"<<endl;
    pol.calcGirth();
    pol.calcArea();
    cout<<"---Rectangle class---"<<endl;
    rec.calcGirth();
    rec.calcArea();
    
    
    
    return 0;
}
