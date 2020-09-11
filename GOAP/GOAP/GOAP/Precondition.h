#pragma once
#include <functional>
#include "World.h"

class Precondition
{
	private:
		World* worldState;
		std::function<bool()> verifyCondition;
	public:
		Precondition(World* worldState, std::function<bool()> verifyCondition);
		~Precondition();
};

