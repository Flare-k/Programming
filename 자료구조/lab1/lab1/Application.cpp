#include "Application.h"
#include "ArrayList.h"
#define FILENAMESIZE 1024

void Application::Run(){
    while(1) {
        m_Command = GetCommand();
        switch(m_Command)
        {
            case 1:// read a record and add to list.
                AddItem();
                break;
            case 2:// display all the records on screen.
                DisplayAllItem();
                break;
            case 3:// make empty list.
                m_List.MakeEmpty();
                break;
            case 4:// load list data from a file.
                ReadDataFromFile();
                break;
            case 5:// save list data into a file.
                WriteDataToFile();
                break;
            case 6:// save list data into a file.
                RetrieveStudent();
                break;
            case 7:// save list data into a file.
                DeleteStudent();
                break;
            case 8:
                Replace();
                break;
            case 0:
                return;
            default:
                cout << "\tIllegal selection...\n";
                break;
                
        }
    }
}
int Application::GetCommand(){
    int command;
    cout << endl << endl;
    cout << "\t---ID -- Command ----- " << endl;
    cout << "\t   1 : Add item" << endl;
    cout << "\t   2 : Print all on screen" << endl;
    cout << "\t   3 : Make empty list" << endl;
    cout << "\t   4 : Get from file" << endl;
    cout << "\t   5 : Put to file " << endl;
    cout << "\t   6 : Search item " << endl;
    cout << "\t   7 : Delete item " << endl;
    cout << "\t   8 : Replace item " <<endl;
    cout << "\t   0 : Quit" << endl;
    
    cout << endl << "\t Choose a Command--> ";
    cin >> command;
    cout << endl;
    
    return command;
}

// 1.
int Application::AddItem(){//clear
    if(m_List.IsFull()){
        cout<<"List is Full."<<endl;
        return 0;
    }
    ItemType data;
    
    data.SetRecordFromKB(); //data객체의 메소드를 이용하여 정보를 할당.
    //객체를 만들고 정보를 채워서 배열에 넣어야한다.
    m_List.Add(data);   //배열에 입력받은 정보 추가
    DisplayAllItem();   //바로 내용확인
    return 1;
}
// 2.
void Application::DisplayAllItem(){//왜 리셋을 쓰지..?   //이 부분 정확한 이해 필요.
    ItemType data;
    cout << "\n\tCurrent list" << endl;
    
    int length = m_List.GetLength();
    m_List.ResetList();
   
    for(int i = 0; i < length; i++){
        m_List.GetNextItem(data);
        data.DisplayRecordOnScreen();   
    }
    
    
    /*
    int length = m_List.GetLength();
    int current = m_List.GetNextItem(data);     //ResetList와 GetNextItem을 통해서 [0]번째이다.
    
    while(current < length && current != -1){       //0<길이 이고 current가 -1(마지막 값)이 아니면
        data.DisplayRecordOnScreen();       //[0]번째 출력, 밑에 줄 실행 후, [1]번째 출력.. 반복!  length-1까지
        current = m_List.GetNextItem(data);     //다음 메소드를 통해서 [0]번째가 들어가면 m_Cur가 1증가하여 [1]인 다음값이 나온다. 쭉 반복
    
    }
     */
    /*
     현재 리스트의 길이를 length에 담음, current는 0번지 부터 끝까지 점점 커지게 됨
     반복문을 통해서 current가 길이보다 작고 -1이 아니면 
    */
    /*
    ItemType data[MAXSIZE];
    for(int i = 0; i < m_List.GetLength(); i++){
        data[i].DisplayRecordOnScreen();
    }
     */  //이렇게 짜면 왜 안 나올까..
    
}


// 3. MakeEmpty


// 4, 5.
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
    /*
    int current = m_List.GetNextItem(data);     //화면 출력 = 파일 저장  같은 논리구조를 가지고 있다.
    
    while(current < length && current != -1){
        data.WriteDataToFile(m_OutFile);    //ItemType의 메소드
        current = m_List.GetNextItem(data);
        
    }*/
    
    for(int i = 0; i < length; i++){
        m_List.GetNextItem(data);
        data.WriteDataToFile(m_OutFile);
    }
    
    m_OutFile.close();    // file close
    
    return 1;
}


// 6.
void Application::RetrieveStudent(){        //Get함수와 호응..
    ItemType data;
    
    data.SetIdFromKB(); //data라는 객체는 ID를 입력받는 메소드를 실행해줌
    m_List.Get(data);   //ArrayList의 메소드.
    data.DisplayRecordOnScreen();
}


// 7.
int Application::DeleteStudent(){
    if(m_List.IsEmpty()){
        cout<<"List is Empty."<<endl;
        return 0;
    }
    ItemType data;  //빈 객체하나 만듬.
    
    data.SetIdFromKB(); //data라는 객체는 ID를 입력받는 메소드를 실행해줌
    m_List.Delete(data); //ArrayList의 메소드.
    
    DisplayAllItem();
    return 1;
}

// 8.
void Application::Replace(){
    ItemType data;
    
    data.SetIdFromKB(); //data라는 객체는 ID를 입력받는 메소드를 실행해줌
    m_List.Get(data);   //ArrayList의 메소드.
    data.DisplayRecordOnScreen();
    
    data.SetIdFromKB(); //data라는 객체는 ID를 입력받는 메소드를 실행해줌
    data.SetNameFromKB();
    data.SetAddressFromKB();
    
    m_List.ReplaceItem(data);   //비교하고 값 바꿔주기!
    
    
}


// ArrayList class에 ItemType class의 메소드를 쓰면 안되고
// ItemType class에서도 ArrayList class의 메소드를 쓰면 안 된다. 서로 각자 자신의 기능만 해줘야한다.
// 하지만 Application class에서는 두 클래스의 기능을 보여줘야 하므로 두 클래스의 멤버메소드를 사용해도 된다.
