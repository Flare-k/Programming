#include <iostream>
#include <string>
using namespace std;

class Account{
private:
    int id;
    string name;
    int balance;
    
public:
    Account(int _id = 0, string _name="", int _bal=0):
    id(_id), name(_name), balance(_bal){}
   
    ~Account(){
        cout<<"(Destruct~ "<<this<<")"<<endl;
    }    //Destruct
 
    void setId(int _id){
        cin>>id;
    }
    void setName(string _name){
        cin>>name;
    }
    void setBalance(int _bal){
        cin>>balance;
    }
    
    
    int getId(){return id;}
    string getName(){return name;}
    int getBalance(){return balance;}
};


int main() {
    bool compare;

    int n = 0;
    int inputbal = 0;
    int sum = 0;
    int inputid = 0;
    string inputname;

    cout<<"How many people would you like to have in total? >>";
    cin>>n;
    Account *user = new Account[n];


    for(int i = 0; i < n; i++){                 //Input Account
        compare = false;
        cout<<i+1<<" Student Account:"<<endl;
        cout<<"Student_ID:";
        user[i].setId(inputid);
        cout<<"Name:";
        user[i].setName(inputname);
        cout<<"Balance:";
        user[i].setBalance(inputbal);
        cout<<"==================="<<endl;
        sum += user[i].getBalance();

    }
    for (int i = 0; i < n; i++) {               //Check The Duplication
        for (int j = i + 1; j < n; j++) {
            if ((user[i].getId() == user[j].getId())) {
                compare = true;
                cout<<"ID is duplicated. Terminateing program."<<endl;
                exit(1);
            }
        }
    }
    delete[] user;
    cout<<"Collected Balance: "<<sum<<endl;

    return 0;
}
