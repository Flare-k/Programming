#include "Application.h"


void Application::Run(){
    int num = 0;
    
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
                    SearchByid_BinaryS();
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
                AddSongToPL();    //플레이 리스트에 추가하는 함수
                break;
            case 12:
                DeleteSongFrPL();
                break;
            case 13:
                PlayIOAddTime();
                break;
            case 14:
                PlayIOAddSelect();
                break;
            case 15:
                PlayIOFreq();
                break;
            case 16:
                PrintPlayList();    //플레이 리스트의 모든 곡을 보여주는 함수
                break;
            case 21:
                AddSinger();
                break;
            case 22:
                ​​​DisplayAllSingerList();
                break;
            case 23:
                AddSong();
                break;
            case 24:
                ​​​DisplayAllSongList();
                break;
            case 25:
                SearchByID();
                break;
            case 26:
                DeleteSong();
                break;
            case 27:
                ReplaceMusic();
                break;
            case 0: // 종료
                return;
            default:    // 맞지 않는 숫자를 입력했을 때의 출력
                cout << "\t Illegal selection...\n";
                break;
        }
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
    cout<<"\t   14 : Play Selected Music "<<endl;
    cout<<"\t   15 : Play Frequency Order "<<endl;
    cout<<"\t   16 : Print Play List "<<endl;
    cout<<"\t   ======= Singer List ======= "<<endl;
    cout<<"\t   21 : Add Singer "<<endl;
    cout<<"\t   22 : Print Singer List "<<endl;
    cout<<"\t   ---- Binary Search Tree ---- "<<endl;
    cout<<"\t   23 : Add Song(BST) "<<endl;
    cout<<"\t   24 : Print Song List "<<endl;
    cout<<"\t   25 : Search in Singer List "<<endl;
    cout<<"\t   26 : Delete Song List "<<endl;
    cout<<"\t   26 : Replace Song List "<<endl;
    cout<<"\t   0 : Quit" << endl;
    
    cout << endl << "\t Choose a Command--> ";
    cin >> command;
    cout << endl;
    
    return command;
}

//--------------------------------- Master List    -----------------------------------

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
    return 1;
}

// 2.
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
void Application::ReplaceMusic(){
    ItemType data;
    Singer singer;
    SimpleItemType song;
    
    data.SetPrimaryFromKB();        //ItemType 객체에 Primary Key값을 키보드로 입력받음.
    song.SetId(data.GetPrimary());  //SongType 객체에 Primary Key값을 입력해줌.
    singer.SetSonglist(song);       //SingerType 객체에 마찬가지로 Primary Key값을 입력해줌.
    bool found;
    simple_List.Get(song, found);
    if(m_List.Retrieve_Binary(data) && found == true){
        data.DisplayRecordOnScreen(); // 내가 바꿀 객체가 무엇인지 다시 확인해보기 정도.
        cout<<"================= Replace ================="<<endl;
        data.SetRecordFromKB();
        song.SetSimpleItem(data.GetPrimary(), data.GetMusic());//SongType객체에 ID, 곡명을 담습니다.
        //SingerType에는 가수명, 나이, 성별만 담습니다.
        singer.SetSinger(data.GetArtist(), data.GetAge(), data.GetGender(), song);
        
        m_List.Replace(data);   //비교하고 값 바꿔주기
        s_List.Replace(singer);
        simple_List.Replace(song, found);
        cout<<"================= Complete ================="<<endl;
    }
    else
        cout<<endl<<"============ Primary Key Error ============"<<endl;
}

// 4-1.
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
void Application::AddSongToPL(){
    ItemType data;
    PlayItem music;
    
    data.SetPrimaryFromKB();
    if(m_List.Retrieve_Binary(data)){
        music.SetRecord(data.GetPrimary(), data.GetTime(), data.GetNumPlay());
        music.SetTime(++times);
        p_List.Replace(music);
        p_List.Add(music);
    }
    else
        cout<<"\t Not Exist in Master List. Please, Try Again."<<endl;
    
    cout<<"\t==============================="<<endl;
    PrintPlayList();
    
}

int Application::DeleteSongFrPL(){
    ItemType data;
    PlayItem music;
    
    if(p_List.IsEmpty()){
        cout<<"\t PlayList is Empty."<<endl;
        return 0;
    }
    
    data.SetPrimaryFromKB();
    music.SetPrimary(data.GetPrimary());
    
    if(p_List.Delete(music)){
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


void Application::PlayIOAddTime(){
    ItemType data;
    PlayItem music;
    
    
    int count=0;    // 특정시점에서의 재생횟수.
    int num = 0;
    int limit = 0;
    
    if(!p_List.IsEmpty()){
        cout<<"\n\t============= Playing ============="<<endl;
        PrintPlayList();
        cout<<"\t =================================="<<endl;
        p_List.ResetList();
        
        while(1){
            limit++;    //길이보다 크거나 같아지면 초기화를 시켜주기 위해 설정.
            count++;    //현재 함수내에서 몇 번 재생되었는지 알기 위해.
            
            p_List.GetCurItem(music);  //플레이 리스트에 있는 데이터에 접근
            num = music.GetNumPlay() + 1;
            music.SetNumPlay(num);
            p_List.Replace(music);
            
            data.SetPrimary(music.GetPrimary());
            
            m_List.Retrieve_Binary(data);  //플레이 리스트와 동일한 내용인 데이터가 마스터리스트에 있는지 확인.
            //마스터리스트에 있는 정보로 가져옴.
            data.DisplayRecordOnScreen();
            cout<<"\t ======= [Play] >> 'Any Number' ==== [Stop] >> '0' ======"<<endl;
            cout<<"\t ----------------> ";
            cin>>num;
            
            if(limit >= p_List.GetLength()){
                p_List.ResetList();
                limit = 0;
            }
            
            if(num == 0){
                cout<<"\n\t [Total Play Times] : "<<count<<endl;
                cout<<"\n\t =============== Stop ==============="<<endl;
                break;
            }
        }
    }
    else
        cout<<"\t >> Please, Add Song to Play List."<<endl;
    
    
}


void Application::PlayIOAddSelect(){
    ItemType data;
    PlayItem music;
    int num = 0;
    int count = 0;
    
    data.SetPrimaryFromKB();    //ID입력
    music.SetPrimary(data.GetPrimary());    //music에다가 초기화.
    if(p_List.Get(music)){      //해당 ID를 가진 데이터가 있는지 조회.
        cout<<"\n\t============= Playing ============="<<endl;
        while(1){
            count++;
            
            num = music.GetNumPlay() + 1;
            music.SetNumPlay(num);
            p_List.Replace(music);
            
            data.SetPrimary(music.GetPrimary());
            
            m_List.Retrieve_Binary(data);  //플레이 리스트와 동일한 내용인 데이터가 마스터리스트에 있는지 확인.
            //마스터리스트에 있는 정보로 가져옴.
            data.DisplayRecordOnScreen();
            //cout<<"\t ======= [Play] >> 'Any Number' ==== [Stop] >> '0' ======"<<endl;
            cout<<"\t ======= [Play]/[Stop] : Any number / 0 ======"<<endl;
            cout<<"\t ----------------> ";
            cin>>num;
            
            if(num == 0){
                cout<<"\n\t [Total Play Times] : "<<count<<endl;
                cout<<"\n\t =============== Stop ==============="<<endl;
                break;
                
            }
        }
    }
}


//플레이 리스트에서 자주 플레이된 횟수 순으로 플레이.
void Application::PlayIOFreq(){
    ItemType data;
    PlayItem music;
    
    int length = p_List.GetLength();
    //각 재생횟수 끼리 비교해서.. 가장 많은 횟수부터 내림차순으로..
    PlayItem *max = new PlayItem[length];
    PlayItem temp[length];
    //max라는 동적배열에다가 집어넣고 대소비교할 예정.
    p_List.ResetList();
    
    for(int i = 0; i<length;i++){
        p_List.GetCurItem(music);//첫번째 데이터를 가져옴.
        max[i] = music;
    }   //일단 다 받음. 다 받고 내림차순하는게 더 쉬울듯..
    int temp1, i;
    
    for(i=0; i<length-1; i++){
        temp1 = i;
        for(int j = i+1; j<length; j++){ //i=0 -> j=1,2 길이가 3이라가정하면..
            if(max[j].GetNumPlay() > max[temp1].GetNumPlay())
                temp1 = j;
        }
        temp[i] = max[i];
        max[i] = max[temp1];
        max[temp1] = temp[i];
    }
    cout << "\n\t* Current Play list *" << endl;
    for(int i=0; i<length; i++){
        max[i].DisplayPLRecordOnScreen();
    }
    
    
    int num = 0;
    int count = 0;
    int elem = 0;
    if(!p_List.IsEmpty()){
        cout<<"\n\t============= Playing ============="<<endl;
        
        while(1){
            count++;
            
            num = max[elem%length].GetNumPlay() + 1;
            max[elem%length].SetNumPlay(num);
            p_List.Replace(max[elem%length]);
            
            data.SetPrimary(max[elem%length].GetPrimary());
            
            m_List.Retrieve_Binary(data);
            data.DisplayRecordOnScreen();
            
            cout<<"\t ======= [Play]/[Stop] : Any number / 0 ======"<<endl;
            cout<<"\t ----------------> ";
            cin>>num;
            
            if(num == 0){
                cout<<"\n\t [Total Play Times] : "<<count<<endl;
                cout<<"\n\t =============== Stop ==============="<<endl;
                break;
            }
            elem++;
        }
    }
    else
        cout<<"\t >> Please, Add Song to Play List."<<endl;
    
    
    
}

void Application::PrintPlayList(){
    PlayItem music;
    DIterator<PlayItem> iter(p_List);
    music = iter.Next();
    cout << "\n\t* Current Play list *" << endl;
    
    while(iter.NextNotNull()){
        music.DisplayPLRecordOnScreen();
        music = iter.Next();
    }
    
}


//----------------------------------- Singer & Song List ----------------------------------
//#21

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
    DIterator<Singer> iter(s_List);
    singer = iter.Next();
    cout << "\n\t* Current Singer list *" << endl;
    
    while(iter.NextNotNull()){
        singer.DisplaySingerOnScreen();
        singer = iter.Next();
    }
    
}

//#24
/*
 DisplayAllSongList() = SimpleItemType의 객체를 Binary Search Tree로 출력하도록 하였습니다.
 */
void Application::​​​DisplayAllSongList(){
    SimpleItemType song;
    cout << "\n\t* Current Song list *" << endl;
    simple_List.PrintTree(cout);
}

//#25
/*
 SearchByID() = 가수의 이름을 검색하여 존재하면 Binary Search Tree로 출력해주는 함수.
 */


void Application::SearchByID(){
    SimpleItemType song;
    cout<<"\t Please Enter The Music Name to Search  "<<endl;
    song.SetIdFromKB();
    cout<<'\n';
    bool found;
    simple_List.Get(song,found);
    if(found == true){
        song.DisplaySimpleItemOnScreen();
    }
    else
        cout << "\t Target song is not in the list." << endl;        // 못 찾았으면 못 찾았다는 문구를 출력
}

//#26
/*
 DeleteSong() = 가수의 ID를 검색하여 존재하면 Binary Search Tree로 삭제해주는 함수.
 */

void Application::DeleteSong(){
    SimpleItemType song;
    cout<<"\t ==== Input ID to Delete Song ==== "<<endl;
    song.SetIdFromKB();
    bool found;
    simple_List.Get(song,found);
    if(found == true){
        simple_List.Delete(song);            // DeleteItem함수를 통해서 simple_List에서 song값에 해당하는 노드를 삭제함
        ​​​DisplayAllSongList();                    // 지우고 나서의 simple_list를 출력
    }
    else
        cout<<"\t No song to delete"<<endl;    // 지우려고 하는 값의 node가 없을 경우
}

//#27
/*
 ReplaceSong() = 가수의 ID를 검색하여 존재하면 Binary Search Tree로 갱신해주는 함수.
 */
