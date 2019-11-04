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
        if(m_Length == MAXSIZE)        //MAXSIZE = 100
            return 1;
        else
            return 0;
    }
bool ArrayList::IsEmpty(){ //배열이 비었는지 여부//clear
    if(m_Length == 0)
        return 1;
    else
        return 0;
}

//추가하는 함수
int ArrayList::Add(ItemType data){//clear
    //배열객체 안에 객체가 들어가는 것.
        if(!IsFull()){
            m_Array[m_Length] = data;      //비어 있다면 m_Array[0]에 data값이 들어가고 m_Length는 1만큼 증가한다..
            m_Length++;                     //할당 받은 정보를 배열에 추가.
        }                       //m_Length의 길이는 Add가 책임진다.
        else
            return 0;
        
        return 1;
}
int ArrayList::Delete(ItemType data){ // 기존 레코드 삭제//clear
    //Application에서 data에 ID값을 입력하여 참조함.
    
    if(m_Length == 0)
        cout<<"\t\t List is empty."<<endl;

    
    for(int i = 0; i < m_Length; i++){   //처음부터 끝까지 확인해본다.
        if(data == m_Array[i]){
           // if(i == m_Length-1){     //만약 제일 끝 값을 삭제한다면
            //    m_Length--;     //그냥 길이를 1 만큼 줄이면 그만이다.
           // }
            //else{               //끝 값이 아닌 처음 또는 중간의 값을 삭제한다고 하면..
                for(; i < m_Length; i++){
                    m_Array[i] = m_Array[i+1];     //뒤에 값을 하나씩 앞으로 당긴다. 그럼 맨 뒤에 값은????
                }//만약 반복문을 하나만 쓰게 되면, 예를들어 0번째에서 같을 경우 [0]에 [1] 값을 할당하고 그걸로 끝나게 된다.
                //한 칸 씩 앞으로 당기려면 이중 포문을 사용해야다. i의 초기값을 정해주지 않은 것은 전체 포문중 문제가 발생하는 번째부터 앞으로 당기기 위해서 이다.
                //초기값을 정해줘 버리면 포문을 한 개만 쓴 것과 다를게 없다.
            m_Length--;  //하나가 삭제되는 것이므로 반복이 끝나면 길이를 하나 줄여줌.  남은 맨 뒤 값은 길이삭제로 없애주면된다.
           // }
        }
        //[정리] 즉, 입력 학번과 같은 객체를 찾아 해당 인덱스부터 한칸씩 앞으로 당기고 길이를 줄인다.
    }
    
    return 1;
}


//비교연산자는 ItemType class에서 만들어줘야한다.
int ArrayList::Get(ItemType& data){// Primary key를 기준으로 데이터를 검색하고 해당 데이터를 가져옴 //clear
    //Application에서 data에 ID값을 입력하여 참조함.
    for(int i = 0; i < m_Length; i++){
        if(data == m_Array[i]){  //data라는 객체는 입력받은 내용을 GetId()에 저장하여 다음과 같이 비교연산을 한다.
            data = m_Array[i];
            cout<<endl;
        }
    }
    
    return 1;
}//템플릿, 연산자 오버로딩 사용하여 generic함을 구현해야한다.

// 레코드 포인터(current pointer) 초기화
// 이해부족 -> 질문
void ArrayList::ResetList(){
        m_CurPointer = -1; //왜 -1??  -> 아마 제일 현재 포인터가 제일 최근 값인 끝 값을 나타내기 때문에 -1이라고 한듯.
}

    // current pointer를 하나 증가시키고 끝이 아니면 record index를 리턴 끝이면 -1을 리턴
    //이 부분 정확한 이해 필요
int ArrayList::GetNextItem(ItemType& data){
        m_CurPointer++;
        if(m_CurPointer == m_Length)
            return -1;  //아마 제일 끝값인 m_Array[-1]을 의미하는 듯..
    
        data = m_Array[m_CurPointer]; //이 부분 잘 이해가 안 됨.
        //0부터 반복하면서 다음 data값을 불러오게 함.
        return 1;           //얘를 뭘로 정해줘야 맞지...?
    }
// 입력된 data와 Primary key와 동일한 기록을 찾아서 List의 해당 기록을 입력된 data로 치환한다.
//Primary key = ID

int ArrayList::ReplaceItem(ItemType data){//clear

    for(int i = 0; i < m_Length; i++){              //이렇게 하면 파라미터로 온 data는 어떻게 쓰지????(질문)
        if(m_Array[i] == data){ //내가 만든 비교연산자는 ID만 비교하도록 해놓음.
            m_Array[i] = data;
        }
    }
    
    return 1;
}


