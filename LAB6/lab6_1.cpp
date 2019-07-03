#include <iostream>
#include <string>
using namespace std;

class CStudent{
private:        //Member Variable
    int id;             //Student_id
    string name;        //name
    string major;       //major
public:         //Member Function
    CStudent(string _name = "HongGillDong", string _major = "Computer Engineering", int _id = 2018000000):
    name(_name),major(_major),id(_id){}                                                      //Default Argument

    
    CStudent(int _id, string _name, string _major):
    name(_name),major(_major),id(_id){}
    
    void setNumber(int _id){
        id = _id;
    }
    void setName(string _name){
        name = _name;
    }
    void setMajor(string _major){
        major = _major;
    }
    
    void getNumber(){
        cout<<"ID:"<<id<<endl;
    }
    void getName(){
        cout<<"Name:"<<name<<endl;
    }
    void getMajor(){
        cout<<"Major:"<<major<<endl;
    }
    
    void Display(){
        cout<<"ID:"<<id<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Major:"<<major<<endl;
        cout<<endl;
    }
};

int main(){
    
    CStudent s1;        
    s1.Display();

    CStudent s2(1999000000, "GongJiChul", "Film & Theater");
    s2.Display();
    
    s1.setNumber(2006000000);
    s1.setName("MinKyungHoon");
    s1.setMajor("Post-Modern");
   
    s1.getNumber();
    s1.getName();
    s1.getMajor();
    
    return 0;
}
