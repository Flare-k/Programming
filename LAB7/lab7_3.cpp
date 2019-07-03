#include <iostream>
#include <string>
using namespace std;


class Account{
private:
    string name;
    string id;
    int balance;
public:
    Account(string _name="", string _id="", int _bal=0);
    Account();

    Account operator+(const Account& acnt);
    Account operator-(const Account& acnt);

    void setName(string _name);
    void setId(string _id);
    void setBal(int _bal);
    
    string getName();
    string getId();
    int getBal();
    
};

ostream& operator<<(ostream& os, Account& acnt) {
    return os<< "ID : " << acnt.getId() << "  Name : " << acnt.getName() << "  Balance : " << acnt.getBal() << endl;
}

int main(){
    Account acnt[3]={
        Account("Shin", "2015204212", 10000),
        Account("Kim", "2012311060", 0),
        Account("Lee", "2011102214", 5000),
    };
    
    string name;
    string ids, idr;
                    //ids = id sender   idr = id receiver
    
    string stu1, stu2, stu3;
    
    stu1 = acnt[0].getId().substr(0,4);
    stu2 = acnt[1].getId().substr(0,4);
    stu3 = acnt[2].getId().substr(0,4);
    
    while(1){
    cout<<"Please Enter Sender's ID (or quit) >> ";                //Sender
    cin>>ids;
        
            if(ids == "quit"){
                cout<<"Terminate Program"<<endl;            //quit
                for (int i = 0; i < 3; i++)
                    cout << acnt[i];
                exit(1);
            }
        
            if(ids != stu1 && ids != stu2 && ids != stu3 ){
                cout<<"Non-Existent ID"<<endl;            //Not Find
            continue;
            }
        
        
            if (ids == stu1) {
                if (acnt[0].getBal() == 0) {
                    cout << "The sender has insufficient money." << endl;
                continue;
                }
            }
            if (ids == stu2) {
                if (acnt[1].getBal() == 0) {
                    cout << "The sender has insufficient money." << endl;
                continue;
                }
            }
            if (ids == stu3) {
                if (acnt[2].getBal() == 0) {
                    cout << "The sender has insufficient money." << endl;
                continue;
                }
            }
        
        
    cout<<"Please Enter Receiver's ID >> ";                  //Receiver
    cin>>idr;
        
            if(idr != stu1 && idr != stu2 && idr != stu3 ){
                cout<<"Non-Existent ID"<<endl;            //Not Find
            continue;
            }
            if (ids == idr){
                cout<<"It is the same ID. Please Re-Enter."<<endl;        //Same.. Re-Input
            continue;
            }

        /*
         2015 = acnt[0]
         2012 = acnt[1]
         2011 = acnt[2]
         */
        if (ids == "2011"){    //Sender
            if (idr == "2012"){   //Receiver
                acnt[1] = acnt[1] + acnt[2];
                cout<<"Receiver's Balance : "<<acnt[1]<<endl;
            }
            else if (idr == "2015"){
                acnt[0] = acnt[0] + acnt[2];
                cout<<"Receiver's Balance : "<<acnt[0]<<endl;
            }
            acnt[2] = acnt[2] - acnt[2];
            cout<<"Sender's Balance : "<<acnt[2]<<endl;
        }
        
        else if (ids == "2012"){//Sender
            if (idr == "2011"){
                acnt[2] = acnt[2] + acnt[1];
                cout<<"Receiver's Balance : "<<acnt[2]<<endl;
            }
            else if (idr == "2015"){
                acnt[0] = acnt[0] + acnt[1];
                cout<<"Receiver's Balance : "<<acnt[0]<<endl;
            }
            acnt[1] =acnt[1]-acnt[1];
            cout<<"Sender's Balance : "<<acnt[1]<<endl;
        }
        
        else if (ids == "2015"){
            if (idr == "2012"){
                acnt[1] = acnt[1] + acnt[0];
                cout<<"Receiver's Balance : "<<acnt[1]<<endl;
            }
            else if (idr == "2011"){
                acnt[2] = acnt[2] + acnt[0];
                cout<<"Receiver's Balance : "<<acnt[2]<<endl;
            }
            acnt[0] = acnt[0] - acnt[0];
            cout<<"Sender's Balance : "<<acnt[0]<<endl;
        }
    }
}
Account::Account(){}

Account::Account(string _name, string _id, int _bal):name(_name), id(_id), balance(_bal){}

Account Account:: operator+(const Account& acnt) {
    return Account(name, id, balance + acnt.balance);
    }
Account Account:: operator-(const Account& acnt) {
    return Account(name, id, balance - acnt.balance);
    }
string Account::getName(){return name;}
string Account::getId(){return id;}
int Account::getBal(){return balance;}

void Account::setName(string _name){name = _name;}
void Account::setId(string _id){id = _id;}
void Account::setBal(int _bal){balance = _bal;}
