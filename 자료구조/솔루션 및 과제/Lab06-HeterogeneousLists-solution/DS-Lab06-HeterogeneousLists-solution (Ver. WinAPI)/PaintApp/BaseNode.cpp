#include "stdafx.h"
#include "BaseNode.h"


BaseNode::BaseNode()
{
	rlink = nullptr;
	llink = nullptr;
	isComplete = false;
	this->penSize = 1;
	this->isEmpty = false;
	this->color = 0x000000;
}


BaseNode::~BaseNode()
{
}
