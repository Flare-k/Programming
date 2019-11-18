#pragma once
/**
*	@brief	이질 리스트의 Iterator Class
*	@author	박유민
*/
class HtgListIterator
{
	friend class HeterogeneousList;
private:
	const HeterogeneousList &list;
	BaseNode *current;
public:
	HtgListIterator(const HeterogeneousList& copy) :list(copy), current(copy.first->rlink) {}
	~HtgListIterator();

	bool NotHeader();	// list의 현재 원소가 마지막 원소인지를 검사 
	BaseNode* Next();	// current node의 data를 반환하고 current 오른 쪽으로 이동  
};

