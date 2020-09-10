#include "StateMachine.h"


StateMachine::StateMachine(State* startState, GameState* gs)
{
	this->startState_ = startState;
	this->currentState_ = startState;

}

void StateMachine::checkTransition(const GameState * gameState)
{
	int transitionSize = currentState_->getTransitions().size();
	for (int i = 0; i < transitionSize; i++)
	{
		Transition currentTransition = currentState_->getTransitions()[i];
		if (currentTransition.getCondition())
		{
			*this->currentState_ = currentTransition.getOuterState();
		}
	}
}

void StateMachine::mainLoop()
{
	char* response;
	
	while (response != "stop")
	{
		this->currentState_->DoSomething();
		cout << "Type << ok >> for next action or << stop >> to stop" << endl;
		while (response != "ok" || response != "stop")
		{
			cin >> response;
		}
		checkTransition(this->gs);
	}
}
