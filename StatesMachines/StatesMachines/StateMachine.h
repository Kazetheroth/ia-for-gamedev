#pragma once
#include "State.h"
#include "GameState.h"

using namespace std;

class StateMachine
{

	private:
		const State *startState_;
		State *currentState_;
		GameState* gs;
		vector<State> states_;
	public:
		StateMachine();
		StateMachine(State* startState, GameState* gs);

		void AddStates(const State* newState);
		void checkTransition(const GameState* gameState);
		void mainLoop();
};
