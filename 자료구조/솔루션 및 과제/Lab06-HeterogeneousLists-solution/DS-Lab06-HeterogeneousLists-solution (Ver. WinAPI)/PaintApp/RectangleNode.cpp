#include "stdafx.h"
#include "RectangleNode.h"


RectangleNode::RectangleNode()
{
	isComplete = true;
	POINT tmp = { 0,0 };
	pt[0] = tmp;
	pt[1] = tmp;
}

RectangleNode::RectangleNode(POINT pt, int size, bool isEmpty, COLORREF color)
{
	this->pt[0] = pt;
	this->pt[1] = pt;
	this->penSize = size;
	this->isEmpty = isEmpty;
	this->color = color;
}


RectangleNode::~RectangleNode()
{
}

void RectangleNode::update()
{
	if (isComplete) return;
	pt[1] = GetMousePos();
	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON)) {
		isComplete = true;
		draw = IDLE;
	}
}

void RectangleNode::display(HDC hdc)
{
	HPEN hNewPen = CreatePen(PS_SOLID, penSize, color);
	HBRUSH hNewBrush = CreateSolidBrush(color);
	HPEN hOldPen = (HPEN)SelectObject(hdc, hNewPen);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hNewBrush);
	if (isEmpty) hOldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));

	for (int i = 0; i < penSize; ++i) {
		POINT tmp[2];
		tmp[0].x = pt[0].x - i;
		tmp[0].y = pt[0].y - i;
		tmp[1].x = pt[1].x - i;
		tmp[1].y = pt[1].y - i;
		RectangleMake(hdc, tmp[0], tmp[1]);
	}

	SelectObject(hdc, hOldPen);
	SelectObject(hdc, hOldBrush);
	DeleteObject(hNewPen);
	DeleteObject(hNewBrush);
}
