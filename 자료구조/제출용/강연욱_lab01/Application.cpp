#include "Application.h"
#include "ArrayList.h"



void Application::Run(){
    while (1){
        m_Command = GetCommand();
        switch(m_Command){
            case 1:// 곡 정보를 입력 받아 리스트에 추가
                AddMusic();
                break;
            case 2:// 곡의 고유번호를 입력 받아 리스트에서 삭제
                DeleteMusic();
                break;
            case 3:// 곡 정보를 입력 받아서 리스트에서 해당 곡 정보를 갱신
                ReplaceMusic();
                break;
            case 4:// 입력된 정보로 리스트에서 곡을 찾아서 화면에 출력
                RetrieveMusic();
                break;
            case 5:// 리스트에 저장된 모든 곡을 화면에 출력
                ​​​DisplayAllMusic();
                break;
            case 6:// 리스트에 입력된 모든 곡을 삭제
                m_List.MakeEmpty();
                break;
            case 7:// load list data from a file.
                ReadDataFromFile();
                break;
            case 8:// save list data into a file.
                ​​WriteDataToFile();
                break;
            case 0:
                return;
            default:
                cout<<"\tIllegal selection...\n";
                break;
        }
    }
}


int Application::GetCommand(){
    int command;
    cout<<endl<<endl;
    cout<<"\t---ID -- Command ----- "<<endl;
    cout<<"\t   1 : Add Music"<<endl;
    cout<<"\t   2 : Delete Music"<<endl;
    cout<<"\t   3 : Replace Music"<<endl;
    cout<<"\t   4 : Search Music"<<endl;
    cout<<"\t   5 : Print all on screen"<<endl;
    cout<<"\t   6 : Make empty list"<<endl;
    cout<<"\t   7 : Get from File"<<endl;
    cout<<"\t   8 : Put to File"<<endl;
    cout<<"\t   0 : Quit"<<endl;
    
    cout<<endl<<"\t Choose a Command--> ";
    cin>>command;
    cout<<endl;
    
    return command;
}



int Application::AddMusic(){
    if(m_List.IsFull())
        cout<<"\t List is full."<<endl<<endl;
    
    ItemType data;      //빈 객체 생성
    
    data.SetRecordFromKB(); //빈 객체에 내용 저장
    m_List.Add(data);       //내용이 담긴 객체를 배열객체에 추가
    
    ​​​DisplayAllMusic();
    
    return 1;
    
}

int Application::DeleteMusic(){
    if(m_List.IsEmpty())
        cout<<"\t List is empty."<<endl<<endl;
    
    ItemType data;
    
    data.SetPrimaryFromKB();
    m_List.Delete(data);
    
    ​​​DisplayAllMusic();
    return 1;
}

void Application::ReplaceMusic(){
    ItemType data;
    
    data.SetPrimaryFromKB();
    m_List.Get(data);
    data.DisplayRecordOnScreen();   // 치환될 자리의 내용을 미리 확인
    
    // 치환할 값들을 입력
    data.SetTypeFromKB();
    data.SetMusicFromKB();
    data.SetComposerFromKB();
    data.SetArtistFromKB();
    data.SetGenreFromKB();
    data.SetPrimaryFromKB();
    
    m_List.ReplaceItem(data);   //입력받은 내용을 치환
    
}
void Application::RetrieveMusic(){
    ItemType data;
    
    data.SetPrimaryFromKB();
    m_List.Get(data);       //고유번호를 입력하여 배열에 있는 내용들과 비교
    data.DisplayRecordOnScreen();
}

void Application::​​​DisplayAllMusic(){
    ItemType data;
    cout << "\n\tCurrent list" << endl;
    
    m_List.ResetList();     //배열 초기화
    
    for(int i = 0; i<m_List.GetLength(); i++){
        m_List.GetNextItem(data);   //객체가 다음 메소드를 통해 반복하여 자리가 채워짐  data에 m_Array의 내용들을 넣어서 출력.
        data.DisplayRecordOnScreen();   //채워진 내용들을 보여줌
    }
    
}
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
    string filename;
    cout<<"\t File Name: ";
    cin>>filename;
    
    ItemType item;
    
    if(!OpenInFile(filename))
        return 0;
    
    while(!m_InFile.eof()){
        item.ReadDataFromFile(m_InFile);  //파일로 읽은 내용을 data객체에 저장
        m_List.Add(item);       //저장된 내용을 화면에 출력해주기 위해 배열에 저장(m_Array에 저장해주는 작업)
    }
    
    m_InFile.close();
    
    ​​​DisplayAllMusic();       //배열에 저장된 내용을 출력
    
    return 1;
}

int Application::​​WriteDataToFile(){
    string filename;
    cout<<"\t File Name: ";
    cin>>filename;
    
    ItemType data;
    
    if(!OpenOutFile(filename))
        return 0;
    
    m_List.ResetList();
    
    for(int i = 0; i < m_List.GetLength(); i++){
        m_List.GetNextItem(data);                   //빈 객체를 넣어서 저장돼 있는 값을 반복하여 넣어준다
        data.WriteDataToFile(m_OutFile);            //그 객체들을 해당 메소드를 사용해 파일객체를 통해 파일로 저장해준다.
    }
    
    m_OutFile.close();
    
    return 1;
}
