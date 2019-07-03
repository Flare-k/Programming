#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


class Account{
public:
    string name;            //이름            //계좌추가 //이름 종류 원금 이자율 계약기간
    string kind;        //계좌종류
    
    double amount;          //원금
    double interest;
    double rate;    //이자율
    double balance;
    int term;
};

void add_Account(vector<Account>& a){
    string name;            //이름            //계좌추가 //이름 종류 원금 이자율 계약기간
    string kind;        //계좌종류

    double amount;          //원금
    double interest;
    double rate;    //이자율
    double balance;
    int term;           //기간
    
    cout<<"Account Name:";
    cin>>name;
    cout<<"Account kind (dan/bok):";
    cin>>kind;
    cout<<"Account amount:";
    cin>>amount;
    cout<<"Account interest:";
    cin>>interest;
    cout<<"Account Balance:";
    cin>>balance;
    cout<<"Account term:";
    cin>>term;
    
}

void print_Account(const vector<Account>& a){
    unsigned long n = a.size();
    for(int i =0; i<n; i++){
        cout<<"Account Name:"<<a[i].name;
        cout<<"Account kind (dan/bok):"<<a[i].kind;
        cout<<"Account amount:"<<a[i].amount;
        cout<<"Account interest:"<<a[i].interest;
        cout<<"Account Balance:"<<a[i].balance;
        cout<<"Account term:"<<a[i].term;
    }
}


void pass(const vector<Account>& a, string& kind){
    int result= 0;
    unsigned long n = a.size();
    if(kind == "dan"){
        for(int i=0; i < n; i++)
            result = a[i].amount*(a[i].rate*a[i].term + 1);
    }
    else if(kind == "bok"){
        for(int i = 0; i < n; i++)
           result = a[i].amount*(a[i].rate + 1);
    }
}

bool less_than_by_name(const Account& e1, const Account& e2){
    return e1.name<e2.name;
}






int main(){
    
    const vector<Account> customer;
    char cmd;
    
    bool done = false;
    do{
        cout<<"[A]dd"<<endl;
        cout<<"[D]elete"<<endl;
        cout<<"[P]ass"<<endl;
        cout<<"[Q]uit"<<endl;
        cin>>cmd;
        
        switch(cmd){
            case 'A':
            case 'a':
                add_Account(customer);
            case 'D':
            case 'd':
                delete_Account(customer);
            case 'P':
            case 'p':
                pass(customer);
            case 'Q':
            case 'q':
                done = true;
                break;
        }
    }while(!done);
    
    
    
    
    return 0;
}
