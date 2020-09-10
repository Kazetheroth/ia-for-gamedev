#pragma once
#include <functional>
#include "State.h"


class Transition
{
	private:
		State *outState;
		const std::function<bool()> condition;
	public:
		const std::function<bool()>& getCondition();
		const State& getOuterState();
		Transition(const State* outState, const std::function<bool()> newCondition);
};

