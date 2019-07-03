#include <iostream>
#include <string>
using namespace std;

class CStudent{
private:
    int id;
    string name;
    string major;
public:
    CStudent(int _id, string _name, string _major):
    name(_name),major(_major),id(_id){}
    
    CStudent(){}
    
    void setNumber(int _id){
        cin>>_id;
        id = _id;
        
    }
    void setName(string _name){
        cin>>_name;
        name = _name;
    }
    void setMajor(string _major){
        cin>>_major;
        major = _major;
    }
    
    int getNumber(){return id;}
    string getName(){return name;}
    string getMajor(){return major;}
    
};


int main(){
    CStudent s[3];
    int inputNumber = 0;
    string inputName, inputMajor;
    int length = 0;
    
    while(1){
        
        if(length == 0){
            cout<<"Enter the "<<length+1<<" Student."<<endl;
            cout<<"ID:";
            s[length].setNumber(inputNumber);
            cout<<"Name:";
            s[length].setName(inputName);
            cout<<"Major:";
            s[length].setMajor(inputMajor);
            cout<<">>Complete Input!"<<endl<<endl;
        }
        
        if(length == 1){
            cout<<"Enter the "<<length+1<<" Student."<<endl;
            cout<<"ID:";
            s[length].setNumber(inputNumber);
            cout<<"Name:";
            s[length].setName(inputName);
            cout<<"Major:";
            s[length].setMajor(inputMajor);
            
            if(s[length].getNumber() != s[length-1].getNumber()){
                cout<<">>Complete Input!"<<endl<<endl;
            }
            else{
                cout<<">>Duplicate values ​​exist."<<endl<<endl;
                continue;
            }
            
        }
        
        if(length == 2){
            cout<<"Enter the "<<length+1<<" Student."<<endl;
            cout<<"ID:";
            s[length].setNumber(inputNumber);
            cout<<"Name:";
            s[length].setName(inputName);
            cout<<"Major:";
            s[length].setMajor(inputMajor);
            
            if(s[length].getNumber() != s[length-1].getNumber()){
                    if(s[length].getNumber() != s[length-2].getNumber()){
                        cout<<">>Complete Input!"<<endl<<endl;
                    }
                    else{
                        cout<<">>Duplicate values ​​exist."<<endl<<endl;
                        continue;
                    }
                
            }
           
            else{
                cout<<">>Duplicate values ​​exist."<<endl<<endl;
                continue;
            }
        }
        
        length++;
        
        if(length == 3)
            break;
        
    }
    
    cout<<"——Exterminate All of Input——" <<endl;
    for(int j=0; j<3; j++){
        cout<<"ID:"<<s[j].getNumber()<<endl;
        cout<<"Name:"<<s[j].getName()<<endl;
        cout<<"Major:"<<s[j].getMajor()<<endl<<endl;
    }
    
    
    return 0;
}
