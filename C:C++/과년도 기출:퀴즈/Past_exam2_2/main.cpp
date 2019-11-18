#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class Item{
private:
    string code;
    string name;
    int price;
public:
    Item(){}

    ifstream& readItemFromFile(ifstream& fin){          //파일 내용 읽기
        fin>>code>>name>>price;
        return fin;
    }
    ofstream& writeItemToFile(ofstream & fout){          //파일에 저장
        fout<<code<<'\t'<<name<<'\t'<<price<<endl;
        return fout;
    }
    void setItem(string _c, string _n, int _p){
        this->code = _c;
        this->name = _n;
        this->price = _p;
    }
};


int main(){
    Item temp;      //빈 객체
    vector<Item> vItem;
    string inFileName = "item.txt";
    string outFileName = "item_output.txt";
    
    //1) Open File using ifstream object
    ifstream fin(inFileName);
    
    while(temp.readItemFromFile(fin))   //파일로부터 Item 읽어서 vector에 추가
        vItem.push_back(temp);

    //2) Close File using ifstream object
    fin.close();

    temp.setItem("E1002", "Bacchus", 1000);
    vItem.push_back(temp);
    
    //3)ofstream 객체를 이용해 outFileName의 이름을 가진 file을 열기
    ofstream fout(outFileName);
    
    for(auto elem : vItem){
        elem.writeItemToFile(fout);
    }
    //4) ofstream 객체를 이용한 파일 닫기
    fout.close();
   
    return 0;
    
}



