#pragma once
/**
*	@brief	다양한 도형을 저장할 이질 리스트
*	@author	박유민
*/
class HeterogeneousList
{
	friend class HtgListIterator;
	friend class BaseNode;

private:
	BaseNode* first;  // linked List의 시작 
	int num;

public:
	HeterogeneousList();
	~HeterogeneousList();

	void UpdateLast();

	void DisplayAll(HDC hdc);				// 모든 primitive를 draw 한다. 
	void DeleteAllNode();					// Header를 제외한 리스트에 연결된 모든 노들 제거 
	bool NotEmpty() { if (num == 0) return FALSE; else return TRUE; };

	void Attach(BaseNode* newNode);			// 노드를 생성한 후, 맨뒤에 추가
};