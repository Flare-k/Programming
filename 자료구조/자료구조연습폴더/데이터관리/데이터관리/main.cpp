
#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class CList {
private:
    T m_Array[5]; // 데이터를 저장할 공간
    int m_Length = 0; // list에 있는 데이터 수
public:
    CList();
    ~CList();
    bool IsEmpty(); // list가 비어 있으면 1, 아니면 0
    bool IsFull(); // list가 꽉 차 있으면 1, 아니면 0
    void Add(T data); // list에 데이터 추가
    void Delete(T data); // list에 데이터 삭제
    void Print(); // list에 데이터 출력
};

template<typename T>
CList<T>::CList() {}

template<typename T>
CList<T>::~CList() {}

template<typename T>
bool CList<T>::IsEmpty() // list가 비어 있으면 1, 아니면 0
{
    if (m_Length == 0)
        return 1;
    else
        return 0;
}

template<typename T>
bool CList<T> ::IsFull() // list가 꽉 차 있으면 1, 아니면 0
{
    if (m_Length == 5)
        return 1;
    else
        return 0;
}

template<typename T>
void CList<T> ::Add(T data) { // list에 데이터 추가
    if (m_Length == 5)
        cout << "List is full." << endl;
    else
    {
        m_Array[m_Length] = data;
        m_Length++;
    }
}

template<typename T>
void CList<T> ::Delete(T data) { // list에 데이터 삭제
    if (m_Length == 0)
        cout << "List is empty." << endl;
    
    for (int i = 0; i < m_Length;)//1 2 3 4 5
    {
        if(data == m_Array[i]) {
            m_Array[i] = m_Array[i + 1];
            i++;
        }
        else i++;
    }
    m_Length--;
}

template<typename T>
void CList<T> ::Print() {  // list에 데이터 출력
    for (auto i = 0; i < m_Length; i++)
        cout << m_Array[i] << '\t';
    cout << endl;
}

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

int main() {
    CList<int> list;        // type형으로 list 선언
    int input;              // list에 입력 할 데이터
    int com;                // 선택한 기능
    while (1)
    {
        com = command();    // 기능을 선택
        switch(com)
        {
            case 1: // 추가
                cout << "\n추가할 데이터 : ";
                cin >> input;
                list.Add(input);
                break;
            case 2: // 삭제
                cout << "\n삭제할 데이터 : ";
                cin >> input;
                list.Delete(input);
                break;
            case 3: // 출력
                list.Print();
                break;
            case 4: // 프로그램 종료
                cout << "\n\t프로그램을 종료합니다\n";
                return 0;
                break;
            default:
                break;
        }
    }
    
    return 0;
}
