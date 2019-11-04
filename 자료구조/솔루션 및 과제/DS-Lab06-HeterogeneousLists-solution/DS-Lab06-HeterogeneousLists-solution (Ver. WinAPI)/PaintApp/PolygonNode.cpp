#include "stdafx.h"
#include "PolygonNode.h"


PolygonNode::PolygonNode(int size, bool isEmpty, COLORREF color)
{
	vertex[0] = GetMousePos();
	curIndex = 1;
	vertex[curIndex] = GetMousePos();
	this->penSize = size;
	this->isEmpty = isEmpty;
	this->color = color;
}


PolygonNode::~PolygonNode()
{
}

void PolygonNode::update()
{
	if (isComplete) return;
	vertex[curIndex] = GetMousePos();
	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON)) {
		curIndex++;
		vertex[curIndex] = GetMousePos();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RBUTTON)) {
		isComplete = true;
		draw = IDLE;
	}
}

void PolygonNode::display(HDC hdc)
{

	HPEN hNewPen = CreatePen(PS_SOLID, penSize, color);
	HBRUSH hNewBrush = CreateSolidBrush(color);
	HPEN hOldPen = (HPEN)SelectObject(hdc, hNewPen);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hNewBrush);
	if (isEmpty) hOldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));


	for (int i = 0; i < penSize; ++i) {
		POINT* moveVertex;
		moveVertex = new POINT[curIndex + 1];

		for (int i = 0; i <= curIndex; ++i) {
			moveVertex[i].x = vertex[i].x - i;
			moveVertex[i].y = vertex[i].y - i;
		}


		if (!isComplete) {
			for (int i = 1; i <= curIndex; ++i) {
				LineMake(hdc, moveVertex[i - 1].x, moveVertex[i - 1].y, moveVertex[i].x, moveVertex[i].y);
			}
		}
		else {
			Polygon(hdc, moveVertex, curIndex);
		}

		delete moveVertex;
	}

	SelectObject(hdc, hOldPen);
	SelectObject(hdc, hOldBrush);
	DeleteObject(hNewPen);
	DeleteObject(hNewBrush);
}
