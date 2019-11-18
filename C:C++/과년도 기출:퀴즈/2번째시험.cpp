#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class VectorList{
    vector<double*> vItem; //Item(array)의 pointer저장
    vector<int> Length; //Item(array)의 길이저장
public:
    VectorList(){}
    ~VectorList(){
      //  cout<<"Destructed~"<<endl;
    }
    void append(double* _pArray, int _length){
        for(int i = 0; i < _length; i++){
            _pArray = new double;
            vItem.push_back(_pArray);           //벡터에다가 아이템 추가함.
        }
    }
    //    int findVector(double* _pArray, int _length){
     
//    }
    void print_single_vector(int idx){
        if(idx < 0){
            cout<<"[Wrong index]"<<endl;
        }
        else if(idx >= 0){
            cout<<idx<<"-th vector: "<<'\t';
            for(auto elem : vItem)
                cout<<*elem<<'\t';
        }
        
    }
    void print_all_vectors(){
        
    }
};


int main(){
    VectorList vectorList;
    double* pTemp = new double[3] {1.1 , 2.2, 3.3};      //0번째.
    vectorList.append(pTemp, 3);
   
    pTemp = new double[5] {10.1, 10.2, 10.3, 10.4, 10.5};
    vectorList.append(pTemp, 5);

    pTemp = new double[2] {4.5, 5.5};
    vectorList.append(pTemp, 2);
    
    vectorList.print_single_vector(-1);
    vectorList.print_single_vector(0);
    cout<<endl;
    
    vectorList.print_all_vectors();
    cout<<endl;

    double* pTemp1 = new double[2]{4.5, 5.5};
    double* pTemp2 = new double[4]{1.1, 2.2, 5.5, 4.4};
    
   // cout<<"Index of vector{4.5, 5.5}:"<<vectorList.findVector(pTemp1, 2)<<endl;
   // cout<<"Index of vector{1.1, 2.2, 5.5, 4.4}:"<<vectorList.findVector(pTemp2, 4)<<endl;
    
    delete [] pTemp;
    delete [] pTemp1;
    delete [] pTemp2;
    
    return 0;
}
