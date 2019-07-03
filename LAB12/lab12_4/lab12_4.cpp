#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class FileNotFoundException: public exception{
    string message;
public:
    FileNotFoundException(string _m):
    message("File not found: "+ _m){}
    
    virtual const char* what() const throw(){
        return message.c_str();
    }
};

vector <vector<int>> load_vector(string filename){
    ifstream fin(filename);
    
    if(!fin){
        throw FileNotFoundException(filename);
    }
    
    vector <vector<int>> matrix;   //임의의 2차원 벡터 저장을 위한 변수
    
    int num, num1,num2,num3,num4, num5, num6, num7, num8, num9;
    while(1){
        fin>>num>>num1>>num2>>num3>>num4>>num5>>num6>>num7>>num8>>num9;
        if(!fin) //끝에 도달했다는 의미
            break;
        vector <int> newCol;
        newCol.push_back(num);
        newCol.push_back(num1);
        newCol.push_back(num2);
        newCol.push_back(num3);
        newCol.push_back(num4);
        newCol.push_back(num5);
        newCol.push_back(num6);
        newCol.push_back(num7);
        newCol.push_back(num8);
        newCol.push_back(num9);
        
        matrix.push_back(newCol);   //2차원 벡터에 1차원 벡터를 push back
       }
    fin.close();
    return matrix;
}



int main(){
    srand((unsigned int)time(NULL));
    ofstream fout("temp.txt");
    
    for(int row = 1; row <= 10; row++){
        for(int column = 1; column <= 10; column++){
            int random = rand()%101;
            fout<<setw(5)<<random;
        }
        fout<<endl;
    }
    fout.close();
    
    string filename;
    cout<<"파일 이름: ";
    cin>>filename;
    int row, col;
    cout<<"출력할 행의 크기: ";
    cin >> row;
    cout<<"출력할 열의 크기: ";
    cin >> col;
    try{
        vector<vector<int>> matrix = load_vector(filename);  //벡터값에 대해선.. 다음 파일에 있는 값들을 받아서 저장.
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cout<<setw(5)<<matrix[i][j];
            }
            cout<<endl;
        }
    }
    catch(FileNotFoundException& e){
        cout<<e.what()<<endl;
    }
    cout<<endl;
    
    return 0;
}
