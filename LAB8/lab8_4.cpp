#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Avengers{
public:
    Avengers(){
        name = "";
        attack_point = 0;
        defense_point = 0;
        health = 0;
    }
    ~Avengers(){}
    
    virtual void set(string _name , int _attack, int _defense, int _health){
        name = _name;
        attack_point = _attack;
        defense_point = _defense;
        health = _health;
    }
    virtual int attack(){
        return attack_point;
    }
    
    virtual void defense(int attack){
        health = health - (attack - defense_point);
        cout<<health;
    }
    
    virtual void print_info(){
        cout<<"--My Character--"<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Attack_Point : "<<attack_point<<endl;
        cout<<"Defense_Point : "<<defense_point<<endl;
        cout<<"Health : "<<health<<endl;
        
    }

    virtual void print_info_en(){
        cout<<"--Enemy Character--"<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Attack_Point : "<<attack_point<<endl;
        cout<<"Defense_Point : "<<defense_point<<endl;
        cout<<"Health : "<<health<<endl;
    }

protected:
    string name;
    int attack_point;
    int defense_point;
    int health;
};



class Character: public Avengers{
public:
    int get_health(){return health;}
};


int main(){
    srand((unsigned int) time (NULL));
    
    Character my_char;
    Character enemy_char;
    
    string choose;
    cout<<"Choose your character(IronMan, CaptainAmerica, Thor):";
    cin>>choose;
    
    //[My Character]
    if(choose == "IronMan"){
        my_char.set("IronMan", 70, 40, 100);
    }
    if(choose == "CaptainAmerica"){
        my_char.set("CaptainAmerica", 60, 50, 100);
    }
    if(choose == "Thor"){
        my_char.set("Thor", 80, 30, 100);
    }
    my_char.print_info();
    
    //[Enemy Character]
    int enemy;
    enemy = rand()%3;    //random 0, 1, 2
    //Enemy is Random Choice...using rand function.. 0 = IronMan , 1 = CaptainAmerica , 2 = Thor
    if(enemy == 0){
        enemy_char.set("IronMan", 70, 40, 100);
    }
    if(enemy == 1){
        enemy_char.set("CaptainAmerica", 60, 50, 100);
    }
    if(enemy == 2){
        enemy_char.set("Thor", 80, 30, 100);
    }
    enemy_char.print_info_en();
    
    if(my_char.attack() == enemy_char.attack()){
        cout<<"Same Hero, Terminate the Program~~"<<endl;
        exit(100);
    }

   //[Batte Condition]
        cout<<endl<<"--Battle--"<<endl;
        cout<<"My Life: "<<my_char.get_health()<<'\t'<<"Enemy Life: "<<enemy_char.get_health()<<endl;
    while(1){
        cout<<"My Life: "<<my_char.get_health()<<'\t'<<"Enemy Life: ";
        enemy_char.defense(my_char.attack());
        cout<<endl;
        cout<<"My Life: ";
        my_char.defense(enemy_char.attack());
        cout<<'\t'<<"Enemy Life: "<<enemy_char.get_health()<<endl;
    
        if(enemy_char.get_health() <= 0 ){
            cout<<"You Win!"<<endl;
            break;
        }

    }
    return 0;
}
