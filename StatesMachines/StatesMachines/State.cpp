#include "State.h"

const vector<Transition>& State::getTransitions()
{
	return this->transitions;
}

void State::DoSomething()
{
	char* response;
	cout << this->responsePhrase_ << endl;
	
}

void State::AddTransitions(const Transition transition)
{
	
}
