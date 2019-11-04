#ifndef _DIFFTYPEDLINKINHERIT_H
#define _DIFFTYPEDLINKINHERIT_H

#include <iostream>
using namespace std;

#define MAXPOINTS 500
enum Boolean { FALSE, TRUE };

struct Point
{
	int x;
	int y;

	void Init(int c, int e) { x = c; y = e;};	// 노드 초기화
	
	//?? 과제
	//?? assignment : print out a point to screen
	Point operator = (Point& b)
	{
		// Solution
		this->x = b.x;
		this->y = b.y;

		return *this;
	};
	
	friend ostream &operator << (ostream& out, Point t)
	{ 
		out << t.x << " , ";
		out << t.y;
		return out;
	};

	//?? 과제
	//?? assignment : input a point from keyboard
	friend istream &operator >> (istream& in, Point& t)
	{ 
		// Solution
		in >> t.x;
		in >> t.y;

		return in;
	};
};


//================================ BaseNode class 정의 ===============================
//	이질적인 graphic primitive들을 하나로 통합하여 관리하고 처리할 수 있게 한다.
//	- 하나의 linked list로 관리한다. 
//	- 종류와 무관하게 primitive를 입력(draw) 출력(display) 한다. virtual 함수를 이용  

//================================ Defie BaseNode class ===============================
//	generate a heterogeneous linked list that can handle graphic primitives
//	can display and draw the primitives independently from the type of primitives by using virtual functions

class BaseNode
{
	friend class List;
	friend class ListIterator;
public:
	BaseNode();
	virtual void draw()=0;  // pure virtual function 순수 가상함수 
	virtual void display()=0;
	int GetAttribute() {
		return attribute;
	}

protected:
	int attribute;
	BaseNode *rlink;  //오른쪽(뒤) 노드를 가리키는 포인터
	BaseNode *llink;  //왼쪽(앞) 노드를 가리키는 포인터
};


//================================ Derived Node class 정의 ===============================
//?? 과제 : 사각형 클래스 등록.
//?? 과제 : 원 클래스 등록.
// 과제와 동일한 구성으로 CircleNode 클래스를 선언하라.
// 시작점 끝 점 대신, 중심점과 경계점으로 구성한다.


//================================ Define Derived Node class ===============================
//?? assignment : Define rectangle class
//?? assignment: define circle class
// A circle can be define by two points; center and one on the boundary

// Rectangle class
class RectangleNode : public BaseNode
{
public:
	RectangleNode() 
	{
		attribute = 1;
		curNum = 0; 
		start.Init(0,0); 
		end.Init(0, 0);
	}
	RectangleNode(Point start, Point end,int attrib);
	~RectangleNode();
	void display();
	void draw();

private:
	int curNum;
	Point start;
	Point end;
};

// Circle class
class CircleNode : public BaseNode
{
public:
	CircleNode() 
	{
		attribute = 2;
		curNum = 0; 
		center.Init(0,0); 
		boundary.Init(0,0);
	}
	CircleNode(Point center,Point boundary,int attrib);
	~CircleNode();
	void display();
	void draw();

private:
	int curNum;
	Point center;
	Point boundary;
};

// Polygon class
class PolygonNode : public BaseNode 
{
public:
	PolygonNode()	
	{
		attribute = 3;
		NumOfPoints = 0; 
	};
	PolygonNode(Point Vertex[], int NumOfPoints, int attrib);
	void display(); // 화면에 출력
	void draw(); // 생성 
	Boolean AddPoints(Point t); // add vertex to the list
private:
	int NumOfPoints;
	Point vertex[MAXPOINTS];
};



//================================== List class   ================================= 
class List
{
	friend class ListIterator;
public:
	List();
	~List();
	void Attach(BaseNode* a); // 노드를 생성한 후, 맨뒤에 추가 
	void drawAll(); // 모든 primitive를 draw 한다. 
	void DeleteAllNode(); // Header를 제외한 리스트에 연결된 모든 노들 제거 
private:
	BaseNode *first;  // linked List의 시작 
};


//==================================== Iterator class =========================
class ListIterator
{
	friend class List;
public:
	ListIterator(const List &l) : list(l), current(l.first->rlink)	{};
	Boolean NotHeader(); // list의 현재 원소가 마지막 원소인지를 검사 
	BaseNode* Next();		// current node의 data를 반환하고 current 오른 쪽으로 이동  
private:
	const List &list;
	BaseNode *current;
};


#endif