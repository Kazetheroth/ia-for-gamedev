#pragma once

#include "State.h"

class Transition
{
	private:
		State *outState;
	public:
		Transition();
		void ChangeState();
};

