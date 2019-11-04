#include "Application.h"
#include "SortedList.h"
#define FILENAMESIZE 1024

void Application::Run(){
    while(1) {
        m_Command = GetCommand();
        switch(m_Command)
        {
            case 1: //객체를 추가하는 기능
                AddItem();
                break;
            case 2: //기존 레코드 삭제 기능
                DeleteStudent();
                break;
            case 3: // ID를 비교하여 같으면 정보를 순차탐색하여 출력
                RetrieveStudent();
                break;
            case 4: // ID를 비교하여 같으면 정보를 이진탐색하여 출력
                SearchByid_BinaryS();
                break;
            case 5: // ID를 비교하여 같으면 객체 정보를 치환
                ReplaceItem();
                break;
            case 7: //전체 레코드를 보여주는 기능
                DisplayAllItem();
                break;
            case 8: // 모든 레코드 값을 지워주는 기능
                m_List.MakeEmpty();
                break;
            case 9: // 파일에 저장된 내용을 불러오는 기능
                ReadDataFromFile();
                break;
            case 10: //파일에 저장하는 기능
                WriteDataToFile();
                break;
            case 0: // 종료
                return;
            default:    // 맞지 않는 숫자를 입력했을 때의 출력
                cout << "\tIllegal selection...\n";
                break;
                
        }
    }
}
int Application::GetCommand(){
    int command;
    cout << endl << endl;
    cout << "\t---ID -- Command ----- " << endl;
    cout << "\t   1 : Add item " << endl;
    cout << "\t   2 : Delete item " << endl;
    cout << "\t   3 : Search item by SQ " << endl;
    cout << "\t   4 : Search item by BS " << endl;
    cout << "\t   5 : Replace item " << endl;
    cout << "\t   7 : Print all on screen " << endl;
    cout << "\t   8 : Make empty list " << endl;
    cout << "\t   9 : Get from file " << endl;
    cout << "\t   10 : Put to file " << endl;
    cout << "\t   0 : Quit" << endl;
    
    cout << endl << "\t Choose a Command--> ";
    cin >> command;
    cout << endl;
    
    return command;
}

// 1.Add item
int Application::AddItem(){
    if(m_List.IsFull()){
        cout<<"List is Full."<<endl;
        return 0;
    }
    ItemType data;
    
    data.SetRecordFromKB(); //data객체의 메소드를 이용하여 정보를 할당.

    m_List.Add(data);   //배열에 입력받은 정보 추가
    cout<<"\t============================"<<endl;
    DisplayAllItem();   //바로 내용확인
    return 1;
}
// 2.Delete item
int Application::DeleteStudent(){
    if(m_List.IsEmpty()){
        cout<<"\t List is Empty."<<endl;
        return 0;
    }
    ItemType data;  //빈 객체하나 만듬.
    
    data.SetIdFromKB(); //data라는 객체는 ID를 입력받는 메소드를 실행해줌
    if(m_List.Delete(data)){ //ArrayList의 메소드.
        cout<<"============ Item is Deleted !=========="<<endl;
        DisplayAllItem();
        return 1;
    }
    else{
        cout<<"============ Item is not Deleted !=========="<<endl;
        DisplayAllItem();
        return 0;
    }
    
}

// 3.Search item by SQ
void Application::RetrieveStudent(){
    ItemType data;
    
    data.SetIdFromKB(); //data라는 객체는 ID를 입력받는 메소드를 실행해줌
    
    if(m_List.Retrieve_Seq(data)){   //ArrayList의 메소드.
    cout<<endl;
    cout<<"========= Item FOUND by Sequence Search======="<<endl;
    data.DisplayRecordOnScreen();
    cout<<"==============================================="<<endl;

    }
    else{
        cout<<endl;
        cout<<"===== Item Not Found by Sequence Search ====="<<endl;
    }
    
}

// 4.Search item by BS
void Application::SearchByid_BinaryS(){
    ItemType data;
    
    data.SetIdFromKB();
    
    if(m_List.Retrieve_Binary(data)){   //ArrayList의 메소드.
        cout<<endl;
        cout<<"========= Item FOUND by Binary Search======="<<endl;
        data.DisplayRecordOnScreen();
        cout<<"============================================="<<endl;
        
    }
    else{
        cout<<endl;
        cout<<"===== Item Not Found by Binary Search ====="<<endl;
    }
}

// 5.Replace item
void Application::ReplaceItem(){
    ItemType data;
    
    cout<<"\t ======Change the record======"<<endl;
    cout<<"\t   (ID should be in Array.)   "<<endl;
    data.SetIdFromKB(); //data라는 객체는 ID를 입력받는 메소드를 실행해줌
    data.SetNameFromKB();
    data.SetAddressFromKB();
    m_List.Replace(data);   //비교하고 값 바꿔주기!
        
    
    
}



// 7.Print all on screen
void Application::DisplayAllItem(){
    ItemType data;
    cout << "\n\t* Current list *" << endl;
    
    int length = m_List.GetLength();
    m_List.ResetList();
    
    for(int i = 0; i < length; i++){
        m_List.GetNextItem(data);
        data.DisplayRecordOnScreen();
    }
}


// 8. MakeEmpty


// 9, 10.  Get from file / Put to file
int Application::OpenInFile(string &fileName){
    m_InFile.open(fileName);
    
    if(!m_InFile)
        return 0;
    else
        return 1;
}

int Application::OpenOutFile(string &fileName){
    m_OutFile.open(fileName);
    
    if(!m_OutFile)
        return 0;
    else
        return 1;
}
int Application::ReadDataFromFile(){
    ItemType data;
    
    string filename;
    cout<<"\n\t File Name: ";
    cin>>filename;
    
    if(!OpenInFile(filename))
        return 0;
    
    while(!m_InFile.eof()){         //만약 읽을 파일이 끝나지 않았다면 계속 읽어 들일 것!
        data.ReadDataFromFile(m_InFile);        //ItemType의 메소드
        m_List.Add(data);//읽은거 저장..
    }
    m_InFile.close();
    
    DisplayAllItem();
    return 1;
}
int Application::WriteDataToFile(){
    ItemType data;
    
    string filename="";
    cout<<"\n\t File Name: ";
    cin>>filename;
    
    if(!OpenOutFile(filename))
        return 0;
    
    m_List.ResetList();//ArrayList의 메소드.
    
    int length = m_List.GetLength();
    
    for(int i = 0; i < length; i++){
        m_List.GetNextItem(data);
        data.WriteDataToFile(m_OutFile);
    }
    
    m_OutFile.close();    // file close
    
    return 1;
}

