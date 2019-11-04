#include "stdafx.h"
#include "AppBase.h"


AppBase::AppBase()
{
}


AppBase::~AppBase()
{
}

HRESULT AppBase::Init()
{
	SetTimer(ghWnd, 0, 10, NULL);
	KEYMANAGER->init();
	return S_OK;
}

void AppBase::Release()
{
	KillTimer(ghWnd, 0);
	KEYMANAGER->releaseSingleton();
}

void AppBase::Update()
{
	InvalidateRect(ghWnd, NULL, false);
}

void AppBase::Render(HDC hdc)
{
}

LRESULT AppBase::MainProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	static HBITMAP BackBit, BackoBit;

	switch (message)
	{
	case WM_TIMER:
		this->Update();
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		// 더블퍼버용
		BackDC = CreateCompatibleDC(hdc);
		BackBit = CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
		BackoBit = (HBITMAP)SelectObject(BackDC, BackBit);

		RECT rt = { 0,0,WINSIZEX, WINSIZEY };
		FillRect(BackDC, &rt, (HBRUSH)COLOR_WINDOWFRAME);
		this->Render(BackDC);

		BitBlt(hdc, 0, 0, WINSIZEX, WINSIZEY, BackDC, 0, 0, SRCCOPY);
		SelectObject(BackDC, BackoBit);
		DeleteObject(BackBit);
		DeleteDC(BackDC);
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:

		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
