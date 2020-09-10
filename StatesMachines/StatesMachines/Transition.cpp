#include "Transition.h"

const std::function<bool()> Transition::getCondition()
{
	return this->condition;
}

State Transition::getOuterState()
{
	return *this->outState;
}
