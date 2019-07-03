#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class CStudent{
private:
    string m_Name;
    int m_Number;
    string m_Major;
public:
    CStudent(string name, int num, string major):
        m_Name(name), m_Number(num), m_Major(major){}
    ~CStudent() {}
    
    void setName(string n){ m_Name = n; }
    void setNumber(int n){ m_Number = n; }
    void setMajor(string n){ m_Major = n; }
    string getName(){return m_Name;}
    int getNumber(){return m_Number;}
    string getMajor(){return m_Major;}
    
    void setAll(string name, int number, string major){
        m_Name = name;
        m_Number = number;
        m_Major = major;
    }
     
    void Display(){
        cout<<"이름 : "<<m_Name<<"\n";
        cout<<"학번 : "<<m_Number<<"\n";
        cout<<"전공 : "<< m_Major<<"\n\n";
    }
};

class FileNotFoundException: public exception{
    string message;
public:
    FileNotFoundException(const string& fname) :
    message("File \"" + fname + "\" not found") {}
    virtual const char* what() const throw (){
        return message.c_str();
    }
};

vector<CStudent> read_file(string& filename){
    ifstream fin(filename);
    
    if(!fin){
        throw FileNotFoundException(filename);
    }
    
    vector<CStudent> result; //임시 객체
    string value;
    int id;
    string major;
    
    while(1){
        fin>>value>>id>>major;
        if(!fin)
            break;
        result.push_back(CStudent(value, id, major));
    }
    
    return result;
}
int main() {
    string str;
    cout << "파일 이름 : ";     //data.txt
    cin >> str;
    
    try {
        vector<CStudent> numbers = read_file(str);
        for (CStudent value : numbers)
            value.Display();
    }
    
    catch(exception& e){
        cout << e.what() << '\n';
    }
    return 0;

}
            
