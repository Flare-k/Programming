#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Item.hpp"
#include "FoodItem.hpp"
#include "OfficeItem.hpp"
#include "Application.hpp"
using namespace std;

int main(){
    ApplicationClass appManager("foodItem.txt", "officeItem.txt");
    appManager.run();
    
    return 0;
}
