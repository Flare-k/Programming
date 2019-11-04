#include "Application.h"


void Application::Run(){
    int num = 0;
    
    try{
        while(1) {
            m_Command = GetCommand();
            switch(m_Command)
            {
                case 1: //객체를 추가하는 기능
                    AddMusic();
                    break;
                case 2: //기존 레코드 삭제 기능
                    DeleteMusic();
                    break;
                case 3: // 동일한 Primary Key를 가진 정보를 입력받은 정보로 치환
                    ReplaceMusic();
                    break;
                case 4: // Primary Key를 비교하여 같으면 정보를 출력 (순차탐색)
                    cout<<"\t           ======== Search ========"<<endl;
                    cout<<"\t           1 : Search Music by SQ "<<endl;
                    cout<<"\t           2 : Search Music by BS "<<endl;
                    cout<<"\t           3 : Search by Artist "<<endl;
                    cout<<"\t           4 : Search by Genre "<<endl;
                    cout<<"\t           ========================"<<endl;
                    cout<<"\n\t         Enter the number  --> ";
                    cin>>num;
                    if(num == 1)
                        SearchByid_Seq();
                    else if(num == 2)
                        SearchinPL_BinaryS();
                    else if(num == 3)
                        SearchByArtist();
                    else
                        SearchByGenre();
                    /*
                     Search와 관련된 함수가 4개가 있어서 한 케이스 안에
                     조건문으로 묶어놨습니다.
                     */
                    break;
                case 5: //전체 레코드를 보여주는 기능
                    ​​​DisplayAllMusic();
                    break;
                case 6: // 모든 레코드 값을 지워주는 기능
                    m_List.MakeEmpty();
                    s_List.MakeEmpty();
                    simple_List.MakeEmpty();
                    break;
                case 7: // 파일에 저장된 내용을 불러오는 기능
                    ReadDataFromFile();
                    break;
                case 8: //파일에 저장하는 기능
                    WriteDataToFile();
                    break;
                case 11:
                    AddtoPlayList();    //플레이 리스트에 추가하는 함수
                    break;
                case 12:
                    DeletetoPlayList();   //플레이 리스트에서 제거하는 함수
                    break;
                case 13:
                    PlayInsertOrder();   //플레이 리스트를 플레이하는 함수
                    break;
                case 14:
                    PrintPlayList();    //플레이 리스트의 모든 곡을 보여주는 함수
                    break;
                case 15:
                    SearchinPL_BinaryS();//플레이 리스트 내에서 원하는 곡을 이진탐색으로 찾아주는 함수
                    break;
                case 21:
                    AddSinger();
                    break;
                case 22:
                    AddSong();
                    break;
                case 23:
                    ​​​DisplayAllSingerList();
                    break;
                case 24:
                    ​​​DisplayAllSongList();
                    break;
                case 25:
                    SearchBySinger();
                    break;
                case 31:
                    TestEmptyException(); // 예외처리 테스트함수 (비어있는 경우)
                    break;
                case 32:
                    TestFullException();    //예외처리 테스트함수 (가득 차 있는 경우)
                    break;
                case 0: // 종료
                    return;
                default:    // 맞지 않는 숫자를 입력했을 때의 출력
                    cout << "\t Illegal selection...\n";
                    break;
            }
        }
    }
    
    catch(FullQueue e){
        e.print();
    }
    catch(EmptyQueue e){
        e.print();
    }
    
}
int Application::GetCommand(){
    int command;
    cout<<endl<<endl;
    cout<<"\t   ====== Master List ====== "<<endl;
    cout<<"\t   1 : Add Music "<<endl;
    cout<<"\t   2 : Delete Music "<<endl;
    cout<<"\t   3 : Replace Music "<<endl;
    cout<<"\t   4 : Search Music "<<endl;
    cout<<"\t   5 : Print Master List "<<endl;
    cout<<"\t   6 : Make empty list "<<endl;
    cout<<"\t   7 : Get from file "<<endl;
    cout<<"\t   8 : Put to file "<<endl;
    cout<<"\t   ======= Play List ======= "<<endl;
    cout<<"\t   11 : Add to Play List "<<endl;
    cout<<"\t   12 : Delete to PlayList "<<endl;
    cout<<"\t   13 : Play Insert Order "<<endl;
    cout<<"\t   14 : Print Play List "<<endl;
    cout<<"\t   15 : Search in Play List "<<endl;
    cout<<"\t   ======= Singer List ======= "<<endl;
    cout<<"\t   21 : Add Singer "<<endl;
    cout<<"\t   22 : Add Song "<<endl;
    cout<<"\t   23 : Print Singer List "<<endl;
    cout<<"\t   24 : Print Song List "<<endl;
    cout<<"\t   25 : Search in Singer List "<<endl;
    cout<<"\t   ===== Test Exception ===== "<<endl;
    cout<<"\t   31. Emptyqueue Exception test"<<endl;
    cout<<"\t   32. Fullqueue Exception test"<<endl;
    cout<<"\t   0 : Quit" << endl;
    
    cout << endl << "\t Choose a Command--> ";
    cin >> command;
    cout << endl;
    
    return command;
}

//--------------------------------- Master List    -----------------------------------

// 1.
/*
 AddMusic() = Master List, Singer List, Song List에 입력값을 연동하여 저장하는 함수.
 
 ItemType 객체에 키보드로 모든 정보의 값을 입력받고 Master List에 저장될 때,
 Singer List에도 동시에 저장되어야 합니다.
 따라서 ItemType 객체로 입력 받은 정보를 통해,
 SingerType객체와 SongType객체에 서로의 메소드를(Set함수, ItemType의 Get함수) 활용하여 값을 입력해줍니다.
 Master List에 객체를 저장할 때, Singer List가 비어있거나 같은 Primary Key를 가진 객체가 없을 경우
 Singer List에도 저장해줍니다. 뿐만아니라 Song List도 관리해야 하므로 동시에 Song List에도 저장해줍니다.
 */
int Application::AddMusic(){
    
    if(m_List.IsFull()){
        cout<<"\t List is Full."<<endl;
        return 0;
    }
    ItemType data;
    Singer singer;
    SimpleItemType songinput;
    
    data.SetRecordFromKB(); //아이템 객체로 정보를 입력받습니다. (키보드로의 정보 입력은 여기서 단 한번 실행됨)
    
    songinput.SetSimpleItem(data.GetPrimary(), data.GetMusic());//SongType객체에 ID, 곡명을 담습니다.
    
    //SingerType에는 가수명, 나이, 성별만 담습니다.
    singer.SetSinger(data.GetArtist(), data.GetAge(), data.GetGender(), songinput);
    
    m_List.Add(data);   //Master List에 저장.
    

    if(s_List.IsEmpty() || !s_List.Get(singer)){//값이 존재하지 않을 경우.
        cout<<"\n\t >>NOT EXIST IN SingerList."<<endl;
        cout<<"\t >>SAVE IN SingerList."<<endl;
            s_List.Add(singer);     //SingList가 비어있을 경우 저장.
        simple_List.Add(songinput); //SongList에도 저장.
    }
    else if(s_List.Get(singer)){//값이 존재할 경우.
        cout<<"\t >>This Singer is already exist."<<endl;
    }
    cout<<"\t=============================="<<endl;
    ​​​DisplayAllMusic();
    ​​​DisplayAllSingerList();
    ​​​DisplayAllSongList();
    return 1;
}

// 2.
/*
 DeleteMusic() = Primary Key값을 입력하여 Master List(Singer List, Song List포함)에 있는 값을 삭제해줍니다.
 
 ItemType 객체에 키보드로 Primary값을 입력받고 SingerType과 SongType 객체에도 필요한 정보를 입력해줍니다.
 Master List에서 삭제되면 Singer List와 Song List에서도 똑같이 없어져야 하므로 세 리스트에서 동시에 삭제가 진행된 경우 참이 되게 조건문을 만들어줬습니다.
 세 리스트에서 삭제가 진행될 경우, 확인하기 위해 출력함수를 모두 작성하였습니다.
 */
int Application::DeleteMusic(){
    ItemType data;
    Singer singer;
    SimpleItemType song;
    
    data.SetPrimaryFromKB();        //ItemType 객체에 Primary Key값을 키보드로 입력받음.
    song.SetId(data.GetPrimary());  //SongType 객체에 Primary Key값을 입력해줌.
    singer.SetSonglist(song);       //SingerType 객체에 마찬가지로 Primary Key값을 입력해줌.
    
    if(m_List.IsEmpty()){
        cout<<"\t List is Empty."<<endl;
        return 0;
    }

    if(m_List.Delete(data) && s_List.Delete(singer) && simple_List.Delete(song)){
        cout<<"============ Music is Deleted !=========="<<endl;
        ​​​DisplayAllMusic();
        ​​​DisplayAllSingerList();
        ​​​DisplayAllSongList();
        return 1;
    }
    else{
        cout<<"============ Music is not Deleted !=========="<<endl;
        ​​​DisplayAllMusic();
        ​​​DisplayAllSingerList();
        ​​​DisplayAllSongList();
        return 0;
    }
    
}

// 3.
/*
 ReplaceMusic() = 키보드로 Primary Key값을 입력받고 Master List내에 같은 값을 가진 객체가 있다면 내용을 수정할 수 있게 해줍니다.
 
 객체에 키보드로 Primary Key를 입력받는다.
 만약 해당 객체가 있다면, 입력받은 객체를 확인하기 위해 해당 정보를 가진 객체 출력.
 바꿀내용을 하나씩 키보드로 바꿈. 단, Primary Key의 내용은 달라지면 안 됨.
 Primary Key를 미리 확인한 객체 정보와 다르게 입력하면 저장이 되지 않거나,
 입력한 Primary Key를 가진 다른 객체의 정보가 바뀌게 됨.
 */
void Application::ReplaceMusic(){
    ItemType data;
    Singer singer;
    SimpleItemType song;
    
    data.SetPrimaryFromKB();        //ItemType 객체에 Primary Key값을 키보드로 입력받음.
    song.SetId(data.GetPrimary());  //SongType 객체에 Primary Key값을 입력해줌.
    singer.SetSonglist(song);       //SingerType 객체에 마찬가지로 Primary Key값을 입력해줌.
    
    if(m_List.Retrieve_Binary(data) && s_List.Get(singer) && simple_List.Get(song)){
        data.DisplayRecordOnScreen(); // 내가 바꿀 객체가 무엇인지 다시 확인해보기 정도.
        cout<<"================= Replace ================="<<endl;
        data.SetRecordFromKB();
        song.SetSimpleItem(data.GetPrimary(), data.GetMusic());//SongType객체에 ID, 곡명을 담습니다.
        //SingerType에는 가수명, 나이, 성별만 담습니다.
        singer.SetSinger(data.GetArtist(), data.GetAge(), data.GetGender(), song);

        m_List.Replace(data);   //비교하고 값 바꿔주기
        s_List.Replace(singer);
        simple_List.ReplaceItem(song);
        cout<<"================= Complete ================="<<endl;
    }
    else
        cout<<endl<<"============ Primary Key Error ============"<<endl;
}

// 4-1.
/*
 SearchByid_Seq() = 키보드로 Primary Key를 입력받고 Master List 내에 같은 값을 가진 객체가 있는지 순차탐색하여 출력해줍니다.
 
 객체에 키보드로 Primary값을 입력받고
 SortedList class에 있는 Retrieve_Seq 함수로 넘겨줍니.
 값을 찾으면 해당 객체의 모든 정보를 화면에 출력해줍니다.
 */

void Application::SearchByid_Seq(){        //Get함수와 호응..
    ItemType data;
    data.SetPrimaryFromKB(); //data라는 객체는 ID를 입력받는 메소드를 실행해줌
    
    if(m_List.Retrieve_Seq(data)){   //ArrayList의 메소드.
        cout<<endl;
        cout<<"========= Music FOUND by Sequence Search======="<<endl;
        data.DisplayRecordOnScreen();
        cout<<"==============================================="<<endl;
        
    }
    else{
        cout<<endl;
        cout<<"===== Music Not Found by Sequence Search ====="<<endl;
    }
    
}
// 4-2.
/*
 SearchByid_BinaryS() = 키보드로 Primary Key를 입력받고 Master List 내에 같은 값을 가진 객체가 있는지 이진탐색하여 출력해줍니다.
 객체에 키보드로 Primary값을 입력받고
 SortedList class에 있는 Retrieve_Binary함수로 넘겨줍니다.
 값을 찾으면 해당 객체의 모든 정보를 화면에 출력해줍니다.
 */

void Application::SearchByid_BinaryS(){
    ItemType data;
    data.SetPrimaryFromKB();
    
    if(m_List.Retrieve_Binary(data)){   //ArrayList의 메소드.
        cout<<endl;
        cout<<"========= Music FOUND by Binary Search======="<<endl;
        data.DisplayRecordOnScreen();
        cout<<"============================================="<<endl;
        
    }
    else{
        cout<<endl;
        cout<<"===== Music Not Found by Binary Search ====="<<endl;
    }
}

// 4-3.가수이름으로 찾기
/*
 SearchByArtist() = 가수명을 입력하면 같은 문자가 겹치는 곡에 대한 모든 정보를 출력해준다.
 
 반복문을 돌며 이미 저장되어있는 값을 계속해서 불러준다.
 객체에 저장된 .GetArtist() 문자열에 cin으로 입력받은 artist의 내용과 겹치는게 있으면 string::npos가 아니다.
 (string::npos, 원하는 문자를 찾지 못했을 때, 값을 가져옴)
 즉, string::npos와 같지 않으면 해당 객체의 모든 정보를 화면에 출력해준다.
 */
int Application::SearchByArtist(){
    ItemType data;
    
    int length = m_List.GetLength();
    
    string artist;
    cout<<"\t         Enter the Artist: ";
    cin>>artist;        //string으로 '가수명' 직접 입력 받음.
    cout<<endl;
    
    m_List.ResetList(); //배열 초기화
   
    for(int i = 0; i < length; i++){
        m_List.GetNextItem(data);
        
        if(data.GetArtist().find(artist) != string::npos){
            cout<<"========= Music FOUND by Artist ========="<<endl;
            data.DisplayRecordOnScreen();
            cout<<"========================================="<<endl;
        }
        
    }
    
    return 1;
}


// 4-4. 장르로 찾기
/*
 SearchByGenre() = 장르를 입력하면 같은 문자가 겹치는 곡에 대한 모든 정보를 출력해준다.
 
 반복문을 돌며 이미 저장되어있는 값을 계속해서 불러준다.
 객체에 저장된 .GetGenre() 문자열에 cin으로 입력받은 genre의 내용과 겹치는게 있으면 string::npos가 아니다.
 (string::npos, 원하는 문자를 찾지 못했을 때, 값을 가져옴)
 즉, string::npos와 같지 않으면 해당 객체의 모든 정보를 화면에 출력해준다.
 */
int Application::SearchByGenre(){
    ItemType data;
    
    int length = m_List.GetLength();
    
    string genre;
    cout<<"\t         Enter the Genre: ";
    cin>>genre;
    cout<<endl;
    
    m_List.ResetList();
  
    for(int i = 0; i < length; i++){
        m_List.GetNextItem(data);
        
        if(data.GetGenre().find(genre) != string::npos){
            cout<<"========= Music FOUND by Genre ========="<<endl;
            data.DisplayRecordOnScreen();
            cout<<"========================================"<<endl;
        }
    }
    
    return 1;
}


// 5. 전체출력
void Application::​​​DisplayAllMusic(){
    ItemType data;
    cout << "\n\t* Current Master list *" << endl;
    
    int length = m_List.GetLength();
    m_List.ResetList();
    
    for(int i = 0; i < length; i++){
        m_List.GetNextItem(data);
        data.DisplayRecordOnScreen();
    }
}


// 6. MakeEmpty


// 7, 8. 파일 입출력
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
    
    ​​​DisplayAllMusic();
    return 1;
}
int Application::WriteDataToFile(){
    ItemType data;
    
    string filename="";
    cout<<"\n\t File Name: ";
    cin>>filename;
    
    if(!OpenOutFile(filename))
        return 0;
    
    m_List.ResetList();
    
    int length = m_List.GetLength();
    
    for(int i = 0; i < length; i++){
        m_List.GetNextItem(data);
        data.WriteDataToFile(m_OutFile);
    }
    
    m_OutFile.close();    // file close
    
    return 1;
}

//--------------------------------- Play List -----------------------------------
//#11
/*
 AddtoPlayList() = Master List에서 데이터를 불러오고 갱신하여 PlayItemType에 값을 할당해줍니다.
 Q_List가 가득차면 Dequeue로 가장 오래된 데이터를 삭제해주고 맨 뒤에 최신 데이터를 저장해줍니다.
 저장할때, 저장하는 순서를 넣어줘야하므로 SetTime()을 사용했습니다.
 */
void Application::AddtoPlayList(){
    ItemType data;
    PlayItem music;
    
    data.SetPrimaryFromKB();
    m_List.Retrieve_Binary(data);
    //music에 ID, 추가순서, 재생횟수 담음.
    music.SetRecord(data.GetPrimary(), data.GetTime(), data.GetNumPlay());
    
    if(q_List.IsFull()){
        music.SetTime(++times);
        q_List.Replace(music);
        
        q_List.DeQueue(music);
        cout<<"\n\t >> Please, Dequeue Item... "<<endl;
        q_List.EnQueue(music);
        
    }
    else{
        q_List.EnQueue(music);
        music.SetTime(++times);
        q_List.Replace(music);
    }
    cout<<"\t==============================="<<endl;
    
}
//#12
/*
 DeletetoPlayList() = 플레이 리스트에 있는 내용중 프라이머리 키로 탐색하여 입력된 데이터의 모든 내용을 삭제해줍니다.
 */
int Application::DeletetoPlayList(){
    ItemType data;
    PlayItem music;
    
    if(q_List.IsEmpty()){
        cout<<"\t PlayList is Empty."<<endl;
        return 0;
    }
    
    data.SetPrimaryFromKB();
    music.SetPrimary(data.GetPrimary());
    
    if(q_List.Delete(music)){
        cout<<"============ Deleted in Play List =========="<<endl;
        PrintPlayList();
        return 1;
    }
    else{
        cout<<"========== Not Deleted in Play List =========="<<endl;
        PrintPlayList();
        return 0;
    }
    
}
//#13
/*
 PlayInsertOrder() = 0을 제외한 아무키나 입력하면 각 객체의 재생횟수가 증가하도록 하였습니다.
 if(limit >= q_List.GetLength()){
 q_List.ResetList();
 limit = 0;
 }
 부분은 플레이 리스트 내에서 정해진 길이만큼 반복이 되면 다시 처음 순서로 와야하므로
 길이가 다 되면 다시 리셋하여 처음값으로 되돌리는 내용입니다.
 */
void Application::PlayInsertOrder(){
    ItemType qdata;
    PlayItem music;
    
    
    cout<<"\n\t============= Playing ============="<<endl;
    int count=0;    // 특정시점에서의 재생횟수.
    
    cout << "\n\t* Current Play list *" << endl;
    PrintPlayList();
    cout<<"\t ========================="<<endl;
    q_List.ResetList();
    
    int num = 0;
    int limit = 0;
    if(!q_List.IsEmpty()){
        while(1){
            limit++;    //길이보다 크거나 같아지면 초기화를 시켜주기 위해 설정.
            count++;    //현재 함수내에서 몇 번 재생되었는지 알기 위해.
        
            q_List.GetNextItem(music);  //플레이 리스트에 있는 데이터에 접근
            num = music.GetNumPlay() + 1;
            music.SetNumPlay(num);
            q_List.Replace(music);
        
            qdata.SetPrimary(music.GetPrimary());
        
            m_List.Retrieve_Binary(qdata);  //플레이 리스트와 동일한 내용인 데이터가 마스터리스트에 있는지 확인.
            //마스터리스트에 있는 정보로 가져옴.
            qdata.DisplayRecordOnScreen();
            cout<<"\t ======= Play >> Any Number - Stop >> 0 ======"<<endl;
            cout<<"\t -----> ";
            cin>>num;
        
            if(limit >= q_List.GetLength()){
                q_List.ResetList();
                limit = 0;
            }
        
            if(num == 0){
                cout<<"\n\t [Total Play Times] : "<<count<<endl;
                cout<<"\n\t=============== Stop ==============="<<endl;
                break;
            }
        }
    }
    else
        cout<<"\t Please, Add Song to Play List."<<endl;
    
}
//#14
/*
 PrintPlayList() = 현재 플레이 리스트에 있는 내용을 출력해주는 함수입니다.
 
 */

void Application::PrintPlayList(){
    ItemType data;
    PlayItem music;
    cout << "\n\t* Play list *" << endl;
    
    int length = q_List.GetLength();
    
    q_List.ResetList();
    
    for(int i = 0; i < length; i++){
        q_List.GetNextItem(music);
        music.DisplayPLRecordOnScreen();
    }
    
}

//#15
/*
 SearchinPL_BinaryS() = 플레이 리스트에 있는 내용을 이진 탐색해줍니다.
 
 객체에 키보드로 Primary값을 입력받고
 플레이 리스트에 있는 Search 함수로 넘겨줍니다.
 값을 찾으면 해당 객체의 모든 정보를 화면에 출력해줍니다.
 */

int Application::SearchinPL_BinaryS(){
    ItemType data;
    PlayItem music;
    
    if(q_List.IsEmpty()){
        cout<<"\t PlayList is empty."<<endl;
        return 0;
    }
    
    data.SetPrimaryFromKB();
    music.SetPrimary(data.GetPrimary());
    
    if(q_List.Search(music)){
        cout<<endl;
        cout<<"=========== Music FOUND in Play List========="<<endl;
        music.DisplayPLRecordOnScreen();
        cout<<"============================================="<<endl;
        return 1;
    }
    else{
        cout<<endl;
        cout<<"======= Music Not Found in Play List ======="<<endl;
    }
    return 1;
}

/*
 PlayItem에 ID, numPlay, inTime만 들어가서 Replace의 필요성이 없다고 생각하여 삭제하였습니다.
 (ID값은 바뀌면 안되고 numPlay와 inTime은 계속 바뀌는 값이기 때문)

*/
//----------------------------------- Exception Test -------------------------------------
void Application::TestEmptyException()
{
    PlayItem music;
    
    while(1){
        q_List.DeQueue(music);
    }
}

void Application::TestFullException()
{
    PlayItem music;
    
    while(1)
    {
        q_List.EnQueue(music);
    }
}

//----------------------------------- Singer & Song List ----------------------------------
//#21
/*
 AddSinger() = Singer에 대한 정보인 '곡명', '가수명', '프라이머리 키', '성별', 나이' 등을 입력 받아서 Singer List와 Master List에 저장해줍니다.
 
 Singer의 정렬을 가수로 하려고 했으나 의미가 없는 것 같아서 SimpleItemType의 ID를 불러와서
 ID순으로 오름차순으로 Singer를 정렬하였습니다.
 함수가 실행되면 Singer List, Song List, Master List 모두 저장됩니다.
 */
int Application::AddSinger(){
    Singer singer;
    ItemType data;
    SimpleItemType songinput;
    
    cout<<"\t ====== Enter the ARTIST ======"<<endl<<endl;
    songinput.SetIdFromKB(); //Primary Key 입력
    singer.SetSonglist(songinput);  //SingerType에 Primary Key 갱신
    
    if(s_List.Get(singer)){ //Primary Key를 이용하여 탐색.
        cout<<"\n\t  >>ID already exists, Please enter again."<<endl;
        return 0;
    }
    else{
        cout<<"\n\t  >>ID is available. ENTER THE SINGER."<<endl<<endl;
        singer.SetSingerFromKB();      //singer list에 대해 정보를 키보드로 입력받음.
        songinput.SetSimpleFromKB();      //song list에 대해 정보를 키보드로 입력받음.
        
        data.SetSingerRecord(songinput.GetMusic(), singer.GetName(), songinput.GetId(), singer.GetGender(), singer.GetAge());
        //입력받은 정보를 마스터리스트 객체에 갱신시켜놓음. 새로운 정보일 경우 추가시키기 위해.
        singer.SetSonglist(songinput);
        //singer list엔 현재 songlist의 내용이 갱신되지 않은 상태이므로 갱신시켜줌.
        m_List.Add(data);
        s_List.Add(singer);
        simple_List.Add(songinput);
        cout<<"\n\t  >> SAVE THE SINGER."<<endl;
    }
    
    return 1;
}

//#22
/*
 AddSong() = Singer에 대한 정보인 '곡명', '가수명', '프라이머리 키', '성별', 나이' 등을 입력 받아서 Singer List와 Master List에 저장해줍니다.
 하지만 같은 가수명이 없다고 가정하여서 같은 이름을 갖는 경우, 저장을 하지 않도록 구현하였습니다.
 
 Song의 정렬은 Unsorted로 정렬하였고, 기준은 ID로 하였습니다.
 */
int Application::AddSong(){
    Singer singer;
    SimpleItemType songinput;
    ItemType emptydata, inputdata;
    
    int length = m_List.GetLength();
    
    cout<<"\t ====== Enter the ARTIST ======"<<endl<<endl;
    
    singer.SetSingerFromKB();       //singer list에 대해 정보를 키보드로 입력받음.
    songinput.SetSimpleFromKB();      //song list에 대해 정보를 키보드로 입력받음.
    
    inputdata.SetSingerRecord(songinput.GetMusic(), singer.GetName(), songinput.GetId(), singer.GetGender(), singer.GetAge());
    //새로운 정보일 경우 추가시키기 위해 입력받은 정보를 마스터리스트 객체에 갱신시켜놓음.
    singer.SetSonglist(songinput);
    //singer list에 있는 songlist의 현재 내용이 갱신되지 않은 상태이므로 갱신시켜줌.
    
    
    m_List.ResetList(); //배열 초기화
    for(int i = 0; i < length; i++){
        m_List.GetNextItem(emptydata);  //빈 객체를 넣어 현재 Master List에 있는 값들 중 같은 가수이름을 가진 데이터가 있는지 탐색.
        
        if(emptydata.GetArtist().find(singer.GetName()) != string::npos){
            cout<<"========= The Artist is already exist. ========="<<endl;
            return 0;
        }
    }
    
    if(s_List.Get(singer)){     //갱신받은 songlist의 id값으로 singer list 내에 해당하는 Primary Key가 있는지 확인.
        cout<<"\t ID already exists Please enter again."<<endl;
        return 0;
    }
    else{
        cout<<"\n\t  >>NOT EXIST. SAVE THE SINGER."<<endl;
        
        m_List.Add(inputdata);
        s_List.Add(singer);
        simple_List.Add(songinput);
        // 새로운 정보일 경우 세 리스트에 모두 추가.
    }
    return 1;
    
}

//#23
/*
 DisplayAllSingerList() = SingerType의 객체를 출력하도록 하였습니다.
 */

void Application::​​​DisplayAllSingerList(){
    Singer singer;
    cout << "\n\t* Current Singer list *" << endl;
    
    int length = m_List.GetLength();
    s_List.ResetList();
    
    for(int i = 0; i < length; i++){
        s_List.GetCurItem(singer);
        singer.DisplaySingerOnScreen();
    }
    
}

//#24
/*
 DisplayAllSongList() = SimpleItemType의 객체를 출력하도록 하였습니다.
 */
void Application::​​​DisplayAllSongList(){
    SimpleItemType song;
    cout << "\n\t* Current Song list *" << endl;
    
    int length = m_List.GetLength();
    simple_List.ResetList();
    
    for(int i = 0; i < length; i++){
        simple_List.GetNextItem(song);
        song.DisplaySimpleItemOnScreen();
    }
    
}

//#25
/*
 SearchBySinger() = 가수의 이름을 검색하여 존재하면 출력해주는 함수.
 */


void Application::SearchBySinger(){
    Singer singer;
    SimpleItemType song;
    int length = m_List.GetLength();
    string name;
    cout<<"\t Please Enter The Artist Name to Search : ";
    cin>> name;
    
    cout<<endl;
    
    s_List.ResetList();
    
    for(int i = 0; i < length; i++){
        s_List.GetCurItem(singer);
        if(singer.GetName().find(name) != string::npos ){
            cout<<"========= Music FOUND by Singer List ========="<<endl;
            singer.DisplaySingerOnScreen();
            singer.DisplaySongInSinger();
            cout<<"=============================================="<<endl;
            
        }
    }
}

