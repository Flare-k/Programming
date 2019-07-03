#include <iostream>
using namespace std;

int main()
{
    int x, y;
    
    while(1)
    {
        cout<<"number:";
        cin>>x;
        if(x<=9)
        {
            for(y=1; y<=9; y++)
            {
                cout<<x<<"*"<<y<<"="<<x*y<<endl;
            }
        }
        else
            break;
    }
            cout<<"Terminate Program."<<endl;
    
    return 0;
}
