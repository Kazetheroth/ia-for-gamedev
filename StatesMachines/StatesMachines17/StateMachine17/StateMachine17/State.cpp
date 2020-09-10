#include "State.h"

State::State(const char* responseString)
{
	this->responsePhrase_ = responseString;
}

const vector<Transition>& State::getTransitions()
{
	return this->transitions;
}

const vector<State*>& State::getOutState()
{
	return this->outState;
}

void State::DoSomething()
{
	char* response = nullptr;
	cout << this->responsePhrase_ << endl;
	
}

void State::AddTransitions(const Transition transition)
{
	
}
