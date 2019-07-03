#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
   
    ifstream fin1("input1.txt");
    string s1;
    ifstream fin2("input2.txt");
    string s2;
    
    ofstream fout("output.txt");
    while(getline(fin2, s2)){
        fout<<s2<<endl;
            while(getline(fin1, s1,'\n')){
                    fout<<s1<<endl;
            }
    }
    fout.close();

    ifstream fin3("output.txt");
    string s3;

    if(!fin3){
        cout<<"Open Error"<<endl;
    }
    else{
        while(getline(fin3, s3)){
            cout<<s3<<endl;
        }
    }
    
    fin1.close();
    fin2.close();
    fin3.close();

    return 0;
}
