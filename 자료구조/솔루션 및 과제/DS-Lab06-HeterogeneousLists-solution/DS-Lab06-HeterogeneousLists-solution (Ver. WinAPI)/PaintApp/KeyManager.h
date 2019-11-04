#pragma once
#include "SingletonBase.h"
#include <bitset>

using namespace std;
//=====================================================
//		## KeyManager ## (키 매니져)
//=====================================================

#define KEYMAX 256

class KeyManager : public SingletonBase <KeyManager>
{
private:
	bitset<KEYMAX> _keyUp;
	bitset<KEYMAX> _keyDown;

public:
	KeyManager();
	~KeyManager();

	HRESULT init();
	void release();

	//키가 한번만 눌렷냐?
	bool isOnceKeyDown(int key);
	//키가 한번 눌렀다 띄었냐?
	bool isOnceKeyUp(int key);
	//키가 계속 눌러있냐?
	bool isStayKeyDown(int key);
	//토글키냐?(캡스락,넘버락)
	bool isToggleKey(int key);
};