#include <iostream>
#include <string>
using namespace std;

class User{
    string id;
    string password;
    
public:
    User(string _id, string _password):
    id(_id), password(_password){}
    User(){}
    
    void setID(string _id){    // Input
        cin>>id;
    }
    void setPsw(string _password){  //Input
        cin>>password;
    }

    string getID(){return id;}
    string getPsw(){return password;}
};

int main(){
    User user[3];
    string id, password, searchId, searchPassword;
    
    for(int i = 0; i < 3; i++){                         //Input
        cout<<"======"<<i+1<<"======"<<endl;
        
        cout<<"ID:";
        user[i].setID(id);
    /*    if(user[i-1].getID()==searchId){
            cout<<"ID existed"<<endl<<"Terminating Program"<<endl;
            break;
        }*/
        cout<<"Password:";
        user[i].setPsw(password);
        
        cout<<"============="<<endl;
    }



    int i = 0;

    while(1){
    
        if(i == 0){
            cout<<"======Log in======"<<endl;
            cout<<"ID:";
            cin>>searchId;
            if(searchId == "quit"){
                cout<<"Termninate Program"<<endl;
                break;
            }
            
            
            cout<<"Password:";
            cin>>searchPassword;

            if(searchId == user[i].getID() && searchPassword == user[i].getPsw())
                cout<<"Complete Log in"<<endl;
            else if(searchId != user[i].getID() || searchPassword != user[i].getPsw())
                cout<<"Your ID/PASSWORD is Wrong"<<endl;
        }
        
        
        
        if(i == 1){
            cout<<"======Log in======"<<endl;
            cout<<"ID:";
            cin>>searchId;
            if(searchId == "quit"){
                cout<<"Termninate Program"<<endl;
                break;
            }
            if(user[i-1].getID()==searchId){
                cout<<"ID existed"<<endl<<"Terminating Program"<<endl;
                break;                  //Check ID Duplication
            }
            
            
            cout<<"Password:";
            cin>>searchPassword;
            if(searchId == user[i].getID() && searchPassword == user[i].getPsw())
                cout<<"Complete Log in"<<endl;
            else if(searchId != user[i].getID() || searchPassword != user[i].getPsw())
                cout<<"Your ID/PASSWORD is Wrong"<<endl;
        }
        
        
        
        if(i == 2){
            cout<<"======Log in======"<<endl;
            cout<<"ID:";
            cin>>searchId;
            if(searchId == "quit"){
                cout<<"Termninate Program"<<endl;
                break;
            }
            if(user[i-1].getID() == searchId or user[i-2].getID() == searchId){
                cout<<"ID existed"<<endl<<"Terminating Program"<<endl;
                break;
            }                   //Check ID Duplication
            
            
            
            cout<<"Password:";
            cin>>searchPassword;

            if(searchId == user[i].getID() && searchPassword == user[i].getPsw())
                cout<<"Complete Log in"<<endl;
            else if(searchId != user[i].getID() || searchPassword != user[i].getPsw())
                cout<<"Your ID/PASSWORD is Wrong"<<endl;
            }
        
        i++;
        
        if(i == 3)
            break;

    }
    
    return 0;
}
