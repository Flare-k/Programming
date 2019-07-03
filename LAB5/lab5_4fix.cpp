#include<iostream>
using namespace std;

int main() {
    int* dynamicarr;
    int size, sum;

    bool compare;

    while(1) {
        compare = false;
        sum = 0;
        
        cout << "Please enter number of values to process : ";
        cin >> size;
        if (size < 1) {
            break;
        }
        dynamicarr = new int[size];
        
        cout << "Please enter numbers : ";
        for (int i = 0; i < size; i++) {
            cin >> dynamicarr[i];
        }
        for (int i = 0; i < size; i++) {
            sum += dynamicarr[i];
            for (int j = i + 1; j < size; j++) {
                if ((dynamicarr[i] == dynamicarr[j])) {
                    compare = true;
                    break;
                }
            }
        }
        
        if (compare || (sum != size * (size + 1) / 2)) {
            cout << "False" << endl;
        }
        else {
            cout << "True" << endl;
        }
    }
    
    return 0;
}
