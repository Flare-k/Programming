#include "stdafx.h"


Application::Application()
{
	srand(time(NULL));
	color = 0x000000;
	penSize = 1;
	isEmpty = false;
}


Application::~Application()
{
}

HRESULT Application::Init()
{
	AppBase::Init();
	shape = NONE;
	draw = IDLE;
	return S_OK;
}

void Application::Release()
{
	AppBase::Release();
}

void Application::Update()
{
	AppBase::Update();
	list.UpdateLast();

	if (KEYMANAGER->isOnceKeyDown('K')) {
		penSize -= 1;
		if (penSize < 1) penSize = 1;
	}
	if (KEYMANAGER->isOnceKeyDown('L')) {
		penSize += 1;
		if (penSize > 10) penSize = 10;
	}

	if (KEYMANAGER->isOnceKeyDown('P')) {
		int randRGB[3];
		for (int i = 0; i < 3; ++i) randRGB[i] = rand() % 256;
		color = RGB(randRGB[0], randRGB[1], randRGB[2]);
	}
	if (KEYMANAGER->isOnceKeyDown('O')) {
		isEmpty = !isEmpty;
	}
	
	if (draw == IDLE) {
		if (KEYMANAGER->isOnceKeyDown(VK_TAB)) {
			if (shape == POLYGON) shape = NONE;
			else shape = (eShapeState)((int)shape + 1);
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) {
			switch (shape)
			{
			case NONE:
				break;
			case RECTANGLE: {
				RectangleNode * newNode = new RectangleNode(GetMousePos(), penSize, isEmpty, color);
				list.Attach(newNode);
				draw = ING;
			} break;
			case CIRCLE: {
				CircleNode * newNode = new CircleNode(GetMousePos(), penSize, isEmpty, color);
				list.Attach(newNode);
				draw = ING;
			} break;
			case CIRCLE_PASSIVE: {
				CircleNode * newNode = new CircleNode(GetMousePos(), penSize, isEmpty, color);
				list.Attach(newNode);
				draw = ING;
			} break;
			case POLYGON: {
				PolygonNode* newNode = new PolygonNode(penSize, isEmpty, color);
				list.Attach(newNode);
				draw = ING;
			} break;
			}
		}
	}
}

void Application::Render(HDC hdc)
{
	list.DisplayAll(hdc);

	string mode;
	mode = "현재 도형: ";
	switch (shape)
	{
	case NONE:
		mode += "NONE";
		break;
	case RECTANGLE:
		mode += "RECTANGLE";
		break;
	case CIRCLE:
		mode += "CIRCLE";
		break;
	case CIRCLE_PASSIVE:
		mode += "CIRCLE_PASSIVE";
		break;
	case POLYGON:
		mode += "POLYGON";
		break;
	}
	TextOutA(hdc, 10, 10, mode.c_str(), strlen(mode.c_str()));

	string HowTo;
	HowTo = "!사용법! Tab: 도형변경, K: 펜사이즈줄이기, L: 펜사이즈키우기, P: 색 변경(랜덤), O: 색 채우기 Toggle";
	TextOutA(hdc, 210, 10, HowTo.c_str(), strlen(HowTo.c_str()));
	HowTo = "다각형을 그릴 시에 마지막은 우클릭으로 마무리 할 수 있습니다.";
	TextOutA(hdc, 210, 30, HowTo.c_str(), strlen(HowTo.c_str()));
}
