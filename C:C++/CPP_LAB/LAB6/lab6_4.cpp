#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student{
    
private:
    string name;        //name
    int id;             //student_ID
    string major;       //Major
    vector<string> subject ;  //initializing string vector >> subject
    vector<char> score;      //initializing string vector >> score
public:
    //Constructor _ Initializing List.
    Student(string _name ="default", int _id = 0, string _major = "depart"): //defaulut argument
    name(_name),id(_id),major(_major){}
    
    //Change The Value
    void setName(string _name){name = _name;}
    void setID(int _id){id = _id;}
    void setdept(string _major){major = _major;}

    //Print Function by Constructor
    void print(){
        cout<<name<<'\t';
        cout<<id<<'\t';
        cout<<major<<endl;
    }
    //get subject&score Function
    void addGrade(string s, char c){
        subject.push_back(s); 
        score.push_back(c);
    }

    //Subject, Score, GPA Function
    void printGrade(){
        for(unsigned int i = 0; i < subject.size() && score.size(); i++){
            cout << subject[i]<<" "<<score[i] <<endl;
        }
        getGPA();
    }
    int getGPA(){
        float sum = 0;
        float avg = 0;
        
        int n = 0;
        for(unsigned int i = 0; i < score.size(); i++){
            if(score[i] == 'A'){           //Using the ASCII Table
                n = score[i] - 61;         //65 - 61 = 4
            }
            else if(score[i] == 'B'){
                n = score[i] - 63;          //66 - 63 = 3
            }
            else if(score[i] == 'C'){
                n = score[i] - 65;          //67 - 65 = 2
            }
            else if(score[i] == 'D'){
                n = score[i] - 67;          //68 - 67 = 1
            }
            else if(score[i] == 'F'){
                n = score[i] - 69;          //69 - 69 = 0
            }
            sum += n;
            avg = sum/score.size();
        }
        cout<<"GPA: "<<avg<<endl;
        return 0;
    }
    //Calculate the grade from input year
    void getYear(int year){
        int year_now;
        year_now = year - id/(1000000) + 1;      //calculate, between year and ID
        
        if(year_now == 1)
            cout<<"Freshmen(1st grade)"<<endl;
        else if(year_now == 2)
            cout<<"Sophomore(2nd grade)"<<endl;
        else if(year_now == 3)
            cout<<"Junior(3rd grade)"<<endl;
        else if(year_now == 4)
            cout<<"Senior(4th grade학년)"<<endl;
        else
            cout<<"About to graduate(5th grade and above)"<<endl;
    }
};
//Main Function
int main(){
    Student Harry("Harry", 2017310973, "CS");
    Harry.print();
    Harry.getYear(2019);
    Harry.addGrade("programming", 'A');
    Harry.addGrade("Basic Circuit", 'B');
    Harry.printGrade();
   
    cout<<"\n\n";
    
    Student ron;
    ron.print();
    cout<<endl;
    ron.setName("Ron");
    ron.setID(2014103959);
    ron.setdept("EE");
    ron.print();
    ron.getYear(2019);
    ron.addGrade("Computer Architecture",'B');
    ron.addGrade("Maching Learning",'B');
    ron.addGrade("Computer Vision",'C');
    ron.printGrade();
    
    return 0;
}
