#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void get_data_A(int &rowa, int &cola);                                          //Input Function (Row & Column)
void get_data_B(int &rowb, int &colb);                                          //Input Function (Row & Column)
void print(vector<vector<int>>& matrixa, vector<vector<int>>& matrixb);         //Print Function
void initialize(vector<vector<int>>& matrixc);

using matrix = vector<vector<int>>;
matrix Multiplication(vector<vector<int>>& matrixa, vector<vector<int>>& matrixb);
                                                                                //Multiple MatrixA & MatrixB   Function
int main() {                                 //Main Function
    int rowa, cola;
    int rowb, colb;
    int rowc=0, colc=0;

    srand(1);
    
    get_data_A(rowa, cola);
    get_data_B(rowb, colb);
    
    vector <vector<int>> matrixa(rowa, vector<int>(cola));  //nxn matrix_A
    vector <vector<int>> matrixb(rowb, vector<int>(colb));  //nxn matrix_B
    vector <vector<int>> matrixc(rowc, vector<int>(colc));  //nxn matrix_C
    
    print(matrixa, matrixb);
    initialize(matrixc);
    Multiplication(matrixa, matrixb);
    
    return 0;
}


void get_data_A(int &rowa, int &cola) {                         //Input Function (Row & Column)
    cout << "Please Enter Row & Column size of Matrix A >> ";
    cin >> rowa >> cola;
}
void get_data_B(int &rowb, int &colb) {                         //Input Function (Row & Column)
    cout << "Please Enter Row & Column size of Matrix B >> ";
    cin >> rowb >> colb;
}


void print(vector<vector<int>>& matrixa, vector<vector<int>>& matrixb){         //Print Function
    cout << endl;
    
    cout << "Matrix_A:" << endl;
    for (vector<int>&veca : matrixa) {              //Input&Print Matrix A
        for (int &elema : veca) {
            elema = rand()%19-9;
            cout << setw(5)<<elema;
        }
        cout << endl;
    }
    
    cout << endl;

    cout << "Matrix_B:" << endl;
    for (vector<int>&vecb : matrixb) {              //Input&Print Matrix B
        for (int &elemb : vecb) {
            elemb = rand()%19-9;
            cout <<setw(5)<< elemb ;
        }
        cout << endl;
    }
    cout << endl;
}


void initialize(vector<vector<int>>& matrixc) {                         //Initialize Matrix C Function
    for (vector<int>&vecc : matrixc) {
        for (int &elemc : vecc) {
            elemc = 0;
        }
    }
    
}


matrix Multiplication(matrix&matrixa, matrix&matrixb) {                 //Multiple MatrixA & MatrixB   Function
    matrix matrixc(matrixa.size(), vector<int>(matrixb[0].size(), 0));
    cout << "Matrix_AB:" << endl;
    
    if (matrixa.size() == matrixb[0].size()) {
        for (unsigned int rowa = 0; rowa < matrixa.size(); rowa++) {
            for (unsigned int colb = 0; colb < matrixb[0].size(); colb++) {
                int sum = 0;
                for (unsigned int i = 0; i < matrixa[0].size(); i++)
                    sum += matrixa[rowa][i] * matrixb[i][colb];
                matrixc[rowa][colb] = sum;
                cout << setw(5) << matrixc[rowa][colb];
            }
            cout << endl;
        }
    }
    else
        cout << "You can't make matrix C" << endl;
    return matrixc;
}
