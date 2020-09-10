#include "StateMachine.h"


StateMachine::StateMachine(State* startState, GameState* gs)
{
	this->startState_ = startState;
	this->currentState_ = startState;

}

vector<State*>& StateMachine::getStates()
{
	return this->states_;
}

void StateMachine::AddStates(State* newState)
{
	this->getStates().push_back(newState);
}

void StateMachine::checkTransition(const GameState * gameState)
{
	size_t transitionSize = currentState_->getTransitions().size();
	for (int i = 0; i < transitionSize; i++)
	{
		Transition currentTransition = currentState_->getTransitions()[i];
		if (currentTransition.getCondition())
		{
			this->currentState_ = currentState_->getOutState()[i];
		}
	}
}

void StateMachine::mainLoop()
{
	char* response = nullptr;
	
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
