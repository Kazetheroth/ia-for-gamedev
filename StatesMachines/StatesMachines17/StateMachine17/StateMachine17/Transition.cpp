#include "Transition.h"

Transition::Transition(const std::function<bool()> newCondition)
{
	this->condition = newCondition;
}

const std::function<bool()> Transition::getCondition()
{
	return this->condition;
}
