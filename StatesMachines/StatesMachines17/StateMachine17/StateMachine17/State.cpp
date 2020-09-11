#include "State.h"

State::State(const char* responseString)
{
	this->responsePhrase_ = responseString;
}

const vector<Transition>& State::getTransitions() const
{
	return this->transitions;
}

const vector<State* >& State::getOutState() const
{
	return this->outState;
}

void State::DoSomething() const
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
