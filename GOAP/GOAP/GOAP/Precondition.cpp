#include "pch.h"
#include "Precondition.h"


Precondition::Precondition(std::function<bool()> verifyCondition)
{
	this->verifyCondition = verifyCondition;
}



Precondition::~Precondition()
{
}

