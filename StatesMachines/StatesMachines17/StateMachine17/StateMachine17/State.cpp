#include "State.h"
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
