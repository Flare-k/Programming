#include <iostream>
using namespace std;

int command(){
    int num;
    
    cout<<"\n\t---- menu ----"<<endl;
    cout<<"\t 1. Add List"<<endl;
    cout<<"\t 2. Delete List"<<endl;
    cout<<"\t 3. Print List"<<endl;
    cout<<"\t 4. Terminate Program"<<endl;
    cout<<"\n\t Input--> ";
    cin>>num;
    
    return num;
}

template<typename T>
class CList{
    T m_Array[5] = {0,};
    int m_Length = (sizeof(m_Array)/sizeof(*m_Array))-5;
public:
    CList(){}
    ~CList(){}

    bool IsEmpty(){
        if(m_Array[0] == 0 and m_Array[1] == 0 and m_Array[2] == 0 and m_Array[3] == 0 and m_Array[4] == 0)
            return true;
        else
            return false;
    }

    bool IsFull(){
        if(m_Array[4] == 0)
            return false;
        else
            return true;
    }

    
    void Add(T data){
        m_Array[m_Length] = data;
        m_Length++;
        
        if(IsFull()){
            cout<<"\n\tList is Full"<<endl;
        }
    }
    

    void Delete(T data){
        for(int i = 0; i < m_Length; i++){
            if(m_Array[i] == data){
                if(i==0){
                    m_Array[i] = m_Array[i+1];
                    m_Array[i+1] = m_Array[i+2];
                    m_Array[i+2] = m_Array[i+3];
                    m_Array[i+3] = m_Array[i+4];
                    m_Array[m_Length-1] = 0;
                }
                else if(i == 1){
                    m_Array[i] = m_Array[i+1];
                    m_Array[i+1] = m_Array[i+2];
                    m_Array[i+2] = m_Array[i+3];
                    m_Array[m_Length-1] = 0;
                }
                else if( i == 2){
                    m_Array[i] = m_Array[i+1];
                    m_Array[i+1] = m_Array[i+2];
                    m_Array[m_Length-1] = 0;
                }
                else if (i == 3){
                    m_Array[i] = m_Array[i+1];
                    m_Array[m_Length-1] = 0;
                 }
                else if(i ==4)
                    m_Array[m_Length-1] = 0;
                }
            }
        if(IsEmpty())
            cout<<"\n\tList if Empty"<<endl;
        }

    void Print(){
        cout<<"\n\t#Current List"<<endl;
        for(int i = 0; i < 5; i++){
            cout<<m_Array[i]<<'\t';
        }
        cout<<endl;
    }
};


int main(){
    
    CList<int> list;
    int input;
    int com;
    
    while(1){
        com  = command();
        
        switch(com){
            case 1:
                cout<<"\nData to Add : ";
                cin>>input;
                list.Add(input);
                break;
            case 2:
                cout<<"\nData to Delete : ";
                cin>>input;
                list.Delete(input);
                break;
            case 3:
                list.Print();
                break;
            case 4:
                cout<<"\n\tExit the Program."<<endl;
                return 0;
                break;
            default:
                cout<<"\n\tRewrite the Number. "<<endl;
                break;
        }
    }

    return 0;
}
