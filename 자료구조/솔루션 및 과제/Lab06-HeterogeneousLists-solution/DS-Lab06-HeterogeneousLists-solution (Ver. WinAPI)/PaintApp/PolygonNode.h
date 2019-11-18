#pragma once
#include "BaseNode.h"
/**
*	@brief	다각형 Class
*	@author	박유민
*/
#define MAXPOLYPOINTS 500
class PolygonNode : public BaseNode
{
private:
	POINT vertex[MAXPOLYPOINTS];
	int curIndex;

public:
	PolygonNode(int size, bool isEmpty, COLORREF color);
	~PolygonNode();

	void update();
	void display(HDC hdc);
};

