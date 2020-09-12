#pragma once
#include "State.h"
#include "GameState.h"

using namespace std;

class StateMachine
{

	private:
		//State de départ
		State *startState_;

		//State dans laquelle la StateMachine est
		State *currentState_;
		GameState* gs;
		vector<State*> states_;
	public:
		StateMachine();
		StateMachine(State* startState, GameState* gs);

		const vector<State*>& getStates() const;
		void AddStates(State* newState);
		void checkTransition(const GameState* gameState);
		void mainLoop();
};

