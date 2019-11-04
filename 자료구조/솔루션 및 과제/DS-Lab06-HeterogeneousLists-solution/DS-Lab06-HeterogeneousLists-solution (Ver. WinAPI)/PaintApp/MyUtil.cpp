#include "stdafx.h"
#include "MyUtil.h"

namespace MyUtil {
	POINT PointMake(int x, int y)
	{
		POINT pt = { x,y };
		return pt;
	}
	void RectangleMake(HDC hdc, POINT start, POINT end)
	{
		int left, top, right, bottom;
		if (start.x <= end.x) {
			left = start.x;
			right = end.x;
		}
		else {
			left = end.x;
			right = start.x;
		}
		if (start.y <= end.y) {
			top = start.y;
			bottom = end.y;
		}
		else {
			top = end.y;
			bottom = start.y;
		}
		Rectangle(hdc, left, top, right, bottom);
	}
	void EllipseMake(HDC hdc, int x, int y, int width, int height)
	{
		Ellipse(hdc, x, y, x + width, y + height);
	}
	void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height)
	{
		Ellipse(hdc, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
	}
	void LineMake(HDC hdc, int x1, int y1, int x2, int y2)
	{
		MoveToEx(hdc, x1, y1, NULL);
		LineTo(hdc, x2, y2);
	}
	float LengthTwoPoint(POINT a, POINT b)
	{
		float result = sqrtf(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
		return result;
	}
	POINT GetMousePos()
	{
		POINT mousePos;
		GetCursorPos(&mousePos);	//마우스 Screen 상의 위치를 얻어준다.
		ScreenToClient(ghWnd, &mousePos); //Screen 상의 위치를 Client 영영역 범위로 바꾼다.
		return mousePos;
	}
}