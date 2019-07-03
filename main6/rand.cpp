#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    srand((unsigned int)time(NULL));
    int random = rand()%101;
    ofstream fout("random.txt");
    
    for(int row=0;row<10; row++){
        for(int column=0; column<10; column++){
            fout<<setw(5)<<random;
        }
    }
    fout.close();
    return 0;
}

// rand()%101  = 0~100
// rand()%101-n = (-n) ~ (100-n)
