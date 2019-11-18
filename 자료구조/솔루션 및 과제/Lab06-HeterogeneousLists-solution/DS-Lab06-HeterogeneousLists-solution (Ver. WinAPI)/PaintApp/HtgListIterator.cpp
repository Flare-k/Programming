#include "stdafx.h"
#include "HtgListIterator.h"

HtgListIterator::~HtgListIterator()
{
}

bool HtgListIterator::NotHeader()
{
	if (current != list.first)  //header가 아닌지 확인 
		return true;
	else
		return false;
}

BaseNode * HtgListIterator::Next()
{
	current = current->rlink;
	return current->llink;
}
