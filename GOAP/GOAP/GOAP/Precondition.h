#pragma once
#include <functional>
#include "World.h"

class Precondition
{
	private:
		std::function<bool()> verifyCondition;
	public:
		Precondition(std::function<bool()> verifyCondition);
		~Precondition();
};

