/*
 Binary Search Tree
 
 대부분의 구현을 전역함수로 재귀를 통해 구현할 것.
 노드 구조를 보면 더블링크드랑 비슷.
 싱글리처럼 한 방향으로 가리키게 되는데 데이터타입의 고유값을 통해 비교.
 인서트일 때는 널일때와 노드가 존재할때를 구분해줄 것.
 재귀로 돌면서 자식으로 쭉쭉 내려가면서 비교하게 된다.
 삭제는 삭제할 데이터를 먼저 찾고 삭제할 데이터보다 작은 것중에 가장 큰 것을 삭제할 자리에 갱신.
 (= 양쪽에 모두 노드가 있는 경우)
 그럼 그 가장 큰 값은 또 삭제를 해줘야 한다.(위로 복사가 됐으니까)
 */
/**
 *    @mainpage    BinarySearchTree
 *                This is a simple example of Lab07 on data structures course.<br>
 
 *    @date
 *    @author
 */

#include "Application.h"

int main()
{
    Application app;
    app.Run();
    
    return 0;
}
