#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "Transition.h"

using namespace std;

class State
{
	private:
		char* responsePhrase_;
		vector<State*> outState;
		vector<Transition> transitions;
	public:
		const vector<Transition>& getTransitions();
		void setTransitions(vector<Transition> newTransitionVector);
		const vector<State*>& getOutState();
		void setOutState(vector<State*>& newOutState);


		State(const char* responseString);
		void DoSomething();
		void AddTransitions(const Transition transition);
		
};

