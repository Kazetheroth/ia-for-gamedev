#include "Transition.h"

const std::function<bool()>& Transition::getCondition()
{
	return this->condition;
}

const State& Transition::getOuterState()
{
	return *this->outState;
}
