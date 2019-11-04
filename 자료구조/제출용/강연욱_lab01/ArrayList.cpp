#include "ArrayList.h"

//배열에 대한 정보를 메소드로 정리
//m_Array는 배열로 표현된 객체이고 data는 단일 객체이다. 근데 data는 주로 내가 입력한 내용을 전달하는 파라미터 용도로 쓰임

void ArrayList::MakeEmpty(){//clear
    m_Length = 0;
}
//길이를 리턴하는 함수
int ArrayList::GetLength(){//clear
    return m_Length;
}
//꽉 차 있는 확인하는 함수
bool ArrayList::IsFull(){//clear
    if(m_Length != MAXSIZE)
        return 0;
    else
        return 1;
}

//배열이 비었는지 여부
bool ArrayList::IsEmpty(){//clear
    if(m_Length != 0)
        return 0;
    else
        return 1;
}

//추가하는 함수
int ArrayList::Add(ItemType data){//clear
    if(!IsFull()){
        m_Array[m_Length] = data;
        m_Length++;
        return 1;
    }
    else
        return 0;
}
int ArrayList::Delete(ItemType data){ // 기존 레코드 삭제
    if(IsEmpty())
        return 0;
    
    for(int i = 0; i < m_Length ; i++){
        if(data == m_Array[i]){
            if(i == m_Length-1)
                m_Length--;
            else{
                for(; i<m_Length ; i++){
                    m_Array[i] = m_Array[i+1];
                }
                m_Length--;
            }
        }
    }
    return 1;
}


//비교연산자는 ItemType class에서 만들어줘야한다.
int ArrayList::Get(ItemType& data){
    for(int i = 0; i < m_Length; i++){
        if(data == m_Array[i]){     //이때는 primary 가지고 만 비교
            data = m_Array[i];      //data에 m_Array에 있는 값을 넣어줌 -> 이 줄이 있어야 출력할 때, 해당 인덱스의 내용이 전달된다.
            cout<<endl;
        }
    }
    return 1;
}

void ArrayList::ResetList(){
    m_CurPointer = -1;
}

// current pointer를 하나 증가시키고 끝이 아니면 record index를 리턴 끝이면 -1을 리턴
int ArrayList::GetNextItem(ItemType& data){
    m_CurPointer++;
    
    if(m_Length == m_CurPointer)
        return -1;
    
    data = m_Array[m_CurPointer];

    return 1;

}
// 입력된 data와 Primary key와 동일한 기록을 찾아서 List의 해당 기록을 입력된 data로 치환한다.
//Primary key = ID

int ArrayList::ReplaceItem(ItemType data){//clear
    for(int i = 0; i < m_Length; i++){
        if(data == m_Array[i])
            m_Array[i] = data;
    }
    
    return 1;
}


