#include "pch.h"
#include "Precondition.h"


Precondition::Precondition(World* worldState, std::function<bool()> verifyCondition)
{
	this->worldState = worldState;
	this->verifyCondition = verifyCondition;
}


Precondition::~Precondition()
{
}

