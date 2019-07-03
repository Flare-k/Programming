#include <iostream>
using namespace std;

int main()
{
    int x=1, input;
    int sum=0;
    
    cout<<"Enter the number:";
    cin>>input;
    
    while(x<=input)
    {
        if(x%2!=0 && x%3!=0)
            sum+=x;
            x++;
    }
    cout<<"Sum:"<<sum<<endl;
    return 0;
}
