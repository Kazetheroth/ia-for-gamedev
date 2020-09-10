#include "State.h"

const vector<Transition>& State::getTransitions()
{
	return this->transitions;
}

void State::DoSomething()
{
	char* response;
	cout << this->responsePhrase_ << endl;
	cout << "Type << ok >> for next action" << endl;

	while (response != "ok")
	{
		cin >> response;
	}

}
