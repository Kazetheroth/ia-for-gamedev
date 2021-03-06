#include "StateMachine.h"


StateMachine::StateMachine()
{
}

StateMachine::StateMachine(State* startState, GameState* gs)
{
	this->startState_ = startState;
	this->currentState_ = startState;
	this->gs = gs;

}

const vector<State*>& StateMachine::getStates() const
{
	return this->states_;
}

void StateMachine::AddStates(State* newState)
{
	this->states_.push_back(newState);
}

void StateMachine::checkTransition(const GameState* gameState)
{
	size_t transitionSize = currentState_->getTransitions().size();
	for (int i = 0; i < transitionSize; i++)
	{
		Transition currentTransition = currentState_->getTransitions()[i];
		if (currentTransition.getCondition()())
		{
			this->currentState_ = currentState_->getOutState()[i];
			break;
		}
	}
}

void StateMachine::mainLoop()
{
	string response = "";
	
	while (response != "stop")
	{
		std::cout << "GameState Day :" << this->gs->isDay << endl;
		this->currentState_->DoSomething();
		checkTransition(this->gs);
		cin >> response;
	}
}
