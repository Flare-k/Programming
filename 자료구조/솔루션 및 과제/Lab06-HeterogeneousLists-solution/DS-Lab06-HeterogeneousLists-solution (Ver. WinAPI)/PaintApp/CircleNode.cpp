#include "stdafx.h"
#include "CircleNode.h"

CircleNode::CircleNode(POINT center, int size, bool isEmpty, COLORREF color)
{
	isComplete = false;
	this->center = center;
	this->penSize = size;
	this->isEmpty = isEmpty;
	this->color = color;
}

CircleNode::~CircleNode()
{
}

void CircleNode::update()
{
	if (isComplete) return;
	radius = LengthTwoPoint(GetMousePos(), center);
	if (shape == eShapeState::CIRCLE) {
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON)) {
			isComplete = true;
			draw = IDLE;
		}

	}
	else if (shape == eShapeState::CIRCLE_PASSIVE) {
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) {
			isComplete = true;
			draw = IDLE;
		}
	}
}

void CircleNode::display(HDC hdc)
{
	HPEN hNewPen = CreatePen(PS_SOLID, penSize, color);
	HBRUSH hNewBrush = CreateSolidBrush(color);
	HPEN hOldPen = (HPEN)SelectObject(hdc, hNewPen);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hNewBrush);
	if (isEmpty) hOldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));

	for (int i = 0; i < penSize; ++i) {
		EllipseMakeCenter(hdc, center.x, center.y, 2 * radius + i, 2 * radius + i);
	}

	SelectObject(hdc, hOldPen);
	SelectObject(hdc, hOldBrush);
	DeleteObject(hNewPen);
	DeleteObject(hNewBrush);
}
