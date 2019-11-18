#pragma once
#include "BaseNode.h"
/**
*	@brief	동그라미 도형 Class
*	@author	박유민
*/
class CircleNode : public BaseNode
{
private:
	float radius;
	POINT center;

public:
	CircleNode(POINT center, int size, bool isEmpty, COLORREF color);
	~CircleNode();

	void update();
	void display(HDC hdc);
};