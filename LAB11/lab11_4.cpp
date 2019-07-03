#include<iostream>
using namespace std;

template<class T>
class Queue{
private:
    T* p_list; // 정수형 변수들을 가지는 배열
    int size = 0;   //현재 저장된 변수들의 개수
    int MAX_SIZE; // 최대로 저장할 수 있는 p_list의 크기
public:
    Queue(int _MAX_SIZE=1000):
    MAX_SIZE(_MAX_SIZE){
        p_list = new T[_MAX_SIZE];
    } //생성자: p_list의 크기를 MAX_SIZE만큼 동적 할당.
    ~Queue(){
        delete[] p_list;
    } // 소멸자: p_list의 동적 할당을 해제
    
    int find_index(T _item){
            if(p_list[size] == _item)
                return size;
            else
                return -1;
       }
    // p_list에서 _item과 동일한 값이 있는지 검색 후 발견시 index를 반환한다 만약 발견하지 못하면 -1을 반환한다

    void Enqueue(T _item){
        if(size == 0){
            p_list[0] = _item;
            size++;
        }
        else{     // size != 0
            for(int i = 0; i<=size;){
                if(p_list[i] == _item){
                    break;              //만약 같은 요소가 있다면 멈춘다. (탐색)
                }
                else
                    i++;                //같지 않다면 인덱스값을 1증가    1 , 2 , 2, 5의 경우
                                        //두번째 2가 (인덱스 2) 중복이므로 멈춘다. 5의 경우 i의 값을 증가시킨다..
                                        //그렇게 되면 사이즈와 같으므로 증가 된 인덱스에 값을 집어넣는다.
                if(i == size){
                    p_list[size] = _item;
                    size++;
                    break;
                }
            }
        }
    }
    // 입력item을 p_list의 끝에 저장한다.
    //만약 _item과 동일한 값이 p_list에 존재할 경우 p_list에 _입력 item을 추가하지 않는다.
    //(힌트: find_index 함수를 사용해서 중복된 값이 p_list에 있는지 조사 후 없는 경우에 입력 item을 p_list에 추가).
    //size가 MAX_SIZE보다 크면 item을 추가하지 않는다.("Error: out of memory"출력)

    T Dequeue(){
        if(size == 0){
            cout<<"Error: No item exists in the list"<<endl;
        }
        else{
            for(int i = 0; i < size; i++){
                    p_list[i] = p_list[i + 1];
            }
            size--;
        }
        return 0;
    }
    // p_list에 있는 첫번째 item을 제거한다음 그 아이템을 return한다 (힌트:size 값을 줄이면 p_list의 아이템을 제거한 것과 동일한 효과) size가 0일 때는 item을 제거하지 않는다. ( "Error: No item exists in the list"출력)
    void print() const{
        cout<<"Items in the list: ";
        for(int i = 0; i < size; i++){
            cout<<p_list[i]<<", ";
        }
        cout<<endl;
    } // Queue 객체의 item들을 출력한다

    int get_size(){
        return size;
    } //Queue 객체의 크기를 출력한다

    T get_item(int _index){
        return p_list[_index];
    } // p_list의 해당 index에 있는 item 값을 리턴한다.
};
//do not modify below
int main(){
    Queue<int> int_queue;
    Queue<float> float_queue;
    Queue<char> char_queue;
    int_queue.Enqueue(1);
    int_queue.Enqueue(2);
    int_queue.Enqueue(2);
    int_queue.Enqueue(5);
    
    float_queue.Enqueue(4.3);
    float_queue.Enqueue(2.5);
    float_queue.Enqueue(3.7);
    float_queue.Enqueue(3.7);
    
    char_queue.Enqueue('b');
    char_queue.Enqueue('b');
    char_queue.Enqueue('c');
    char_queue.Enqueue('a');
    
    cout << "<Before Dequeue>" << endl;
    int_queue.print();
    float_queue.print();
    char_queue.print();
    
    int_queue.Dequeue();            //선입선출!!
    float_queue.Dequeue();
    float_queue.Dequeue();
    
    char_queue.Dequeue();
    char_queue.Dequeue();
    char_queue.Dequeue();
    char_queue.Dequeue();
    cout << "<After Dequeue>" << endl;
    int_queue.print();
    float_queue.print();
    char_queue.print();
    
    return 0;
}



