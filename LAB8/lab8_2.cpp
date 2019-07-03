#include <iostream>
#include <cmath>
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

class Triangle: public Polygon{
public:
    Triangle(){}
    Triangle(int point, float length): Polygon(point, length){}
    ~Triangle(){}
    
    void calcGirth() override{
        cout<<"Girth:"<<mPoint*mLength;
    }
    void calcArea() override{
        cout<<endl;
        cout<<"Area:"<< (mLength*mLength)*(0.25)*(sqrt(3))<<endl;
        
    }
};


class Circle: public Polygon{
public:
    Circle(){}
    Circle(int point, float length): Polygon(point, length){}
    ~Circle(){}
    
    void calcGirth() override{
        cout<<"Girth:"<<2*(3.14)*mLength;
    }
    void calcArea() override{
        cout<<endl;
        cout<<"Area:"<< (3.14)*mLength*mLength<<endl;
        
    }
};


int main(){
    Triangle tri(3, 10);
    Rectangle rec(4, 10);
    Circle cir(0, 5);
    
    cout<<"--- Triangle class ---"<<endl;
    tri.calcGirth();
    tri.calcArea();
    
    cout<<"---Rectangle class---"<<endl;
    rec.calcGirth();
    rec.calcArea();
    
    cout<<"---Circle class---"<<endl;
    cir.calcGirth();
    cir.calcArea();
    
    
    return 0;
}
