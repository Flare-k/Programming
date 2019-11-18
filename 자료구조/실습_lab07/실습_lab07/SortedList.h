#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Master List
template <typename T>
class SortedList{
    
private:
    T *m_Array; //레코드 배열, 객체를 배열의 형태로 만듬.
    int m_Length;       //리스트에 저장된 레코드 수
    int m_CurPointer;   //current pointer  -> iterator
    
public:
    SortedList();
    ~SortedList();
    
    
    void MakeEmpty();
    /*
     길이를 0으로 초기화 시키는 함수
     */
    int GetLength();
    /*
     길이를 리턴하는 함수
     */
    bool IsFull();
    /*
     꽉 차 있는지 확인하는 함수
     */
    bool IsEmpty();
    /*
     배열이 비었는지 여부
     */
    void ResetList();
    /*
     레코드 포인터(current pointer) 초기화
     */
    int GetNextItem(T& data);
    /*
     current pointer를 하나 증가시키고 끝이 아니면 record index를 리턴 끝이면 -1을 리턴
     */
    
    int Add(T& data);
    /*
     중복이 아닐경우 실행문
     반복문 안의 전체 조건문 = data 객체가 저장돼 있는 내용과 같지 않을 때,
     첫번째 조건문 = 입력받은 data객체가 배열의 마지막 값 보다 클 때, 그 뒤(맨 마지막)에 저장.
     두번째 조건문 = 입력받은 data객체가 배열의 첫번째 값 보다 작을 때, 그 앞(맨 앞)에 저장.
     마지막 조건문 = 입력받은 data객체가 배열의 사이에 존재할 때,
     ex, 1,3에 2가 들어와야한다면 1, 1, 3으로 만들고 두번째 1자리를 2로 초기화.
     전체 반복문을 빠져나오면 배열의 길이를 1만큼 증가시킨다.
     */
    int Delete(T data);
    /*
     입력받은 data의 primary key와 m_Array[i]의 primary key가 같으면 해당 인덱스에서
     뒤의 값을 앞으로 하나씩 당겨주고 길이를 1만큼 감소시켜준다.
     그렇지 않으면 return 0을 해준다.
     */
    
    
    int Replace(T data);
    /*
     치환하려고 받은 정보와 같은 primary key를 갖는 객체가 있다면 치환해준다.
     그렇지 않으면 return 0을 해준다.
     */
    int Retrieve_Seq(T& data);
    /*
     Primary key를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
     반복문을 돌며 primary key가 같으면 해당 인덱스에 있는 내용을
     data 객체에 할당해준다.
     찾으면 return 1을 해주고 더이상의 반복을 하지않는다.
     그렇지 않으면 return 0을 해준다.
     */
    int Retrieve_Binary(T& data);
    /*
     이진탐색
     찾고자 하는 값이 있다면 일단 전체 내용중에 중간부터 탐색을 한다.
     중간보다 작은 값이라면 '중간 값'이 '끝 값'으로 할당되고 다시 탐색을 시작한다.
     중간보다 큰 값이라면 '중간 값'이 '시작 값'으로 할당되고 다시 탐색을 시작한다.
     */
    
    
};
template<typename T>
SortedList<T>::SortedList(){
    m_Array = new T[MAXSIZE];
    m_Length = 0;
    ResetList();
}

template<typename T>
SortedList<T>::~SortedList(){
    delete [] m_Array;
}

template <typename T>
void SortedList<T>::MakeEmpty(){
    m_Length = 0;
}

template <typename T>
int SortedList<T>::GetLength(){
    return m_Length;
}

template <typename T>
bool SortedList<T>::IsFull(){
    if(m_Length == MAXSIZE) //MAXSIZE = 10
        return true;
    else
        return false;
}

template <typename T>
bool SortedList<T>::IsEmpty(){
    if(m_Length == 0)
        return true;
    else
        return false;
}

template <typename T>
void SortedList<T>::ResetList(){
    m_CurPointer = -1;
}


template <typename T>
int SortedList<T>::GetNextItem(T& data){
    m_CurPointer++;
    if(m_CurPointer == m_Length)
        return -1;
    
    data = m_Array[m_CurPointer];
    //0부터 반복하면서 다음 data값을 불러오게 함.
    return 1;
}


template <typename T>
int SortedList<T>::Add(T& data){
    
    if(IsFull())
        return 0;       //이미 가득 차 있으면 0을 리턴
    
    if(m_Length == 0){          //비어있을때 추가하는 코드
        m_Array[m_Length] = data;
        m_Length++;
        return 1;
    }
    
    //중복처리 출력문
    for(int i = 0; i < m_Length; i++){
        if(data == m_Array[i]){
            cout<<"\t=============================="<<endl;
            cout<<"\t Primary Key is already exist."<<endl;
            cout<<"\t=============================="<<endl;
            return 0;
        }
    }
    
    for(int i = 0; i < m_Length; i++){
        if(data > m_Array[m_Length-1]){// data가 마지막 값보다 크면 마지막에 저장
            m_Array[m_Length] = data;
        }
        else if(data < m_Array[0]){// data가 첫번째 값보다 작으면 첫번째에 저장
            for(int j = m_Length; i < j; j--){
                m_Array[j] = m_Array[j-1];
            }
            m_Array[0] = data;
        }
        else if (m_Array[i] < data && data < m_Array[i+1]){// data가 사이에 존재할 경우 사이에 저장
            for(int j = m_Length; i < j; j--){
                m_Array[j] = m_Array[j-1];
            }
            m_Array[i+1] = data;
        }
    }
    m_Length++;
    
    return 1;
}

template <typename T>
int SortedList<T>::Delete(T data){
    
    if(m_Length == 0)
        cout<<"\t\t List is empty."<<endl;
    
    for(int i = 0; i < m_Length; i++){
        if(data == m_Array[i]){
            if(i == m_Length-1)
                m_Length--;
            else{
                for(; i < m_Length; i++){
                    m_Array[i] = m_Array[i+1];
                }
                m_Length--;
                return 1;
            }
        }
    }
    
    return 0;
}

template <typename T>
int SortedList<T>::Replace(T data){
    for(int i = 0; i < m_Length; i++){
        if(m_Array[i] == data){
            m_Array[i] = data;
            return 1;
        }
    }
    return 0;
}


template <typename T>
int SortedList<T>::Retrieve_Seq(T& data){
    
    for(int i = 0; i < m_Length; i++){
        if(data == m_Array[i]){
            data = m_Array[i];
            return 1;
        }
    }
    
    return 0;
}

template <typename T>
int SortedList<T>::Retrieve_Binary(T& data){
    int first = 0;
    int last = m_Length-1;
    int mid;
    
    while(first <= last){
        mid = (first+last)/2;
        
        if(data == m_Array[mid]){
            data = m_Array[mid];
            return 1;
        }
        else{
            if(data > m_Array[mid])
                first = mid + 1;
            else
                last = mid - 1;
        }
    }
    
    return 0;
}

