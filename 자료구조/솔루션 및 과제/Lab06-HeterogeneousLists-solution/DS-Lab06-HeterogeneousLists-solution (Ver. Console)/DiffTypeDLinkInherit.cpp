#include "DiffTypeDLinkInherit.h"


////////////////////////////////////////////////////////////////////////////////////
// BaseNode의 member function  
///////////////////////////////////////////////////////////////////////////////////
//<<수정>>
BaseNode::BaseNode()
{
	rlink = 0;
	llink = 0;
}


////////////////////////////////////////////////////////////////////////////////////
// List member function
////////////////////////////////////////////////////////////////////////////////////
List::List()
{   
	first = new RectangleNode();
	first->rlink = first->llink = first;	//자신을 가리키는 doubly linked로 만듬
}


// List에 연결된 모든 노드의 메모리를 해제시킨다. 
List::~List()
{
	DeleteAllNode();
	delete first;
}


// List에 연결된 모든 노드의 메모리를 해제시킨다. 
void List::DeleteAllNode()
{   
	BaseNode *tmp, *p;
	for(p = first->rlink; p != first; )
	{	
		tmp = p;
		p = p->rlink;
		delete tmp;
	}
	first->llink = first->rlink = first;	// empty list로 만듬 
}



// list 뒤에 newNode를 추가 
void List::Attach(BaseNode *newNode)
{
	BaseNode *lastNode = first->llink;  // lastNode

	newNode->llink = lastNode;
	newNode->rlink = first;
	lastNode->rlink = newNode;
	first->llink = newNode;
}

//?? 과제, assignment
// 모든 primitive를 draw 한다.
void List::drawAll() 
{
	// this포인터를 넘겨서 iterator 객체를 하나 선언한다.
	// iterator를 이용하여 작성하라.
	ListIterator iterator(*this);

	while (iterator.NotHeader())
	{
		iterator.current->display();
		iterator.Next();
	}
	
}


///////////////////////////////////////////////////////////////////////////////////////
//=================ListIterator Member Function ========================
///////////////////////////////////////////////////////////////////////////////////////
// list의 현재 원소가 Header가 아닌지 검사

Boolean ListIterator::NotHeader()
{
	if(current != list.first)  //header가 아닌지 확인 
		return TRUE;
	else
		return FALSE;
}


// current 자료를 리턴하고 current 포인터를 오른쪽으로 이동  
BaseNode* ListIterator:: Next()
{
	current = current->rlink;
	return current->llink;
}


//?? 과제 : 변수 초기화 하시오.
//?? assignment : define creator. intialize a variables
// 하나의 원과 attribute를 정의
// deife a circle and attribute
CircleNode::CircleNode(Point center,Point boundary,int attrib)
{
	this->center = center;
	this->boundary = boundary;
	this->curNum = attrib;
}

CircleNode::~CircleNode()
{
}

//?? 과제 : 원 노드의 정보를 출력하시오.
//?? assignment : print out the circle information on the screen.
void CircleNode:: display()
{
	cout << "원 노드의 정보를 출력합니다." << endl;
	cout << "center좌표	: " << "(" << center.x << ", " << center.y << ")" << endl;
	cout << "boundary좌표	: " << "(" << boundary.x << ", " << boundary.y << ")" << endl;
	cout << "curNum		: " << this->curNum << endl;
}

//?? 과제 : 원노드에서 필요한 중심점과 경계점을 입력 받아 저장하시오.
//?? assignment : input the two point defining a circle from keyboard
void CircleNode:: draw()
{
	cout << "원의 중심점의 x좌표값과 y좌표값을 입력하세요 : " << endl;
	cout << "x좌표값 : ";
	cin >> center.x;
	cout << "y좌표값 : ";
	cin >> center.y;
	cout << "원의 경계점의 x좌표값과 y좌표값을 입력하세요 : " << endl;
	cout << "x좌표값 : ";
	cin >> boundary.x;
	cout << "y좌표값 : ";
	cin >> boundary.y;
	
}



//?? 과제
//?? assignment : intialize a rectangle object
RectangleNode::RectangleNode(Point start, Point end,int attrib)  // rectangle을 정의 
{
	this->start = start;
	this->end = end;
	this->curNum = attrib;
}

RectangleNode::~RectangleNode()
{
}

//?? 과제
//?? assignment : display the two points defining the current rectangle
void RectangleNode:: display()
{
	cout << "직사각형 노드의 정보를 출력합니다." << endl;
	cout << "start좌표	: " << "(" << start.x << ", " << start.y << ")" << endl;
	cout << "end좌표	: " << "(" << end.x << ", " << end.y << ")" << endl;
	cout << "curNum		: " << this->curNum << endl;
}

//?? 과제
//?? assignment : read in the two points definding a rectagnle
void RectangleNode:: draw()
{
	cout << "직사각형의 중심점의 x좌표값과 y좌표값을 입력하세요 : " << endl;
	cout << "x좌표값 : ";
	cin >> start.x;
	cout << "y좌표값 : ";
	cin >> start.y;
	cout << "원의 경계점의 x좌표값과 y좌표값을 입력하세요 : " << endl;
	cout << "x좌표값 : ";
	cin >> end.x;
	cout << "y좌표값 : ";
	cin >> end.y;
}


PolygonNode::PolygonNode(Point vert[], int NumOfP,int attrib)
{
	if (NumOfP < MAXPOINTS)	NumOfPoints = NumOfP;
	else	NumOfPoints = MAXPOINTS - 1;

	attribute = attrib;
	for (int i = 0; i < NumOfPoints; i++)
		vertex[i] = vert[i];
}

void PolygonNode:: display()
{
	cout<<"<< Polygon >>\n";
	for (int i = 0; i < NumOfPoints; i++)
		cout << " Vertex " << i << " : ( " << vertex[i] << " )\n";
	cout << endl;
}


//?? 과제 : 폴리곤 노드에서 점을 추가하는 함수를 작성하시오.
//?? assignment : write a function adding a point to the polygon object.
Boolean PolygonNode:: AddPoints(Point t)
{
	if (NumOfPoints < MAXPOINTS)
	{
		vertex[NumOfPoints].Init(t.x, t.y);
		return TRUE;
	}
	else
	{
		cout << "더 이상 점을 추가할 수 없습니다." << endl;
		return FALSE;
	}
}

//?? 과제 :폴리곤노드 에서 필요한 정보를 입력 받는 함수를 작성하시오.
//?? assignment : display the points defining the current polygon
void PolygonNode:: draw()
{
	cout << "다각형을 이루는 점의 x좌표값과 y좌표값을 입력하세요 : " << endl;
	cout << "x좌표값 : ";
	cin >> vertex[NumOfPoints].x;
	cout << "y좌표값 : ";
	cin >> vertex[NumOfPoints].y;
}