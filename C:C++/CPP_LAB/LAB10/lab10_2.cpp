#include <iostream>
#include <vector>
using namespace std;

int main(){
    srand((unsigned int) time(NULL));
    
    vector<int> v1(10);
    vector<int> v2(10);
    
    cout<<"<Vector1>"<<endl;
    for(int i = 0; i < v1.size(); i++){
        v1[i] = rand()%11;
        cout<<v1[i]<<'\t';
    }
    cout<<endl;

    cout<<"<Vector2>"<<endl;
    for(int i = 0; i < v2.size(); i++){
        v2[i] = rand()%21;
        cout<<v2[i]<<'\t';
    }
    cout<<endl;

    vector<int>::iterator iter_begin1 = begin(v1);
    vector<int>::iterator iter_end1 = end(v1);
    
    vector<int>::iterator iter_begin2 = begin(v2);
    vector<int>::iterator iter_end2 = end(v2);
    
   
    int max1 = 0, max2 = 0;
    int min1 = 0, min2 = 10;
    
    
    for(auto iter1 = iter_begin1; iter1 != iter_end1; iter1++){
        for(auto iter2 = iter_begin2; iter2 != iter_end2; iter2++){
            max1 = (*iter1) * (*iter2);
            if(max1 > max2){
                max2 = max1;
            }
        }
    }
    cout<<endl;
    cout<<"MAX = "<<max2<<endl;

    for(auto iter1 = iter_begin1; iter1 != iter_end1; iter1++){
        for(auto iter2 = iter_begin2; iter2 != iter_end2; iter2++){
            min1 = (*iter1) * (*iter2);
            if(min1 < min2){
                min2 = min1;
            }
        }
    }
    cout<<"MIN = "<<min2<<endl;

    
    
    return 0;
}
