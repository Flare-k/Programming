#pragma once
namespace MyUtil {
	POINT PointMake(int x, int y);
	void RectangleMake(HDC hdc, POINT start, POINT end);
	void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height);
	void LineMake(HDC hdc, int x1, int y1, int x2, int y2);
	float LengthTwoPoint(POINT a, POINT b);
	/**
	*	@brief	현재 마우스 포인터의 좌표를 POINT로 반환하는 함수
	*/
	POINT GetMousePos();
}