#include "State.h"

State::State(const char* responseString)
{
	this->responsePhrase_ = responseString;
}

const vector<Transition>& State::getTransitions()
{
	return this->transitions;
}

const vector<State* >& State::getOutState()
{
	return this->outState;
}

void State::DoSomething()
{
	cout << this->responsePhrase_ << endl;	
}

void State::AddTransitions(const Transition transition)
{
	this->transitions.push_back(transition);
}

void State::AddOutStates(const State states)
{
	
}

void State::AddOutState(State* state)
{
	this->outState.push_back(state);
}
