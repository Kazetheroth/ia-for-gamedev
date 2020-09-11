#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "Transition.h"

using namespace std;

class State
{
	private:
		const char* responsePhrase_;
		vector<State* > outState;
		vector<Transition> transitions;
	public:
		const vector<Transition>& getTransitions() const;
		void setTransitions(vector<Transition> newTransitionVector);
		const vector<State* >& getOutState() const;
		void setOutState(vector<State*>& newOutState);


		State(const char* responseString);
		void DoSomething() const;
		void AddTransitions(const Transition transition);
		void AddOutStates(const State states);
		void AddOutState(State* state);
		
};

