#include <iostream>
#include <cmath>
using namespace std;


class Point{
    int x;
    int y;
    
public:
    Point(int _x = 0, int _y = 0):
    x(_x), y(_y){}
    
    void setPoint(int _x, int _y){
        cin>>x>>y;
    }
    Point operator-(const Point& pt){
        Point result(this->x - pt.x, this->y - pt.y);   //pt1 - pt2
            return result;
        }
        
    Point operator*(const Point& pt){
        Point result(this->x * pt.x, this->y * pt.y);
        return result;
        }
    
    Point operator=(const Point& pt){
        this->x = pt.x;
        this->y = pt.y;
        return(*this);
        }
    
    void print(){cout<<sqrt(x + y)<<endl;}
};


int main(){
    int x1 = 0, y1 = 0;
    int x2 = 0, y2 = 0;
    
    Point *pP1, *pP2, *pP3;
    
    cout<<"Input First [x1, y1]:";
    cin>>x1>>y1;
    
    cout<<"Input Second [x2, y2]:";
    cin>>x2>>y2;
    
    pP1 = new Point(x1, y1);
    pP2 = new Point(x2, y2);
    
    pP3 = new Point();
    
    
    *pP3 = (*pP1 - *pP2)*(*pP1 - *pP2);         //(x1-x2,y1-y2)^2
    
    cout<<"The distance between two points is ";
    pP3->print();
    cout<<endl;
    return 0;
}
