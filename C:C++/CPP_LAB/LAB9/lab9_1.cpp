#include <iostream>
#include <string>

using namespace std;

class Student{
private:
    string name;
    int id;
    string department;
    int grade;
    int credit;
public:
    Student(string n = "", unsigned int i = 0, string d = "default", int g = 0, int c = 0):
    name(n), id(i), department(d), grade(g), credit(c){}
    ~Student(){}
    
    void set_name(string n){name = n;}
    void set_id(int i){id = i;}
    void set_department(string d){department = d;}
    void set_grade(int g){grade = g;}
    void set_credit(int c){credit = c;}

    virtual string get_name(){return name;}
    virtual int get_id(){return id;}
    virtual string get_department(){return department;}
    virtual int get_grade(){return grade;}
    virtual int get_credit(){return credit;}
    virtual void print(){
        cout<<"I'm student"<<endl;
        cout<<"==================="<<endl;
    }
    
};//////////////////////////////////////////////////////

class Undergraduate: public Student{
private:
    string club;
public:
    Undergraduate(string n = "", unsigned int i = 0, string d ="default", int g = 0, int c = 0, string cl = ""):
    Student::Student(n, i, d, g, c), club(cl){}
  
    ~Undergraduate(){}
    
    void set_club(string cl){club = cl;}
    string get_club(){return club;}
    
    void print() override{
        cout<<"==================="<<endl;
        cout<<"이름: "<<Student::get_name()<<endl;
        cout<<"학번: "<<Student::get_id()<<endl;
        cout<<"전공: "<<Student::get_department()<<endl;
        cout<<"학년: "<<Student::get_grade()<<endl;
        cout<<"학점: "<<Student::get_credit()<<endl;
        cout<<"동아리: "<<get_club()<<endl;
        cout<<"==================="<<endl;
        exit(1);
    }
};//////////////////////////////////////////////////////

class Graduate: public Student{
private:
    bool kind;
    double ratio;
public:
    Graduate(string n = "", unsigned int i = 0, string d ="default", int g = 0, int c = 0, bool k ="", double r = 0):
    Student::Student(n, i, d, g, c), kind(k), ratio(r){}
    ~Graduate(){}
    
    void set_kind(bool k){kind = k;}
    void set_ratio(double r){ratio = r;}
    
    string get_kind(){
        if(kind == false){
            return "연구조교";
        }
        else{
            return "장학조교";
        }
    }
    double get_ratio(){return ratio;}
    
  
    void print() override{
        cout<<"==================="<<endl;
        cout<<"이름: "<<Student::get_name()<<endl;
        cout<<"학번: "<<Student::get_id()<<endl;
        cout<<"전공: "<<Student::get_department()<<endl;
        cout<<"학년: "<<Student::get_grade()<<endl;
        cout<<"학점: "<<Student::get_credit()<<endl;
        cout<<"조교: "<<get_kind()<<endl;
        cout<<"장학비율: "<<get_ratio()<<endl;
        cout<<"==================="<<endl;
    }
    
    
};//////////////////////////////////////////////////////

int main(void){
    
    Student Std;
    Graduate Kang("강석원", 2018311025, "컴퓨터공학과", 1, 18, false, 0.5);
    Undergraduate Hong("홍길동", 20141111, "컴퓨터공학과", 2, 80, "알고리즘 동아리");
    
    Std.print();        //Student
    Kang.print();       //Graduate
    Hong.print();       //Undergraduate
    
    return 0;
}
