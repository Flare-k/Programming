#include <iostream>
using namespace std;


template<typename T>
class Array{
    T arr[50] = {};
    T size = arr.size();
public:
    Array(T s):
    size(s){}
    
    T setA(T s){size = s;}
    void getA(){return size;}
    
    void append(T x){
        int i = 0;
        arr[i] = x;
        i++;
        
        T temp = 0;
        
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 3; j++){
                if(arr[j] > arr[j+1]){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        
    }
    
    void print(){
        for(int i = 0; i < 4; i++){
         
            cout<<"["<<i<<"]: "<<arr[i]<<'\t';
        }
        cout<<endl;
    }
};


int main(){
    Array <int> iAry(50);
    iAry.append(5);
    iAry.append(13);
    iAry.append(1);
    iAry.append(7);
    iAry.print();
    
    Array<double> dAry(50);
    dAry.append(11.23);
    dAry.append(3.41);
    dAry.append(7.31);
    dAry.append(5.2);
    dAry.print();
    
    
    return 0;
}
