#include <iostream>
using namespace std;

class Stack{
private:
    int* p_list;
    int size;
    int MAX_SIZE;
public:
    Stack(int _MAX_SIZE = 1000):
    MAX_SIZE(_MAX_SIZE){
        p_list = new int [MAX_SIZE];
    }
    ~Stack(){
        delete[] p_list;
    }
    int find_index(int _item){
        for(int i = 0; i < MAX_SIZE; i++){
            if(p_list[i] == _item){
                return i;
            }
        }
        return -1;
    }
    
    void push(int _item){
        if(_item == find_index(_item))
            cout<<"Error: No item exists in the list"<<endl;
        else
            p_list[-1] = _item;
    }
   
   
    int pop(){
        p_list[-1] = 0;
        if(sizeof(p_list) == 0){
            cout<<"Error: No item exists in the list"<<endl;
        }
        else
            return p_list[-1];
        
    }
    void print() const{
        for(int i=0; i<MAX_SIZE; i++){
            cout<<p_list[i]<<endl;
        }
    }
    int get_size(){
        return sizeof(p_list);
    }
    int get_item(int _index){
        return _index;
    }
    
    Stack operator +(const Stack& s){
        Stack result;
        for(int i = 0; i < MAX_SIZE; i++){
            result = this->p_list[i] + p_list[i+1];
        }
        return result;
    }
    Stack operator ==(const Stack& s){
        
    }
    
};



//#do not modify below
int main()
{
    Stack s1, s2;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s2.push(1);
    s2.push(2);
    s2.push(5);
    s1.print();
    s2.print();
    s1 += s2;
    s1.print();
    s2.print();
    
    cout << "s1 == s2 ? " << (s1 == s2) << endl;
    s1.pop(); // 5 out
    s1.pop(); // 3 out
    s2.pop(); // 5 out
    
    cout << "s1 == s2 ? " << (s1 == s2) << endl;
    s2.pop();
    s2.pop();
    s2.pop();
    
    return 0;
}
