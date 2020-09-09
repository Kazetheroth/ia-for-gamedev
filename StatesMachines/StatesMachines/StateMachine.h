#pragma once
#include <iostream>
#include <vector>
#include "State.h"
#include "Transition.h"
#include "GameState.h"

using namespace std;

class StateMachine
{

	private:
		State *startState_;
		State *currentState_;
		vector<State> states_;
	public:
		StateMachine();
		void AddStates(uint8_t id, string responsePhrase);
		void checkTransition(const GameState& gameState);
};

