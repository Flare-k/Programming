#pragma once
//=====================================================
//		## AppBase ## (이 베이스로 앱을 만든다)
//=====================================================
class AppBase
{
public:
	AppBase();
	virtual ~AppBase();

	//초기화
	virtual HRESULT Init();
	//해제
	virtual void Release();
	//업데이트
	virtual void Update();
	//그리기
	virtual void Render(HDC hdc);

	//WndProc
	LRESULT MainProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};