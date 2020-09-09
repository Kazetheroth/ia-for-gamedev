#pragma once
#include <string>
#include <vector>
#include "Transition.h"

using namespace std;

class State
{
	private:
		string responsePhrase_;
		vector<Transition> transition;
	public:
		State(string responseString);
		void DoSomething();
		void AddTransitions(const State outState);
	
};

