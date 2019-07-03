#include <iostream>
using namespace std;

int main()
{
    int sum=0;
    int input;
    
    cout<<"Enter the number:";
    cin>>input;
    

    for(int i=1; i<=input; i++)
    {
        sum += i;
    }
    cout<<"Sum:"<<sum<<endl;

    return 0;
}
