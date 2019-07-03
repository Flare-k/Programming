//
//  FoodItem.cpp
//  과년도Exam2_4
//
//  Created by Flare_k on 16/05/2019.
//  Copyright © 2019 Kang. All rights reserved.
//

#include "FoodItem.hpp"
#include "Item.hpp"

int FoodItem::readItemFromFile(ifstream& _fin){
    _fin>>code>>name>>price>>dueDate;
    return 0;
}
void FoodItem::displayItem()const {
    cout<<code<<'\t'<<name<<'\t'<<price<<'\t'<<dueDate<<endl;
    }
