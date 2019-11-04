#pragma once
#include "AppBase.h"

class Application : public AppBase
{
private:
	HeterogeneousList list;		//도형 List

	COLORREF	color;			//색
	int			penSize;		//펜 사이즈
	bool		isEmpty;		//채워서 그릴 것인지 판단

public:
	Application();
	~Application();

	HRESULT Init();				//App을 시작
	void Release();				//App을 종료할 때
	void Update();
	void Render(HDC hdc);
};
