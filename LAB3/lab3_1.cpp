#include <iostream>
using namespace std;

int main()
{
    int x;
    
    while(1)
    {
        cout<<"number:";
        cin>>x;
        
        if(x>0)
        {
            if(x%2==1)
                cout<<x<<" is odd."<<endl;
            else
                cout<<x<<" is even."<<endl;
        }
        else
            break;
    }
    cout<<"Terminate Program."<<endl;
    
    return 0;
}
