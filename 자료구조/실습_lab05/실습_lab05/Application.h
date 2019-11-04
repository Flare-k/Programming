#pragma once
#include <iostream>
#include <string>
#include <fstream>

#include "ItemType.h"
#include "Singer.h"
#include "SimpleItemType.h"
#include "PlayItem.h"

#include "SortedList.h"
#include "UnsortedList.h"
#include "D_LinkedList.h"
using namespace std;

//Application 클래스

class Application
{
private:
    ifstream m_InFile;
    ofstream m_OutFile;
    SortedList<ItemType> m_List;        //Master List
    D_LinkedList<PlayItem> p_List;     //Play List
    D_LinkedList<Singer> s_List;    //Singer List
    UnsortedList<SimpleItemType> simple_List;//Song List
    
    int m_Command;
    int times = 0;
    
public:
    Application(){
        m_Command=0;
    }
    ~Application(){}
    
    void Run();
    int GetCommand();
    
    /*
     =========================== Master List ===========================
     */
    int AddMusic();
    /*
     AddMusic() = Master List, Singer List, Song List에 입력값을 연동하여 저장하는 함수.
     
     ItemType 객체에 키보드로 모든 정보의 값을 입력받고 Master List에 저장될 때,
     Singer List에도 동시에 저장되어야 합니다.
     따라서 ItemType 객체로 입력 받은 정보를 통해,
     SingerType객체와 SongType객체에 서로의 메소드를(Set함수, ItemType의 Get함수) 활용하여 값을 입력해줍니다.
     Master List에 객체를 저장할 때, Singer List가 비어있거나 같은 Primary Key를 가진 객체가 없을 경우
     Singer List에도 저장해줍니다. 뿐만아니라 Song List도 관리해야 하므로 동시에 Song List에도 저장해줍니다.
     */
    int DeleteMusic();
    /*
     DeleteMusic() = Primary Key값을 입력하여 Master List(Singer List, Song List포함)에 있는 값을 삭제해줍니다.
     
     ItemType 객체에 키보드로 Primary값을 입력받고 SingerType과 SongType 객체에도 필요한 정보를 입력해줍니다.
     Master List에서 삭제되면 Singer List와 Song List에서도 똑같이 없어져야 하므로 세 리스트에서 동시에 삭제가 진행된 경우 참이 되게 조건문을 만들어줬습니다.
     세 리스트에서 삭제가 진행될 경우, 확인하기 위해 출력함수를 모두 작성하였습니다.
     */
    void ReplaceMusic();
    /*
     ReplaceMusic() = 키보드로 Primary Key값을 입력받고 Master List내에 같은 값을 가진 객체가 있다면 내용을 수정할 수 있게 해줍니다.
     
     객체에 키보드로 Primary Key를 입력받는다.
     만약 해당 객체가 있다면, 입력받은 객체를 확인하기 위해 해당 정보를 가진 객체 출력.
     바꿀내용을 하나씩 키보드로 바꿈. 단, Primary Key의 내용은 달라지면 안 됨.
     Primary Key를 미리 확인한 객체 정보와 다르게 입력하면 저장이 되지 않거나,
     입력한 Primary Key를 가진 다른 객체의 정보가 바뀌게 됨.
     */
    void SearchByid_Seq();
    /*
     SearchByid_Seq() = 키보드로 Primary Key를 입력받고 Master List 내에 같은 값을 가진 객체가 있는지 순차탐색하여 출력해줍니다.
     
     객체에 키보드로 Primary값을 입력받고
     SortedList class에 있는 Retrieve_Seq 함수로 넘겨줍니.
     값을 찾으면 해당 객체의 모든 정보를 화면에 출력해줍니다.
     */
    void SearchByid_BinaryS();
    /*
     SearchByid_BinaryS() = 키보드로 Primary Key를 입력받고 Master List 내에 같은 값을 가진 객체가 있는지 이진탐색하여 출력해줍니다.
     객체에 키보드로 Primary값을 입력받고
     SortedList class에 있는 Retrieve_Binary함수로 넘겨줍니다.
     값을 찾으면 해당 객체의 모든 정보를 화면에 출력해줍니다.
     */
    int SearchByArtist();
    /*
     SearchByArtist() = 가수명을 입력하면 같은 문자가 겹치는 곡에 대한 모든 정보를 출력해준다.
     
     반복문을 돌며 이미 저장되어있는 값을 계속해서 불러준다.
     객체에 저장된 .GetArtist() 문자열에 cin으로 입력받은 artist의 내용과 겹치는게 있으면 string::npos가 아니다.
     (string::npos, 원하는 문자를 찾지 못했을 때, 값을 가져옴)
     즉, string::npos와 같지 않으면 해당 객체의 모든 정보를 화면에 출력해준다.
     */
    int SearchByGenre();
    /*
     SearchByGenre() = 장르를 입력하면 같은 문자가 겹치는 곡에 대한 모든 정보를 출력해준다.
     
     반복문을 돌며 이미 저장되어있는 값을 계속해서 불러준다.
     객체에 저장된 .GetGenre() 문자열에 cin으로 입력받은 genre의 내용과 겹치는게 있으면 string::npos가 아니다.
     (string::npos, 원하는 문자를 찾지 못했을 때, 값을 가져옴)
     즉, string::npos와 같지 않으면 해당 객체의 모든 정보를 화면에 출력해준다.
     */
    void ​​​DisplayAllMusic();
    int OpenInFile(string &fileName);
    int OpenOutFile(string &fileName);
    int ReadDataFromFile();
    int WriteDataToFile();
   
    
    /*
     =========================== Play List ===========================
     */    void AddSongToPL();
    /*
     AddtoPlayList() = Master List에서 데이터를 불러오고 갱신하여 PlayItemType에 값을 할당해줍니다.
     Q_List가 가득차면 Dequeue로 가장 오래된 데이터를 삭제해주고 맨 뒤에 최신 데이터를 저장해줍니다.
     저장할때, 저장하는 순서를 넣어줘야하므로 SetTime()을 사용했습니다.
     */

    int DeleteSongFrPL();
    /*
     DeleteSongFrPL() = Play List에서 원하는 데이터를 삭제해줍니다.
     */
    void PlayIOAddTime();
    /*
     PlayIDAddTime() = Master List에서 Play List로 정보를 저장할 때, 순서가 저장되고
     저장된 순서대로 아무런 키를 입력할때마다 Play List가 재생됩니다.
     */
    void PlayIOAddSelect();
    /*
     PlayIOAddSelect() = Play List 안에 있는 곡 중에서 사용자가 원하는 특정 곡을 재생하게 해줍니다.
     */
    void PlayIOFreq();  //자주 Play된 횟수 순으로 Play..
    /*
     PlayIOFreq() = 앞서 PlayIOAddTime() 함수와 PlayIOAddSelect() 함수를 통해서 갱신된
     재생횟수를 통해 가장 많이 플레이 된 횟수부터 내림차순으로 정렬이 되고
     그 순서대로 플레이할 수 있게 해줍니다.
     */
    void PrintPlayList();
    /*
     PrintPlayList() = 현재 Play List의 곡들의 정보를 모두 출력해줍니다.
     */
    
    
    /*
     =========================== Singer & Song List ===========================
     */
    void ​​​DisplayAllSingerList();
    /*
     DisplayAllSingerList() = SingerType의 객체를 출력하도록 하였습니다.
     */
    void ​​​DisplayAllSongList();
    /*
     DisplayAllSongList() = SimpleItemType의 객체를 출력하도록 하였습니다.
     */
    int AddSinger();
    /*
     AddSinger() = Singer에 대한 정보인 '곡명', '가수명', '프라이머리 키', '성별', 나이' 등을 입력 받아서 Singer List와 Master List에 저장해줍니다.
     
     Singer의 정렬을 가수로 하려고 했으나 의미가 없는 것 같아서 SimpleItemType의 ID를 불러와서
     ID순으로 오름차순으로 Singer를 정렬하였습니다.
     함수가 실행되면 Singer List, Song List, Master List 모두 저장됩니다.
     */
    int AddSong();
    /*
     AddSong() = Singer에 대한 정보인 '곡명', '가수명', '프라이머리 키', '성별', 나이' 등을 입력 받아서 Singer List와 Master List에 저장해줍니다.
     하지만 같은 가수명이 없다고 가정하여서 같은 이름을 갖는 경우, 저장을 하지 않도록 구현하였습니다.
     
     Song의 정렬은 Unsorted로 정렬하였고, 기준은 ID로 하였습니다.
     */
    void SearchBySinger();
    /*
     SearchBySinger() = 가수의 이름을 검색하여 존재하면 출력해주는 함수.
     */
};
