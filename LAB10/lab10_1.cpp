#include <iostream>
#include<cmath>
using namespace std;

template <class type>
class Point{
    type x, y, z, w;
public:
    Point(type _x, type _y, type _z, type _w):
    x(_x),y(_y),z(_z),w(_w){}
    Point(){}
    ~Point(){}
    
    void setX(type _x){x=_x;}
    void setY(type _y){y=_y;}
    type getX(){return x;}
    type getY(){return y;}

    void setPointFromKeyboard(){
        cout<<"첫번째 x: ";
        cin>>x;
        cout<<"첫번째 y: ";
        cin>>y;
        
        cout<<"두번째 x: ";
        cin>>z;
        cout<<"두번째 y: ";
        cin>>w;
    }

    
    void print(){
        cout<<"두 점 사이의 거리 = "<<type(sqrt( pow(x-z,2) + pow(y-w,2) ))<<endl;
    }
};

int main()
{
   
    Point<float> p;
    
   
    p.setPointFromKeyboard();
    
    p.print();
    return
    0;
}
