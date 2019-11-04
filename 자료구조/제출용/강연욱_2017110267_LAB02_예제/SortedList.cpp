#include "SortedList.h"


//길이를 0으로 초기화 시키는 함수
void SortedList::MakeEmpty(){
    m_Length = 0;
}

//길이를 리턴하는 함수
int SortedList::GetLength(){
    return m_Length;
}

//꽉 차 있는 확인하는 함수
bool SortedList::IsFull(){
    if(m_Length == MAXSIZE) //MAXSIZE = 10
        return 1;
    else
        return 0;
}

//배열이 비었는지 여부
bool SortedList::IsEmpty(){
    if(m_Length == 0)
        return 1;
    else
        return 0;
}

// 레코드 포인터(current pointer) 초기화
void SortedList::ResetList(){
    m_CurPointer = -1;
}

// current pointer를 하나 증가시키고 끝이 아니면 record index를 리턴 끝이면 -1을 리턴
int SortedList::GetNextItem(ItemType& data){
    m_CurPointer++;
    if(m_CurPointer == m_Length)
        return -1;
    
    data = m_Array[m_CurPointer];
    //0부터 반복하면서 다음 data값을 불러오게 함.
    return 1;
}


//배열에 추가하는 함수
int SortedList::Add(ItemType data){
    
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
            cout<<"\t============================"<<endl;
            cout<<"\t ID is already exist."<<endl;
            cout<<"\t============================"<<endl;
            return 0;
        }
    }
    
    //중복이 아닐경우 실행문
    for(int i = 0; i < m_Length; i++){
        if(data != m_Array[i]){
                // data가 마지막 값보다 크면 마지막에 저장
                if(data > m_Array[m_Length-1]){
                    m_Array[m_Length] = data;
                }
                // data가 첫번째 값보다 작으면 첫번째에 저장
                else if(data < m_Array[0]){
                    for(int j = m_Length; i < j; j--){
                        m_Array[j] = m_Array[j-1];
                    }
                    m_Array[0] = data;
                }
                // data가 사이에 존재할 경우 사이에 저장
                else if (m_Array[i] < data && data < m_Array[i+1]){
                    for(int j = m_Length; i < j; j--){
                        m_Array[j] = m_Array[j-1];
                    }
                    m_Array[i+1] = data;
                }
            }
    }
    m_Length++;
    
    return 1;
}


// 기존 레코드 삭제
int SortedList::Delete(ItemType data){
    
    if(m_Length == 0)
        cout<<"\t\t List is empty."<<endl;
    
    for(int i = 0; i < m_Length; i++){
        if(data == m_Array[i]){
            for(; i < m_Length; i++){
                m_Array[i] = m_Array[i+1];
            }
            m_Length--;
            return 1;
        }
    }
    return 0;
}


// 입력된 data와 Primary key와 동일한 기록을 찾아서 List의 해당 기록을 입력된 data로 치환한다. Primary key = ID
int SortedList::Replace(ItemType data){
    for(int i = 0; i < m_Length; i++){
        if(m_Array[i] == data){
            m_Array[i] = data;
            cout<<"\t ===========Complete==========="<<endl;
            return 1;
        }
    }
    cout<<"\t ==========Not Change=========="<<endl;
    return 0;
}

// Primary key를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
int SortedList::Retrieve_Seq(ItemType& data){
    for(int i = 0; i < m_Length; i++){
        if(data == m_Array[i]){   //ID만 가지고 있는 data라는 객체의 ID와 이미 저장된 내용들의 ID를 비교연산한다.
            data = m_Array[i];  //ID가 같으면 저장된 내용을 data객체에 저장해준다.
            return 1;
        }
    }
    
    return 0;
}


//이진탐색
int SortedList::Retrieve_Binary(ItemType& data){        //Primary Key가 담겨있는 data객체
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

