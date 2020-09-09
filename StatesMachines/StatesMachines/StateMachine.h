#pragma once
#include <iostream>
#include <vector>
#include "State.h"
#include "Transition.h"

using namespace std;

class StateMachine
{

	private:
		vector<State> states_;
		vector<Transition> transitions_;
	public:
	
		StateMachine();
		void AddState();
		void AddTransition();
};

