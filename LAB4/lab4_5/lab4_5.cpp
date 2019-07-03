#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    int length;
    
    ifstream fin("input.txt");
    string s1;
    ofstream fout("out.txt");
    string s2;
   
    cout<<"Length :";
    cin>>length;
    
    while(1){
        fin>>s1;
        fout<<s1<<' ';
        if(!fin)
            break;
    }
    fout.close();
    
    ifstream fin1("out.txt");
    string s3;
    ofstream fout1("out1.txt");
    string s4;
   
    getline(fin1,s3);
    
    for(unsigned i=0; i<s3.size(); i++){
        fout1<<s3[i];{
        if((i+1)%length==0){
            fout1<<endl;
            }
        }
    }
    
    fin1.close();
    fout1.close();
    fin.close();
    return 0;
    
}
