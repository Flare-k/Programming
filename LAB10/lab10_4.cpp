#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class CList {
private:
    T m_Array[5]; // 데이터를 저장할 공간
    int m_Length = 0; // list에 있는 데이터 수
public:
    CList(){};
    ~CList(){};
    bool IsEmpty(){
        if (m_Length == 0)
            return 1;
        else
            return 0;
    }// list가 비어 있으면 1, 아니면 0
    bool IsFull(){
        if (m_Length == 5)
            return 1;
        else return 0;
    } // list가 꽉 차 있으면 1, 아니면 0
    
    void Add(T data){
        if(m_Length == 5)
            cout << "List is full." << endl;
        else if(m_Length == 0)
        {
            m_Array[0] = data;
            m_Length++;
        }
        else
        {//3랭스 2인덱스
            for (int i = 0; i <= m_Length;)
            {
                if (m_Array[i] == data)
                {
                    cout << "\n중복된 데이터가 존재" << i << "에서" << endl;
                    break;
                }
                else
                {
                    i++;
                    
                    if(i == m_Length)
                    {
                        m_Array[m_Length] = data;
                        m_Length++;
                        break;
                    }
                }
            }
        }
        for(int i = m_Length - 2; i >= 0; i--){
            if (data < m_Array[i])
                swap(m_Array[i], m_Array[i + 1]);
        }
    } // list에 데이터 추가
    
    void Delete(T data){
        if(m_Length == 0)
            cout << "List is empty." << endl;
        
        for(int i = 0; i < m_Length;){
            if (data == m_Array[i]){
                m_Array[i] = m_Array[i + 1];
                i++;
            }
            else i++;
        }
        m_Length--;
    } // list에 데이터 삭제
    void Print(){
        for (auto i = 0; i < m_Length; i++)
            cout << m_Array[i] << '\t';
        cout << endl;
    } // list에 데이터 출력
};


int command()
{
    int num;
    cout << "\n\t---- menu ----" << endl;
    cout << "\t1. 리스트 추가" << endl;
    cout << "\t2. 리스트 삭제" << endl;
    cout << "\t3. 리스트 출력" << endl;
    cout << "\t4. 프로그램 종료" << endl;
    cout << "\n\t입력 --> ";
    cin >> num;
    return num;
}
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