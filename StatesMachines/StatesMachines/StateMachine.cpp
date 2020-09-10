#include "StateMachine.h"


StateMachine::StateMachine(State* startState, GameState* gs)
{
	this->startState_ = startState;
	this->currentState_ = startState;

}

void StateMachine::checkTransition(const GameState* gameState)
{

		
}

void StateMachine::checkTransition(const GameState * gameState)
{
	const vector<Transition>& transitionTab = currentState_->getTransitions();
	for (int i = 0; i < transitionTab.size(); i++)
	{

	}
}

void StateMachine::mainLoop()
{
	char* userInput;
	while (userInput != "stop")
	{
		checkTransition(this->gs);
	}
}
