
#include <iostream>
using namespace std;

bool compareTF(int dynamicArr[]);

void print(int dynamicArr[], int n){
    while(1){
        cout<<"Please enter number of values to process: ";
        cin>>n ;

        if(n > 0){
            cout<<"Please enter numbers: ";
                for(int j = 0; j < n; j++){
                    cin>>dynamicArr[j];
                }
        }
        else
            break;
        
        if(compareTF(dynamicArr))
            cout<<"False"<<endl;
        else
            cout<<"True"<<endl;
    }
    cout<<endl;
}

int main()
{
    int n;
    
    int *dynamicArr = new int[n];
    
    print(dynamicArr, n);
    
    
    if(!dynamicArr){
        cout<<"Don't assign to Memory";
    }
    delete[] dynamicArr;
    
    return 0;
}

bool compareTF(int dynamicArr[]){
    int j = 0;
    
    for(int i = 0; i <100; i++){
        if(dynamicArr[i] == dynamicArr[j])
            return false;
        j++;
    }
    return true;
}


