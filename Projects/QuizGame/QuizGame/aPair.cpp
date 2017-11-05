#include "stdafx.h"
#include "aPair.h"


aPair::aPair(std::string answer, bool correct)
{
	this->_answer = answer;
	this->_correct = correct;
}


aPair::~aPair()
{
}
