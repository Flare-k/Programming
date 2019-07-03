#include <iostream>
#include <string>
using namespace std;

int alpha1[26], alpha2[26];

int main(void){
    
    string a, b;
    
    
    cout<<"Please, Enter Two Words(Only small letter)>> ";
    cin>>a>>b;
    
    
    for (int i = 0; i < a.length(); i++)
        alpha1[a[i] - 'a']++;               //Save the number of alphabets
    for (int i = 0; i < b.length(); i++)
        alpha2[b[i] - 'a']++;
    
    int count = 0;
    for (int i = 0; i < 26; i++){
        if (alpha1[i] != alpha2[i]){
            count += abs(alpha1[i] - alpha2[i]);
        }
    }
    
    
    cout<<count<<endl;
    
    return 0;
    
}
