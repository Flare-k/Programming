#pragma once
/**
*	@brief	도형의 부모 Class
*	@author	박유민
*/
class BaseNode
{
	friend class HeterogeneousList;
	friend class HtgListIterator;

protected:
	BaseNode*	rlink;			//오른쪽(뒤) 노드를 가리키는 포인터
	BaseNode*	llink;			//왼쪽(앞) 노드를 가리키는 포인터
	bool		isComplete;		//도형의 그리기가 종료되었는지 판단

	COLORREF	color;			//색
	int			penSize;		//펜사이즈
	bool		isEmpty;		//채워서 그릴것인지 판단

public:
	BaseNode();
	~BaseNode();

	virtual void update() = 0;
	virtual void display(HDC hdc) = 0;
};

