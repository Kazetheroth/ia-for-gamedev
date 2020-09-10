#pragma once
#include <functional>

#include "GameState.h"


class Transition
{
	private:
		std::function<bool()> condition;
	public:
		Transition(const std::function<bool()> newCondition);
		const std::function<bool()> getCondition();	
};

