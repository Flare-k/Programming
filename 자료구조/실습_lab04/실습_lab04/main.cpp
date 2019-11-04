#include "Application.h"

using namespace std;

int main(){
    
    Application app;
    app.Run();
    
    return 0;
}

/*
 Application class의 객체를 생성해주고
 메소드 Run()을 사용하여 SortedList, ItemType class, CircularQueue의 내용들을 구현할 수 있게끔 해줍니다.
 */


/*
 1) AddSinger() 함수는 Singer List에 (Master List와 Singer List에 존재하지 않는다면)새로운 가수를 추가하고 동시에 Master List에도 추가하는 것 맞나요??
 >>맞습니다.
 
 
 2) AddSong()함수에서 '가수'를 검색하고 추가하라고 하였는데 '가수' 변수로 검색해서 중복되는 '가수'가 있으면 기존과 프라이머리 키만 다르게 해서 저장하면 되는 것인가요??
 >>그렇습니다.
 
 
 3) AddSinger()함수와 AddSong() 함수를 통해서 내용을 singer와 song list에 저장을 하면 마스터 리스트에도 동시에 같이 저장하게 끔 해야하는 것인가요??(만약 AddSong()같은경우 같은 이름을 가진 가수가 여러 곡을 가지게 될 수도 있는데 그것들도 다 마스터에 추가 되어야하는것인지 궁금합니다.)
 >>동시에 진행되어야합니다. 같은 이름을 가진 가수가 없다고 가정하시는게 편하실 겁니다.
 
 
 4) 마지막으로 Singer List에 songlist가 있어서 저는 simpleItemType class를 따로 만들어 주고 Singer class에서 Private변수로 받았는데 이렇게 하면 Generic과는 상관 없는 것인가요??
 >>SingerClass가 SingerType을 말하시는 거라면 말씀하신게 맞습니다. SingerType에서 SimpleItemType을 private 변수로 가지는 것은 제너릭과 무관합니다.
 
 */


/*
 13 
 */
