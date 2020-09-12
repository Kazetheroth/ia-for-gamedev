#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "Transition.h"

using namespace std;

class State
{
	private:
		//La phrase qui sera print en tant qu'action
		const char* responsePhrase_;
		//Les states de sorties 
		vector<State* > outState;
		
		//Les transitions liés aux states de sorties
		vector<Transition> transitions;
	public:

		//Getters et Setters
		const vector<Transition>& getTransitions() const;
		void setTransitions(vector<Transition> newTransitionVector);
		const vector<State* >& getOutState() const;
		void setOutState(vector<State*>& newOutState);


		State(const char* responseString);

		//Faire l'action liée à la State
		void DoSomething() const;
		//Permet l'ajout d'une transition au vector de transition
		void AddTransitions(const Transition transition);
		
		//Permet l'ajout d'une State au vector de State
		void AddOutState(State* state);
		
};

