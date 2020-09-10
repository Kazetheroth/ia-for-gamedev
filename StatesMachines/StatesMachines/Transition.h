#pragma once
#include <functional>

#include "GameState.h"
#include "State.h"


class Transition
{
	private:
		State* outState;
		const std::function<bool()> condition;
	public:
		Transition(State* outState, const std::function<bool()> newCondition);
		State getOuterState();
		const std::function<bool()> getCondition();	
};

