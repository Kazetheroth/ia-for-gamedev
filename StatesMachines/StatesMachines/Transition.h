#pragma once

#include <functional>

class Transition
{
	private:
		const State *outState;
		const std::function<bool()> condition;
	public:
		Transition(const State* outState, const std::function<bool()> newCondition);
		void ChangeState();
};

