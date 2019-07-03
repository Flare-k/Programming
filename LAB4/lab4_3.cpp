#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){
    srand(0);
    ofstream fout("random.txt");
    
    for(int row=1;row<=10; row++){
        for(int column=1; column<=10; column++){
                int random = rand()%101;
                fout<<setw(5)<<random;
        }
        fout<<endl;
    }
    
    fout.close();
    return 0;
}
