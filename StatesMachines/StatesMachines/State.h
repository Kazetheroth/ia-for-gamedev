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
		vector<Transition> transitions;
	public:
		const vector<Transition>& getTransitions();
		void setTransitions(vector<Transition> newTransitionVector);
		State(const char* responseString);
		void DoSomething();
		void AddTransitions(const Transition transition);
		
};

