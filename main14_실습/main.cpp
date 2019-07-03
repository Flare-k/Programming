#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <cctype>
#include <functional>
using namespace std;
/*
int main(){
    
    list<int> seq{5, 22, 6, -3, 8, 4};
    
    for_each(begin(seq), end(seq), [](int x){cout<<x<<' ';});
    cout<<endl;
    
    for_each(begin(seq), end(seq), [](int& x){x++;});           //call by ref. 주의.
    for_each(begin(seq), end(seq), [](int x){cout<<x<<' ';});
    cout<<endl;
}
*/


/*
int main(){
    
    vector<int> seq{2,3,4,5,6};
    
    for_each(begin(seq), end(seq), [](int x) {cout<<x<<' ';});
    
    cout<<endl;
    
    if(seq.size() >= 2){
        vector<int> seq2(seq.size() - 2);   // seq2(3)
        copy(begin(seq) + 1, end(seq) - 1, begin(seq2));        //copy부분 다시볼것
    
    for_each(begin(seq2), end(seq2), [](int x){cout<<x<<' ';});
    }
    
    cout<<endl;
    return 0;
}
*/

/*
int main(){
    string name = "Fred",
    str = "abcDEF-GHIjkl345qw",
    alpha = "eLePhAnT";
    
    cout<<"Before: "<<name<<" "<<str<<" "<<alpha<<endl;
    transform(begin(name), end(name), begin(name), ::toupper);
    transform(begin(str), end(str), begin(str), ::toupper);
    transform(begin(alpha), end(alpha), begin(alpha), ::tolower);
    cout<<"After: "<<name<<" "<<str<<" "<<alpha<<endl;
}
*/



/*
int evaluate2( function<int(int, int)>func, int x, int y){
    return func(x, y);
}

int main(){
    int a;
    cout<<"Enter an integer: ";
    cin>>a;
    cout<<evaluate2([a](int x, int y){  if(x==a)
        x = 0;
    else
        y++;
        cout<<x<<"+"<<y<<"=";
        return x+y;
    }, 2, 3)<<endl;

}

*/
