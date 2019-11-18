#include "stdafx.h"
#include "HeterogeneousList.h"


HeterogeneousList::HeterogeneousList()
{
	first = new RectangleNode();
	first->rlink = first->llink = first;//자신을 가리키는 doubly linked로 만듬
	num = 0;
}


HeterogeneousList::~HeterogeneousList()
{
}

void HeterogeneousList::UpdateLast()
{
	first->llink->update(); // 마지막만 검사(변경 중이기 때문에)
}

void HeterogeneousList::DisplayAll(HDC hdc)
{
	HtgListIterator iter(*this);
	while (iter.NotHeader())
	{
		iter.current->display(hdc); // 현재 노드를 출력. Virtual 함수 
		iter.Next();  // 포인터를 다음로 이동 
	}
}

void HeterogeneousList::DeleteAllNode()
{
	BaseNode *tmp, *p;
	for (p = first->rlink; p != first; ) {
		tmp = p;
		p = p->rlink;
		delete tmp;
	}
	first->llink = first->rlink = first; // empty list로 만듬 
	num = 0;
}

void HeterogeneousList::Attach(BaseNode * newNode)
{
	BaseNode *lastNode = first->llink;  // lastNode
	newNode->llink = lastNode;
	newNode->rlink = first;
	lastNode->rlink = newNode;
	first->llink = newNode;
	num++;
}
