#include <iostream>
using namespace std;

class Node{
public:
    int data;   //데이터 저장
    Node *next; //연결해주는 고리역할
                //노드에 [데이터 저장부분 | 꼬리부분] 이런식으로 되게 만들어주기위해..
};

int main(){
    //초기화
    Node *head = NULL;      //첫번째 노드를 가리키도록(무조건 필요하다)
    Node *tail = NULL;      //끝 노드를 가리키도록(없을 수도 있다)
    Node *cur = NULL;       //내가 어디까지 갔는지에 대한 정보를 담는다
    
    Node *newNode = NULL;
    int readData;
    //노드의 생성 및 추가
    while (1){
        cout<<"자연수 입력 : ";
        cin>>readData;
        if(readData < 1)
            break;          //입력받는 데이터가 1보다 작으면 빠져나감
        //노드의 추가과정
        newNode = new Node();       //노드를 동적할당하여 생성
        newNode->data = readData;   //데이터 입력받은것을 저장
        newNode->next = NULL;       //고리에는 NULL이 저장  [readData|NULL]
        //머리이자 동시에 꼬리(처음 선언되어서.. 하나밖에없으니까..)
        
        //첫 번째 노드와 그 이후의 노드를 추가하는 루틴이 다르다. [중요!!!!!!!!]
        if(head == NULL)
            head = newNode;
        else
            tail->next = newNode;//[중요]tail->next : tail이 가리키는 멤버 next (2회전이상일때)
        
        tail = newNode;     //tail이 새노드를 가리키게 됨..
        //연결리스트의 개념적이해 3강 참고..
        
        //헤드와 테일이 새노드(머리이자 꼬리)를 동시에 가리키게 됨(1회전 경우)
        //끝나면 다시 반복되어 또 다른 새로운 노드를 만든다.
    }
    cout<<endl;
    //데이터 조회(순차적)
    cout<<"저장 된 데이터 전체 출력 : ";
    if(head == NULL){
        cout<<"저장된 값 없음"<<endl;
    }
    else{
        cur = head;     //cur가 첫 번째 노드를 가리키게 된다.
        cout<<cur->data<<" ";   //첫 노드의 데이터 값.
        
        while(cur->next != NULL){   //다음 데이터가 비어있지 않으면 반복
            //이동이 필요하다. cur의 next엔 다음값이 저장되어 있으므로 다음과 같은 코드를 쓰면
            // 다음값이 cur에 저장되게 되어서 이동하는 역할을 하게 된다.
            //즉, cur가 가리키는 노드의 멤버 next를 cur에 저장.
            cur = cur->next;
            cout<<cur->data<<" ";   //출력하며 참조 완료!
        }//여기서도 역시 첫번째 노드 참조 방법과 그이후의 방법이 나뉨을 알 수 있다.
    }
    cout<<endl<<endl;
    
    
    //전체 노드의 삭제 과정
    //데이터 삭제_특정 위치에 있는 노드 하나를 삭제하는 방법.
    //삭제를 하려면 노드를 가리키는 포인터변수가 2개가 있어야 한다.
    if (head == NULL)
        return 0;
    
    else{
        Node *delNode = head;       //delNode에 해드노드를 저장
        Node *delNextNode = head->next; //delNextNode에 그 다음 노드를 저장
        
        cout << head->data << " 을 삭제합니다" << endl;
        delete delNode;
        //[중요]
        while (delNextNode != NULL){// delNextNode != NULL는 맨마지막까지라는 의미와 동일.
            delNode = delNextNode;      //저장을 하고
            delNextNode = delNextNode->next;    //하나씩 밀어서 저장하고
                                                //그 다음 삭제
            cout << delNode->data << " 을 삭제합니다" << endl;
            delete delNode;
        }
    }//여기서도 역시 첫번째 노드 참조 방법과 그이후의 방법이 나뉨을 알 수 있다.
}
